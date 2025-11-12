#pragma once
#include "DatosRobotsUsuariosForm.h"
#include "AccountForm.h"
#include "AdminAlertManagementForm.h"
#include "DelimitarZonasTrabajoAdmin.h"
#include "GraficsAdminForm.h"
//faltan añadir demas ventanas

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//ejemplo

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

	private: System::Windows::Forms::Button^ btnRobots;


	private: System::Windows::Forms::Button^ btnZonasT;


	private: System::Windows::Forms::Button^ btnEstadistica;
	private: System::Windows::Forms::PictureBox^ btnAccount;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox4;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnRobots = (gcnew System::Windows::Forms::Button());
			this->btnZonasT = (gcnew System::Windows::Forms::Button());
			this->btnEstadistica = (gcnew System::Windows::Forms::Button());
			this->btnAccount = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAccount))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
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
			this->button1->Click += gcnew System::EventHandler(this, &AdminForm::button1_Click);
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
			// btnZonasT
			// 
			this->btnZonasT->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F));
			this->btnZonasT->Location = System::Drawing::Point(482, 254);
			this->btnZonasT->Name = L"btnZonasT";
			this->btnZonasT->Size = System::Drawing::Size(158, 64);
			this->btnZonasT->TabIndex = 21;
			this->btnZonasT->Text = L"Delimitar Zonas de Trabajo";
			this->btnZonasT->UseVisualStyleBackColor = true;
			this->btnZonasT->Click += gcnew System::EventHandler(this, &AdminForm::btnZonasT_Click);
			// 
			// btnEstadistica
			// 
			this->btnEstadistica->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEstadistica->Location = System::Drawing::Point(34, 512);
			this->btnEstadistica->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnEstadistica->Name = L"btnEstadistica";
			this->btnEstadistica->Size = System::Drawing::Size(157, 64);
			this->btnEstadistica->TabIndex = 24;
			this->btnEstadistica->Text = L"Estadisticas";
			this->btnEstadistica->UseVisualStyleBackColor = true;
			this->btnEstadistica->Click += gcnew System::EventHandler(this, &AdminForm::btnEstadistica_Click);
			// 
			// btnAccount
			// 
			this->btnAccount->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAccount.Image")));
			this->btnAccount->Location = System::Drawing::Point(12, 11);
			this->btnAccount->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAccount->Name = L"btnAccount";
			this->btnAccount->Size = System::Drawing::Size(59, 59);
			this->btnAccount->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnAccount->TabIndex = 25;
			this->btnAccount->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(480, 102);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(161, 148);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 28;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(258, 102);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(161, 148);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 27;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(28, 102);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(161, 148);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 26;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(28, 359);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(159, 148);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 29;
			this->pictureBox4->TabStop = false;
			// 
			// AdminForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(716, 610);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnAccount);
			this->Controls->Add(this->btnEstadistica);
			this->Controls->Add(this->btnZonasT);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnRobots);
			this->Name = L"AdminForm";
			this->Text = L"AdminForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAccount))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
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
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		AdminAlertManagementForm^ form = gcnew AdminAlertManagementForm();
		this->Hide();
		form->ShowDialog();
		this->Show();
	}
	private: System::Void btnZonasT_Click(System::Object^ sender, System::EventArgs^ e) {
		DelimitarZonasTrabajoAdmin^ form = gcnew DelimitarZonasTrabajoAdmin();
		this->Hide();
		form->ShowDialog();
		this->Show();
	}
	private: System::Void btnEstadistica_Click(System::Object^ sender, System::EventArgs^ e) {
		GraficsAdminForm^ form = gcnew GraficsAdminForm();
		this->Hide();
		form->ShowDialog();
		this->Show();
	}
	};
}
