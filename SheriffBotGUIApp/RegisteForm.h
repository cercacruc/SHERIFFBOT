#pragma once

namespace SheriffBotGUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de RegisteForm
	/// </summary>
	public ref class RegisteForm : public System::Windows::Forms::Form
	{
	public:
		RegisteForm(void)
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
		~RegisteForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnRegister2;
	protected:
	private: System::Windows::Forms::ComboBox^ cbmRole;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ btnPassword;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ btnUsername;
	private: System::Windows::Forms::Label^ label2;
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
			this->btnRegister2 = (gcnew System::Windows::Forms::Button());
			this->cbmRole = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnPassword = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnUsername = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnRegister2
			// 
			this->btnRegister2->Location = System::Drawing::Point(141, 294);
			this->btnRegister2->Name = L"btnRegister2";
			this->btnRegister2->Size = System::Drawing::Size(260, 55);
			this->btnRegister2->TabIndex = 22;
			this->btnRegister2->Text = L"Registrarse";
			this->btnRegister2->UseVisualStyleBackColor = true;
			// 
			// cbmRole
			// 
			this->cbmRole->FormattingEnabled = true;
			this->cbmRole->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Sheriff", L"Estudiante", L"Profesor", L"Visitante externo" });
			this->cbmRole->Location = System::Drawing::Point(278, 218);
			this->cbmRole->Name = L"cbmRole";
			this->cbmRole->Size = System::Drawing::Size(179, 24);
			this->cbmRole->TabIndex = 21;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(24, 218);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(135, 20);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Escoja su cargo:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnPassword
			// 
			this->btnPassword->Location = System::Drawing::Point(278, 154);
			this->btnPassword->Margin = System::Windows::Forms::Padding(4);
			this->btnPassword->Name = L"btnPassword";
			this->btnPassword->Size = System::Drawing::Size(179, 22);
			this->btnPassword->TabIndex = 19;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(24, 156);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(161, 20);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Cree su contraseña:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnUsername
			// 
			this->btnUsername->Location = System::Drawing::Point(278, 92);
			this->btnUsername->Margin = System::Windows::Forms::Padding(4);
			this->btnUsername->Name = L"btnUsername";
			this->btnUsername->Size = System::Drawing::Size(179, 22);
			this->btnUsername->TabIndex = 17;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(24, 93);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(217, 20);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Cree su nombre de usuario:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label1->Location = System::Drawing::Point(22, 25);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(116, 31);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Registro";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// RegisteForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(499, 368);
			this->Controls->Add(this->btnRegister2);
			this->Controls->Add(this->cbmRole);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnPassword);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnUsername);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"RegisteForm";
			this->Text = L"RegisteForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
