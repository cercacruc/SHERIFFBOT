#pragma once
#include "DatosRobotsUsuariosForm.h"
#include "AccountForm.h"
//faltan añadir demas ventanas

namespace SheriffBotGUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de AdminForm
	/// </summary>
	public ref class AdminForm : public System::Windows::Forms::Form
	{
	public:
		DatosUsuario^ Usuario;
		AdminForm(DatosUsuario^ usuario)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			Usuario = usuario;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~AdminForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ btnRobots;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ btnAccount;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->btnRobots = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnAccount = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAccount))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(262, 254);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(157, 64);
			this->button1->TabIndex = 20;
			this->button1->Text = L"Registro de Incidencias";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(260, 95);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(161, 148);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 19;
			this->pictureBox2->TabStop = false;
			// 
			// btnRobots
			// 
			this->btnRobots->Location = System::Drawing::Point(32, 254);
			this->btnRobots->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnRobots->Name = L"btnRobots";
			this->btnRobots->Size = System::Drawing::Size(157, 64);
			this->btnRobots->TabIndex = 18;
			this->btnRobots->Text = L"Gestión de Usuarios/Robots";
			this->btnRobots->UseVisualStyleBackColor = true;
			this->btnRobots->Click += gcnew System::EventHandler(this, &AdminForm::btnRobots_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(30, 95);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(161, 148);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			// 
			// btnAccount
			// 
			this->btnAccount->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAccount.Image")));
			this->btnAccount->Location = System::Drawing::Point(12, 11);
			this->btnAccount->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAccount->Name = L"btnAccount";
			this->btnAccount->Size = System::Drawing::Size(59, 59);
			this->btnAccount->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnAccount->TabIndex = 16;
			this->btnAccount->TabStop = false;
			this->btnAccount->Click += gcnew System::EventHandler(this, &AdminForm::btnAccount_Click);
			// 
			// AdminForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(716, 610);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->btnRobots);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnAccount);
			this->Name = L"AdminForm";
			this->Text = L"AdminForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAccount))->EndInit();
			this->ResumeLayout(false);

		}
		#pragma endregion
		private: System::Void btnRobots_Click(System::Object^ sender, System::EventArgs^ e) {
			DatosRobotsUsuariosForm^ form = gcnew DatosRobotsUsuariosForm();
			this->Hide();
			form->ShowDialog();
			this->Show();
		}
		private: System::Void btnAccount_Click(System::Object^ sender, System::EventArgs^ e) {
			AccountForm^ form = gcnew AccountForm(Usuario);
			this->Hide();
			form->ShowDialog();
			this->Show();
		}
	};
}
