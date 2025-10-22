#pragma once
#include "AdminForm.h"
#include "SheriffForm.h"
#include "UsuarioPromedioForm.h"
#include "ForgotPasswordForm.h"

namespace SheriffBotGUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace BotModel;
	using namespace BotService;

	/// <summary>
	/// Resumen de LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			ClearFields();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnForgotPassword;
	protected:
	private: System::Windows::Forms::Button^ btnLogin2;
	private: System::Windows::Forms::TextBox^ Password;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ Username;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;

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
			this->btnForgotPassword = (gcnew System::Windows::Forms::Button());
			this->btnLogin2 = (gcnew System::Windows::Forms::Button());
			this->Password = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Username = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnForgotPassword
			// 
			this->btnForgotPassword->Location = System::Drawing::Point(156, 315);
			this->btnForgotPassword->Name = L"btnForgotPassword";
			this->btnForgotPassword->Size = System::Drawing::Size(210, 23);
			this->btnForgotPassword->TabIndex = 27;
			this->btnForgotPassword->Text = L"Olvidé mi contraseña";
			this->btnForgotPassword->UseVisualStyleBackColor = true;
			this->btnForgotPassword->Click += gcnew System::EventHandler(this, &LoginForm::btnForgotPassword_Click);
			// 
			// btnLogin2
			// 
			this->btnLogin2->Location = System::Drawing::Point(131, 239);
			this->btnLogin2->Name = L"btnLogin2";
			this->btnLogin2->Size = System::Drawing::Size(260, 59);
			this->btnLogin2->TabIndex = 26;
			this->btnLogin2->Text = L"Iniciar sesión";
			this->btnLogin2->UseVisualStyleBackColor = true;
			this->btnLogin2->Click += gcnew System::EventHandler(this, &LoginForm::btnLogin2_Click);
			// 
			// Password
			// 
			this->Password->Location = System::Drawing::Point(260, 168);
			this->Password->Margin = System::Windows::Forms::Padding(4);
			this->Password->Name = L"Password";
			this->Password->Size = System::Drawing::Size(175, 22);
			this->Password->TabIndex = 25;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label5->Location = System::Drawing::Point(35, 171);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(100, 20);
			this->label5->TabIndex = 24;
			this->label5->Text = L"Contraseña:";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Username
			// 
			this->Username->Location = System::Drawing::Point(260, 106);
			this->Username->Margin = System::Windows::Forms::Padding(4);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(175, 22);
			this->Username->TabIndex = 23;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label6->Location = System::Drawing::Point(35, 108);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(72, 20);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Usuario:";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label7->Location = System::Drawing::Point(33, 40);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(201, 31);
			this->label7->TabIndex = 21;
			this->label7->Text = L"Inicio de sesión";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(487, 365);
			this->Controls->Add(this->btnForgotPassword);
			this->Controls->Add(this->btnLogin2);
			this->Controls->Add(this->Password);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Username);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion
		private: System::Void btnLogin2_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				if (String::IsNullOrEmpty(Username->Text) || String::IsNullOrEmpty(Password->Text)) {
					MessageBox::Show("Por favor, complete todos los campos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				String^ username = Username->Text;
				String^ password = Password->Text;

				DatosUsuario^ usuarioEncontrado = Service::buscarUsuarioCredenciales(username, password);
				if (usuarioEncontrado != nullptr) {
					int userID = usuarioEncontrado->ID;
					String^ strID = userID.ToString();

					if (strID->Length >= 2) {
						String^ primerosDigitos = strID->Substring(0, 2);

						if (primerosDigitos == "99") {//Admin
							AdminForm^ adminForm = gcnew AdminForm();
							this->Hide();
							adminForm->ShowDialog();
							this->Show();
						}
						else if (primerosDigitos == "11") {//Sherif
							SheriffForm^ sherifForm = gcnew SheriffForm();
							this->Hide();
							sherifForm->ShowDialog();
							this->Show();
						}
						else if (primerosDigitos == "22" || primerosDigitos == "33" || primerosDigitos == "44") {//public general
							UsuarioPromedioForm^ usuarioForm = gcnew UsuarioPromedioForm();
							this->Hide();
							usuarioForm->ShowDialog();
							this->Show();
						}
					}
				}
				else {
					MessageBox::Show("Nombre de usuario o contraseña erroneos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				ClearFields();

			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al iniciar sesión: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		private: void LoginForm::ClearFields() {
			Username->Text = "";
			Password->Text = "";
		}
		private: System::Void btnForgotPassword_Click(System::Object^ sender, System::EventArgs^ e) {
			ForgotPasswordForm^ form = gcnew ForgotPasswordForm();
			this->Hide();
			form->ShowDialog();
			this->Show();
		}
};
}
