#pragma once

namespace SheriffBotGUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace BotModel;
	using namespace BotService;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Resumen de DatosRobotsUsuariosForm
	/// </summary>
	public ref class DatosRobotsUsuariosForm : public System::Windows::Forms::Form
	{
	public:
		DatosRobotsUsuariosForm(void)
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
		~DatosRobotsUsuariosForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TextBox^ YRobot;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ XRobot;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ ZonaRobot;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ NombreRobot;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ BateriaRobot;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ IDRobot;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ btnControlRobot;
	private: System::Windows::Forms::Button^ btnDeleteRobot;
	private: System::Windows::Forms::Button^ btnModifyRobot;

	private: System::Windows::Forms::Button^ btnAddRobot;
	private: System::Windows::Forms::DataGridView^ dgvRobot;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceRobotD;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceBattery;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceRobotName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceWorkArea;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourcePosX;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourcePosY;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TextBox^ CargoUser;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ PasswordUser;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ NombreUser;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ IDUser;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnDeleteUser;
	private: System::Windows::Forms::Button^ btnModifyUser;

	private: System::Windows::Forms::Button^ btnAddUser;
	private: System::Windows::Forms::DataGridView^ dgvUser;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceUserID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceUserName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourcePassword;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceRole;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->YRobot = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->XRobot = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->ZonaRobot = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->NombreRobot = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->BateriaRobot = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->IDRobot = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->btnControlRobot = (gcnew System::Windows::Forms::Button());
			this->btnDeleteRobot = (gcnew System::Windows::Forms::Button());
			this->btnModifyRobot = (gcnew System::Windows::Forms::Button());
			this->btnAddRobot = (gcnew System::Windows::Forms::Button());
			this->dgvRobot = (gcnew System::Windows::Forms::DataGridView());
			this->ResourceRobotD = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceBattery = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceRobotName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceWorkArea = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourcePosX = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourcePosY = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->CargoUser = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->PasswordUser = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->NombreUser = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->IDUser = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnDeleteUser = (gcnew System::Windows::Forms::Button());
			this->btnModifyUser = (gcnew System::Windows::Forms::Button());
			this->btnAddUser = (gcnew System::Windows::Forms::Button());
			this->dgvUser = (gcnew System::Windows::Forms::DataGridView());
			this->ResourceUserID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceUserName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourcePassword = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceRole = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabControl1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRobot))->BeginInit();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUser))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(679, 658);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->YRobot);
			this->tabPage2->Controls->Add(this->label7);
			this->tabPage2->Controls->Add(this->XRobot);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->ZonaRobot);
			this->tabPage2->Controls->Add(this->label9);
			this->tabPage2->Controls->Add(this->NombreRobot);
			this->tabPage2->Controls->Add(this->label10);
			this->tabPage2->Controls->Add(this->BateriaRobot);
			this->tabPage2->Controls->Add(this->label11);
			this->tabPage2->Controls->Add(this->IDRobot);
			this->tabPage2->Controls->Add(this->label12);
			this->tabPage2->Controls->Add(this->btnControlRobot);
			this->tabPage2->Controls->Add(this->btnDeleteRobot);
			this->tabPage2->Controls->Add(this->btnModifyRobot);
			this->tabPage2->Controls->Add(this->btnAddRobot);
			this->tabPage2->Controls->Add(this->dgvRobot);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Size = System::Drawing::Size(671, 629);
			this->tabPage2->TabIndex = 0;
			this->tabPage2->Text = L"Administrar Robots";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// YRobot
			// 
			this->YRobot->Location = System::Drawing::Point(152, 337);
			this->YRobot->Name = L"YRobot";
			this->YRobot->Size = System::Drawing::Size(213, 22);
			this->YRobot->TabIndex = 35;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label7->Location = System::Drawing::Point(15, 333);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(104, 25);
			this->label7->TabIndex = 34;
			this->label7->Text = L"Posición Y";
			// 
			// XRobot
			// 
			this->XRobot->Location = System::Drawing::Point(152, 279);
			this->XRobot->Name = L"XRobot";
			this->XRobot->Size = System::Drawing::Size(213, 22);
			this->XRobot->TabIndex = 33;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label8->Location = System::Drawing::Point(15, 275);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(105, 25);
			this->label8->TabIndex = 32;
			this->label8->Text = L"Posición X";
			// 
			// ZonaRobot
			// 
			this->ZonaRobot->Location = System::Drawing::Point(152, 225);
			this->ZonaRobot->Name = L"ZonaRobot";
			this->ZonaRobot->Size = System::Drawing::Size(213, 22);
			this->ZonaRobot->TabIndex = 31;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label9->Location = System::Drawing::Point(15, 221);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(121, 25);
			this->label9->TabIndex = 30;
			this->label9->Text = L"Zona trabajo";
			// 
			// NombreRobot
			// 
			this->NombreRobot->Location = System::Drawing::Point(152, 165);
			this->NombreRobot->Name = L"NombreRobot";
			this->NombreRobot->Size = System::Drawing::Size(213, 22);
			this->NombreRobot->TabIndex = 29;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label10->Location = System::Drawing::Point(15, 161);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(81, 25);
			this->label10->TabIndex = 28;
			this->label10->Text = L"Nombre";
			// 
			// BateriaRobot
			// 
			this->BateriaRobot->Location = System::Drawing::Point(152, 108);
			this->BateriaRobot->Name = L"BateriaRobot";
			this->BateriaRobot->Size = System::Drawing::Size(213, 22);
			this->BateriaRobot->TabIndex = 27;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label11->Location = System::Drawing::Point(15, 104);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(73, 25);
			this->label11->TabIndex = 26;
			this->label11->Text = L"Batería";
			// 
			// IDRobot
			// 
			this->IDRobot->Location = System::Drawing::Point(152, 51);
			this->IDRobot->Name = L"IDRobot";
			this->IDRobot->Size = System::Drawing::Size(213, 22);
			this->IDRobot->TabIndex = 25;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label12->Location = System::Drawing::Point(15, 47);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(87, 25);
			this->label12->TabIndex = 24;
			this->label12->Text = L"ID Robot";
			// 
			// btnControlRobot
			// 
			this->btnControlRobot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnControlRobot->Location = System::Drawing::Point(454, 258);
			this->btnControlRobot->Name = L"btnControlRobot";
			this->btnControlRobot->Size = System::Drawing::Size(177, 49);
			this->btnControlRobot->TabIndex = 23;
			this->btnControlRobot->Text = L"Controlar";
			this->btnControlRobot->UseVisualStyleBackColor = true;
			this->btnControlRobot->Click += gcnew System::EventHandler(this, &DatosRobotsUsuariosForm::btnControlRobot_Click);
			// 
			// btnDeleteRobot
			// 
			this->btnDeleteRobot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnDeleteRobot->Location = System::Drawing::Point(454, 189);
			this->btnDeleteRobot->Name = L"btnDeleteRobot";
			this->btnDeleteRobot->Size = System::Drawing::Size(177, 49);
			this->btnDeleteRobot->TabIndex = 22;
			this->btnDeleteRobot->Text = L"Eliminar";
			this->btnDeleteRobot->UseVisualStyleBackColor = true;
			this->btnDeleteRobot->Click += gcnew System::EventHandler(this, &DatosRobotsUsuariosForm::btnDeleteRobot_Click);
			// 
			// btnModifyRobot
			// 
			this->btnModifyRobot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnModifyRobot->Location = System::Drawing::Point(454, 122);
			this->btnModifyRobot->Name = L"btnModifyRobot";
			this->btnModifyRobot->Size = System::Drawing::Size(177, 49);
			this->btnModifyRobot->TabIndex = 21;
			this->btnModifyRobot->Text = L"Modificar";
			this->btnModifyRobot->UseVisualStyleBackColor = true;
			this->btnModifyRobot->Click += gcnew System::EventHandler(this, &DatosRobotsUsuariosForm::btnModifyRobot_Click);
			// 
			// btnAddRobot
			// 
			this->btnAddRobot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnAddRobot->Location = System::Drawing::Point(454, 52);
			this->btnAddRobot->Name = L"btnAddRobot";
			this->btnAddRobot->Size = System::Drawing::Size(177, 49);
			this->btnAddRobot->TabIndex = 19;
			this->btnAddRobot->Text = L"Agregar";
			this->btnAddRobot->UseVisualStyleBackColor = true;
			this->btnAddRobot->Click += gcnew System::EventHandler(this, &DatosRobotsUsuariosForm::btnAddRobot_Click);
			// 
			// dgvRobot
			// 
			this->dgvRobot->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvRobot->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->ResourceRobotD,
					this->ResourceBattery, this->ResourceRobotName, this->ResourceWorkArea, this->ResourcePosX, this->ResourcePosY
			});
			this->dgvRobot->Location = System::Drawing::Point(0, 404);
			this->dgvRobot->Name = L"dgvRobot";
			this->dgvRobot->RowHeadersWidth = 51;
			this->dgvRobot->RowTemplate->Height = 24;
			this->dgvRobot->Size = System::Drawing::Size(706, 222);
			this->dgvRobot->TabIndex = 18;
			this->dgvRobot->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DatosRobotsUsuariosForm::dgvRobot_CellClick);
			// 
			// ResourceRobotD
			// 
			this->ResourceRobotD->HeaderText = L"ID Robot";
			this->ResourceRobotD->MinimumWidth = 6;
			this->ResourceRobotD->Name = L"ResourceRobotD";
			this->ResourceRobotD->Width = 125;
			// 
			// ResourceBattery
			// 
			this->ResourceBattery->HeaderText = L"Batería";
			this->ResourceBattery->MinimumWidth = 6;
			this->ResourceBattery->Name = L"ResourceBattery";
			this->ResourceBattery->Width = 125;
			// 
			// ResourceRobotName
			// 
			this->ResourceRobotName->HeaderText = L"Nombre";
			this->ResourceRobotName->MinimumWidth = 6;
			this->ResourceRobotName->Name = L"ResourceRobotName";
			this->ResourceRobotName->Width = 125;
			// 
			// ResourceWorkArea
			// 
			this->ResourceWorkArea->HeaderText = L"Zona de trabajo";
			this->ResourceWorkArea->MinimumWidth = 6;
			this->ResourceWorkArea->Name = L"ResourceWorkArea";
			this->ResourceWorkArea->Width = 125;
			// 
			// ResourcePosX
			// 
			this->ResourcePosX->HeaderText = L"Posición X";
			this->ResourcePosX->MinimumWidth = 6;
			this->ResourcePosX->Name = L"ResourcePosX";
			this->ResourcePosX->Width = 125;
			// 
			// ResourcePosY
			// 
			this->ResourcePosY->HeaderText = L"Posición Y";
			this->ResourcePosY->MinimumWidth = 6;
			this->ResourcePosY->Name = L"ResourcePosY";
			this->ResourcePosY->Width = 125;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->CargoUser);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->PasswordUser);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->NombreUser);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->IDUser);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->btnDeleteUser);
			this->tabPage1->Controls->Add(this->btnModifyUser);
			this->tabPage1->Controls->Add(this->btnAddUser);
			this->tabPage1->Controls->Add(this->dgvUser);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Size = System::Drawing::Size(671, 629);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Administrar Usuarios";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// CargoUser
			// 
			this->CargoUser->Location = System::Drawing::Point(216, 225);
			this->CargoUser->Name = L"CargoUser";
			this->CargoUser->Size = System::Drawing::Size(213, 22);
			this->CargoUser->TabIndex = 13;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->Location = System::Drawing::Point(15, 221);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 25);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Cargo";
			// 
			// PasswordUser
			// 
			this->PasswordUser->Location = System::Drawing::Point(216, 165);
			this->PasswordUser->Name = L"PasswordUser";
			this->PasswordUser->Size = System::Drawing::Size(213, 22);
			this->PasswordUser->TabIndex = 11;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(15, 161);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(114, 25);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Contraseña";
			// 
			// NombreUser
			// 
			this->NombreUser->Location = System::Drawing::Point(216, 108);
			this->NombreUser->Name = L"NombreUser";
			this->NombreUser->Size = System::Drawing::Size(213, 22);
			this->NombreUser->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(15, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(177, 25);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Nombre de usuario";
			// 
			// IDUser
			// 
			this->IDUser->Location = System::Drawing::Point(216, 51);
			this->IDUser->Name = L"IDUser";
			this->IDUser->Size = System::Drawing::Size(213, 22);
			this->IDUser->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(15, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 25);
			this->label1->TabIndex = 6;
			this->label1->Text = L"ID Usuario";
			// 
			// btnDeleteUser
			// 
			this->btnDeleteUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnDeleteUser->Location = System::Drawing::Point(477, 175);
			this->btnDeleteUser->Name = L"btnDeleteUser";
			this->btnDeleteUser->Size = System::Drawing::Size(177, 49);
			this->btnDeleteUser->TabIndex = 4;
			this->btnDeleteUser->Text = L"Eliminar";
			this->btnDeleteUser->UseVisualStyleBackColor = true;
			this->btnDeleteUser->Click += gcnew System::EventHandler(this, &DatosRobotsUsuariosForm::btnDeleteUser_Click);
			// 
			// btnModifyUser
			// 
			this->btnModifyUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnModifyUser->Location = System::Drawing::Point(477, 108);
			this->btnModifyUser->Name = L"btnModifyUser";
			this->btnModifyUser->Size = System::Drawing::Size(177, 49);
			this->btnModifyUser->TabIndex = 3;
			this->btnModifyUser->Text = L"Modificar";
			this->btnModifyUser->UseVisualStyleBackColor = true;
			this->btnModifyUser->Click += gcnew System::EventHandler(this, &DatosRobotsUsuariosForm::btnModifyUser_Click);
			// 
			// btnAddUser
			// 
			this->btnAddUser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnAddUser->Location = System::Drawing::Point(477, 35);
			this->btnAddUser->Name = L"btnAddUser";
			this->btnAddUser->Size = System::Drawing::Size(177, 49);
			this->btnAddUser->TabIndex = 1;
			this->btnAddUser->Text = L"Agregar";
			this->btnAddUser->UseVisualStyleBackColor = true;
			this->btnAddUser->Click += gcnew System::EventHandler(this, &DatosRobotsUsuariosForm::btnAddUser_Click);
			// 
			// dgvUser
			// 
			this->dgvUser->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvUser->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->ResourceUserID,
					this->ResourceUserName, this->ResourcePassword, this->ResourceRole
			});
			this->dgvUser->Location = System::Drawing::Point(8, 321);
			this->dgvUser->Name = L"dgvUser";
			this->dgvUser->RowHeadersVisible = false;
			this->dgvUser->RowHeadersWidth = 51;
			this->dgvUser->RowTemplate->Height = 24;
			this->dgvUser->Size = System::Drawing::Size(646, 301);
			this->dgvUser->TabIndex = 0;
			this->dgvUser->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DatosRobotsUsuariosForm::dgvUser_CellClick);
			// 
			// ResourceUserID
			// 
			this->ResourceUserID->HeaderText = L"ID Usuario";
			this->ResourceUserID->MinimumWidth = 6;
			this->ResourceUserID->Name = L"ResourceUserID";
			this->ResourceUserID->Width = 125;
			// 
			// ResourceUserName
			// 
			this->ResourceUserName->HeaderText = L"Nombre de usuario";
			this->ResourceUserName->MinimumWidth = 6;
			this->ResourceUserName->Name = L"ResourceUserName";
			this->ResourceUserName->Width = 125;
			// 
			// ResourcePassword
			// 
			this->ResourcePassword->HeaderText = L"Contraseña";
			this->ResourcePassword->MinimumWidth = 6;
			this->ResourcePassword->Name = L"ResourcePassword";
			this->ResourcePassword->Width = 125;
			// 
			// ResourceRole
			// 
			this->ResourceRole->HeaderText = L"Cargo";
			this->ResourceRole->MinimumWidth = 6;
			this->ResourceRole->Name = L"ResourceRole";
			this->ResourceRole->Width = 125;
			// 
			// DatosRobotsUsuariosForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(693, 675);
			this->Controls->Add(this->tabControl1);
			this->Name = L"DatosRobotsUsuariosForm";
			this->Text = L"DatosRobotsUsuariosForm";
			this->Load += gcnew System::EventHandler(this, &DatosRobotsUsuariosForm::DatosRobotsUsuariosForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRobot))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUser))->EndInit();
			this->ResumeLayout(false);

		}
		#pragma endregion
		private: System::Void btnAddRobot_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				if (String::IsNullOrEmpty(IDRobot->Text) || String::IsNullOrEmpty(NombreRobot->Text) || String::IsNullOrEmpty(ZonaRobot->Text)) {
					MessageBox::Show("Por favor, complete todos los campos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				Robot^ robot = gcnew Robot();

				robot->ID = Convert::ToInt32(IDRobot->Text);
				robot->Nombre = NombreRobot->Text;
				robot->Bateria = Convert::ToInt32(BateriaRobot->Text);//ver luego su función que de eso
				robot->Zona = ZonaRobot->Text;
				double x = Convert::ToDouble(XRobot->Text);
				double y = Convert::ToDouble(YRobot->Text);
				robot->PosicionRobot = Service::delimitarZonaTrabajo(x, y);

				int id = Convert::ToInt32(IDRobot->Text);
				Robot^ robotExistente = Service::buscarRobotID(id);
				if (robotExistente != nullptr) {
					MessageBox::Show("El robot ya existe.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				Service::registrarRobot(robot);
				MessageBox::Show("Robot agregado exitosamente", "Exito", MessageBoxButtons::OK);

				ShowRobots();
				ClearFieldsR();
			}
			catch (FormatException^) {
				MessageBox::Show("Por favor, ingrese valores válidos en los campos numéricos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al agregar robot: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		private: System::Void btnModifyRobot_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				if (String::IsNullOrEmpty(NombreRobot->Text)) {
					MessageBox::Show("Ingrese un nombre de robot a modificar", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				Robot^ robot = gcnew Robot();

				robot->ID = Convert::ToInt32(IDRobot->Text);
				robot->Nombre = NombreRobot->Text;
				robot->Zona = ZonaRobot->Text;

				int robotModificar = Service::modificarRobotID(robot);
				if (robotModificar != 0) {
					ShowRobots();
					ClearFieldsR();
					MessageBox::Show("Robot modificado exitosamente", "Exito", MessageBoxButtons::OK);
				}
				else {
					MessageBox::Show("No se encontró el robot", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			catch (FormatException^) {
				MessageBox::Show("Por favor, ingrese valores válidos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al modificar robot: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		private: System::Void btnDeleteRobot_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ robotID = IDRobot->Text->Trim();
			if (robotID->Equals("")) {
				MessageBox::Show("Debe seleccionar un robot");
				return;
			}
			try {
				System::Windows::Forms::DialogResult dlgResult = MessageBox::Show("¿Desea eliminar el robot?",
					"Confirmación", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

				if (dlgResult == System::Windows::Forms::DialogResult::Yes) {
					bool eliminado = Service::borrarRobotID(Convert::ToInt32(robotID));
					if (eliminado) {
						ShowRobots();
						ClearFieldsR();
						MessageBox::Show("Robot eliminado exitosamente", "Exito", MessageBoxButtons::OK);
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al eliminar robot: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		private: System::Void dgvRobot_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			int robotID = Int32::Parse(dgvRobot->Rows[dgvRobot->SelectedCells[0]->RowIndex]->Cells[0]->Value->ToString());
			Robot^ robot = (Robot^)Service::buscarRobotID(robotID);
			if (robot != nullptr) {
				IDRobot->Text = Convert::ToString(robot->ID);
				NombreRobot->Text = robot->Nombre;
				ZonaRobot->Text = robot->Zona;
				BateriaRobot->Text = Convert::ToString(robot->Bateria);
				XRobot->Text = Convert::ToString(robot->PosicionRobot->x);
				YRobot->Text = Convert::ToString(robot->PosicionRobot->y);

				//se pondria lo de la foto
			}
		}
		private:
			void ShowRobots() {//crear un atributo de bateria al robot
				List<Robot^>^ robots = Service::GetRobots();
				if (robots != nullptr) {
					dgvRobot->Rows->Clear();
					for (int i = 0; i < robots->Count; i++) {
						if (robots[i]->GetType() == Robot::typeid) {
							dgvRobot->Rows->Add(gcnew array<String^>{
								"" + robots[i]->ID, "" + robots[i]->Bateria, robots[i]->Nombre,
									robots[i]->Zona, "" + robots[i]->PosicionRobot->x, "" + robots[i]->PosicionRobot->y
							});
						}
					}
				}
			}
		private:
			void ClearFieldsR() {
				IDRobot->Text = "";
				NombreRobot->Text = "";
				ZonaRobot->Text = "";
				XRobot->Text = "";
				YRobot->Text = "";
				BateriaRobot->Text = "";
			}
		private:
			void MostrarDatosRobot(Robot^ robotEncontrado) {
				IDRobot->Text = Convert::ToString(robotEncontrado->ID);
				ZonaRobot->Text = robotEncontrado->Zona;
				XRobot->Text = Convert::ToString(robotEncontrado->PosicionRobot->x);
				YRobot->Text = Convert::ToString(robotEncontrado->PosicionRobot->y);
			}
		private: System::Void btnAddUser_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				if (String::IsNullOrEmpty(IDUser->Text) || String::IsNullOrEmpty(NombreUser->Text) ||
					String::IsNullOrEmpty(CargoUser->Text) || String::IsNullOrEmpty(PasswordUser->Text)) {
					MessageBox::Show("Por favor, complete todos los campos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				DatosUsuario^ usuario = gcnew DatosUsuario();


				usuario->ID = Convert::ToInt32(IDUser->Text);
				usuario->Nombre = NombreUser->Text;
				usuario->Cargo = CargoUser->Text;
				usuario->Contra = PasswordUser->Text;

				int id = Convert::ToInt32(IDUser->Text);
				DatosUsuario^ usuarioExistente = Service::buscarUsuarioID(id);
				if (usuarioExistente != nullptr) {
					MessageBox::Show("El usuario ya existe.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				Service::registrarUsuario(usuario);
				MessageBox::Show("Usuario agregado exitosamente", "Exito", MessageBoxButtons::OK);

				ShowUsuarios();
				ClearFieldsU();

			}
			catch (FormatException^) {
				MessageBox::Show("Por favor, ingrese valores válidos en los campos numéricos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al agregar usuario: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		private: System::Void btnModifyUser_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				if (String::IsNullOrEmpty(IDUser->Text)) {
					MessageBox::Show("Ingrese el nombre de usuario para modificar", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				DatosUsuario^ usuario = gcnew DatosUsuario();
				usuario->ID = Convert::ToInt32(IDUser->Text);
				usuario->Nombre = NombreUser->Text;
				usuario->Cargo = CargoUser->Text;
				usuario->Contra = PasswordUser->Text;

				Service::modificarUsuarioID(usuario);
				ShowUsuarios();
				ClearFieldsU();
				MessageBox::Show("Usuario modificado exitosamente", "Exito", MessageBoxButtons::OK);
				
			}
			catch (FormatException^) {
				MessageBox::Show("Por favor, ingrese valores válidos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al modificar usuario: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		private: System::Void btnDeleteUser_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ UsuarioName = NombreUser->Text->Trim();
			if (UsuarioName == "") {
				MessageBox::Show("Debe seleccionar un usuario");
				return;
			}
			
			try {
				System::Windows::Forms::DialogResult dlgResult = MessageBox::Show("¿Desea eliminar el usuario?",
					"Confirmación", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

				if (dlgResult == System::Windows::Forms::DialogResult::Yes) {
					bool eliminado = Service::borrarUsuarioNombre(UsuarioName);
					if (eliminado) {
						ShowUsuarios();
						ClearFieldsU();
						MessageBox::Show("Usuario eliminado exitosamente", "Exito", MessageBoxButtons::OK);
					}
					else {
						MessageBox::Show("No se encontró el usuario", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}				
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al eliminar usuario: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		private: System::Void dgvUser_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			int usuarioID = Int32::Parse(dgvUser->Rows[dgvUser->SelectedCells[0]->RowIndex]->Cells[0]->Value->ToString());
			DatosUsuario^ usuario = (DatosUsuario^)Service::buscarUsuarioID(usuarioID);
			if (usuario != nullptr) {
				IDUser->Text = Convert::ToString(usuario->ID);
				NombreUser->Text = usuario->Nombre;
				CargoUser->Text = usuario->Cargo;
				PasswordUser->Text = usuario->Contra;
			}
		}
		private:
			void ShowUsuarios() {
				List<DatosUsuario^>^ usuarioList = Service::GetUsuarios();
				if (usuarioList != nullptr) {
					dgvUser->Rows->Clear();
					for (int i = 0; i < usuarioList->Count; i++) {
						if (usuarioList[i]->GetType() == DatosUsuario::typeid) {
							dgvUser->Rows->Add(gcnew array<String^>{
								"" + usuarioList[i]->ID, usuarioList[i]->Nombre,
									usuarioList[i]->Contra, usuarioList[i]->Cargo
							});
						}
					}
				}
			}
		private:
			void ClearFieldsU() {
				IDUser->Text = "";
				NombreUser->Text = "";
				CargoUser->Text = "";
				PasswordUser->Text = "";
			}
		private:
			void MostrarDatosUsuario(DatosUsuario^ u) {
				IDUser->Text = Convert::ToString(u->ID);
				NombreUser->Text = u->Nombre;
				CargoUser->Text = u->Cargo;
				PasswordUser->Text = u->Contra;
			}
		private: System::Void btnControlRobot_Click(System::Object^ sender, System::EventArgs^ e) {
			/*Dirige al robot elegido*/
		}
		private: System::Void DatosRobotsUsuariosForm_Load(System::Object^ sender, System::EventArgs^ e) {
			ShowUsuarios();
			ShowRobots();
			ClearFieldsR();
			ClearFieldsU();

		}
	};
}
