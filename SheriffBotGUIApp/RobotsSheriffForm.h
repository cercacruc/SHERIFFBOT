#pragma once

namespace SheriffBotGUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Collections::Generic;
	using namespace BotModel;
	using namespace BotService;

	/// <summary>
	/// Resumen de RobotsSheriffForm
	/// </summary>
	public ref class RobotsSheriffForm : public System::Windows::Forms::Form
	{
	public:
		RobotsSheriffForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~RobotsSheriffForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ cmbRobots;
	private: System::Windows::Forms::PictureBox^ pbPhoto;
	protected:


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtCaracteristicas;
	private: System::Windows::Forms::Button^ btnRobots;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ cmbLugares;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cmbRobots = (gcnew System::Windows::Forms::ComboBox());
			this->pbPhoto = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtCaracteristicas = (gcnew System::Windows::Forms::TextBox());
			this->btnRobots = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cmbLugares = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhoto))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(181, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Robots Registrados";
			// 
			// cmbRobots
			// 
			this->cmbRobots->FormattingEnabled = true;
			this->cmbRobots->Location = System::Drawing::Point(210, 10);
			this->cmbRobots->Name = L"cmbRobots";
			this->cmbRobots->Size = System::Drawing::Size(227, 24);
			this->cmbRobots->TabIndex = 1;
			this->cmbRobots->SelectedIndexChanged += gcnew System::EventHandler(this, &RobotsSheriffForm::cmbRobots_SelectedIndexChanged);
			// 
			// pbPhoto
			// 
			this->pbPhoto->Location = System::Drawing::Point(17, 48);
			this->pbPhoto->Name = L"pbPhoto";
			this->pbPhoto->Size = System::Drawing::Size(188, 151);
			this->pbPhoto->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbPhoto->TabIndex = 2;
			this->pbPhoto->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(211, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(141, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Características";
			// 
			// txtCaracteristicas
			// 
			this->txtCaracteristicas->Location = System::Drawing::Point(216, 77);
			this->txtCaracteristicas->Multiline = true;
			this->txtCaracteristicas->Name = L"txtCaracteristicas";
			this->txtCaracteristicas->Size = System::Drawing::Size(221, 122);
			this->txtCaracteristicas->TabIndex = 4;
			// 
			// btnRobots
			// 
			this->btnRobots->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRobots->Location = System::Drawing::Point(278, 206);
			this->btnRobots->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnRobots->Name = L"btnRobots";
			this->btnRobots->Size = System::Drawing::Size(159, 47);
			this->btnRobots->TabIndex = 14;
			this->btnRobots->Text = L"Enviar";
			this->btnRobots->UseVisualStyleBackColor = true;
			this->btnRobots->Click += gcnew System::EventHandler(this, &RobotsSheriffForm::btnRobots_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 216);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 25);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Lugar: ";
			// 
			// cmbLugares
			// 
			this->cmbLugares->FormattingEnabled = true;
			this->cmbLugares->Location = System::Drawing::Point(91, 221);
			this->cmbLugares->Name = L"cmbLugares";
			this->cmbLugares->Size = System::Drawing::Size(181, 24);
			this->cmbLugares->TabIndex = 17;
			// 
			// RobotsSheriffForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(450, 264);
			this->Controls->Add(this->cmbLugares);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnRobots);
			this->Controls->Add(this->txtCaracteristicas);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pbPhoto);
			this->Controls->Add(this->cmbRobots);
			this->Controls->Add(this->label1);
			this->Name = L"RobotsSheriffForm";
			this->Text = L"EnviarRobot";
			this->Load += gcnew System::EventHandler(this, &RobotsSheriffForm::RobotsSheriffForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhoto))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion
		private: void CargarListaRobots() {
			List<Robot^>^ robots = Service::GetRobots();
			cmbRobots->Visible = true;
			cmbRobots->Enabled = true;
			cmbRobots->Items->Clear();

			for each (Robot ^ robot in robots) {
				cmbRobots->Items->Add(robot->Nombre);
			}
		}
		private: System::Void RobotsSheriffForm_Load(System::Object^ sender, System::EventArgs^ e) {
			CargarListaRobots();
			CargarListaLugares();
		}
		private: System::Void cmbRobots_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			String^ robotLista = cmbRobots->Text;

			Robot^ robotSeleccionado = Service::buscarRobotNombre(robotLista);
			ActualizarCaracteristicasRobot(robotSeleccionado);
			ActualizarFotoRobot(robotSeleccionado);
		}
		private: void ActualizarCaracteristicasRobot(Robot^ robot) {
			txtCaracteristicas->Text = robot->Caracteristicas;
		}
		private: void ActualizarFotoRobot(Robot^ robot) {
			if (robot->Photo != nullptr) {
				System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(robot->Photo);
				pbPhoto->Image = Image::FromStream(ms);
			}
			else {
				pbPhoto->Image = nullptr;
				pbPhoto->Invalidate();
			}
		}
		private: System::Void btnRobots_Click(System::Object^ sender, System::EventArgs^ e) {

		}
		private: void CargarListaLugares() {

		}
	};
}
