#include "pch.h"

#include "SERVICE.h"

void BotService::Service::registrarUsuario(DatosUsuario^ usuario) {
	return Persistance::registrarUsuario(usuario);
}
int BotService::Service::generarAutoID(String^ cargo) {
	return Persistance::generarAutoID(cargo);
}
DatosUsuario^ BotService::Service::buscarUsuarioID(int id) {
	return Persistance::buscarUsuarioID(id);
}
DatosUsuario^ BotService::Service::buscarUsuarioNombre(String^ nombre) {
	return Persistance::buscarUsuarioNombre(nombre);
}
DatosUsuario^ BotService::Service::buscarUsuarioCredenciales(String^ nombre, String^ contra) {
	return Persistance::buscarUsuarioCredenciales(nombre, contra);
}
bool BotService::Service::borrarUsuarioID(int id) {
	return Persistance::borrarUsuarioID(id);
}
bool BotService::Service::borrarUsuarioNombre(String^ nombre) {
	return Persistance::borrarUsuarioNombre(nombre);
}
int BotService::Service::restablecerUsuario(String^ usuario, String^ contranueva, String^ confirmacion) {
	return Persistance::restablecerUsuario(usuario, contranueva, confirmacion);
}
int BotService::Service::modificarUsuarioID(DatosUsuario^ usuario) {
	return Persistance::modificarUsuarioID(usuario);
}
List <DatosUsuario^>^ BotService::Service::GetUsuarios() {
	return Persistance::GetUsuarios();
}

//CRUD Robots
void BotService::Service::registrarRobot(Robot^ robot) {
	return Persistance::registrarRobot(robot);
}
Robot^ BotService::Service::buscarRobotID(int id) {
	return Persistance::buscarRobotID(id);
}
Robot^ BotService::Service::buscarRobotNombre(String^ nombre) {
	return Persistance::buscarRobotNombre(nombre);
}
bool BotService::Service::borrarRobotID(int id) {
	return Persistance::borrarRobotID(id);
}
bool BotService::Service::borrarRobotNombre(String^ nombre) {
	return Persistance::borrarRobotNombre(nombre);
}
int BotService::Service::modificarRobotID(Robot^ robot) {
	return Persistance::modificarRobotID(robot);
}
List <Robot^>^ BotService::Service::GetRobots() {
	return Persistance::GetRobots();
}
String^ BotService::Service::delimitarZonaTrabajo(double x, double y) {
	return Persistance::delimitarZonaTrabajo(x, y);
}
List<Robot^>^ BotService::Service::listaRobotsDisponibles() {
	return Persistance::listaRobotsDisponibles();
}

//CRUD Alert Report
void BotService::Service::registrarAlerta(Alert^ alerta) {
	return Persistance::registrarAlerta(alerta);
}
void BotService::Service::registrarObjPerdido(ObjPerdido^ objeto) {
	return Persistance::registrarObjPerdido(objeto);
}
void BotService::Service::registrarDTIReport(DTIReport^ reporte) {
	return Persistance::registrarDTIReport(reporte);
}
void BotService::Service::registrarAltercado(Altercado^ altercado) {
	return Persistance::registrarAltercado(altercado);
}
List<Alert^>^ BotService::Service::ShowAlertas() {
	return Persistance::ShowAlertas();
}
List<ObjPerdido^>^ BotService::Service::ShowObjetosPerdidos() {
	return Persistance::ShowObjetosPerdidos();
}
List<Altercado^>^ BotService::Service::ShowAltercados() {
	return Persistance::ShowAltercados();
}
List<DTIReport^>^ BotService::Service::ShowDTIReport() {
	return Persistance::ShowDTIReport();
}
Alert^ BotService::Service::buscarAlerta(int id) {
	return Persistance::buscarAlerta(id);
}
Alert^ BotService::Service::buscarAlertaDescrip(String^ descrip) {
	return Persistance::buscarAlertaDescrip(descrip);
}
ObjPerdido^ BotService::Service::buscarObjetoPerdido(int id) {
	return Persistance::buscarObjetoPerdido(id);
}
Altercado^ BotService::Service::buscarAltercado(int id) {
	return Persistance::buscarAltercado(id);
}
DTIReport^ BotService::Service::buscarDTIReport(int id) {
	return Persistance::buscarDTIReport(id);
}
List<Alert^>^ BotService::Service::GetAlertasPorUsuario(int usuarioID) {
	return Persistance::GetAlertasPorUsuario(usuarioID);
}

//CRUD zonas de trabajo
void BotService::Service::registrarZona(ZonaTrabajo^ zona) {
	return Persistance::registrarZona(zona);
}
int BotService::Service::modificarZona(ZonaTrabajo^ zona) {
	return Persistance::modificarZona(zona);
}
bool BotService::Service::eliminarZona(int id) {
	return Persistance::eliminarZona(id);
}
bool BotService::Service::buscarZonaID(int id) {
	return Persistance::buscarZonaID(id);
}
ZonaTrabajo^ BotService::Service::buscarReturnZonaId(int id) {
	return Persistance::buscarReturnZonaId(id);
}
List <ZonaTrabajo^>^ BotService::Service::GetZonas() {
	return Persistance::GetZonas();
}
bool BotService::Service::eliminarAlerta(int id) {
	return Persistance::eliminarAlerta(id);
}
int BotService::Service::modificarAlerta(Alert^ alerta) {
	return Persistance::modificarAlerta(alerta);
}


