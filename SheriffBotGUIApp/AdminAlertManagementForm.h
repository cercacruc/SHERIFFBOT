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
	/// Resumen de AdminAlertManagementForm
	/// </summary>
	public ref class AdminAlertManagementForm : public System::Windows::Forms::Form
	{
	public:
		AdminAlertManagementForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~AdminAlertManagementForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage2;



	private: System::Windows::Forms::Label^ label8;



	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txtObjetoPerdido;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ txtIDObjPerdido;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ btnSolucionObj;
	private: System::Windows::Forms::DataGridView^ dgvOjbPerdido;































	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceAlertDMO;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceNameMO;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceDateMO;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceTimeMO;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceStatusMO;
	private: System::Windows::Forms::TabPage^ tabPage1;





	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtIDAltercado;



	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DataGridView^ dgvAltercado;















	private: System::Windows::Forms::Label^ label13;

	private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::TextBox^ txtIDDTI;

	private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::DataGridView^ dgvDTI;





	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn10;
private: System::Windows::Forms::PictureBox^ pbPhotoObj;

private: System::Windows::Forms::DateTimePicker^ dtpObjetoPerdido;


private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::GroupBox^ groupBox1;
private: System::Windows::Forms::RadioButton^ rbtnSolucionObNo;

private: System::Windows::Forms::RadioButton^ rbtnSolucionObjYes;

private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::TextBox^ txtDescriptionObj;

private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::TextBox^ txtDescriptionAltercado;
private: System::Windows::Forms::PictureBox^ pbPhotoAltercado;


private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
private: System::Windows::Forms::Button^ btnSolucionAltercado;

private: System::Windows::Forms::GroupBox^ groupBox2;
private: System::Windows::Forms::RadioButton^ rbtnSolucionAltercadoNo;

private: System::Windows::Forms::RadioButton^ rbtnSolucionAltercadoYes;

private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::TextBox^ txtDescriptionDTI;

private: System::Windows::Forms::Button^ btnSolucionDTI;

private: System::Windows::Forms::GroupBox^ groupBox3;
private: System::Windows::Forms::RadioButton^ radioButton3;
private: System::Windows::Forms::RadioButton^ radioButton4;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::DateTimePicker^ dtpDTI;

private: System::Windows::Forms::ComboBox^ cmbTipoAlertaDTI;
private: System::Windows::Forms::Button^ btnEliminarObjPerd;
private: System::Windows::Forms::Button^ btnEliminarAltercado;
private: System::Windows::Forms::Button^ btnEliminarDTI;


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rbtnSolucionObNo = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnSolucionObjYes = (gcnew System::Windows::Forms::RadioButton());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtDescriptionObj = (gcnew System::Windows::Forms::TextBox());
			this->dtpObjetoPerdido = (gcnew System::Windows::Forms::DateTimePicker());
			this->pbPhotoObj = (gcnew System::Windows::Forms::PictureBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtObjetoPerdido = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->txtIDObjPerdido = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->btnSolucionObj = (gcnew System::Windows::Forms::Button());
			this->dgvOjbPerdido = (gcnew System::Windows::Forms::DataGridView());
			this->ResourceAlertDMO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceNameMO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceDateMO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceTimeMO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceStatusMO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->btnSolucionAltercado = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->rbtnSolucionAltercadoNo = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnSolucionAltercadoYes = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->txtDescriptionAltercado = (gcnew System::Windows::Forms::TextBox());
			this->pbPhotoAltercado = (gcnew System::Windows::Forms::PictureBox());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtIDAltercado = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dgvAltercado = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtDescriptionDTI = (gcnew System::Windows::Forms::TextBox());
			this->btnSolucionDTI = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dtpDTI = (gcnew System::Windows::Forms::DateTimePicker());
			this->cmbTipoAlertaDTI = (gcnew System::Windows::Forms::ComboBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->txtIDDTI = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->dgvDTI = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnEliminarDTI = (gcnew System::Windows::Forms::Button());
			this->btnEliminarAltercado = (gcnew System::Windows::Forms::Button());
			this->btnEliminarObjPerd = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhotoObj))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvOjbPerdido))->BeginInit();
			this->tabPage1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhotoAltercado))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAltercado))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDTI))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(2, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(924, 543);
			this->tabControl1->TabIndex = 2;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->btnEliminarObjPerd);
			this->tabPage2->Controls->Add(this->label16);
			this->tabPage2->Controls->Add(this->groupBox1);
			this->tabPage2->Controls->Add(this->label9);
			this->tabPage2->Controls->Add(this->txtDescriptionObj);
			this->tabPage2->Controls->Add(this->dtpObjetoPerdido);
			this->tabPage2->Controls->Add(this->pbPhotoObj);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->label10);
			this->tabPage2->Controls->Add(this->txtObjetoPerdido);
			this->tabPage2->Controls->Add(this->label11);
			this->tabPage2->Controls->Add(this->txtIDObjPerdido);
			this->tabPage2->Controls->Add(this->label12);
			this->tabPage2->Controls->Add(this->btnSolucionObj);
			this->tabPage2->Controls->Add(this->dgvOjbPerdido);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Size = System::Drawing::Size(916, 514);
			this->tabPage2->TabIndex = 0;
			this->tabPage2->Text = L"Administrar Objeto Perdido";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label16->Location = System::Drawing::Point(665, 14);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(77, 25);
			this->label16->TabIndex = 39;
			this->label16->Text = L"Imagen";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rbtnSolucionObNo);
			this->groupBox1->Controls->Add(this->rbtnSolucionObjYes);
			this->groupBox1->Location = System::Drawing::Point(152, 128);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(133, 46);
			this->groupBox1->TabIndex = 38;
			this->groupBox1->TabStop = false;
			// 
			// rbtnSolucionObNo
			// 
			this->rbtnSolucionObNo->AutoSize = true;
			this->rbtnSolucionObNo->Location = System::Drawing::Point(68, 20);
			this->rbtnSolucionObNo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->rbtnSolucionObNo->Name = L"rbtnSolucionObNo";
			this->rbtnSolucionObNo->Size = System::Drawing::Size(46, 20);
			this->rbtnSolucionObNo->TabIndex = 1;
			this->rbtnSolucionObNo->Text = L"No";
			this->rbtnSolucionObNo->UseVisualStyleBackColor = true;
			// 
			// rbtnSolucionObjYes
			// 
			this->rbtnSolucionObjYes->AutoSize = true;
			this->rbtnSolucionObjYes->Checked = true;
			this->rbtnSolucionObjYes->Location = System::Drawing::Point(12, 20);
			this->rbtnSolucionObjYes->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->rbtnSolucionObjYes->Name = L"rbtnSolucionObjYes";
			this->rbtnSolucionObjYes->Size = System::Drawing::Size(40, 20);
			this->rbtnSolucionObjYes->TabIndex = 0;
			this->rbtnSolucionObjYes->TabStop = true;
			this->rbtnSolucionObjYes->Text = L"S�";
			this->rbtnSolucionObjYes->UseVisualStyleBackColor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label9->Location = System::Drawing::Point(406, 14);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(114, 25);
			this->label9->TabIndex = 37;
			this->label9->Text = L"Descripci�n";
			// 
			// txtDescriptionObj
			// 
			this->txtDescriptionObj->Location = System::Drawing::Point(411, 49);
			this->txtDescriptionObj->Multiline = true;
			this->txtDescriptionObj->Name = L"txtDescriptionObj";
			this->txtDescriptionObj->Size = System::Drawing::Size(226, 177);
			this->txtDescriptionObj->TabIndex = 36;
			// 
			// dtpObjetoPerdido
			// 
			this->dtpObjetoPerdido->Location = System::Drawing::Point(152, 101);
			this->dtpObjetoPerdido->Name = L"dtpObjetoPerdido";
			this->dtpObjetoPerdido->Size = System::Drawing::Size(213, 22);
			this->dtpObjetoPerdido->TabIndex = 35;
			// 
			// pbPhotoObj
			// 
			this->pbPhotoObj->Location = System::Drawing::Point(670, 49);
			this->pbPhotoObj->Name = L"pbPhotoObj";
			this->pbPhotoObj->Size = System::Drawing::Size(211, 177);
			this->pbPhotoObj->TabIndex = 34;
			this->pbPhotoObj->TabStop = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label8->Location = System::Drawing::Point(15, 140);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(121, 25);
			this->label8->TabIndex = 32;
			this->label8->Text = L"Solucionado";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label10->Location = System::Drawing::Point(15, 98);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(67, 25);
			this->label10->TabIndex = 28;
			this->label10->Text = L"Fecha";
			// 
			// txtObjetoPerdido
			// 
			this->txtObjetoPerdido->Location = System::Drawing::Point(152, 62);
			this->txtObjetoPerdido->Name = L"txtObjetoPerdido";
			this->txtObjetoPerdido->Size = System::Drawing::Size(213, 22);
			this->txtObjetoPerdido->TabIndex = 27;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label11->Location = System::Drawing::Point(15, 58);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(70, 25);
			this->label11->TabIndex = 26;
			this->label11->Text = L"Objeto";
			// 
			// txtIDObjPerdido
			// 
			this->txtIDObjPerdido->Location = System::Drawing::Point(152, 18);
			this->txtIDObjPerdido->Name = L"txtIDObjPerdido";
			this->txtIDObjPerdido->Size = System::Drawing::Size(213, 22);
			this->txtIDObjPerdido->TabIndex = 25;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label12->Location = System::Drawing::Point(15, 14);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(87, 25);
			this->label12->TabIndex = 24;
			this->label12->Text = L"ID Alerta";
			// 
			// btnSolucionObj
			// 
			this->btnSolucionObj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnSolucionObj->Location = System::Drawing::Point(202, 179);
			this->btnSolucionObj->Name = L"btnSolucionObj";
			this->btnSolucionObj->Size = System::Drawing::Size(163, 49);
			this->btnSolucionObj->TabIndex = 22;
			this->btnSolucionObj->Text = L"Solucionado";
			this->btnSolucionObj->UseVisualStyleBackColor = true;
			// 
			// dgvOjbPerdido
			// 
			this->dgvOjbPerdido->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvOjbPerdido->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->ResourceAlertDMO,
					this->ResourceNameMO, this->ResourceDateMO, this->ResourceTimeMO, this->ResourceStatusMO
			});
			this->dgvOjbPerdido->Location = System::Drawing::Point(20, 266);
			this->dgvOjbPerdido->Name = L"dgvOjbPerdido";
			this->dgvOjbPerdido->RowHeadersVisible = false;
			this->dgvOjbPerdido->RowHeadersWidth = 51;
			this->dgvOjbPerdido->RowTemplate->Height = 24;
			this->dgvOjbPerdido->Size = System::Drawing::Size(882, 222);
			this->dgvOjbPerdido->TabIndex = 18;
			// 
			// ResourceAlertDMO
			// 
			this->ResourceAlertDMO->HeaderText = L"ID Alerta";
			this->ResourceAlertDMO->MinimumWidth = 6;
			this->ResourceAlertDMO->Name = L"ResourceAlertDMO";
			this->ResourceAlertDMO->Width = 125;
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
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->btnEliminarAltercado);
			this->tabPage1->Controls->Add(this->btnSolucionAltercado);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label17);
			this->tabPage1->Controls->Add(this->txtDescriptionAltercado);
			this->tabPage1->Controls->Add(this->pbPhotoAltercado);
			this->tabPage1->Controls->Add(this->dateTimePicker2);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->txtIDAltercado);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->dgvAltercado);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Size = System::Drawing::Size(916, 514);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Administrar Altercado";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// btnSolucionAltercado
			// 
			this->btnSolucionAltercado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnSolucionAltercado->Location = System::Drawing::Point(224, 179);
			this->btnSolucionAltercado->Name = L"btnSolucionAltercado";
			this->btnSolucionAltercado->Size = System::Drawing::Size(177, 49);
			this->btnSolucionAltercado->TabIndex = 57;
			this->btnSolucionAltercado->Text = L"Solucionado";
			this->btnSolucionAltercado->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->rbtnSolucionAltercadoNo);
			this->groupBox2->Controls->Add(this->rbtnSolucionAltercadoYes);
			this->groupBox2->Location = System::Drawing::Point(153, 101);
			this->groupBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Size = System::Drawing::Size(133, 46);
			this->groupBox2->TabIndex = 56;
			this->groupBox2->TabStop = false;
			// 
			// rbtnSolucionAltercadoNo
			// 
			this->rbtnSolucionAltercadoNo->AutoSize = true;
			this->rbtnSolucionAltercadoNo->Location = System::Drawing::Point(68, 20);
			this->rbtnSolucionAltercadoNo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->rbtnSolucionAltercadoNo->Name = L"rbtnSolucionAltercadoNo";
			this->rbtnSolucionAltercadoNo->Size = System::Drawing::Size(46, 20);
			this->rbtnSolucionAltercadoNo->TabIndex = 1;
			this->rbtnSolucionAltercadoNo->Text = L"No";
			this->rbtnSolucionAltercadoNo->UseVisualStyleBackColor = true;
			// 
			// rbtnSolucionAltercadoYes
			// 
			this->rbtnSolucionAltercadoYes->AutoSize = true;
			this->rbtnSolucionAltercadoYes->Checked = true;
			this->rbtnSolucionAltercadoYes->Location = System::Drawing::Point(12, 20);
			this->rbtnSolucionAltercadoYes->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->rbtnSolucionAltercadoYes->Name = L"rbtnSolucionAltercadoYes";
			this->rbtnSolucionAltercadoYes->Size = System::Drawing::Size(40, 20);
			this->rbtnSolucionAltercadoYes->TabIndex = 0;
			this->rbtnSolucionAltercadoYes->TabStop = true;
			this->rbtnSolucionAltercadoYes->Text = L"S�";
			this->rbtnSolucionAltercadoYes->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(16, 113);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 25);
			this->label1->TabIndex = 55;
			this->label1->Text = L"Solucionado";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(685, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 25);
			this->label2->TabIndex = 54;
			this->label2->Text = L"Imagen";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label17->Location = System::Drawing::Point(426, 16);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(114, 25);
			this->label17->TabIndex = 53;
			this->label17->Text = L"Descripci�n";
			// 
			// txtDescriptionAltercado
			// 
			this->txtDescriptionAltercado->Location = System::Drawing::Point(431, 51);
			this->txtDescriptionAltercado->Multiline = true;
			this->txtDescriptionAltercado->Name = L"txtDescriptionAltercado";
			this->txtDescriptionAltercado->Size = System::Drawing::Size(226, 177);
			this->txtDescriptionAltercado->TabIndex = 52;
			// 
			// pbPhotoAltercado
			// 
			this->pbPhotoAltercado->Location = System::Drawing::Point(690, 51);
			this->pbPhotoAltercado->Name = L"pbPhotoAltercado";
			this->pbPhotoAltercado->Size = System::Drawing::Size(211, 177);
			this->pbPhotoAltercado->TabIndex = 51;
			this->pbPhotoAltercado->TabStop = false;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(188, 63);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(213, 22);
			this->dateTimePicker2->TabIndex = 50;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->Location = System::Drawing::Point(16, 60);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 25);
			this->label3->TabIndex = 43;
			this->label3->Text = L"Fecha";
			// 
			// txtIDAltercado
			// 
			this->txtIDAltercado->Location = System::Drawing::Point(188, 19);
			this->txtIDAltercado->Name = L"txtIDAltercado";
			this->txtIDAltercado->Size = System::Drawing::Size(213, 22);
			this->txtIDAltercado->TabIndex = 40;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->Location = System::Drawing::Point(16, 15);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(87, 25);
			this->label5->TabIndex = 39;
			this->label5->Text = L"ID Alerta";
			// 
			// dgvAltercado
			// 
			this->dgvAltercado->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvAltercado->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5
			});
			this->dgvAltercado->Location = System::Drawing::Point(21, 267);
			this->dgvAltercado->Name = L"dgvAltercado";
			this->dgvAltercado->RowHeadersVisible = false;
			this->dgvAltercado->RowHeadersWidth = 51;
			this->dgvAltercado->RowTemplate->Height = 24;
			this->dgvAltercado->Size = System::Drawing::Size(884, 222);
			this->dgvAltercado->TabIndex = 34;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->DataPropertyName = L"ResourceAlertIDALT";
			this->dataGridViewTextBoxColumn1->HeaderText = L"ID Alerta";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 125;
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
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->btnEliminarDTI);
			this->tabPage3->Controls->Add(this->label6);
			this->tabPage3->Controls->Add(this->txtDescriptionDTI);
			this->tabPage3->Controls->Add(this->btnSolucionDTI);
			this->tabPage3->Controls->Add(this->groupBox3);
			this->tabPage3->Controls->Add(this->label4);
			this->tabPage3->Controls->Add(this->dtpDTI);
			this->tabPage3->Controls->Add(this->cmbTipoAlertaDTI);
			this->tabPage3->Controls->Add(this->label13);
			this->tabPage3->Controls->Add(this->label14);
			this->tabPage3->Controls->Add(this->txtIDDTI);
			this->tabPage3->Controls->Add(this->label15);
			this->tabPage3->Controls->Add(this->dgvDTI);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(916, 514);
			this->tabPage3->TabIndex = 1;
			this->tabPage3->Text = L"Administrar Reporte DTI";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label6->Location = System::Drawing::Point(410, 11);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(114, 25);
			this->label6->TabIndex = 62;
			this->label6->Text = L"Descripci�n";
			// 
			// txtDescriptionDTI
			// 
			this->txtDescriptionDTI->Location = System::Drawing::Point(415, 46);
			this->txtDescriptionDTI->Multiline = true;
			this->txtDescriptionDTI->Name = L"txtDescriptionDTI";
			this->txtDescriptionDTI->Size = System::Drawing::Size(471, 177);
			this->txtDescriptionDTI->TabIndex = 61;
			// 
			// btnSolucionDTI
			// 
			this->btnSolucionDTI->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnSolucionDTI->Location = System::Drawing::Point(203, 205);
			this->btnSolucionDTI->Name = L"btnSolucionDTI";
			this->btnSolucionDTI->Size = System::Drawing::Size(177, 49);
			this->btnSolucionDTI->TabIndex = 60;
			this->btnSolucionDTI->Text = L"Solucionado";
			this->btnSolucionDTI->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->radioButton3);
			this->groupBox3->Controls->Add(this->radioButton4);
			this->groupBox3->Location = System::Drawing::Point(153, 143);
			this->groupBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox3->Size = System::Drawing::Size(133, 46);
			this->groupBox3->TabIndex = 59;
			this->groupBox3->TabStop = false;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(68, 20);
			this->radioButton3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(46, 20);
			this->radioButton3->TabIndex = 1;
			this->radioButton3->Text = L"No";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Checked = true;
			this->radioButton4->Location = System::Drawing::Point(12, 20);
			this->radioButton4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(40, 20);
			this->radioButton4->TabIndex = 0;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"S�";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->Location = System::Drawing::Point(16, 155);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(121, 25);
			this->label4->TabIndex = 58;
			this->label4->Text = L"Solucionado";
			// 
			// dtpDTI
			// 
			this->dtpDTI->Location = System::Drawing::Point(167, 104);
			this->dtpDTI->Name = L"dtpDTI";
			this->dtpDTI->Size = System::Drawing::Size(213, 22);
			this->dtpDTI->TabIndex = 51;
			// 
			// cmbTipoAlertaDTI
			// 
			this->cmbTipoAlertaDTI->FormattingEnabled = true;
			this->cmbTipoAlertaDTI->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Necesidades tecnologicas", L"Prestamo de dispositivo",
					L"Proteccion contra ciberdelincuencia", L"Autenticaci�n y acceso a aplicaciones y datos PUCP"
			});
			this->cmbTipoAlertaDTI->Location = System::Drawing::Point(167, 55);
			this->cmbTipoAlertaDTI->Name = L"cmbTipoAlertaDTI";
			this->cmbTipoAlertaDTI->Size = System::Drawing::Size(213, 24);
			this->cmbTipoAlertaDTI->TabIndex = 44;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label13->Location = System::Drawing::Point(16, 102);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(67, 25);
			this->label13->TabIndex = 43;
			this->label13->Text = L"Fecha";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label14->Location = System::Drawing::Point(16, 55);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(131, 25);
			this->label14->TabIndex = 41;
			this->label14->Text = L"Tipo de alerta";
			// 
			// txtIDDTI
			// 
			this->txtIDDTI->Location = System::Drawing::Point(167, 14);
			this->txtIDDTI->Name = L"txtIDDTI";
			this->txtIDDTI->Size = System::Drawing::Size(213, 22);
			this->txtIDDTI->TabIndex = 40;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label15->Location = System::Drawing::Point(16, 10);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(87, 25);
			this->label15->TabIndex = 39;
			this->label15->Text = L"ID Alerta";
			// 
			// dgvDTI
			// 
			this->dgvDTI->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvDTI->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn6,
					this->dataGridViewTextBoxColumn7, this->dataGridViewTextBoxColumn8, this->dataGridViewTextBoxColumn9, this->dataGridViewTextBoxColumn10
			});
			this->dgvDTI->Location = System::Drawing::Point(21, 276);
			this->dgvDTI->Name = L"dgvDTI";
			this->dgvDTI->RowHeadersVisible = false;
			this->dgvDTI->RowHeadersWidth = 51;
			this->dgvDTI->RowTemplate->Height = 24;
			this->dgvDTI->Size = System::Drawing::Size(865, 222);
			this->dgvDTI->TabIndex = 34;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->DataPropertyName = L"ResourceAlertIDDTI";
			this->dataGridViewTextBoxColumn6->HeaderText = L"ID Alerta";
			this->dataGridViewTextBoxColumn6->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			this->dataGridViewTextBoxColumn6->Width = 125;
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
			// btnEliminarDTI
			// 
			this->btnEliminarDTI->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnEliminarDTI->Location = System::Drawing::Point(21, 205);
			this->btnEliminarDTI->Name = L"btnEliminarDTI";
			this->btnEliminarDTI->Size = System::Drawing::Size(176, 49);
			this->btnEliminarDTI->TabIndex = 63;
			this->btnEliminarDTI->Text = L"Eliminar";
			this->btnEliminarDTI->UseVisualStyleBackColor = true;
			// 
			// btnEliminarAltercado
			// 
			this->btnEliminarAltercado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnEliminarAltercado->Location = System::Drawing::Point(21, 179);
			this->btnEliminarAltercado->Name = L"btnEliminarAltercado";
			this->btnEliminarAltercado->Size = System::Drawing::Size(176, 49);
			this->btnEliminarAltercado->TabIndex = 64;
			this->btnEliminarAltercado->Text = L"Eliminar";
			this->btnEliminarAltercado->UseVisualStyleBackColor = true;
			// 
			// btnEliminarObjPerd
			// 
			this->btnEliminarObjPerd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnEliminarObjPerd->Location = System::Drawing::Point(20, 177);
			this->btnEliminarObjPerd->Name = L"btnEliminarObjPerd";
			this->btnEliminarObjPerd->Size = System::Drawing::Size(162, 49);
			this->btnEliminarObjPerd->TabIndex = 64;
			this->btnEliminarObjPerd->Text = L"Eliminar";
			this->btnEliminarObjPerd->UseVisualStyleBackColor = true;
			// 
			// AdminAlertManagementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(929, 556);
			this->Controls->Add(this->tabControl1);
			this->Name = L"AdminAlertManagementForm";
			this->Text = L"AdminAlertManagementForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhotoObj))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvOjbPerdido))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhotoAltercado))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAltercado))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
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

					if (objeto[i]->GetType() == ObjPerdido::typeid) {
						dgvOjbPerdido->Rows->Add(gcnew array<String^>{
							"" + objeto[i]->id,
							objeto[i]->ObjetoEncontrado, 
							fecha, 
							hora, 
							estado
						});
					}
				}
			}
		}
		private: void CargarTablaAltercado() {

		}
		private: void CargarTablaDTIReport() {

		}
	};
}
