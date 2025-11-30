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
List<Robot^>^ BotService::Service::GetRobotsConAlertas() {
	return Persistance::GetRobotsConAlertas();
}
bool BotService::Service::AsignarAlertaRobot(int robotID, int alertaID) {
	return Persistance::AsignarAlertaRobot(robotID, alertaID);
}
bool BotService::Service::LiberarRobot(int robotID) {
	return Persistance::LiberarRobot(robotID);
}
List<Alert^>^ BotService::Service::GetAlertasPendientes() {
	return Persistance::GetAlertasPendientes();
}

// Conexión con Arduino
bool BotService::Service::ConectarArduino()
{
	int intentos = 0;
	const int maxIntentos = 3;

	while (intentos < maxIntentos) {
		try {
			intentos++;
			Console::WriteLine("🔄 Intento de conexión " + intentos + "/" + maxIntentos);

			// Si ya está conectado, retornar true
			if (ArduinoPort != nullptr && ArduinoPort->IsOpen) {
				Console::WriteLine("✅ Arduino ya está conectado en " + ArduinoPort->PortName);
				return true;
			}

			// Cerrar puerto si existe pero está cerrado
			if (ArduinoPort != nullptr) {
				delete ArduinoPort;
				ArduinoPort = nullptr;
				System::Threading::Thread::Sleep(500); // Pequeña pausa
			}

			// Intentar conexión en COM3
			String^ puertoDeseado = "COM3";
			Console::WriteLine("🎯 Intentando conectar en: " + puertoDeseado);

			ArduinoPort = gcnew SerialPort();
			ArduinoPort->PortName = puertoDeseado;
			ArduinoPort->BaudRate = 9600;
			ArduinoPort->Parity = Parity::None;
			ArduinoPort->DataBits = 8;
			ArduinoPort->StopBits = StopBits::One;
			ArduinoPort->Handshake = Handshake::None;
			ArduinoPort->ReadTimeout = 2000;
			ArduinoPort->WriteTimeout = 2000;

			// Intentar abrir el puerto
			ArduinoPort->Open();

			Console::WriteLine("✅ Puerto " + puertoDeseado + " abierto exitosamente");

			// Esperar para inicialización del Arduino
			System::Threading::Thread::Sleep(3000);

			// Limpiar buffers
			ArduinoPort->DiscardInBuffer();
			ArduinoPort->DiscardOutBuffer();

			// Probar comunicación
			ArduinoPort->WriteLine("TEST");
			System::Threading::Thread::Sleep(1000);

			// Intentar leer respuesta
			if (ArduinoPort->BytesToRead > 0) {
				String^ respuesta = ArduinoPort->ReadLine();
				Console::WriteLine("✅ Arduino responde: " + respuesta);
			}
			else {
				Console::WriteLine("⚠️  Arduino conectado pero no responde (continuando...)");
			}

			Console::WriteLine("🎉 Conexión con Arduino establecida exitosamente");
			return true;
		}
		catch (Exception^ ex) {
			Console::WriteLine("❌ Error en intento " + intentos + ": " + ex->Message);

			// Cerrar puerto si está abierto
			if (ArduinoPort != nullptr) {
				try {
					if (ArduinoPort->IsOpen) {
						ArduinoPort->Close();
					}
					delete ArduinoPort;
					ArduinoPort = nullptr;
				}
				catch (...) {
					// Ignorar errores al limpiar
				}
			}

			// Si es error de acceso denegado, esperar y reintentar
			if (ex->Message->Contains("denegado") || ex->Message->Contains("acceso")) {
				Console::WriteLine("💡 Puerto ocupado, reintentando en 2 segundos...");
				System::Threading::Thread::Sleep(2000);
			}
			else {
				// Otro tipo de error, no reintentar
				break;
			}
		}
	}

	Console::WriteLine("❌ No se pudo conectar después de " + maxIntentos + " intentos");
	return false;
}

bool BotService::Service::DesconectarArduino()
{
    try {
        if (ArduinoPort != nullptr && ArduinoPort->IsOpen) {
            ArduinoPort->Close();
            Console::WriteLine("Desconectado de Arduino");
        }
        return true;
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error desconectando Arduino: " + ex->Message);
        return false;
    }
}

