#pragma once

namespace SheriffBotGUIApp {

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
	/// Resumen de AlertHistForm
	/// </summary>
	public ref class AlertHistForm : public System::Windows::Forms::Form
	{
	public:
		DatosUsuario^ Usuario;

		AlertHistForm(DatosUsuario^ usuario)
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
		~AlertHistForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dgvAlertHist;





	private: System::Windows::Forms::Button^ btnShowAlert;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ X1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ X2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Y1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Y2;





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
			this->dgvAlertHist = (gcnew System::Windows::Forms::DataGridView());
			this->btnShowAlert = (gcnew System::Windows::Forms::Button());
			this->ID1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->X1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->X2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Y1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Y2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAlertHist))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvAlertHist
			// 
			this->dgvAlertHist->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvAlertHist->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->ID1, this->X1,
					this->X2, this->Y1, this->Y2
			});
			this->dgvAlertHist->Location = System::Drawing::Point(12, 114);
			this->dgvAlertHist->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dgvAlertHist->Name = L"dgvAlertHist";
			this->dgvAlertHist->RowHeadersVisible = false;
			this->dgvAlertHist->RowHeadersWidth = 51;
			this->dgvAlertHist->RowTemplate->Height = 24;
			this->dgvAlertHist->Size = System::Drawing::Size(676, 326);
			this->dgvAlertHist->TabIndex = 16;
			this->dgvAlertHist->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AlertHistForm::dgvAlertHist_CellContentClick);
			// 
			// btnShowAlert
			// 
			this->btnShowAlert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnShowAlert->Location = System::Drawing::Point(242, 27);
			this->btnShowAlert->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnShowAlert->Name = L"btnShowAlert";
			this->btnShowAlert->Size = System::Drawing::Size(223, 58);
			this->btnShowAlert->TabIndex = 17;
			this->btnShowAlert->Text = L"Mostrar Alertas";
			this->btnShowAlert->UseVisualStyleBackColor = true;
			this->btnShowAlert->Click += gcnew System::EventHandler(this, &AlertHistForm::btnShowAlert_Click);
			// 
			// ID1
			// 
			this->ID1->HeaderText = L"Tipo de Alerta";
			this->ID1->MinimumWidth = 6;
			this->ID1->Name = L"ID1";
			this->ID1->Width = 125;
			// 
			// X1
			// 
			this->X1->HeaderText = L"Descripción";
			this->X1->MinimumWidth = 6;
			this->X1->Name = L"X1";
			this->X1->Width = 125;
			// 
			// X2
			// 
			this->X2->HeaderText = L"Fecha";
			this->X2->MinimumWidth = 6;
			this->X2->Name = L"X2";
			this->X2->Width = 125;
			// 
			// Y1
			// 
			this->Y1->HeaderText = L"Hora";
			this->Y1->MinimumWidth = 6;
			this->Y1->Name = L"Y1";
			this->Y1->Width = 125;
			// 
			// Y2
			// 
			this->Y2->HeaderText = L"Estado";
			this->Y2->MinimumWidth = 6;
			this->Y2->Name = L"Y2";
			this->Y2->Width = 125;
			// 
			// AlertHistForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(708, 463);
			this->Controls->Add(this->btnShowAlert);
			this->Controls->Add(this->dgvAlertHist);
			this->Name = L"AlertHistForm";
			this->Text = L"Historial de Alertas";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAlertHist))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dgvAlertHist_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void btnShowAlert_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			List<Alert^>^ listaAlertas = BotPersistance::Persistance::ShowAlertas();

			dgvAlertHist->Rows->Clear();

			if (listaAlertas == nullptr || listaAlertas->Count == 0) {
				MessageBox::Show("No hay alertas registradas.", "Información",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			for each (Alert ^ alerta in listaAlertas) {
				String^ estado = alerta->Solucionado ? "Solucionado" : "Pendiente";

				if (String::IsNullOrEmpty(alerta->TipoAlerta)) {
					if (dynamic_cast<DTIReport^>(alerta) != nullptr)
						alerta->TipoAlerta = "DTI Reporte";
					else if (dynamic_cast<Altercado^>(alerta) != nullptr)
						alerta->TipoAlerta = "Altercado";
					else if (dynamic_cast<ObjPerdido^>(alerta) != nullptr)
						alerta->TipoAlerta = "Objeto Perdido";
					else
						alerta->TipoAlerta = "General";
				}

				dgvAlertHist->Rows->Add(
					alerta->TipoAlerta,                        
					alerta->Description,                       
					alerta->Fecha->ToString("dd/MM/yyyy"),     
					alerta->Fecha->ToString("HH:mm"),          
					estado                                     
				);
			}

			MessageBox::Show("Alertas cargadas correctamente.", "Información",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al cargar alertas: " + ex->Message,
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
