#pragma once

using namespace System;
using namespace BotModel;
using namespace BotPersistance;
using namespace System::Collections::Generic;

using namespace System::Net::WebSockets;
using namespace System::Threading;
using namespace System::Text;
using namespace System::Collections::Generic;

namespace BotService {
	public ref class Service {
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
		static void registrarAltercado(Altercado^ altercado);
		static List<Alert^>^ ShowAlertas();
		static List<ObjPerdido^>^ ShowObjetosPerdidos();
		static List<Altercado^>^ ShowAltercados();
		static List<DTIReport^>^ ShowDTIReport();

		static Alert^ buscarAlerta(int id);
		static Alert^ buscarAlertaDescrip(String^ descrip);
		static ObjPerdido^ buscarObjetoPerdido(int id);
		static Altercado^ buscarAltercado(int id);
		static DTIReport^ buscarDTIReport(int id);
		static int modificarAlerta(Alert^ alerta);
		static bool eliminarAlerta(int id);
		static List<Alert^>^ GetAlertasPorUsuario(int usuarioID);
		//Zonas
		static void registrarZona(ZonaTrabajo^ zona);
		static int modificarZona(ZonaTrabajo^ zona);
		static bool eliminarZona(int id);
		static bool buscarZonaID(int id);
		static ZonaTrabajo^ buscarReturnZonaId(int id);
		static List <ZonaTrabajo^>^ GetZonas();


	};
	public ref class MQTTClient {
	private:
		static ClientWebSocket^ webSocket;
		static String^ brokerUrl;
		static bool conectado;

	public:
		property bool EstaConectado;

		MQTTClient();
		static bool Conectar();
		static bool EnviarComando(String^ comando);
		static bool EnviarComandoConVelocidad(String^ comando, int velocidad);

		// Métodos específicos para cada movimiento
		static bool Adelante();
		static bool Atras();
		static bool Izquierda();
		static bool Derecha();
		static bool RotarIzquierda();
		static bool RotarDerecha();
		static bool Detener();

		// Métodos con velocidad
		static bool AdelanteConVelocidad(int velocidad);
		static bool AtrasConVelocidad(int velocidad);
		static bool IzquierdaConVelocidad(int velocidad);
		static bool DerechaConVelocidad(int velocidad);

		// Métodos para desconectar
		static void Desconectar();
		~MQTTClient();
	};
}