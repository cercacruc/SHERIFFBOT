#pragma once

namespace GUIApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    using namespace BotModel;
    using namespace BotService;

    /// <summary>
    /// Formulario para mostrar gráfica de alertas solucionadas por usuario
    /// </summary>
    public ref class GraficAlertUserSolForm : public System::Windows::Forms::Form
    {
    public:
        DatosUsuario^ Usuario;
        GraficAlertUserSolForm(/*DatosUsuario^ usuario*/)
        {
            InitializeComponent();
            //Usuario = usuario;

            // Inicializar datos
            usuarios = gcnew List<DatosUsuario^>();
            datosGrafico = gcnew Dictionary<String^, int>();
            debeMostrarGrafico = false;
        }

    protected:
        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        ~GraficAlertUserSolForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        System::ComponentModel::Container^ components;

        // Variables para el gráfico
        List<DatosUsuario^>^ usuarios;
        Dictionary<String^, int>^ datosGrafico;
        bool debeMostrarGrafico;

    private: System::Windows::Forms::PictureBox^ pictureBoxGrafico;
    private: System::Windows::Forms::Button^ btnSalir;
    private: System::Windows::Forms::Label^ labelTitulo;
    private: System::Windows::Forms::ComboBox^ comboBoxTipoGrafico;
    private: System::Windows::Forms::Label^ labelTipoGrafico;

#pragma region Windows Form Designer generated code
           /// <summary>
           /// Método necesario para admitir el Diseñador. No se puede modificar
           /// el contenido de este método con el editor de código.
           /// </summary>
           void InitializeComponent(void)
           {
               this->pictureBoxGrafico = (gcnew System::Windows::Forms::PictureBox());
               this->btnSalir = (gcnew System::Windows::Forms::Button());
               this->labelTitulo = (gcnew System::Windows::Forms::Label());
               this->comboBoxTipoGrafico = (gcnew System::Windows::Forms::ComboBox());
               this->labelTipoGrafico = (gcnew System::Windows::Forms::Label());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGrafico))->BeginInit();
               this->SuspendLayout();
               // 
               // pictureBoxGrafico
               // 
               this->pictureBoxGrafico->BackColor = System::Drawing::Color::White;
               this->pictureBoxGrafico->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->pictureBoxGrafico->Location = System::Drawing::Point(12, 80);
               this->pictureBoxGrafico->Name = L"pictureBoxGrafico";
               this->pictureBoxGrafico->Size = System::Drawing::Size(860, 500);
               this->pictureBoxGrafico->TabIndex = 0;
               this->pictureBoxGrafico->TabStop = false;
               this->pictureBoxGrafico->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GraficAlertUserSolForm::pictureBoxGrafico_Paint);
               // 
               // btnSalir
               // 
               this->btnSalir->Location = System::Drawing::Point(12, 12);
               this->btnSalir->Name = L"btnSalir";
               this->btnSalir->Size = System::Drawing::Size(100, 30);
               this->btnSalir->TabIndex = 1;
               this->btnSalir->Text = L"Salir";
               this->btnSalir->UseVisualStyleBackColor = true;
               this->btnSalir->Click += gcnew System::EventHandler(this, &GraficAlertUserSolForm::btnSalir_Click);
               // 
               // labelTitulo
               // 
               this->labelTitulo->AutoSize = true;
               this->labelTitulo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->labelTitulo->Location = System::Drawing::Point(329, 40);
               this->labelTitulo->Name = L"labelTitulo";
               this->labelTitulo->Size = System::Drawing::Size(259, 29);
               this->labelTitulo->TabIndex = 2;
               this->labelTitulo->Text = L"Alertas Solucionadas";
               // 
               // comboBoxTipoGrafico
               // 
               this->comboBoxTipoGrafico->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
               this->comboBoxTipoGrafico->FormattingEnabled = true;
               this->comboBoxTipoGrafico->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Barras", L"Torta" });
               this->comboBoxTipoGrafico->Location = System::Drawing::Point(650, 45);
               this->comboBoxTipoGrafico->Name = L"comboBoxTipoGrafico";
               this->comboBoxTipoGrafico->Size = System::Drawing::Size(120, 24);
               this->comboBoxTipoGrafico->TabIndex = 3;
               this->comboBoxTipoGrafico->SelectedIndexChanged += gcnew System::EventHandler(this, &GraficAlertUserSolForm::comboBoxTipoGrafico_SelectedIndexChanged);
               // 
               // labelTipoGrafico
               // 
               this->labelTipoGrafico->AutoSize = true;
               this->labelTipoGrafico->Location = System::Drawing::Point(650, 25);
               this->labelTipoGrafico->Name = L"labelTipoGrafico";
               this->labelTipoGrafico->Size = System::Drawing::Size(100, 16);
               this->labelTipoGrafico->TabIndex = 4;
               this->labelTipoGrafico->Text = L"Tipo de Gráfico";
               // 
               // GraficAlertUserSolForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(884, 595);
               this->Controls->Add(this->labelTipoGrafico);
               this->Controls->Add(this->comboBoxTipoGrafico);
               this->Controls->Add(this->labelTitulo);
               this->Controls->Add(this->btnSalir);
               this->Controls->Add(this->pictureBoxGrafico);
               this->Name = L"GraficAlertUserSolForm";
               this->Text = L"Gráfica - Alertas Solucionadas por Usuario";
               this->Load += gcnew System::EventHandler(this, &GraficAlertUserSolForm::GraficAlertUserSolForm_Load);
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxGrafico))->EndInit();
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion

    private:
        // Método para cargar los datos del gráfico
        void CargarDatosGrafico()
        {
            try
            {
                // Obtener todas las alertas
                List<Alert^>^ todasAlertas = Service::ShowAlertas();

                // Limpiar datos previos
                datosGrafico->Clear();

                // Contar alertas solucionadas por usuario
                for each (Alert ^ alerta in todasAlertas)
                {
                    if (alerta->Solucionado && alerta->UsuarioID > 0)
                    {
                        String^ nombreUsuario = alerta->UsuarioNombre;

                        // Si el nombre de usuario está vacío, buscar el usuario por ID
                        if (String::IsNullOrEmpty(nombreUsuario))
                        {
                            DatosUsuario^ usuario = Service::buscarUsuarioID(alerta->UsuarioID);
                            if (usuario != nullptr)
                            {
                                nombreUsuario = usuario->Nombre;
                            }
                            else
                            {
                                nombreUsuario = "Usuario " + alerta->UsuarioID.ToString();
                            }
                        }

                        if (datosGrafico->ContainsKey(nombreUsuario))
                        {
                            datosGrafico[nombreUsuario]++;
                        }
                        else
                        {
                            datosGrafico->Add(nombreUsuario, 1);
                        }
                    }
                }

                // Si no hay datos, agregar un mensaje
                if (datosGrafico->Count == 0)
                {
                    datosGrafico->Add("Sin datos", 0);
                }

                debeMostrarGrafico = true;
                pictureBoxGrafico->Invalidate();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error al cargar datos: " + ex->Message, "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

    private: System::Void pictureBoxGrafico_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        Graphics^ g = e->Graphics;
        g->Clear(Color::White);
        g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

        if (!debeMostrarGrafico || datosGrafico->Count == 0) {
            // Mostrar mensaje cuando no hay datos
            Brush^ textoBrush = gcnew SolidBrush(Color::Gray);
            System::Drawing::Font^ font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Italic);
            String^ mensaje = "No hay datos para mostrar";
            SizeF textSize = g->MeasureString(mensaje, font);

            float x = (pictureBoxGrafico->Width - textSize.Width) / 2;
            float y = (pictureBoxGrafico->Height - textSize.Height) / 2;

            g->DrawString(mensaje, font, textoBrush, x, y);

            delete textoBrush;
            delete font;
            return;
        }

        try {
            // Determinar qué tipo de gráfico mostrar
            String^ tipoGrafico = comboBoxTipoGrafico->SelectedItem != nullptr ?
                comboBoxTipoGrafico->SelectedItem->ToString() : "Barras";

            if (tipoGrafico == "Barras")
                DibujarGraficoBarras(g, pictureBoxGrafico->Width, pictureBoxGrafico->Height);
            else if (tipoGrafico == "Torta")
                DibujarGraficoTorta(g, pictureBoxGrafico->Width, pictureBoxGrafico->Height);
        }
        catch (Exception^ ex) {
            Brush^ errorBrush = gcnew SolidBrush(Color::Red);
            System::Drawing::Font^ errorFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
            g->DrawString("Error al dibujar el gráfico: " + ex->Message,
                errorFont, errorBrush, 10, 10);
            delete errorBrush;
            delete errorFont;
        }
    }

    private: void DibujarGraficoBarras(Graphics^ g, int width, int height) {
        // Configuración del gráfico
        int margenIzquierdo = 100;
        int margenDerecho = 40;
        int margenSuperior = 60;
        int margenInferior = 100;

        int areaGraficoWidth = width - margenIzquierdo - margenDerecho;
        int areaGraficoHeight = height - margenSuperior - margenInferior;

        // Calcular valores máximos para la escala
        int maxCantidad = 1;
        for each (KeyValuePair<String^, int> ^ par in datosGrafico) {
            if (par->Value > maxCantidad)
                maxCantidad = par->Value;
        }

        // Dibujar título
        Brush^ tituloBrush = gcnew SolidBrush(Color::DarkBlue);
        System::Drawing::Font^ tituloFont = gcnew System::Drawing::Font("Arial", 12, FontStyle::Bold);
        String^ titulo = "Alertas Solucionadas por Usuario - Gráfico de Barras";
        SizeF tituloSize = g->MeasureString(titulo, tituloFont);
        g->DrawString(titulo, tituloFont, tituloBrush, (width - tituloSize.Width) / 2, 10);
        delete tituloBrush;
        delete tituloFont;

        // Dibujar ejes
        Pen^ ejePen = gcnew Pen(Color::Black, 2);
        g->DrawLine(ejePen, margenIzquierdo, margenSuperior, margenIzquierdo, margenSuperior + areaGraficoHeight); // Eje Y
        g->DrawLine(ejePen, margenIzquierdo, margenSuperior + areaGraficoHeight,
            margenIzquierdo + areaGraficoWidth, margenSuperior + areaGraficoHeight); // Eje X

        // Configuración de barras
        int numBarras = datosGrafico->Count;
        int anchoBarra = areaGraficoWidth / (numBarras + 2);
        int espacioEntreBarras = anchoBarra / 3;
        int anchoBarraReal = anchoBarra - espacioEntreBarras;

        // Colores para las barras
        array<Color>^ colores = {
            Color::Blue, Color::Red, Color::Green, Color::Orange,
            Color::Purple, Color::Brown, Color::Teal, Color::Magenta,
            Color::DarkGreen, Color::DarkRed, Color::DarkBlue, Color::Goldenrod
        };

        // Dibujar barras
        int indice = 0;
        for each (KeyValuePair<String^, int> ^ par in datosGrafico) {
            String^ nombreUsuario = par->Key;
            int cantidad = par->Value;

            // Calcular posición y tamaño de la barra
            int x = margenIzquierdo + (indice * anchoBarra) + espacioEntreBarras;
            int alturaBarra = (int)((cantidad / (double)maxCantidad) * areaGraficoHeight);
            int y = margenSuperior + areaGraficoHeight - alturaBarra;

            // Seleccionar color
            Color colorBarra = colores[indice % colores->Length];
            Brush^ barraBrush = gcnew SolidBrush(colorBarra);

            // Dibujar barra
            g->FillRectangle(barraBrush, x, y, anchoBarraReal, alturaBarra);

            // Borde de la barra
            Pen^ bordePen = gcnew Pen(Color::Black, 1);
            g->DrawRectangle(bordePen, x, y, anchoBarraReal, alturaBarra);

            // Etiqueta con la cantidad
            Brush^ textoBrush = gcnew SolidBrush(Color::White);
            System::Drawing::Font^ textoFont = gcnew System::Drawing::Font("Arial", 8, FontStyle::Bold);
            String^ etiquetaCantidad = cantidad.ToString();
            SizeF textoSize = g->MeasureString(etiquetaCantidad, textoFont);

            float textoX = x + (anchoBarraReal - textoSize.Width) / 2;
            float textoY;

            if (alturaBarra > textoSize.Height + 4) {
                textoY = y + (alturaBarra - textoSize.Height) / 2;
            }
            else {
                textoY = y - textoSize.Height - 2;
                delete textoBrush;
                textoBrush = gcnew SolidBrush(Color::Black);
            }

            g->DrawString(etiquetaCantidad, textoFont, textoBrush, textoX, textoY);

            // Etiqueta del nombre del usuario (eje X)
            Brush^ nombreBrush = gcnew SolidBrush(Color::Black);
            System::Drawing::Font^ nombreFont = gcnew System::Drawing::Font("Arial", 8);

            // Acortar nombre si es muy largo
            String^ nombreMostrar = nombreUsuario;
            if (nombreMostrar->Length > 10) {
                nombreMostrar = nombreMostrar->Substring(0, 8) + "...";
            }

            SizeF nombreSize = g->MeasureString(nombreMostrar, nombreFont);
            float nombreX = x + (anchoBarraReal - nombreSize.Width) / 2;
            float nombreY = margenSuperior + areaGraficoHeight + 5;

            // Rotar texto si hay muchos usuarios
            if (numBarras > 6) {
                g->TranslateTransform(nombreX + nombreSize.Width / 2, nombreY);
                g->RotateTransform(-45);
                g->DrawString(nombreMostrar, nombreFont, nombreBrush, -nombreSize.Width / 2, 0);
                g->ResetTransform();
            }
            else {
                g->DrawString(nombreMostrar, nombreFont, nombreBrush, nombreX, nombreY);
            }

            // Mostrar nombre completo como tooltip (se puede implementar con ToolTip control)
            if (nombreUsuario != nombreMostrar) {
                g->DrawString(nombreUsuario, nombreFont, nombreBrush, nombreX, nombreY + 15);
            }

            // Liberar recursos
            delete barraBrush;
            delete bordePen;
            delete textoBrush;
            delete textoFont;
            delete nombreBrush;
            delete nombreFont;

            indice++;
        }

        // Dibujar escala del eje Y
        DibujarEscalaEjeY(g, margenIzquierdo, margenSuperior, areaGraficoWidth, areaGraficoHeight, maxCantidad);

        // Etiqueta del eje Y
        Brush^ escalaBrush = gcnew SolidBrush(Color::Black);
        System::Drawing::Font^ ejeYFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
        String^ etiquetaEjeY = "Cantidad de Alertas";
        SizeF ejeYSize = g->MeasureString(etiquetaEjeY, ejeYFont);
        g->TranslateTransform(20, margenSuperior + areaGraficoHeight / 2);
        g->RotateTransform(-90);
        g->DrawString(etiquetaEjeY, ejeYFont, escalaBrush, -ejeYSize.Height / 2, 0);
        g->ResetTransform();

        // Etiqueta del eje X
        System::Drawing::Font^ ejeXFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
        String^ etiquetaEjeX = "Usuarios";
        SizeF ejeXSize = g->MeasureString(etiquetaEjeX, ejeXFont);
        g->DrawString(etiquetaEjeX, ejeXFont, escalaBrush,
            margenIzquierdo + (areaGraficoWidth - ejeXSize.Width) / 2,
            margenSuperior + areaGraficoHeight + 50);

        // Total de alertas
        int totalAlertas = 0;
        for each (KeyValuePair<String^, int> ^ par in datosGrafico) {
            totalAlertas += par->Value;
        }

        Brush^ totalBrush = gcnew SolidBrush(Color::DarkGreen);
        System::Drawing::Font^ totalFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
        String^ totalTexto = String::Format("Total de alertas solucionadas: {0}", totalAlertas);
        g->DrawString(totalTexto, totalFont, totalBrush, margenIzquierdo, 35);

        // Liberar recursos finales
        delete ejePen;
        delete escalaBrush;
        delete ejeYFont;
        delete ejeXFont;
        delete totalBrush;
        delete totalFont;
    }

    private: void DibujarGraficoTorta(Graphics^ g, int width, int height) {
        // Configuración del gráfico de torta
        int centroX = width / 2;
        int centroY = height / 2;
        int radio = Math::Min(width, height) / 3;

        // Dibujar título
        Brush^ tituloBrush = gcnew SolidBrush(Color::DarkBlue);
        System::Drawing::Font^ tituloFont = gcnew System::Drawing::Font("Arial", 12, FontStyle::Bold);
        String^ titulo = "Alertas Solucionadas por Usuario - Gráfico de Torta";
        SizeF tituloSize = g->MeasureString(titulo, tituloFont);
        g->DrawString(titulo, tituloFont, tituloBrush, (width - tituloSize.Width) / 2, 10);
        delete tituloBrush;
        delete tituloFont;

        // Calcular total para porcentajes
        int totalAlertas = 0;
        for each (KeyValuePair<String^, int> ^ par in datosGrafico) {
            totalAlertas += par->Value;
        }

        if (totalAlertas == 0) return;

        // Colores para los segmentos
        array<Color>^ colores = {
            Color::Red, Color::Blue, Color::Green, Color::Orange,
            Color::Purple, Color::Brown, Color::Teal, Color::Magenta,
            Color::DarkGreen, Color::DarkRed, Color::DarkBlue, Color::Goldenrod
        };

        // Dibujar segmentos - CORREGIDO: usando tipos explícitos
        float anguloInicio = 0.0f;
        int indice = 0;

        for each (KeyValuePair<String^, int> ^ par in datosGrafico) {
            String^ nombreUsuario = par->Key;
            int cantidad = par->Value;

            float anguloBarrido = (cantidad / (float)totalAlertas) * 360.0f;


            Brush^ segmentoBrush = gcnew SolidBrush(colores[indice % colores->Length]);

            // Usar RectangleF en lugar de valores separados
            RectangleF rect = RectangleF(centroX - radio, centroY - radio, radio * 2, radio * 2);
            g->FillPie(segmentoBrush, (float)(centroX - radio), (float)(centroY - radio), (float)(radio * 2), (float)(radio * 2), anguloInicio, anguloBarrido);

            // Borde del segmento
            Pen^ bordePen = gcnew Pen(Color::Black, 1);
            g->DrawPie(bordePen, rect, anguloInicio, anguloBarrido);

            // Calcular posición para la etiqueta
            float anguloMedio = anguloInicio + anguloBarrido / 2.0f;
            float anguloRadianes = anguloMedio * (float)Math::PI / 180.0f;
            float etiquetaX = centroX + (radio + 20) * (float)Math::Cos(anguloRadianes);
            float etiquetaY = centroY + (radio + 20) * (float)Math::Sin(anguloRadianes);

            // Dibujar línea conectora
            float lineaX = centroX + (radio - 10) * (float)Math::Cos(anguloRadianes);
            float lineaY = centroY + (radio - 10) * (float)Math::Sin(anguloRadianes);
            g->DrawLine(bordePen, lineaX, lineaY, etiquetaX, etiquetaY);

            // Etiqueta con porcentaje y nombre
            float porcentaje = (cantidad / (float)totalAlertas) * 100.0f;
            String^ etiqueta = String::Format("{0}: {1} ({2:F1}%)", nombreUsuario, cantidad, porcentaje);

            Brush^ textoBrush = gcnew SolidBrush(Color::Black);
            System::Drawing::Font^ textoFont = gcnew System::Drawing::Font("Arial", 8);
            SizeF textoSize = g->MeasureString(etiqueta, textoFont);

            // Ajustar posición según cuadrante
            float textoX = etiquetaX;
            float textoY = etiquetaY - textoSize.Height / 2;

            if (etiquetaX > centroX) {
                // Derecha - alinear a la izquierda
                g->DrawString(etiqueta, textoFont, textoBrush, textoX, textoY);
            }
            else {
                // Izquierda - alinear a la derecha
                g->DrawString(etiqueta, textoFont, textoBrush, textoX - textoSize.Width, textoY);
            }

            // Liberar recursos
            delete segmentoBrush;
            delete bordePen;
            delete textoBrush;
            delete textoFont;

            anguloInicio += anguloBarrido;
            indice++;
        }

        // Total en el centro
        Brush^ totalBrush = gcnew SolidBrush(Color::DarkRed);
        System::Drawing::Font^ totalFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
        String^ totalTexto = String::Format("Total: {0}", totalAlertas);
        SizeF totalSize = g->MeasureString(totalTexto, totalFont);
        g->DrawString(totalTexto, totalFont, totalBrush,
            centroX - totalSize.Width / 2, centroY - totalSize.Height / 2);

        delete totalBrush;
        delete totalFont;
    }

    private: void DibujarEscalaEjeY(Graphics^ g, int margenIzquierdo, int margenSuperior, int areaGraficoWidth, int areaGraficoHeight, int maxCantidad) {
        Brush^ escalaBrush = gcnew SolidBrush(Color::Black);
        System::Drawing::Font^ escalaFont = gcnew System::Drawing::Font("Arial", 8);
        Pen^ lineaEscalaPen = gcnew Pen(Color::Gray, 1);

        int numLineasEscala = 10;
        for (int i = 0; i <= numLineasEscala; i++) {
            double valor = (i / (double)numLineasEscala) * maxCantidad;
            int y = margenSuperior + areaGraficoHeight - (int)((i / (double)numLineasEscala) * areaGraficoHeight);

            // Línea de guía
            g->DrawLine(lineaEscalaPen, margenIzquierdo, y, margenIzquierdo + areaGraficoWidth, y);

            // Etiqueta del valor
            String^ etiquetaValor = valor.ToString("F0");
            SizeF etiquetaSize = g->MeasureString(etiquetaValor, escalaFont);
            g->DrawString(etiquetaValor, escalaFont, escalaBrush,
                margenIzquierdo - etiquetaSize.Width - 5, y - etiquetaSize.Height / 2);
        }

        delete escalaBrush;
        delete escalaFont;
        delete lineaEscalaPen;
    }

    private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }

    private: System::Void GraficAlertUserSolForm_Load(System::Object^ sender, System::EventArgs^ e) {
        try {
            // Configurar combo box
            comboBoxTipoGrafico->SelectedIndex = 0;

            // Cargar datos
            CargarDatosGrafico();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error al cargar el formulario: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void comboBoxTipoGrafico_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        // Redibujar el gráfico cuando cambia el tipo
        if (debeMostrarGrafico) {
            pictureBoxGrafico->Invalidate();
        }
    }
    };
}