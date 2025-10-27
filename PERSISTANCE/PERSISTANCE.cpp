#include "pch.h"
#include "PERSISTANCE.h"

using namespace System::IO;
using namespace System::Xml::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System;
using namespace System::Collections::Generic;

//funciones del robot en persistance
void BotPersistance::Persistance::registrarRobot(Robot^ robot) {  
    listaRobots->Add(robot);
    //PersistTextFileRobots(fileRobotName, listaRobots);
    PersistBinaryFile(fileBinRobots, listaRobots);
}
Robot^ BotPersistance::Persistance::buscarRobotID(int id) {
    for each (Robot ^ robot in listaRobots) {
        if (robot->ID == id) {
            return robot;
        }
    }
    return nullptr;
}
Robot^ BotPersistance::Persistance::buscarRobotNombre(String^ nombre) {
    for each (Robot ^ r in listaRobots) {
        if (r->Nombre->Equals(nombre)) {
            return r;
        }
    }
    return nullptr;
}
bool BotPersistance::Persistance::borrarRobotID(int id) {
    for (int i = 0; i < listaRobots->Count; i++) {
        if (listaRobots[i]->ID == id) {
            listaRobots->RemoveAt(i);
            //PersistTextFileRobots(fileRobotName, listaRobots);
            PersistBinaryFile(fileBinRobots, listaRobots);
            return true;
        }
    }
    return false;
}
bool BotPersistance::Persistance::borrarRobotNombre(String^ nombre) {
    for (int i = 0; i < listaRobots->Count; i++) {
        if (listaRobots[i]->Nombre->Equals(nombre)) {
            listaRobots->RemoveAt(i);
            //PersistTextFileRobots(fileRobotName, listaRobots);
            PersistBinaryFile(fileBinRobots, listaRobots);
            return true;
        }
    }
    return false;
}
int BotPersistance::Persistance::modificarRobotID(Robot^ robot) {
    for (int i = 0; i < listaRobots->Count; i++) {
        if (listaRobots[i]->ID == robot->ID) {
            listaRobots[i] = robot;
            //PersistTextFileRobots(fileRobotName, listaRobots);
            PersistBinaryFile(fileBinRobots, listaRobots);
            return 1;
        }
    }
    return 0;
}
List <Robot^>^ BotPersistance::Persistance::GetRobots() {
    Object^ res = LoadBinaryFile(fileBinRobots);
    if (res != nullptr) {
        //listaRobots = (List<Robot^>^) LoadRobotsFromTextFile(fileRobotName);
        listaRobots = (List<Robot^>^)res;
    }
    return listaRobots;
}



