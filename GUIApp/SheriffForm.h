#pragma once
#include "TasksRobotsForm.h"
#include "AccountForm.h"
#include "RobotsSheriffForm.h"
#include "AlertManagementForm.h"
#include "AsignarAlertaRobotForm.h"

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de SheriffForm
	/// </summary>
	public ref class SheriffForm : public System::Windows::Forms::Form
	{
	public:
		DatosUsuario^ Usuario;
		SheriffForm(DatosUsuario^ usuario)
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
		~SheriffForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ btnInfo;

	private: System::Windows::Forms::Button^ btnRobots;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ btnAccount;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ btnCerrarSesion;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SheriffForm::typeid));
			this->btnInfo = (gcnew System::Windows::Forms::Button());
			this->btnRobots = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnAccount = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->btnCerrarSesion = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAccount))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// btnInfo
			// 
			this->btnInfo->Location = System::Drawing::Point(16, 490);
			this->btnInfo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnInfo->Name = L"btnInfo";
			this->btnInfo->Size = System::Drawing::Size(157, 37);
			this->btnInfo->TabIndex = 15;
			this->btnInfo->Text = L"Menú de Solicitudes\r\n";
			this->btnInfo->UseVisualStyleBackColor = true;
			this->btnInfo->Click += gcnew System::EventHandler(this, &SheriffForm::btnInfo_Click);
			// 
			// btnRobots
			// 
			this->btnRobots->Location = System::Drawing::Point(14, 247);
			this->btnRobots->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnRobots->Name = L"btnRobots";
			this->btnRobots->Size = System::Drawing::Size(157, 37);
			this->btnRobots->TabIndex = 13;
			this->btnRobots->Text = L"Gestión de robots";
			this->btnRobots->UseVisualStyleBackColor = true;
			this->btnRobots->Click += gcnew System::EventHandler(this, &SheriffForm::btnRobots_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(203, 247);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(157, 37);
			this->button1->TabIndex = 18;
			this->button1->Text = L"Asignar Robots";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SheriffForm::button1_Click);
			// 
			// btnAccount
			// 
			this->btnAccount->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAccount.Image")));
			this->btnAccount->Location = System::Drawing::Point(12, 11);
			this->btnAccount->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAccount->Name = L"btnAccount";
			this->btnAccount->Size = System::Drawing::Size(59, 59);
			this->btnAccount->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnAccount->TabIndex = 19;
			this->btnAccount->TabStop = false;
			this->btnAccount->Click += gcnew System::EventHandler(this, &SheriffForm::btnAccount_Click_1);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(10, 88);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(161, 148);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 20;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(199, 88);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(161, 148);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 21;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(10, 338);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(161, 148);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 22;
			this->pictureBox2->TabStop = false;
			// 
			// btnCerrarSesion
			// 
			this->btnCerrarSesion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCerrarSesion->Location = System::Drawing::Point(216, 11);
			this->btnCerrarSesion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCerrarSesion->Name = L"btnCerrarSesion";
			this->btnCerrarSesion->Size = System::Drawing::Size(144, 59);
			this->btnCerrarSesion->TabIndex = 31;
			this->btnCerrarSesion->Text = L"Cerrar Sesión";
			this->btnCerrarSesion->UseVisualStyleBackColor = true;
			this->btnCerrarSesion->Click += gcnew System::EventHandler(this, &SheriffForm::btnCerrarSesion_Click);
			// 
			// SheriffForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(377, 556);
			this->Controls->Add(this->btnCerrarSesion);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnAccount);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnInfo);
			this->Controls->Add(this->btnRobots);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"SheriffForm";
			this->Text = L"SheriffForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAccount))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
		#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			AsignarAlertaRobotForm^ form = gcnew AsignarAlertaRobotForm();
			this->Hide();
			form->ShowDialog();
			this->Show();
		}
		private: System::Void btnRobots_Click(System::Object^ sender, System::EventArgs^ e) {
			RobotsSheriffForm^ form = gcnew RobotsSheriffForm();
			this->Hide();
			form->ShowDialog();
			this->Show();
		}
		private: System::Void btnInfo_Click(System::Object^ sender, System::EventArgs^ e) {
			AlertManagementForm^ form = gcnew AlertManagementForm();
			this->Hide();
			form->ShowDialog();
			this->Show();
		}
		private: System::Void btnCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
		private: System::Void btnAccount_Click_1(System::Object^ sender, System::EventArgs^ e) {
			AccountForm^ form = gcnew AccountForm(Usuario);
			this->Hide();
			form->ShowDialog();
			this->Show();
		}
	};
}
