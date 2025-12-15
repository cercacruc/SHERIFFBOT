#pragma once
#include "UIStyles.h"

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
    using namespace System::Threading;

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

            this->DoubleBuffered = true;

            this->BackColor = System::Drawing::Color::FromArgb(5, 8, 22);
            this->ForeColor = System::Drawing::Color::White;
            this->StartPosition = FormStartPosition::CenterScreen;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;

            // Inicializar datos
            usuarios = gcnew List<DatosUsuario^>();
            datosGrafico = gcnew Dictionary<String^, int>();
            debeMostrarGrafico = false;
            ApplyDarkTheme();
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
            StopTimer();
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
           // ---------- Estilo visual ----------
    private:
        void ApplyDarkTheme()
        {
            // Form
            this->BackColor = Color::FromArgb(20, 27, 47);
            this->ForeColor = Color::FromArgb(226, 232, 240);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;

            // Área del gráfico
            this->pictureBoxGrafico->BackColor = Color::White;
            this->pictureBoxGrafico->BorderStyle = BorderStyle::FixedSingle;

            // Título
            this->labelTitulo->ForeColor = Color::FromArgb(241, 245, 249);
            this->labelTitulo->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);

            // Label "Tipo de gráfico"
            this->labelTipoGrafico->ForeColor = Color::FromArgb(200, 210, 230);
            this->labelTipoGrafico->Font = gcnew Drawing::Font("Segoe UI", 9, FontStyle::Regular);

            // Combo tipo de gráfico
            this->comboBoxTipoGrafico->BackColor = Color::FromArgb(10, 16, 32);
            this->comboBoxTipoGrafico->ForeColor = Color::FromArgb(226, 232, 240);
            this->comboBoxTipoGrafico->FlatStyle = FlatStyle::Flat;
            this->comboBoxTipoGrafico->Font = gcnew Drawing::Font("Segoe UI", 9);

            // Botón "Volver/Salir" como PRIMARIO (es el único botón)
            this->btnSalir->FlatStyle = FlatStyle::Flat;
            this->btnSalir->FlatAppearance->BorderSize = 0;
            this->btnSalir->BackColor = Color::FromArgb(0, 140, 255);
            this->btnSalir->ForeColor = Color::White;
            this->btnSalir->Font = gcnew Drawing::Font("Segoe UI", 9, FontStyle::Bold);
            UIHelpers::SetRoundedRegionAuto(this->btnSalir);
        }

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

        Color chartBg = Color::FromArgb(15, 23, 42);
        Color emptyText = Color::FromArgb(148, 163, 184);

        g->Clear(chartBg);
        g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

        if (!debeMostrarGrafico || datosGrafico->Count == 0) {
            Brush^ textoBrush = gcnew SolidBrush(emptyText);
            System::Drawing::Font^ font = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Italic);
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
            String^ tipoGrafico = comboBoxTipoGrafico->SelectedItem != nullptr ?
                comboBoxTipoGrafico->SelectedItem->ToString() : "Barras";

            if (tipoGrafico == "Barras")
                DibujarGraficoBarras(g, pictureBoxGrafico->Width, pictureBoxGrafico->Height);
            else if (tipoGrafico == "Torta")
                DibujarGraficoTorta(g, pictureBoxGrafico->Width, pictureBoxGrafico->Height);
        }
        catch (Exception^) {
            Brush^ errorBrush = gcnew SolidBrush(Color::FromArgb(248, 113, 113));
            System::Drawing::Font^ errorFont = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);
            g->DrawString("Error al dibujar el gráfico", errorFont, errorBrush, 10, 10);
            delete errorBrush;
            delete errorFont;
        }
    }


    private: void DibujarGraficoBarras(Graphics^ g, int width, int height) {
        Color gridColor = Color::FromArgb(55, 65, 81);
        Color axisColor = Color::FromArgb(148, 163, 184);
        Color labelColor = Color::FromArgb(226, 232, 240);
        Color titleColor = Color::FromArgb(248, 250, 252);
        Color totalColor = Color::FromArgb(52, 211, 153);

        array<Color>^ colores = {
            Color::FromArgb(59, 130, 246),   // azul
            Color::FromArgb(172, 138, 230),  // lila
            Color::FromArgb(52, 211, 153),   // verde
            Color::FromArgb(251, 191, 36),   // amarillo
            Color::FromArgb(129, 140, 248),  // indigo
            Color::FromArgb(45, 212, 191),   // teal
            Color::FromArgb(244, 114, 182),  // rosa
            Color::FromArgb(234, 179, 8)
        };

        int margenIzquierdo = 100;
        int margenDerecho = 40;
        int margenSuperior = 60;
        int margenInferior = 100;

        int areaGraficoWidth = width - margenIzquierdo - margenDerecho;
        int areaGraficoHeight = height - margenSuperior - margenInferior;

        int maxCantidad = 1;
        for each (KeyValuePair<String^, int> ^ par in datosGrafico) {
            if (par->Value > maxCantidad)
                maxCantidad = par->Value;
        }

        // Título
        Brush^ tituloBrush = gcnew SolidBrush(titleColor);
        System::Drawing::Font^ tituloFont = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Bold);
        String^ titulo = "Alertas Solucionadas por Usuario - Gráfico de Barras";
        SizeF tituloSize = g->MeasureString(titulo, tituloFont);
        g->DrawString(titulo, tituloFont, tituloBrush, (width - tituloSize.Width) / 2, 10);
        delete tituloBrush;
        delete tituloFont;

        // Ejes
        Pen^ ejePen = gcnew Pen(axisColor, 2);
        g->DrawLine(ejePen, margenIzquierdo, margenSuperior,
            margenIzquierdo, margenSuperior + areaGraficoHeight);
        g->DrawLine(ejePen, margenIzquierdo, margenSuperior + areaGraficoHeight,
            margenIzquierdo + areaGraficoWidth, margenSuperior + areaGraficoHeight);

        int numBarras = datosGrafico->Count;
        int anchoBarra = areaGraficoWidth / (numBarras + 2);
        int espacioEntreBarras = anchoBarra / 3;
        int anchoBarraReal = anchoBarra - espacioEntreBarras;

        int indice = 0;
        for each (KeyValuePair<String^, int> ^ par in datosGrafico) {
            String^ nombreUsuario = par->Key;
            int cantidad = par->Value;

            int x = margenIzquierdo + (indice * anchoBarra) + espacioEntreBarras;
            int alturaBarra = (int)((cantidad / (double)maxCantidad) * areaGraficoHeight);
            int y = margenSuperior + areaGraficoHeight - alturaBarra;

            Color colorBarra = colores[indice % colores->Length];
            Brush^ barraBrush = gcnew SolidBrush(colorBarra);
            g->FillRectangle(barraBrush, x, y, anchoBarraReal, alturaBarra);

            Pen^ bordePen = gcnew Pen(Color::FromArgb(15, 23, 42), 1);
            g->DrawRectangle(bordePen, x, y, anchoBarraReal, alturaBarra);

            // Cantidad
            Brush^ textoBrush = gcnew SolidBrush(Color::White);
            System::Drawing::Font^ textoFont = gcnew System::Drawing::Font("Segoe UI", 8, FontStyle::Bold);
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
                textoBrush = gcnew SolidBrush(labelColor);
            }

            g->DrawString(etiquetaCantidad, textoFont, textoBrush, textoX, textoY);

            // Nombre usuario
            Brush^ nombreBrush = gcnew SolidBrush(labelColor);
            System::Drawing::Font^ nombreFont = gcnew System::Drawing::Font("Segoe UI", 8);

            String^ nombreMostrar = nombreUsuario;
            if (nombreMostrar->Length > 10)
                nombreMostrar = nombreMostrar->Substring(0, 8) + "...";

            SizeF nombreSize = g->MeasureString(nombreMostrar, nombreFont);
            float nombreX = x + (anchoBarraReal - nombreSize.Width) / 2;
            float nombreY = margenSuperior + areaGraficoHeight + 5;

            if (numBarras > 6) {
                g->TranslateTransform(nombreX + nombreSize.Width / 2, nombreY);
                g->RotateTransform(-45);
                g->DrawString(nombreMostrar, nombreFont, nombreBrush, -nombreSize.Width / 2, 0);
                g->ResetTransform();
            }
            else {
                g->DrawString(nombreMostrar, nombreFont, nombreBrush, nombreX, nombreY);
            }

            // Si se recortó el nombre, mostrar completo debajo
            if (nombreUsuario != nombreMostrar) {
                g->DrawString(nombreUsuario, nombreFont, nombreBrush, nombreX, nombreY + 15);
            }

            delete barraBrush;
            delete bordePen;
            delete textoBrush;
            delete textoFont;
            delete nombreBrush;
            delete nombreFont;

            indice++;
        }

        // Escala Y
        DibujarEscalaEjeY(g, margenIzquierdo, margenSuperior, areaGraficoWidth, areaGraficoHeight, maxCantidad);

        // Ejes X/Y
        Brush^ escalaBrush = gcnew SolidBrush(axisColor);
        System::Drawing::Font^ ejeYFont = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);
        String^ etiquetaEjeY = "Cantidad de Alertas";
        SizeF ejeYSize = g->MeasureString(etiquetaEjeY, ejeYFont);
        g->TranslateTransform(20, margenSuperior + areaGraficoHeight / 2);
        g->RotateTransform(-90);
        g->DrawString(etiquetaEjeY, ejeYFont, escalaBrush, -ejeYSize.Height / 2, 0);
        g->ResetTransform();

        System::Drawing::Font^ ejeXFont = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);
        String^ etiquetaEjeX = "Usuarios";
        SizeF ejeXSize = g->MeasureString(etiquetaEjeX, ejeXFont);
        g->DrawString(etiquetaEjeX, ejeXFont, escalaBrush,
            margenIzquierdo + (areaGraficoWidth - ejeXSize.Width) / 2,
            margenSuperior + areaGraficoHeight + 50);

        // Total
        int totalAlertas = 0;
        for each (KeyValuePair<String^, int> ^ par in datosGrafico)
            totalAlertas += par->Value;

        Brush^ totalBrush = gcnew SolidBrush(totalColor);
        System::Drawing::Font^ totalFont = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);
        String^ totalTexto = String::Format("Total de alertas solucionadas: {0}", totalAlertas);
        g->DrawString(totalTexto, totalFont, totalBrush, margenIzquierdo, 35);

        delete ejePen;
        delete escalaBrush;
        delete ejeYFont;
        delete ejeXFont;
        delete totalBrush;
        delete totalFont;
    }


    private: void DibujarGraficoTorta(Graphics^ g, int width, int height) {
        Color labelColor = Color::FromArgb(226, 232, 240);
        Color titleColor = Color::FromArgb(248, 250, 252);
        Color lineColor = Color::FromArgb(148, 163, 184);
        Color totalColor = Color::FromArgb(52, 211, 153);

        array<Color>^ colores = {
            Color::FromArgb(59, 130, 246),   // azul
            Color::FromArgb(172, 138, 230),  // lila
            Color::FromArgb(52, 211, 153),   // verde
            Color::FromArgb(251, 191, 36),   // amarillo
            Color::FromArgb(129, 140, 248),  // indigo
            Color::FromArgb(45, 212, 191),   // teal
            Color::FromArgb(244, 114, 182),  // rosa
            Color::FromArgb(234, 179, 8)
        };

        int centroX = width / 2;
        int centroY = height / 2;
        int radio = Math::Min(width, height) / 3;

        Brush^ tituloBrush = gcnew SolidBrush(titleColor);
        System::Drawing::Font^ tituloFont = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Bold);
        String^ titulo = "Alertas Solucionadas por Usuario - Gráfico de Torta";
        SizeF tituloSize = g->MeasureString(titulo, tituloFont);
        g->DrawString(titulo, tituloFont, tituloBrush, (width - tituloSize.Width) / 2, 10);
        delete tituloBrush;
        delete tituloFont;

        int totalAlertas = 0;
        for each (KeyValuePair<String^, int> ^ par in datosGrafico)
            totalAlertas += par->Value;

        if (totalAlertas == 0) return;

        float anguloInicio = 0.0f;
        int indice = 0;

        for each (KeyValuePair<String^, int> ^ par in datosGrafico) {
            String^ nombreUsuario = par->Key;
            int cantidad = par->Value;

            float anguloBarrido = (cantidad / (float)totalAlertas) * 360.0f;

            Brush^ segmentoBrush = gcnew SolidBrush(colores[indice % colores->Length]);

            System::Drawing::Rectangle rect(
                centroX - radio,
                centroY - radio,
                radio * 2,
                radio * 2
            );
            g->FillPie(segmentoBrush, rect, anguloInicio, anguloBarrido);

            Pen^ bordePen = gcnew Pen(Color::FromArgb(15, 23, 42), 1);
            g->DrawPie(bordePen, rect, anguloInicio, anguloBarrido);

            float anguloMedio = anguloInicio + anguloBarrido / 2.0f;
            float angRad = anguloMedio * (float)Math::PI / 180.0f;
            float etiquetaX = centroX + (radio + 20) * (float)Math::Cos(angRad);
            float etiquetaY = centroY + (radio + 20) * (float)Math::Sin(angRad);

            float lineaX = centroX + (radio - 10) * (float)Math::Cos(angRad);
            float lineaY = centroY + (radio - 10) * (float)Math::Sin(angRad);
            Pen^ lineaPen = gcnew Pen(lineColor, 1);
            g->DrawLine(lineaPen, lineaX, lineaY, etiquetaX, etiquetaY);

            float porcentaje = (cantidad / (float)totalAlertas) * 100.0f;
            String^ etiqueta = String::Format("{0}: {1} ({2:F1}%)", nombreUsuario, cantidad, porcentaje);

            Brush^ textoBrush = gcnew SolidBrush(labelColor);
            System::Drawing::Font^ textoFont = gcnew System::Drawing::Font("Segoe UI", 8);
            SizeF textoSize = g->MeasureString(etiqueta, textoFont);

            float textoX = etiquetaX;
            float textoY = etiquetaY - textoSize.Height / 2;

            if (etiquetaX <= centroX) {
                textoX -= textoSize.Width;
            }

            g->DrawString(etiqueta, textoFont, textoBrush, textoX, textoY);

            delete segmentoBrush;
            delete bordePen;
            delete lineaPen;
            delete textoBrush;
            delete textoFont;

            anguloInicio += anguloBarrido;
            indice++;
        }

        // Total en el centro
        Brush^ totalBrush = gcnew SolidBrush(totalColor);
        System::Drawing::Font^ totalFont = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);
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
           Thread^ myThread;
           delegate void MyDelegate(String^);
        private: void CargarHoraRealTime() {
            String^ title = "Gráficos de Alertas registras - ";
            while (true)
            {
                try {
                    myThread->Sleep(1000);
                    Invoke(gcnew MyDelegate(this, &GraficAlertUserSolForm::UpdateTitle), title + DateTime::Now);
                }
                catch (Exception^ ex) {
                    return;
                }
            }
        }
        private: void UpdateTitle(String^ newTitle) {
            this->Text = newTitle;
        }

    private: void CargarDatos() {
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
    private:
        Thread^ timer;
        bool timerRunning;
        int currentInterval;
        int elapsedTime;
        Object^ lockObject;

        delegate void UpdateDataDelegate();
        private: void InitializateTimer() {
            lockObject = gcnew Object();
            timerRunning = false;
            currentInterval = 0;
            elapsedTime = 0;
        }
        private: void StartTimer() {
            StopTimer();

            Monitor::Enter(lockObject);
            try {
                timerRunning = true;

                currentInterval = 10 * 1000;
                elapsedTime = 0;
            }
            finally {
                Monitor::Exit(lockObject);
            }

            timer = gcnew Thread(gcnew ThreadStart(this, &GraficAlertUserSolForm::TimerMethod));
            timer->IsBackground = true;
            timer->Start();
        }
        private: void StopTimer() {
            Monitor::Enter(lockObject);
            try {
                timerRunning = false;
            }
            finally {
                Monitor::Exit(lockObject);
            }
            if (timer != nullptr && timer->IsAlive) {
                if (!timer->Join(500)) {
                    try {
                        timer->Abort();
                    }
                    catch (ThreadAbortException^) {
                        Thread::ResetAbort();
                    }
                    timer = nullptr;
                }
            }
        }
        private: void TimerMethod() {
            int updateInterval = 100;

            try {
                while (true)
                {
                    Monitor::Enter(lockObject);
                    bool shouldStop = !timerRunning;
                    bool timerCompleted = (elapsedTime >= currentInterval);
                    Monitor::Exit(lockObject);

                    if (shouldStop) break;
                    if (timerCompleted) break;

                    Thread::Sleep(updateInterval);

                    Monitor::Enter(lockObject);
                    try {
                        if (timerRunning) {
                            elapsedTime += updateInterval;
                            int remainingTime = currentInterval - elapsedTime;
                        }
                    }
                    finally {
                        Monitor::Exit(lockObject);
                    }
                }

                bool shouldRefresh = false;
                Monitor::Enter(lockObject);
                try {
                    shouldRefresh = timerRunning && (elapsedTime >= currentInterval);
                }
                finally {
                    Monitor::Exit(lockObject);
                }
                if (shouldRefresh) {
                    RefreshData();
                }
            }
            catch (ThreadAbortException^) {
                Thread::ResetAbort();
            }
            catch (Exception^ ex) {
                System::Diagnostics::Debug::WriteLine("Error en Timer: " + ex->Message);
            }
        }
        private: void RefreshData() {
            if (this->IsDisposed || !this->IsHandleCreated) {
                return;
            }

            if (this->InvokeRequired) {
                try {
                    this->BeginInvoke(gcnew UpdateDataDelegate(this, &GraficAlertUserSolForm::RefreshData));
                }
                catch (ObjectDisposedException^) {
                    return;
                }
                catch (InvalidOperationException^) {
                    return;
                }
                return;
            }

            if (this->IsDisposed) return;

            CargarDatos();

            bool shouldRestart = false;
            Monitor::Enter(lockObject);
            try {
                shouldRestart = timerRunning && !this->IsDisposed;
            }
            finally {
                Monitor::Exit(lockObject);
            }

            if (shouldRestart) {
                StartTimer();
            }
        }
    private: System::Void GraficAlertUserSolForm_Load(System::Object^ sender, System::EventArgs^ e) {
        CargarDatos();
        myThread = gcnew Thread(gcnew ThreadStart(this, &GraficAlertUserSolForm::CargarHoraRealTime));
        myThread->Start();
        InitializateTimer();
        StartTimer();
    }

    private: System::Void comboBoxTipoGrafico_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        // Redibujar el gráfico cuando cambia el tipo
        if (debeMostrarGrafico) {
            pictureBoxGrafico->Invalidate();
        }
    }

    };
}