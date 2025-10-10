#include "pch.h"
#include "PERSISTANCE.h"

//funciones del robot en persistance
void BotPersistance::Persistance::registrarRobot(int id, String^ nombre, String^ zona, Point^ ubicacion) {
    Robot^ robot = gcnew Robot(id, nombre, zona,ubicacion);
    listaRobots->Add(robot);
}
Robot^ BotPersistance::Persistance::buscarRobotID(int id) {
    Robot^ robot = nullptr;
    for (int i = 0; i < listaRobots->Count; i++) {
        if (listaRobots[i]->getID() == id) {
            robot = listaRobots[i];
            break;
        }
    }
    return robot;
}
Robot^ BotPersistance::Persistance::buscarRobotNombre(String^ nombre) {
    for each (Robot ^ r in listaRobots) {
        if (r->getNombre()->Equals(nombre)) {
            return r;
        }
    }
    return nullptr;
}
bool BotPersistance::Persistance::borrarRobotID(int id) {
    for (int i = 0; i < listaRobots->Count; i++) {
        if (listaRobots[i]->getID() == id) {
            listaRobots->RemoveAt(i);
            return true;
        }
    }
    return false;
}
bool BotPersistance::Persistance::borrarRobotNombre(String^ nombre) {
    for (int i = 0; i < listaRobots->Count; i++) {
        if (listaRobots[i]->getNombre()->Equals(nombre)) {
            listaRobots->RemoveAt(i);
            return true;
        }
    }
    return false;
}
Robot^ BotPersistance::Persistance::modificarRobotID(int id, String^ nombre, String^ zona) {
    for each (Robot ^ r in listaRobots) {
        if (r->getID() == id) {
            r->setID(id);
            r->setNombre(nombre);
            r->setZona(zona);
            return r;
        }
    }
    return nullptr;
}
List <Robot^>^ BotPersistance::Persistance::GetRobots() {
    return listaRobots;
}
//void BotPersistance::Persistance::delimitarZonaTrabajo(Point^ x, Point^ y, String^ zonaTrabajo) {

//}


//funciones de usuario en persistance
void BotPersistance::Persistance::registrarUsuario(int id, String^ nombre, String^ contra, String^ cargo) {
    DatosUsuario^ usuario = gcnew DatosUsuario(id, nombre, contra, cargo);
    listaUsuarios->Add(usuario);
    PersistTextFile(fileName, listaUsuarios);
}
void BotPersistance::Persistance::registrarUsuarioAutoID(String^ nombre, String^ contra, String^ cargo) {
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
    for each (DatosUsuario ^ usuario in listaUsuarios) {
        String^ idString = usuario->getID().ToString();
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

    registrarUsuario(nuevoID, nombre, contra, cargo);
}
DatosUsuario^ BotPersistance::Persistance::buscarUsuarioID(int id) {
    DatosUsuario^ usuario = nullptr;
    for (int i = 0; i < listaUsuarios->Count; i++) {
        if (listaUsuarios[i]->getID() == id) {
            usuario = listaUsuarios[i];
            break;
        }
    }
    return usuario;
}
DatosUsuario^ BotPersistance::Persistance::buscarUsuarioNombre(String^ nombre) {
    for each (DatosUsuario ^ usuario in listaUsuarios) {
        if (usuario->getNombre()->Equals(nombre)) {
            return usuario;
        }
    }
    return nullptr;
}
DatosUsuario^ BotPersistance::Persistance::buscarUsuarioCredenciales(String^ nombre, String^ contra) {
    GetUsuarios();
    for each (DatosUsuario ^ usuario in listaUsuarios) {
        if (usuario->getNombre()->Equals(nombre) && usuario->getContrasena()->Equals(contra)) {
            return usuario;
        }
    }
    return nullptr;
}
bool BotPersistance::Persistance::borrarUsuarioID(int id) {
    for (int i = 0; i < listaUsuarios->Count; i++) {
        if (listaUsuarios[i]->getID() == id) {
            listaUsuarios->RemoveAt(i);
            PersistTextFile(fileName, listaUsuarios);
            return true;
        }
    }
    return false;
}
bool BotPersistance::Persistance::borrarUsuarioNombre(String^ nombre) {
    for (int i = 0; i < listaUsuarios->Count; i++) {
        if (listaUsuarios[i]->getNombre()->Equals(nombre)) {
            listaUsuarios->RemoveAt(i);
            PersistTextFile(fileName, listaUsuarios);
            return true;
        }
    }
    return false;
}
DatosUsuario^ BotPersistance::Persistance::restablecerUsuario(String^ nombre, String^ nuevaContra, String^ confirmarContra) {
    if (!nuevaContra->Equals(confirmarContra)) {
        throw gcnew Exception("Las contraseñas no coinciden");
    }

    // Validar que la nueva contraseña no esté vacía
    if (String::IsNullOrEmpty(nuevaContra)) {
        throw gcnew Exception("La contraseña no puede estar vacía");
    }

    // Buscar usuario y actualizar contraseña
    for each (DatosUsuario ^ u in listaUsuarios) {
        if (u->getNombre()->Equals(nombre)) {
            u->setContrasena(nuevaContra);
            PersistTextFile(fileName, listaUsuarios);
            return u;
        }
    }

    throw gcnew Exception("Usuario no encontrado");
}
DatosUsuario^ BotPersistance::Persistance::modificarUsuarioID(int id, String^ nombre, String^ contra, String^ cargo) {
    for each (DatosUsuario ^ u in listaUsuarios) {
        if (u->getID() == id) {
            u->setID(id);
            u->setNombre(nombre);
            u->setContrasena(contra);
            u->setCargo(cargo);
            PersistTextFile(fileName, listaUsuarios);
            return u;
        }
    }
    return nullptr;
}
List <DatosUsuario^>^ BotPersistance::Persistance::GetUsuarios() {
    if (listaUsuarios->Count == 0) {
        listaUsuarios = (List<DatosUsuario^>^) LoadUsuariosFromTextFile(fileName);
    }
    return listaUsuarios;
}


//Funciones de guardado
using namespace System::IO;

void BotPersistance::Persistance::PersistTextFile(String^ fileName, List<DatosUsuario^>^ lista) {
    FileStream^ file = nullptr;
    StreamWriter^ writer = nullptr;
    try {
        file = gcnew FileStream(fileName, FileMode::Create, FileAccess::Write);
        writer = gcnew StreamWriter(file);
        for each (DatosUsuario ^ usuario in listaUsuarios) {
            writer->WriteLine("{0}|{1}|{2}|{3}",
                usuario->getID(),
                usuario->getNombre(),
                usuario->getContrasena(),
                usuario->getCargo());
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
    listaUsuarios->Clear();
    try {
        
        file = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
        reader = gcnew StreamReader(file);
        while (!reader->EndOfStream) {
            String^ line = reader->ReadLine();
            array<String^>^ record = line->Split('|');

            int ID = Convert::ToInt32(record[0]);
            String^ nombre = record[1];
            String^ contra = record[2];
            String^ rol = record[3];
            
            DatosUsuario^ usuario = gcnew DatosUsuario(ID, nombre, contra, rol);
            listaUsuarios->Add(usuario);
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        if (reader != nullptr) reader->Close();
        if (file != nullptr) file->Close();
    }
    return listaUsuarios;
}

Point^ BotPersistance::Persistance::delimitarZonaTrabajo(double x, double y) {
    String^ Ubicacion = "nullptr";
    if (x >= 0 && x < 62) {
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
    }
    Point^ ubicacionRobot = gcnew Point(x, y, Ubicacion);
    return ubicacionRobot;
}

