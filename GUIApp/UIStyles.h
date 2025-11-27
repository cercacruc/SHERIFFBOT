#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

namespace GUIApp {

    // ============================
    //  Helpers de UI reutilizables
    // ============================
    public ref class UIHelpers abstract sealed
    {
    public:
        // -----------------------------------------
        // 1) Región redondeada para cualquier botón
        // -----------------------------------------
        static void SetRoundedRegion(Button^ btn, int radius)
        {
            GraphicsPath^ path = gcnew GraphicsPath();

            int r = radius;
            Rectangle rect = Rectangle(0, 0, btn->Width, btn->Height);
            int d = r * 2;

            path->AddArc(rect.X, rect.Y, d, d, 180, 90);
            path->AddArc(rect.Right - d, rect.Y, d, d, 270, 90);
            path->AddArc(rect.Right - d, rect.Bottom - d, d, d, 0, 90);
            path->AddArc(rect.X, rect.Bottom - d, d, d, 90, 90);
            path->CloseFigure();

            btn->Region = gcnew Region(path);
        }

        // ----------------------------------------------------
        // 2) Borde redondeado celeste (para botones secundarios)
        //    Se usa en el evento Paint del botón.
        // ----------------------------------------------------
        static void OutlineButton_Paint(Object^ sender, PaintEventArgs^ e)
        {
            Button^ b = safe_cast<Button^>(sender);

            e->Graphics->SmoothingMode = SmoothingMode::AntiAlias;

            int r = 18;
            Rectangle rect(0, 0, b->Width - 1, b->Height - 1);
            int d = r * 2;

            GraphicsPath^ path = gcnew GraphicsPath();
            path->AddArc(rect.X, rect.Y, d, d, 180, 90);
            path->AddArc(rect.Right - d, rect.Y, d, d, 270, 90);
            path->AddArc(rect.Right - d, rect.Bottom - d, d, d, 0, 90);
            path->AddArc(rect.X, rect.Bottom - d, d, d, 90, 90);
            path->CloseFigure();

            Pen^ pen = gcnew Pen(Color::FromArgb(0, 140, 255), 1.5f);
            e->Graphics->DrawPath(pen, path);
        }

        // ---------------------------------------------------------
        // 3) Panel / tarjeta redondeada con relleno y borde moderno
        //    Se usa en el evento Paint de un Panel normal.
        // ---------------------------------------------------------
        static void RoundedPanel_Paint(Object^ sender, PaintEventArgs^ e)
        {
            Panel^ p = safe_cast<Panel^>(sender);

            e->Graphics->SmoothingMode = SmoothingMode::AntiAlias;

            int radius = 24;
            Rectangle rect = Rectangle(0, 0, p->Width - 1, p->Height - 1);
            int d = radius * 2;

            GraphicsPath^ path = gcnew GraphicsPath();
            path->AddArc(rect.X, rect.Y, d, d, 180, 90);
            path->AddArc(rect.Right - d, rect.Y, d, d, 270, 90);
            path->AddArc(rect.Right - d, rect.Bottom - d, d, d, 0, 90);
            path->AddArc(rect.X, rect.Bottom - d, d, d, 90, 90);
            path->CloseFigure();

            // Relleno oscuro de la tarjeta
            SolidBrush^ brush = gcnew SolidBrush(Color::FromArgb(20, 27, 47)); // #141B2F
            e->Graphics->FillPath(brush, path);

            // Borde azul cian
            Pen^ pen = gcnew Pen(Color::FromArgb(40, 209, 255), 1.0f);
            e->Graphics->DrawPath(pen, path);
        }
    };

} // namespace GUIApp
