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
List<Robot^>^ BotService::Service::listaRobotsDisponibles() {
	return Persistance::listaRobotsDisponibles();
}

//CRUD Alert Report
void BotService::Service::registrarAlerta(Alert^ alerta) {
	return Persistance::registrarAlerta(alerta);
}
void BotService::Service::registrarObjPerdido(ObjPerdido^ objeto) {
	return Persistance::registrarObjPerdido(objeto);
}
void BotService::Service::registrarDTIReport(DTIReport^ reporte) {
	return Persistance::registrarDTIReport(reporte);
}
void BotService::Service::registrarAltercado(Altercado^ altercado) {
	return Persistance::registrarAltercado(altercado);
}
List<Alert^>^ BotService::Service::ShowAlertas() {
	return Persistance::ShowAlertas();
}
List<ObjPerdido^>^ BotService::Service::ShowObjetosPerdidos() {
	return Persistance::ShowObjetosPerdidos();
}
List<Altercado^>^ BotService::Service::ShowAltercados() {
	return Persistance::ShowAltercados();
}
List<DTIReport^>^ BotService::Service::ShowDTIReport() {
	return Persistance::ShowDTIReport();
}
Alert^ BotService::Service::buscarAlerta(int id) {
	return Persistance::buscarAlerta(id);
}
ObjPerdido^ BotService::Service::buscarObjetoPerdido(int id) {
	return Persistance::buscarObjetoPerdido(id);
}
Altercado^ BotService::Service::buscarAltercado(int id) {
	return Persistance::buscarAltercado(id);
}
DTIReport^ BotService::Service::buscarDTIReport(int id) {
	return Persistance::buscarDTIReport(id);
}

//CRUD zonas de trabajo
void BotService::Service::registrarZona(ZonaTrabajo^ zona) {
	return Persistance::registrarZona(zona);
}
int BotService::Service::modificarZona(ZonaTrabajo^ zona) {
	return Persistance::modificarZona(zona);
}
bool BotService::Service::eliminarZona(int id) {
	return Persistance::eliminarZona(id);
}
bool BotService::Service::buscarZonaID(int id) {
	return Persistance::buscarZonaID(id);
}
ZonaTrabajo^ BotService::Service::buscarReturnZonaId(int id) {
	return Persistance::buscarReturnZonaId(id);
}
List <ZonaTrabajo^>^ BotService::Service::GetZonas() {
	return Persistance::GetZonas();
}



