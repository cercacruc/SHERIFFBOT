#pragma once
#include "RegisterForm.h"
#include "LoginForm.h"

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnLogin;
	protected:

	private: System::Windows::Forms::Button^ btnRegister;
	protected:


	private: System::Windows::Forms::PictureBox^ pictureBox1;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(78, 432);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(249, 66);
			this->btnLogin->TabIndex = 7;
			this->btnLogin->Text = L"Iniciar sesión";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &MainForm::btnLogin_Click);
			// 
			// btnRegister
			// 
			this->btnRegister->Location = System::Drawing::Point(78, 346);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(249, 62);
			this->btnRegister->TabIndex = 6;
			this->btnRegister->Text = L"Registrarse";
			this->btnRegister->UseVisualStyleBackColor = true;
			this->btnRegister->Click += gcnew System::EventHandler(this, &MainForm::btnRegister_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(24, 67);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(367, 255);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(419, 528);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->btnRegister);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		private: System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
			RegisterForm^ registerform = gcnew RegisterForm();
			registerform->Owner = this;
			this->Hide();
			registerform->ShowDialog();
			this->Show();
		}
		private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
			LoginForm^ loginForm = gcnew LoginForm();
			loginForm->Owner = this;
			this->Hide();
			loginForm->ShowDialog();
			this->Show();
		}
		Thread^ myThread;
		delegate void MyDelegate(String^);
		private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
			myThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::CargarHoraRealTime));
			myThread->Start();
		}
		private: void CargarHoraRealTime() {
			String^ title = " ";
			while (true)
			{
				try {
					myThread->Sleep(1000);
					Invoke(gcnew MyDelegate(this, &MainForm::UpdateTitle), title + DateTime::Now);
				}
				catch (Exception^ ex) {
					return;
				}
			}
		}
		private: void UpdateTitle(String^ newTitle) {
			this->Text = newTitle;
		}
	};
}
