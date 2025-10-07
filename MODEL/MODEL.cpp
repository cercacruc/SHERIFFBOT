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


Robot::Robot() {
	ID = 0;
	Nombre = nullptr;
	Zona = nullptr;
}
Robot::Robot(int ID, String^ nombre, String^ zona) {
	this->ID = ID;
	this->Nombre = nombre;
	this->Zona = zona;
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

