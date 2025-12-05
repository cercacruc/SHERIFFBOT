#pragma once
#include "MissingObjectForm.h"
#include "AltercationReportForm.h"
#include "DTIReportForm.h"
#include "AlertHistForm.h"
#include "UIStyles.h"    // estilos reutilizables

namespace GUIApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    using namespace BotModel;
    using namespace BotService;


    /// Resumen de AlertForm

    public ref class AlertForm : public System::Windows::Forms::Form
    {
    public:
        DatosUsuario^ Usuario;

        AlertForm(DatosUsuario^ usuario)
        {
            InitializeComponent();
            this->DoubleBuffered = true;
            Usuario = usuario;
            StyleControls();
        }

    protected:

        /// Limpiar los recursos que se estén usando.

        ~AlertForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ btnReturn;
        System::Windows::Forms::Button^ btnDTIReport;
        System::Windows::Forms::Button^ btnAltercation;
        System::Windows::Forms::Button^ btnMissingObject;
        System::Windows::Forms::Button^ btnHistReport;
        System::Windows::Forms::Label^ label1;

        System::Windows::Forms::Panel^ mainCard;

 
        /// Variable del diseñador necesaria.
  
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
       
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources =
                (gcnew System::ComponentModel::ComponentResourceManager(AlertForm::typeid));

            this->btnReturn = (gcnew System::Windows::Forms::Button());
            this->btnDTIReport = (gcnew System::Windows::Forms::Button());
            this->btnAltercation = (gcnew System::Windows::Forms::Button());
            this->btnMissingObject = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->btnHistReport = (gcnew System::Windows::Forms::Button());
            this->mainCard = (gcnew System::Windows::Forms::Panel());

            this->mainCard->SuspendLayout();
            this->SuspendLayout();

            // 
            // mainCard
            // 
            this->mainCard->BackColor = System::Drawing::Color::Transparent;
            this->mainCard->Location = System::Drawing::Point(20, 20);
            this->mainCard->Name = L"mainCard";
            this->mainCard->Size = System::Drawing::Size(340, 420);
            this->mainCard->TabIndex = 0;
            this->mainCard->Paint += gcnew System::Windows::Forms::PaintEventHandler(
                this, &AlertForm::mainCard_Paint);

            // 
            // label1  (Título)
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16,
                System::Drawing::FontStyle::Bold));
            this->label1->Location = System::Drawing::Point(70, 30);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(183, 37);
            this->label1->TabIndex = 5;
            this->label1->Text = L"Tipo de alerta";

            // 
            // btnMissingObject (principal)
            // 
            this->btnMissingObject->Location = System::Drawing::Point(50, 95);
            this->btnMissingObject->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnMissingObject->Name = L"btnMissingObject";
            this->btnMissingObject->Size = System::Drawing::Size(240, 45);
            this->btnMissingObject->TabIndex = 6;
            this->btnMissingObject->Text = L"Objeto perdido";
            this->btnMissingObject->UseVisualStyleBackColor = true;
            this->btnMissingObject->Click += gcnew System::EventHandler(
                this, &AlertForm::btnMissingObject_Click);

            // 
            // btnAltercation (principal)
            // 
            this->btnAltercation->Location = System::Drawing::Point(50, 150);
            this->btnAltercation->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnAltercation->Name = L"btnAltercation";
            this->btnAltercation->Size = System::Drawing::Size(240, 45);
            this->btnAltercation->TabIndex = 7;
            this->btnAltercation->Text = L"Reporte de altercado";
            this->btnAltercation->UseVisualStyleBackColor = true;
            this->btnAltercation->Click += gcnew System::EventHandler(
                this, &AlertForm::btnAltercation_Click);

            // 
            // btnDTIReport (principal)
            // 
            this->btnDTIReport->Location = System::Drawing::Point(50, 205);
            this->btnDTIReport->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnDTIReport->Name = L"btnDTIReport";
            this->btnDTIReport->Size = System::Drawing::Size(240, 45);
            this->btnDTIReport->TabIndex = 8;
            this->btnDTIReport->Text = L"Llamada al DTI";
            this->btnDTIReport->UseVisualStyleBackColor = true;
            this->btnDTIReport->Click += gcnew System::EventHandler(
                this, &AlertForm::btnDTIReport_Click);

            // 
            // btnHistReport (principal grande)
            // 
            this->btnHistReport->Location = System::Drawing::Point(40, 265);
            this->btnHistReport->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnHistReport->Name = L"btnHistReport";
            this->btnHistReport->Size = System::Drawing::Size(260, 55);
            this->btnHistReport->TabIndex = 10;
            this->btnHistReport->Text = L"Historial de alertas";
            this->btnHistReport->UseVisualStyleBackColor = true;
            this->btnHistReport->Click += gcnew System::EventHandler(
                this, &AlertForm::btnHistReport_Click);

            // 
            // btnReturn (secundario)
            // 
            this->btnReturn->Location = System::Drawing::Point(75, 340);
            this->btnReturn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->btnReturn->Name = L"btnReturn";
            this->btnReturn->Size = System::Drawing::Size(190, 32);
            this->btnReturn->TabIndex = 9;
            this->btnReturn->Text = L"Volver";
            this->btnReturn->UseVisualStyleBackColor = true;
            this->btnReturn->Click += gcnew System::EventHandler(
                this, &AlertForm::btnReturn_Click);

            // 
            // Añadir controles al mainCard
            // 
            this->mainCard->Controls->Add(this->label1);
            this->mainCard->Controls->Add(this->btnMissingObject);
            this->mainCard->Controls->Add(this->btnAltercation);
            this->mainCard->Controls->Add(this->btnDTIReport);
            this->mainCard->Controls->Add(this->btnHistReport);
            this->mainCard->Controls->Add(this->btnReturn);

            // 
            // AlertForm (form)
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(
                static_cast<System::Int32>(5),
                static_cast<System::Int32>(8),
                static_cast<System::Int32>(22));
            this->ClientSize = System::Drawing::Size(380, 465);
            this->Controls->Add(this->mainCard);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(
                resources->GetObject(L"$this.Icon")));
            this->Name = L"AlertForm";
            this->Text = L"Tipo de alerta";

            this->mainCard->ResumeLayout(false);
            this->mainCard->PerformLayout();
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        // --------- LÓGICA (igual que tu versión original) ---------
        System::Void btnMissingObject_Click(System::Object^ sender, System::EventArgs^ e) {
            MissingObjectForm^ form = gcnew MissingObjectForm(Usuario);
            this->Hide();
            form->ShowDialog();
            this->Show();
        }

        System::Void btnAltercation_Click(System::Object^ sender, System::EventArgs^ e) {
            AltercationReportForm^ form = gcnew AltercationReportForm(Usuario);
            this->Hide();
            form->ShowDialog();
            this->Show();
        }

        System::Void btnDTIReport_Click(System::Object^ sender, System::EventArgs^ e) {
            DTIReportForm^ form = gcnew DTIReportForm(Usuario);
            this->Hide();
            form->ShowDialog();
            this->Show();
        }

        System::Void btnReturn_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Close();
        }

        System::Void btnHistReport_Click(System::Object^ sender, System::EventArgs^ e) {
            AlertHistForm^ form = gcnew AlertHistForm(Usuario);
            this->Hide();
            form->ShowDialog();
            this->Show();
        }

        // ------------------- ESTILOS VISUALES -------------------
        void StyleControls()
        {
            // Título
            this->label1->ForeColor = System::Drawing::Color::White;

            // Botones principales
            auto primaryFont = gcnew System::Drawing::Font(
                "Segoe UI", 10, System::Drawing::FontStyle::Bold);

            array<Button^>^ primaryButtons = {
                this->btnMissingObject,
                this->btnAltercation,
                this->btnDTIReport,
                this->btnHistReport
            };

            for each (Button ^ b in primaryButtons)
            {
                b->FlatStyle = FlatStyle::Flat;
                b->FlatAppearance->BorderSize = 0;
                b->BackColor = System::Drawing::Color::FromArgb(0, 140, 255);
                b->ForeColor = System::Drawing::Color::White;
                b->Font = primaryFont;
                UIHelpers::SetRoundedRegionAuto(b);
            }

            // Botón secundario (Volver)
            this->btnReturn->FlatStyle = FlatStyle::Flat;
            this->btnReturn->FlatAppearance->BorderSize = 0;
            this->btnReturn->BackColor = System::Drawing::Color::FromArgb(20, 27, 47);
            this->btnReturn->ForeColor =
                System::Drawing::Color::FromArgb(0, 140, 255);
            this->btnReturn->Font =
                gcnew System::Drawing::Font("Segoe UI", 8, System::Drawing::FontStyle::Regular);
            UIHelpers::SetRoundedRegionAuto(this->btnReturn);

            // Contorno estilo píldora
            this->btnReturn->Paint += gcnew System::Windows::Forms::PaintEventHandler(
                &GUIApp::UIHelpers::OutlineButton_Paint);
        }

        // ------------------- PINTURA PERSONALIZADA -------------------
        System::Void mainCard_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e)
        {
            UIHelpers::RoundedPanel_Paint(sender, e);
        }
    };
}
