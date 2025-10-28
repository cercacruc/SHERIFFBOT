#include "pch.h"
#include "MODEL.h"

using namespace System;
using namespace BotModel;

DatosUsuario::DatosUsuario() {

}
DatosUsuario::DatosUsuario(int id, String^ nombre, String^ contra, String^ cargo) {
	this->ID = id;
	this->Nombre = nombre;
	this->Contra = contra;
	this->Cargo = cargo;
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

}
Alert::Alert(String^ description, String^ lugar) {
	this->Description = description;
	this->Lugar = lugar;
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

