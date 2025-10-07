#pragma once

namespace SheriffBotGUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de AlertForm
	/// </summary>
	public ref class AlertForm : public System::Windows::Forms::Form
	{
	public:
		AlertForm(void)
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
			this->btnReturn = (gcnew System::Windows::Forms::Button());
			this->btnDTIReport = (gcnew System::Windows::Forms::Button());
			this->btnAltercation = (gcnew System::Windows::Forms::Button());
			this->btnMissingObject = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnReturn
			// 
			this->btnReturn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnReturn->Location = System::Drawing::Point(67, 372);
			this->btnReturn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnReturn->Name = L"btnReturn";
			this->btnReturn->Size = System::Drawing::Size(241, 47);
			this->btnReturn->TabIndex = 9;
			this->btnReturn->Text = L"Volver";
			this->btnReturn->UseVisualStyleBackColor = true;
			// 
			// btnDTIReport
			// 
			this->btnDTIReport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnDTIReport->Location = System::Drawing::Point(67, 265);
			this->btnDTIReport->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnDTIReport->Name = L"btnDTIReport";
			this->btnDTIReport->Size = System::Drawing::Size(241, 47);
			this->btnDTIReport->TabIndex = 8;
			this->btnDTIReport->Text = L"Llamada al DTI";
			this->btnDTIReport->UseVisualStyleBackColor = true;
			// 
			// btnAltercation
			// 
			this->btnAltercation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnAltercation->Location = System::Drawing::Point(67, 190);
			this->btnAltercation->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAltercation->Name = L"btnAltercation";
			this->btnAltercation->Size = System::Drawing::Size(241, 47);
			this->btnAltercation->TabIndex = 7;
			this->btnAltercation->Text = L"Reporte de altercado";
			this->btnAltercation->UseVisualStyleBackColor = true;
			// 
			// btnMissingObject
			// 
			this->btnMissingObject->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnMissingObject->Location = System::Drawing::Point(67, 113);
			this->btnMissingObject->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnMissingObject->Name = L"btnMissingObject";
			this->btnMissingObject->Size = System::Drawing::Size(241, 47);
			this->btnMissingObject->TabIndex = 6;
			this->btnMissingObject->Text = L"Objeto perdido";
			this->btnMissingObject->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(99, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(163, 29);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Tipo de alerta";
			// 
			// AlertForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(380, 465);
			this->Controls->Add(this->btnReturn);
			this->Controls->Add(this->btnDTIReport);
			this->Controls->Add(this->btnAltercation);
			this->Controls->Add(this->btnMissingObject);
			this->Controls->Add(this->label1);
			this->Name = L"AlertForm";
			this->Text = L"AlertForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
