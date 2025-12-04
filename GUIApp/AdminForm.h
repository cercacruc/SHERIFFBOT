#pragma once
#include "DatosRobotsUsuariosForm.h"
#include "AccountForm.h"
#include "AdminAlertManagementForm.h"
#include "DelimitarZonasTrabajoAdmin.h"
#include "GraficsAdminForm.h"
#include "GraficosUserForm.h"

// estilos reutilizables (RoundedPanel, SetRoundedRegion, etc.)
#include "UIStyles.h"

namespace GUIApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    using namespace BotModel;

    /// <summary>
    /// Resumen de AdminForm
    /// </summary>
    public ref class AdminForm : public System::Windows::Forms::Form
    {
    public:
        DatosUsuario^ Usuario;

        AdminForm(DatosUsuario^ usuario)
        {
            InitializeComponent();
            this->DoubleBuffered = true;
            Usuario = usuario;
            StyleButtons();
        }

    protected:
        ~AdminForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        // Botones
        System::Windows::Forms::Button^ button1;        // Registro incidencias
        System::Windows::Forms::Button^ btnRobots;      // Gestión usuarios/robots
        System::Windows::Forms::Button^ btnZonasT;      // Zonas trabajo
        System::Windows::Forms::Button^ btnEstadistica; // Estadísticas
        System::Windows::Forms::Button^ btnCerrarSesion;

        // Iconos
        System::Windows::Forms::PictureBox^ btnAccount;
        System::Windows::Forms::PictureBox^ pictureBox3;
        System::Windows::Forms::PictureBox^ pictureBox2;
        System::Windows::Forms::PictureBox^ pictureBox1;
        System::Windows::Forms::PictureBox^ pictureBox4;

        // Tarjeta principal
        System::Windows::Forms::Panel^ mainCard;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminForm::typeid));
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->btnRobots = (gcnew System::Windows::Forms::Button());
            this->btnZonasT = (gcnew System::Windows::Forms::Button());
            this->btnEstadistica = (gcnew System::Windows::Forms::Button());
            this->btnAccount = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
            this->btnCerrarSesion = (gcnew System::Windows::Forms::Button());
            this->mainCard = (gcnew System::Windows::Forms::Panel());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAccount))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
            this->mainCard->SuspendLayout();
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->Location = System::Drawing::Point(263, 260);
            this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(150, 48);
            this->button1->TabIndex = 20;
            this->button1->Text = L"Registro de Incidencias";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &AdminForm::button1_Click);
            // 
            // btnRobots
            // 
            this->btnRobots->Location = System::Drawing::Point(48, 260);
            this->btnRobots->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnRobots->Name = L"btnRobots";
            this->btnRobots->Size = System::Drawing::Size(150, 48);
            this->btnRobots->TabIndex = 18;
            this->btnRobots->Text = L"Gestión de Usuarios/Robots";
            this->btnRobots->UseVisualStyleBackColor = true;
            this->btnRobots->Click += gcnew System::EventHandler(this, &AdminForm::btnRobots_Click);
            // 
            // btnZonasT
            // 
            this->btnZonasT->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnZonasT->Location = System::Drawing::Point(263, 495);
            this->btnZonasT->Name = L"btnZonasT";
            this->btnZonasT->Size = System::Drawing::Size(150, 48);
            this->btnZonasT->TabIndex = 21;
            this->btnZonasT->Text = L"Delimitar Zonas de Trabajo";
            this->btnZonasT->UseVisualStyleBackColor = true;
            this->btnZonasT->Click += gcnew System::EventHandler(this, &AdminForm::btnZonasT_Click);
            // 
            // btnEstadistica
            // 
            this->btnEstadistica->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnEstadistica->Location = System::Drawing::Point(48, 495);
            this->btnEstadistica->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnEstadistica->Name = L"btnEstadistica";
            this->btnEstadistica->Size = System::Drawing::Size(150, 48);
            this->btnEstadistica->TabIndex = 24;
            this->btnEstadistica->Text = L"Estadísticas";
            this->btnEstadistica->UseVisualStyleBackColor = true;
            this->btnEstadistica->Click += gcnew System::EventHandler(this, &AdminForm::btnEstadistica_Click);
            // 
            // btnAccount
            // 
            this->btnAccount->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnAccount->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAccount.Image")));
            this->btnAccount->Location = System::Drawing::Point(24, 24);
            this->btnAccount->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnAccount->Name = L"btnAccount";
            this->btnAccount->Size = System::Drawing::Size(56, 56);
            this->btnAccount->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->btnAccount->TabIndex = 25;
            this->btnAccount->TabStop = false;
            this->btnAccount->Click += gcnew System::EventHandler(this, &AdminForm::btnAccount_Click_1);
            // 
            // pictureBox3
            // 
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(263, 345);
            this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(150, 140);
            this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox3->TabIndex = 28;
            this->pictureBox3->TabStop = false;
            // 
            // pictureBox2
            // 
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(263, 110);
            this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(150, 140);
            this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox2->TabIndex = 27;
            this->pictureBox2->TabStop = false;
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(48, 110);
            this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(150, 140);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 26;
            this->pictureBox1->TabStop = false;
            // 
            // pictureBox4
            // 
            this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
            this->pictureBox4->Location = System::Drawing::Point(48, 345);
            this->pictureBox4->Name = L"pictureBox4";
            this->pictureBox4->Size = System::Drawing::Size(150, 140);
            this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox4->TabIndex = 29;
            this->pictureBox4->TabStop = false;
            // 
            // btnCerrarSesion
            // 
            this->btnCerrarSesion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnCerrarSesion->Location = System::Drawing::Point(263, 24);
            this->btnCerrarSesion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnCerrarSesion->Name = L"btnCerrarSesion";
            this->btnCerrarSesion->Size = System::Drawing::Size(150, 45);
            this->btnCerrarSesion->TabIndex = 30;
            this->btnCerrarSesion->Text = L"Cerrar sesión";
            this->btnCerrarSesion->UseVisualStyleBackColor = true;
            this->btnCerrarSesion->Click += gcnew System::EventHandler(this, &AdminForm::btnCerrarSesion_Click);
            // 
            // mainCard
            // 
            this->mainCard->BackColor = System::Drawing::Color::Transparent;
            this->mainCard->Controls->Add(this->btnAccount);
            this->mainCard->Controls->Add(this->btnCerrarSesion);
            this->mainCard->Controls->Add(this->pictureBox1);
            this->mainCard->Controls->Add(this->pictureBox2);
            this->mainCard->Controls->Add(this->pictureBox3);
            this->mainCard->Controls->Add(this->pictureBox4);
            this->mainCard->Controls->Add(this->btnRobots);
            this->mainCard->Controls->Add(this->button1);
            this->mainCard->Controls->Add(this->btnZonasT);
            this->mainCard->Controls->Add(this->btnEstadistica);
            this->mainCard->Location = System::Drawing::Point(20, 20);
            this->mainCard->Name = L"mainCard";
            this->mainCard->Size = System::Drawing::Size(451, 570);
            this->mainCard->TabIndex = 0;
            this->mainCard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &AdminForm::mainCard_Paint);
            // 
            // AdminForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
                static_cast<System::Int32>(static_cast<System::Byte>(22)));
            this->ClientSize = System::Drawing::Size(487, 610);
            this->Controls->Add(this->mainCard);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"AdminForm";
            this->Text = L"Panel de administración";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAccount))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
            this->mainCard->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion

        // ========= Navegación =========
    private: System::Void btnRobots_Click(System::Object^ sender, System::EventArgs^ e) {
        DatosRobotsUsuariosForm^ form = gcnew DatosRobotsUsuariosForm();
        this->Hide();
        form->ShowDialog();
        this->Show();
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        AdminAlertManagementForm^ form = gcnew AdminAlertManagementForm();
        this->Hide();
        form->ShowDialog();
        this->Show();
    }
    private: System::Void btnZonasT_Click(System::Object^ sender, System::EventArgs^ e) {
        DelimitarZonasTrabajoAdmin^ form = gcnew DelimitarZonasTrabajoAdmin();
        this->Hide();
        form->ShowDialog();
        this->Show();
    }
    private: System::Void btnEstadistica_Click(System::Object^ sender, System::EventArgs^ e) {
        GraficosUserForm^ form = gcnew GraficosUserForm();
        this->Hide();
        form->ShowDialog();
        this->Show();
    }
    private: System::Void btnCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }
    private: System::Void btnAccount_Click_1(System::Object^ sender, System::EventArgs^ e) {
        AccountForm^ form = gcnew AccountForm(Usuario);
        this->Hide();
        form->ShowDialog();
        this->Show();
    }

           // ========= Estilos visuales =========
    private:
        void StyleButtons()
        {
            // Botones principales (debajo de cada icono)
            array<Button^>^ mainButtons = gcnew array<Button^> {
                this->btnRobots, this->button1, this->btnZonasT, this->btnEstadistica
            };

            for each (Button ^ b in mainButtons)
            {
                b->FlatStyle = FlatStyle::Flat;
                b->FlatAppearance->BorderSize = 0;
                b->BackColor = System::Drawing::Color::FromArgb(20, 27, 47);        // fondo oscuro
                b->ForeColor = System::Drawing::Color::FromArgb(224, 231, 255);     // texto claro
                b->Font = gcnew System::Drawing::Font("Segoe UI", 9,
                    System::Drawing::FontStyle::Regular);

                // esquinas redondeadas
                GUIApp::UIHelpers::SetRoundedRegion(b, 18);

                // borde celeste (diseño secundario)
                b->Paint += gcnew System::Windows::Forms::PaintEventHandler(
                    &GUIApp::UIHelpers::OutlineButton_Paint);
            }

            // Botón Cerrar sesión (lo dejamos también como outline)
            this->btnCerrarSesion->FlatStyle = FlatStyle::Flat;
            this->btnCerrarSesion->FlatAppearance->BorderSize = 0;
            this->btnCerrarSesion->BackColor = System::Drawing::Color::FromArgb(20, 27, 47);
            this->btnCerrarSesion->ForeColor = System::Drawing::Color::FromArgb(224, 231, 255);
            this->btnCerrarSesion->Font =
                gcnew System::Drawing::Font("Segoe UI", 9, System::Drawing::FontStyle::Regular);
            GUIApp::UIHelpers::SetRoundedRegion(this->btnCerrarSesion, 18);
            this->btnCerrarSesion->Paint += gcnew System::Windows::Forms::PaintEventHandler(
                &GUIApp::UIHelpers::OutlineButton_Paint);
        }
        // Tarjeta redondeada
        System::Void mainCard_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e)
        {
            GUIApp::UIHelpers::RoundedPanel_Paint(sender, e);
        }
    };
}
