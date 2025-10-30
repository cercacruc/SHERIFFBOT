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
		property array<int>^ cant_alertas;
		//property array<Byte>^ Photo;

		DatosUsuario();
		DatosUsuario(int ID, String^ nombre, String^ contra, String^ cargo, array<int>^ cantAlertas);
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
		property bool Disponibilidad;
		property String^ Caracteristicas;

		Robot();
		Robot(int ID, String^ nombre, String^ zona, Point^ ubicacion, String^ caracteristica);
	};

	[Serializable]
		public ref class Alert : DatosUsuario {
	public:
		property int id;
		property DateTime^ Fecha;
		property String^ Description;
		property array<Byte>^ Photo;
		property String^ Lugar;
		property bool Solucionado;
		
		Alert();
		Alert(String^ description, String^ lugar);
	};
	[Serializable]
	public ref class DTIReport : Alert {
	public:
		property String^ tipoReporte;
	};
	[Serializable]
	public ref class Altercado : Alert {
		public:
			
	};
	[Serializable]
	public ref class ObjPerdido : Alert {
		public:
			property String^ ObjetoEncontrado;
	};
	[Serializable]
		public ref class ZonaTrabajo {
		public:
			property int ID;
			property double x_min;
			property double x_max;
			property double y_min;
			property double y_max;
			property String^ zona;
			ZonaTrabajo();
			ZonaTrabajo(int ID, double x_min, double x_max, double y_min, double y_max, String^ zona);
	};
}
