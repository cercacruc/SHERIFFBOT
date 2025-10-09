#pragma once

namespace SheriffBotGUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de UserAlertViewForm
	/// </summary>
	public ref class UserAlertViewForm : public System::Windows::Forms::Form
	{
	public:
		UserAlertViewForm(void)
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
		~UserAlertViewForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::ColumnHeader^ columnHeader4;
	private: System::Windows::Forms::ColumnHeader^ columnHeader5;
	private: System::Windows::Forms::ColumnHeader^ columnHeader6;
	private: System::Windows::Forms::TabPage^ tabPage2;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::ListView^ listView2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader7;
	private: System::Windows::Forms::ColumnHeader^ columnHeader8;
	private: System::Windows::Forms::ColumnHeader^ columnHeader9;
	private: System::Windows::Forms::ColumnHeader^ columnHeader10;
	private: System::Windows::Forms::ColumnHeader^ columnHeader11;
	private: System::Windows::Forms::ColumnHeader^ columnHeader12;
	private: System::Windows::Forms::TabPage^ tabPage3;

	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::ListView^ listView3;
	private: System::Windows::Forms::ColumnHeader^ columnHeader13;
	private: System::Windows::Forms::ColumnHeader^ columnHeader14;
	private: System::Windows::Forms::ColumnHeader^ columnHeader15;
	private: System::Windows::Forms::ColumnHeader^ columnHeader16;
	private: System::Windows::Forms::ColumnHeader^ columnHeader17;
	private: System::Windows::Forms::ColumnHeader^ columnHeader18;

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
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->listView2 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader10 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader11 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader12 = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->listView3 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader13 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader14 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader15 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader16 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader17 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader18 = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(2, 62);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(659, 407);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->listView1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(651, 378);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Objeto perdido";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button1->Location = System::Drawing::Point(241, 38);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(174, 66);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Ver detalle";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6
			});
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(0, 133);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(651, 245);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"ID Alerta";
			this->columnHeader1->Width = 89;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Usuario";
			this->columnHeader2->Width = 114;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Objeto";
			this->columnHeader3->Width = 107;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Fecha";
			this->columnHeader4->Width = 105;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"Hora";
			this->columnHeader5->Width = 96;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"Estado";
			this->columnHeader6->Width = 112;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->button4);
			this->tabPage2->Controls->Add(this->listView2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(651, 378);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Altercado";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button4->Location = System::Drawing::Point(241, 37);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(174, 66);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Ver detalle";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// listView2
			// 
			this->listView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->columnHeader7, this->columnHeader8,
					this->columnHeader9, this->columnHeader10, this->columnHeader11, this->columnHeader12
			});
			this->listView2->HideSelection = false;
			this->listView2->Location = System::Drawing::Point(0, 137);
			this->listView2->Name = L"listView2";
			this->listView2->Size = System::Drawing::Size(650, 245);
			this->listView2->TabIndex = 3;
			this->listView2->UseCompatibleStateImageBehavior = false;
			this->listView2->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"ID Alerta";
			this->columnHeader7->Width = 89;
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"Usuario";
			this->columnHeader8->Width = 114;
			// 
			// columnHeader9
			// 
			this->columnHeader9->Text = L"Tipo de altercado";
			this->columnHeader9->Width = 138;
			// 
			// columnHeader10
			// 
			this->columnHeader10->Text = L"Fecha";
			this->columnHeader10->Width = 100;
			// 
			// columnHeader11
			// 
			this->columnHeader11->Text = L"Hora";
			this->columnHeader11->Width = 86;
			// 
			// columnHeader12
			// 
			this->columnHeader12->Text = L"Estado";
			this->columnHeader12->Width = 118;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->button6);
			this->tabPage3->Controls->Add(this->listView3);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(651, 378);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Reporte DTI";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button6->Location = System::Drawing::Point(233, 35);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(174, 66);
			this->button6->TabIndex = 7;
			this->button6->Text = L"Ver detalle";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// listView3
			// 
			this->listView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->columnHeader13, this->columnHeader14,
					this->columnHeader15, this->columnHeader16, this->columnHeader17, this->columnHeader18
			});
			this->listView3->HideSelection = false;
			this->listView3->Location = System::Drawing::Point(0, 137);
			this->listView3->Name = L"listView3";
			this->listView3->Size = System::Drawing::Size(655, 245);
			this->listView3->TabIndex = 6;
			this->listView3->UseCompatibleStateImageBehavior = false;
			this->listView3->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader13
			// 
			this->columnHeader13->Text = L"ID Alerta";
			this->columnHeader13->Width = 89;
			// 
			// columnHeader14
			// 
			this->columnHeader14->Text = L"Usuario";
			this->columnHeader14->Width = 114;
			// 
			// columnHeader15
			// 
			this->columnHeader15->Text = L"Tipo de alerta";
			this->columnHeader15->Width = 111;
			// 
			// columnHeader16
			// 
			this->columnHeader16->Text = L"Fecha";
			this->columnHeader16->Width = 113;
			// 
			// columnHeader17
			// 
			this->columnHeader17->Text = L"Hora";
			this->columnHeader17->Width = 100;
			// 
			// columnHeader18
			// 
			this->columnHeader18->Text = L"Estado";
			this->columnHeader18->Width = 152;
			// 
			// UserAlertViewForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(658, 463);
			this->Controls->Add(this->tabControl1);
			this->Name = L"UserAlertViewForm";
			this->Text = L"UserAlertViewForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
