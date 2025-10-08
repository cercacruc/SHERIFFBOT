#pragma once

namespace BotController {
	using namespace System::Collections::Generic;
	using namespace BotModel;
	using namespace System;

	public ref class CONTROLLER {
	private:
		List<DatosUsuario^>^ listaUsuarios;
		List<Robot^>^ listaRobots;
	public:
		CONTROLLER();
		void registrarUsuario(int id, String^ nombre, String^ contra, String^ cargo);
		void registrarUsuarioAutoID(String^ nombre, String^ contra, String^ cargo);
		DatosUsuario^ buscarUsuarioID(int id);
		DatosUsuario^ buscarUsuarioNombre(String^ nombre);
		DatosUsuario^ buscarUsuarioCredenciales(String^ nombre, String^ contra);
		bool borrarUsuarioID(int id);
		bool borrarUsuarioNombre(String^ nombre);
		DatosUsuario^ restablecerUsuario(String^ nombre, String^ contranueva, String^ confirmacion);
		DatosUsuario^ modificarUsuarioID(int id, String^ nombre, String^ contra, String^ cargo);
		List <DatosUsuario^>^ GetUsuarios();
		
		void registrarRobot(int id, String^ nombre, String^ zona,Point^ ubicacion);
		Robot^ buscarRobotID(int id);
		Robot^ buscarRobotNombre(String^ nombre);
		bool borrarRobotID(int id);
		bool borrarRobotNombre(String^ nombre);
		Robot^ modificarRobotID(int id, String^ nombre, String^ zona);
		List <Robot^>^ GetRobots();
	};
}
