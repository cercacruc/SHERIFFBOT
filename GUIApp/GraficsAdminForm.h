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
	/// Resumen de GraficoBarras
	/// </summary>
	public ref class GraficsAdminForm : public System::Windows::Forms::Form
	{
	public:
		GraficsAdminForm(void)
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
		~GraficsAdminForm()
		{
			if (components)
			{
				delete components;
			}
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
			g->Clear(Color::White);
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

			if (!debeMostrarGrafico || listaUsuarios == nullptr || listaUsuarios->Count == 0) {
				// Mostrar mensaje cuando no hay datos
				Brush^ textoBrush = gcnew SolidBrush(Color::Gray);
				System::Drawing::Font^ font = gcnew System::Drawing::Font("Arial", 14, FontStyle::Italic);
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
			catch (Exception^ ex) {
				// Manejar errores de dibujo
				Brush^ errorBrush = gcnew SolidBrush(Color::Red);
				System::Drawing::Font^ errorFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
				g->DrawString("Error al dibujar el gráfico: " + ex->Message,
					errorFont, errorBrush, 10, 10);

				delete errorBrush;
				delete errorFont;
			}
		}

		private: void DibujarGraficoBarras_Usuarios(Graphics^ g, int width, int height) {
			// Configuración del gráfico
			int margenIzquierdo = 80;
			int margenDerecho = 40;
			int margenSuperior = 60;
			int margenInferior = 80;

			int areaGraficoWidth = width - margenIzquierdo - margenDerecho;
			int areaGraficoHeight = height - margenSuperior - margenInferior;

			// Calcular valores máximos para la escala

			int cant_robots = listaRobots->Count;
			int cant_usuarios = listaUsuarios->Count;
			int maxcantidad = cant_robots;
			if (cant_robots < cant_usuarios) maxcantidad = cant_usuarios;
			int cant_total = cant_robots + cant_usuarios;


			// Asegurar que maxcant sea al menos 1 para evitar división por cero
			if (maxcantidad == 0) maxcantidad = 1;

			// Dibujar título
			Brush^ tituloBrush = gcnew SolidBrush(Color::DarkBlue);
			System::Drawing::Font^ tituloFont = gcnew System::Drawing::Font("Arial", 14, FontStyle::Bold);
			String^ titulo = "Cantidad de Usuarios y Robots Registrados";
			SizeF tituloSize = g->MeasureString(titulo, tituloFont);
			g->DrawString(titulo, tituloFont, tituloBrush, (width - tituloSize.Width) / 2, 10);

			delete tituloBrush;
			delete tituloFont;

			// Dibujar ejes
			Pen^ ejePen = gcnew Pen(Color::Black, 2);
			g->DrawLine(ejePen, margenIzquierdo, margenSuperior, margenIzquierdo, margenSuperior + areaGraficoHeight); // Eje Y
			g->DrawLine(ejePen, margenIzquierdo, margenSuperior + areaGraficoHeight,
				margenIzquierdo + areaGraficoWidth, margenSuperior + areaGraficoHeight); // Eje X

			// Configuración de barras
			int numBarras = 2;
			int anchoBarra = areaGraficoWidth / (numBarras + 2); // Espacio entre barras
			int espacioEntreBarras = anchoBarra / 3;
			int anchoBarraReal = anchoBarra - espacioEntreBarras;

			// Colores para las barras
			array<Color>^ colores = {
				Color::Blue, Color::Red, Color::Green, Color::Orange,
				Color::Purple, Color::Brown, Color::Teal, Color::Magenta,
				Color::DarkGreen, Color::DarkRed, Color::DarkBlue, Color::Goldenrod
			};

			// Dibujar barras
			for (int i = 0; i < numBarras; i++) {
				int cantidad;
				//definimos la cantidad
				if (i == 0) cantidad = listaUsuarios->Count;
				if (i == 1) cantidad = listaRobots->Count;

				// Calcular posición y tamaño de la barra
				int x = margenIzquierdo + (i * anchoBarra) + espacioEntreBarras;
				int alturaBarra = (int)((cantidad / (double)maxcantidad) * areaGraficoHeight);
				int y = margenSuperior + areaGraficoHeight - alturaBarra;

				// Seleccionar color (ciclar si hay más máquinas que colores)
				Color colorBarra = colores[i % colores->Length];
				Brush^ barraBrush = gcnew SolidBrush(colorBarra);

				// Dibujar barra
				g->FillRectangle(barraBrush, x, y, anchoBarraReal, alturaBarra);

				// Borde de la barra
				Pen^ bordePen = gcnew Pen(Color::Black, 1);
				g->DrawRectangle(bordePen, x, y, anchoBarraReal, alturaBarra);

				// Etiqueta con la cantidad (dentro de la barra si cabe, sino arriba)
				Brush^ textoBrush = gcnew SolidBrush(Color::White);
				System::Drawing::Font^ textoFont = gcnew System::Drawing::Font("Arial", 8, FontStyle::Bold);
				String^ etiquetaCantidad = cantidad.ToString();
				SizeF textoSize = g->MeasureString(etiquetaCantidad, textoFont);

				float textoX = x + (anchoBarraReal - textoSize.Width) / 2;
				float textoY;

				if (alturaBarra > textoSize.Height + 4) {
					// Texto dentro de la barra
					textoY = y + (alturaBarra - textoSize.Height) / 2;
				}
				else {
					// Texto arriba de la barra
					textoY = y - textoSize.Height - 2;
					delete textoBrush;
					textoBrush = gcnew SolidBrush(Color::Black);
				}

				g->DrawString(etiquetaCantidad, textoFont, textoBrush, textoX, textoY);

				// Etiqueta del nombre de la máquina (eje X)
				Brush^ nombreBrush = gcnew SolidBrush(Color::Black);
				System::Drawing::Font^ nombreFont = gcnew System::Drawing::Font("Arial", 8);
				String^ nombre;
				if (i == 0) nombre = "Usuario";
				if (i == 1) nombre = "Robot";

				if (nombre->Length > 12) {
					nombre = nombre->Substring(0, 10) + "...";
				}

				SizeF nombreSize = g->MeasureString(nombre, nombreFont);
				float nombreX = x + (anchoBarraReal - nombreSize.Width) / 2;
				float nombreY = margenSuperior + areaGraficoHeight + 5;

				// Rotar texto si hay muchas máquinas
				if (numBarras > 8) {
					g->TranslateTransform(nombreX + nombreSize.Width / 2, nombreY);
					g->RotateTransform(-45);
					g->DrawString(nombre, nombreFont, nombreBrush, -nombreSize.Width / 2, 0);
					g->ResetTransform();
				}
				else {
					g->DrawString(nombre, nombreFont, nombreBrush, nombreX, nombreY);
				}

				// Liberar recursos
				delete barraBrush;
				delete bordePen;
				delete textoBrush;
				delete textoFont;
				delete nombreBrush;
				delete nombreFont;
			}

			// Dibujar escala del eje Y
			Brush^ escalaBrush = gcnew SolidBrush(Color::Black);
			System::Drawing::Font^ escalaFont = gcnew System::Drawing::Font("Arial", 8);
			Pen^ lineaEscalaPen = gcnew Pen(Color::Gray, 1);

			int numLineasEscala = 10;
			for (int i = 0; i <= numLineasEscala; i++) {
				double valor = (i / (double)numLineasEscala) * maxcantidad;
				int y = margenSuperior + areaGraficoHeight - (int)((i / (double)numLineasEscala) * areaGraficoHeight);

				// Línea de guía
				g->DrawLine(lineaEscalaPen, margenIzquierdo, y, margenIzquierdo + areaGraficoWidth, y);

				// Etiqueta del valor
				String^ etiquetaValor = valor.ToString("F0");
				SizeF etiquetaSize = g->MeasureString(etiquetaValor, escalaFont);
				g->DrawString(etiquetaValor, escalaFont, escalaBrush,
					margenIzquierdo - etiquetaSize.Width - 5, y - etiquetaSize.Height / 2);
			}

			// Etiqueta del eje Y
			System::Drawing::Font^ ejeYFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
			String^ etiquetaEjeY = "Registros";
			SizeF ejeYSize = g->MeasureString(etiquetaEjeY, ejeYFont);
			g->TranslateTransform(20, margenSuperior + areaGraficoHeight / 2);
			g->RotateTransform(-90);
			g->DrawString(etiquetaEjeY, ejeYFont, escalaBrush, -ejeYSize.Height / 2, 0);
			g->ResetTransform();

			// Etiqueta del eje X
			System::Drawing::Font^ ejeXFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
			String^ etiquetaEjeX = "Registrados";
			SizeF ejeXSize = g->MeasureString(etiquetaEjeX, ejeXFont);
			g->DrawString(etiquetaEjeX, ejeXFont, escalaBrush,
				margenIzquierdo + (areaGraficoWidth - ejeXSize.Width) / 2,
				margenSuperior + areaGraficoHeight + 30);

			// Leyenda de total
			Brush^ totalBrush = gcnew SolidBrush(Color::DarkGreen);
			System::Drawing::Font^ totalFont = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
			String^ totalTexto = String::Format("Total de registros: {0}", cant_total);
			g->DrawString(totalTexto, totalFont, totalBrush, margenIzquierdo, 35);

			// Liberar recursos finales
			delete ejePen;
			delete escalaBrush;
			delete escalaFont;
			delete lineaEscalaPen;
			delete ejeYFont;
			delete ejeXFont;
			delete totalBrush;
			delete totalFont;
		}
		private: System::Void GraficsAdminForm_Load(System::Object^ sender, System::EventArgs^ e) {
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
		private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}