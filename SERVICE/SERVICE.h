#pragma once

using namespace System;
using namespace BotModel;
using namespace BotPersistance;
using namespace System::Collections::Generic;

namespace BotService {
	public ref class Service{
	public:
		//CRUD Usuarios
		static void registrarUsuario(DatosUsuario^ usuario);
		static int generarAutoID(String^ cargo);
		static DatosUsuario^ buscarUsuarioID(int id);
		static DatosUsuario^ buscarUsuarioNombre(String^ nombre);
		static DatosUsuario^ buscarUsuarioCredenciales(String^ nombre, String^ contra);
		static bool borrarUsuarioID(int id);
		static bool borrarUsuarioNombre(String^ nombre);
		static int restablecerUsuario(String^ usuario, String^ contranueva, String^ confirmacion);
		static int modificarUsuarioID(DatosUsuario^ usuario);
		static List <DatosUsuario^>^ GetUsuarios();

		//CRUD Robots
		static void registrarRobot(Robot^ robot);
		static Robot^ buscarRobotID(int id);
		static Robot^ buscarRobotNombre(String^ nombre);
		static bool borrarRobotID(int id);
		static bool borrarRobotNombre(String^ nombre);
		static int modificarRobotID(Robot^ robot);
		static List <Robot^>^ GetRobots();
		static String^ delimitarZonaTrabajo(double x, double y);
		static List<Robot^>^ listaRobotsDisponibles();

		//CRUC Alert Reports
		static void registrarAlerta(Alert^ alerta);
		static void registrarObjPerdido(ObjPerdido^ objeto);
		static void registrarDTIReport(DTIReport^ reporte);
		static void registrarAlercado(Altercado^ altercado);
		static List<Alert^>^ ShowAlertas();
		static List<ObjPerdido^>^ ShowObjetosPerdidos();
		static List<Altercado^>^ ShowAltercados();
		static List<DTIReport^>^ ShowDTIReport();

		static Alert^ buscarAlerta(int id);
		static ObjPerdido^ buscarObjetoPerdido(int id);
		static Altercado^ buscarAltercado(int id);
		static DTIReport^ buscarDTIReport(int id);
		//Zonas
		static void registrarZona(ZonaTrabajo^ zona);
		static int modificarZona(ZonaTrabajo^ zona);
		static bool eliminarZona(int id);
		static bool buscarZonaID(int id);
		static ZonaTrabajo^ buscarReturnZonaId(int id);
		static List <ZonaTrabajo^>^ GetZonas();


	};
}