bool BotService::Service::EnviarComandoArduino(String^ comando)
{
    try {
        if (ArduinoPort == nullptr || !ArduinoPort->IsOpen) {
            if (!ConectarArduino()) {
                return false;
            }
        }

        // Enviar comando con terminación de nueva línea
        ArduinoPort->WriteLine(comando);
        Console::WriteLine("Comando enviado a Arduino: " + comando);

        // Opcional: Leer respuesta de Arduino
        System::Threading::Thread::Sleep(100); // Pequeña pausa para que Arduino procese
        
        if (ArduinoPort->BytesToRead > 0) {
            String^ respuesta = ArduinoPort->ReadLine();
            Console::WriteLine("Arduino responde: " + respuesta);
        }

        return true;
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error enviando comando a Arduino: " + ex->Message);
        return false;
    }
}

bool BotService::Service::EncenderLED()
{
    return EnviarComandoArduino("LED_ON");
}

bool BotService::Service::ApagarLED()
{
    return EnviarComandoArduino("LED_OFF");
}

bool BotService::Service::IsArduinoConectado()
{
    return (ArduinoPort != nullptr && ArduinoPort->IsOpen);
}

bool BotService::Service::LiberarPuertoCOM3()
{
	try {
		// Cerrar conexión actual si existe
		if (ArduinoPort != nullptr) {
			if (ArduinoPort->IsOpen) {
				ArduinoPort->Close();
				Console::WriteLine("✅ Puerto COM3 cerrado");
			}
			delete ArduinoPort;
			ArduinoPort = nullptr;
		}

		// Pequeña pausa para que el sistema libere el puerto
		System::Threading::Thread::Sleep(1000);
		return true;
	}
	catch (Exception^ ex) {
		Console::WriteLine("❌ Error liberando puerto: " + ex->Message);
		return false;
	}
}
bool BotService::Service::EnviarComandoDirecto(String^ comando)
{
	try {
		if (ArduinoPort == nullptr || !ArduinoPort->IsOpen) {
			if (!ConectarArduino()) {
				Console::WriteLine("❌ No se pudo conectar al Arduino para enviar comando: " + comando);
				return false;
			}
		}

		// Enviar comando directo
		ArduinoPort->WriteLine(comando);
		Console::WriteLine("📤 Comando enviado: " + comando);

		// Pequeña pausa para procesamiento
		System::Threading::Thread::Sleep(100);

		// Leer respuesta si hay
		if (ArduinoPort->BytesToRead > 0) {
			String^ respuesta = ArduinoPort->ReadLine();
			Console::WriteLine("📥 Arduino responde: " + respuesta);
		}

		return true;
	}
	catch (Exception^ ex) {
		Console::WriteLine("❌ Error enviando comando '" + comando + "': " + ex->Message);
		return false;
	}
}

// Comando específico para LEDs
bool BotService::Service::ComandoLED(int numero, bool encender)
{
	if (numero < 1 || numero > 6) {
		Console::WriteLine("❌ Número de LED debe ser entre 1 y 6");
		return false;
	}

	String^ comando = String::Format("LED{0}_{1}", numero, encender ? "ON" : "OFF");
	return EnviarComandoDirecto(comando);
}

// Comando para todos los LEDs
bool BotService::Service::ComandoTodosLEDs(bool encender)
{
	String^ comando = encender ? "ALL_ON" : "ALL_OFF";
	return EnviarComandoDirecto(comando);
}

// Comando de prueba
bool BotService::Service::ComandoTest()
{
	return EnviarComandoDirecto("TEST");
}

bool BotService::Vehiculo::Connect() {
	if (carController == nullptr) {
		// Inicializar con los parámetros correctos
		carController = gcnew CarController("tcp://broker.hivemq.com:1883", "R08/teleop/cmd");
	}
	return carController->Connect();
}
void BotService::Vehiculo::Disconnect() {
	if (carController)
		carController->Disconnect();
}
void BotService::Vehiculo::Forward() {
	if (carController) carController->Forward();
}
void BotService::Vehiculo::Backward() {
	if (carController) carController->Backward();
}
void BotService::Vehiculo::Left() {
	if (carController) carController->Left();
}
void BotService::Vehiculo::Right() {
	if (carController) carController->Right();
}
void BotService::Vehiculo::Stop() {
	if (carController) carController->Stop();
}
void BotService::Vehiculo::TurnRight() {
	if (carController) carController->TurnRight();
}
void BotService::Vehiculo::TurnLeft() {
	if (carController) carController->TurnLeft();
}
