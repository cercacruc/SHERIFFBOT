#pragma once

namespace SheriffBotGUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
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
	private: System::Windows::Forms::TextBox^ BateriaRobot;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ IDRobot;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ btnSolucion;





	private: System::Windows::Forms::DataGridView^ dgvRobot;
























	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceAlertDMO;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceNameMO;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceDateMO;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceTimeMO;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ResourceStatusMO;
	private: System::Windows::Forms::TabPage^ tabPage1;





	private: System::Windows::Forms::Label^ label3;


	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;




	private: System::Windows::Forms::DataGridView^ dataGridView1;










	private: System::Windows::Forms::Label^ label13;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label15;




	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn10;
private: System::Windows::Forms::PictureBox^ pictureBox1;

private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::GroupBox^ groupBox1;
private: System::Windows::Forms::RadioButton^ rbtnContinuousUseNo;
private: System::Windows::Forms::RadioButton^ rbtnContinuousUseYes;
private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::TextBox^ textBox11;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::PictureBox^ pictureBox2;
private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::GroupBox^ groupBox2;
private: System::Windows::Forms::RadioButton^ radioButton1;
private: System::Windows::Forms::RadioButton^ radioButton2;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::GroupBox^ groupBox3;
private: System::Windows::Forms::RadioButton^ radioButton3;
private: System::Windows::Forms::RadioButton^ radioButton4;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::DateTimePicker^ dateTimePicker3;
private: System::Windows::Forms::ComboBox^ comboBox1;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->BateriaRobot = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->IDRobot = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->btnSolucion = (gcnew System::Windows::Forms::Button());
			this->dgvRobot = (gcnew System::Windows::Forms::DataGridView());
			this->ResourceAlertDMO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceNameMO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceDateMO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceTimeMO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ResourceStatusMO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rbtnContinuousUseNo = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnContinuousUseYes = (gcnew System::Windows::Forms::RadioButton());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->dateTimePicker3 = (gcnew System::Windows::Forms::DateTimePicker());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRobot))->BeginInit();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
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
			this->tabPage2->Controls->Add(this->label16);
			this->tabPage2->Controls->Add(this->groupBox1);
			this->tabPage2->Controls->Add(this->label9);
			this->tabPage2->Controls->Add(this->textBox11);
			this->tabPage2->Controls->Add(this->dateTimePicker1);
			this->tabPage2->Controls->Add(this->pictureBox1);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->label10);
			this->tabPage2->Controls->Add(this->BateriaRobot);
			this->tabPage2->Controls->Add(this->label11);
			this->tabPage2->Controls->Add(this->IDRobot);
			this->tabPage2->Controls->Add(this->label12);
			this->tabPage2->Controls->Add(this->btnSolucion);
			this->tabPage2->Controls->Add(this->dgvRobot);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Size = System::Drawing::Size(916, 514);
			this->tabPage2->TabIndex = 0;
			this->tabPage2->Text = L"Administrar Objeto Perdido";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(670, 49);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(211, 177);
			this->pictureBox1->TabIndex = 34;
			this->pictureBox1->TabStop = false;
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
			// BateriaRobot
			// 
			this->BateriaRobot->Location = System::Drawing::Point(152, 62);
			this->BateriaRobot->Name = L"BateriaRobot";
			this->BateriaRobot->Size = System::Drawing::Size(213, 22);
			this->BateriaRobot->TabIndex = 27;
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
			// IDRobot
			// 
			this->IDRobot->Location = System::Drawing::Point(152, 18);
			this->IDRobot->Name = L"IDRobot";
			this->IDRobot->Size = System::Drawing::Size(213, 22);
			this->IDRobot->TabIndex = 25;
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
			// btnSolucion
			// 
			this->btnSolucion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnSolucion->Location = System::Drawing::Point(89, 189);
			this->btnSolucion->Name = L"btnSolucion";
			this->btnSolucion->Size = System::Drawing::Size(177, 49);
			this->btnSolucion->TabIndex = 22;
			this->btnSolucion->Text = L"Solucionado";
			this->btnSolucion->UseVisualStyleBackColor = true;
			// 
			// dgvRobot
			// 
			this->dgvRobot->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvRobot->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->ResourceAlertDMO,
					this->ResourceNameMO, this->ResourceDateMO, this->ResourceTimeMO, this->ResourceStatusMO
			});
			this->dgvRobot->Location = System::Drawing::Point(20, 266);
			this->dgvRobot->Name = L"dgvRobot";
			this->dgvRobot->RowHeadersVisible = false;
			this->dgvRobot->RowHeadersWidth = 51;
			this->dgvRobot->RowTemplate->Height = 24;
			this->dgvRobot->Size = System::Drawing::Size(882, 222);
			this->dgvRobot->TabIndex = 18;
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
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label17);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->pictureBox2);
			this->tabPage1->Controls->Add(this->dateTimePicker2);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->textBox5);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Size = System::Drawing::Size(916, 514);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Administrar Altercado";
			this->tabPage1->UseVisualStyleBackColor = true;
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
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(188, 19);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(213, 22);
			this->textBox5->TabIndex = 40;
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
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5
			});
			this->dataGridView1->Location = System::Drawing::Point(21, 267);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(884, 222);
			this->dataGridView1->TabIndex = 34;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label6);
			this->tabPage3->Controls->Add(this->textBox1);
			this->tabPage3->Controls->Add(this->button2);
			this->tabPage3->Controls->Add(this->groupBox3);
			this->tabPage3->Controls->Add(this->label4);
			this->tabPage3->Controls->Add(this->dateTimePicker3);
			this->tabPage3->Controls->Add(this->comboBox1);
			this->tabPage3->Controls->Add(this->label13);
			this->tabPage3->Controls->Add(this->label14);
			this->tabPage3->Controls->Add(this->textBox10);
			this->tabPage3->Controls->Add(this->label15);
			this->tabPage3->Controls->Add(this->dataGridView2);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(916, 514);
			this->tabPage3->TabIndex = 1;
			this->tabPage3->Text = L"Administrar Reporte DTI";
			this->tabPage3->UseVisualStyleBackColor = true;
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
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(167, 14);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(213, 22);
			this->textBox10->TabIndex = 40;
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
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn6,
					this->dataGridViewTextBoxColumn7, this->dataGridViewTextBoxColumn8, this->dataGridViewTextBoxColumn9, this->dataGridViewTextBoxColumn10
			});
			this->dataGridView2->Location = System::Drawing::Point(21, 276);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(865, 222);
			this->dataGridView2->TabIndex = 34;
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
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(152, 101);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(213, 22);
			this->dateTimePicker1->TabIndex = 35;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(411, 49);
			this->textBox11->Multiline = true;
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(226, 177);
			this->textBox11->TabIndex = 36;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label9->Location = System::Drawing::Point(406, 14);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(114, 25);
			this->label9->TabIndex = 37;
			this->label9->Text = L"Descripción";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rbtnContinuousUseNo);
			this->groupBox1->Controls->Add(this->rbtnContinuousUseYes);
			this->groupBox1->Location = System::Drawing::Point(152, 128);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(133, 46);
			this->groupBox1->TabIndex = 38;
			this->groupBox1->TabStop = false;
			// 
			// rbtnContinuousUseNo
			// 
			this->rbtnContinuousUseNo->AutoSize = true;
			this->rbtnContinuousUseNo->Location = System::Drawing::Point(68, 20);
			this->rbtnContinuousUseNo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->rbtnContinuousUseNo->Name = L"rbtnContinuousUseNo";
			this->rbtnContinuousUseNo->Size = System::Drawing::Size(46, 20);
			this->rbtnContinuousUseNo->TabIndex = 1;
			this->rbtnContinuousUseNo->Text = L"No";
			this->rbtnContinuousUseNo->UseVisualStyleBackColor = true;
			// 
			// rbtnContinuousUseYes
			// 
			this->rbtnContinuousUseYes->AutoSize = true;
			this->rbtnContinuousUseYes->Checked = true;
			this->rbtnContinuousUseYes->Location = System::Drawing::Point(12, 20);
			this->rbtnContinuousUseYes->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->rbtnContinuousUseYes->Name = L"rbtnContinuousUseYes";
			this->rbtnContinuousUseYes->Size = System::Drawing::Size(40, 20);
			this->rbtnContinuousUseYes->TabIndex = 0;
			this->rbtnContinuousUseYes->TabStop = true;
			this->rbtnContinuousUseYes->Text = L"Sí";
			this->rbtnContinuousUseYes->UseVisualStyleBackColor = true;
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
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(188, 63);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(213, 22);
			this->dateTimePicker2->TabIndex = 50;
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
			this->label17->Text = L"Descripción";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(431, 51);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(226, 177);
			this->textBox2->TabIndex = 52;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(690, 51);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(211, 177);
			this->pictureBox2->TabIndex = 51;
			this->pictureBox2->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioButton1);
			this->groupBox2->Controls->Add(this->radioButton2);
			this->groupBox2->Location = System::Drawing::Point(153, 101);
			this->groupBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Size = System::Drawing::Size(133, 46);
			this->groupBox2->TabIndex = 56;
			this->groupBox2->TabStop = false;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(68, 20);
			this->radioButton1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(46, 20);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->Text = L"No";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = true;
			this->radioButton2->Location = System::Drawing::Point(12, 20);
			this->radioButton2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(40, 20);
			this->radioButton2->TabIndex = 0;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Sí";
			this->radioButton2->UseVisualStyleBackColor = true;
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
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button1->Location = System::Drawing::Point(132, 179);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(177, 49);
			this->button1->TabIndex = 57;
			this->button1->Text = L"Solucionado";
			this->button1->UseVisualStyleBackColor = true;
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
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Necesidades tecnologicas", L"Prestamo de dispositivo",
					L"Proteccion contra ciberdelincuencia", L"Autenticación y acceso a aplicaciones y datos PUCP"
			});
			this->comboBox1->Location = System::Drawing::Point(167, 55);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(213, 24);
			this->comboBox1->TabIndex = 44;
			// 
			// dateTimePicker3
			// 
			this->dateTimePicker3->Location = System::Drawing::Point(167, 104);
			this->dateTimePicker3->Name = L"dateTimePicker3";
			this->dateTimePicker3->Size = System::Drawing::Size(213, 22);
			this->dateTimePicker3->TabIndex = 51;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button2->Location = System::Drawing::Point(132, 221);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(177, 49);
			this->button2->TabIndex = 60;
			this->button2->Text = L"Solucionado";
			this->button2->UseVisualStyleBackColor = true;
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
			this->radioButton4->Text = L"Sí";
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
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label6->Location = System::Drawing::Point(410, 11);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(114, 25);
			this->label6->TabIndex = 62;
			this->label6->Text = L"Descripción";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(415, 46);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(471, 177);
			this->textBox1->TabIndex = 61;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRobot))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
