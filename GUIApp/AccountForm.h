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

    /// <summary>
    /// Resumen de AccountForm
    /// </summary>
    public ref class AccountForm : public System::Windows::Forms::Form
    {
    public:
        DatosUsuario^ Usuario;

        AccountForm(DatosUsuario^ usuario)
        {
            InitializeComponent();
            this->DoubleBuffered = true;
            Usuario = usuario;
            StyleControls();
        }

    protected:
        ~AccountForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        // Controles
        System::Windows::Forms::Button^ btnReturnPassword;
        System::Windows::Forms::Label^ labelTitle;
        System::Windows::Forms::Label^ labelUser;
        System::Windows::Forms::Label^ labelID;
        System::Windows::Forms::Label^ labelCargo;

        System::Windows::Forms::TextBox^ textUsuario;
        System::Windows::Forms::TextBox^ textID;
        System::Windows::Forms::TextBox^ textCargo;

        System::Windows::Forms::PictureBox^ pictureBox1;
        System::Windows::Forms::Panel^ mainCard;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AccountForm::typeid));
            this->btnReturnPassword = (gcnew System::Windows::Forms::Button());
            this->labelTitle = (gcnew System::Windows::Forms::Label());
            this->labelUser = (gcnew System::Windows::Forms::Label());
            this->labelID = (gcnew System::Windows::Forms::Label());
            this->labelCargo = (gcnew System::Windows::Forms::Label());
            this->textUsuario = (gcnew System::Windows::Forms::TextBox());
            this->textID = (gcnew System::Windows::Forms::TextBox());
            this->textCargo = (gcnew System::Windows::Forms::TextBox());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->mainCard = (gcnew System::Windows::Forms::Panel());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->mainCard->SuspendLayout();
            this->SuspendLayout();
            // 
            // btnReturnPassword
            // 
            this->btnReturnPassword->Location = System::Drawing::Point(350, 260);
            this->btnReturnPassword->Name = L"btnReturnPassword";
            this->btnReturnPassword->Size = System::Drawing::Size(120, 36);
            this->btnReturnPassword->TabIndex = 8;
            this->btnReturnPassword->Text = L"Volver";
            this->btnReturnPassword->UseVisualStyleBackColor = true;
            this->btnReturnPassword->Click += gcnew System::EventHandler(this, &AccountForm::btnReturnPassword_Click);
            // 
            // labelTitle
            // 
            this->labelTitle->AutoSize = true;
            this->labelTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->labelTitle->Location = System::Drawing::Point(40, 20);
            this->labelTitle->Name = L"labelTitle";
            this->labelTitle->Size = System::Drawing::Size(215, 32);
            this->labelTitle->TabIndex = 1;
            this->labelTitle->Text = L"Mi cuenta / perfil";
            // 
            // labelUser
            // 
            this->labelUser->AutoSize = true;
            this->labelUser->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->labelUser->Location = System::Drawing::Point(210, 70);
            this->labelUser->Name = L"labelUser";
            this->labelUser->Size = System::Drawing::Size(59, 20);
            this->labelUser->TabIndex = 2;
            this->labelUser->Text = L"Usuario";
            // 
            // labelID
            // 
            this->labelID->AutoSize = true;
            this->labelID->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->labelID->Location = System::Drawing::Point(210, 130);
            this->labelID->Name = L"labelID";
            this->labelID->Size = System::Drawing::Size(24, 20);
            this->labelID->TabIndex = 3;
            this->labelID->Text = L"ID";
            // 
            // labelCargo
            // 
            this->labelCargo->AutoSize = true;
            this->labelCargo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->labelCargo->Location = System::Drawing::Point(210, 190);
            this->labelCargo->Name = L"labelCargo";
            this->labelCargo->Size = System::Drawing::Size(49, 20);
            this->labelCargo->TabIndex = 4;
            this->labelCargo->Text = L"Cargo";
            // 
            // textUsuario
            // 
            this->textUsuario->Location = System::Drawing::Point(210, 95);
            this->textUsuario->Name = L"textUsuario";
            this->textUsuario->Size = System::Drawing::Size(260, 22);
            this->textUsuario->TabIndex = 5;
            // 
            // textID
            // 
            this->textID->Location = System::Drawing::Point(210, 155);
            this->textID->Name = L"textID";
            this->textID->Size = System::Drawing::Size(260, 22);
            this->textID->TabIndex = 6;
            // 
            // textCargo
            // 
            this->textCargo->Location = System::Drawing::Point(210, 215);
            this->textCargo->Name = L"textCargo";
            this->textCargo->Size = System::Drawing::Size(260, 22);
            this->textCargo->TabIndex = 7;
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(46, 90);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(120, 120);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            // 
            // mainCard
            // 
            this->mainCard->BackColor = System::Drawing::Color::Transparent;
            this->mainCard->Controls->Add(this->labelTitle);
            this->mainCard->Controls->Add(this->pictureBox1);
            this->mainCard->Controls->Add(this->labelUser);
            this->mainCard->Controls->Add(this->labelID);
            this->mainCard->Controls->Add(this->labelCargo);
            this->mainCard->Controls->Add(this->textUsuario);
            this->mainCard->Controls->Add(this->textID);
            this->mainCard->Controls->Add(this->textCargo);
            this->mainCard->Controls->Add(this->btnReturnPassword);
            this->mainCard->Location = System::Drawing::Point(20, 20);
            this->mainCard->Name = L"mainCard";
            this->mainCard->Size = System::Drawing::Size(540, 320);
            this->mainCard->TabIndex = 0;
            this->mainCard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &AccountForm::mainCard_Paint);
            // 
            // AccountForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(580, 360);
            this->Controls->Add(this->mainCard);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"AccountForm";
            this->Text = L"Mi cuenta";
            this->Load += gcnew System::EventHandler(this, &AccountForm::AccountForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->mainCard->ResumeLayout(false);
            this->mainCard->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

        // ---------- Estilo visual ----------
    private:
        void StyleControls()
        {
            // Form
            this->BackColor = Color::FromArgb(5, 8, 22);
            this->ForeColor = Color::FromArgb(226, 232, 240);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;

            // Labels
            this->labelTitle->ForeColor = Color::White;
            this->labelUser->ForeColor = Color::FromArgb(200, 210, 230);
            this->labelID->ForeColor = Color::FromArgb(200, 210, 230);
            this->labelCargo->ForeColor = Color::FromArgb(200, 210, 230);

            // TextBoxes (solo lectura, estilo dark)
            Color back = Color::FromArgb(10, 16, 32);
            Color fore = Color::FromArgb(226, 232, 240);

            array<TextBox^>^ boxes = gcnew array<TextBox^> {
                this->textUsuario, this->textID, this->textCargo
            };

            for each (TextBox ^ tb in boxes)
            {
                tb->BackColor = back;
                tb->ForeColor = fore;
                tb->BorderStyle = BorderStyle::FixedSingle;
                tb->ReadOnly = true;
            }

            // Botón Volver (secundario con borde celeste)
            this->btnReturnPassword->FlatStyle = FlatStyle::Flat;
            this->btnReturnPassword->FlatAppearance->BorderSize = 0;
            this->btnReturnPassword->BackColor = Color::FromArgb(20, 27, 47);
            this->btnReturnPassword->ForeColor = Color::FromArgb(0, 140, 255);
            this->btnReturnPassword->Font =
                gcnew System::Drawing::Font(L"Segoe UI", 9, FontStyle::Regular);

            GUIApp::UIHelpers::SetRoundedRegionAuto(this->btnReturnPassword);
            this->btnReturnPassword->Paint += gcnew PaintEventHandler(
                &GUIApp::UIHelpers::OutlineButton_Paint);
        }

        // Card redondeada
        System::Void mainCard_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e)
        {
            GUIApp::UIHelpers::RoundedPanel_Paint(sender, e);
        }

        // ---------- Lógica ----------
    private: System::Void AccountForm_Load(System::Object^ sender, System::EventArgs^ e) {
        CargarDatosUsuario(Usuario->Nombre);
    }

    private: void CargarDatosUsuario(String^ username) {
        DatosUsuario^ encontrado = Service::buscarUsuarioNombre(username);
        if (encontrado != nullptr) {
            textUsuario->Text = encontrado->Nombre;
            textID->Text = encontrado->ID.ToString();
            textCargo->Text = encontrado->Cargo;
        }
    }

    private: System::Void btnReturnPassword_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }
    };
}
