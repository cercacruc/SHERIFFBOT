#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

namespace GUIApp {

    // ============================
    //  Helpers de UI reutilizables
    // ============================
    public ref class UIHelpers abstract sealed
    {
        
    public:
        static int GetAutoRadius(Button^ b)
        {
            int r = b->Height / 2 - 1;      // píldora según altura
            if (r > 18) r = 18;             // límite superior como ya usabas
            if (r < 4)  r = 4;              // mínimo para que no se vea cuadrado
            return r;
        }
        static void SetRoundedRegionAuto(Button^ btn)
        {
            if (!btn) return;
            int r = GetAutoRadius(btn);

            GraphicsPath^ path = gcnew GraphicsPath();
            Rectangle rect = Rectangle(0, 0, btn->Width, btn->Height);
            int d = r * 2;

            path->AddArc(rect.X, rect.Y, d, d, 180, 90);
            path->AddArc(rect.Right - d, rect.Y, d, d, 270, 90);
            path->AddArc(rect.Right - d, rect.Bottom - d, d, d, 0, 90);
            path->AddArc(rect.X, rect.Bottom - d, d, d, 90, 90);
            path->CloseFigure();

            btn->Region = gcnew Region(path);
        }

        // -----------------------------------------
        // 1) Región redondeada para cualquier botón
        // -----------------------------------------
        static void SetRoundedRegion(Button^ btn, int radius)
        {
            GraphicsPath^ path = gcnew GraphicsPath();

            int r = radius;
            Rectangle rect = Rectangle(0, 0, btn->Width, btn->Height);
            int d = r * 2;

            path->AddArc(rect.X, rect.Y, d, d, 180, 90);
            path->AddArc(rect.Right - d, rect.Y, d, d, 270, 90);
            path->AddArc(rect.Right - d, rect.Bottom - d, d, d, 0, 90);
            path->AddArc(rect.X, rect.Bottom - d, d, d, 90, 90);
            path->CloseFigure();

            btn->Region = gcnew Region(path);
        }

        // ----------------------------------------------------
        // 2) Borde redondeado celeste (para botones secundarios)
        //    Se usa en el evento Paint del botón.
        // ----------------------------------------------------
        static void OutlineButton_Paint(Object^ sender, PaintEventArgs^ e)
        {
            Button^ b = safe_cast<Button^>(sender);

            e->Graphics->SmoothingMode =
                System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

            int r = GetAutoRadius(b);

            Rectangle rect(0, 0, b->Width - 1, b->Height - 1);
            int d = r * 2;

            GraphicsPath^ path = gcnew GraphicsPath();
            path->AddArc(rect.X, rect.Y, d, d, 180, 90);
            path->AddArc(rect.Right - d, rect.Y, d, d, 270, 90);
            path->AddArc(rect.Right - d, rect.Bottom - d, d, d, 0, 90);
            path->AddArc(rect.X, rect.Bottom - d, d, d, 90, 90);
            path->CloseFigure();

            Pen^ pen = gcnew Pen(Color::FromArgb(0, 140, 255), 1.5f);
            e->Graphics->DrawPath(pen, path);
        }

        // ---------------------------------------------------------
        // 3) Panel / tarjeta redondeada con relleno y borde moderno
        //    Se usa en el evento Paint de un Panel normal.
        // ---------------------------------------------------------
        static void RoundedPanel_Paint(Object^ sender, PaintEventArgs^ e)
        {
            Panel^ p = safe_cast<Panel^>(sender);

            e->Graphics->SmoothingMode = SmoothingMode::AntiAlias;

            int radius = 24;
            Rectangle rect = Rectangle(0, 0, p->Width - 1, p->Height - 1);
            int d = radius * 2;

            GraphicsPath^ path = gcnew GraphicsPath();
            path->AddArc(rect.X, rect.Y, d, d, 180, 90);
            path->AddArc(rect.Right - d, rect.Y, d, d, 270, 90);
            path->AddArc(rect.Right - d, rect.Bottom - d, d, d, 0, 90);
            path->AddArc(rect.X, rect.Bottom - d, d, d, 90, 90);
            path->CloseFigure();

            // Relleno oscuro de la tarjeta
            SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(20, 27, 47)); // #141B2F
            e->Graphics->FillPath(brush, path);

            // Borde azul cian
            Pen^ pen = gcnew Pen(Color::FromArgb(40, 209, 255), 1.0f);
            e->Graphics->DrawPath(pen, path);
        }
    };


    public ref class DarkTabControl : public TabControl
    {
    public:
        DarkTabControl()
        {
            // El control se dibuja a sí mismo
            this->SetStyle(
                static_cast<ControlStyles>(
                    ControlStyles::UserPaint |
                    ControlStyles::AllPaintingInWmPaint |
                    ControlStyles::OptimizedDoubleBuffer),
                true);
            this->UpdateStyles();

            this->DrawMode = TabDrawMode::OwnerDrawFixed;
            this->ItemSize = System::Drawing::Size(200, 30);
            this->SizeMode = TabSizeMode::Fixed;
            this->Padding = System::Drawing::Point(0, 0);

            this->BackColor = Color::FromArgb(20, 27, 47);
            this->ForeColor = Color::FromArgb(224, 231, 255);
        }

    protected:

        virtual void OnPaint(PaintEventArgs^ e) override
        {
            using namespace System::Drawing;
            using namespace System::Drawing::Drawing2D;

            Graphics^ g = e->Graphics;
            g->SmoothingMode = SmoothingMode::AntiAlias;

            // 1) Fondo completo del TabControl (incluye área de páginas)
            Color fullBack = Color::FromArgb(20, 27, 47);
            g->Clear(fullBack);

            // 2) Franja donde viven las pestañas (header)
            int headerH = this->ItemSize.Height + 4;
            Rectangle headerRect(0, 0, this->Width, headerH);
            Color headerBack = Color::FromArgb(10, 16, 32);
            g->FillRectangle(gcnew SolidBrush(headerBack), headerRect);

            // 3) Dibujar cada pestaña
            Color backSel = Color::FromArgb(37, 99, 235);   // azul seleccionado
            Color backNorm = Color::FromArgb(15, 23, 42);    // azul oscuro
            Color border = Color::FromArgb(56, 189, 248);  // borde celeste
            Color foreSel = Color::White;
            Color foreNorm = Color::FromArgb(226, 232, 240);

            for (int i = 0; i < this->TabPages->Count; ++i)
            {
                TabPage^ page = this->TabPages[i];
                if (page == nullptr) continue;

                Rectangle rect = this->GetTabRect(i);
                bool selected = (i == this->SelectedIndex);

                Color back = selected ? backSel : backNorm;
                Color fore = selected ? foreSel : foreNorm;

                rect.Inflate(-2, -2);

                // Fondo pestaña
                g->FillRectangle(gcnew SolidBrush(back), rect);
                // Borde pestaña
                g->DrawRectangle(gcnew Pen(border, 1.5f), rect);

                // Texto centrado
                StringFormat^ sf = gcnew StringFormat();
                sf->Alignment = StringAlignment::Center;
                sf->LineAlignment = StringAlignment::Center;

                g->DrawString(
                    page->Text,
                    gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold),
                    gcnew SolidBrush(fore),
                    RectangleF(
                        (float)rect.X,
                        (float)rect.Y,
                        (float)rect.Width,
                        (float)rect.Height),
                    sf
                );
            }

            // 4) (Opcional) borde exterior del TabControl en oscuro
            // g->DrawRectangle(gcnew Pen(Color::FromArgb(15,23,42), 1),
            //                  Rectangle(0, 0, this->Width - 1, this->Height - 1));
        }

        // No dejamos que el fondo por defecto meta blanco
        virtual void OnPaintBackground(PaintEventArgs^ e) override
        {
            // No llamamos a TabControl::OnPaintBackground;
            // el fondo ya se pinta en OnPaint.
        }

    };

} // namespace GUIApp
