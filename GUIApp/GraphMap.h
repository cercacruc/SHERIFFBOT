// GraphMap.h - Campus routing
// - A* Manhattan sobre grilla (obstáculos = zonas)
// - Compatibilidad con tu UI anterior: AgregarNodo / ConectarNodos / EncontrarRuta / ObtenerPosicionNodo
// Coordenadas base: MAP_W=935, MAP_H=465 (igual a tu tabla SQL)
// NOTA: este archivo NO depende de Service/BotModel.

#pragma once

namespace GUIApp {

    using namespace System;
    using namespace System::Drawing;
    using namespace System::Collections::Generic;

    public ref class ZonaRect
    {
    public:
        String^ Nombre;
        RectangleF Rect;     // coordenadas del mapa (0..935, 0..465)

        ZonaRect(String^ nombre, float xMin, float xMax, float yMin, float yMax)
        {
            Nombre = nombre;
            float x = Math::Min(xMin, xMax);
            float y = Math::Min(yMin, yMax);
            float w = Math::Abs(xMax - xMin);
            float h = Math::Abs(yMax - yMin);
            Rect = RectangleF(x, y, w, h);
        }

        PointF Centro()
        {
            return PointF(Rect.X + Rect.Width / 2.0f, Rect.Y + Rect.Height / 2.0f);
        }

        bool Contiene(PointF p)
        {
            return Rect.Contains(p);
        }
    };

