#pragma once

using namespace System;
using namespace BotModel;
using namespace System::Collections::Generic;

namespace BotPersistance {
	public ref class Persistance{
	private:
		static List<DatosUsuario^>^ listaUsuarios = gcnew List<DatosUsuario^>();
		static List<Robot^>^ listaRobots = gcnew List<Robot^>();
		static List<Point^>^ listPoints = gcnew List<Point^>();
		static List<ZonaTrabajo^>^ listaZonas = gcnew List<ZonaTrabajo^>;

		static void PersistTextFileUsers(String^ fileName, List<DatosUsuario^>^ lista);
		static Object^ LoadUsuariosFromTextFile(String^ fileName);
		/*static void PersistXMLFileRobots(String^ fileName, Object^ persistObject);
		static Object^ LoadRobotsFromXMLFile(String^ fileName);*/
		static void PersistTextFileRobots(String^ fileName, List<Robot^>^ lista);
		static Object^ LoadRobotsFromTextFile(String^ fileName);

		static void PersistBinaryFile(String^ fileName, Object^ persistObject);
		static Object^ LoadBinaryFile(String^ fileName);


		//vista de reportes
		static List<Alert^>^ listaReportesAlertas = gcnew List<Alert^>();

		static void PersistTxtFileZonas(String^ fileName, List<ZonaTrabajo^>^ lista);
		static Object^ LoadZonasFormTxtFile(String^ fileName);
		static void PersistTxtFilePoint(String^ fileName, List<Point^>^ lista);
		static Object^ LoadPointsFormTxtFile(String^ fileName);
		

	public:
		//Datos de guardado
		static String^ fileUsersName = "usuarios.txt";
		static String^ fileRobotName = "robots.txt";
		static String^ fileBinUsers = "usuarios.bin";
		static String^ fileBinRobots = "robos.bin";

		static String^ fileAlertReport = "alertReport.txt";
		static String^ fileBinAlertReport = "alertReport.bin";
		static String^ fileZonaTrabajo = "Zonas.txt";
		static String^ filePoints = "Point.txt";


		//CRUD Usuarios
		static void registrarUsuario(DatosUsuario^ usuario);//modificado
		static int generarAutoID(String^ cargo); //nueva función
		static DatosUsuario^ buscarUsuarioID(int id);
		static DatosUsuario^ buscarUsuarioNombre(String^ nombre);
		static DatosUsuario^ buscarUsuarioCredenciales(String^ nombre, String^ contra);
		static bool borrarUsuarioID(int id);
		static bool borrarUsuarioNombre(String^ nombre);//modificado en proceso
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
		static Point^ getPoint(double x, double y);
		static List<Robot^>^ listaRobotsDisponibles();

		//CRUD Alert Report
		static void registrarAlerta(Alert^ alerta);
		static void registrarObjPerdido(ObjPerdido^ objeto);
		static void registrarDTIReport(DTIReport^ reporte);
		static void registrarAltercado(Altercado^ altercado);
		static List<Alert^>^ ShowAlertas();
		static List<ObjPerdido^>^ ShowObjetosPerdidos();
		static List<Altercado^>^ ShowAltercados();
		static List<DTIReport^>^ ShowDTIReport();
		static Alert^ buscarAlerta(int id);
		static ObjPerdido^ buscarObjetoPerdido(int id);
		static Altercado^ buscarAltercado(int id);
		static DTIReport^ buscarDTIReport(int id);
		static int modificarAlerta(Alert^ alerta);
		static bool eliminarAlerta(int id);

		static void registrarZona(ZonaTrabajo^ zona);
		static int modificarZona(ZonaTrabajo^ zona);
		static bool eliminarZona(int id);
		static bool buscarZonaID(int id);
		static ZonaTrabajo^ buscarReturnZonaId(int id);
		static List<ZonaTrabajo^>^ GetZonas();
	};
}
