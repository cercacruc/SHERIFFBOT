#pragma once
#include "UIStyles.h"

namespace GUIApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Collections::Generic;

    public ref class InformationRequestForm : public System::Windows::Forms::Form
    {
    public:
        InformationRequestForm(void)
        {
            InitializeComponent();

            this->DoubleBuffered = true;

            this->BackColor = System::Drawing::Color::FromArgb(5, 8, 22);
            this->ForeColor = System::Drawing::Color::White;
            this->StartPosition = FormStartPosition::CenterScreen;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;

            // CRÍTICO: enganchar Paint del pictureBox
            this->pictureBox1->Paint += gcnew PaintEventHandler(this, &InformationRequestForm::pictureBox1_Paint);

            // Estado rutas
            mostrarRuta = false;
            rutaPuntos = gcnew List<System::Drawing::PointF>();
            debugWaypoints = true;

            // Estilos
            UpgradeTabControlToDark();
            ApplyDarkTheme();
            StyleButton();
            StyleComboLugar();
            StyleComboInicio();
            StyleGrids();

            // Datos manuales
            InicializarPuntos();
            InicializarRutasManuales();
            CargarCombos();

            // Tablas (Comida / Aulas / Zonas)
            ConfigurarGrids();
            CargarDatosGrids();

            if (comboBoxInicio->Items->Count > 0) comboBoxInicio->SelectedIndex = 0;
            if (comboBox1->Items->Count > 0) comboBox1->SelectedIndex = 0;
        }

    protected:
        ~InformationRequestForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        // ====== Tu sistema de coordenadas ======
        // X: 0..935 (izq->der)
        // Y: 0..465 (abajo->arriba)  <-- IMPORTANTE
        literal int MAP_W = 935;
        literal int MAP_H = 465;

        // Controles base
        System::Windows::Forms::Button^ btnReturnInfoRequest;
        System::Windows::Forms::TabControl^ tabControl1;
        System::Windows::Forms::TabPage^ tabPage1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::TabPage^ tabPage2;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::TabPage^ tabPage3;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::TabPage^ tabPage4;
        System::Windows::Forms::Label^ label6;
        System::Windows::Forms::ComboBox^ comboBox1; // destino
        System::Windows::Forms::Label^ label5;
        System::Windows::Forms::Label^ label1;

        // DGVs (tabs 1-3)
        System::Windows::Forms::DataGridView^ dgvComida;
        System::Windows::Forms::DataGridView^ dgvAulas;
        System::Windows::Forms::DataGridView^ dgvZonas;

        // Controles rutas (tab Lugar)
        System::Windows::Forms::ComboBox^ comboBoxInicio; // inicio
        System::Windows::Forms::Label^ label7;
        System::Windows::Forms::Button^ btnCalcularRuta;
        System::Windows::Forms::RichTextBox^ txtInstrucciones;
        System::Windows::Forms::PictureBox^ pictureBox1;

        System::ComponentModel::Container^ components;

        // Datos manuales (rutas)
        Dictionary<String^, System::Drawing::PointF>^ puntos;
        Dictionary<String^, List<System::Drawing::PointF>^>^ rutas;

        List<System::Drawing::PointF>^ rutaPuntos;
        bool mostrarRuta;
        bool debugWaypoints;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources =
                (gcnew System::ComponentModel::ComponentResourceManager(InformationRequestForm::typeid));

            this->btnReturnInfoRequest = (gcnew System::Windows::Forms::Button());
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->dgvComida = (gcnew System::Windows::Forms::DataGridView());

            this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->dgvAulas = (gcnew System::Windows::Forms::DataGridView());

            this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->dgvZonas = (gcnew System::Windows::Forms::DataGridView());

            this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->txtInstrucciones = (gcnew System::Windows::Forms::RichTextBox());
            this->btnCalcularRuta = (gcnew System::Windows::Forms::Button());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->comboBoxInicio = (gcnew System::Windows::Forms::ComboBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());

            this->tabControl1->SuspendLayout();
            this->tabPage1->SuspendLayout();
            this->tabPage2->SuspendLayout();
            this->tabPage3->SuspendLayout();
            this->tabPage4->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvComida))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAulas))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvZonas))->BeginInit();
            this->SuspendLayout();

            // 
            // btnReturnInfoRequest
            // 
            this->btnReturnInfoRequest->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
            this->btnReturnInfoRequest->Location = System::Drawing::Point(297, 952);
            this->btnReturnInfoRequest->Name = L"btnReturnInfoRequest";
            this->btnReturnInfoRequest->Size = System::Drawing::Size(193, 47);
            this->btnReturnInfoRequest->TabIndex = 27;
            this->btnReturnInfoRequest->Text = L"Volver";
            this->btnReturnInfoRequest->UseVisualStyleBackColor = true;
            this->btnReturnInfoRequest->Click += gcnew System::EventHandler(this, &InformationRequestForm::btnReturnInfoRequest_Click);

            // 
            // tabControl1
            // 
            this->tabControl1->Controls->Add(this->tabPage1);
            this->tabControl1->Controls->Add(this->tabPage2);
            this->tabControl1->Controls->Add(this->tabPage3);
            this->tabControl1->Controls->Add(this->tabPage4);
            this->tabControl1->Location = System::Drawing::Point(12, 72);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(780, 874);
            this->tabControl1->TabIndex = 25;

            // 
            // tabPage1 (Comida)
            // 
            this->tabPage1->Controls->Add(this->label2);
            this->tabPage1->Controls->Add(this->dgvComida);
            this->tabPage1->Location = System::Drawing::Point(4, 25);
            this->tabPage1->Name = L"tabPage1";
            this->tabPage1->Size = System::Drawing::Size(772, 845);
            this->tabPage1->TabIndex = 0;
            this->tabPage1->Text = L"Comida";
            this->tabPage1->UseVisualStyleBackColor = true;

            // label2
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->label2->Location = System::Drawing::Point(210, 25);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(281, 20);
            this->label2->TabIndex = 0;
            this->label2->Text = L"Comedores y cafeterías disponibles:";

            // dgvComida
            this->dgvComida->Location = System::Drawing::Point(20, 65);
            this->dgvComida->Name = L"dgvComida";
            this->dgvComida->Size = System::Drawing::Size(730, 740);
            this->dgvComida->TabIndex = 1;

            // 
            // tabPage2 (Aulas libres)
            // 
            this->tabPage2->Controls->Add(this->label3);
            this->tabPage2->Controls->Add(this->dgvAulas);
            this->tabPage2->Location = System::Drawing::Point(4, 25);
            this->tabPage2->Name = L"tabPage2";
            this->tabPage2->Size = System::Drawing::Size(772, 845);
            this->tabPage2->TabIndex = 1;
            this->tabPage2->Text = L"Aulas libres";
            this->tabPage2->UseVisualStyleBackColor = true;

            // label3
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->label3->Location = System::Drawing::Point(290, 28);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(170, 20);
            this->label3->TabIndex = 1;
            this->label3->Text = L"Aulas disponibles:";

            // dgvAulas
            this->dgvAulas->Location = System::Drawing::Point(20, 65);
            this->dgvAulas->Name = L"dgvAulas";
            this->dgvAulas->Size = System::Drawing::Size(730, 740);
            this->dgvAulas->TabIndex = 2;

            // 
            // tabPage3 (Zonas de estudio)
            // 
            this->tabPage3->Controls->Add(this->label4);
            this->tabPage3->Controls->Add(this->dgvZonas);
            this->tabPage3->Location = System::Drawing::Point(4, 25);
            this->tabPage3->Name = L"tabPage3";
            this->tabPage3->Size = System::Drawing::Size(772, 845);
            this->tabPage3->TabIndex = 2;
            this->tabPage3->Text = L"Zonas de estudio";
            this->tabPage3->UseVisualStyleBackColor = true;

            // label4
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->label4->Location = System::Drawing::Point(250, 23);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(230, 20);
            this->label4->TabIndex = 1;
            this->label4->Text = L"Zonas de estudio disponibles:";

            // dgvZonas
            this->dgvZonas->Location = System::Drawing::Point(20, 65);
            this->dgvZonas->Name = L"dgvZonas";
            this->dgvZonas->Size = System::Drawing::Size(730, 740);
            this->dgvZonas->TabIndex = 3;

            // 
            // tabPage4 (Lugar)
            // 
            this->tabPage4->Controls->Add(this->pictureBox1);
            this->tabPage4->Controls->Add(this->txtInstrucciones);
            this->tabPage4->Controls->Add(this->btnCalcularRuta);
            this->tabPage4->Controls->Add(this->label6);
            this->tabPage4->Controls->Add(this->comboBox1);
            this->tabPage4->Controls->Add(this->label5);
            this->tabPage4->Controls->Add(this->comboBoxInicio);
            this->tabPage4->Controls->Add(this->label7);
            this->tabPage4->Location = System::Drawing::Point(4, 25);
            this->tabPage4->Name = L"tabPage4";
            this->tabPage4->Size = System::Drawing::Size(772, 845);
            this->tabPage4->TabIndex = 3;
            this->tabPage4->Text = L"Lugar";
            this->tabPage4->UseVisualStyleBackColor = true;

            // pictureBox1
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(18, 224);
            this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(739, 489);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 39;
            this->pictureBox1->TabStop = false;

            // txtInstrucciones
            this->txtInstrucciones->Location = System::Drawing::Point(116, 739);
            this->txtInstrucciones->Name = L"txtInstrucciones";
            this->txtInstrucciones->Size = System::Drawing::Size(540, 80);
            this->txtInstrucciones->TabIndex = 8;
            this->txtInstrucciones->Text = L"";

            // btnCalcularRuta
            this->btnCalcularRuta->Location = System::Drawing::Point(324, 167);
            this->btnCalcularRuta->Name = L"btnCalcularRuta";
            this->btnCalcularRuta->Size = System::Drawing::Size(150, 35);
            this->btnCalcularRuta->TabIndex = 7;
            this->btnCalcularRuta->Text = L"Calcular Ruta";
            this->btnCalcularRuta->UseVisualStyleBackColor = true;
            this->btnCalcularRuta->Click += gcnew System::EventHandler(this, &InformationRequestForm::btnCalcularRuta_Click);

            // label6
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->label6->Location = System::Drawing::Point(360, 137);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(104, 20);
            this->label6->TabIndex = 3;
            this->label6->Text = L"Cómo llegar:";

            // comboBox1 (destino)
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Location = System::Drawing::Point(264, 97);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(310, 24);
            this->comboBox1->TabIndex = 2;

            // label5
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->label5->Location = System::Drawing::Point(324, 67);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(174, 20);
            this->label5->TabIndex = 1;
            this->label5->Text = L"Ingrese una dirección:";

            // comboBoxInicio
            this->comboBoxInicio->FormattingEnabled = true;
            this->comboBoxInicio->Location = System::Drawing::Point(264, 24);
            this->comboBoxInicio->Name = L"comboBoxInicio";
            this->comboBoxInicio->Size = System::Drawing::Size(310, 24);
            this->comboBoxInicio->TabIndex = 0;

            // label7
            this->label7->AutoSize = true;
            this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->label7->Location = System::Drawing::Point(134, 27);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(124, 20);
            this->label7->TabIndex = 9;
            this->label7->Text = L"Punto de inicio:";

            // label1
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
            this->label1->Location = System::Drawing::Point(275, 20);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(277, 29);
            this->label1->TabIndex = 26;
            this->label1->Text = L"Solicitud de información:";

            // Form
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(804, 1011);
            this->Controls->Add(this->btnReturnInfoRequest);
            this->Controls->Add(this->tabControl1);
            this->Controls->Add(this->label1);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"InformationRequestForm";
            this->Text = L"Solicitud de información";

            this->tabControl1->ResumeLayout(false);
            this->tabPage1->ResumeLayout(false);
            this->tabPage1->PerformLayout();
            this->tabPage2->ResumeLayout(false);
            this->tabPage2->PerformLayout();
            this->tabPage3->ResumeLayout(false);
            this->tabPage3->PerformLayout();
            this->tabPage4->ResumeLayout(false);
            this->tabPage4->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvComida))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAulas))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvZonas))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        // ====== Conversión de coordenadas (FIX REAL) ======
        // Tus puntos vienen con Y desde abajo -> aquí lo convertimos a Y desde arriba
        System::Drawing::PointF MapToPicture(System::Drawing::PointF pMap)
        {
            float w = (float)pictureBox1->ClientSize.Width;
            float h = (float)pictureBox1->ClientSize.Height;

            float x = pMap.X * (w / (float)MAP_W);
            float y = (float)(MAP_H - pMap.Y) * (h / (float)MAP_H); // <-- flip Y

            return System::Drawing::PointF(x, y);
        }

        // =======================
        //  Estilos (dark theme)
        // =======================
        void UpgradeTabControlToDark()
        {
            if (this->tabControl1 == nullptr) return;

            TabControl^ original = this->tabControl1;
            GUIApp::DarkTabControl^ dark = gcnew GUIApp::DarkTabControl();

            dark->Location = original->Location;
            dark->Size = original->Size;
            dark->Anchor = original->Anchor;
            dark->Name = original->Name;

            while (original->TabPages->Count > 0)
            {
                TabPage^ p = original->TabPages[0];
                original->TabPages->RemoveAt(0);
                dark->TabPages->Add(p);
            }

            dark->SizeMode = TabSizeMode::Fixed;
            dark->ItemSize = System::Drawing::Size(120, 28);

            this->Controls->Remove(original);
            this->tabControl1 = dark;
            this->Controls->Add(this->tabControl1);
        }

        void ApplyDarkTheme()
        {
            Color back = Color::FromArgb(20, 27, 47);
            Color fore = Color::FromArgb(224, 231, 255);

            this->BackColor = back;
            this->ForeColor = fore;
            this->StartPosition = FormStartPosition::CenterScreen;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;

            if (this->tabControl1 != nullptr)
            {
                this->tabControl1->BackColor = back;
                this->tabControl1->ForeColor = fore;

                for each (TabPage ^ page in this->tabControl1->TabPages)
                {
                    page->BackColor = back;
                    page->ForeColor = fore;
                }
            }

            if (label1 != nullptr)
            {
                label1->ForeColor = Color::FromArgb(241, 245, 249);
                label1->Font = gcnew Drawing::Font("Segoe UI", 14, FontStyle::Bold);
            }

            array<Label^>^ labels = gcnew array<Label^>{ label2, label3, label4, label5, label6, label7 };
            for each (Label ^ lb in labels)
            {
                if (lb != nullptr)
                {
                    lb->ForeColor = fore;
                    lb->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Regular);
                }
            }

            if (txtInstrucciones != nullptr) {
                txtInstrucciones->BackColor = Color::FromArgb(15, 23, 42);
                txtInstrucciones->ForeColor = fore;
                txtInstrucciones->BorderStyle = BorderStyle::FixedSingle;
                txtInstrucciones->ReadOnly = true;
                txtInstrucciones->Font = gcnew Drawing::Font("Segoe UI", 9);
            }
        }

        void StyleButton()
        {
            btnReturnInfoRequest->FlatStyle = FlatStyle::Flat;
            btnReturnInfoRequest->FlatAppearance->BorderSize = 0;
            btnReturnInfoRequest->BackColor = Color::FromArgb(0, 140, 255);
            btnReturnInfoRequest->ForeColor = Color::White;
            btnReturnInfoRequest->Font = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);
            UIHelpers::SetRoundedRegionAuto(this->btnReturnInfoRequest);

            btnCalcularRuta->FlatStyle = FlatStyle::Flat;
            btnCalcularRuta->FlatAppearance->BorderSize = 0;
            btnCalcularRuta->BackColor = Color::FromArgb(0, 200, 83);
            btnCalcularRuta->ForeColor = Color::White;
            btnCalcularRuta->Font = gcnew Drawing::Font("Segoe UI", 9, FontStyle::Bold);
            UIHelpers::SetRoundedRegionAuto(this->btnCalcularRuta);
        }

        void StyleComboLugar()
        {
            if (comboBox1 == nullptr) return;

            comboBox1->FlatStyle = FlatStyle::Flat;
            comboBox1->DropDownStyle = ComboBoxStyle::DropDownList;
            comboBox1->BackColor = Color::FromArgb(15, 23, 42);
            comboBox1->ForeColor = Color::FromArgb(226, 232, 240);
            comboBox1->DrawMode = DrawMode::OwnerDrawFixed;
            comboBox1->DrawItem += gcnew DrawItemEventHandler(this, &InformationRequestForm::comboBox_DrawItem);
        }

        void StyleComboInicio()
        {
            if (comboBoxInicio == nullptr) return;

            comboBoxInicio->FlatStyle = FlatStyle::Flat;
            comboBoxInicio->DropDownStyle = ComboBoxStyle::DropDownList;
            comboBoxInicio->BackColor = Color::FromArgb(15, 23, 42);
            comboBoxInicio->ForeColor = Color::FromArgb(226, 232, 240);
            comboBoxInicio->DrawMode = DrawMode::OwnerDrawFixed;
            comboBoxInicio->DrawItem += gcnew DrawItemEventHandler(this, &InformationRequestForm::comboBox_DrawItem);
        }

        void comboBox_DrawItem(System::Object^ sender, DrawItemEventArgs^ e)
        {
            if (e->Index < 0) return;

            ComboBox^ cb = safe_cast<ComboBox^>(sender);

            bool selected = (e->State & DrawItemState::Selected) == DrawItemState::Selected;
            Color back = selected ? Color::FromArgb(37, 99, 235) : Color::FromArgb(15, 23, 42);
            Color fore = Color::FromArgb(226, 232, 240);

            e->Graphics->FillRectangle(gcnew SolidBrush(back), e->Bounds);

            String^ text = cb->Items[e->Index]->ToString();
            e->Graphics->DrawString(
                text,
                cb->Font,
                gcnew SolidBrush(fore),
                RectangleF((float)e->Bounds.X, (float)e->Bounds.Y, (float)e->Bounds.Width, (float)e->Bounds.Height)
            );

            if (selected) e->DrawFocusRectangle();
        }

        // ====== Estilo DGVs (igual que AdminAlertManagementForm) ======
        void StyleGrids()
        {
            StyleGrid(dgvComida);
            StyleGrid(dgvAulas);
            StyleGrid(dgvZonas);
        }

        void StyleGrid(DataGridView^ grid)
        {
            if (grid == nullptr) return;

            grid->BackgroundColor = Color::FromArgb(10, 16, 32);
            grid->EnableHeadersVisualStyles = false;
            grid->GridColor = Color::FromArgb(30, 41, 59);
            grid->BorderStyle = BorderStyle::None;

            grid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

            grid->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(37, 99, 235);
            grid->ColumnHeadersDefaultCellStyle->ForeColor = Color::FromArgb(241, 245, 249);
            grid->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);
            grid->ColumnHeadersBorderStyle = DataGridViewHeaderBorderStyle::Single;

            grid->DefaultCellStyle->BackColor = Color::FromArgb(20, 27, 47);
            grid->DefaultCellStyle->ForeColor = Color::FromArgb(226, 232, 240);
            grid->DefaultCellStyle->SelectionBackColor = Color::FromArgb(37, 99, 235);
            grid->DefaultCellStyle->SelectionForeColor = Color::White;

            grid->RowHeadersVisible = false;
            grid->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            grid->MultiSelect = false;
        }

        // =======================
        //  Grids: columnas + datos
        // =======================
        void ConfigurarGrids()
        {
            // Comida
            dgvComida->AllowUserToAddRows = false;
            dgvComida->AllowUserToDeleteRows = false;
            dgvComida->ReadOnly = true;
            dgvComida->Columns->Clear();
            dgvComida->Columns->Add("colComedor", "Comedor");
            dgvComida->Columns->Add("colHorario", "Horario");
            dgvComida->Columns->Add("colMenu", "Menú del día");
            dgvComida->Columns->Add("colEstado", "Estado");

            // Aulas
            dgvAulas->AllowUserToAddRows = false;
            dgvAulas->AllowUserToDeleteRows = false;
            dgvAulas->ReadOnly = true;
            dgvAulas->Columns->Clear();
            dgvAulas->Columns->Add("colHorarioA", "Horario");
            dgvAulas->Columns->Add("colAula", "Aula");
            dgvAulas->Columns->Add("colPabellon", "Pabellón");
            dgvAulas->Columns->Add("colCap", "Cap. Máx");

            // Zonas
            dgvZonas->AllowUserToAddRows = false;
            dgvZonas->AllowUserToDeleteRows = false;
            dgvZonas->ReadOnly = true;
            dgvZonas->Columns->Clear();
            dgvZonas->Columns->Add("colZona", "Zona");
            dgvZonas->Columns->Add("colHorarioZ", "Horario");
            dgvZonas->Columns->Add("colCubiculos", "Cubículos");
        }

        void CargarDatosGrids()
        {
            // ================== COMIDA ==================
            dgvComida->Rows->Clear();
            dgvComida->Rows->Add(gcnew array<String^>{
                "Comedor de Estudios Generales Letras",
                    "11am - 3pm",
                    "Pollo saltado con arroz y papas fritas",
                    "Disponible"
            });
            dgvComida->Rows->Add(gcnew array<String^>{
                "KiloMio",
                    "7am - 7pm",
                    "Libre elección",
                    "Disponible"
            });
            dgvComida->Rows->Add(gcnew array<String^>{
                "Comedor Central",
                    "11am - 5pm",
                    "Seco de res",
                    "Disponible"
            });

            // ================== AULAS LIBRES ==================
            dgvAulas->Rows->Clear();
            dgvAulas->Rows->Add(gcnew array<String^>{
                "7am - 5pm",
                    "A607",
                    "A",
                    "36"
            });
            dgvAulas->Rows->Add(gcnew array<String^>{
                "1pm - 5pm",
                    "Z401",
                    "Z",
                    "36"
            });
            dgvAulas->Rows->Add(gcnew array<String^>{
                "10am - 6pm",
                    "Z215",
                    "Z",
                    "36"
            });

            // ================== ZONAS DE ESTUDIO ==================
            dgvZonas->Rows->Clear();
            dgvZonas->Rows->Add(gcnew array<String^>{
                "Biblioteca central",
                    "9am - 7pm",
                    "10"
            });
            dgvZonas->Rows->Add(gcnew array<String^>{
                "CIA",
                    "8am - 10pm",
                    "28"
            });
            dgvZonas->Rows->Add(gcnew array<String^>{
                "Facultad de Ciencias Sociales",
                    "10am - 10pm",
                    "15"
            });
        }

        // =======================
        //  Datos manuales (Rutas)
        // =======================
        String^ Key(String^ a, String^ b) { return a + "|" + b; }

        void InicializarPuntos()
        {
            puntos = gcnew Dictionary<String^, System::Drawing::PointF>();

            // Puertas
            puntos["Puerta peatonal Riva Aguero"] = System::Drawing::PointF(550.0f, 390.0f);
            puntos["Puerta vehicular Riva Aguero"] = System::Drawing::PointF(516.0f, 390.0f);
            puntos["Puerta peatonal 8"] = System::Drawing::PointF(828.0f, 110.0f);
            puntos["Puerta peatonal principal"] = System::Drawing::PointF(575.0f, 82.0f);
            puntos["Puerta vehicular principal"] = System::Drawing::PointF(523.0f, 86.0f);
            puntos["Puerta peatonal EE.GG.CC"] = System::Drawing::PointF(302.0f, 73.0f);
            puntos["Puerta peatonal Urubamba"] = System::Drawing::PointF(32.0f, 395.0f);

            // Intersecciones / Lugares (SIN Tontodromo Oeste/Este)
            puntos["Tontodromo"] = System::Drawing::PointF(580.0f, 213.0f);

            // Actualizados / nuevos
            puntos["Edificio Mac Gregor"] = System::Drawing::PointF(612.0f, 116.0f);
            puntos["Polideportivo"] = System::Drawing::PointF(784.0f, 244.0f);

            puntos["EE.GG.CC"] = System::Drawing::PointF(307.0f, 165.0f);
            puntos["Aulario"] = System::Drawing::PointF(116.0f, 176.0f);

            // Consistencia: Pabellón V final según tu ruta
            puntos["Pabellón V"] = System::Drawing::PointF(65.0f, 385.0f);

            puntos["Facultad de Mecatrónica"] = System::Drawing::PointF(101.0f, 438.0f);

            // CIA (endpoint único)
            puntos["CIA"] = System::Drawing::PointF(185.0f, 210.0f);
        }

        void InicializarRutasManuales()
        {
            rutas = gcnew Dictionary<String^, List<System::Drawing::PointF>^>();

            // (Se mantiene) Puerta principal -> Tontodromo
            {
                auto p = gcnew List<System::Drawing::PointF>();
                p->Add(System::Drawing::PointF(575.0f, 82.0f));
                p->Add(System::Drawing::PointF(580.0f, 213.0f));
                rutas[Key("Puerta peatonal principal", "Tontodromo")] = p;
            }

            // (Se mantiene) Urubamba -> Pabellón V
            {
                auto p = gcnew List<System::Drawing::PointF>();
                p->Add(System::Drawing::PointF(32.0f, 395.0f));
                p->Add(System::Drawing::PointF(65.0f, 385.0f));
                rutas[Key("Puerta peatonal Urubamba", "Pabellón V")] = p;
            }

            // (Se mantiene) Urubamba -> Mecatrónica
            {
                auto p = gcnew List<System::Drawing::PointF>();
                p->Add(System::Drawing::PointF(32.0f, 395.0f));
                p->Add(System::Drawing::PointF(65.0f, 385.0f));
                p->Add(System::Drawing::PointF(101.0f, 438.0f));
                rutas[Key("Puerta peatonal Urubamba", "Facultad de Mecatrónica")] = p;
            }

            // ====== MODIFICADO: Principal -> Mac Gregor ======
            // 575,82 -> 582,123 -> 612,116
            {
                auto p = gcnew List<System::Drawing::PointF>();
                p->Add(System::Drawing::PointF(575.0f, 82.0f));
                p->Add(System::Drawing::PointF(582.0f, 123.0f));
                p->Add(System::Drawing::PointF(612.0f, 116.0f));
                rutas[Key("Puerta peatonal principal", "Edificio Mac Gregor")] = p;
            }

            // ====== NUEVA: Principal -> Polideportivo ======
            // 575,82 -> 580,213 -> 730,221 -> 784,244
            {
                auto p = gcnew List<System::Drawing::PointF>();
                p->Add(System::Drawing::PointF(575.0f, 82.0f));
                p->Add(System::Drawing::PointF(580.0f, 213.0f));
                p->Add(System::Drawing::PointF(730.0f, 221.0f));
                p->Add(System::Drawing::PointF(784.0f, 244.0f));
                rutas[Key("Puerta peatonal principal", "Polideportivo")] = p;
            }

            // ====== NUEVA: Principal -> CIA ======
            // 575,82 -> 580,213 -> 278,219 -> 214,217 -> 185,210
            {
                auto p = gcnew List<System::Drawing::PointF>();
                p->Add(System::Drawing::PointF(575.0f, 82.0f));
                p->Add(System::Drawing::PointF(580.0f, 213.0f));
                p->Add(System::Drawing::PointF(278.0f, 219.0f));
                p->Add(System::Drawing::PointF(214.0f, 217.0f));
                p->Add(System::Drawing::PointF(185.0f, 210.0f));
                rutas[Key("Puerta peatonal principal", "CIA")] = p;
            }

            // ====== NUEVA: Puerta EEGGCC -> EEGGCC ======
            // 302,73 -> 307,131 -> 298,133 -> 307,165
            {
                auto p = gcnew List<System::Drawing::PointF>();
                p->Add(System::Drawing::PointF(302.0f, 73.0f));
                p->Add(System::Drawing::PointF(307.0f, 131.0f));
                p->Add(System::Drawing::PointF(298.0f, 133.0f));
                p->Add(System::Drawing::PointF(307.0f, 165.0f));
                rutas[Key("Puerta peatonal EE.GG.CC", "EE.GG.CC")] = p;
            }

            // ====== NUEVA: Puerta EEGGCC -> Aulario ======
            // 302,73 -> 307,131 -> 106,144 -> 116,176
            {
                auto p = gcnew List<System::Drawing::PointF>();
                p->Add(System::Drawing::PointF(302.0f, 73.0f));
                p->Add(System::Drawing::PointF(307.0f, 131.0f));
                p->Add(System::Drawing::PointF(106.0f, 144.0f));
                p->Add(System::Drawing::PointF(116.0f, 176.0f));
                rutas[Key("Puerta peatonal EE.GG.CC", "Aulario")] = p;
            }

            // ====== NUEVA: Aulario -> Pabellón V ======
            // 116,176 -> 128,205 -> 91,210 -> 108,257 -> 86,263 -> 126,354 -> 98,363 -> 92,370 -> 65,385
            {
                auto p = gcnew List<System::Drawing::PointF>();
                p->Add(System::Drawing::PointF(116.0f, 176.0f));
                p->Add(System::Drawing::PointF(128.0f, 205.0f));
                p->Add(System::Drawing::PointF(91.0f, 210.0f));
                p->Add(System::Drawing::PointF(108.0f, 257.0f));
                p->Add(System::Drawing::PointF(86.0f, 263.0f));
                p->Add(System::Drawing::PointF(126.0f, 354.0f));
                p->Add(System::Drawing::PointF(98.0f, 363.0f));
                p->Add(System::Drawing::PointF(92.0f, 370.0f));
                p->Add(System::Drawing::PointF(65.0f, 385.0f));
                rutas[Key("Aulario", "Pabellón V")] = p;
            }

            // ====== NUEVA: Aulario -> CIA ======
            // 116,176 -> 128,205 -> 190,214 -> (normalizo endpoint CIA = 185,210)
            {
                auto p = gcnew List<System::Drawing::PointF>();
                p->Add(System::Drawing::PointF(116.0f, 176.0f));
                p->Add(System::Drawing::PointF(128.0f, 205.0f));
                p->Add(System::Drawing::PointF(190.0f, 214.0f));
                p->Add(System::Drawing::PointF(185.0f, 210.0f));
                rutas[Key("Aulario", "CIA")] = p;
            }

            // IMPORTANTE: ya NO existe Tontodromo (Oeste/Este) y su ruta (borrado)
        }

        void CargarCombos()
        {
            comboBoxInicio->Items->Clear();
            comboBox1->Items->Clear();

            // Inicios: puertas + Aulario (pedido)
            array<String^>^ inicios = gcnew array<String^>{
                "Puerta peatonal Riva Aguero",
                    "Puerta vehicular Riva Aguero",
                    "Puerta peatonal 8",
                    "Puerta peatonal principal",
                    "Puerta vehicular principal",
                    "Puerta peatonal EE.GG.CC",
                    "Puerta peatonal Urubamba",
                    "Aulario"
            };

            for each (String ^ s in inicios) comboBoxInicio->Items->Add(s);

            // Destinos: puertas + lugares
            array<String^>^ destinos = gcnew array<String^>{
                "Puerta peatonal Riva Aguero",
                    "Puerta vehicular Riva Aguero",
                    "Puerta peatonal 8",
                    "Puerta peatonal principal",
                    "Puerta vehicular principal",
                    "Puerta peatonal EE.GG.CC",
                    "Puerta peatonal Urubamba",

                    "Tontodromo",
                    "EE.GG.CC",
                    "Aulario",
                    "Pabellón V",
                    "Facultad de Mecatrónica",
                    "Edificio Mac Gregor",
                    "Polideportivo",
                    "CIA"
            };

            for each (String ^ d in destinos) comboBox1->Items->Add(d);
        }

        List<System::Drawing::PointF>^ ObtenerRutaManual(String^ inicio, String^ destino)
        {
            if (String::IsNullOrEmpty(inicio) || String::IsNullOrEmpty(destino))
                return gcnew List<System::Drawing::PointF>();

            String^ k1 = Key(inicio, destino);
            if (rutas->ContainsKey(k1))
                return rutas[k1];

            // Inversa
            String^ k2 = Key(destino, inicio);
            if (rutas->ContainsKey(k2))
            {
                List<System::Drawing::PointF>^ src = rutas[k2];
                List<System::Drawing::PointF>^ inv = gcnew List<System::Drawing::PointF>();
                for (int i = src->Count - 1; i >= 0; --i) inv->Add(src[i]);
                return inv;
            }

            return gcnew List<System::Drawing::PointF>();
        }

        void GenerarInstruccionesManual(String^ inicio, String^ destino, List<System::Drawing::PointF>^ pts)
        {
            txtInstrucciones->Clear();

            if (pts == nullptr || pts->Count < 2)
            {
                txtInstrucciones->AppendText("No hay ruta manual definida.\n");
                txtInstrucciones->AppendText("Inicio: " + inicio + "\nDestino: " + destino + "\n");
                return;
            }

            txtInstrucciones->AppendText("Ruta manual (tramos) desde " + inicio + " hasta " + destino + ":\n\n");

            for (int i = 0; i < pts->Count - 1; i++)
            {
                PointF a = pts[i];
                PointF b = pts[i + 1];

                txtInstrucciones->AppendText((i + 1).ToString() + ". ");
                txtInstrucciones->AppendText("(" + ((int)a.X).ToString() + "," + ((int)a.Y).ToString() + ")");
                txtInstrucciones->AppendText(" → ");
                txtInstrucciones->AppendText("(" + ((int)b.X).ToString() + "," + ((int)b.Y).ToString() + ")\n");
            }
        }

        // =======================
        //  Eventos
        // =======================
    private: System::Void btnCalcularRuta_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (comboBoxInicio->SelectedItem == nullptr || comboBox1->SelectedItem == nullptr)
        {
            MessageBox::Show("Seleccione inicio y destino.", "Advertencia",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        String^ inicio = comboBoxInicio->SelectedItem->ToString();
        String^ destino = comboBox1->SelectedItem->ToString();

        rutaPuntos = ObtenerRutaManual(inicio, destino);

        mostrarRuta = (rutaPuntos != nullptr && rutaPuntos->Count >= 2);
        GenerarInstruccionesManual(inicio, destino, rutaPuntos);

        pictureBox1->Invalidate();
    }

    private: System::Void pictureBox1_Paint(System::Object^ sender,
        System::Windows::Forms::PaintEventArgs^ e)
    {
        Graphics^ g = e->Graphics;
        g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

        if (!mostrarRuta || rutaPuntos == nullptr || rutaPuntos->Count < 2)
            return;

        // Ruta roja punteada
        Pen^ penRuta = gcnew Pen(Color::Red, 3.0f);
        penRuta->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash;

        for (int i = 0; i < rutaPuntos->Count - 1; i++)
        {
            PointF a = MapToPicture(rutaPuntos[i]);
            PointF b = MapToPicture(rutaPuntos[i + 1]);
            g->DrawLine(penRuta, a, b);
        }

        // Inicio y fin
        PointF ini = MapToPicture(rutaPuntos[0]);
        PointF fin = MapToPicture(rutaPuntos[rutaPuntos->Count - 1]);

        g->FillEllipse(Brushes::Green, ini.X - 8.0f, ini.Y - 8.0f, 16.0f, 16.0f);
        g->FillEllipse(Brushes::Red, fin.X - 8.0f, fin.Y - 8.0f, 16.0f, 16.0f);

        delete penRuta;
    }

    private: System::Void btnReturnInfoRequest_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close();
    }
    };

} // namespace GUIApp