    public ref class GrafoCampus
    {
    public:
        literal int MAP_W = 935;
        literal int MAP_H = 465;

    private:
        // Zonas (obstáculos A*)
        List<ZonaRect^>^ zonas;

        // Puntos especiales (puertas, etc.)
        Dictionary<String^, PointF>^ puntosEspeciales;

        // ===== Compatibilidad BFS por nodos =====
        Dictionary<String^, PointF>^ nodos;                 // nombre -> punto (mundo)
        Dictionary<String^, List<String^>^>^ adyacencia;     // nombre -> vecinos

        // --------- A* en grilla ----------
        int cellSize;
        int cols;
        int rows;

        inline int Idx(int cx, int cy) { return cy * cols + cx; }

        bool InBounds(int cx, int cy)
        {
            return (cx >= 0 && cy >= 0 && cx < cols && cy < rows);
        }

        PointF CellCenter(int cx, int cy)
        {
            float x = (cx + 0.5f) * cellSize;
            float y = (cy + 0.5f) * cellSize;
            return PointF(x, y);
        }

        int HeuManhattan(int ax, int ay, int bx, int by)
        {
            return Math::Abs(ax - bx) + Math::Abs(ay - by);
        }

        // Simplifica quitando puntos colineales (para verse por tramos)
        List<PointF>^ Simplificar(List<PointF>^ path)
        {
            if (path == nullptr || path->Count < 3) return path;

            List<PointF>^ outp = gcnew List<PointF>();
            outp->Add(path[0]);

            for (int i = 1; i < path->Count - 1; i++)
            {
                PointF a = outp[outp->Count - 1];
                PointF b = path[i];
                PointF c = path[i + 1];

                float abx = b.X - a.X;
                float aby = b.Y - a.Y;
                float bcx = c.X - b.X;
                float bcy = c.Y - b.Y;

                bool dirChange = false;
                bool abH = (Math::Abs(aby) < 0.0001f);
                bool abV = (Math::Abs(abx) < 0.0001f);
                bool bcH = (Math::Abs(bcy) < 0.0001f);
                bool bcV = (Math::Abs(bcx) < 0.0001f);

                if ((abH && bcV) || (abV && bcH)) dirChange = true;

                if (dirChange) outp->Add(b);
            }

            outp->Add(path[path->Count - 1]);
            return outp;
        }

        // ========= Soporte para adyacencia por rectángulos =========
        bool Overlap1D(float a1, float a2, float b1, float b2)
        {
            float left = Math::Max(a1, b1);
            float right = Math::Min(a2, b2);
            return (right - left) > 0.001f;
        }

        bool AreAdjacent(ZonaRect^ A, ZonaRect^ B)
        {
            if (A == nullptr || B == nullptr) return false;

            float ax1 = A->Rect.Left;
            float ax2 = A->Rect.Right;
            float ay1 = A->Rect.Top;
            float ay2 = A->Rect.Bottom;

            float bx1 = B->Rect.Left;
            float bx2 = B->Rect.Right;
            float by1 = B->Rect.Top;
            float by2 = B->Rect.Bottom;

            bool touchV =
                (Math::Abs(ax2 - bx1) < 0.001f || Math::Abs(bx2 - ax1) < 0.001f) &&
                Overlap1D(ay1, ay2, by1, by2);

            bool touchH =
                (Math::Abs(ay2 - by1) < 0.001f || Math::Abs(by2 - ay1) < 0.001f) &&
                Overlap1D(ax1, ax2, bx1, bx2);

            return touchV || touchH;
        }

        ZonaRect^ BuscarZonaPorNombre(String^ nombre)
        {
            if (String::IsNullOrEmpty(nombre) || zonas == nullptr) return nullptr;
            for each (ZonaRect ^ z in zonas)
            {
                if (z != nullptr && z->Nombre == nombre) return z;
            }
            return nullptr;
        }

        bool TryGetPunto(String^ nombre, PointF% outP)
        {
            outP = PointF(0, 0);

            // 1) si es punto especial
            if (puntosEspeciales != nullptr && puntosEspeciales->ContainsKey(nombre))
            {
                outP = puntosEspeciales[nombre];
                return true;
            }

            // 2) si está en nodos (compatibilidad)
            if (nodos != nullptr && nodos->ContainsKey(nombre))
            {
                outP = nodos[nombre];
                return true;
            }

            // 3) si es una zona, usar centro
            ZonaRect^ z = BuscarZonaPorNombre(nombre);
            if (z != nullptr)
            {
                outP = z->Centro();
                return true;
            }

            return false;
        }

        // Construye grid de obstáculos (true=bloqueado)
        array<bool>^ BuildBlocked(String^ inicioNombre, String^ destinoNombre)
        {
            array<bool>^ blocked = gcnew array<bool>(cols * rows);

            ZonaRect^ zInicio = BuscarZonaPorNombre(inicioNombre);
            ZonaRect^ zDestino = BuscarZonaPorNombre(destinoNombre);

            float inflate = (float)cellSize * 1.5f;

            for (int cy = 0; cy < rows; cy++)
            {
                for (int cx = 0; cx < cols; cx++)
                {
                    PointF p = CellCenter(cx, cy);
                    bool isBlocked = false;

                    for each (ZonaRect ^ z in zonas)
                    {
                        if (z == nullptr) continue;

                        if ((zInicio != nullptr && z->Nombre == zInicio->Nombre) ||
                            (zDestino != nullptr && z->Nombre == zDestino->Nombre))
                            continue;

                        RectangleF r = z->Rect;
                        r.Inflate(inflate, inflate);

                        if (r.Contains(p))
                        {
                            isBlocked = true;
                            break;
                        }
                    }

                    blocked[Idx(cx, cy)] = isBlocked;
                }
            }

            return blocked;
        }

        // A* simple (sin PriorityQueue)
        List<PointF>^ AStar(PointF start, PointF goal, array<bool>^ blocked)
        {
            int sx = (int)Math::Floor(start.X / cellSize);
            int sy = (int)Math::Floor(start.Y / cellSize);
            int gx = (int)Math::Floor(goal.X / cellSize);
            int gy = (int)Math::Floor(goal.Y / cellSize);

            if (!InBounds(sx, sy) || !InBounds(gx, gy)) return gcnew List<PointF>();

            if (blocked[Idx(sx, sy)] || blocked[Idx(gx, gy)]) {
                blocked[Idx(sx, sy)] = false;
                blocked[Idx(gx, gy)] = false;
            }

            int total = cols * rows;

            array<int>^ gScore = gcnew array<int>(total);
            array<int>^ fScore = gcnew array<int>(total);
            array<int>^ cameFrom = gcnew array<int>(total);
            array<bool>^ inOpen = gcnew array<bool>(total);
            array<bool>^ inClosed = gcnew array<bool>(total);

            for (int i = 0; i < total; i++)
            {
                gScore[i] = Int32::MaxValue / 4;
                fScore[i] = Int32::MaxValue / 4;
                cameFrom[i] = -1;
                inOpen[i] = false;
                inClosed[i] = false;
            }

            int startId = Idx(sx, sy);
            int goalId = Idx(gx, gy);

            gScore[startId] = 0;
            fScore[startId] = HeuManhattan(sx, sy, gx, gy);

            List<int>^ openList = gcnew List<int>();
            openList->Add(startId);
            inOpen[startId] = true;

            array<int>^ dx = gcnew array<int>{ 1, -1, 0, 0 };
            array<int>^ dy = gcnew array<int>{ 0, 0, 1, -1 };

            while (openList->Count > 0)
            {
                int bestIndex = 0;
                int bestId = openList[0];
                int bestF = fScore[bestId];

                for (int i = 1; i < openList->Count; i++)
                {
                    int id = openList[i];
                    if (fScore[id] < bestF)
                    {
                        bestF = fScore[id];
                        bestId = id;
                        bestIndex = i;
                    }
                }

                openList->RemoveAt(bestIndex);
                inOpen[bestId] = false;
                inClosed[bestId] = true;

                if (bestId == goalId)
                {
                    List<PointF>^ path = gcnew List<PointF>();
                    int cur = goalId;

                    while (cur != -1)
                    {
                        int cx = cur % cols;
                        int cy = cur / cols;
                        path->Insert(0, CellCenter(cx, cy));
                        cur = cameFrom[cur];
                    }

                    return Simplificar(path);
                }

                int bx = bestId % cols;
                int by = bestId / cols;

                for (int k = 0; k < 4; k++)
                {
                    int nx = bx + dx[k];
                    int ny = by + dy[k];
                    if (!InBounds(nx, ny)) continue;

                    int nid = Idx(nx, ny);
                    if (blocked[nid]) continue;
                    if (inClosed[nid]) continue;

                    int tentativeG = gScore[bestId] + 1;
                    if (tentativeG < gScore[nid])
                    {
                        cameFrom[nid] = bestId;
                        gScore[nid] = tentativeG;
                        fScore[nid] = tentativeG + HeuManhattan(nx, ny, gx, gy);

                        if (!inOpen[nid])
                        {
                            openList->Add(nid);
                            inOpen[nid] = true;
                        }
                    }
                }
            }

            return gcnew List<PointF>();
        }

        // ===== BFS (compatibilidad) =====
        List<String^>^ ReconstruirRuta(Dictionary<String^, String^>^ padre, String^ inicio, String^ destino)
        {
            List<String^>^ ruta = gcnew List<String^>();
            if (inicio == destino) { ruta->Add(inicio); return ruta; }
            if (padre == nullptr || !padre->ContainsKey(destino)) return ruta;

            String^ cur = destino;
            while (cur != inicio && padre->ContainsKey(cur))
            {
                ruta->Insert(0, cur);
                cur = padre[cur];
            }
            if (cur == inicio) ruta->Insert(0, inicio);
            return ruta;
        }

        String^ NodoMasCercano(PointF p)
        {
            String^ best = "";
            double bestD = Double::MaxValue;

            for each (KeyValuePair<String^, PointF> kvp in nodos)
            {
                PointF q = kvp.Value;
                double d = Math::Abs(q.X - p.X) + Math::Abs(q.Y - p.Y);
                if (d < bestD) { bestD = d; best = kvp.Key; }
            }
            return best;
        }

        void EnsureNodo(String^ nombre, PointF p)
        {
            if (String::IsNullOrEmpty(nombre)) return;

            if (!nodos->ContainsKey(nombre))
                nodos[nombre] = p;

            if (!adyacencia->ContainsKey(nombre))
                adyacencia[nombre] = gcnew List<String^>();
        }

        void BuildAutoConnectionsFromZones()
        {
            if (zonas == nullptr) return;

            // Conectar zonas por adyacencia de rectángulos
            for (int i = 0; i < zonas->Count; i++)
            {
                ZonaRect^ A = zonas[i];
                if (A == nullptr) continue;

                for (int j = i + 1; j < zonas->Count; j++)
                {
                    ZonaRect^ B = zonas[j];
                    if (B == nullptr) continue;

                    if (AreAdjacent(A, B))
                        ConectarNodos(A->Nombre, B->Nombre);
                }
            }

            // Conectar puertas a la zona más cercana (por centro)
            for each (KeyValuePair<String^, PointF> kvp in puntosEspeciales)
            {
                String^ puerta = kvp.Key;
                PointF pp = kvp.Value;

                String^ zonaCercana = "";
                double bestD = Double::MaxValue;

                for each (ZonaRect ^ z in zonas)
                {
                    if (z == nullptr) continue;
                    PointF c = z->Centro();
                    double d = Math::Abs(c.X - pp.X) + Math::Abs(c.Y - pp.Y);
                    if (d < bestD) { bestD = d; zonaCercana = z->Nombre; }
                }

                if (!String::IsNullOrEmpty(zonaCercana))
                    ConectarNodos(puerta, zonaCercana);
            }
        }

    public:
        GrafoCampus()
        {
            zonas = gcnew List<ZonaRect^>();

            puntosEspeciales = gcnew Dictionary<String^, PointF>();
            puntosEspeciales["Puerta principal"] = PointF(560.0f, 445.0f);
            puntosEspeciales["Puerta peatonal principal"] = PointF(600.0f, 445.0f);
            puntosEspeciales["Puerta Riva-Agüero (peatonal)"] = PointF(600.0f, 15.0f);
            puntosEspeciales["Puerta Riva-Agüero (vehicular)"] = PointF(540.0f, 15.0f);
            puntosEspeciales["Puerta peatonal Urubamba"] = PointF(30.0f, 95.0f);
            puntosEspeciales["Puerta peatonal N° 8"] = PointF(850.0f, 320.0f);

            // grilla
            cellSize = 10;
            cols = (int)Math::Ceiling((double)MAP_W / cellSize);
            rows = (int)Math::Ceiling((double)MAP_H / cellSize);

            // compatibilidad BFS
            nodos = gcnew Dictionary<String^, PointF>();
            adyacencia = gcnew Dictionary<String^, List<String^>^>();

            // registrar puntos especiales también como nodos
            for each (KeyValuePair<String^, PointF> kvp in puntosEspeciales)
                EnsureNodo(kvp.Key, kvp.Value);
        }

        // ====== API NUEVA (A*) ======
        void SetZonas(List<ZonaRect^>^ nuevasZonas)
        {
            zonas = (nuevasZonas != nullptr) ? nuevasZonas : gcnew List<ZonaRect^>();

            // Crear nodos para cada zona (centro)
            for each (ZonaRect ^ z in zonas)
            {
                if (z == nullptr || String::IsNullOrEmpty(z->Nombre)) continue;
                EnsureNodo(z->Nombre, z->Centro());
            }

            // Conexiones automáticas (para BFS UI) basadas en adyacencia de rectángulos
            BuildAutoConnectionsFromZones();
        }

        Dictionary<String^, PointF>^ GetPuntosEspeciales()
        {
            return puntosEspeciales;
        }

        List<PointF>^ EncontrarRutaPuntos(String^ inicio, String^ destino)
        {
            PointF pInicio, pDestino;
            if (!TryGetPunto(inicio, pInicio) || !TryGetPunto(destino, pDestino))
                return gcnew List<PointF>();

            array<bool>^ blocked = BuildBlocked(inicio, destino);
            return AStar(pInicio, pDestino, blocked);
        }

        // ====== API COMPATIBILIDAD (lo que te falta en tu UI) ======
        void AgregarNodo(String^ nombre, int x, int y)
        {
            EnsureNodo(nombre, PointF((float)x, (float)y));
        }

        void ConectarNodos(String^ a, String^ b)
        {
            if (String::IsNullOrEmpty(a) || String::IsNullOrEmpty(b)) return;

            if (!adyacencia->ContainsKey(a)) adyacencia[a] = gcnew List<String^>();
            if (!adyacencia->ContainsKey(b)) adyacencia[b] = gcnew List<String^>();

            if (!adyacencia[a]->Contains(b)) adyacencia[a]->Add(b);
            if (!adyacencia[b]->Contains(a)) adyacencia[b]->Add(a);

            // asegurar nodos aunque no existan todavía
            if (!nodos->ContainsKey(a))
            {
                PointF p; if (TryGetPunto(a, p)) nodos[a] = p;
                else nodos[a] = PointF(0, 0);
            }
            if (!nodos->ContainsKey(b))
            {
                PointF p; if (TryGetPunto(b, p)) nodos[b] = p;
                else nodos[b] = PointF(0, 0);
            }
        }

        List<String^>^ EncontrarRuta(String^ inicio, String^ destino)
        {
            // BFS por adyacencia (para tu UI vieja)
            if (String::IsNullOrEmpty(inicio) || String::IsNullOrEmpty(destino))
                return gcnew List<String^>();

            if (!adyacencia->ContainsKey(inicio) || !adyacencia->ContainsKey(destino))
                return gcnew List<String^>();

            if (inicio == destino) {
                List<String^>^ r = gcnew List<String^>();
                r->Add(inicio);
                return r;
            }

            Dictionary<String^, bool>^ visitado = gcnew Dictionary<String^, bool>();
            Dictionary<String^, String^>^ padre = gcnew Dictionary<String^, String^>();

            List<String^>^ cola = gcnew List<String^>();
            for each (String ^ k in adyacencia->Keys) visitado[k] = false;

            visitado[inicio] = true;
            cola->Add(inicio);

            int idx = 0;
            while (idx < cola->Count)
            {
                String^ cur = cola[idx++];
                if (cur == destino)
                    return ReconstruirRuta(padre, inicio, destino);

                for each (String ^ nb in adyacencia[cur])
                {
                    if (!visitado->ContainsKey(nb)) visitado[nb] = false;
                    if (!visitado[nb])
                    {
                        visitado[nb] = true;
                        padre[nb] = cur;
                        cola->Add(nb);
                    }
                }
            }

            return gcnew List<String^>();
        }

        Drawing::Point ObtenerPosicionNodo(String^ nombre)
        {
            PointF p;
            if (TryGetPunto(nombre, p))
                return Drawing::Point((int)Math::Round(p.X), (int)Math::Round(p.Y));

            return Drawing::Point(0, 0);
        }

        // (Opcional) Exponer nodos por si quieres debug
        property Dictionary<String^, PointF>^ Nodos {
            Dictionary<String^, PointF>^ get() { return nodos; }
        }
    };

} // namespace GUIApp
