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
	/// Resumen de DelimitarZonasTrabajoAdmin
	/// </summary>
	public ref class DelimitarZonasTrabajoAdmin : public System::Windows::Forms::Form
	{
	public:
		DelimitarZonasTrabajoAdmin(void)
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
		~DelimitarZonasTrabajoAdmin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ idZona;
	private: System::Windows::Forms::TextBox^ textX1;
	private: System::Windows::Forms::TextBox^ textX2;
	private: System::Windows::Forms::TextBox^ textY1;
	private: System::Windows::Forms::TextBox^ textY2;
	private: System::Windows::Forms::TextBox^ textZona;







	private: System::Windows::Forms::Button^ btnAddZona;
	private: System::Windows::Forms::Button^ btnModificarZona;
	private: System::Windows::Forms::Button^ btnEliminarZona;
	private: System::Windows::Forms::DataGridView^ dgvZona;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ X1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ X2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Y1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Y2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ZonaTRA;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DelimitarZonasTrabajoAdmin::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->idZona = (gcnew System::Windows::Forms::TextBox());
			this->textX1 = (gcnew System::Windows::Forms::TextBox());
			this->textX2 = (gcnew System::Windows::Forms::TextBox());
			this->textY1 = (gcnew System::Windows::Forms::TextBox());
			this->textY2 = (gcnew System::Windows::Forms::TextBox());
			this->textZona = (gcnew System::Windows::Forms::TextBox());
			this->btnAddZona = (gcnew System::Windows::Forms::Button());
			this->btnModificarZona = (gcnew System::Windows::Forms::Button());
			this->btnEliminarZona = (gcnew System::Windows::Forms::Button());
			this->dgvZona = (gcnew System::Windows::Forms::DataGridView());
			this->ID1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->X1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->X2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Y1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Y2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ZonaTRA = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvZona))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(29, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"X minimo";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(29, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"X máximo";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(29, 158);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 16);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Y mínimo";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(29, 198);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 16);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Y máximo";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(32, 242);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(45, 16);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Zonas";
			// 
			// idZona
			// 
			this->idZona->Location = System::Drawing::Point(122, 26);
			this->idZona->Name = L"idZona";
			this->idZona->Size = System::Drawing::Size(168, 22);
			this->idZona->TabIndex = 6;
			// 
			// textX1
			// 
			this->textX1->Location = System::Drawing::Point(122, 72);
			this->textX1->Name = L"textX1";
			this->textX1->Size = System::Drawing::Size(168, 22);
			this->textX1->TabIndex = 7;
			// 
			// textX2
			// 
			this->textX2->Location = System::Drawing::Point(122, 112);
			this->textX2->Name = L"textX2";
			this->textX2->Size = System::Drawing::Size(168, 22);
			this->textX2->TabIndex = 8;
			// 
			// textY1
			// 
			this->textY1->Location = System::Drawing::Point(122, 158);
			this->textY1->Name = L"textY1";
			this->textY1->Size = System::Drawing::Size(168, 22);
			this->textY1->TabIndex = 9;
			// 
			// textY2
			// 
			this->textY2->Location = System::Drawing::Point(122, 198);
			this->textY2->Name = L"textY2";
			this->textY2->Size = System::Drawing::Size(168, 22);
			this->textY2->TabIndex = 10;
			// 
			// textZona
			// 
			this->textZona->Location = System::Drawing::Point(122, 242);
			this->textZona->Name = L"textZona";
			this->textZona->Size = System::Drawing::Size(168, 22);
			this->textZona->TabIndex = 11;
			// 
			// btnAddZona
			// 
			this->btnAddZona->Location = System::Drawing::Point(356, 39);
			this->btnAddZona->Name = L"btnAddZona";
			this->btnAddZona->Size = System::Drawing::Size(149, 55);
			this->btnAddZona->TabIndex = 12;
			this->btnAddZona->Text = L"Agregar";
			this->btnAddZona->UseVisualStyleBackColor = true;
			this->btnAddZona->Click += gcnew System::EventHandler(this, &DelimitarZonasTrabajoAdmin::btnAddZona_Click);
			// 
			// btnModificarZona
			// 
			this->btnModificarZona->Location = System::Drawing::Point(356, 115);
			this->btnModificarZona->Name = L"btnModificarZona";
			this->btnModificarZona->Size = System::Drawing::Size(149, 59);
			this->btnModificarZona->TabIndex = 13;
			this->btnModificarZona->Text = L"Modificar";
			this->btnModificarZona->UseVisualStyleBackColor = true;
			this->btnModificarZona->Click += gcnew System::EventHandler(this, &DelimitarZonasTrabajoAdmin::btnModificarZona_Click);
			// 
			// btnEliminarZona
			// 
			this->btnEliminarZona->Location = System::Drawing::Point(356, 196);
			this->btnEliminarZona->Name = L"btnEliminarZona";
			this->btnEliminarZona->Size = System::Drawing::Size(149, 62);
			this->btnEliminarZona->TabIndex = 14;
			this->btnEliminarZona->Text = L"Eliminar";
			this->btnEliminarZona->UseVisualStyleBackColor = true;
			this->btnEliminarZona->Click += gcnew System::EventHandler(this, &DelimitarZonasTrabajoAdmin::btnEliminarZona_Click);
			// 
			// dgvZona
			// 
			this->dgvZona->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvZona->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->ID1, this->X1,
					this->X2, this->Y1, this->Y2, this->ZonaTRA
			});
			this->dgvZona->Location = System::Drawing::Point(32, 292);
			this->dgvZona->Name = L"dgvZona";
			this->dgvZona->RowHeadersVisible = false;
			this->dgvZona->RowHeadersWidth = 51;
			this->dgvZona->RowTemplate->Height = 24;
			this->dgvZona->Size = System::Drawing::Size(493, 246);
			this->dgvZona->TabIndex = 15;
			this->dgvZona->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DelimitarZonasTrabajoAdmin::dgvZona_CellContentClick);
			// 
			// ID1
			// 
			this->ID1->HeaderText = L"ID";
			this->ID1->MinimumWidth = 6;
			this->ID1->Name = L"ID1";
			this->ID1->Width = 125;
			// 
			// X1
			// 
			this->X1->HeaderText = L"X_min";
			this->X1->MinimumWidth = 6;
			this->X1->Name = L"X1";
			this->X1->Width = 125;
			// 
			// X2
			// 
			this->X2->HeaderText = L"X_máx";
			this->X2->MinimumWidth = 6;
			this->X2->Name = L"X2";
			this->X2->Width = 125;
			// 
			// Y1
			// 
			this->Y1->HeaderText = L"Y_mín";
			this->Y1->MinimumWidth = 6;
			this->Y1->Name = L"Y1";
			this->Y1->Width = 125;
			// 
			// Y2
			// 
			this->Y2->HeaderText = L"Y_Máx";
			this->Y2->MinimumWidth = 6;
			this->Y2->Name = L"Y2";
			this->Y2->Width = 125;
			// 
			// ZonaTRA
			// 
			this->ZonaTRA->HeaderText = L"Zona";
			this->ZonaTRA->MinimumWidth = 6;
			this->ZonaTRA->Name = L"ZonaTRA";
			this->ZonaTRA->Width = 125;
			// 
			// DelimitarZonasTrabajoAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(564, 564);
			this->Controls->Add(this->dgvZona);
			this->Controls->Add(this->btnEliminarZona);
			this->Controls->Add(this->btnModificarZona);
			this->Controls->Add(this->btnAddZona);
			this->Controls->Add(this->textZona);
			this->Controls->Add(this->textY2);
			this->Controls->Add(this->textY1);
			this->Controls->Add(this->textX2);
			this->Controls->Add(this->textX1);
			this->Controls->Add(this->idZona);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"DelimitarZonasTrabajoAdmin";
			this->Text = L"DelimitarZonasTrabajoAdmin";
			this->Load += gcnew System::EventHandler(this, &DelimitarZonasTrabajoAdmin::DelimitarZonasTrabajoAdmin_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvZona))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnAddZona_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (String::IsNullOrEmpty(idZona->Text) || String::IsNullOrEmpty(textX1->Text) || String::IsNullOrEmpty(textX2->Text)
				|| String::IsNullOrEmpty(textY1->Text) || String::IsNullOrEmpty(textY2->Text) || String::IsNullOrEmpty(textZona->Text)) {
				MessageBox::Show("Por favor, complete todos los campos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			ZonaTrabajo^ zonaT = gcnew ZonaTrabajo();

			zonaT->ID = Convert::ToInt32(idZona->Text);
			zonaT->x_min = Convert::ToDouble(textX1->Text);
			zonaT->x_max = Convert::ToDouble(textX2->Text);//ver luego su función que de eso

			zonaT->y_min = Convert::ToDouble(textY1->Text);
			zonaT->y_max = Convert::ToDouble(textY2->Text);

			zonaT->zona = textZona->Text;

			int id = Convert::ToInt32(idZona->Text);
			if (Service::buscarZonaID(id)) {
				MessageBox::Show("La zona ya existe.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			Service::registrarZona(zonaT);
			MessageBox::Show("Zona agregada exitosamente", "Exito", MessageBoxButtons::OK);

			ShowZonas();
			ClearFieldsZona();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al agregar Zona: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnModificarZona_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (String::IsNullOrEmpty(idZona->Text)) {
				MessageBox::Show("Ingrese el id de la zona a modificar", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			ZonaTrabajo^ zonaT = gcnew ZonaTrabajo();

			zonaT->ID = Convert::ToInt32(idZona->Text);
			zonaT->x_min = Convert::ToDouble(textX1->Text);
			zonaT->x_max = Convert::ToDouble(textX2->Text);//ver luego su función que de eso

			zonaT->y_min = Convert::ToDouble(textY1->Text);
			zonaT->y_max = Convert::ToDouble(textY2->Text);

			zonaT->zona = textZona->Text;

			int zonModificar = Service::modificarZona(zonaT);
			if (zonModificar != 0) {
				ShowZonas();
				ClearFieldsZona();
				MessageBox::Show("Zona modificada exitosamente", "Exito", MessageBoxButtons::OK);
			}
			else {
				MessageBox::Show("No se encontró la zona", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (System::FormatException^) {
			MessageBox::Show("Por favor, ingrese valores válidos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al modificar la zona: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnEliminarZona_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ zonaId = idZona->Text->Trim();
		if (idZona->Equals("")) {
			MessageBox::Show("Debe seleccionar una zona");
			return;
		}
		try {
			System::Windows::Forms::DialogResult dlgResult = MessageBox::Show("¿Desea eliminar la zona?",
				"Confirmación", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			if (dlgResult == System::Windows::Forms::DialogResult::Yes) {
				bool eliminado = Service::eliminarZona(Convert::ToInt32(zonaId));
				if (eliminado) {
					ShowZonas();
					ClearFieldsZona();
					MessageBox::Show("Zona eliminada exitosamente", "Exito", MessageBoxButtons::OK);
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al eliminar la zona: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void dgvZona_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int ZonaId = Int32::Parse(dgvZona->Rows[dgvZona->SelectedCells[0]->RowIndex]->Cells[0]->Value->ToString());
		ZonaTrabajo^ ZonaT = Service::buscarReturnZonaId(ZonaId);
		if (ZonaT != nullptr) {
			idZona->Text = Convert::ToString(ZonaT->ID);
			textX1->Text = Convert::ToString(ZonaT->x_min);
			textX2->Text = Convert::ToString(ZonaT->x_max);
			textY1->Text = Convert::ToString(ZonaT->y_min);
			textY2->Text = Convert::ToString(ZonaT->y_max);
			textZona->Text = Convert::ToString(ZonaT->zona);
		}
	}
	private: void ShowZonas() {
		List<ZonaTrabajo^>^ zonaT = Service::GetZonas();
		if (zonaT != nullptr) {
			dgvZona->Rows->Clear();
			for (int i = 0; i < zonaT->Count; i++) {
				dgvZona->Rows->Add(gcnew array<String^>{
					Convert::ToString(zonaT[i]->ID),
						Convert::ToString(zonaT[i]->x_min),
						Convert::ToString(zonaT[i]->x_max),
						Convert::ToString(zonaT[i]->y_min),
						Convert::ToString(zonaT[i]->y_max),
						zonaT[i]->zona
				});
			}
		}
	}
	private:
		void ClearFieldsZona() {
			idZona->Text = "";
			textX1->Text = "";
			textX2->Text = "";
			textY1->Text = "";
			textY2->Text = "";
			textZona->Text = "";
		}

	private: System::Void DelimitarZonasTrabajoAdmin_Load(System::Object^ sender, System::EventArgs^ e) {
		ShowZonas();
		ClearFieldsZona();
	}
	};
}
