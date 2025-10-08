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

	public ref class Point {
	private:
		//Medidas en metros
		double x;
		double y;
		String^ Ubicacion;
	public:
		Point();
		Point(double x, double y, String^ ubicacion);
		double getX();
		void setX(double nuevoX);
		double getY();
		void setY(double nuevoY);
		String^ getUbicacion();
		void setUbicacion(String^ ubicacion);
	};

	public ref class Robot {
	private:
		int ID;
		String^ Nombre;
		String^ Zona;
		Point^ PosicionRobot;
	public:
		Robot();
		Robot(int ID, String^ nombre, String^ zona,Point^ ubicacion);
		int getID();
		void setID(int nuevoID);
		String^ getNombre();
		void setNombre(String^ nuevoNombre);
		String^ getZona();
		void setZona(String^ nuevaZona);
		Point^ getPosicion();
		void setPosicion(Point^ nuevaPosicion);
	};

}
