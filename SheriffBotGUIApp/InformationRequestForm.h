#pragma once

namespace SheriffBotGUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de InformationRequestForm
	/// </summary>
	public ref class InformationRequestForm : public System::Windows::Forms::Form
	{
	public:
		InformationRequestForm(void)
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
		~InformationRequestForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnReturnInfoRequest;
	protected:
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label1;

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
			this->btnReturnInfoRequest = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnReturnInfoRequest
			// 
			this->btnReturnInfoRequest->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnReturnInfoRequest->Location = System::Drawing::Point(145, 397);
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
			this->tabControl1->Size = System::Drawing::Size(456, 308);
			this->tabControl1->TabIndex = 25;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Size = System::Drawing::Size(448, 279);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Comida";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(64, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(281, 20);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Comedores y cafeterias disponibles:";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Size = System::Drawing::Size(448, 279);
			this->tabPage2->TabIndex = 0;
			this->tabPage2->Text = L"Aulas libres";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(133, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(145, 20);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Aulas disponibles:";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label4);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(448, 279);
			this->tabPage3->TabIndex = 1;
			this->tabPage3->Text = L"Zonas de estudio";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(93, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(230, 20);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Zonas de estudio disponibles:";
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->label6);
			this->tabPage4->Controls->Add(this->comboBox1);
			this->tabPage4->Controls->Add(this->label5);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(448, 279);
			this->tabPage4->TabIndex = 2;
			this->tabPage4->Text = L"Lugar";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label6->Location = System::Drawing::Point(161, 97);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(104, 20);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Como llegar:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(22) {
				L"Pabellón A", L"Pabellón B", L"Pabellón D", L"Pabellón E",
					L"Pabellón F", L"Pabellón H", L"Pabellón I", L"Pabellón J", L"Pabellón K", L"Pabellón L", L"Pabellón M", L"Pabellón N", L"Pabellón O",
					L"Pabellón P", L"Pabellón Q", L"Pabellón R", L"Pabellón S", L"Pabellón U", L"Pabellón V", L"Pabellón X", L"Pabellón Y", L"Pabellón Z"
			});
			this->comboBox1->Location = System::Drawing::Point(65, 57);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(310, 24);
			this->comboBox1->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label5->Location = System::Drawing::Point(125, 20);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(174, 20);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Ingrese una dirección:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(98, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(277, 29);
			this->label1->TabIndex = 26;
			this->label1->Text = L"Solicitud de información:";
			// 
			// InformationRequestForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(478, 455);
			this->Controls->Add(this->btnReturnInfoRequest);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->label1);
			this->Name = L"InformationRequestForm";
			this->Text = L"InformationRequestForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void btnReturnInfoRequest_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