//funciones de usuario en persistance
void BotPersistance::Persistance::registrarUsuario(DatosUsuario^ user) {
    List<DatosUsuario^>^ todosUsuarios = GetUsuarios();

    for each (DatosUsuario ^ usuarioExistente in todosUsuarios) {
        if (usuarioExistente->ID == user->ID) {
            throw gcnew Exception("El usuario ya existe");
        }
    }
    
    todosUsuarios->Add(user);
    listaUsuarios = todosUsuarios;

    PersistTextFileUsers(fileUsersName, todosUsuarios);
}
int BotPersistance::Persistance::generarAutoID(String^ cargo) {
    String^ prefijo = nullptr;
    if (cargo->ToLower()->Equals("sheriff")) {
        prefijo = "11";
    }
    else if (cargo->ToLower()->Equals("estudiante")) {
        prefijo = "22";
    }
    else if (cargo->ToLower()->Equals("profesor")) {
        prefijo = "33";
    }
    else if (cargo->ToLower()->Equals("visitante externo")) {
        prefijo = "44";
    }
    else if (cargo->ToLower()->Equals("admin")) {
        prefijo = "99";
    }
    else {
        prefijo = "88"; // Prefijo por defecto para cargos no reconocidos
    }
    int maxNumero = 0;

    List<DatosUsuario^>^ todosUsuarios = GetUsuarios();

    for each (DatosUsuario ^ usuario in todosUsuarios) {
        String^ idString = usuario->ID.ToString();
        if (idString->StartsWith(prefijo) && idString->Length >= 3) {
            try {
                String^ numeroStr = idString->Substring(2);
                int numero = Convert::ToInt32(numeroStr);
                if (numero > maxNumero) {
                    maxNumero = numero;
                }
            }
            catch (Exception^) {
                continue;
            }
        }
    }

    int nuevoNumero = maxNumero + 1;
    String^ nuevoIDString = prefijo + nuevoNumero.ToString("D1");
    int nuevoID = Convert::ToInt32(nuevoIDString);

    return nuevoID;
}
DatosUsuario^ BotPersistance::Persistance::buscarUsuarioID(int id) {
    for each (DatosUsuario ^ usuario in listaUsuarios) {
        if (usuario->ID == id) {
            return usuario;
        }
    }
    return nullptr;
}
DatosUsuario^ BotPersistance::Persistance::buscarUsuarioNombre(String^ nombre) {
    for each (DatosUsuario ^ usuario in listaUsuarios) {
        if (usuario->Nombre->Equals(nombre)) {
            return usuario;
        }
    }
    return nullptr;
}
DatosUsuario^ BotPersistance::Persistance::buscarUsuarioCredenciales(String^ nombre, String^ contra) {
    GetUsuarios();
    for each (DatosUsuario ^ usuario in listaUsuarios) {
        if (usuario->Nombre->Equals(nombre) && usuario->Contra->Equals(contra)) {
            return usuario;
        }
    }
    return nullptr;
}
bool BotPersistance::Persistance::borrarUsuarioID(int id) {
    for (int i = 0; i < listaUsuarios->Count; i++) {
        if (listaUsuarios[i]->ID == id) {
            listaUsuarios->RemoveAt(i);
            PersistTextFileUsers(fileUsersName, listaUsuarios);
            //PersistBinaryFile(fileBinUsers, listaUsuarios);
            return true;
        }
    }
    return false;
}
bool BotPersistance::Persistance::borrarUsuarioNombre(String^ nombre) {
    for (int i = 0; i < listaUsuarios->Count; i++) {
        if (listaUsuarios[i]->Nombre->Equals(nombre)) {
            listaUsuarios->RemoveAt(i);
            PersistTextFileUsers(fileUsersName, listaUsuarios);
            //PersistBinaryFile(fileBinUsers, listaUsuarios);
            return true;
        }
    }
    return false;
}
int BotPersistance::Persistance::restablecerUsuario(String^ usuario, String^ nuevaContra, String^ confirmarContra) {
    // Validar que sean la misma contraseña
    if (!nuevaContra->Equals(confirmarContra)) {
        throw gcnew Exception("Las contraseñas no coinciden");
    }

    // Validar que la nueva contraseña no esté vacía
    if (String::IsNullOrEmpty(nuevaContra)) {
        throw gcnew Exception("La contraseña no puede estar vacía");
    }

    DatosUsuario^ usuarioEncontrado = buscarUsuarioNombre(usuario);
    if (usuarioEncontrado != nullptr) {
        usuarioEncontrado->Contra = nuevaContra;
        PersistTextFileUsers(fileUsersName, listaUsuarios);
        return 1;
    }
    else {
        throw gcnew Exception("Usuario no encontrado");
    }    
    return 0;
}
int BotPersistance::Persistance::modificarUsuarioID(DatosUsuario^ usuario) {
    for (int i = 0; i < listaUsuarios->Count; i++) {
        if (listaUsuarios[i]->ID == usuario->ID) {
            listaUsuarios[i] = usuario;
            PersistTextFileUsers(fileUsersName, listaUsuarios);
            //PersistBinaryFile(fileBinUsers, listaUsuarios);
            return 1;
        }
    }
    return 0;
}
List <DatosUsuario^>^ BotPersistance::Persistance::GetUsuarios() {
    if (listaUsuarios->Count == 0) {
        Object^ res = LoadUsuariosFromTextFile(fileUsersName);
        //Object^ res = LoadBinaryFile(fileBinUsers);
        if (res != nullptr) {
            listaUsuarios = (List<DatosUsuario^>^) res;
        }
    }
    return listaUsuarios;
}


