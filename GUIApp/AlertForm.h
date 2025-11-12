#pragma once
#include "MissingObjectForm.h"
#include "AltercationReportForm.h"
#include "DTIReportForm.h"
#include "AlertHistForm.h"

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace BotModel;
	using namespace BotService;

	/// <summary>
	/// Resumen de AlertForm
	/// </summary>
	public ref class AlertForm : public System::Windows::Forms::Form
	{
	public:
		DatosUsuario^ Usuario;
		AlertForm(DatosUsuario^ usuario)
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
		~AlertForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnReturn;
	protected:
	private: System::Windows::Forms::Button^ btnDTIReport;
	private: System::Windows::Forms::Button^ btnAltercation;
	private: System::Windows::Forms::Button^ btnMissingObject;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnHistReport;

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
			this->btnReturn = (gcnew System::Windows::Forms::Button());
			this->btnDTIReport = (gcnew System::Windows::Forms::Button());
			this->btnAltercation = (gcnew System::Windows::Forms::Button());
			this->btnMissingObject = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnHistReport = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnReturn
			// 
			this->btnReturn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnReturn->Location = System::Drawing::Point(75, 476);
			this->btnReturn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnReturn->Name = L"btnReturn";
			this->btnReturn->Size = System::Drawing::Size(271, 59);
			this->btnReturn->TabIndex = 9;
			this->btnReturn->Text = L"Volver";
			this->btnReturn->UseVisualStyleBackColor = true;
			this->btnReturn->Click += gcnew System::EventHandler(this, &AlertForm::btnReturn_Click);
			// 
			// btnDTIReport
			// 
			this->btnDTIReport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnDTIReport->Location = System::Drawing::Point(75, 252);
			this->btnDTIReport->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnDTIReport->Name = L"btnDTIReport";
			this->btnDTIReport->Size = System::Drawing::Size(271, 59);
			this->btnDTIReport->TabIndex = 8;
			this->btnDTIReport->Text = L"Llamada al DTI";
			this->btnDTIReport->UseVisualStyleBackColor = true;
			this->btnDTIReport->Click += gcnew System::EventHandler(this, &AlertForm::btnDTIReport_Click);
			// 
			// btnAltercation
			// 
			this->btnAltercation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnAltercation->Location = System::Drawing::Point(75, 169);
			this->btnAltercation->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAltercation->Name = L"btnAltercation";
			this->btnAltercation->Size = System::Drawing::Size(271, 59);
			this->btnAltercation->TabIndex = 7;
			this->btnAltercation->Text = L"Reporte de altercado";
			this->btnAltercation->UseVisualStyleBackColor = true;
			this->btnAltercation->Click += gcnew System::EventHandler(this, &AlertForm::btnAltercation_Click);
			// 
			// btnMissingObject
			// 
			this->btnMissingObject->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnMissingObject->Location = System::Drawing::Point(75, 91);
			this->btnMissingObject->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnMissingObject->Name = L"btnMissingObject";
			this->btnMissingObject->Size = System::Drawing::Size(271, 59);
			this->btnMissingObject->TabIndex = 6;
			this->btnMissingObject->Text = L"Objeto perdido";
			this->btnMissingObject->UseVisualStyleBackColor = true;
			this->btnMissingObject->Click += gcnew System::EventHandler(this, &AlertForm::btnMissingObject_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(116, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(188, 32);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Tipo de alerta";
			// 
			// btnHistReport
			// 
			this->btnHistReport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->btnHistReport->Location = System::Drawing::Point(55, 347);
			this->btnHistReport->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnHistReport->Name = L"btnHistReport";
			this->btnHistReport->Size = System::Drawing::Size(320, 88);
			this->btnHistReport->TabIndex = 10;
			this->btnHistReport->Text = L"Historial de Alertas";
			this->btnHistReport->UseVisualStyleBackColor = true;
			this->btnHistReport->Click += gcnew System::EventHandler(this, &AlertForm::btnHistReport_Click);
			// 
			// AlertForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(428, 581);
			this->Controls->Add(this->btnHistReport);
			this->Controls->Add(this->btnReturn);
			this->Controls->Add(this->btnDTIReport);
			this->Controls->Add(this->btnAltercation);
			this->Controls->Add(this->btnMissingObject);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"AlertForm";
			this->Text = L"AlertForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnMissingObject_Click(System::Object^ sender, System::EventArgs^ e) {
		MissingObjectForm^ form = gcnew MissingObjectForm(Usuario);
		this->Hide();
		form->ShowDialog();
		this->Show();
	}
	private: System::Void btnAltercation_Click(System::Object^ sender, System::EventArgs^ e) {
		AltercationReportForm^ form = gcnew AltercationReportForm(Usuario);
		this->Hide();
		form->ShowDialog();
		this->Show();
	}
	private: System::Void btnDTIReport_Click(System::Object^ sender, System::EventArgs^ e) {
		DTIReportForm^ form = gcnew DTIReportForm(Usuario);
		this->Hide();
		form->ShowDialog();
		this->Show();
	}
	private: System::Void btnReturn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnHistReport_Click(System::Object^ sender, System::EventArgs^ e) {
		AlertHistForm^ form = gcnew AlertHistForm(Usuario);
		this->Hide();
		form->ShowDialog();
		this->Show();
	}
	};
}
