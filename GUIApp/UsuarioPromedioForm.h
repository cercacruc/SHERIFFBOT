#pragma once
#include "InformationRequestForm.h"
#include "AlertForm.h"
#include "AccountForm.h"
#include "GraficsUsersForm.h"
#include "GraficosUserForm.h"
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
    /// Resumen de UsuarioPromedioForm
    /// </summary>
    public ref class UsuarioPromedioForm : public System::Windows::Forms::Form
    {
    public:
        DatosUsuario^ Usuario;

        UsuarioPromedioForm(DatosUsuario^ usuario)
        {
            InitializeComponent();
            this->DoubleBuffered = true;

            this->BackColor = System::Drawing::Color::FromArgb(5, 8, 22);
            this->ForeColor = System::Drawing::Color::White;
            this->StartPosition = FormStartPosition::CenterScreen;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;

            Usuario = usuario;
            StyleButtons();
        }

    protected:
        ~UsuarioPromedioForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        // Botones
        System::Windows::Forms::Button^ btnAlert;
        System::Windows::Forms::Button^ btnInfo;
        System::Windows::Forms::Button^ btnEstadisticas;
        System::Windows::Forms::Button^ btnCerrarSesion;

        // Imágenes
        System::Windows::Forms::PictureBox^ pictureBox2;
        System::Windows::Forms::PictureBox^ pictureBox1;
        System::Windows::Forms::PictureBox^ pictureBox3;
        System::Windows::Forms::PictureBox^ pictureBox4; // cuenta

        // Tarjeta principal
        System::Windows::Forms::Panel^ mainCard;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UsuarioPromedioForm::typeid));
            this->btnAlert = (gcnew System::Windows::Forms::Button());
            this->btnInfo = (gcnew System::Windows::Forms::Button());
            this->btnEstadisticas = (gcnew System::Windows::Forms::Button());
            this->btnCerrarSesion = (gcnew System::Windows::Forms::Button());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
            this->mainCard = (gcnew System::Windows::Forms::Panel());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
            this->mainCard->SuspendLayout();
            this->SuspendLayout();
            // 
            // btnAlert
            // 
            this->btnAlert->Location = System::Drawing::Point(164, 503);
            this->btnAlert->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnAlert->Name = L"btnAlert";
            this->btnAlert->Size = System::Drawing::Size(150, 50);
            this->btnAlert->TabIndex = 13;
            this->btnAlert->Text = L"Alertar";
            this->btnAlert->UseVisualStyleBackColor = true;
            this->btnAlert->Click += gcnew System::EventHandler(this, &UsuarioPromedioForm::btnAlert_Click);
            // 
            // btnInfo
            // 
            this->btnInfo->Location = System::Drawing::Point(39, 260);
            this->btnInfo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnInfo->Name = L"btnInfo";
            this->btnInfo->Size = System::Drawing::Size(150, 50);
            this->btnInfo->TabIndex = 11;
            this->btnInfo->Text = L"Solicitar información";
            this->btnInfo->UseVisualStyleBackColor = true;
            this->btnInfo->Click += gcnew System::EventHandler(this, &UsuarioPromedioForm::btnInfo_Click);
            // 
            // btnEstadisticas
            // 
            this->btnEstadisticas->Location = System::Drawing::Point(274, 260);
            this->btnEstadisticas->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnEstadisticas->Name = L"btnEstadisticas";
            this->btnEstadisticas->Size = System::Drawing::Size(150, 50);
            this->btnEstadisticas->TabIndex = 15;
            this->btnEstadisticas->Text = L"Estadísticas";
            this->btnEstadisticas->UseVisualStyleBackColor = true;
            this->btnEstadisticas->Click += gcnew System::EventHandler(this, &UsuarioPromedioForm::btnEstadisticas_Click);
            // 
            // btnCerrarSesion
            // 
            this->btnCerrarSesion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->btnCerrarSesion->Location = System::Drawing::Point(305, 11);
            this->btnCerrarSesion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnCerrarSesion->Name = L"btnCerrarSesion";
            this->btnCerrarSesion->Size = System::Drawing::Size(144, 59);
            this->btnCerrarSesion->TabIndex = 32;
            this->btnCerrarSesion->Text = L"Cerrar Sesión";
            this->btnCerrarSesion->UseVisualStyleBackColor = true;
            this->btnCerrarSesion->Click += gcnew System::EventHandler(this, &UsuarioPromedioForm::btnCerrarSesion_Click);
            // 
            // pictureBox2
            // 
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(34, 99);
            this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(161, 148);
            this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox2->TabIndex = 33;
            this->pictureBox2->TabStop = false;
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(271, 99);
            this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(161, 148);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 34;
            this->pictureBox1->TabStop = false;
            // 
            // pictureBox3
            // 
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(160, 340);
            this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(161, 148);
            this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox3->TabIndex = 35;
            this->pictureBox3->TabStop = false;
            // 
            // pictureBox4
            // 
            this->pictureBox4->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
            this->pictureBox4->Location = System::Drawing::Point(12, 11);
            this->pictureBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox4->Name = L"pictureBox4";
            this->pictureBox4->Size = System::Drawing::Size(59, 59);
            this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox4->TabIndex = 36;
            this->pictureBox4->TabStop = false;
            this->pictureBox4->Click += gcnew System::EventHandler(this, &UsuarioPromedioForm::pictureBox4_Click);
            // 
            // mainCard
            // 
            this->mainCard->BackColor = System::Drawing::Color::Transparent;
            this->mainCard->Controls->Add(this->pictureBox4);
            this->mainCard->Controls->Add(this->pictureBox2);
            this->mainCard->Controls->Add(this->pictureBox1);
            this->mainCard->Controls->Add(this->pictureBox3);
            this->mainCard->Controls->Add(this->btnCerrarSesion);
            this->mainCard->Controls->Add(this->btnEstadisticas);
            this->mainCard->Controls->Add(this->btnAlert);
            this->mainCard->Controls->Add(this->btnInfo);
            this->mainCard->Location = System::Drawing::Point(12, 12);
            this->mainCard->Name = L"mainCard";
            this->mainCard->Size = System::Drawing::Size(463, 574);
            this->mainCard->TabIndex = 0;
            this->mainCard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &UsuarioPromedioForm::mainCard_Paint);
            // 
            // UsuarioPromedioForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
                static_cast<System::Int32>(static_cast<System::Byte>(22)));
            this->ClientSize = System::Drawing::Size(487, 610);
            this->Controls->Add(this->mainCard);
            this->Name = L"UsuarioPromedioForm";
            this->Text = L"Panel de Usuario";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
            this->mainCard->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void btnInfo_Click(System::Object^ sender, System::EventArgs^ e) {
        InformationRequestForm^ Informationform = gcnew InformationRequestForm();
        this->Hide();
        Informationform->ShowDialog();
        this->Show();
    }
    private: System::Void btnAlert_Click(System::Object^ sender, System::EventArgs^ e) {
        AlertForm^ form = gcnew AlertForm(Usuario);
        this->Hide();
        form->ShowDialog();
        this->Show();
    }
    private: System::Void btnEstadisticas_Click(System::Object^ sender, System::EventArgs^ e) {
        GraficsUsersForm^ form = gcnew GraficsUsersForm(Usuario);
        this->Hide();
        form->ShowDialog();
        this->Show();
    }
    private: System::Void btnCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }
    private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
        AccountForm^ form = gcnew AccountForm(Usuario);
        this->Hide();
        form->ShowDialog();
        this->Show();
    }

           // ========= Estilos visuales =========
    private:
        void StyleButtons()
        {
            // Botones principales
            array<Button^>^ primary = gcnew array<Button^> {
                this->btnInfo,
                    this->btnEstadisticas,
                    this->btnAlert
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
