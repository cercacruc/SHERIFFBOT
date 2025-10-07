#pragma once

namespace BotModel {
	using namespace System;
	public ref class DatosUsuario {
	private:
		String^ Nombre;
		String^ Contra;//Contraseña
		String^ Cargo;
		int ID;
	public:
		DatosUsuario();
		DatosUsuario(int ID, String^ nombre, String^ contra, String^ cargo);
		int getID();
		void setID(int nuevoID);
		String^ getNombre();
		void setNombre(String^ nuevoNombre);
		String^ getContrasena();
		void setContrasena(String^ nuevaContraseña);
		String^ getCargo();
		void setCargo(String^ nuevoCargo);
	};

	public ref class Robot {
	private:
		int ID;
		String^ Nombre;
		String^ Zona;
	public:
		Robot();
		Robot(int ID, String^ nombre, String^ zona);
		int getID();
		void setID(int nuevoID);
		String^ getNombre();
		void setNombre(String^ nuevoNombre);
		String^ getZona();
		void setZona(String^ nuevaZona);
	};
}
