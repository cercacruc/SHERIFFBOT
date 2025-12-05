#pragma once
#include "AccountForm.h"
#include "RobotsSheriffForm.h"
#include "AlertManagementForm.h"
#include "AsignarAlertaRobotForm.h"
#include "GraficosUserForm.h"
#include "GraficAlertUserSolForm.h"
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
    /// Resumen de SheriffForm
    /// </summary>
    public ref class SheriffForm : public System::Windows::Forms::Form
    {
    public:
        DatosUsuario^ Usuario;

        SheriffForm(DatosUsuario^ usuario)
        {
            InitializeComponent();
            this->DoubleBuffered = true;
            Usuario = usuario;
            StyleButtons();
        }

    protected:
        ~SheriffForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        // Botones
        System::Windows::Forms::Button^ btnInfo;
        System::Windows::Forms::Button^ btnRobots;
        System::Windows::Forms::Button^ button1;       // Asignar robots
        System::Windows::Forms::Button^ btnCerrarSesion;
        System::Windows::Forms::Button^ btnEstadistica;

        // Iconos / imágenes
        System::Windows::Forms::PictureBox^ btnAccount;
        System::Windows::Forms::PictureBox^ pictureBox1;
        System::Windows::Forms::PictureBox^ pictureBox3;
        System::Windows::Forms::PictureBox^ pictureBox2;
        System::Windows::Forms::PictureBox^ pictureBox4;

        // Tarjeta principal
        System::Windows::Forms::Panel^ mainCard;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SheriffForm::typeid));
            this->btnInfo = (gcnew System::Windows::Forms::Button());
            this->btnRobots = (gcnew System::Windows::Forms::Button());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->btnAccount = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->btnCerrarSesion = (gcnew System::Windows::Forms::Button());
            this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
            this->btnEstadistica = (gcnew System::Windows::Forms::Button());
            this->mainCard = (gcnew System::Windows::Forms::Panel());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAccount))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
            this->mainCard->SuspendLayout();
            this->SuspendLayout();
            // 
            // btnInfo
            // 
            this->btnInfo->Location = System::Drawing::Point(44, 491);
            this->btnInfo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnInfo->Name = L"btnInfo";
            this->btnInfo->Size = System::Drawing::Size(155, 55);
            this->btnInfo->TabIndex = 15;
            this->btnInfo->Text = L"Menú de Solicitudes";
            this->btnInfo->UseVisualStyleBackColor = true;
            this->btnInfo->Click += gcnew System::EventHandler(this, &SheriffForm::btnInfo_Click);
            // 
            // btnRobots
            // 
            this->btnRobots->Location = System::Drawing::Point(42, 247);
            this->btnRobots->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnRobots->Name = L"btnRobots";
            this->btnRobots->Size = System::Drawing::Size(155, 55);
            this->btnRobots->TabIndex = 13;
            this->btnRobots->Text = L"Gestión de robots";
            this->btnRobots->UseVisualStyleBackColor = true;
            this->btnRobots->Click += gcnew System::EventHandler(this, &SheriffForm::btnRobots_Click);
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(259, 247);
            this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(155, 55);
            this->button1->TabIndex = 18;
            this->button1->Text = L"Asignar Robots";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &SheriffForm::button1_Click);
            // 
            // btnAccount
            // 
            this->btnAccount->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnAccount->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAccount.Image")));
            this->btnAccount->Location = System::Drawing::Point(12, 11);
            this->btnAccount->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnAccount->Name = L"btnAccount";
            this->btnAccount->Size = System::Drawing::Size(59, 59);
            this->btnAccount->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->btnAccount->TabIndex = 19;
            this->btnAccount->TabStop = false;
            this->btnAccount->Click += gcnew System::EventHandler(this, &SheriffForm::btnAccount_Click_1);
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(40, 88);
            this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(161, 148);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 20;
            this->pictureBox1->TabStop = false;
            // 
            // pictureBox3
            // 
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(257, 88);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(161, 148);
            this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox3->TabIndex = 21;
            this->pictureBox3->TabStop = false;
            // 
            // pictureBox2
            // 
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(40, 339);
            this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(161, 148);
            this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox2->TabIndex = 22;
            this->pictureBox2->TabStop = false;
            // 
            // btnCerrarSesion
            // 
            this->btnCerrarSesion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->btnCerrarSesion->Location = System::Drawing::Point(296, 11);
            this->btnCerrarSesion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnCerrarSesion->Name = L"btnCerrarSesion";
            this->btnCerrarSesion->Size = System::Drawing::Size(144, 59);
            this->btnCerrarSesion->TabIndex = 31;
            this->btnCerrarSesion->Text = L"Cerrar Sesión";
            this->btnCerrarSesion->UseVisualStyleBackColor = true;
            this->btnCerrarSesion->Click += gcnew System::EventHandler(this, &SheriffForm::btnCerrarSesion_Click);
            // 
            // pictureBox4
            // 
            this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
            this->pictureBox4->Location = System::Drawing::Point(257, 339);
            this->pictureBox4->Name = L"pictureBox4";
            this->pictureBox4->Size = System::Drawing::Size(159, 148);
            this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox4->TabIndex = 33;
            this->pictureBox4->TabStop = false;
            // 
            // btnEstadistica
            // 
            this->btnEstadistica->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->btnEstadistica->Location = System::Drawing::Point(255, 492);
            this->btnEstadistica->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnEstadistica->Name = L"btnEstadistica";
            this->btnEstadistica->Size = System::Drawing::Size(155, 55);
            this->btnEstadistica->TabIndex = 32;
            this->btnEstadistica->Text = L"Estadísticas";
            this->btnEstadistica->UseVisualStyleBackColor = true;
            this->btnEstadistica->Click += gcnew System::EventHandler(this, &SheriffForm::btnEstadistica_Click);
            // 
            // mainCard
            // 
            this->mainCard->BackColor = System::Drawing::Color::Transparent;
            this->mainCard->Controls->Add(this->btnAccount);
            this->mainCard->Controls->Add(this->btnCerrarSesion);
            this->mainCard->Controls->Add(this->pictureBox1);
            this->mainCard->Controls->Add(this->pictureBox3);
            this->mainCard->Controls->Add(this->pictureBox2);
            this->mainCard->Controls->Add(this->pictureBox4);
            this->mainCard->Controls->Add(this->btnRobots);
            this->mainCard->Controls->Add(this->button1);
            this->mainCard->Controls->Add(this->btnInfo);
            this->mainCard->Controls->Add(this->btnEstadistica);
            this->mainCard->Location = System::Drawing::Point(12, 12);
            this->mainCard->Name = L"mainCard";
            this->mainCard->Size = System::Drawing::Size(453, 574);
            this->mainCard->TabIndex = 0;
            this->mainCard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SheriffForm::mainCard_Paint);
            // 
            // SheriffForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
                static_cast<System::Int32>(static_cast<System::Byte>(22)));
            this->ClientSize = System::Drawing::Size(487, 610);
            this->Controls->Add(this->mainCard);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"SheriffForm";
            this->Text = L"Panel Sheriff";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAccount))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
            this->mainCard->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        AsignarAlertaRobotForm^ form = gcnew AsignarAlertaRobotForm();
        this->Hide();
        form->ShowDialog();
        this->Show();
    }
    private: System::Void btnRobots_Click(System::Object^ sender, System::EventArgs^ e) {
        RobotsSheriffForm^ form = gcnew RobotsSheriffForm();
        this->Hide();
        form->ShowDialog();
        this->Show();
    }
    private: System::Void btnInfo_Click(System::Object^ sender, System::EventArgs^ e) {
        AlertManagementForm^ form = gcnew AlertManagementForm();
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
    private: System::Void btnEstadistica_Click(System::Object^ sender, System::EventArgs^ e) {
        GraficAlertUserSolForm^ form = gcnew GraficAlertUserSolForm();
        this->Hide();
        form->ShowDialog();
        this->Show();
    }

           // ========= Estilos visuales =========
    private:
        void StyleButtons()
        {
            // Botones principales del Sheriff
            array<Button^>^ primary = gcnew array<Button^> {
                this->btnRobots,
                    this->button1,
                    this->btnInfo,
                    this->btnEstadistica
            };

            for each (Button ^ b in primary)
            {
                b->FlatStyle = FlatStyle::Flat;
                b->FlatAppearance->BorderSize = 0;
                b->BackColor = System::Drawing::Color::FromArgb(0, 140, 255);
                b->ForeColor = System::Drawing::Color::White;
                b->Font = gcnew System::Drawing::Font("Segoe UI", 9, System::Drawing::FontStyle::Bold);
                UIHelpers::SetRoundedRegion(b, 18);
            }

            // Cerrar sesión como secundario (outline)
            this->btnCerrarSesion->FlatStyle = FlatStyle::Flat;
            this->btnCerrarSesion->FlatAppearance->BorderSize = 0;
            this->btnCerrarSesion->BackColor = System::Drawing::Color::FromArgb(20, 27, 47);
            this->btnCerrarSesion->ForeColor = System::Drawing::Color::FromArgb(224, 231, 255);
            this->btnCerrarSesion->Font =
                gcnew System::Drawing::Font("Segoe UI", 9, System::Drawing::FontStyle::Regular);
            UIHelpers::SetRoundedRegion(this->btnCerrarSesion, 18);
            this->btnCerrarSesion->Paint += gcnew System::Windows::Forms::PaintEventHandler(
                &UIHelpers::OutlineButton_Paint);
        }

        System::Void mainCard_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e)
        {
            UIHelpers::RoundedPanel_Paint(sender, e);
        }
    };
}
