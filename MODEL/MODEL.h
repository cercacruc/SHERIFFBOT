#pragma once

using namespace System;
namespace BotModel {
	[Serializable]
	public ref class DatosUsuario {
	public:
		property String^ Nombre;
		property String^ Contra;//Contraseña
		property String^ Cargo;
		property int ID;
		

		DatosUsuario();
		DatosUsuario(int ID, String^ nombre, String^ contra, String^ cargo);
	};

	[Serializable]
	public ref class Point {
	public:
		//Medidas en metros
		property double x;
		property double y;
		property String^ Ubicacion;

		Point();
		Point(double x, double y, String^ ubicacion);
	};

	[Serializable]
	public ref class Robot {
	public:
		property int ID;
		property String^ Nombre;
		property String^ Zona;
		property Point^ PosicionRobot;
		property int Bateria;
		property array<Byte>^ Photo;

		Robot();
		Robot(int ID, String^ nombre, String^ zona, Point^ ubicacion);
	};
}