//Cosas para la conexión con el carro
BotService::MQTTClient::MQTTClient() {
	brokerUrl = "ws://broker.hivemq.com:8884/mqtt";
	conectado = false;
}

bool BotService::MQTTClient::Conectar()
{
	try {
		if (conectado) {
			return true;
		}

		webSocket = gcnew ClientWebSocket();
		auto token = CancellationToken::None;

		auto connectTask = webSocket->ConnectAsync(gcnew Uri(brokerUrl), token);

		// Esperar con timeout
		if (connectTask->Wait(5000)) // 5 segundos timeout
		{
			if (webSocket->State == WebSocketState::Open)
			{
				conectado = true;
				Console::WriteLine("Conectado al broker MQTT via WebSockets");
				return true;
			}
		}
		else
		{
			Console::WriteLine("Error: Timeout en la conexión");
		}

		return false;
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error conectando: " + ex->Message);
		conectado = false;
		return false;
	}
}

bool BotService::MQTTClient::EnviarComando(String^ comando)
{
	try
	{
		if (!conectado && !Conectar())
		{
			Console::WriteLine("No conectado, intentando reconectar...");
			return false;
		}

		String^ mensaje = String::Format("{{\"cmd\":\"{0}\"}}", comando);
		array<unsigned char>^ bytes = Encoding::UTF8->GetBytes(mensaje);
		ArraySegment<unsigned char> segment(bytes);

		auto sendTask = webSocket->SendAsync(segment, WebSocketMessageType::Text, true, CancellationToken::None);

		if (sendTask->Wait(3000))
		{
			Console::WriteLine("Comando enviado: " + mensaje);
			return true;
		}
		else
		{
			Console::WriteLine("Timeout enviando comando");
			conectado = false;
			return false;
		}
	}
	catch (Exception^ ex)
	{
		Console::WriteLine("Error enviando comando: " + ex->Message);
		conectado = false;
		return false;
	}
}

bool BotService::MQTTClient::EnviarComandoConVelocidad(String^ comando, int velocidad)
{
	try
	{
		if (!conectado && !Conectar())
		{
			Console::WriteLine("No conectado, intentando reconectar...");
			return false;
		}

		// Crear y enviar mensaje directamente
		String^ mensaje = String::Format("{{\"cmd\":\"{0}\",\"speed\":{1}}}", comando, velocidad);
		array<unsigned char>^ bytes = Encoding::UTF8->GetBytes(mensaje);
		ArraySegment<unsigned char> segment(bytes);

		auto sendTask = webSocket->SendAsync(segment, WebSocketMessageType::Text, true, CancellationToken::None);

		if (sendTask->Wait(3000))
		{
			Console::WriteLine("Comando con velocidad enviado: " + mensaje);
			return true;
		}
		else
		{
			Console::WriteLine("Timeout enviando comando con velocidad");
			conectado = false;
			return false;
		}
	}
	catch (Exception^ ex)
	{
		Console::WriteLine("Error enviando comando con velocidad: " + ex->Message);
		conectado = false;
		return false;
	}
}

bool BotService::MQTTClient::Adelante()
{
	return EnviarComando("w");
}

bool BotService::MQTTClient::Atras()
{
	return EnviarComando("s");
}

bool BotService::MQTTClient::Izquierda()
{
	return EnviarComando("a");
}

bool BotService::MQTTClient::Derecha()
{
	return EnviarComando("d");
}

bool BotService::MQTTClient::RotarIzquierda()
{
	return EnviarComando("q");
}

bool BotService::MQTTClient::RotarDerecha()
{
	return EnviarComando("e");
}

bool BotService::MQTTClient::Detener()
{
	return EnviarComando("x");
}

bool BotService::MQTTClient::AdelanteConVelocidad(int velocidad)
{
	return EnviarComandoConVelocidad("w", velocidad);
}

bool BotService::MQTTClient::AtrasConVelocidad(int velocidad)
{
	return EnviarComandoConVelocidad("s", velocidad);
}

bool BotService::MQTTClient::IzquierdaConVelocidad(int velocidad)
{
	return EnviarComandoConVelocidad("a", velocidad);
}

bool BotService::MQTTClient::DerechaConVelocidad(int velocidad)
{
	return EnviarComandoConVelocidad("d", velocidad);
}

void BotService::MQTTClient::Desconectar()
{
	try
	{
		if (webSocket != nullptr && webSocket->State == WebSocketState::Open)
		{
			auto closeTask = webSocket->CloseAsync(WebSocketCloseStatus::NormalClosure, "Desconexión", CancellationToken::None);
			closeTask->Wait(2000);
		}
	}
	catch (Exception^ ex)
	{
		// Ignorar errores en desconexión
	}
	finally
	{
		conectado = false;
		if (webSocket != nullptr)
		{
			//webSocket->Dispose();
			webSocket = nullptr;
		}
	}
}

BotService::MQTTClient::~MQTTClient()
{
	Desconectar();
}

