#pragma once
#include "UIStyles.h"

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
	using namespace System::Threading;

	/// <summary>
	/// Resumen de GraficoBarras
	/// </summary>
	public ref class GraficsAdminForm : public System::Windows::Forms::Form
	{
	public:
		GraficsAdminForm(void)
		{
			InitializeComponent();
			ApplyDarkTheme();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~GraficsAdminForm()
		{
			if (components)
			{
				delete components;
			}
			StopTimer();
		}


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnSalir;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GraficsAdminForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 53);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(760, 477);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GraficsAdminForm::pictureBox1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(225, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(328, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Cantidad de registros en sistema";
			// 
			// btnSalir
			// 
			this->btnSalir->Location = System::Drawing::Point(12, 12);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(100, 30);
			this->btnSalir->TabIndex = 5;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &GraficsAdminForm::btnSalir_Click);
			// 
			// GraficsAdminForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 542);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GraficsAdminForm";
			this->Text = L"Gráfico de Barras - Registros en Sistema";
			this->Load += gcnew System::EventHandler(this, &GraficsAdminForm::GraficsAdminForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion
	private:
		void ApplyDarkTheme()
		{
			// Form
			this->BackColor = Color::FromArgb(20, 27, 47);
			this->ForeColor = Color::FromArgb(226, 232, 240);
			this->StartPosition = FormStartPosition::CenterScreen;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;

			// Área del gráfico (lienzo blanco)
			this->pictureBox1->BackColor = Color::White;
			this->pictureBox1->BorderStyle = BorderStyle::FixedSingle;

			// Título
			this->label1->ForeColor = Color::FromArgb(241, 245, 249);
			this->label1->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);

			// Botón "Salir" como PRIMARIO
			this->btnSalir->FlatStyle = FlatStyle::Flat;
			this->btnSalir->FlatAppearance->BorderSize = 0;
			this->btnSalir->BackColor = Color::FromArgb(0, 140, 255);
			this->btnSalir->ForeColor = Color::White;
			this->btnSalir->Font = gcnew Drawing::Font("Segoe UI", 9, FontStyle::Bold);
			UIHelpers::SetRoundedRegionAuto(this->btnSalir);
		}

		private:
			bool debeMostrarGrafico = false;
			List<DatosUsuario^>^ listaUsuarios;
			List<Robot^>^ listaRobots;

		private: System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
			debeMostrarGrafico = false;
			listaUsuarios = nullptr;
			listaRobots = nullptr;
			pictureBox1->Invalidate();
		}

		private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			Graphics^ g = e->Graphics;

			Color chartBg = Color::FromArgb(15, 23, 42);
			Color emptyText = Color::FromArgb(148, 163, 184);

			g->Clear(chartBg);
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

			if (!debeMostrarGrafico || listaUsuarios == nullptr || listaUsuarios->Count == 0) {
				Brush^ textoBrush = gcnew SolidBrush(emptyText);
				System::Drawing::Font^ font = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Italic);
				String^ mensaje = "Presione 'Generar Gráfico' para ver los datos";
				SizeF textSize = g->MeasureString(mensaje, font);

				float x = (pictureBox1->Width - textSize.Width) / 2;
				float y = (pictureBox1->Height - textSize.Height) / 2;

				g->DrawString(mensaje, font, textoBrush, x, y);

				delete textoBrush;
				delete font;
				return;
			}

			try {
				DibujarGraficoBarras_Usuarios(g, pictureBox1->Width, pictureBox1->Height);
			}
			catch (Exception^) {
				Brush^ errorBrush = gcnew SolidBrush(Color::FromArgb(248, 113, 113));
				System::Drawing::Font^ errorFont = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);
				g->DrawString("Error al dibujar el gráfico", errorFont, errorBrush, 10, 10);

				delete errorBrush;
				delete errorFont;
			}
		}

		private: void DibujarGraficoBarras_Usuarios(Graphics^ g, int width, int height) {
			// Paleta
			Color chartBg = Color::FromArgb(15, 23, 42);
			Color gridColor = Color::FromArgb(55, 65, 81);
			Color axisColor = Color::FromArgb(148, 163, 184);
			Color labelColor = Color::FromArgb(226, 232, 240);
			Color titleColor = Color::FromArgb(248, 250, 252);
			Color totalColor = Color::FromArgb(52, 211, 153);
			Color userBarCol = Color::FromArgb(59, 130, 246);  
			Color robotBarCol = Color::FromArgb(172, 138, 230);

			int margenIzquierdo = 80;
			int margenDerecho = 40;
			int margenSuperior = 60;
			int margenInferior = 80;

			int areaGraficoWidth = width - margenIzquierdo - margenDerecho;
			int areaGraficoHeight = height - margenSuperior - margenInferior;

			int cant_robots = listaRobots->Count;
			int cant_usuarios = listaUsuarios->Count;
			int maxcantidad = Math::Max(cant_robots, cant_usuarios);
			int cant_total = cant_robots + cant_usuarios;

			if (maxcantidad == 0) maxcantidad = 1;

			// Título
			Brush^ tituloBrush = gcnew SolidBrush(titleColor);
			System::Drawing::Font^ tituloFont = gcnew System::Drawing::Font("Segoe UI", 14, FontStyle::Bold);
			String^ titulo = "Cantidad de Usuarios y Robots Registrados";
			SizeF tituloSize = g->MeasureString(titulo, tituloFont);
			g->DrawString(titulo, tituloFont, tituloBrush, (width - tituloSize.Width) / 2, 10);
			delete tituloBrush;
			delete tituloFont;

			// Ejes
			Pen^ ejePen = gcnew Pen(axisColor, 2);
			g->DrawLine(ejePen, margenIzquierdo, margenSuperior,
				margenIzquierdo, margenSuperior + areaGraficoHeight);
			g->DrawLine(ejePen, margenIzquierdo, margenSuperior + areaGraficoHeight,
				margenIzquierdo + areaGraficoWidth, margenSuperior + areaGraficoHeight);

			int numBarras = 2;
			int anchoBarra = areaGraficoWidth / (numBarras + 2);
			int espacioEntreBarras = anchoBarra / 3;
			int anchoBarraReal = anchoBarra - espacioEntreBarras;

			for (int i = 0; i < numBarras; i++) {
				int cantidad = (i == 0) ? cant_usuarios : cant_robots;

				int x = margenIzquierdo + (i * anchoBarra) + espacioEntreBarras;
				int alturaBarra = (int)((cantidad / (double)maxcantidad) * areaGraficoHeight);
				int y = margenSuperior + areaGraficoHeight - alturaBarra;

				Color colorBarra = (i == 0) ? userBarCol : robotBarCol;
				Brush^ barraBrush = gcnew SolidBrush(colorBarra);
				g->FillRectangle(barraBrush, x, y, anchoBarraReal, alturaBarra);

				Pen^ bordePen = gcnew Pen(Color::FromArgb(15, 23, 42), 1);
				g->DrawRectangle(bordePen, x, y, anchoBarraReal, alturaBarra);

				// Cantidad
				Brush^ textoBrush = gcnew SolidBrush(Color::White);
				System::Drawing::Font^ textoFont = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);
				String^ etiquetaCantidad = cantidad.ToString();
				SizeF textoSize = g->MeasureString(etiquetaCantidad, textoFont);

				float textoX = x + (anchoBarraReal - textoSize.Width) / 2;
				float textoY;

				if (alturaBarra > textoSize.Height + 4) {
					textoY = y + (alturaBarra - textoSize.Height) / 2;
				}
				else {
					textoY = y - textoSize.Height - 2;
					delete textoBrush;
					textoBrush = gcnew SolidBrush(labelColor);
				}

				g->DrawString(etiquetaCantidad, textoFont, textoBrush, textoX, textoY);

				// Nombre eje X
				Brush^ nombreBrush = gcnew SolidBrush(labelColor);
				System::Drawing::Font^ nombreFont = gcnew System::Drawing::Font("Segoe UI", 9);
				String^ nombre = (i == 0) ? "Usuario" : "Robot";

				SizeF nombreSize = g->MeasureString(nombre, nombreFont);
				float nombreX = x + (anchoBarraReal - nombreSize.Width) / 2;
				float nombreY = margenSuperior + areaGraficoHeight + 5;
				g->DrawString(nombre, nombreFont, nombreBrush, nombreX, nombreY);

				delete barraBrush;
				delete bordePen;
				delete textoBrush;
				delete textoFont;
				delete nombreBrush;
				delete nombreFont;
			}

			// Escala Y
			Brush^ escalaBrush = gcnew SolidBrush(axisColor);
			System::Drawing::Font^ escalaFont = gcnew System::Drawing::Font("Segoe UI", 8);
			Pen^ lineaEscalaPen = gcnew Pen(gridColor, 1);

			int numLineasEscala = 10;
			for (int i = 0; i <= numLineasEscala; i++) {
				double valor = (i / (double)numLineasEscala) * maxcantidad;
				int y = margenSuperior + areaGraficoHeight -
					(int)((i / (double)numLineasEscala) * areaGraficoHeight);

				g->DrawLine(lineaEscalaPen, margenIzquierdo, y,
					margenIzquierdo + areaGraficoWidth, y);

				String^ etiquetaValor = valor.ToString("F0");
				SizeF etiquetaSize = g->MeasureString(etiquetaValor, escalaFont);
				g->DrawString(etiquetaValor, escalaFont, escalaBrush,
					margenIzquierdo - etiquetaSize.Width - 5, y - etiquetaSize.Height / 2);
			}

			// Eje Y
			System::Drawing::Font^ ejeYFont = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);
			String^ etiquetaEjeY = "Registros";
			SizeF ejeYSize = g->MeasureString(etiquetaEjeY, ejeYFont);
			g->TranslateTransform(20, margenSuperior + areaGraficoHeight / 2);
			g->RotateTransform(-90);
			g->DrawString(etiquetaEjeY, ejeYFont, escalaBrush, -ejeYSize.Height / 2, 0);
			g->ResetTransform();

			// Eje X
			System::Drawing::Font^ ejeXFont = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);
			String^ etiquetaEjeX = "Registrados";
			SizeF ejeXSize = g->MeasureString(etiquetaEjeX, ejeXFont);
			g->DrawString(etiquetaEjeX, ejeXFont, escalaBrush,
				margenIzquierdo + (areaGraficoWidth - ejeXSize.Width) / 2,
				margenSuperior + areaGraficoHeight + 30);

			// Total
			Brush^ totalBrush = gcnew SolidBrush(totalColor);
			System::Drawing::Font^ totalFont = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);
			String^ totalTexto = String::Format("Total de registros: {0}", cant_total);
			g->DrawString(totalTexto, totalFont, totalBrush, margenIzquierdo, 35);

			delete ejePen;
			delete escalaBrush;
			delete escalaFont;
			delete lineaEscalaPen;
			delete ejeYFont;
			delete ejeXFont;
			delete totalBrush;
			delete totalFont;
		}

		private: void CargarDatos() {
			try {
				// Obtener todas las máquinas
				listaUsuarios = Service::GetUsuarios();
				listaRobots = Service::GetRobots();

				if (listaUsuarios == nullptr || listaUsuarios->Count == 0) {
					MessageBox::Show("No hay usuarios registrados.", "Información",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}
				if (listaRobots == nullptr || listaRobots->Count == 0) {
					MessageBox::Show("No hay robots registrados.", "Información",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}

				debeMostrarGrafico = true;
				pictureBox1->Invalidate();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al generar el gráfico: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		Thread^ myThread;
		delegate void MyDelegate(String^);
		private: void CargarHoraRealTime() {
			String^ title = "Gráficos de Usuarios y Robots registrados - ";
			while (true)
			{
				try {
					myThread->Sleep(1000);
					Invoke(gcnew MyDelegate(this, &GraficsAdminForm::UpdateTitle), title + DateTime::Now);
				}
				catch (Exception^ ex) {
					return;
				}
			}
		}
		private: void UpdateTitle(String^ newTitle) {
			this->Text = newTitle;
		}
		private: System::Void GraficsAdminForm_Load(System::Object^ sender, System::EventArgs^ e) {
			CargarDatos();
			InitializateTimer();
			StartTimer();
			myThread = gcnew Thread(gcnew ThreadStart(this, &GraficsAdminForm::CargarHoraRealTime));
			myThread->Start();
		}
		private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
		private:
			Thread^ timer;
			bool timerRunning;
			int currentInterval;
			int elapsedTime;
			Object^ lockObject;

			delegate void UpdateDataDelegate();
		private: void InitializateTimer() {
			lockObject = gcnew Object();
			timerRunning = false;
			currentInterval = 0;
			elapsedTime = 0;
		}
		private: void StartTimer() {
			StopTimer();

			Monitor::Enter(lockObject);
			try {
				timerRunning = true;

				currentInterval = 10 * 1000;
				elapsedTime = 0;
			}
			finally {
				Monitor::Exit(lockObject);
			}

			timer = gcnew Thread(gcnew ThreadStart(this, &GraficsAdminForm::TimerMethod));
			timer->IsBackground = true;
			timer->Start();
		}
		private: void StopTimer() {
			Monitor::Enter(lockObject);
			try {
				timerRunning = false;
			}
			finally {
				Monitor::Exit(lockObject);
			}
			if (timer != nullptr && timer->IsAlive) {
				if (!timer->Join(500)) {
					try {
						timer->Abort();
					}
					catch (ThreadAbortException^) {
						Thread::ResetAbort();
					}
					timer = nullptr;
				}
			}
		}
		private: void TimerMethod() {
			int updateInterval = 100;

			try {
				while (true)
				{
					Monitor::Enter(lockObject);
					bool shouldStop = !timerRunning;
					bool timerCompleted = (elapsedTime >= currentInterval);
					Monitor::Exit(lockObject);

					if (shouldStop) break;
					if (timerCompleted) break;

					Thread::Sleep(updateInterval);

					Monitor::Enter(lockObject);
					try {
						if (timerRunning) {
							elapsedTime += updateInterval;
							int remainingTime = currentInterval - elapsedTime;
						}
					}
					finally {
						Monitor::Exit(lockObject);
					}
				}

				bool shouldRefresh = false;
				Monitor::Enter(lockObject);
				try {
					shouldRefresh = timerRunning && (elapsedTime >= currentInterval);
				}
				finally {
					Monitor::Exit(lockObject);
				}
				if (shouldRefresh) {
					RefreshData();
				}
			}
			catch (ThreadAbortException^) {
				Thread::ResetAbort();
			}
			catch (Exception^ ex) {
				System::Diagnostics::Debug::WriteLine("Error en Timer: " + ex->Message);
			}
		}
		private: void RefreshData() {
			if (this->IsDisposed || !this->IsHandleCreated) {
				return;
			}

			if (this->InvokeRequired) {
				try {
					this->BeginInvoke(gcnew UpdateDataDelegate(this, &GraficsAdminForm::RefreshData));
				}
				catch (ObjectDisposedException^) {
					return;
				}
				catch (InvalidOperationException^) {
					return;
				}
				return;
			}

			if (this->IsDisposed) return;

			CargarDatos();

			bool shouldRestart = false;
			Monitor::Enter(lockObject);
			try {
				shouldRestart = timerRunning && !this->IsDisposed;
			}
			finally {
				Monitor::Exit(lockObject);
			}

			if (shouldRestart) {
				StartTimer();
			}
		}
	};
}