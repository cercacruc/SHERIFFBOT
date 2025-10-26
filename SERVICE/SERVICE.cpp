#include "pch.h"

#include "SERVICE.h"

void BotService::Service::registrarUsuario(DatosUsuario^ usuario) {
	return Persistance::registrarUsuario(usuario);
}
int BotService::Service::generarAutoID(String^ cargo) {
	return Persistance::generarAutoID(cargo);
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
int BotService::Service::restablecerUsuario(String^ usuario, String^ contranueva, String^ confirmacion) {
	return Persistance::restablecerUsuario(usuario, contranueva, confirmacion);
}
int BotService::Service::modificarUsuarioID(DatosUsuario^ usuario) {
	return Persistance::modificarUsuarioID(usuario);
}
List <DatosUsuario^>^ BotService::Service::GetUsuarios() {
	return Persistance::GetUsuarios();
}

//CRUD Robots
void BotService::Service::registrarRobot(Robot^ robot) {
	return Persistance::registrarRobot(robot);
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
int BotService::Service::modificarRobotID(Robot^ robot) {
	return Persistance::modificarRobotID(robot);
}
List <Robot^>^ BotService::Service::GetRobots() {
	return Persistance::GetRobots();
}
String^ BotService::Service::delimitarZonaTrabajo(double x, double y) {
	return Persistance::delimitarZonaTrabajo(x, y);
}

//CRUD Alert Report
void BotService::Service::registrarAlerta(Alert^ alerta) {
	return Persistance::registrarAlerta(alerta);
}


