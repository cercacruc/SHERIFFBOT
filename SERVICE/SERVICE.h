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

		//CRUC Alert Reports
		static void registrarAlerta(Alert^ alerta);
	};
}
