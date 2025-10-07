#include "pch.h"
#include "CONTROLLER.h"

using namespace BotController;
using namespace BotModel;
using namespace System::Collections::Generic;
using namespace System;

CONTROLLER::CONTROLLER() {
    this->listaUsuarios = gcnew List<DatosUsuario^>();
    this->listaRobots = gcnew List<Robot^>();
}
void CONTROLLER::registrarUsuario(int id, String^ nombre, String^ contra, String^ cargo) {
    int newID = this->listaUsuarios->Count + 1;
    DatosUsuario^ usuario = gcnew DatosUsuario(id, nombre, contra, cargo);
    this->listaUsuarios->Add(usuario);
}

DatosUsuario^ CONTROLLER::buscarUsuarioID(int id) {
    DatosUsuario^ usuario = nullptr;
    for (int i = 0; i < this->listaUsuarios->Count; i++) {
        if (this->listaUsuarios[i]->getID() == id) {
            usuario = this->listaUsuarios[i];
            break;
        }
    }
    return usuario;
}
DatosUsuario^ CONTROLLER::buscarUsuarioNombre(String^ nombre) {
    for each (DatosUsuario ^ usuario in this->listaUsuarios) {
        if (usuario->getNombre()->Equals(nombre)) {
            return usuario;
        }
    }
    return nullptr;
}
DatosUsuario^ CONTROLLER::buscarUsuarioCredenciales(String^ nombre, String^ contra) {
    for each (DatosUsuario ^ usuario in this->listaUsuarios) {
        if (usuario->getNombre()->Equals(nombre) && usuario->getContrasena()->Equals(contra)) {
            return usuario;
        }
    }
    return nullptr;
}
bool CONTROLLER::borrarUsuarioID(int id) {
    for (int i = 0; i < this->listaUsuarios->Count; i++) {
        if (this->listaUsuarios[i]->getID() == id) {
            this->listaUsuarios->RemoveAt(i);
            return true;
        }
    }
    return false;
}
bool CONTROLLER::borrarUsuarioNombre(String^ nombre) {
    for (int i = 0; i < this->listaUsuarios->Count; i++) {
        if (this->listaUsuarios[i]->getNombre()->Equals(nombre)) {
            this->listaUsuarios->RemoveAt(i);
            return true;
        }
    }
    return false;
}
DatosUsuario^ CONTROLLER::restablecerUsuario(String^ nombre, String^ nuevaContra, String^ confirmarContra) {
    if (!nuevaContra->Equals(confirmarContra)) {
        throw gcnew Exception("Las contraseñas no coinciden");
    }

    // Validar que la nueva contraseña no esté vacía
    if (String::IsNullOrEmpty(nuevaContra)) {
        throw gcnew Exception("La contraseña no puede estar vacía");
    }

    // Buscar usuario y actualizar contraseña
    for each (DatosUsuario ^ u in this->listaUsuarios) {
        if (u->getNombre()->Equals(nombre)) {
            u->setContrasena(nuevaContra);
            return u;
        }
    }

    throw gcnew Exception("Usuario no encontrado");

}
DatosUsuario^ CONTROLLER::modificarUsuarioID(int id, String^ nombre, String^ contra, String^ cargo) {
    for each (DatosUsuario ^ u in this->listaUsuarios) {
        if (u->getID() == id) {
            u->setID(id);
            u->setNombre(nombre);
            u->setContrasena(contra);
            u->setCargo(cargo);
            return u;
        }
    }
    return nullptr;
}
List <DatosUsuario^>^ CONTROLLER::GetUsuarios() {
    return this->listaUsuarios;
}
void CONTROLLER::registrarUsuarioAutoID(String^ nombre, String^ contra, String^ cargo) {
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
    for each (DatosUsuario ^ usuario in this->listaUsuarios) {
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

//Funciones Robot
void CONTROLLER::registrarRobot(int id, String^ nombre, String^ zona) {
    int newID = this->listaRobots->Count + 1;
    Robot^ robot = gcnew Robot(id, nombre, zona);
    this->listaRobots->Add(robot);
}
Robot^ CONTROLLER::buscarRobotID(int id) {
    Robot^ robot = nullptr;
    for (int i = 0; i < this->listaRobots->Count; i++) {
        if (this->listaRobots[i]->getID() == id) {
            robot = this->listaRobots[i];
            break;
        }
    }
    return robot;
}
Robot^ CONTROLLER::buscarRobotNombre(String^ nombre) {
    for each (Robot ^ r in this->listaRobots) {
        if (r->getNombre()->Equals(nombre)) {
            return r;
        }
    }
    return nullptr;
}
bool CONTROLLER::borrarRobotID(int id) {
    for (int i = 0; i < this->listaRobots->Count; i++) {
        if (this->listaRobots[i]->getID() == id) {
            this->listaRobots->RemoveAt(i);
            return true;
        }
    }
    return false;
}
bool CONTROLLER::borrarRobotNombre(String^ nombre) {
    for (int i = 0; i < this->listaRobots->Count; i++) {
        if (this->listaRobots[i]->getNombre()->Equals(nombre)) {
            this->listaRobots->RemoveAt(i);
            return true;
        }
    }
    return false;
}
Robot^ CONTROLLER::modificarRobotID(int id, String^ nombre, String^ zona) {
    for each (Robot ^ r in this->listaRobots) {
        if (r->getID() == id) {
            r->setID(id);
            r->setNombre(nombre);
            r->setZona(zona);
            return r;
        }
    }
    return nullptr;
}
List <Robot^>^ CONTROLLER::GetRobots() {
    return this->listaRobots;
}
