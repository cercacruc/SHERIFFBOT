#include "pch.h"

#include "SERVICE.h"

void BotService::Service::registrarUsuario(int id, String^ nombre, String^ contra, String^ cargo) {
	return Persistance::registrarUsuario(id, nombre, contra, cargo);
}
void BotService::Service::registrarUsuarioAutoID(String^ nombre, String^ contra, String^ cargo) {
	return Persistance::registrarUsuarioAutoID(nombre, contra, cargo);
}
DatosUsuario^ BotService::Service::buscarUsuarioID(int id) {
	return Persistance::buscarUsuarioID(id);
}
DatosUsuario^ BotService::Service::buscarUsuarioNombre(String^ nombre) {
	return Persistance::buscarUsuarioNombre(nombre);
}
DatosUsuario^ BotService::Service::buscarUsuarioCredenciales(String^ nombre, String^ contra) {
	return Persistance::buscarUsuarioCredenciales(nombre, contra);
}
bool BotService::Service::borrarUsuarioID(int id) {
	return Persistance::borrarUsuarioID(id);
}
bool BotService::Service::borrarUsuarioNombre(String^ nombre) {
	return Persistance::borrarUsuarioNombre(nombre);
}
DatosUsuario^ BotService::Service::restablecerUsuario(String^ nombre, String^ contranueva, String^ confirmacion) {
	return Persistance::restablecerUsuario(nombre, contranueva, confirmacion);
}
DatosUsuario^ BotService::Service::modificarUsuarioID(int id, String^ nombre, String^ contra, String^ cargo) {
	return Persistance::modificarUsuarioID(id, nombre, contra, cargo);
}
List <DatosUsuario^>^ BotService::Service::GetUsuarios() {
	return Persistance::GetUsuarios();
}

//CRUD Robots
void BotService::Service::registrarRobot(int id, String^ nombre, String^ zona, Point^ ubicacion) {
	return Persistance::registrarRobot(id, nombre, zona,ubicacion);
}
Robot^ BotService::Service::buscarRobotID(int id) {
	return Persistance::buscarRobotID(id);
}
Robot^ BotService::Service::buscarRobotNombre(String^ nombre) {
	return Persistance::buscarRobotNombre(nombre);
}
bool BotService::Service::borrarRobotID(int id) {
	return Persistance::borrarRobotID(id);
}
bool BotService::Service::borrarRobotNombre(String^ nombre) {
	return Persistance::borrarRobotNombre(nombre);
}
Robot^ BotService::Service::modificarRobotID(int id, String^ nombre, String^ zona) {
	return Persistance::modificarRobotID(id, nombre, zona);
}
List <Robot^>^ BotService::Service::GetRobots() {
	return Persistance::GetRobots();
}
static void delimitarZonaTrabajo(Point^ x, Point^ y, String^ zonaTrabajo) {
	return Persistance::delimitarZonaTrabajo(x, y, zonaTrabajo);
}

