#include "pch.h"
#include "MODEL.h"

using namespace System;
using namespace BotModel;

DatosUsuario::DatosUsuario() {

}
DatosUsuario::DatosUsuario(int id, String^ nombre, String^ contra, String^ cargo, array<int>^ cantAlertas) {
	this->ID = id;
	this->Nombre = nombre;
	this->Contra = contra;
	this->Cargo = cargo;
	this->cant_alertas = gcnew array<int>(3);

	for (int i = 0; i < 3; i++) {
		this->cant_alertas[i] = 0;
	}
}

Point::Point() {
	x = 0.0;
	y = 0.0;
	Ubicacion = String::Empty;
}
Point::Point(double x, double y, String^ ubicacion) {
	this->x = x;
	this->y = y;
	this->Ubicacion = ubicacion;
}

Robot::Robot() {
	PosicionRobot = gcnew Point();
	Bateria = 100; // Valor por defecto
}
Robot::Robot(int ID, String^ nombre, String^ zona, Point^ ubicacion, String^ caracteristica) {
	this->ID = ID;
	this->Nombre = nombre;
	this->Zona = zona;
	this->PosicionRobot = ubicacion != nullptr ? ubicacion : gcnew Point();
	this->Bateria = 100;
	this->Caracteristicas = caracteristica;
}

Alert::Alert() {
	this->UsuarioID = 0;
	this->UsuarioNombre = String::Empty;
	this->Photo = nullptr;

}
Alert::Alert(int id, DateTime^ fecha, String^ description, String^ lugar, bool solucionado, String^ tipoAlerta) {
	this->ID = id;
	this->Fecha = fecha;
	this->Description = description;
	this->Lugar = lugar;
	this->Solucionado = solucionado;
	this->TipoAlerta = tipoAlerta;

	this->UsuarioID = 0;
	this->UsuarioNombre = String::Empty;
	this->Photo = nullptr;
}

ZonaTrabajo::ZonaTrabajo() {

}

BotModel::ZonaTrabajo::ZonaTrabajo(int ID, double x_min, double x_max, double y_min, double y_max, String^ zona)
{
	this->ID = ID;
	this->x_min = x_min;
	this->x_max = x_max;
	this->y_min = y_min;
	this->y_max = y_max;
	this->zona = zona;
}
