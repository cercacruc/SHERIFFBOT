#pragma once}
#include "GraficsUsersForm.h"
#include "GraficAlertUserSolForm.h"
#include "GraficsAdminForm.h"

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de GraficosUserForm
	/// </summary>
	public ref class GraficosUserForm : public System::Windows::Forms::Form
	{
	public:
		
		GraficosUserForm()
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
		~GraficosUserForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnAlertDoIt;
	private: System::Windows::Forms::Button^ btnAlertSolucionado;
	private: System::Windows::Forms::Button^ btnVolver;
	protected:

	protected:



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GraficosUserForm::typeid));
			this->btnAlertDoIt = (gcnew System::Windows::Forms::Button());
			this->btnAlertSolucionado = (gcnew System::Windows::Forms::Button());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnAlertDoIt
			// 
			this->btnAlertDoIt->Location = System::Drawing::Point(27, 26);
			this->btnAlertDoIt->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAlertDoIt->Name = L"btnAlertDoIt";
			this->btnAlertDoIt->Size = System::Drawing::Size(228, 68);
			this->btnAlertDoIt->TabIndex = 16;
			this->btnAlertDoIt->Text = L"USUARIOS/ROBOTS REGISTRADOS";
			this->btnAlertDoIt->UseVisualStyleBackColor = true;
			this->btnAlertDoIt->Click += gcnew System::EventHandler(this, &GraficosUserForm::btnAlertDoIt_Click);
			// 
			// btnAlertSolucionado
			// 
			this->btnAlertSolucionado->Location = System::Drawing::Point(27, 110);
			this->btnAlertSolucionado->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAlertSolucionado->Name = L"btnAlertSolucionado";
			this->btnAlertSolucionado->Size = System::Drawing::Size(228, 68);
			this->btnAlertSolucionado->TabIndex = 17;
			this->btnAlertSolucionado->Text = L"ALERTAS SOLUCIONADAS";
			this->btnAlertSolucionado->UseVisualStyleBackColor = true;
			this->btnAlertSolucionado->Click += gcnew System::EventHandler(this, &GraficosUserForm::btnAlertSolucionado_Click);
			// 
			// btnVolver
			// 
			this->btnVolver->Location = System::Drawing::Point(27, 194);
			this->btnVolver->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(228, 68);
			this->btnVolver->TabIndex = 18;
			this->btnVolver->Text = L"VOLVER";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &GraficosUserForm::btnVolver_Click);
			// 
			// GraficosUserForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(285, 284);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->btnAlertSolucionado);
			this->Controls->Add(this->btnAlertDoIt);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GraficosUserForm";
			this->Text = L"Graficos";
			this->ResumeLayout(false);

		}
		#pragma endregion
		private: System::Void btnAlertDoIt_Click(System::Object^ sender, System::EventArgs^ e) {
			GraficsAdminForm^ form = gcnew GraficsAdminForm();
			this->Hide();
			form->ShowDialog();
			this->Show();
		}
		private: System::Void btnAlertSolucionado_Click(System::Object^ sender, System::EventArgs^ e) {
			GraficAlertUserSolForm^ form = gcnew GraficAlertUserSolForm();
			this->Hide();
			form->ShowDialog();
			this->Show();
		}
		private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
