#include "pch.h"
#include "MODEL.h"

using namespace System;
using namespace BotModel;

DatosUsuario::DatosUsuario() {
	ID = 0;
	Nombre = nullptr;
	Contra = nullptr;
	Cargo = nullptr;
}

DatosUsuario::DatosUsuario(int id, String^ nombre, String^ contra, String^ cargo) {
	this->ID = id;
	this->Nombre = nombre;
	this->Contra = contra;
	this->Cargo = cargo;
}
int DatosUsuario::getID() {
	return this->ID;
}
void DatosUsuario::setID(int nuevoID) {
	this->ID = nuevoID;
}

String^ DatosUsuario::getNombre() {
	return this->Nombre;
}
void DatosUsuario::setNombre(String^ nuevoNombre) {
	this->Nombre = nuevoNombre;
}

String^ DatosUsuario::getContrasena() {
	return this->Contra;
}
void DatosUsuario::setContrasena(String^ nuevaContraseña) {
	this->Contra = nuevaContraseña;
}

String^ DatosUsuario::getCargo() {
	return this->Cargo;
}
void DatosUsuario::setCargo(String^ nuevoCargo) {
	this->Cargo = nuevoCargo;
}

Point::Point() {
	this->x = 0;
	this->y = 0;
	this->Ubicacion = nullptr;
}
Point::Point(double x, double y, String^ ubicacion) {
	this->x = x;
	this->y = y;
	this->Ubicacion = ubicacion;
}
double Point::getX() {
	return this->x;
}
void Point::setX(double nuevoX) {
	this->x = nuevoX;
}
double Point::getY() {
	return this->y;
}
void Point::setY(double nuevoY) {
	this->y = nuevoY;
}
String^ Point::getUbicacion() {
	return this->Ubicacion;
}
void Point::setUbicacion(String^ ubicacion) {
	this->Ubicacion = ubicacion;
}


Robot::Robot() {
	ID = 0;
	Nombre = nullptr;
	Zona = nullptr;
}
Robot::Robot(int ID, String^ nombre, String^ zona,Point^ ubicacion) {
	this->ID = ID;
	this->Nombre = nombre;
	this->Zona = zona;
	this->PosicionRobot = ubicacion;
}
int Robot::getID() {
	return this->ID;
}
void Robot::setID(int nuevoID) {
	this->ID = nuevoID;
}
String^ Robot::getNombre() {
	return this->Nombre;
}
void Robot::setNombre(String^ nuevoNombre) {
	this->Nombre = nuevoNombre;

}
String^ Robot::getZona() {
	return this->Zona;
}
void Robot::setZona(String^ nuevaZona) {
	this->Zona = nuevaZona;
}
Point^ Robot::getPosicion() {
	return this->PosicionRobot;
}
void Robot::setPosicion(Point^ nuevaPosicion) {
	this->PosicionRobot = nuevaPosicion;
}

