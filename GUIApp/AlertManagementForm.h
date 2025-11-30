#pragma once

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Collections::Generic;
	using namespace BotModel;
	using namespace BotService;
	using namespace System::Threading;

	/// <summary>
	/// Resumen de AlertManagementForm
	/// </summary>
	public ref class AlertManagementForm : public System::Windows::Forms::Form
	{
	public:
		AlertManagementForm(void)
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
		~AlertManagementForm()
		{
			if (components)
			{
				delete components;
			}
			StopTimer();
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;




	private: System::Windows::Forms::Button^ btnAtendidoObj;












	private: System::Windows::Forms::TabPage^ tabPage3;
















	private: System::Windows::Forms::Button^ btnAtendidoDTI;











	private: System::Windows::Forms::DataGridView^ dgvOjbPerdido;





	private: System::Windows::Forms::DataGridView^ dgvAltercado;




	private: System::Windows::Forms::DataGridView^ dgvDTI;











	private: System::Windows::Forms::TextBox^ txtDescriptionObj;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::PictureBox^ pbPhotoObj;

















	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TextBox^ txtDescriptionAltercado;
	private: System::Windows::Forms::PictureBox^ pbPhotoAltercado;
	private: System::Windows::Forms::Button^ btnAtendidoAlt;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtDescriptionDTI;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdObj;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceUsuarioMO;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceNameMO;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceDateMO;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceTimeMO;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceStatusMO;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceRobotAsignadoObj;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceUsuarioALT;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceRobotAsignadoAlt;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceUsuarioDTI;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn8;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn9;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn10;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceRobotAsignadoDTI;















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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AlertManagementForm::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->pbPhotoObj = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtDescriptionObj = (gcnew System::Windows::Forms::TextBox());
			this->dgvOjbPerdido = (gcnew System::Windows::Forms::DataGridView());
			this->IdObj = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceUsuarioMO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceNameMO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceDateMO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceTimeMO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceStatusMO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceRobotAsignadoObj = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnAtendidoObj = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->txtDescriptionAltercado = (gcnew System::Windows::Forms::TextBox());
			this->pbPhotoAltercado = (gcnew System::Windows::Forms::PictureBox());
			this->dgvAltercado = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceUsuarioALT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceRobotAsignadoAlt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnAtendidoAlt = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtDescriptionDTI = (gcnew System::Windows::Forms::TextBox());
			this->dgvDTI = (gcnew System::Windows::Forms::DataGridView());
			this->ResourceUsuarioDTI = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceRobotAsignadoDTI = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnAtendidoDTI = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhotoObj))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvOjbPerdido))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhotoAltercado))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAltercado))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDTI))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(3, 3);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(752, 537);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label16);
			this->tabPage1->Controls->Add(this->pbPhotoObj);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->txtDescriptionObj);
			this->tabPage1->Controls->Add(this->dgvOjbPerdido);
			this->tabPage1->Controls->Add(this->btnAtendidoObj);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(744, 508);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Objeto perdido";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label16->Location = System::Drawing::Point(518, 10);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(77, 25);
			this->label16->TabIndex = 65;
			this->label16->Text = L"Imagen";
			// 
			// pbPhotoObj
			// 
			this->pbPhotoObj->Location = System::Drawing::Point(523, 38);
			this->pbPhotoObj->Name = L"pbPhotoObj";
			this->pbPhotoObj->Size = System::Drawing::Size(211, 177);
			this->pbPhotoObj->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbPhotoObj->TabIndex = 64;
			this->pbPhotoObj->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label6->Location = System::Drawing::Point(6, 10);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(114, 25);
			this->label6->TabIndex = 63;
			this->label6->Text = L"Descripción";
			// 
			// txtDescriptionObj
			// 
			this->txtDescriptionObj->Location = System::Drawing::Point(6, 38);
			this->txtDescriptionObj->Multiline = true;
			this->txtDescriptionObj->Name = L"txtDescriptionObj";
			this->txtDescriptionObj->Size = System::Drawing::Size(333, 177);
			this->txtDescriptionObj->TabIndex = 62;
			// 
			// dgvOjbPerdido
			// 
			this->dgvOjbPerdido->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvOjbPerdido->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->IdObj,
					this->ResourceUsuarioMO, this->ResourceNameMO, this->ResourceDateMO, this->ResourceTimeMO, this->ResourceStatusMO, this->ResourceRobotAsignadoObj
			});
			this->dgvOjbPerdido->Location = System::Drawing::Point(6, 243);
			this->dgvOjbPerdido->Name = L"dgvOjbPerdido";
			this->dgvOjbPerdido->RowHeadersVisible = false;
			this->dgvOjbPerdido->RowHeadersWidth = 51;
			this->dgvOjbPerdido->RowTemplate->Height = 24;
			this->dgvOjbPerdido->Size = System::Drawing::Size(732, 259);
			this->dgvOjbPerdido->TabIndex = 19;
			this->dgvOjbPerdido->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AlertManagementForm::dgvOjbPerdido_CellClick);
			// 
			// IdObj
			// 
			this->IdObj->HeaderText = L"ID";
			this->IdObj->MinimumWidth = 6;
			this->IdObj->Name = L"IdObj";
			this->IdObj->Width = 50;
			// 
			// ResourceUsuarioMO
			// 
			this->ResourceUsuarioMO->HeaderText = L"Usuario";
			this->ResourceUsuarioMO->MinimumWidth = 6;
			this->ResourceUsuarioMO->Name = L"ResourceUsuarioMO";
			this->ResourceUsuarioMO->Width = 125;
			// 
			// ResourceNameMO
			// 
			this->ResourceNameMO->HeaderText = L"Objeto";
			this->ResourceNameMO->MinimumWidth = 6;
			this->ResourceNameMO->Name = L"ResourceNameMO";
			this->ResourceNameMO->Width = 125;
			// 
			// ResourceDateMO
			// 
			this->ResourceDateMO->HeaderText = L"Fecha";
			this->ResourceDateMO->MinimumWidth = 6;
			this->ResourceDateMO->Name = L"ResourceDateMO";
			this->ResourceDateMO->Width = 125;
			// 
			// ResourceTimeMO
			// 
			this->ResourceTimeMO->HeaderText = L"Hora";
			this->ResourceTimeMO->MinimumWidth = 6;
			this->ResourceTimeMO->Name = L"ResourceTimeMO";
			this->ResourceTimeMO->Width = 125;
			// 
			// ResourceStatusMO
			// 
			this->ResourceStatusMO->HeaderText = L"Estado";
			this->ResourceStatusMO->MinimumWidth = 6;
			this->ResourceStatusMO->Name = L"ResourceStatusMO";
			this->ResourceStatusMO->Width = 125;
			// 
			// ResourceRobotAsignadoObj
			// 
			this->ResourceRobotAsignadoObj->HeaderText = L"Robot Asignado";
			this->ResourceRobotAsignadoObj->MinimumWidth = 6;
			this->ResourceRobotAsignadoObj->Name = L"ResourceRobotAsignadoObj";
			this->ResourceRobotAsignadoObj->Width = 125;
			// 
			// btnAtendidoObj
			// 
			this->btnAtendidoObj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnAtendidoObj->Location = System::Drawing::Point(345, 98);
			this->btnAtendidoObj->Name = L"btnAtendidoObj";
			this->btnAtendidoObj->Size = System::Drawing::Size(172, 68);
			this->btnAtendidoObj->TabIndex = 2;
			this->btnAtendidoObj->Text = L"Marcar atendido";
			this->btnAtendidoObj->UseVisualStyleBackColor = true;
			this->btnAtendidoObj->Click += gcnew System::EventHandler(this, &AlertManagementForm::btnAtendidoObj_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->label17);
			this->tabPage2->Controls->Add(this->txtDescriptionAltercado);
			this->tabPage2->Controls->Add(this->pbPhotoAltercado);
			this->tabPage2->Controls->Add(this->dgvAltercado);
			this->tabPage2->Controls->Add(this->btnAtendidoAlt);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(744, 508);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Altercado";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(511, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 25);
			this->label2->TabIndex = 58;
			this->label2->Text = L"Imagen";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label17->Location = System::Drawing::Point(17, 101);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(114, 25);
			this->label17->TabIndex = 57;
			this->label17->Text = L"Descripción";
			// 
			// txtDescriptionAltercado
			// 
			this->txtDescriptionAltercado->Location = System::Drawing::Point(9, 129);
			this->txtDescriptionAltercado->Multiline = true;
			this->txtDescriptionAltercado->Name = L"txtDescriptionAltercado";
			this->txtDescriptionAltercado->Size = System::Drawing::Size(465, 117);
			this->txtDescriptionAltercado->TabIndex = 56;
			// 
			// pbPhotoAltercado
			// 
			this->pbPhotoAltercado->Location = System::Drawing::Point(516, 52);
			this->pbPhotoAltercado->Name = L"pbPhotoAltercado";
			this->pbPhotoAltercado->Size = System::Drawing::Size(211, 177);
			this->pbPhotoAltercado->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbPhotoAltercado->TabIndex = 55;
			this->pbPhotoAltercado->TabStop = false;
			// 
			// dgvAltercado
			// 
			this->dgvAltercado->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvAltercado->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column1,
					this->ResourceUsuarioALT, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5,
					this->ResourceRobotAsignadoAlt
			});
			this->dgvAltercado->Location = System::Drawing::Point(9, 252);
			this->dgvAltercado->Name = L"dgvAltercado";
			this->dgvAltercado->RowHeadersVisible = false;
			this->dgvAltercado->RowHeadersWidth = 51;
			this->dgvAltercado->RowTemplate->Height = 24;
			this->dgvAltercado->Size = System::Drawing::Size(729, 250);
			this->dgvAltercado->TabIndex = 35;
			this->dgvAltercado->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AlertManagementForm::dgvAltercado_CellClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 125;
			// 
			// ResourceUsuarioALT
			// 
			this->ResourceUsuarioALT->HeaderText = L"Usuario";
			this->ResourceUsuarioALT->MinimumWidth = 6;
			this->ResourceUsuarioALT->Name = L"ResourceUsuarioALT";
			this->ResourceUsuarioALT->Width = 125;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->DataPropertyName = L"ResourceDateALT";
			this->dataGridViewTextBoxColumn3->HeaderText = L"Fecha";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 125;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->DataPropertyName = L"ResourceTimeALT";
			this->dataGridViewTextBoxColumn4->HeaderText = L"Hora";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->Width = 125;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->DataPropertyName = L"ResourceStatusALT";
			this->dataGridViewTextBoxColumn5->HeaderText = L"Estado";
			this->dataGridViewTextBoxColumn5->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->Width = 125;
			// 
			// ResourceRobotAsignadoAlt
			// 
			this->ResourceRobotAsignadoAlt->HeaderText = L"Robot Asignado";
			this->ResourceRobotAsignadoAlt->MinimumWidth = 6;
			this->ResourceRobotAsignadoAlt->Name = L"ResourceRobotAsignadoAlt";
			this->ResourceRobotAsignadoAlt->Width = 125;
			// 
			// btnAtendidoAlt
			// 
			this->btnAtendidoAlt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnAtendidoAlt->Location = System::Drawing::Point(108, 21);
			this->btnAtendidoAlt->Name = L"btnAtendidoAlt";
			this->btnAtendidoAlt->Size = System::Drawing::Size(174, 63);
			this->btnAtendidoAlt->TabIndex = 5;
			this->btnAtendidoAlt->Text = L"Marcar atendido";
			this->btnAtendidoAlt->UseVisualStyleBackColor = true;
			this->btnAtendidoAlt->Click += gcnew System::EventHandler(this, &AlertManagementForm::btnAtendidoAlt_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label1);
			this->tabPage3->Controls->Add(this->txtDescriptionDTI);
			this->tabPage3->Controls->Add(this->dgvDTI);
			this->tabPage3->Controls->Add(this->btnAtendidoDTI);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(744, 508);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Reporte DTI";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(3, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 25);
			this->label1->TabIndex = 64;
			this->label1->Text = L"Descripción";
			// 
			// txtDescriptionDTI
			// 
			this->txtDescriptionDTI->Location = System::Drawing::Point(3, 62);
			this->txtDescriptionDTI->Multiline = true;
			this->txtDescriptionDTI->Name = L"txtDescriptionDTI";
			this->txtDescriptionDTI->Size = System::Drawing::Size(374, 170);
			this->txtDescriptionDTI->TabIndex = 63;
			// 
			// dgvDTI
			// 
			this->dgvDTI->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvDTI->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->ResourceUsuarioDTI,
					this->Column2, this->dataGridViewTextBoxColumn7, this->dataGridViewTextBoxColumn8, this->dataGridViewTextBoxColumn9, this->dataGridViewTextBoxColumn10,
					this->ResourceRobotAsignadoDTI
			});
			this->dgvDTI->Location = System::Drawing::Point(3, 238);
			this->dgvDTI->Name = L"dgvDTI";
			this->dgvDTI->RowHeadersVisible = false;
			this->dgvDTI->RowHeadersWidth = 51;
			this->dgvDTI->RowTemplate->Height = 24;
			this->dgvDTI->Size = System::Drawing::Size(735, 267);
			this->dgvDTI->TabIndex = 35;
			this->dgvDTI->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AlertManagementForm::dgvDTI_CellClick);
			// 
			// ResourceUsuarioDTI
			// 
			this->ResourceUsuarioDTI->HeaderText = L"Usuario";
			this->ResourceUsuarioDTI->MinimumWidth = 6;
			this->ResourceUsuarioDTI->Name = L"ResourceUsuarioDTI";
			this->ResourceUsuarioDTI->Width = 125;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"ID";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 125;
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->DataPropertyName = L"ResourceAlertTypeDTI";
			this->dataGridViewTextBoxColumn7->HeaderText = L"Tipo de alerta";
			this->dataGridViewTextBoxColumn7->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			this->dataGridViewTextBoxColumn7->Width = 125;
			// 
			// dataGridViewTextBoxColumn8
			// 
			this->dataGridViewTextBoxColumn8->DataPropertyName = L"ResourceDateDTI";
			this->dataGridViewTextBoxColumn8->HeaderText = L"Fecha";
			this->dataGridViewTextBoxColumn8->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
			this->dataGridViewTextBoxColumn8->Width = 125;
			// 
			// dataGridViewTextBoxColumn9
			// 
			this->dataGridViewTextBoxColumn9->DataPropertyName = L"ResourceTimeDTI";
			this->dataGridViewTextBoxColumn9->HeaderText = L"Hora";
			this->dataGridViewTextBoxColumn9->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
			this->dataGridViewTextBoxColumn9->Width = 125;
			// 
			// dataGridViewTextBoxColumn10
			// 
			this->dataGridViewTextBoxColumn10->DataPropertyName = L"ResourceStatusDTI";
			this->dataGridViewTextBoxColumn10->HeaderText = L"Estado";
			this->dataGridViewTextBoxColumn10->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn10->Name = L"dataGridViewTextBoxColumn10";
			this->dataGridViewTextBoxColumn10->Width = 125;
			// 
			// ResourceRobotAsignadoDTI
			// 
			this->ResourceRobotAsignadoDTI->HeaderText = L"Robot Asignado";
			this->ResourceRobotAsignadoDTI->MinimumWidth = 6;
			this->ResourceRobotAsignadoDTI->Name = L"ResourceRobotAsignadoDTI";
			this->ResourceRobotAsignadoDTI->Width = 125;
			// 
			// btnAtendidoDTI
			// 
			this->btnAtendidoDTI->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnAtendidoDTI->Location = System::Drawing::Point(484, 104);
			this->btnAtendidoDTI->Name = L"btnAtendidoDTI";
			this->btnAtendidoDTI->Size = System::Drawing::Size(174, 74);
			this->btnAtendidoDTI->TabIndex = 8;
			this->btnAtendidoDTI->Text = L"Marcar atendido";
			this->btnAtendidoDTI->UseVisualStyleBackColor = true;
			this->btnAtendidoDTI->Click += gcnew System::EventHandler(this, &AlertManagementForm::btnAtendidoDTI_Click);
			// 
			// AlertManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(757, 545);
			this->Controls->Add(this->tabControl1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AlertManagementForm";
			this->Text = L"AlertManagementForm";
			this->Load += gcnew System::EventHandler(this, &AlertManagementForm::AlertManagementForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhotoObj))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvOjbPerdido))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhotoAltercado))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAltercado))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDTI))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void CargarTablaObjetoPerdido() {
		List<ObjPerdido^>^ objeto = Service::ShowObjetosPerdidos();
		if (objeto != nullptr) {
			dgvOjbPerdido->Rows->Clear();
			for (int i = 0; i < objeto->Count; i++) {
				String^ fecha = objeto[i]->Fecha->ToString("dd/MM/yyyy");
				String^ hora = objeto[i]->Fecha->ToString("HH:mm:ss");
				String^ estado = objeto[i]->Solucionado ? "Solucionado" : "No solucionado";
				String^ usuario = objeto[i]->UsuarioNombre;

				String^ robotAsignado = "Ninguno";
				List<Robot^>^ robots = Service::GetRobots();
				for each (Robot ^ robot in robots) {
					if (robot->AlertaAsignadaID == objeto[i]->id) {
						robotAsignado = robot->Nombre + " (ID: " + robot->ID + ")";
						break;
					}
				}

				if (objeto[i]->GetType() == ObjPerdido::typeid) {
					dgvOjbPerdido->Rows->Add(gcnew array<String^>{
						"" + objeto[i]->id,
							usuario,
							objeto[i]->ObjetoEncontrado,
							fecha,
							hora,
							estado,
							robotAsignado

					});
				}
			}
		}
	}
	private: void CargarTablaAltercado() {
		List<Altercado^>^ altercado = Service::ShowAltercados();
		if (altercado != nullptr) {
			dgvAltercado->Rows->Clear();
			for (int i = 0; i < altercado->Count; i++) {
				String^ fecha = altercado[i]->Fecha->ToString("dd/MM/yyyy");
				String^ hora = altercado[i]->Fecha->ToString("HH:mm:ss");
				String^ estado = altercado[i]->Solucionado ? "Solucionado" : "No solucionado";
				String^ usuario = altercado[i]->UsuarioNombre;

				String^ robotAsignado = "Ninguno";
				List<Robot^>^ robots = Service::GetRobots();
				for each (Robot ^ robot in robots) {
					if (robot->AlertaAsignadaID == altercado[i]->id) {
						robotAsignado = robot->Nombre + " (ID: " + robot->ID + ")";
						break;
					}
				}

				if (altercado[i]->GetType() == Altercado::typeid) {
					dgvAltercado->Rows->Add(gcnew array<String^>{
						"" + altercado[i]->id,
							usuario,
							fecha,
							hora,
							estado,
							robotAsignado
					});
				}
			}
		}
	}
	private: void CargarTablaDTIReport() {
		List<DTIReport^>^ reporte = Service::ShowDTIReport();
		if (reporte != nullptr) {
			dgvDTI->Rows->Clear();
			for (int i = 0; i < reporte->Count; i++) {
				String^ fecha = reporte[i]->Fecha->ToString("dd/MM/yyyy");
				String^ hora = reporte[i]->Fecha->ToString("HH:mm:ss");
				String^ estado = reporte[i]->Solucionado ? "Solucionado" : "No solucionado";
				String^ usuario = reporte[i]->UsuarioNombre;

				String^ robotAsignado = "Ninguno";
				List<Robot^>^ robots = Service::GetRobots();
				for each (Robot ^ robot in robots) {
					if (robot->AlertaAsignadaID == reporte[i]->id) {
						robotAsignado = robot->Nombre + " (ID: " + robot->ID + ")";
						break;
					}
				}

				if (reporte[i]->GetType() == DTIReport::typeid) {
					dgvDTI->Rows->Add(gcnew array<String^>{
						"" + reporte[i]->id,
							usuario,
							reporte[i]->tipoReporte,
							fecha,
							hora,
							estado,
							robotAsignado
					});
				}
			}
		}
	}
	private: void CargarRobots(Alert^ alerta) {
		String^ robotAsignado = "Ninguno";
		List<Robot^>^ robots = Service::GetRobots();
		for each (Robot ^ robot in robots)
		{
			if (robot->AlertaAsignadaID == alerta->id)
			{
				robotAsignado = robot->Nombre + " (ID: " + robot->ID + ")";
				break;
			}
		}
	}
	private: void ClearFields() {
		txtDescriptionObj->Clear();
		txtDescriptionAltercado->Clear();
		txtDescriptionDTI->Clear();
		if (pbPhotoObj != nullptr) {
			pbPhotoObj->Image = nullptr;
			pbPhotoObj->Invalidate();
		}
		if (pbPhotoAltercado != nullptr) {
			pbPhotoAltercado->Image = nullptr;
			pbPhotoAltercado->Invalidate();
		}
	}
	private: System::Void AlertManagementForm_Load(System::Object^ sender, System::EventArgs^ e) {
		CargarTablaObjetoPerdido();
		CargarTablaAltercado();
		CargarTablaDTIReport();

		InitializateTimer();
		StartTimer();

		txtDescriptionAltercado->Enabled = false;
		txtDescriptionDTI->Enabled = false;
		txtDescriptionObj->Enabled = false;
	}
	private: System::Void dgvOjbPerdido_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			int objetoID = Int32::Parse(dgvOjbPerdido->Rows[dgvOjbPerdido->SelectedCells[0]->RowIndex]->Cells[0]->Value->ToString());
			ObjPerdido^ objeto = Service::buscarObjetoPerdido(objetoID);
			if (objeto != nullptr) {
				txtDescriptionObj->Text = objeto->Description;
				if (objeto->Photo != nullptr) {
					System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(objeto->Photo);
					pbPhotoObj->Image = Image::FromStream(ms);
				}
				else {
					pbPhotoObj->Image = nullptr;
					pbPhotoObj->Invalidate();
				}
			}

		}
	}
	private: System::Void btnAtendidoObj_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrEmpty(txtDescriptionObj->Text)) {
			MessageBox::Show("Por favor seleccione una alerta", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		try {
			String^ descrip = txtDescriptionObj->Text;
			Alert^ alertaEncontrada = Service::buscarAlertaDescrip(descrip);
			if (alertaEncontrada != nullptr) {
				alertaEncontrada->Solucionado = true;
				int alertaModificada = Service::modificarAlerta(alertaEncontrada);
				if (alertaModificada != 0) {
					CargarTablaObjetoPerdido();
					ClearFields();
					MessageBox::Show("Alert solucionada", "Exito", MessageBoxButtons::OK);
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al solucionar alerta: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnAtendidoAlt_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrEmpty(txtDescriptionAltercado->Text)) {
			MessageBox::Show("Por favor seleccione una alerta", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		try {
			String^ descrip = txtDescriptionAltercado->Text;
			Alert^ alertaEncontrada = Service::buscarAlertaDescrip(descrip);
			if (alertaEncontrada != nullptr) {
				alertaEncontrada->Solucionado = true;
				int alertaModificada = Service::modificarAlerta(alertaEncontrada);
				if (alertaModificada != 0) {
					CargarTablaAltercado();
					ClearFields();
					MessageBox::Show("Alert solucionada", "Exito", MessageBoxButtons::OK);
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al solucionar alerta: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnAtendidoDTI_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrEmpty(txtDescriptionDTI->Text)) {
			MessageBox::Show("Por favor seleccione una alerta", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		try {
			String^ descrip = txtDescriptionDTI->Text;
			Alert^ alertaEncontrada = Service::buscarAlertaDescrip(descrip);
			if (alertaEncontrada != nullptr) {
				alertaEncontrada->Solucionado = true;
				int alertaModificada = Service::modificarAlerta(alertaEncontrada);
				if (alertaModificada != 0) {
					CargarTablaDTIReport();
					ClearFields();
					MessageBox::Show("Alert solucionada", "Exito", MessageBoxButtons::OK);
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al solucionar alerta: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void dgvAltercado_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int id = Int32::Parse(dgvAltercado->Rows[dgvAltercado->SelectedCells[0]->RowIndex]->Cells[0]->Value->ToString());
		Altercado^ altercado = Service::buscarAltercado(id);
		if (altercado != nullptr) {
			txtDescriptionAltercado->Text = altercado->Description;
			if (altercado->Photo != nullptr) {
				System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(altercado->Photo);
				pbPhotoAltercado->Image = Image::FromStream(ms);
			}
			else {
				pbPhotoAltercado->Image = nullptr;
				pbPhotoAltercado->Invalidate();
			}
		}
	}
	private: System::Void dgvDTI_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int id = Int32::Parse(dgvDTI->Rows[dgvDTI->SelectedCells[0]->RowIndex]->Cells[0]->Value->ToString());
		DTIReport^ reporte = Service::buscarDTIReport(id);
		if (reporte != nullptr) {
			txtDescriptionDTI->Text = reporte->Description;
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

			timer = gcnew Thread(gcnew ThreadStart(this, &AlertManagementForm::TimerMethod));
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
					this->BeginInvoke(gcnew UpdateDataDelegate(this, &AlertManagementForm::RefreshData));
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

			CargarTablaObjetoPerdido();
			CargarTablaAltercado();
			CargarTablaDTIReport();

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
	};
}
