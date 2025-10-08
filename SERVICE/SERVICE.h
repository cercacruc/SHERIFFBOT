#pragma once

using namespace System;
using namespace BotModel;
using namespace BotPersistance;
using namespace System::Collections::Generic;

namespace BotService {
	public ref class Service{
	public:
		//CRUD Usuarios
		static void registrarUsuario(int id, String^ nombre, String^ contra, String^ cargo);
		static void registrarUsuarioAutoID(String^ nombre, String^ contra, String^ cargo);
		static DatosUsuario^ buscarUsuarioID(int id);
		static DatosUsuario^ buscarUsuarioNombre(String^ nombre);
		static DatosUsuario^ buscarUsuarioCredenciales(String^ nombre, String^ contra);
		static bool borrarUsuarioID(int id);
		static bool borrarUsuarioNombre(String^ nombre);
		static DatosUsuario^ restablecerUsuario(String^ nombre, String^ contranueva, String^ confirmacion);
		static DatosUsuario^ modificarUsuarioID(int id, String^ nombre, String^ contra, String^ cargo);
		static List <DatosUsuario^>^ GetUsuarios();

		//CRUD Robots
		static void registrarRobot(int id, String^ nombre, String^ zona,Point^ ubicacion);
		static Robot^ buscarRobotID(int id);
		static Robot^ buscarRobotNombre(String^ nombre);
		static bool borrarRobotID(int id);
		static bool borrarRobotNombre(String^ nombre);
		static Robot^ modificarRobotID(int id, String^ nombre, String^ zona);
		static List <Robot^>^ GetRobots();
	};
}
