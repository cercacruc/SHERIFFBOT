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
	/// Resumen de DTIReportForm
	/// </summary>
	public ref class DTIReportForm : public System::Windows::Forms::Form
	{
	public:
		DatosUsuario^ Usuario;
		DTIReportForm(DatosUsuario^ usuario)
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
		~DTIReportForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ cbTipoAlerta;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnLlamar;





	private: System::Windows::Forms::TextBox^ txtDescription;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtLugar;
	private: System::Windows::Forms::DateTimePicker^ dtpFecha;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnVolver;

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
			this->cbTipoAlerta = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnLlamar = (gcnew System::Windows::Forms::Button());
			this->txtDescription = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtLugar = (gcnew System::Windows::Forms::TextBox());
			this->dtpFecha = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// cbTipoAlerta
			// 
			this->cbTipoAlerta->FormattingEnabled = true;
			this->cbTipoAlerta->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Necesidades tecnologicas", L"Prestamo de dispositivo",
					L"Proteccion contra ciberdelincuencia", L"Autenticación y acceso a aplicaciones y datos PUCP"
			});
			this->cbTipoAlerta->Location = System::Drawing::Point(141, 76);
			this->cbTipoAlerta->Name = L"cbTipoAlerta";
			this->cbTipoAlerta->Size = System::Drawing::Size(293, 24);
			this->cbTipoAlerta->TabIndex = 27;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(19, 76);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(116, 20);
			this->label4->TabIndex = 26;
			this->label4->Text = L"Tipo de alerta:";
			// 
			// btnLlamar
			// 
			this->btnLlamar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnLlamar->Location = System::Drawing::Point(30, 310);
			this->btnLlamar->Name = L"btnLlamar";
			this->btnLlamar->Size = System::Drawing::Size(193, 47);
			this->btnLlamar->TabIndex = 25;
			this->btnLlamar->Text = L"Llamar";
			this->btnLlamar->UseVisualStyleBackColor = true;
			this->btnLlamar->Click += gcnew System::EventHandler(this, &DTIReportForm::btnLlamar_Click);
			// 
			// txtDescription
			// 
			this->txtDescription->Location = System::Drawing::Point(14, 143);
			this->txtDescription->Multiline = true;
			this->txtDescription->Name = L"txtDescription";
			this->txtDescription->Size = System::Drawing::Size(445, 83);
			this->txtDescription->TabIndex = 21;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(19, 120);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 20);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Descripción:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(106, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(252, 43);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Llamada al DTI";
			// 
			// txtLugar
			// 
			this->txtLugar->Location = System::Drawing::Point(253, 263);
			this->txtLugar->Name = L"txtLugar";
			this->txtLugar->Size = System::Drawing::Size(163, 22);
			this->txtLugar->TabIndex = 48;
			// 
			// dtpFecha
			// 
			this->dtpFecha->Location = System::Drawing::Point(23, 263);
			this->dtpFecha->Name = L"dtpFecha";
			this->dtpFecha->Size = System::Drawing::Size(200, 22);
			this->dtpFecha->TabIndex = 47;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(19, 240);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 20);
			this->label3->TabIndex = 46;
			this->label3->Text = L"Fecha y lugar:";
			// 
			// btnVolver
			// 
			this->btnVolver->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnVolver->Location = System::Drawing::Point(253, 310);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(193, 47);
			this->btnVolver->TabIndex = 24;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &DTIReportForm::btnVolver_Click);
			// 
			// DTIReportForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(477, 369);
			this->Controls->Add(this->txtLugar);
			this->Controls->Add(this->dtpFecha);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->cbTipoAlerta);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnLlamar);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->txtDescription);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"DTIReportForm";
			this->Text = L"DTIReportForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnLlamar_Click(System::Object^ sender, System::EventArgs^ e) {
		DTIReport^ reporte = gcnew DTIReport();
		reporte->Description = txtDescription->Text;
		reporte->Fecha = dtpFecha->Value;
		reporte->tipoReporte = cbTipoAlerta->Text;

		//vincula con usuario
		reporte->UsuarioID = Usuario->ID;
		reporte->UsuarioNombre = Usuario->Nombre;

		reporte->Solucionado = false;

		if (Usuario != nullptr && Usuario->cant_alertas != nullptr) {
			Usuario->cant_alertas[2] += 1;
			Service::modificarUsuarioID(Usuario);
		}

		Service::registrarAlerta(reporte);
		MessageBox::Show("Se ha llamado al DTI", "Exito", MessageBoxButtons::OK);
		ClearFields();
	}
	private: void ClearFields() {
		txtDescription->Text = "";
		txtLugar->Text = "";

		cbTipoAlerta->SelectedIndex = -1;
	}
	};
}