//Funciones de guardado
using namespace System::IO;

void BotPersistance::Persistance::PersistTextFileUsers(String^ fileName, List<DatosUsuario^>^ lista) {
    FileStream^ file = nullptr;
    StreamWriter^ writer = nullptr;
    try {
        file = gcnew FileStream(fileName, FileMode::Create, FileAccess::Write);
        writer = gcnew StreamWriter(file);
        for each (DatosUsuario ^ usuario in listaUsuarios) {
            writer->WriteLine("{0}|{1}|{2}|{3}",
                usuario->ID,
                usuario->Nombre,
                usuario->Contra,
                usuario->Cargo
            );
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        if (writer != nullptr) writer->Close();
        if (file != nullptr) file->Close();
    }
}
Object^ BotPersistance::Persistance::LoadUsuariosFromTextFile(String^ fileName) {
    FileStream^ file;
    StreamReader^ reader;
    Object^ result = gcnew List<DatosUsuario^>();
    try {
        
        file = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
        reader = gcnew StreamReader(file);
        while (!reader->EndOfStream) {
            String^ line = reader->ReadLine();
            if (String::IsNullOrEmpty(line)) continue;

            array<String^>^ record = line->Split('|');
            DatosUsuario^ usuario = gcnew DatosUsuario();
            usuario->ID = Convert::ToInt32(record[0]);
            usuario->Nombre = record[1];
            usuario->Contra = record[2];
            usuario->Cargo = record[3];
            
            
            ((List<DatosUsuario^>^)result)->Add(usuario);
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        if (reader != nullptr) reader->Close();
        if (file != nullptr) file->Close();
    }
    return result;
}

void BotPersistance::Persistance::PersistTextFileRobots(String^ fileName, List<Robot^>^ lista) {
    FileStream^ file = nullptr;
    StreamWriter^ writer = nullptr;
    try {
        file = gcnew FileStream(fileName, FileMode::Create, FileAccess::Write);
        writer = gcnew StreamWriter(file);
        for each (Robot ^ robot in listaRobots) {
            writer->WriteLine("{0}|{1}|{2}|{3}|{4}|{5}",
                robot->ID,
                robot->Bateria,
                robot->Nombre,
                robot->Zona,
                robot->PosicionRobot->x,
                robot->PosicionRobot->y
            );
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        if (writer != nullptr) writer->Close();
        if (file != nullptr) file->Close();
    }
}

Object^ BotPersistance::Persistance::LoadRobotsFromTextFile(String^ fileName) {
    FileStream^ file;
    StreamReader^ reader;
    Object^ result = gcnew List<Robot^>();
    try {

        file = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
        reader = gcnew StreamReader(file);
        while (!reader->EndOfStream) {
            String^ line = reader->ReadLine();
            if (String::IsNullOrEmpty(line)) continue;

            array<String^>^ record = line->Split('|');
            Robot^ robot = gcnew Robot();
            robot->ID = Convert::ToInt32(record[0]);
            robot->Bateria = Convert::ToInt32(record[1]);
            robot->Nombre = record[2];
            robot->Zona = record[3];
            robot->PosicionRobot->x = Convert::ToDouble(record[4]);
            robot->PosicionRobot->y = Convert::ToDouble(record[5]);
            
            ((List<Robot^>^)result)->Add(robot);
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        if (reader != nullptr) reader->Close();
        if (file != nullptr) file->Close();
    }
    return result;
}

void BotPersistance::Persistance::PersistBinaryFile(String^ fileName, Object^ persistObject)
{
    FileStream^ file;
    BinaryFormatter^ formatter = gcnew BinaryFormatter();
    try {
        file = gcnew FileStream(fileName, FileMode::Create, FileAccess::Write);
        formatter->Serialize(file, persistObject);
    }
    catch (Exception^ ex) { 
        throw ex; 
    }
    finally {
        if (file != nullptr) file->Close();
        delete file;
    }
}

Object^ BotPersistance::Persistance::LoadBinaryFile(String^ fileName)
{
    FileStream^ file;
    Object^ result;
    BinaryFormatter^ formatter;
    try {
        if (File::Exists(fileName)) {
            file = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
            formatter = gcnew BinaryFormatter();
            result = formatter->Deserialize(file);
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        if (file != nullptr) file->Close();
        delete file;
    }
    return result;
}

void BotPersistance::Persistance::PersistTxtFileAlert(String^ fileName, List<Alert^>^ lista)//completar
{
    FileStream^ file = nullptr;
    StreamWriter^ writer = nullptr;
    try {
        file = gcnew FileStream(fileName, FileMode::Create, FileAccess::Write);
        writer = gcnew StreamWriter(file);
        for each (Alert ^ Alerta in listaAlerts) {
            //Cambiar luego segun sea necesario
            writer->WriteLine("{0}|{1}|{2}|{3}",
                Alerta->Fecha,
                Alerta->Description,
                //Alerta->Nombre,
                Alerta->Lugar
            );
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        if (writer != nullptr) writer->Close();
        if (file != nullptr) file->Close();
    }
}

Object^ BotPersistance::Persistance::LoadAlertFormTxtFile(String^ fileName)//completar
{
    FileStream^ file;
    StreamReader^ reader;
    Object^ result = gcnew List<Alert^>();
    try {

        file = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
        reader = gcnew StreamReader(file);
        while (!reader->EndOfStream) {
            String^ line = reader->ReadLine();
            if (String::IsNullOrEmpty(line)) continue;

            array<String^>^ record = line->Split('|');
            Alert^ alerta = gcnew Alert();
            alerta->Fecha = Convert::ToDateTime(record[0]);
            alerta->Description = record[1];
            //Ni idea de como guardar el arreglo de bytes
            //alerta->Photo = Convert::ToByte(record[2]);
            alerta->Lugar = record[3];

            ((List<Alert^>^)result)->Add(alerta);
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        if (reader != nullptr) reader->Close();
        if (file != nullptr) file->Close();
    }
    return result;
}

//Funcion de zonas
void BotPersistance::Persistance::delimitarZonaTrabajo(double x, double y) {
    String^ Ubicacion = "nullptr";
    /*if (x >= 0 && x < 62) {
        if (y >= 0 && y < 223) {
            Ubicacion = "Criadero";
        }
        else if (y >= 223 && y < 285) {
            Ubicacion = "Digimundo";
        }
        else if (y >= 285 && y < 379) {
            Ubicacion = "Pabellón V";
        }
        else if (y >= 379 && y <= 465) {
            if (x >= 0 && x < 37) {
                Ubicacion = "Ingeniería Mecatrónica";
            }
            if (x >= 37 && x < 62) {
                Ubicacion = "Ingeniería Industrial";
            }
        }
    }
    else if (x >= 62 && x < 99 && y >= 0 && y <= 465) {
        Ubicacion = "Huaca";
    }
    else if (y >= 0 && y < 58) {
        if (x >= 99 && x < 165) {
            Ubicacion = "CEPRE PUCP";
        }
        else if (x >= 165 && x < 287) {
            Ubicacion = "Estacionamiento CEPRE PUCP";
        }
        else if (y >= 287 && y < 330) {
            Ubicacion = "Entrada Ciencias";
        }
        else if (x >= 330 && x < 528) {
            Ubicacion = "Estacionamiento Ciencias";
        }
        else if (y >= 528 && y < 598) {
            Ubicacion = "Puerta Principal";
        }
        else if (y >= 779 && y < 935) {
            Ubicacion = "Artes escénicas";
        }
    }
    else if (x >= 99 && x < 189 && y >= 58 && y < 149) {
        Ubicacion = "FACI";
    }
    else if (x >= 189 && x < 254 && y >= 58 && y < 149) {
        Ubicacion = "Química";
    }
    else if (x >= 254 && x < 287) {
        if (y >= 58 && y < 90) {
            Ubicacion = "FAD";
        }
        else if (y >= 90 && y < 149) {
            Ubicacion = "El puesto";
        }
    }
    else if (x >= 287 && x < 367 && y >= 58 && y < 185) {
        Ubicacion = "EEGGCC";
    }
    else if (x >= 367 && x < 459) {
        if (y >= 58 && y < 143) {
            Ubicacion = "ARTES VIEJAS";
        }
        else if (y >= 143 && y < 185) {
            Ubicacion = "Comedor de arte viejas";
        }
    }
    else if (x >= 459 && x < 528 && y >= 58 && y < 185) {
        Ubicacion = "Tópico";
    }
    else if (x >= 528 && x < 598 && y >= 58 && y < 185) {
        Ubicacion = "Jardin central";
    }
    else if (x >= 598 && x < 670) {
        if (y >= 0 && y < 135) {
            Ubicacion = "Mac Gregor";
        }
        else if (y >= 135 && y < 185) {
            Ubicacion = "Tinkuy";
        }
    }
    else if (x >= 670 && x < 779 && y >= 0 && y < 185) {
        Ubicacion = "Educa/Fares";
    }
    else if (x >= 779 && x < 935 && y >= 58 && y < 342) {
        Ubicacion = "Canchas";
    }
    else if (x >= 779 && x < 935 && y >= 342 && y < 465) {
        Ubicacion = "INRAS";
    }*/
    /*else if (x == -1 && y == -1) {//base de operaciones
        Ubicacion = "BASE";
    }*/
    //listPoints->Add(nuevoPunto);
}

Point^ BotPersistance::Persistance::getPoint(double x, double y)
{
    for each (Point ^ p in listPoints) {
        if (p->x == x && p->y == y) {
            return p;
        }
    }
    return nullptr;
}


//Registro de alertas
void BotPersistance::Persistance::registrarAlerta(Alert^ alerta) {
    
    List<Alert^>^ alertasExistentes = ShowAlertas();
    
    int maxId = 0;
    for each (Alert ^ alertaExistente in alertasExistentes) {
        if (alertaExistente->id > maxId) {
            maxId = alertaExistente->id;
        }
    }

    alerta->id = maxId + 1;
    
    listaReportesAlertas->Add(alerta);
    PersistBinaryFile(fileBinAlertReport, listaReportesAlertas);
}
void BotPersistance::Persistance::registrarObjPerdido(ObjPerdido^ objeto) {
    registrarAlerta(objeto);
}
void BotPersistance::Persistance::registrarDTIReport(DTIReport^ reporte) {
    registrarAlerta(reporte);
}
void BotPersistance::Persistance::registrarAlercado(Altercado^ altercado) {
    registrarAlerta(altercado);
}

List<Alert^>^ BotPersistance::Persistance::ShowAlertas()
{
    listaReportesAlertas = (List<Alert^>^)LoadBinaryFile(fileBinAlertReport);
    if (listaReportesAlertas == nullptr) {
        listaReportesAlertas = gcnew List<Alert^>();
    }
    return listaReportesAlertas;
}

List<ObjPerdido^>^  BotPersistance::Persistance::ShowObjetosPerdidos()
{
    List<ObjPerdido^>^ lista = gcnew List<ObjPerdido^>();
    List<Alert^>^ alertasList = ShowAlertas();
    for (int i = 0; i < alertasList->Count; i++) {
        if (alertasList[i]->GetType() == ObjPerdido::typeid) {
            lista->Add((ObjPerdido^)alertasList[i]);
        }
    }
    return lista;
}

List<Altercado^>^ BotPersistance::Persistance::ShowAltercados()
{
    List<Altercado^>^ lista = gcnew List<Altercado^>();
    List<Alert^>^ alertasList = ShowAlertas();
    for (int i = 0; i < alertasList->Count; i++) {
        if (alertasList[i]->GetType() == Altercado::typeid) {
            lista->Add((Altercado^)alertasList[i]);
        }
    }
    return lista;
}

List<DTIReport^>^ BotPersistance::Persistance::ShowDTIReport()
{
    List<DTIReport^>^ lista = gcnew List<DTIReport^>();
    List<Alert^>^ alertasList = ShowAlertas();
    for (int i = 0; i < alertasList->Count; i++) {
        if (alertasList[i]->GetType() == DTIReport::typeid) {
            lista->Add((DTIReport^)alertasList[i]);
        }
    }
    return lista;
}
