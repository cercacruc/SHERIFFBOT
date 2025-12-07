#pragma once
#include "ControlRobotForm.h"
#include "AsignarAlertaRobotForm.h"
#include "UIStyles.h"   // Para UIHelpers: botones redondeados, etc.

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Collections::Generic;
	using namespace BotModel;
	using namespace BotService;

	/// <summary>
	/// Resumen de RobotsSheriffForm
	/// </summary>
	public ref class RobotsSheriffForm : public System::Windows::Forms::Form
	{
	public:
		RobotsSheriffForm(void)
		{
			InitializeComponent();

			// ---- upgrade visual ----
			ApplyDarkTheme();
			StyleButtonsAndInputs();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~RobotsSheriffForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::ComboBox^ cmbRobots;
		System::Windows::Forms::PictureBox^ pbPhoto;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::TextBox^ txtCaracteristicas;
		System::Windows::Forms::Button^ btnRobots;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::ComboBox^ cmbLugares;
		System::Windows::Forms::Button^ btnControlRobot;
		System::Windows::Forms::Button^ btnSalir;

		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RobotsSheriffForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cmbRobots = (gcnew System::Windows::Forms::ComboBox());
			this->pbPhoto = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtCaracteristicas = (gcnew System::Windows::Forms::TextBox());
			this->btnRobots = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cmbLugares = (gcnew System::Windows::Forms::ComboBox());
			this->btnControlRobot = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhoto))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(181, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Robots Registrados";
			// 
			// cmbRobots
			// 
			this->cmbRobots->FormattingEnabled = true;
			this->cmbRobots->Location = System::Drawing::Point(210, 10);
			this->cmbRobots->Name = L"cmbRobots";
			this->cmbRobots->Size = System::Drawing::Size(227, 24);
			this->cmbRobots->TabIndex = 1;
			this->cmbRobots->SelectedIndexChanged += gcnew System::EventHandler(this, &RobotsSheriffForm::cmbRobots_SelectedIndexChanged);
			// 
			// pbPhoto
			// 
			this->pbPhoto->Location = System::Drawing::Point(17, 48);
			this->pbPhoto->Name = L"pbPhoto";
			this->pbPhoto->Size = System::Drawing::Size(188, 151);
			this->pbPhoto->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbPhoto->TabIndex = 2;
			this->pbPhoto->TabStop = false;
			// borde celeste
			this->pbPhoto->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &RobotsSheriffForm::PictureBoxBorder_Paint);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(211, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(141, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Características";
			// 
			// txtCaracteristicas
			// 
			this->txtCaracteristicas->Location = System::Drawing::Point(216, 77);
			this->txtCaracteristicas->Multiline = true;
			this->txtCaracteristicas->Name = L"txtCaracteristicas";
			this->txtCaracteristicas->Size = System::Drawing::Size(221, 122);
			this->txtCaracteristicas->TabIndex = 4;
			// 
			// btnRobots
			// 
			this->btnRobots->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRobots->Location = System::Drawing::Point(278, 206);
			this->btnRobots->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnRobots->Name = L"btnRobots";
			this->btnRobots->Size = System::Drawing::Size(159, 47);
			this->btnRobots->TabIndex = 14;
			this->btnRobots->Text = L"Enviar";
			this->btnRobots->UseVisualStyleBackColor = true;
			this->btnRobots->Click += gcnew System::EventHandler(this, &RobotsSheriffForm::btnRobots_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 216);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 25);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Lugar: ";
			// 
			// cmbLugares
			// 
			this->cmbLugares->FormattingEnabled = true;
			this->cmbLugares->Location = System::Drawing::Point(91, 221);
			this->cmbLugares->Name = L"cmbLugares";
			this->cmbLugares->Size = System::Drawing::Size(181, 24);
			this->cmbLugares->TabIndex = 17;
			this->cmbLugares->SelectedIndexChanged += gcnew System::EventHandler(this, &RobotsSheriffForm::cmbLugares_SelectedIndexChanged);
			// 
			// btnControlRobot
			// 
			this->btnControlRobot->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnControlRobot->Location = System::Drawing::Point(43, 262);
			this->btnControlRobot->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnControlRobot->Name = L"btnControlRobot";
			this->btnControlRobot->Size = System::Drawing::Size(162, 47);
			this->btnControlRobot->TabIndex = 18;
			this->btnControlRobot->Text = L"CONTROLAR";
			this->btnControlRobot->UseVisualStyleBackColor = true;
			this->btnControlRobot->Click += gcnew System::EventHandler(this, &RobotsSheriffForm::btnControlRobot_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(216, 262);
			this->btnSalir->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(159, 47);
			this->btnSalir->TabIndex = 19;
			this->btnSalir->Text = L"SALIR";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &RobotsSheriffForm::btnSalir_Click);
			// 
			// RobotsSheriffForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(450, 320);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnControlRobot);
			this->Controls->Add(this->cmbLugares);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnRobots);
			this->Controls->Add(this->txtCaracteristicas);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pbPhoto);
			this->Controls->Add(this->cmbRobots);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"RobotsSheriffForm";
			this->Text = L"EnviarRobot";
			this->Load += gcnew System::EventHandler(this, &RobotsSheriffForm::RobotsSheriffForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhoto))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// =============== ESTILO (Dark Theme) ===============

		void ApplyDarkTheme()
		{
			Color back = Color::FromArgb(20, 27, 47);
			Color fore = Color::FromArgb(224, 231, 255);

			this->BackColor = back;

			array<Label^>^ labels = gcnew array<Label^>{
				label1, label2, label3
			};

			for each (Label ^ lb in labels)
			{
				if (lb != nullptr)
				{
					lb->ForeColor = fore;
					lb->BackColor = Color::Transparent;
				}
			}

			if (pbPhoto != nullptr)
				pbPhoto->BackColor = Color::FromArgb(10, 16, 32);
		}

		void StyleComboBox(ComboBox^ cb)
		{
			if (cb == nullptr) return;

			cb->FlatStyle = FlatStyle::Flat;
			cb->DropDownStyle = ComboBoxStyle::DropDownList;
			cb->BackColor = Color::FromArgb(15, 23, 42);
			cb->ForeColor = Color::FromArgb(226, 232, 240);
			cb->DrawMode = DrawMode::OwnerDrawFixed;
			cb->DrawItem += gcnew DrawItemEventHandler(this, &RobotsSheriffForm::ComboBox_DrawItem);
		}

		void StyleButtonsAndInputs()
		{
			// Botones principales (acción): Enviar / Controlar
			array<Button^>^ primary = gcnew array<Button^> {
				btnRobots, btnControlRobot
			};

			for each (Button ^ b in primary)
			{
				if (b == nullptr) continue;
				b->FlatStyle = FlatStyle::Flat;
				b->FlatAppearance->BorderSize = 0;
				b->BackColor = Color::FromArgb(0, 140, 255);
				b->ForeColor = Color::White;
				b->Font = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);
				UIHelpers::SetRoundedRegion(b, 18);
			}

			// Botón secundario: Salir
			array<Button^>^ secondary = gcnew array<Button^> {
				btnSalir
			};

			for each (Button ^ b in secondary)
			{
				if (b == nullptr) continue;
				b->FlatStyle = FlatStyle::Flat;
				b->FlatAppearance->BorderSize = 0;
				b->BackColor = Color::FromArgb(20, 27, 47);
				b->ForeColor = Color::FromArgb(224, 231, 255);
				b->Font = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Regular);
				b->Paint += gcnew PaintEventHandler(&UIHelpers::OutlineButton_Paint);
				UIHelpers::SetRoundedRegion(b, 18);
			}

			// TextBox dark
			Color backBox = Color::FromArgb(10, 16, 32);
			Color foreBox = Color::FromArgb(226, 232, 240);

			if (txtCaracteristicas != nullptr)
			{
				txtCaracteristicas->BackColor = backBox;
				txtCaracteristicas->ForeColor = foreBox;
				txtCaracteristicas->BorderStyle = BorderStyle::FixedSingle;
			}

			// Combos dark
			StyleComboBox(cmbRobots);
			StyleComboBox(cmbLugares);
		}

		// Draw de los combos (dark)
		void ComboBox_DrawItem(System::Object^ sender, DrawItemEventArgs^ e)
		{
			if (e->Index < 0) return;

			ComboBox^ cb = safe_cast<ComboBox^>(sender);
			bool selected = (e->State & DrawItemState::Selected) == DrawItemState::Selected;

			Color back = selected ? Color::FromArgb(37, 99, 235) : Color::FromArgb(15, 23, 42);
			Color fore = Color::FromArgb(226, 232, 240);

			e->Graphics->FillRectangle(gcnew SolidBrush(back), e->Bounds);

			String^ text = cb->Items[e->Index]->ToString();
			e->Graphics->DrawString(
				text,
				cb->Font,
				gcnew SolidBrush(fore),
				RectangleF(
					(float)e->Bounds.X,
					(float)e->Bounds.Y,
					(float)e->Bounds.Width,
					(float)e->Bounds.Height
				)
			);

			e->DrawFocusRectangle();
		}

		// Borde celeste para PictureBox (igual que en otros forms)
		void PictureBoxBorder_Paint(System::Object^ sender, PaintEventArgs^ e)
		{
			PictureBox^ pb = safe_cast<PictureBox^>(sender);
			e->Graphics->SmoothingMode =
				System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

			Rectangle rect = pb->ClientRectangle;
			rect.Inflate(-1, -1);   // margen interno

			Pen^ pen = gcnew Pen(Color::FromArgb(56, 189, 248), 2.0f);
			e->Graphics->DrawRectangle(pen, rect);
			delete pen;
		}

		// =============== LÓGICA ORIGINAL ===============

	private: void CargarListaRobots() {
		List<Robot^>^ robots = Service::GetRobots();
		cmbRobots->Visible = true;
		cmbRobots->Enabled = true;
		cmbRobots->Items->Clear();

		for each (Robot ^ robot in robots) {
			String^ nombreConEstado = robot->Nombre;

			// Solo mostrar "Ocupado" si NO está disponible Y NO está en BASE
			if (!robot->Disponibilidad && robot->Zona->ToUpper() != "BASE") {
				nombreConEstado += " (Ocupado en " + robot->Zona + ")";
			}
			// Si está en BASE, aunque no esté disponible, no mostrar como ocupado
			else if (!robot->Disponibilidad && robot->Zona->ToUpper() == "BASE") {
				nombreConEstado += " (En BASE)";
			}
			// Si está disponible
			else if (robot->Disponibilidad) {
				nombreConEstado += " (Disponible)";
			}

			cmbRobots->Items->Add(nombreConEstado);
		}

		if (cmbRobots->Items->Count > 0 && cmbRobots->SelectedIndex == -1) {
			cmbRobots->SelectedIndex = -1;
		}
	}

	private: System::Void RobotsSheriffForm_Load(System::Object^ sender, System::EventArgs^ e) {
		CargarListaRobots();
		CargarListaLugares();
		txtCaracteristicas->Enabled = false;
	}

	private: System::Void cmbRobots_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cmbRobots->SelectedIndex == -1) return;

		String^ robotLista = cmbRobots->Text;

		// Extraer solo el nombre del robot (sin el estado entre paréntesis)
		String^ nombreRobot = robotLista;
		int indexParentesis = robotLista->IndexOf('(');
		if (indexParentesis > 0) {
			nombreRobot = robotLista->Substring(0, indexParentesis)->Trim();
		}

		Robot^ robotSeleccionado = Service::buscarRobotNombre(nombreRobot);
		if (robotSeleccionado != nullptr) {
			ActualizarCaracteristicasRobot(robotSeleccionado);
			ActualizarFotoRobot(robotSeleccionado);

			// Actualizar el estado del botón de enviar según la disponibilidad
			btnRobots->Enabled = robotSeleccionado->Disponibilidad ||
				(cmbLugares->Text->ToUpper() == "BASE" && !robotSeleccionado->Disponibilidad);
		}
	}

	private: System::Void cmbLugares_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cmbRobots->SelectedIndex == -1) return;

		String^ robotLista = cmbRobots->Text;
		String^ nombreRobot = robotLista;
		int indexParentesis = robotLista->IndexOf('(');
		if (indexParentesis > 0) {
			nombreRobot = robotLista->Substring(0, indexParentesis)->Trim();
		}

		Robot^ robotSeleccionado = Service::buscarRobotNombre(nombreRobot);
		if (robotSeleccionado != nullptr) {
			// Habilitar el botón solo si:
			// - El robot está disponible Y el destino no es BASE
			// - O el robot NO está disponible Y el destino es BASE
			btnRobots->Enabled =
				(robotSeleccionado->Disponibilidad && cmbLugares->Text->ToUpper() != "BASE") ||
				(!robotSeleccionado->Disponibilidad && cmbLugares->Text->ToUpper() == "BASE");
		}
	}

	private: void ActualizarCaracteristicasRobot(Robot^ robot) {
		txtCaracteristicas->Text = robot->Caracteristicas;
	}

	private: void ActualizarFotoRobot(Robot^ robot) {
		if (robot->Photo != nullptr) {
			System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(robot->Photo);
			pbPhoto->Image = Image::FromStream(ms);
		}
		else {
			pbPhoto->Image = nullptr;
			pbPhoto->Invalidate();
		}
	}

	private: System::Void btnRobots_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ lugarDestino = cmbLugares->Text;
		String^ robotElegido = cmbRobots->Text;

		// Validar selecciones
		if (String::IsNullOrEmpty(robotElegido)) {
			MessageBox::Show("Por favor seleccione un robot", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (String::IsNullOrEmpty(lugarDestino)) {
			MessageBox::Show("Por favor seleccione un lugar", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		String^ nombreRobot = robotElegido;
		int indexParentesis = robotElegido->IndexOf('(');
		if (indexParentesis > 0) {
			nombreRobot = robotElegido->Substring(0, indexParentesis)->Trim();
		}

		Robot^ robot = Service::buscarRobotNombre(nombreRobot);

		if (robot == nullptr) {
			MessageBox::Show("Robot no encontrado", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Si el destino es BASE
		if (lugarDestino->ToUpper() == "BASE") {
			robot->Zona = lugarDestino;
			robot->Disponibilidad = true; // Siempre disponible en BASE
			robot->AlertaAsignadaID = 0;  // Limpiar alerta asignada si existe
			robot->TipoMision = "";       // Limpiar misión

			Service::modificarRobotID(robot);

			String^ mensaje = String::Format("{0} ha regresado a la BASE y está disponible", robot->Nombre);
			MessageBox::Show(mensaje, "Éxito", MessageBoxButtons::OK);
		}
		// Si el destino NO es BASE
		else {
			// Verificar si el robot está disponible
			if (robot->Disponibilidad) {
				robot->Zona = lugarDestino;
				robot->Disponibilidad = false; // Ocupado en misión
				Service::modificarRobotID(robot);

				String^ mensaje = String::Format("Se ha enviado a {0} a {1}", robot->Nombre, lugarDestino);
				MessageBox::Show(mensaje, "Éxito", MessageBoxButtons::OK);
			}
			else {
				// Si el robot no está disponible
				MessageBox::Show(
					"El robot no está disponible. Solo puede ser enviado a BASE para liberarlo.",
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}

		// Actualizar la interfaz
		ActualizarCaracteristicasRobot(robot);
		cmbRobots->SelectedIndex = -1;
		cmbLugares->SelectedIndex = -1;
		CargarListaRobots(); // Recargar lista con estados actualizados
	}

	private: void CargarListaLugares() {
		List<ZonaTrabajo^>^ listaLugares = Service::GetZonas();
		cmbLugares->Visible = true;
		cmbLugares->Enabled = true;
		cmbLugares->Items->Clear();

		for each (ZonaTrabajo ^ zona in listaLugares) {
			cmbLugares->Items->Add(zona->zona);
		}
	}

	private: System::Void btnControlRobot_Click(System::Object^ sender, System::EventArgs^ e) {
		if (cmbRobots->SelectedIndex == -1) {
			MessageBox::Show("Por favor seleccione un robot primero", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		String^ robotLista = cmbRobots->Text;
		String^ nombreRobot = robotLista;

		// Extraer solo el nombre del robot (sin el estado entre paréntesis)
		int indexParentesis = robotLista->IndexOf('(');
		if (indexParentesis > 0) {
			nombreRobot = robotLista->Substring(0, indexParentesis)->Trim();
		}

		Robot^ robotEncontrado = Service::buscarRobotNombre(nombreRobot);

		if (robotEncontrado != nullptr) {
			ControlRobotForm^ controlRobot = gcnew ControlRobotForm(robotEncontrado);
			this->Hide();
			controlRobot->ShowDialog();
			this->Show();

			// Recargar la lista después de controlar el robot
			CargarListaRobots();

			// Limpiar selecciones
			cmbRobots->SelectedIndex = -1;
			cmbLugares->SelectedIndex = -1;
			pbPhoto->Image = nullptr;
			txtCaracteristicas->Clear();
		}
		else {
			MessageBox::Show("Robot no encontrado", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
