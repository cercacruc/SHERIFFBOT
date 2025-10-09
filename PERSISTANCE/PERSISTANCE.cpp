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
    listaUsuarios = (List<DatosUsuario^>^) LoadUsuariosFromTextFile(fileName);
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
    Object^ result = gcnew List<DatosUsuario^>();
    try {
        file = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
        reader = gcnew StreamReader(file);
        while (!reader->EndOfStream) {
            String^ line = reader->ReadLine();
            array<String^>^ record = line->Split('|');
            DatosUsuario^ usuario = gcnew DatosUsuario();
            int ID = Convert::ToInt32(record[0]);
            String^ nombre = record[1];
            String^ contra = record[2];
            String^ rol = record[3];
            
            ((List<DatosUsuario^>^)result)->Add(gcnew DatosUsuario(ID, nombre, contra, rol));//chequear esta linea
            //registrarUsuario(ID, nombre, contra, rol);
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

