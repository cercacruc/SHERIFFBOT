#pragma once

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
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ RobotID;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ RobotNombre;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ AlertaAsignadaID;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ TipoAlerta;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ TipoMision;
           System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->cmbRobots = (gcnew System::Windows::Forms::ComboBox());
            this->cmbAlertasPendientes = (gcnew System::Windows::Forms::ComboBox());
            this->btnAsignar = (gcnew System::Windows::Forms::Button());
            this->btnLiberar = (gcnew System::Windows::Forms::Button());
            this->btnSalir = (gcnew System::Windows::Forms::Button());
            this->dgvAsignaciones = (gcnew System::Windows::Forms::DataGridView());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->RobotID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->RobotNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->AlertaAsignadaID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->TipoAlerta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->TipoMision = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAsignaciones))->BeginInit();
            this->SuspendLayout();
            // 
            // cmbRobots
            // 
            this->cmbRobots->FormattingEnabled = true;
            this->cmbRobots->Location = System::Drawing::Point(141, 20);
            this->cmbRobots->Name = L"cmbRobots";
            this->cmbRobots->Size = System::Drawing::Size(200, 24);
            this->cmbRobots->TabIndex = 0;
            // 
            // cmbAlertasPendientes
            // 
            this->cmbAlertasPendientes->FormattingEnabled = true;
            this->cmbAlertasPendientes->Location = System::Drawing::Point(141, 60);
            this->cmbAlertasPendientes->Name = L"cmbAlertasPendientes";
            this->cmbAlertasPendientes->Size = System::Drawing::Size(200, 24);
            this->cmbAlertasPendientes->TabIndex = 1;
            // 
            // btnAsignar
            // 
            this->btnAsignar->Location = System::Drawing::Point(351, 20);
            this->btnAsignar->Name = L"btnAsignar";
            this->btnAsignar->Size = System::Drawing::Size(100, 30);
            this->btnAsignar->TabIndex = 2;
            this->btnAsignar->Text = L"Asignar";
            this->btnAsignar->UseVisualStyleBackColor = true;
            this->btnAsignar->Click += gcnew System::EventHandler(this, &AsignarAlertaRobotForm::btnAsignar_Click);
            // 
            // btnLiberar
            // 
            this->btnLiberar->Location = System::Drawing::Point(351, 60);
            this->btnLiberar->Name = L"btnLiberar";
            this->btnLiberar->Size = System::Drawing::Size(100, 30);
            this->btnLiberar->TabIndex = 3;
            this->btnLiberar->Text = L"Liberar";
            this->btnLiberar->UseVisualStyleBackColor = true;
            this->btnLiberar->Click += gcnew System::EventHandler(this, &AsignarAlertaRobotForm::btnLiberar_Click);
            // 
            // btnSalir
            // 
            this->btnSalir->Location = System::Drawing::Point(351, 100);
            this->btnSalir->Name = L"btnSalir";
            this->btnSalir->Size = System::Drawing::Size(100, 30);
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
            this->dgvAsignaciones->Location = System::Drawing::Point(20, 150);
            this->dgvAsignaciones->Name = L"dgvAsignaciones";
            this->dgvAsignaciones->RowHeadersVisible = false;
            this->dgvAsignaciones->RowHeadersWidth = 51;
            this->dgvAsignaciones->Size = System::Drawing::Size(600, 200);
            this->dgvAsignaciones->TabIndex = 5;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(20, 23);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(115, 16);
            this->label1->TabIndex = 6;
            this->label1->Text = L"Robot Disponible:";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(20, 63);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(109, 16);
            this->label2->TabIndex = 7;
            this->label2->Text = L"Alerta Pendiente:";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(20, 130);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(147, 16);
            this->label3->TabIndex = 8;
            this->label3->Text = L"Asignaciones Actuales:";
            // 
            // RobotID
            // 
            this->RobotID->HeaderText = L"ID";
            this->RobotID->MinimumWidth = 6;
            this->RobotID->Name = L"RobotID";
            this->RobotID->Width = 125;
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
            // AsignarAlertaRobotForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(650, 370);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->dgvAsignaciones);
            this->Controls->Add(this->btnSalir);
            this->Controls->Add(this->btnLiberar);
            this->Controls->Add(this->btnAsignar);
            this->Controls->Add(this->cmbAlertasPendientes);
            this->Controls->Add(this->cmbRobots);
            this->Name = L"AsignarAlertaRobotForm";
            this->Text = L"Asignar Alertas a Robots";
            this->Load += gcnew System::EventHandler(this, &AsignarAlertaRobotForm::AsignarAlertaRobotForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAsignaciones))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
        #pragma endregion
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
                List<Robot^>^ robotsDisponibles = Service::listaRobotsDisponibles();

                for each (Robot ^ robot in robotsDisponibles)
                {
                    cmbRobots->Items->Add(robot->Nombre + " (ID: " + robot->ID + ")");
                }
            }

            void CargarAlertasPendientes()
            {
                cmbAlertasPendientes->Items->Clear();
                List<Alert^>^ alertasPendientes = Service::GetAlertasPendientes();

                for each (Alert ^ alerta in alertasPendientes)
                {
                    // Verificar que no esté ya asignada a otro robot
                    bool yaAsignada = false;
                    List<Robot^>^ todosRobots = Service::GetRobots();
                    for each (Robot ^ robot in todosRobots)
                    {
                        if (robot->AlertaAsignadaID == alerta->id)
                        {
                            yaAsignada = true;
                            break;
                        }
                    }

                    if (!yaAsignada)
                    {
                        String^ infoAlerta = alerta->TipoAlerta + " - ID: " + alerta->id + " - " + alerta->Description;
                        cmbAlertasPendientes->Items->Add(infoAlerta);
                    }
                }
            }

            void CargarAsignacionesActuales()
            {
                dgvAsignaciones->Rows->Clear();
                List<Robot^>^ robots = Service::GetRobotsConAlertas();

                for each (Robot ^ robot in robots)
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
                    }
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
                    int robotID = ExtraerID(cmbRobots->SelectedItem->ToString());
                    int alertaID = ExtraerID(cmbAlertasPendientes->SelectedItem->ToString());

                    bool asignado = Service::AsignarAlertaRobot(robotID, alertaID);

                    if (asignado) {
                        MessageBox::Show("Alerta asignada al robot exitosamente", "Éxito", MessageBoxButtons::OK);
                        CargarDatos(); // Recargar la lista
                    }
                }
                catch (Exception^ ex)
                {
                    MessageBox::Show("Error al asignar alerta: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
    };
}