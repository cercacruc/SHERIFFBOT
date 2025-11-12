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

	/// <summary>
	/// Resumen de RegisteForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			textPassword->PasswordChar = '*';
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnRegister2;
	private: System::Windows::Forms::ComboBox^ textRole;
	protected:

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textPassword;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textUsername;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

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
			this->btnRegister2 = (gcnew System::Windows::Forms::Button());
			this->textRole = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textPassword = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textUsername = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnRegister2
			// 
			this->btnRegister2->Location = System::Drawing::Point(115, 284);
			this->btnRegister2->Name = L"btnRegister2";
			this->btnRegister2->Size = System::Drawing::Size(260, 55);
			this->btnRegister2->TabIndex = 22;
			this->btnRegister2->Text = L"Registrarse";
			this->btnRegister2->UseVisualStyleBackColor = true;
			this->btnRegister2->Click += gcnew System::EventHandler(this, &RegisterForm::btnRegister2_Click);
			// 
			// textRole
			// 
			this->textRole->FormattingEnabled = true;
			this->textRole->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Sheriff", L"Estudiante", L"Profesor", L"Visitante externo" });
			this->textRole->Location = System::Drawing::Point(278, 218);
			this->textRole->Name = L"textRole";
			this->textRole->Size = System::Drawing::Size(179, 24);
			this->textRole->TabIndex = 21;
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
			// textPassword
			// 
			this->textPassword->Location = System::Drawing::Point(278, 154);
			this->textPassword->Margin = System::Windows::Forms::Padding(4);
			this->textPassword->Name = L"textPassword";
			this->textPassword->Size = System::Drawing::Size(179, 22);
			this->textPassword->TabIndex = 19;
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
			// textUsername
			// 
			this->textUsername->Location = System::Drawing::Point(278, 92);
			this->textUsername->Margin = System::Windows::Forms::Padding(4);
			this->textUsername->Name = L"textUsername";
			this->textUsername->Size = System::Drawing::Size(179, 22);
			this->textUsername->TabIndex = 17;
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
			this->Controls->Add(this->textRole);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textPassword);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textUsername);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"RegisteForm";
			this->Text = L"RegisteForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnRegister2_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (String::IsNullOrEmpty(textUsername->Text) || String::IsNullOrEmpty(textPassword->Text) || String::IsNullOrEmpty(textRole->Text)) {
				MessageBox::Show("Por favor, complete todos los campos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			DatosUsuario^ usuario = gcnew DatosUsuario();

			usuario->Nombre = textUsername->Text;
			usuario->Cargo = textRole->Text;
			usuario->Contra = textPassword->Text;

			String^ cargo = textRole->Text;
			usuario->ID = Service::generarAutoID(cargo);

			usuario->cant_alertas = gcnew array<int>(3);
			for (int i = 0; i < 3; i++) {
				usuario->cant_alertas[i] = 0;
			}

			Service::registrarUsuario(usuario);
			MessageBox::Show("¡Registro exitoso!", "Exito", MessageBoxButtons::OK);

			this->Close();
		}
		catch (FormatException^) {
			MessageBox::Show("Por favor, ingrese valores válidos en los campos numéricos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al agregar usuario: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	};
}
