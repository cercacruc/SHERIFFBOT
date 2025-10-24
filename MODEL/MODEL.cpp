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
Robot::Robot(int ID, String^ nombre, String^ zona,Point^ ubicacion) {
	this->ID = ID;
	this->Nombre = nombre;
	this->Zona = zona;
	this->PosicionRobot = ubicacion != nullptr ? ubicacion : gcnew Point();
	this->Bateria = 100;
}
