#pragma once
#include "UIStyles.h"   // UIHelpers (botones redondeados, OutlineButton_Paint)

namespace GUIApp {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace BotModel;
    using namespace BotService;
    using namespace System::Collections::Generic;
    using namespace System::Text::RegularExpressions;

    public ref class AsignarAlertaRobotForm : public System::Windows::Forms::Form
    {
    public:
        AsignarAlertaRobotForm(void)
        {
            InitializeComponent();

            // ==== UPGRADE VISUAL ====
            ApplyDarkTheme();
            StyleButtonsAndGrids();
            StyleTextBoxes();
            StyleComboBoxes();
        }

    protected:
        ~AsignarAlertaRobotForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::ComboBox^ cmbRobots;
        System::Windows::Forms::ComboBox^ cmbAlertasPendientes;
        System::Windows::Forms::Button^ btnAsignar;
        System::Windows::Forms::Button^ btnLiberar;
        System::Windows::Forms::Button^ btnSalir;
        System::Windows::Forms::DataGridView^ dgvAsignaciones;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::TextBox^ txtDescripcion;
        System::Windows::Forms::Label^ label4;

        System::Windows::Forms::DataGridViewTextBoxColumn^ RobotID;
        System::Windows::Forms::DataGridViewTextBoxColumn^ RobotNombre;
        System::Windows::Forms::DataGridViewTextBoxColumn^ AlertaAsignadaID;
        System::Windows::Forms::DataGridViewTextBoxColumn^ TipoAlerta;
        System::Windows::Forms::DataGridViewTextBoxColumn^ TipoMision;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AsignarAlertaRobotForm::typeid));
            this->cmbRobots = (gcnew System::Windows::Forms::ComboBox());
            this->cmbAlertasPendientes = (gcnew System::Windows::Forms::ComboBox());
            this->btnAsignar = (gcnew System::Windows::Forms::Button());
            this->btnLiberar = (gcnew System::Windows::Forms::Button());
            this->btnSalir = (gcnew System::Windows::Forms::Button());
            this->dgvAsignaciones = (gcnew System::Windows::Forms::DataGridView());
            this->RobotID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->RobotNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->AlertaAsignadaID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->TipoAlerta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->TipoMision = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->txtDescripcion = (gcnew System::Windows::Forms::TextBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAsignaciones))->BeginInit();
            this->SuspendLayout();
            // 
            // cmbRobots
            // 
            this->cmbRobots->FormattingEnabled = true;
            this->cmbRobots->Location = System::Drawing::Point(142, 57);
            this->cmbRobots->Name = L"cmbRobots";
            this->cmbRobots->Size = System::Drawing::Size(200, 24);
            this->cmbRobots->TabIndex = 0;
            this->cmbRobots->SelectedIndexChanged += gcnew System::EventHandler(this, &AsignarAlertaRobotForm::cmbRobots_SelectedIndexChanged);
            // 
            // cmbAlertasPendientes
            // 
            this->cmbAlertasPendientes->FormattingEnabled = true;
            this->cmbAlertasPendientes->Location = System::Drawing::Point(142, 117);
            this->cmbAlertasPendientes->Name = L"cmbAlertasPendientes";
            this->cmbAlertasPendientes->Size = System::Drawing::Size(200, 24);
            this->cmbAlertasPendientes->TabIndex = 1;
            this->cmbAlertasPendientes->SelectedIndexChanged += gcnew System::EventHandler(this, &AsignarAlertaRobotForm::cmbAlertasPendientes_SelectedIndexChanged);
            // 
            // btnAsignar
            // 
            this->btnAsignar->Location = System::Drawing::Point(556, 12);
            this->btnAsignar->Name = L"btnAsignar";
            this->btnAsignar->Size = System::Drawing::Size(150, 50);
            this->btnAsignar->TabIndex = 2;
            this->btnAsignar->Text = L"Asignar";
            this->btnAsignar->UseVisualStyleBackColor = true;
            this->btnAsignar->Click += gcnew System::EventHandler(this, &AsignarAlertaRobotForm::btnAsignar_Click);
            // 
            // btnLiberar
            // 
            this->btnLiberar->Location = System::Drawing::Point(556, 71);
            this->btnLiberar->Name = L"btnLiberar";
            this->btnLiberar->Size = System::Drawing::Size(150, 50);
            this->btnLiberar->TabIndex = 3;
            this->btnLiberar->Text = L"Liberar";
            this->btnLiberar->UseVisualStyleBackColor = true;
            this->btnLiberar->Click += gcnew System::EventHandler(this, &AsignarAlertaRobotForm::btnLiberar_Click);
            // 
            // btnSalir
            // 
            this->btnSalir->Location = System::Drawing::Point(556, 132);
            this->btnSalir->Name = L"btnSalir";
            this->btnSalir->Size = System::Drawing::Size(150, 50);
            this->btnSalir->TabIndex = 4;
            this->btnSalir->Text = L"Salir";
            this->btnSalir->UseVisualStyleBackColor = true;
            this->btnSalir->Click += gcnew System::EventHandler(this, &AsignarAlertaRobotForm::btnSalir_Click);
            // 
            // dgvAsignaciones
            // 
            this->dgvAsignaciones->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvAsignaciones->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
                this->RobotID,
                    this->RobotNombre, this->AlertaAsignadaID, this->TipoAlerta, this->TipoMision
            });
            this->dgvAsignaciones->Location = System::Drawing::Point(23, 202);
            this->dgvAsignaciones->Name = L"dgvAsignaciones";
            this->dgvAsignaciones->RowHeadersVisible = false;
            this->dgvAsignaciones->RowHeadersWidth = 51;
            this->dgvAsignaciones->Size = System::Drawing::Size(683, 200);
            this->dgvAsignaciones->TabIndex = 5;
            // 
            // RobotID
            // 
            this->RobotID->HeaderText = L"ID";
            this->RobotID->MinimumWidth = 6;
            this->RobotID->Name = L"RobotID";
            this->RobotID->Width = 25;
            // 
            // RobotNombre
            // 
            this->RobotNombre->HeaderText = L"Nombre";
            this->RobotNombre->MinimumWidth = 6;
            this->RobotNombre->Name = L"RobotNombre";
            this->RobotNombre->Width = 125;
            // 
            // AlertaAsignadaID
            // 
            this->AlertaAsignadaID->HeaderText = L"ID Alerta";
            this->AlertaAsignadaID->MinimumWidth = 6;
            this->AlertaAsignadaID->Name = L"AlertaAsignadaID";
            this->AlertaAsignadaID->Width = 125;
            // 
            // TipoAlerta
            // 
            this->TipoAlerta->HeaderText = L"Tipo de Alerta";
            this->TipoAlerta->MinimumWidth = 6;
            this->TipoAlerta->Name = L"TipoAlerta";
            this->TipoAlerta->Width = 125;
            // 
            // TipoMision
            // 
            this->TipoMision->HeaderText = L"Tipo de Misión";
            this->TipoMision->MinimumWidth = 6;
            this->TipoMision->Name = L"TipoMision";
            this->TipoMision->Width = 125;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(21, 60);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(115, 16);
            this->label1->TabIndex = 6;
            this->label1->Text = L"Robot Disponible:";
            this->label1->Click += gcnew System::EventHandler(this, &AsignarAlertaRobotForm::label1_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(21, 120);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(109, 16);
            this->label2->TabIndex = 7;
            this->label2->Text = L"Alerta Pendiente:";
            this->label2->Click += gcnew System::EventHandler(this, &AsignarAlertaRobotForm::label2_Click);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(23, 182);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(147, 16);
            this->label3->TabIndex = 8;
            this->label3->Text = L"Asignaciones Actuales:";
            // 
            // txtDescripcion
            // 
            this->txtDescripcion->Location = System::Drawing::Point(359, 29);
            this->txtDescripcion->Multiline = true;
            this->txtDescripcion->Name = L"txtDescripcion";
            this->txtDescripcion->Size = System::Drawing::Size(181, 153);
            this->txtDescripcion->TabIndex = 9;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(356, 5);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(82, 16);
            this->label4->TabIndex = 10;
            this->label4->Text = L"Descripción:";
            // 
            // AsignarAlertaRobotForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(718, 414);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->txtDescripcion);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->dgvAsignaciones);
            this->Controls->Add(this->btnSalir);
            this->Controls->Add(this->btnLiberar);
            this->Controls->Add(this->btnAsignar);
            this->Controls->Add(this->cmbAlertasPendientes);
            this->Controls->Add(this->cmbRobots);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"AsignarAlertaRobotForm";
            this->Text = L"Asignar Alertas a Robots";
            this->Load += gcnew System::EventHandler(this, &AsignarAlertaRobotForm::AsignarAlertaRobotForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAsignaciones))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        // ================= ESTILO =================

        void ApplyDarkTheme()
        {
            Color back = Color::FromArgb(20, 27, 47);
            Color fore = Color::FromArgb(224, 231, 255);

            this->BackColor = back;
            this->ForeColor = fore;

            array<Label^>^ labels = gcnew array<Label^>{
                label1, label2, label3, label4
            };

            for each(Label ^ lb in labels)
            {
                if (lb != nullptr)
                    lb->ForeColor = fore;
            }
        }

        void StyleButtonsAndGrids()
        {
            // Botón principal (acción fuerte)
            array<Button^>^ primary = gcnew array<Button^>{
                btnAsignar
            };

            for each(Button ^ b in primary)
            {
                if (b == nullptr) continue;
                b->FlatStyle = FlatStyle::Flat;
                b->FlatAppearance->BorderSize = 0;
                b->BackColor = Color::FromArgb(0, 140, 255);
                b->ForeColor = Color::White;
                b->Font = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);
                UIHelpers::SetRoundedRegion(b, 18);
            }

            // Botones secundarios
            array<Button^>^ secondary = gcnew array<Button^>{
                btnLiberar, btnSalir
            };

            for each(Button ^ b in secondary)
            {
                if (b == nullptr) continue;
                b->FlatStyle = FlatStyle::Flat;
                b->FlatAppearance->BorderSize = 0;
                b->BackColor = Color::FromArgb(20, 27, 47);
                b->ForeColor = Color::FromArgb(224, 231, 255);
                b->Font = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Regular);
                b->Paint += gcnew PaintEventHandler(&UIHelpers::OutlineButton_Paint);
                UIHelpers::SetRoundedRegion(b, 18);
            }

            StyleGrid(dgvAsignaciones);
        }

        void StyleGrid(DataGridView^ grid)
        {
            if (grid == nullptr) return;

            grid->BackgroundColor = Color::FromArgb(10, 16, 32);
            grid->EnableHeadersVisualStyles = false;
            grid->GridColor = Color::FromArgb(30, 41, 59);
            grid->BorderStyle = BorderStyle::None;

            grid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

            grid->ColumnHeadersDefaultCellStyle->BackColor =
                Color::FromArgb(37, 99, 235);
            grid->ColumnHeadersDefaultCellStyle->ForeColor =
                Color::FromArgb(241, 245, 249);
            grid->ColumnHeadersDefaultCellStyle->Font =
                gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);
            grid->ColumnHeadersBorderStyle = DataGridViewHeaderBorderStyle::Single;

            grid->DefaultCellStyle->BackColor =
                Color::FromArgb(20, 27, 47);
            grid->DefaultCellStyle->ForeColor =
                Color::FromArgb(226, 232, 240);
            grid->DefaultCellStyle->SelectionBackColor =
                Color::FromArgb(37, 99, 235);
            grid->DefaultCellStyle->SelectionForeColor = Color::White;

            grid->RowHeadersVisible = false;
        }

        void StyleTextBoxes()
        {
            Color back = Color::FromArgb(10, 16, 32);
            Color fore = Color::FromArgb(226, 232, 240);

            array<TextBox^>^ boxes = gcnew array<TextBox^>{
                txtDescripcion
            };

            for each(TextBox ^ tb in boxes)
            {
                if (tb == nullptr) continue;
                tb->BackColor = back;
                tb->ForeColor = fore;
                tb->BorderStyle = BorderStyle::FixedSingle;
            }
        }

        void StyleComboBoxes()
        {
            array<ComboBox^>^ combos = gcnew array<ComboBox^>{
                cmbRobots, cmbAlertasPendientes
            };

            for each(ComboBox ^ cb in combos)
            {
                if (cb == nullptr) continue;
                cb->FlatStyle = FlatStyle::Flat;
                cb->DropDownStyle = ComboBoxStyle::DropDownList;
                cb->BackColor = Color::FromArgb(15, 23, 42);
                cb->ForeColor = Color::FromArgb(226, 232, 240);
                cb->DrawMode = DrawMode::OwnerDrawFixed;
                cb->DrawItem += gcnew DrawItemEventHandler(this, &AsignarAlertaRobotForm::ComboBox_DrawItem);
            }
        }

        void ComboBox_DrawItem(System::Object^ sender, DrawItemEventArgs^ e)
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
                RectangleF(
                    (float)e->Bounds.X,
                    (float)e->Bounds.Y,
                    (float)e->Bounds.Width,
                    (float)e->Bounds.Height
                )
            );

            e->DrawFocusRectangle();
        }

        // ================= LÓGICA ORIGINAL =================

    private:
        void CargarDatos()
        {
            CargarRobotsDisponibles();
            CargarAlertasPendientes();
            CargarAsignacionesActuales();
        }

        void CargarRobotsDisponibles()
        {
            cmbRobots->Items->Clear();

            // Obtener TODOS los robots, no solo los "disponibles"
            List<Robot^>^ todosLosRobots = Service::GetRobots();

            for each(Robot ^ robot in todosLosRobots)
            {
                // Incluir robots que estén en BASE (aunque tengan Disponibilidad = false)
                // Y robots que estén disponibles
                if (robot->Disponibilidad || robot->Zona->ToUpper() == "BASE")
                {
                    String^ estado = robot->Disponibilidad ? " (Disponible)" : " (En BASE)";
                    cmbRobots->Items->Add(robot->Nombre + estado + " - ID: " + robot->ID);
                }
            }

            // Si no hay robots, mostrar mensaje
            if (cmbRobots->Items->Count == 0)
            {
                cmbRobots->Items->Add("No hay robots disponibles");
                cmbRobots->Enabled = false;
            }
            else
            {
                cmbRobots->Enabled = true;
            }
        }

        void CargarAlertasPendientes()
        {
            cmbAlertasPendientes->Items->Clear();
            List<Alert^>^ alertasPendientes = Service::GetAlertasPendientes();

            for each(Alert ^ alerta in alertasPendientes)
            {
                // Verificar que no esté ya asignada a otro robot
                bool yaAsignada = false;
                List<Robot^>^ todosRobots = Service::GetRobots();
                for each(Robot ^ robot in todosRobots)
                {
                    if (robot->AlertaAsignadaID == alerta->id)
                    {
                        yaAsignada = true;
                        break;
                    }
                }

                if (!yaAsignada)
                {
                    String^ infoAlerta = alerta->TipoAlerta + " - ID: " + alerta->id;
                    cmbAlertasPendientes->Items->Add(infoAlerta);
                }
            }
        }

        void CargarAsignacionesActuales()
        {
            dgvAsignaciones->Rows->Clear();

            try
            {
                // Obtener TODOS los robots y filtrar los que tienen alerta asignada
                List<Robot^>^ todosRobots = Service::GetRobots();

                for each(Robot ^ robot in todosRobots)
                {
                    if (robot->AlertaAsignadaID > 0)
                    {
                        Alert^ alerta = Service::buscarAlerta(robot->AlertaAsignadaID);
                        if (alerta != nullptr)
                        {
                            dgvAsignaciones->Rows->Add(
                                robot->ID,
                                robot->Nombre,
                                robot->AlertaAsignadaID,
                                alerta->TipoAlerta,
                                robot->TipoMision
                            );
                        }
                        else
                        {
                            // Si no se encuentra la alerta, mostrar igualmente el robot con la alerta asignada
                            dgvAsignaciones->Rows->Add(
                                robot->ID,
                                robot->Nombre,
                                robot->AlertaAsignadaID,
                                "Alerta no encontrada",
                                robot->TipoMision
                            );
                        }
                    }
                }

                // DEBUG: Mostrar cuántas filas se cargaron
                System::Diagnostics::Debug::WriteLine("Filas cargadas en DataGridView: " + dgvAsignaciones->Rows->Count);
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error al cargar asignaciones: " + ex->Message, "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

    private:
        System::Void btnAsignar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (cmbRobots->SelectedIndex == -1 || cmbAlertasPendientes->SelectedIndex == -1)
            {
                MessageBox::Show("Seleccione un robot y una alerta", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            try
            {
                // Obtener los textos seleccionados
                String^ robotTexto = cmbRobots->SelectedItem->ToString();
                String^ alertaTexto = cmbAlertasPendientes->SelectedItem->ToString();

                int robotID = ExtraerID(robotTexto);
                int alertaID = ExtraerID(alertaTexto);

                // Verificar que el robot existe
                Robot^ robot = Service::buscarRobotID(robotID);
                if (robot == nullptr)
                {
                    MessageBox::Show("ERROR: Robot con ID " + robotID + " no encontrado", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }

                // Verificar que la alerta existe
                Alert^ alerta = Service::buscarAlerta(alertaID);
                if (alerta == nullptr)
                {
                    MessageBox::Show("ERROR: Alerta con ID " + alertaID + " no encontrada", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }

                bool asignado = Service::AsignarAlertaRobot(robotID, alertaID);

                if (asignado) {
                    MessageBox::Show("Alerta asignada al robot exitosamente", "Éxito", MessageBoxButtons::OK);
                    // RESETEAR LAS COMBOBOX ANTES DE RECARGAR DATOS
                    cmbRobots->SelectedIndex = -1;
                    cmbAlertasPendientes->SelectedIndex = -1;
                    txtDescripcion->Clear();

                    // Recargar datos
                    CargarDatos();

                    // ASEGURARSE DE QUE LAS COMBOBOX QUEDEN EN BLANCO
                    cmbRobots->Text = "";
                    cmbAlertasPendientes->Text = "";

                }
                else {
                    MessageBox::Show("Service::AsignarAlertaRobot devolvió FALSE", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error al asignar alerta: " + ex->Message + "\nStack Trace: " + ex->StackTrace,
                    "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        System::Void btnLiberar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (dgvAsignaciones->CurrentRow == nullptr)
            {
                MessageBox::Show("Seleccione una asignación para liberar", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            try
            {
                int robotID = Convert::ToInt32(dgvAsignaciones->CurrentRow->Cells[0]->Value);

                bool liberado = Service::LiberarRobot(robotID);

                if (liberado) {
                    MessageBox::Show("Robot liberado exitosamente", "Éxito", MessageBoxButtons::OK);
                    CargarDatos(); // Recargar la lista
                    cmbAlertasPendientes->SelectedIndex = -1;
                    cmbRobots->SelectedIndex = -1;
                    txtDescripcion->Clear();
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error al liberar robot: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->Close();
        }

        int ExtraerID(String^ texto)
        {
            if (String::IsNullOrEmpty(texto)) {
                throw gcnew System::FormatException("El texto está vacío o es nulo");
            }

            // Buscar el patrón "ID: número"
            int inicio = texto->IndexOf("ID:");
            if (inicio == -1) {
                throw gcnew System::FormatException("No se encontró 'ID:' en el texto: " + texto);
            }
            inicio += 3; // Avanzar más allá de "ID:"

            // Buscar el siguiente separador (puede ser ')', '-', espacio, o fin de cadena)
            int fin = texto->IndexOf(")", inicio);
            if (fin == -1) fin = texto->IndexOf("-", inicio);
            if (fin == -1) fin = texto->IndexOf(" ", inicio + 1);
            if (fin == -1) fin = texto->Length;

            // Extraer y limpiar la cadena del ID
            String^ idStr = texto->Substring(inicio, fin - inicio)->Trim();

            // Eliminar cualquier caracter no numérico que pueda haber quedado
            idStr = Regex::Replace(idStr, "[^0-9]", "");

            if (String::IsNullOrEmpty(idStr)) {
                throw gcnew System::FormatException("No se pudo extraer un ID numérico de: " + texto);
            }

            return Convert::ToInt32(idStr);
        }

    private: System::Void AsignarAlertaRobotForm_Load(System::Object^ sender, System::EventArgs^ e) {
        CargarDatos();
    }

    private: System::Void cmbAlertasPendientes_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
        if (cmbAlertasPendientes->SelectedIndex != -1)
        {
            try
            {
                int alertaID = ExtraerID(cmbAlertasPendientes->SelectedItem->ToString());
                Alert^ alertaSeleccionada = Service::buscarAlerta(alertaID);

                if (alertaSeleccionada != nullptr)
                {
                    // MOSTRAR LA DESCRIPCIÓN EN EL TEXTBOX
                    txtDescripcion->Text = alertaSeleccionada->Description;
                }
            }
            catch (Exception^ ex)
            {
                txtDescripcion->Text = "Error al cargar descripción: " + ex->Message;
            }
        }
        else
        {
            txtDescripcion->Clear();
        }
    }
    private: System::Void cmbRobots_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
