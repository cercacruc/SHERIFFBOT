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

	/// <summary>
	/// Resumen de ForgotPasswordForm
	/// </summary>
	public ref class ForgotPasswordForm : public System::Windows::Forms::Form
	{
	public:
		ForgotPasswordForm(void)
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
		~ForgotPasswordForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnSendPassword;
	protected:
	private: System::Windows::Forms::Button^ btnReturnPassword;
	private: System::Windows::Forms::TextBox^ NewPassword2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ NewPassword1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ UserName;
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
			this->btnSendPassword = (gcnew System::Windows::Forms::Button());
			this->btnReturnPassword = (gcnew System::Windows::Forms::Button());
			this->NewPassword2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->NewPassword1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->UserName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnSendPassword
			// 
			this->btnSendPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnSendPassword->Location = System::Drawing::Point(162, 341);
			this->btnSendPassword->Name = L"btnSendPassword";
			this->btnSendPassword->Size = System::Drawing::Size(193, 47);
			this->btnSendPassword->TabIndex = 33;
			this->btnSendPassword->Text = L"Enviar";
			this->btnSendPassword->UseVisualStyleBackColor = true;
			this->btnSendPassword->Click += gcnew System::EventHandler(this, &ForgotPasswordForm::btnSendPassword_Click);
			// 
			// btnReturnPassword
			// 
			this->btnReturnPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnReturnPassword->Location = System::Drawing::Point(162, 410);
			this->btnReturnPassword->Name = L"btnReturnPassword";
			this->btnReturnPassword->Size = System::Drawing::Size(193, 47);
			this->btnReturnPassword->TabIndex = 32;
			this->btnReturnPassword->Text = L"Volver";
			this->btnReturnPassword->UseVisualStyleBackColor = true;
			this->btnReturnPassword->Click += gcnew System::EventHandler(this, &ForgotPasswordForm::btnReturnPassword_Click);
			// 
			// NewPassword2
			// 
			this->NewPassword2->Location = System::Drawing::Point(281, 282);
			this->NewPassword2->Margin = System::Windows::Forms::Padding(4);
			this->NewPassword2->Name = L"NewPassword2";
			this->NewPassword2->Size = System::Drawing::Size(175, 22);
			this->NewPassword2->TabIndex = 31;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(28, 282);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(188, 20);
			this->label4->TabIndex = 30;
			this->label4->Text = L"Confirme la contraseña:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// NewPassword1
			// 
			this->NewPassword1->Location = System::Drawing::Point(281, 205);
			this->NewPassword1->Margin = System::Windows::Forms::Padding(4);
			this->NewPassword1->Name = L"NewPassword1";
			this->NewPassword1->Size = System::Drawing::Size(175, 22);
			this->NewPassword1->TabIndex = 29;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(28, 207);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(224, 20);
			this->label3->TabIndex = 28;
			this->label3->Text = L"Ingrese la nueva contraseña:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// UserName
			// 
			this->UserName->Location = System::Drawing::Point(281, 140);
			this->UserName->Margin = System::Windows::Forms::Padding(4);
			this->UserName->Name = L"UserName";
			this->UserName->Size = System::Drawing::Size(175, 22);
			this->UserName->TabIndex = 27;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(28, 140);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 20);
			this->label2->TabIndex = 26;
			this->label2->Text = L"Usuario:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(119, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(267, 29);
			this->label1->TabIndex = 25;
			this->label1->Text = L"Restablecer contraseña";
			// 
			// ForgotPasswordForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(495, 484);
			this->Controls->Add(this->btnSendPassword);
			this->Controls->Add(this->btnReturnPassword);
			this->Controls->Add(this->NewPassword2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->NewPassword1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->UserName);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ForgotPasswordForm";
			this->Text = L"ForgotPasswordForm";
			this->Load += gcnew System::EventHandler(this, &ForgotPasswordForm::ForgotPasswordForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSendPassword_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (String::IsNullOrEmpty(UserName->Text) || String::IsNullOrEmpty(NewPassword1->Text) || String::IsNullOrEmpty(NewPassword2->Text)) {
				MessageBox::Show("Por favor, complete todos los campos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (NewPassword1->Text != NewPassword2->Text) {
				MessageBox::Show("Las contraseñas no coinciden", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				NewPassword1->Text = "";
				NewPassword2->Text = "";
				NewPassword1->Focus();
				return;
			}

			int restablecer = Service::restablecerUsuario(UserName->Text, NewPassword1->Text, NewPassword2->Text);

			if (restablecer != 0) {
				MessageBox::Show("Contraseña restablecida exitosamente", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Close();
			}
			else {
				MessageBox::Show("Error al cambiar la contraseña", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al restablecer contraseña: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnReturnPassword_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: void CargarDatos() {
		List<DatosUsuario^>^ usuarioList = Service::GetUsuarios();
	}
	private: System::Void ForgotPasswordForm_Load(System::Object^ sender, System::EventArgs^ e) {
		CargarDatos();
	}
	};
}
