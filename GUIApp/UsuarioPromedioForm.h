#pragma once
#include "InformationRequestForm.h"
#include "AlertForm.h"
#include "AccountForm.h"
#include "GraficsUsersForm.h"
#include "GraficosUserForm.h"

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de UsuarioPromedioForm
	/// </summary>
	public ref class UsuarioPromedioForm : public System::Windows::Forms::Form
	{
	public:
		DatosUsuario^ Usuario;
		UsuarioPromedioForm(DatosUsuario^ usuario)
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
		~UsuarioPromedioForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ btnAlert;

	private: System::Windows::Forms::Button^ btnInfo;

	private: System::Windows::Forms::Button^ btnEstadisticas;




	private: System::Windows::Forms::Button^ btnCerrarSesion;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UsuarioPromedioForm::typeid));
			this->btnAlert = (gcnew System::Windows::Forms::Button());
			this->btnInfo = (gcnew System::Windows::Forms::Button());
			this->btnEstadisticas = (gcnew System::Windows::Forms::Button());
			this->btnCerrarSesion = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// btnAlert
			// 
			this->btnAlert->Location = System::Drawing::Point(132, 475);
			this->btnAlert->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAlert->Name = L"btnAlert";
			this->btnAlert->Size = System::Drawing::Size(157, 37);
			this->btnAlert->TabIndex = 13;
			this->btnAlert->Text = L"Alertar";
			this->btnAlert->UseVisualStyleBackColor = true;
			this->btnAlert->Click += gcnew System::EventHandler(this, &UsuarioPromedioForm::btnAlert_Click);
			// 
			// btnInfo
			// 
			this->btnInfo->Location = System::Drawing::Point(16, 248);
			this->btnInfo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnInfo->Name = L"btnInfo";
			this->btnInfo->Size = System::Drawing::Size(157, 37);
			this->btnInfo->TabIndex = 11;
			this->btnInfo->Text = L"Solicitar información";
			this->btnInfo->UseVisualStyleBackColor = true;
			this->btnInfo->Click += gcnew System::EventHandler(this, &UsuarioPromedioForm::btnInfo_Click);
			// 
			// btnEstadisticas
			// 
			this->btnEstadisticas->Location = System::Drawing::Point(256, 248);
			this->btnEstadisticas->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnEstadisticas->Name = L"btnEstadisticas";
			this->btnEstadisticas->Size = System::Drawing::Size(157, 37);
			this->btnEstadisticas->TabIndex = 15;
			this->btnEstadisticas->Text = L"Estadisticas";
			this->btnEstadisticas->UseVisualStyleBackColor = true;
			this->btnEstadisticas->Click += gcnew System::EventHandler(this, &UsuarioPromedioForm::btnEstadisticas_Click);
			// 
			// btnCerrarSesion
			// 
			this->btnCerrarSesion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCerrarSesion->Location = System::Drawing::Point(269, 11);
			this->btnCerrarSesion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCerrarSesion->Name = L"btnCerrarSesion";
			this->btnCerrarSesion->Size = System::Drawing::Size(144, 59);
			this->btnCerrarSesion->TabIndex = 32;
			this->btnCerrarSesion->Text = L"Cerrar Sesión";
			this->btnCerrarSesion->UseVisualStyleBackColor = true;
			this->btnCerrarSesion->Click += gcnew System::EventHandler(this, &UsuarioPromedioForm::btnCerrarSesion_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(12, 96);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(161, 148);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 33;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(252, 96);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(161, 148);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 34;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(128, 323);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(161, 148);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 35;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(12, 11);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(59, 59);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 36;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &UsuarioPromedioForm::pictureBox4_Click);
			// 
			// UsuarioPromedioForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(430, 536);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->btnCerrarSesion);
			this->Controls->Add(this->btnEstadisticas);
			this->Controls->Add(this->btnAlert);
			this->Controls->Add(this->btnInfo);
			this->Name = L"UsuarioPromedioForm";
			this->Text = L"UsuarioPromedioForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnInfo_Click(System::Object^ sender, System::EventArgs^ e) {
		InformationRequestForm^ Informationform = gcnew InformationRequestForm();
		this->Hide();
		Informationform->ShowDialog();
		this->Show();
	}
	private: System::Void btnAlert_Click(System::Object^ sender, System::EventArgs^ e) {
		AlertForm^ form = gcnew AlertForm(Usuario);
		this->Hide();
		form->ShowDialog();
		this->Show();
	}
	private: System::Void btnEstadisticas_Click(System::Object^ sender, System::EventArgs^ e) {
		GraficsUsersForm^ form = gcnew GraficsUsersForm(Usuario);
		this->Hide();
		form->ShowDialog();
		this->Show();
	}
	private: System::Void btnCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
		AccountForm^ form = gcnew AccountForm(Usuario);
		this->Hide();
		form->ShowDialog();
		this->Show();
	}
};
}
