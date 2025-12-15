#include "pch.h"
#include "PERSISTANCE.h"

using namespace System::IO;
using namespace System::Xml::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;

//funciones del robot en persistance
void BotPersistance::Persistance::registrarRobot(Robot^ robot) {
    /*
    listaRobots->Add(robot);
    //PersistTextFileRobots(fileRobotName, listaRobots);
    PersistBinaryFile(fileBinRobots, listaRobots);
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^>
        {
            gcnew SqlParameter("@Nombre", robot->Nombre),
            gcnew SqlParameter("@Zona", robot->Zona),
            gcnew SqlParameter("@Bateria", robot->Bateria),
            gcnew SqlParameter("@PosicionX", robot->PosicionRobot->x),
            gcnew SqlParameter("@PosicionY", robot->PosicionRobot->y),
            gcnew SqlParameter("@Caracteristicas",
                String::IsNullOrEmpty(robot->Caracteristicas) ?
                DBNull::Value : (Object^)robot->Caracteristicas),
                gcnew SqlParameter("@Foto",
                    robot->Photo != nullptr ? (Object^)robot->Photo : DBNull::Value)
        };

        executeStoredProcedure("usp_AddRobot", params);
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error registrando robot: " + ex->Message);
    }
}
Robot^ BotPersistance::Persistance::buscarRobotID(int id) {
    /*
    for each (Robot ^ robot in listaRobots) {
        if (robot->ID == id) {
            return robot;
        }
    }
    return nullptr;
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^>{
            gcnew SqlParameter("@ID", id)
        };

        SqlDataReader^ reader = executeStoredProcedureReader("usp_BuscarRobotPorID", params);

        if (reader != nullptr && reader->Read() && !reader->IsDBNull(0))
        {
            Robot^ robot = gcnew Robot();

            robot->ID = reader->GetInt32(reader->GetOrdinal("ID_Robot"));
            robot->Nombre = reader["Nombre_robot"]->ToString();
            robot->Zona = reader["Zona_asignada"]->ToString();
            robot->Bateria = reader->GetInt32(reader->GetOrdinal("Bateria"));

            double posX = reader->GetDouble(reader->GetOrdinal("Posicion_X"));
            double posY = reader->GetDouble(reader->GetOrdinal("Posicion_Y"));
            robot->PosicionRobot = gcnew Point(posX, posY, robot->Zona);

            robot->Disponibilidad = reader->GetBoolean(reader->GetOrdinal("Disponibilidad"));
            robot->Caracteristicas = reader["Caracteristicas"]->ToString();

            if (!reader->IsDBNull(reader->GetOrdinal("Foto"))) {
                int fotoIndex = reader->GetOrdinal("Foto");
                robot->Photo = safe_cast<array<Byte>^>(reader[fotoIndex]);
            }
            else {
                robot->Photo = nullptr; // Asegurar que sea null si no hay foto
            }

            // Verificar si la columna existe antes de leerla
            if (!reader->IsDBNull(reader->GetOrdinal("Alerta_asignada_ID"))) {
                robot->AlertaAsignadaID = reader->GetInt32(reader->GetOrdinal("Alerta_asignada_ID"));
            }
            else {
                robot->AlertaAsignadaID = 0;
            }

            robot->TipoMision = reader["Tipo_mision"]->ToString();

            reader->Close();
            cerrarConexion();
            return robot;
        }

        if (reader != nullptr) {
            reader->Close();
            cerrarConexion();
        }
        return nullptr;
    }
    catch (Exception^ ex)
    {
        cerrarConexion();
        throw gcnew Exception("Error buscando robot por ID: " + ex->Message);
    }
}
Robot^ BotPersistance::Persistance::buscarRobotNombre(String^ nombre) {
    /*
    for each (Robot ^ r in listaRobots) {
        if (r->Nombre->Equals(nombre)) {
            return r;
        }
    }
    return nullptr;
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^> {
            gcnew SqlParameter("@Nombre", nombre)
        };

        SqlDataReader^ reader = executeStoredProcedureReader("usp_BuscarRobotPorNombre", params);

        if (reader != nullptr && reader->Read())
        {
            Robot^ robot = gcnew Robot();

            robot->ID = reader->GetInt32(reader->GetOrdinal("ID_Robot"));
            robot->Nombre = reader["Nombre_robot"]->ToString();
            robot->Zona = reader["Zona_asignada"]->ToString();
            robot->Bateria = reader->GetInt32(reader->GetOrdinal("Bateria"));

            double posX = reader->GetDouble(reader->GetOrdinal("Posicion_X"));
            double posY = reader->GetDouble(reader->GetOrdinal("Posicion_Y"));
            robot->PosicionRobot = gcnew Point(posX, posY, robot->Zona);

            robot->Disponibilidad = reader->GetBoolean(reader->GetOrdinal("Disponibilidad"));
            robot->Caracteristicas = reader["Caracteristicas"]->ToString();

            // Verificar si la columna existe antes de leerla
            if (!reader->IsDBNull(reader->GetOrdinal("Alerta_asignada_ID"))) {
                robot->AlertaAsignadaID = reader->GetInt32(reader->GetOrdinal("Alerta_asignada_ID"));
            }
            else {
                robot->AlertaAsignadaID = 0;
            }

            

            if (!reader->IsDBNull(reader->GetOrdinal("Foto"))) {
                try {
                    int fotoIndex = reader->GetOrdinal("Foto");
                    // Leer como array de bytes de forma segura
                    robot->Photo = safe_cast<array<Byte>^>(reader[fotoIndex]);
                }
                catch (Exception^ ex) {
                    // Si hay error al leer la foto, establecer como null y continuar
                    robot->Photo = nullptr;
                    System::Diagnostics::Debug::WriteLine("Advertencia: Error leyendo foto del robot: " + ex->Message);
                }
            }
            else {
                robot->Photo = nullptr;
            }

            robot->TipoMision = reader["Tipo_mision"]->ToString();

            reader->Close();
            cerrarConexion();
            return robot;
        }

        if (reader != nullptr) {
            reader->Close();
            cerrarConexion();
        }
        return nullptr;
    }
    catch (Exception^ ex)
    {
        cerrarConexion();
        throw gcnew Exception("Error buscando robot por nombre: " + ex->Message);
    }
}
bool BotPersistance::Persistance::borrarRobotID(int id) {
    /*
    for (int i = 0; i < listaRobots->Count; i++) {
        if (listaRobots[i]->ID == id) {
            listaRobots->RemoveAt(i);
            //PersistTextFileRobots(fileRobotName, listaRobots);
            PersistBinaryFile(fileBinRobots, listaRobots);
            return true;
        }
    }
    return false;
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^>
        {
            gcnew SqlParameter("@ID", id)
        };

        return executeStoredProcedureNonQuery("usp_DeleteRobot", params);
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error eliminando robot: " + ex->Message);
    }
}
bool BotPersistance::Persistance::borrarRobotNombre(String^ nombre) {
    /*
    for (int i = 0; i < listaRobots->Count; i++) {
        if (listaRobots[i]->Nombre->Equals(nombre)) {
            listaRobots->RemoveAt(i);
            //PersistTextFileRobots(fileRobotName, listaRobots);
            PersistBinaryFile(fileBinRobots, listaRobots);
            return true;
        }
    }
    return false;
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^>
        {
            gcnew SqlParameter("@Nombre", nombre)
        };

        return executeStoredProcedureNonQuery("usp_BorrarRobotPorNombre", params);
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error eliminando robot por nombre: " + ex->Message);
    }
}
int BotPersistance::Persistance::modificarRobotID(Robot^ robot) {
    /*
    for (int i = 0; i < listaRobots->Count; i++) {
        if (listaRobots[i]->ID == robot->ID) {
            listaRobots[i] = robot;
            //PersistTextFileRobots(fileRobotName, listaRobots);
            PersistBinaryFile(fileBinRobots, listaRobots);
            return 1;
        }
    }
    return 0;
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^>
        {
            gcnew SqlParameter("@ID", robot->ID),
            gcnew SqlParameter("@Nombre", robot->Nombre),
            gcnew SqlParameter("@Zona", robot->Zona),
            gcnew SqlParameter("@Bateria", robot->Bateria),
            gcnew SqlParameter("@PosicionX", robot->PosicionRobot->x),
            gcnew SqlParameter("@PosicionY", robot->PosicionRobot->y),
            gcnew SqlParameter("@Caracteristicas",
                String::IsNullOrEmpty(robot->Caracteristicas) ?
                DBNull::Value : (Object^)robot->Caracteristicas),
            gcnew SqlParameter("@Disponibilidad", robot->Disponibilidad),
            gcnew SqlParameter("@Foto",
                    robot->Photo != nullptr ? (Object^)robot->Photo : DBNull::Value)
        };

        return executeStoredProcedure("usp_UpdateRobot", params);
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error modificando robot: " + ex->Message);
    }
}
List <Robot^>^ BotPersistance::Persistance::GetRobots() {
    /*
    Object^ res = LoadBinaryFile(fileBinRobots);
    if (res != nullptr) {
        //listaRobots = (List<Robot^>^) LoadRobotsFromTextFile(fileRobotName);
        listaRobots = (List<Robot^>^)res;
    }
    return listaRobots;
    */
    List<Robot^>^ lista = gcnew List<Robot^>();

    try
    {
        SqlDataReader^ reader = executeStoredProcedureReader("usp_GetAllRobots", nullptr);

        while (reader->Read())
        {
            Robot^ r = gcnew Robot();

            r->ID = reader->GetInt32(0);
            r->Nombre = reader->GetString(1);
            r->Zona = reader->GetString(2);
            r->Bateria = reader->GetInt32(3);

            double px = reader->GetDouble(4);
            double py = reader->GetDouble(5);

            r->PosicionRobot = gcnew Point(px, py, r->Zona);

            // Campos críticos que faltaban
            r->Disponibilidad = reader->GetBoolean(reader->GetOrdinal("Disponibilidad"));

            // Recuperar Alerta_asignada_ID (puede ser NULL)
            if (!reader->IsDBNull(reader->GetOrdinal("Alerta_asignada_ID"))) {
                r->AlertaAsignadaID = reader->GetInt32(reader->GetOrdinal("Alerta_asignada_ID"));
            }
            else {
                r->AlertaAsignadaID = 0;
            }

            // Recuperar Tipo_mision (puede ser NULL o vacío)
            if (!reader->IsDBNull(reader->GetOrdinal("Tipo_mision"))) {
                r->TipoMision = reader->GetString(reader->GetOrdinal("Tipo_mision"));
            }
            else {
                r->TipoMision = "";
            }

            // Opcional: recuperar otros campos si existen
            if (!reader->IsDBNull(reader->GetOrdinal("Caracteristicas"))) {
                r->Caracteristicas = reader->GetString(reader->GetOrdinal("Caracteristicas"));
            }
            else {
                r->Caracteristicas = "";
            }

            lista->Add(r);
        }

        reader->Close();
        cerrarConexion();

        return lista;
    }
    catch (Exception^ ex)
    {
        cerrarConexion();
        throw gcnew Exception("Error obteniendo robots: " + ex->Message);
    }
}

//funciones de usuario en persistance
void BotPersistance::Persistance::registrarUsuario(DatosUsuario^ user) {
    /*
    List<DatosUsuario^>^ todosUsuarios = GetUsuarios();

    for each (DatosUsuario ^ usuarioExistente in todosUsuarios) {
        if (usuarioExistente->ID == user->ID) {
            throw gcnew Exception("El usuario ya existe");
        }
    }

    todosUsuarios->Add(user);
    listaUsuarios = todosUsuarios;

    //PersistTextFileUsers(fileUsersName, todosUsuarios);
    PersistBinaryFile(fileBinUsers, todosUsuarios);
    */
    try
    {
        // GENERAR ID AUTOMÁTICO SEGÚN EL CARGO
        array<SqlParameter^>^ paramsID = {
            gcnew SqlParameter("@Cargo", user->Cargo),
            gcnew SqlParameter("@NuevoID", SqlDbType::Int)
        };

        paramsID[1]->Direction = System::Data::ParameterDirection::Output;

        executeStoredProcedureNonQuery("usp_GenerarIDUsuario", paramsID);

        // Obtener ID generado
        user->ID = Convert::ToInt32(paramsID[1]->Value);

        // INSERTAR EL USUARIO EN SQL
        array<SqlParameter^>^ paramsInsert = {
            gcnew SqlParameter("@ID", user->ID),
            gcnew SqlParameter("@Nombre", user->Nombre),
            gcnew SqlParameter("@Contra", user->Contra),
            gcnew SqlParameter("@Cargo", user->Cargo),
            gcnew SqlParameter("@Cant1", user->cant_alertas[0]),
            gcnew SqlParameter("@Cant2", user->cant_alertas[1]),
            gcnew SqlParameter("@Cant3", user->cant_alertas[2])
        };

        executeStoredProcedureNonQuery("usp_RegistrarUsuario", paramsInsert);
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error al registrar usuario en SQL: " + ex->Message);
    }
}
int BotPersistance::Persistance::generarAutoID(String^ cargo) {//el mismo SQL lo genera
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
    /*
    for each (DatosUsuario ^ usuario in listaUsuarios) {
        if (usuario->ID == id) {
            return usuario;
        }
    }
    return nullptr;
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^> {
            gcnew SqlParameter("@ID", id)
        };

        SqlDataReader^ reader = executeStoredProcedureReader("usp_BuscarUsuarioPorID", params);

        if (reader != nullptr && reader->Read())
        {
            DatosUsuario^ usuario = gcnew DatosUsuario();

            usuario->ID = reader->GetInt32(reader->GetOrdinal("ID_Usuario"));
            usuario->Nombre = reader["Nombre_de_usuario"]->ToString();
            usuario->Contra = reader["Contrasena"]->ToString();
            usuario->Cargo = reader["Cargo"]->ToString();

            usuario->cant_alertas = gcnew array<int>(3);
            usuario->cant_alertas[0] = Convert::ToInt32(reader["Perdidas"]);
            usuario->cant_alertas[1] = Convert::ToInt32(reader["Altercados"]);
            usuario->cant_alertas[2] = Convert::ToInt32(reader["Reportes_dti"]);

            reader->Close();
            cerrarConexion();
            return usuario;
        }

        if (reader != nullptr) {
            reader->Close();
            cerrarConexion();
        }
        return nullptr;
    }
    catch (Exception^ ex)
    {
        cerrarConexion();
        throw gcnew Exception("Error buscando usuario por ID: " + ex->Message);
    }
}
DatosUsuario^ BotPersistance::Persistance::buscarUsuarioNombre(String^ nombre) {
    /*
    for each (DatosUsuario ^ usuario in listaUsuarios) {
        if (usuario->Nombre->Equals(nombre)) {
            return usuario;
        }
    }
    return nullptr;
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^> {
            gcnew SqlParameter("@Nombre", nombre)
        };

        SqlDataReader^ reader = executeStoredProcedureReader("usp_BuscarUsuarioPorNombre", params);

        if (reader != nullptr && reader->Read())
        {
            DatosUsuario^ usuario = gcnew DatosUsuario();

            usuario->ID = reader->GetInt32(reader->GetOrdinal("ID_Usuario"));
            usuario->Nombre = reader["Nombre_de_usuario"]->ToString();
            usuario->Contra = reader["Contrasena"]->ToString();
            usuario->Cargo = reader["Cargo"]->ToString();

            usuario->cant_alertas = gcnew array<int>(3);
            usuario->cant_alertas[0] = Convert::ToInt32(reader["Perdidas"]);
            usuario->cant_alertas[1] = Convert::ToInt32(reader["Altercados"]);
            usuario->cant_alertas[2] = Convert::ToInt32(reader["Reportes_dti"]);

            reader->Close();
            cerrarConexion();
            return usuario;
        }

        if (reader != nullptr) {
            reader->Close();
            cerrarConexion();
        }
        return nullptr;
    }
    catch (Exception^ ex)
    {
        cerrarConexion();
        throw gcnew Exception("Error buscando usuario por nombre: " + ex->Message);
    }
}
DatosUsuario^ BotPersistance::Persistance::buscarUsuarioCredenciales(String^ nombre, String^ contra) {
   /*
    GetUsuarios();
    for each (DatosUsuario ^ usuario in listaUsuarios) {
        if (usuario->Nombre->Equals(nombre) && usuario->Contra->Equals(contra)) {
            return usuario;
        }
    }
    return nullptr;
    */
    /*
    try
    {
        array<SqlParameter^>^ params = {
            gcnew SqlParameter("@Nombre", nombre),
            gcnew SqlParameter("@Contra", contra)
        };

        SqlDataReader^ reader = executeStoredProcedureReader("usp_LoginUser", params);

        if (reader != nullptr && reader->Read())
        {
            DatosUsuario^ u = gcnew DatosUsuario();

            u->ID = reader->GetInt32(reader->GetOrdinal("ID_Usuario"));
            u->Nombre = reader["Nombre_de_usuario"]->ToString();
            u->Contra = reader["Contrasena"]->ToString();
            u->Cargo = reader["Cargo"]->ToString();

            u->cant_alertas = gcnew array<int>(3);
            u->cant_alertas[0] = Convert::ToInt32(reader["Perdidas"]);
            u->cant_alertas[1] = Convert::ToInt32(reader["Altercados"]);
            u->cant_alertas[2] = Convert::ToInt32(reader["Reportes_dti"]);

            return u;
        }

        return nullptr;
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error al buscar usuario en SQL: " + ex->Message);
        cerrarConexion();
    }
    */
    SqlDataReader^ reader = nullptr;
    try
    {
        array<SqlParameter^>^ params = {
            gcnew SqlParameter("@Nombre", nombre),
            gcnew SqlParameter("@Contra", contra)
        };

        reader = executeStoredProcedureReader("usp_LoginUser", params);

        if (reader != nullptr && reader->Read())
        {
            DatosUsuario^ u = gcnew DatosUsuario();

            u->ID = reader->GetInt32(reader->GetOrdinal("ID_Usuario"));
            u->Nombre = reader["Nombre_de_usuario"]->ToString();
            u->Contra = reader["Contrasena"]->ToString();
            u->Cargo = reader["Cargo"]->ToString();

            u->cant_alertas = gcnew array<int>(3);
            u->cant_alertas[0] = Convert::ToInt32(reader["Perdidas"]);
            u->cant_alertas[1] = Convert::ToInt32(reader["Altercados"]);
            u->cant_alertas[2] = Convert::ToInt32(reader["Reportes_dti"]);

            // Cerrar el reader antes de retornar
            reader->Close();
            cerrarConexion();
            return u;
        }

        return nullptr;
    }
    catch (Exception^ ex)
    {
        // Asegurarse de cerrar el reader y la conexión en caso de error
        if (reader != nullptr) {
            reader->Close();
            cerrarConexion();
        }
        throw gcnew Exception("Error al buscar usuario en SQL: " + ex->Message);
    }
    finally
    {
        // Garantizar que el reader se cierre incluso si hay excepción
        if (reader != nullptr && !reader->IsClosed) {
            reader->Close();
            cerrarConexion();
        }
    }
}
bool BotPersistance::Persistance::borrarUsuarioID(int id) {
    /*
    for (int i = 0; i < listaUsuarios->Count; i++) {
        if (listaUsuarios[i]->ID == id) {
            listaUsuarios->RemoveAt(i);
            //PersistTextFileUsers(fileUsersName, listaUsuarios);
            PersistBinaryFile(fileBinUsers, listaUsuarios);
            return true;
        }
    }
    return false;
    */
    array<SqlParameter^>^ params = {
        gcnew SqlParameter("@ID", id)
    };

    return executeStoredProcedureNonQuery("usp_BorrarUsuario", params);
}
bool BotPersistance::Persistance::borrarUsuarioNombre(String^ nombre) {
    /*
    for (int i = 0; i < listaUsuarios->Count; i++) {
        if (listaUsuarios[i]->Nombre->Equals(nombre)) {
            listaUsuarios->RemoveAt(i);
            //PersistTextFileUsers(fileUsersName, listaUsuarios);
            PersistBinaryFile(fileBinUsers, listaUsuarios);
            return true;
        }
    }
    return false;
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^>
        {
            gcnew SqlParameter("@Nombre", nombre)
        };

        return executeStoredProcedureNonQuery("usp_BorrarUsuarioPorNombre", params);
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error eliminando usuario por nombre: " + ex->Message);
    }
}
int BotPersistance::Persistance::restablecerUsuario(String^ usuario, String^ nuevaContra, String^ confirmarContra) {
    /*
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
        //PersistTextFileUsers(fileUsersName, listaUsuarios);
        PersistBinaryFile(fileBinUsers, listaUsuarios);
        return 1;
    }
    else {
        throw gcnew Exception("Usuario no encontrado");
    }
    return 0;
    */
    // Validaciones básicas
    if (!nuevaContra->Equals(confirmarContra))
        throw gcnew Exception("Las contraseñas no coinciden");

    if (String::IsNullOrWhiteSpace(nuevaContra))
        throw gcnew Exception("La contraseña no puede estar vacía");

    try
    {
        // Primero verificar si el usuario existe
        DatosUsuario^ usuarioExistente = buscarUsuarioNombre(usuario);
        if (usuarioExistente == nullptr) {
            return 0; // Usuario no existe
        }

        // Luego actualizar la contraseña usando executeStoredProcedureNonQuery
        array<SqlParameter^>^ params = {
            gcnew SqlParameter("@Nombre", usuario),
            gcnew SqlParameter("@NuevaContra", nuevaContra)
        };

        bool result = executeStoredProcedureNonQuery("usp_ResetPassword", params);
        return result ? 1 : 0;
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error al restablecer contraseña en SQL: " + ex->Message);
    }
}
int BotPersistance::Persistance::modificarUsuarioID(DatosUsuario^ usuario) {
    /*
    for (int i = 0; i < listaUsuarios->Count; i++) {
        if (listaUsuarios[i]->ID == usuario->ID) {
            listaUsuarios[i] = usuario;
            //PersistTextFileUsers(fileUsersName, listaUsuarios);
            PersistBinaryFile(fileBinUsers, listaUsuarios);
            return 1;
        }
    }
    return 0;
    */
    if (usuario->cant_alertas == nullptr) {
        usuario->cant_alertas = gcnew array<int>(3);
        usuario->cant_alertas[0] = 0;
        usuario->cant_alertas[1] = 0;
        usuario->cant_alertas[2] = 0;
    }


    array<SqlParameter^>^ params = {
        gcnew SqlParameter("@ID", usuario->ID),
        gcnew SqlParameter("@Nombre", usuario->Nombre),
        gcnew SqlParameter("@Contra", usuario->Contra),
        gcnew SqlParameter("@Cargo", usuario->Cargo),
        gcnew SqlParameter("@Cant1", usuario->cant_alertas[0]),
        gcnew SqlParameter("@Cant2", usuario->cant_alertas[1]),
        gcnew SqlParameter("@Cant3", usuario->cant_alertas[2])
    };

    // ExecuteNonQuery no devuelve filas, así que devolvemos 1 si fue exitoso
    executeStoredProcedureNonQuery("usp_ModificarUsuario", params);
    return 1;
}
List <DatosUsuario^>^ BotPersistance::Persistance::GetUsuarios() {
    /*
    if (listaUsuarios->Count == 0) {
        //Object^ res = LoadUsuariosFromTextFile(fileUsersName);
        Object^ res = LoadBinaryFile(fileBinUsers);
        if (res != nullptr) {
            listaUsuarios = (List<DatosUsuario^>^) res;
        }
    }
    return listaUsuarios;
    */

    List<DatosUsuario^>^ lista = gcnew List<DatosUsuario^>();

    SqlDataReader^ dr = executeStoredProcedureReader("usp_QueryAllUsers", nullptr);

    while (dr->Read()) {

        DatosUsuario^ u = gcnew DatosUsuario();

        u->ID = dr->GetInt32(0);
        u->Nombre = dr->GetString(1);
        u->Contra = dr->GetString(2);
        u->Cargo = dr->GetString(3);

        // Cantidades de alertas
        u->cant_alertas = gcnew array<int>(3);
        u->cant_alertas[0] = dr->GetInt32(4); // Perdidas
        u->cant_alertas[1] = dr->GetInt32(5); // Altercados
        u->cant_alertas[2] = dr->GetInt32(6); // Reportes DTI

        lista->Add(u);
    }

    dr->Close();
    cerrarConexion();

    return lista;
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
            writer->WriteLine("{0}|{1}|{2}|{3}|{4}|{5}|{6}",
                usuario->ID,
                usuario->Nombre,
                usuario->Contra,
                usuario->Cargo,
                usuario->cant_alertas[0],
                usuario->cant_alertas[1],
                usuario->cant_alertas[2]
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
            usuario->cant_alertas[0] = Convert::ToInt32(record[4]);
            usuario->cant_alertas[1] = Convert::ToInt32(record[5]);
            usuario->cant_alertas[2] = Convert::ToInt32(record[6]);


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

void BotPersistance::Persistance::PersistTxtFileZonas(String^ fileName, List<ZonaTrabajo^>^ lista)
{
    FileStream^ file = nullptr;
    StreamWriter^ writer = nullptr;
    try {
        file = gcnew FileStream(fileName, FileMode::Create, FileAccess::Write);
        writer = gcnew StreamWriter(file);
        for each (ZonaTrabajo ^ z in listaZonas) {
            writer->WriteLine("{0}|{1}|{2}|{3}|{4}|{5}",
                z->ID,
                z->x_min,
                z->x_max,
                z->y_min,
                z->y_max,
                z->zona
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

Object^ BotPersistance::Persistance::LoadZonasFormTxtFile(String^ fileName)
{
    FileStream^ file;
    StreamReader^ reader;
    Object^ result = gcnew List<ZonaTrabajo^>();
    try {

        file = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
        reader = gcnew StreamReader(file);
        while (!reader->EndOfStream) {
            String^ line = reader->ReadLine();
            if (String::IsNullOrEmpty(line)) continue;

            array<String^>^ record = line->Split('|');
            ZonaTrabajo^ zona = gcnew ZonaTrabajo();
            zona->ID = Convert::ToInt32(record[0]);
            zona->x_min = Convert::ToDouble(record[1]);
            zona->x_max = Convert::ToDouble(record[2]);
            zona->y_min = Convert::ToDouble(record[3]);
            zona->y_max = Convert::ToDouble(record[4]);
            zona->zona = record[5];

            ((List<ZonaTrabajo^>^)result)->Add(zona);
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

void BotPersistance::Persistance::PersistTxtFilePoint(String^ fileName, List<Point^>^ lista)
{
    FileStream^ file = nullptr;
    StreamWriter^ writer = nullptr;
    try {
        file = gcnew FileStream(fileName, FileMode::Create, FileAccess::Write);
        writer = gcnew StreamWriter(file);
        for each (Point ^ p in listPoints) {
            writer->WriteLine("{0}|{1}|{2}",
                p->x,
                p->y,
                p->Ubicacion
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

Object^ BotPersistance::Persistance::LoadPointsFormTxtFile(String^ fileName)
{
    FileStream^ file;
    StreamReader^ reader;
    Object^ result = gcnew List<Point^>();
    try {

        file = gcnew FileStream(fileName, FileMode::Open, FileAccess::Read);
        reader = gcnew StreamReader(file);
        while (!reader->EndOfStream) {
            String^ line = reader->ReadLine();
            if (String::IsNullOrEmpty(line)) continue;

            array<String^>^ record = line->Split('|');
            Point^ p = gcnew Point();
            p->x = Convert::ToDouble(record[0]);
            p->y = Convert::ToDouble(record[1]);
            p->Ubicacion = record[2];
            ((List<Point^>^)result)->Add(p);
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
String^ BotPersistance::Persistance::delimitarZonaTrabajo(double x, double y) {
    /*
    String^ Ubicacion = "nullptr";
    for each (ZonaTrabajo ^ z in listaZonas) {
        if (x >= z->x_min && x <= z->x_max && y >= z->y_min && y <= z->y_max) {
            Ubicacion = z->zona;

            Point^ nuevoPunto = gcnew Point(x, y, Ubicacion);
            listPoints->Add(nuevoPunto);
            PersistTxtFilePoint(filePoints, listPoints);
            return Ubicacion;
        }
    }

    return Ubicacion;
    */
    try
    {
        List<ZonaTrabajo^>^ zonas = GetZonas();
        String^ Ubicacion = "nullptr";

        for each (ZonaTrabajo ^ z in zonas) {
            if (x >= z->x_min && x <= z->x_max && y >= z->y_min && y <= z->y_max) {
                Ubicacion = z->zona;

                // Guardar punto en SQL
                array<SqlParameter^>^ params = gcnew array<SqlParameter^>
                {
                    gcnew SqlParameter("@X", x),
                        gcnew SqlParameter("@Y", y),
                        gcnew SqlParameter("@Ubicacion", Ubicacion)
                };

                executeStoredProcedureNonQuery("usp_AddPunto", params);
                return Ubicacion;
            }
        }
        return Ubicacion;
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error delimitando zona: " + ex->Message);
    }
}

Point^ BotPersistance::Persistance::getPoint(double x, double y)
{
    /*
    for each (Point ^ p in listPoints) {
        if (p->x == x && p->y == y) {
            return p;
        }
    }
    return nullptr;
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^> {
            gcnew SqlParameter("@X", x),
                gcnew SqlParameter("@Y", y)
        };

        SqlDataReader^ reader = executeStoredProcedureReader("usp_GetPunto", params);

        if (reader != nullptr && reader->Read())
        {
            Point^ punto = gcnew Point();

            punto->x = reader->GetDouble(reader->GetOrdinal("Coordenada_X"));
            punto->y = reader->GetDouble(reader->GetOrdinal("Coordenada_Y"));
            punto->Ubicacion = reader["Ubicacion"]->ToString();

            reader->Close();
            cerrarConexion();
            return punto;
        }

        if (reader != nullptr) {
            reader->Close();
            cerrarConexion();
        }
        return nullptr;
    }
    catch (Exception^ ex)
    {
        cerrarConexion();
        throw gcnew Exception("Error obteniendo punto: " + ex->Message);
    }
}

//Lista Robot Disponible
List<Robot^>^ BotPersistance::Persistance::listaRobotsDisponibles()
{
    List<Robot^>^ listaRobots = GetRobots();
    List<Robot^>^ listaRobotsDisponibles = gcnew List<Robot^>();
    for each (Robot ^ robot in listaRobots) {
        if (robot->Disponibilidad == true) {
            listaRobotsDisponibles->Add(robot);
        }
    }
    return listaRobotsDisponibles;
}


//Registro de alertas
void BotPersistance::Persistance::registrarAlerta(Alert^ alerta) {
    /*
    List<Alert^>^ alertasExistentes = ShowAlertas();

    int maxId = 0;
    for each (Alert ^ alertaExistente in alertasExistentes) {
        if (alertaExistente->id > maxId) {
            maxId = alertaExistente->id;
        }
    }

    alerta->id = maxId + 1;

    if (dynamic_cast<DTIReport^>(alerta) != nullptr) {
        alerta->TipoAlerta = "DTI Reporte";
    }
    else if (dynamic_cast<Altercado^>(alerta) != nullptr) {
        alerta->TipoAlerta = "Altercado";
    }
    else if (dynamic_cast<ObjPerdido^>(alerta) != nullptr) {
        alerta->TipoAlerta = "Objeto Perdido";
    }
    else {
        alerta->TipoAlerta = "General";
    }

    listaReportesAlertas->Add(alerta);
    PersistBinaryFile(fileBinAlertReport, listaReportesAlertas);
    */
    try
    {
        // Determinar tipo de alerta
        if (dynamic_cast<DTIReport^>(alerta) != nullptr) {
            alerta->TipoAlerta = "DTI Reporte";
        }
        else if (dynamic_cast<Altercado^>(alerta) != nullptr) {
            alerta->TipoAlerta = "Altercado";
        }
        else if (dynamic_cast<ObjPerdido^>(alerta) != nullptr) {
            alerta->TipoAlerta = "Objeto Perdido";
        }
        else {
            alerta->TipoAlerta = "General";
        }

        // Guardar en SQL
        int alertaID = AddAlerta(alerta);
        alerta->id = alertaID;
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error registrando alerta en SQL: " + ex->Message);
    }
}
void BotPersistance::Persistance::registrarObjPerdido(ObjPerdido^ objeto) {
    registrarAlerta(objeto);
}
void BotPersistance::Persistance::registrarDTIReport(DTIReport^ reporte) {
    registrarAlerta(reporte);
}
void BotPersistance::Persistance::registrarAltercado(Altercado^ altercado) {
    registrarAlerta(altercado);
}
void BotPersistance::Persistance::registrarZona(ZonaTrabajo^ zona)
{
    /*
    listaZonas->Add(zona);
    PersistTxtFileZonas(fileZonaTrabajo, listaZonas);
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^>
        {
            gcnew SqlParameter("@Nombre", zona->zona),
                gcnew SqlParameter("@X_min", zona->x_min),
                gcnew SqlParameter("@X_max", zona->x_max),
                gcnew SqlParameter("@Y_min", zona->y_min),
                gcnew SqlParameter("@Y_max", zona->y_max)
        };

        executeStoredProcedureNonQuery("usp_AddZona", params);
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error registrando zona: " + ex->Message);
    }
}

int BotPersistance::Persistance::modificarZona(ZonaTrabajo^ zona)
{
    /*
    for (int i = 0; i < listaZonas->Count; i++) {
        if (listaZonas[i]->ID == zona->ID) {
            listaZonas[i] = zona;
            PersistTxtFileZonas(fileZonaTrabajo, listaZonas);
            return 1;
        }
    }
    return 0;
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^>
        {
            gcnew SqlParameter("@ID", zona->ID),
                gcnew SqlParameter("@Nombre", zona->zona),
                gcnew SqlParameter("@X_min", zona->x_min),
                gcnew SqlParameter("@X_max", zona->x_max),
                gcnew SqlParameter("@Y_min", zona->y_min),
                gcnew SqlParameter("@Y_max", zona->y_max)
        };
        int resultado = executeStoredProcedure("usp_UpdateZona", params);

        return resultado;
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error modificando zona: " + ex->Message);
    }
}

bool BotPersistance::Persistance::eliminarZona(int id)
{
    /*
    for (int i = 0; i < listaZonas->Count; i++) {
        if (listaZonas[i]->ID == id) {
            listaZonas->RemoveAt(i);
            PersistTxtFileZonas(fileZonaTrabajo, listaZonas);
            return true;
        }
    }
    return false;
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^>
        {
            gcnew SqlParameter("@ID", id)
        };

        return executeStoredProcedureNonQuery("usp_DeleteZona", params);
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error eliminando zona: " + ex->Message);
    }
}

bool BotPersistance::Persistance::buscarZonaID(int id)
{
    /*
    for (int i = 0; i < listaZonas->Count; i++) {
        if (listaZonas[i]->ID == id) {
            return true;
        }
    }
    return false;
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^> {
            gcnew SqlParameter("@ID", id)
        };

        SqlDataReader^ reader = executeStoredProcedureReader("usp_BuscarZonaPorID", params);
        bool existe = reader->Read();

        reader->Close();
        cerrarConexion();
        return existe;
    }
    catch (Exception^ ex)
    {
        cerrarConexion();
        throw gcnew Exception("Error buscando zona por ID: " + ex->Message);
    }
}

ZonaTrabajo^ BotPersistance::Persistance::buscarReturnZonaId(int id)
{
    /*
    ZonaTrabajo^ zonaEncontrada = nullptr;
    for (int i = 0; i < listaZonas->Count; i++) {
        if (listaZonas[i]->ID == id) {
            zonaEncontrada = listaZonas[i];
            return zonaEncontrada;
        }
    }
    return zonaEncontrada;
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^> {
            gcnew SqlParameter("@ID", id)
        };

        SqlDataReader^ reader = executeStoredProcedureReader("usp_BuscarZonaPorID", params);

        if (reader != nullptr && reader->Read())
        {
            ZonaTrabajo^ zona = gcnew ZonaTrabajo();

            zona->ID = reader->GetInt32(reader->GetOrdinal("ID_Zona"));
            zona->zona = reader["Nombre_zona"]->ToString();
            zona->x_min = reader->GetDouble(reader->GetOrdinal("X_min"));
            zona->x_max = reader->GetDouble(reader->GetOrdinal("X_max"));
            zona->y_min = reader->GetDouble(reader->GetOrdinal("Y_min"));
            zona->y_max = reader->GetDouble(reader->GetOrdinal("Y_max"));

            reader->Close();
            cerrarConexion();
            return zona;
        }

        if (reader != nullptr) {
            reader->Close();
            cerrarConexion();
        }
        return nullptr;
    }
    catch (Exception^ ex)
    {
        cerrarConexion();
        throw gcnew Exception("Error buscando zona por ID: " + ex->Message);
    }
}

List<ZonaTrabajo^>^ BotPersistance::Persistance::GetZonas()
{
    /*
    if (listaZonas->Count == 0) {
        Object^ res = LoadZonasFormTxtFile(fileZonaTrabajo);
        if (res != nullptr) {
            listaZonas = (List<ZonaTrabajo^>^) res;
        }
    }
    return listaZonas;
    */
    List<ZonaTrabajo^>^ lista = gcnew List<ZonaTrabajo^>();

    try
    {
        SqlDataReader^ reader = executeStoredProcedureReader("usp_GetAllZonas", nullptr);

        while (reader->Read())
        {
            ZonaTrabajo^ zona = gcnew ZonaTrabajo();

            zona->ID = reader->GetInt32(reader->GetOrdinal("ID_Zona"));
            zona->zona = reader["Nombre_zona"]->ToString();
            zona->x_min = reader->GetDouble(reader->GetOrdinal("X_min"));
            zona->x_max = reader->GetDouble(reader->GetOrdinal("X_max"));
            zona->y_min = reader->GetDouble(reader->GetOrdinal("Y_min"));
            zona->y_max = reader->GetDouble(reader->GetOrdinal("Y_max"));

            lista->Add(zona);
        }

        reader->Close();
        cerrarConexion();
        return lista;
    }
    catch (Exception^ ex)
    {
        cerrarConexion();
        throw gcnew Exception("Error obteniendo zonas: " + ex->Message);
    }
}

List<Robot^>^ BotPersistance::Persistance::GetRobotsConAlertas()
{
    List<Robot^>^ robots = GetRobots();
    List<Robot^>^ robotsConAlertas = gcnew List<Robot^>();

    for each (Robot ^ robot in robots)
    {
        if (robot->AlertaAsignadaID > 0)
        {
            robotsConAlertas->Add(robot);
        }
    }
    return robotsConAlertas;
}

bool BotPersistance::Persistance::AsignarAlertaRobot(int robotID, int alertaID)
{
    /*
    SqlConnection^ connection = nullptr;
    SqlTransaction^ transaction = nullptr;

    try
    {
        abrirConexion();
        connection = getObjConexion();

        // Verificar que la conexión esté abierta
        if (connection->State != ConnectionState::Open)
        {
            throw gcnew Exception("La conexión a la base de datos no está disponible");
        }

        // Iniciar transacción
        transaction = connection->BeginTransaction();

        // 1. Verificar que la alerta existe y obtener su tipo
        String^ sqlVerificarAlerta =
            "SELECT Tipo_alerta FROM Alertas WHERE ID_Alerta = @AlertaID AND Solucionado = 0";
        SqlCommand^ cmdVerificar = gcnew SqlCommand(sqlVerificarAlerta, connection, transaction);
        cmdVerificar->Parameters->AddWithValue("@AlertaID", alertaID);

        Object^ tipoAlertaObj = cmdVerificar->ExecuteScalar();
        if (tipoAlertaObj == nullptr || tipoAlertaObj == DBNull::Value)
        {
            throw gcnew Exception("La alerta no existe o ya está solucionada");
        }
        String^ tipoMision = tipoAlertaObj->ToString();

        // 2. Verificar que el robot existe y está disponible
        String^ sqlVerificarRobot =
            "SELECT COUNT(*) FROM Robots WHERE ID_Robot = @RobotID AND (Disponibilidad = 1 OR Zona_asignada = 'BASE')";
        SqlCommand^ cmdRobot = gcnew SqlCommand(sqlVerificarRobot, connection, transaction);
        cmdRobot->Parameters->AddWithValue("@RobotID", robotID);

        int robotExiste = Convert::ToInt32(cmdRobot->ExecuteScalar());
        if (robotExiste == 0)
        {
            throw gcnew Exception("El robot no existe o no está disponible");
        }

        // 3. Verificar que la alerta no esté ya asignada a otro robot
        String^ sqlAlertaAsignada =
            "SELECT COUNT(*) FROM Robots WHERE Alerta_asignada_ID = @AlertaID AND ID_Robot != @RobotID";
        SqlCommand^ cmdAlertaAsignada = gcnew SqlCommand(sqlAlertaAsignada, connection, transaction);
        cmdAlertaAsignada->Parameters->AddWithValue("@AlertaID", alertaID);
        cmdAlertaAsignada->Parameters->AddWithValue("@RobotID", robotID);

        int alertaYaAsignada = Convert::ToInt32(cmdAlertaAsignada->ExecuteScalar());
        if (alertaYaAsignada > 0)
        {
            throw gcnew Exception("La alerta ya está asignada a otro robot");
        }

        // 4. Asignar la alerta al robot
        String^ sqlAsignar =
            "UPDATE Robots SET Alerta_asignada_ID = @AlertaID, Tipo_mision = @TipoMision, Disponibilidad = 0 WHERE ID_Robot = @RobotID";
        SqlCommand^ command = gcnew SqlCommand(sqlAsignar, connection, transaction);
        command->Parameters->AddWithValue("@AlertaID", alertaID);
        command->Parameters->AddWithValue("@RobotID", robotID);
        command->Parameters->AddWithValue("@TipoMision", tipoMision);

        int rowsAffected = command->ExecuteNonQuery();

        if (rowsAffected > 0)
        {
            // Confirmar la transacción
            transaction->Commit();
            return true;
        }
        else
        {
            throw gcnew Exception("No se pudo asignar la alerta al robot");
        }
    }
    catch (Exception^ ex)
    {
        // Revertir la transacción en caso de error
        if (transaction != nullptr)
        {
            transaction->Rollback();
        }
        throw gcnew Exception("Error al asignar alerta al robot: " + ex->Message);
    }
    finally
    {
        // Limpiar recursos
        if (transaction != nullptr)
            delete transaction;

        if (connection != nullptr && connection->State == ConnectionState::Open)
        {
            connection->Close();
        }
    }
    */
    SqlConnection^ connection = nullptr;
    SqlTransaction^ transaction = nullptr;

    try
    {
        abrirConexion();
        connection = getObjConexion();

        // Verificar que la conexión esté abierta
        if (connection->State != ConnectionState::Open)
        {
            throw gcnew Exception("La conexión a la base de datos no está disponible");
        }

        // Iniciar transacción
        transaction = connection->BeginTransaction();

        // 1. Verificar que la alerta existe y obtener su tipo Y LUGAR
        String^ sqlVerificarAlerta =
            "SELECT Tipo_alerta, Lugar FROM Alertas WHERE ID_Alerta = @AlertaID AND Solucionado = 0";
        SqlCommand^ cmdVerificar = gcnew SqlCommand(sqlVerificarAlerta, connection, transaction);
        cmdVerificar->Parameters->AddWithValue("@AlertaID", alertaID);

        SqlDataReader^ alertaReader = cmdVerificar->ExecuteReader();
        String^ tipoMision = "Investigación"; // Valor por defecto
        String^ lugarAlerta = "";

        if (alertaReader->Read())
        {
            tipoMision = alertaReader->GetString(0); // Tipo_alerta
            lugarAlerta = alertaReader->GetString(1); // Lugar
        }
        else
        {
            alertaReader->Close();
            throw gcnew Exception("La alerta no existe o ya está solucionada");
        }
        alertaReader->Close();

        // 2. Verificar que el robot existe y está disponible
        String^ sqlVerificarRobot =
            "SELECT COUNT(*) FROM Robots WHERE ID_Robot = @RobotID AND (Disponibilidad = 1 OR Zona_asignada = 'BASE')";
        SqlCommand^ cmdRobot = gcnew SqlCommand(sqlVerificarRobot, connection, transaction);
        cmdRobot->Parameters->AddWithValue("@RobotID", robotID);

        int robotExiste = Convert::ToInt32(cmdRobot->ExecuteScalar());
        if (robotExiste == 0)
        {
            throw gcnew Exception("El robot no existe o no está disponible");
        }

        // 3. Verificar que la alerta no esté ya asignada a otro robot
        String^ sqlAlertaAsignada =
            "SELECT COUNT(*) FROM Robots WHERE Alerta_asignada_ID = @AlertaID AND ID_Robot != @RobotID";
        SqlCommand^ cmdAlertaAsignada = gcnew SqlCommand(sqlAlertaAsignada, connection, transaction);
        cmdAlertaAsignada->Parameters->AddWithValue("@AlertaID", alertaID);
        cmdAlertaAsignada->Parameters->AddWithValue("@RobotID", robotID);

        int alertaYaAsignada = Convert::ToInt32(cmdAlertaAsignada->ExecuteScalar());
        if (alertaYaAsignada > 0)
        {
            throw gcnew Exception("La alerta ya está asignada a otro robot");
        }

        // 4. Asignar la alerta al robot - ACTUALIZADO PARA INCLUIR LA ZONA
        String^ sqlAsignar =
            "UPDATE Robots SET Alerta_asignada_ID = @AlertaID, Tipo_mision = @TipoMision, "
            "Disponibilidad = 0, Zona_asignada = @ZonaAlerta WHERE ID_Robot = @RobotID";

        SqlCommand^ command = gcnew SqlCommand(sqlAsignar, connection, transaction);
        command->Parameters->AddWithValue("@AlertaID", alertaID);
        command->Parameters->AddWithValue("@RobotID", robotID);
        command->Parameters->AddWithValue("@TipoMision", tipoMision);
        command->Parameters->AddWithValue("@ZonaAlerta", lugarAlerta);

        int rowsAffected = command->ExecuteNonQuery();

        if (rowsAffected > 0)
        {
            // Confirmar la transacción
            transaction->Commit();
            return true;
        }
        else
        {
            throw gcnew Exception("No se pudo asignar la alerta al robot");
        }
    }
    catch (Exception^ ex)
    {
        // Revertir la transacción en caso de error
        if (transaction != nullptr)
        {
            transaction->Rollback();
        }
        throw gcnew Exception("Error al asignar alerta al robot: " + ex->Message);
    }
    finally
    {
        // Limpiar recursos
        if (transaction != nullptr)
            delete transaction;

        if (connection != nullptr && connection->State == ConnectionState::Open)
        {
            connection->Close();
        }
    }
}

bool BotPersistance::Persistance::LiberarRobot(int robotID)
{
    /*
    SqlConnection^ connection = nullptr;
    SqlTransaction^ transaction = nullptr;

    try
    {
        abrirConexion();
        connection = getObjConexion();

        if (connection->State != ConnectionState::Open)
        {
            throw gcnew Exception("La conexión a la base de datos no está disponible");
        }

        // Iniciar transacción
        transaction = connection->BeginTransaction();

        // 1. Obtener la alerta asignada al robot
        String^ sqlObtenerAlerta =
            "SELECT Alerta_asignada_ID FROM Robots WHERE ID_Robot = @RobotID";
        SqlCommand^ cmdObtener = gcnew SqlCommand(sqlObtenerAlerta, connection, transaction);
        cmdObtener->Parameters->AddWithValue("@RobotID", robotID);

        Object^ alertaIDObj = cmdObtener->ExecuteScalar();
        int alertaID = 0;
        if (alertaIDObj != nullptr && alertaIDObj != DBNull::Value)
        {
            alertaID = Convert::ToInt32(alertaIDObj);
        }

        // 2. Liberar el robot
        String^ sqlLiberar =
            "UPDATE Robots SET Alerta_asignada_ID = 0, Tipo_mision = '', Disponibilidad = 1, Zona_asignada = 'BASE' WHERE ID_Robot = @RobotID";
        SqlCommand^ command = gcnew SqlCommand(sqlLiberar, connection, transaction);
        command->Parameters->AddWithValue("@RobotID", robotID);

        int rowsAffected = command->ExecuteNonQuery();

        if (rowsAffected > 0)
        {
            // 3. Si tenía una alerta asignada, marcarla como solucionada
            if (alertaID > 0)
            {
                String^ sqlMarcarAlerta =
                    "UPDATE Alertas SET Solucionado = 1 WHERE ID_Alerta = @AlertaID";
                SqlCommand^ cmdMarcar = gcnew SqlCommand(sqlMarcarAlerta, connection, transaction);
                cmdMarcar->Parameters->AddWithValue("@AlertaID", alertaID);
                cmdMarcar->ExecuteNonQuery();
            }

            // Confirmar transacción
            transaction->Commit();
            return true;
        }

        return false;
    }
    catch (Exception^ ex)
    {
        // Revertir transacción en caso de error
        if (transaction != nullptr)
        {
            transaction->Rollback();
        }
        throw gcnew Exception("Error al liberar robot: " + ex->Message);
    }
    finally
    {
        // Limpiar recursos
        if (transaction != nullptr)
            delete transaction;

        if (connection != nullptr && connection->State == ConnectionState::Open)
        {
            connection->Close();
        }
    }
    */
    SqlConnection^ connection = nullptr;
    SqlTransaction^ transaction = nullptr;

    try
    {
        abrirConexion();
        connection = getObjConexion();

        if (connection->State != ConnectionState::Open)
        {
            throw gcnew Exception("La conexión a la base de datos no está disponible");
        }

        // Iniciar transacción
        transaction = connection->BeginTransaction();

        // 1. Obtener la alerta asignada al robot
        String^ sqlObtenerAlerta =
            "SELECT Alerta_asignada_ID FROM Robots WHERE ID_Robot = @RobotID";
        SqlCommand^ cmdObtener = gcnew SqlCommand(sqlObtenerAlerta, connection, transaction);
        cmdObtener->Parameters->AddWithValue("@RobotID", robotID);

        Object^ alertaIDObj = cmdObtener->ExecuteScalar();
        int alertaID = 0;
        if (alertaIDObj != nullptr && alertaIDObj != DBNull::Value)
        {
            alertaID = Convert::ToInt32(alertaIDObj);
        }

        // 2. Liberar el robot - ACTUALIZADO PARA PONER ZONA EN BASE
        String^ sqlLiberar =
            "UPDATE Robots SET Alerta_asignada_ID = 0, Tipo_mision = '', "
            "Disponibilidad = 1, Zona_asignada = 'BASE' WHERE ID_Robot = @RobotID";

        SqlCommand^ command = gcnew SqlCommand(sqlLiberar, connection, transaction);
        command->Parameters->AddWithValue("@RobotID", robotID);

        int rowsAffected = command->ExecuteNonQuery();

        if (rowsAffected > 0)
        {
            // 3. Si tenía una alerta asignada, marcarla como solucionada
            if (alertaID > 0)
            {
                String^ sqlMarcarAlerta =
                    "UPDATE Alertas SET Solucionado = 1 WHERE ID_Alerta = @AlertaID";
                SqlCommand^ cmdMarcar = gcnew SqlCommand(sqlMarcarAlerta, connection, transaction);
                cmdMarcar->Parameters->AddWithValue("@AlertaID", alertaID);
                cmdMarcar->ExecuteNonQuery();
            }

            // Confirmar transacción
            transaction->Commit();
            return true;
        }

        return false;
    }
    catch (Exception^ ex)
    {
        // Revertir transacción en caso de error
        if (transaction != nullptr)
        {
            transaction->Rollback();
        }
        throw gcnew Exception("Error al liberar robot: " + ex->Message);
    }
    finally
    {
        // Limpiar recursos
        if (transaction != nullptr)
            delete transaction;

        if (connection != nullptr && connection->State == ConnectionState::Open)
        {
            connection->Close();
        }
    }
}

List<Alert^>^ BotPersistance::Persistance::GetAlertasPendientes()
{
    List<Alert^>^ todasAlertas = ShowAlertas();
    List<Alert^>^ alertasPendientes = gcnew List<Alert^>();

    for each (Alert ^ alerta in todasAlertas)
    {
        if (!alerta->Solucionado)
        {
            alertasPendientes->Add(alerta);
        }
    }
    return alertasPendientes;
}

bool BotPersistance::Persistance::MarcarAlertaSolucionada(int alertaID)
{
    // Buscar la alerta por ID
    Alert^ alerta = buscarAlerta(alertaID);

    if (alerta != nullptr) {
        // Marcar la alerta como solucionada
        alerta->Solucionado = true;

        // Actualizar la alerta en la base de datos
        return modificarAlerta(alerta) == 1;
    }
    return false;
}

int BotPersistance::Persistance::AddAlerta(Alert^ alerta)
{
    try
    {
        Object^ fotoParam = DBNull::Value;

        if (alerta->Photo != nullptr)
        {
            array<Byte>^ photoBytes = dynamic_cast<array<Byte>^>(alerta->Photo);
            if (photoBytes != nullptr && photoBytes->Length > 0)
            {
                fotoParam = photoBytes;
            }
            else
            {
                fotoParam = DBNull::Value;
                System::Diagnostics::Debug::WriteLine("Advertencia: Photo no es un array de bytes válido en AddAlerta");
            }
        }

        array<SqlParameter^>^ params = gcnew array<SqlParameter^>
        {
            gcnew SqlParameter("@TipoAlerta", alerta->TipoAlerta),
                gcnew SqlParameter("@Fecha", alerta->Fecha),
                gcnew SqlParameter("@Descripcion",
                    String::IsNullOrEmpty(alerta->Description) ?
                    DBNull::Value : (Object^)alerta->Description),
                gcnew SqlParameter("@Lugar",
                    String::IsNullOrEmpty(alerta->Lugar) ?
                    DBNull::Value : (Object^)alerta->Lugar),
                gcnew SqlParameter("@UsuarioID", alerta->UsuarioID),
                gcnew SqlParameter("@UsuarioNombre",
                    String::IsNullOrEmpty(alerta->UsuarioNombre) ?
                    DBNull::Value : (Object^)alerta->UsuarioNombre),
                gcnew SqlParameter("@ObjetoEncontrado",
                    (dynamic_cast<ObjPerdido^>(alerta) != nullptr &&
                        !String::IsNullOrEmpty(dynamic_cast<ObjPerdido^>(alerta)->ObjetoEncontrado)) ?
                    dynamic_cast<ObjPerdido^>(alerta)->ObjetoEncontrado :
                    (Object^)DBNull::Value),
                gcnew SqlParameter("@Tipo_reporte",
                    (dynamic_cast<DTIReport^>(alerta) != nullptr &&
                        !String::IsNullOrEmpty(dynamic_cast<DTIReport^>(alerta)->tipoReporte)) ?
                    dynamic_cast<DTIReport^>(alerta)->tipoReporte :
                    (Object^)DBNull::Value),
                gcnew SqlParameter("@Foto", fotoParam)  // Usar el parámetro ya validado
        };

        return executeStoredProcedure("usp_AddAlerta", params);
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error agregando alerta: " + ex->Message);
    }
}
List<Alert^>^ BotPersistance::Persistance::GetAllAlertas()
{
    List<Alert^>^ lista = gcnew List<Alert^>();

    try
    {
        SqlDataReader^ reader = executeStoredProcedureReader("usp_GetAllAlertas", nullptr);

        while (reader->Read())
        {
            String^ tipoAlerta = reader->GetString(reader->GetOrdinal("Tipo_alerta"));
            Alert^ alerta;

            if (tipoAlerta == "Objeto Perdido")
            {
                ObjPerdido^ obj = gcnew ObjPerdido();
                if (!reader->IsDBNull(reader->GetOrdinal("Objeto_encontrado"))) {
                    obj->ObjetoEncontrado = reader["Objeto_encontrado"]->ToString();
                }
                alerta = obj;
            }
            else if (tipoAlerta == "DTI Reporte")
            {
                DTIReport^ dti = gcnew DTIReport();
                if (!reader->IsDBNull(reader->GetOrdinal("Tipo_reporte"))) {
                    dti->tipoReporte = reader["Tipo_reporte"]->ToString();
                }
                alerta = dti;
            }
            else if (tipoAlerta == "Altercado")
            {
                alerta = gcnew Altercado();
            }
            else
            {
                alerta = gcnew Alert();
            }

            alerta->id = reader->GetInt32(reader->GetOrdinal("ID_Alerta"));
            alerta->TipoAlerta = tipoAlerta;
            alerta->Fecha = reader->GetDateTime(reader->GetOrdinal("Fecha_alerta"));
            alerta->Description = reader["Descripcion"]->ToString();
            alerta->Lugar = reader["Lugar"]->ToString();
            alerta->Solucionado = reader->GetBoolean(reader->GetOrdinal("Solucionado"));
            alerta->UsuarioID = reader->GetInt32(reader->GetOrdinal("Usuario_ID"));
            alerta->UsuarioNombre = reader["Usuario_nombre"]->ToString();

            // MANEJO MEJORADO DE LA FOTO
            if (!reader->IsDBNull(reader->GetOrdinal("Foto"))) {
                try {
                    int fotoIndex = reader->GetOrdinal("Foto");

                    // Verificar si realmente es un array de bytes
                    if (reader[fotoIndex] != nullptr && reader[fotoIndex]->GetType() == array<Byte>::typeid) {
                        alerta->Photo = safe_cast<array<Byte>^>(reader[fotoIndex]);
                    }
                    else {
                        alerta->Photo = nullptr;
                        System::Diagnostics::Debug::WriteLine("Advertencia: El campo Foto no es un array de bytes válido");
                    }
                }
                catch (InvalidCastException^ icex) {
                    alerta->Photo = nullptr;
                    System::Diagnostics::Debug::WriteLine("Advertencia: Error de casteo en foto: " + icex->Message);
                }
                catch (Exception^ ex) {
                    alerta->Photo = nullptr;
                    System::Diagnostics::Debug::WriteLine("Advertencia: Error leyendo foto de alerta: " + ex->Message);
                }
            }
            else {
                alerta->Photo = nullptr;
            }

            lista->Add(alerta);
        }

        reader->Close();
        cerrarConexion();
        return lista;
    }
    catch (Exception^ ex)
    {
        cerrarConexion();
        throw gcnew Exception("Error obteniendo alertas: " + ex->Message);
    }
}

void BotPersistance::Persistance::UpdateUserAlertCounts(int usuarioID, String^ tipoAlerta)
{
    try
    {
        String^ campo = "";
        if (tipoAlerta == "Objeto Perdido") campo = "Perdidas";
        else if (tipoAlerta == "Altercado") campo = "Altercados";
        else if (tipoAlerta == "DTI Reporte") campo = "Reportes_dti";

        if (!String::IsNullOrEmpty(campo))
        {
            String^ sql = String::Format("UPDATE Usuarios SET {0} = {0} + 1 WHERE ID_Usuario = {1}", campo, usuarioID);
            executeSql(sql);
        }
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error actualizando contador de alertas: " + ex->Message);
    }
}

SqlConnection^ BotPersistance::Persistance::getObjConexion()
{
    return objConexion;
}

void BotPersistance::Persistance::abrirConexion()
{
    try {
        // Verificar si objConexion es null y crear nueva instancia
        if (objConexion == nullptr) {
            objConexion = gcnew SqlConnection();
        }

        // Si ya está abierta, no hacer nada
        if (objConexion->State == System::Data::ConnectionState::Open) {
            return;
        }

        //Conexión de Boris
        //objConexion->ConnectionString = "Server=200.16.7.140;DataBase='a20230612';User id='a20230612';Password='Yz2j7Mdt'";

        //Conexion de Rodrigo
        //objConexion->ConnectionString = "Server=200.16.7.140;DataBase=a20230319;User id=a20230319;Password=w2RzV77V";

        //Conexión con AWS
        objConexion->ConnectionString = "Server=idb1inf53.c5gygwkugnnn.us-east-1.rds.amazonaws.com;DataBase=SheriffbotDB;User id=sherifflogin;Password=Sheriffbot";


        objConexion->Open();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Error al abrir conexión: " + ex->Message);
    }
}

int BotPersistance::Persistance::insertSql(String^ sSql)
{
    try {
        abrirConexion();
        SqlCommand^ comando = gcnew SqlCommand(sSql, getObjConexion());
        int idPK = Convert::ToInt32(comando->ExecuteScalar());
        cerrarConexion();
        return idPK;
    }
    catch (Exception^ ex) {
        throw ex;
        return 0;
    }
}

bool BotPersistance::Persistance::executeSql(String^ sSql)
{
    try {
        abrirConexion();
        SqlCommand^ comando = gcnew SqlCommand(sSql, getObjConexion());
        comando->ExecuteNonQuery();
        cerrarConexion();
        return true;
    }
    catch (Exception^ ex) {
        throw ex;
        return false;
    }
}

void BotPersistance::Persistance::cerrarConexion()
{
    try {
        if (objConexion != nullptr && objConexion->State == System::Data::ConnectionState::Open) {
            objConexion->Close();
        }
    }
    catch (Exception^ ex) {
        throw ex;
    }
}

int BotPersistance::Persistance::executeStoredProcedure(String^ procedureName, array<SqlParameter^>^ parameters)
{
    try {
        abrirConexion();
        SqlCommand^ comando = gcnew SqlCommand(procedureName, getObjConexion());
        comando->CommandType = System::Data::CommandType::StoredProcedure;

        if (parameters != nullptr) {
            for each (SqlParameter ^ param in parameters) {
                comando->Parameters->Add(param);
            }
        }

        int result = Convert::ToInt32(comando->ExecuteScalar());
        cerrarConexion();
        return result;
    }
    catch (Exception^ ex) {
        cerrarConexion();
        throw ex;
    }
}

SqlDataReader^ BotPersistance::Persistance::executeStoredProcedureReader(String^ procedureName, array<SqlParameter^>^ parameters)
{
    try {
        //abrirConexion();

        if (objConexion == nullptr || objConexion->State != System::Data::ConnectionState::Open) {
            abrirConexion();
        }

        SqlCommand^ comando = gcnew SqlCommand(procedureName, getObjConexion());
        comando->CommandType = System::Data::CommandType::StoredProcedure;

        if (parameters != nullptr) {
            for each (SqlParameter ^ param in parameters) {
                comando->Parameters->Add(param);
            }
        }

        return comando->ExecuteReader(System::Data::CommandBehavior::CloseConnection);
    }
    catch (Exception^ ex) {
        cerrarConexion();
        throw gcnew Exception("Error en stored procedure reader " + procedureName + ": " + ex->Message);
    }
}

bool BotPersistance::Persistance::executeStoredProcedureNonQuery(String^ procedureName, array<SqlParameter^>^ parameters)
{
    /*
    try {
        abrirConexion();
        SqlCommand^ comando = gcnew SqlCommand(procedureName, getObjConexion());
        comando->CommandType = System::Data::CommandType::StoredProcedure;

        if (parameters != nullptr) {
            for each (SqlParameter ^ param in parameters) {
                comando->Parameters->Add(param);
            }
        }

        comando->ExecuteNonQuery();

        return true;
    }
    catch (Exception^ ex) {
        cerrarConexion();
        throw ex;
    }
    */
    abrirConexion();

    try {
        SqlCommand^ comando = gcnew SqlCommand(procedureName, getObjConexion());
        comando->CommandType = System::Data::CommandType::StoredProcedure;

        if (parameters != nullptr) {
            for each (SqlParameter ^ param in parameters) {
                comando->Parameters->Add(param);
            }
        }

        comando->ExecuteNonQuery();
        return true;
    }
    catch (Exception^ ex) {
        throw ex;
    }
    finally {
        cerrarConexion();
    }
}

List<Alert^>^ BotPersistance::Persistance::ShowAlertas()
{
    /*
    listaReportesAlertas = (List<Alert^>^)LoadBinaryFile(fileBinAlertReport);
    if (listaReportesAlertas == nullptr) {
        listaReportesAlertas = gcnew List<Alert^>();
    }
    return listaReportesAlertas;
    */
    return GetAllAlertas();
}

List<ObjPerdido^>^ BotPersistance::Persistance::ShowObjetosPerdidos()
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

Alert^ BotPersistance::Persistance::buscarAlerta(int id)
{
    /*
    for each (Alert ^ alerta in listaReportesAlertas) {
        if (alerta->id == id) {
            return alerta;
        }
    }
    return nullptr;
    */
    try
    {
        // Obtener todas las alertas y buscar por ID
        List<Alert^>^ todasAlertas = GetAllAlertas();

        for each (Alert ^ alerta in todasAlertas) {
            if (alerta->id == id) {
                return alerta;
            }
        }
        return nullptr;
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error buscando alerta por ID: " + ex->Message);
    }
}

ObjPerdido^ BotPersistance::Persistance::buscarObjetoPerdido(int id)
{
    /*
    Alert^ objeto = buscarAlerta(id);
    if (objeto->GetType() == ObjPerdido::typeid)
        return (ObjPerdido^)objeto;
    return nullptr;
    */
    Alert^ alerta = buscarAlerta(id);
    if (alerta != nullptr && alerta->TipoAlerta == "Objeto Perdido")
        return (ObjPerdido^)alerta;
    return nullptr;
}

Altercado^ BotPersistance::Persistance::buscarAltercado(int id)
{
    /*
    Alert^ altercado = buscarAlerta(id);
    if (altercado->GetType() == Altercado::typeid)
        return (Altercado^)altercado;
    return nullptr;
    */
    Alert^ alerta = buscarAlerta(id);
    if (alerta != nullptr && alerta->TipoAlerta == "Altercado")
        return (Altercado^)alerta;
    return nullptr;
}

DTIReport^ BotPersistance::Persistance::buscarDTIReport(int id)
{
    /*
    Alert^ reporte = buscarAlerta(id);
    if (reporte->GetType() == DTIReport::typeid)
        return (DTIReport^)reporte;
    return nullptr;
    */
    Alert^ alerta = buscarAlerta(id);
    if (alerta != nullptr && alerta->TipoAlerta == "DTI Reporte")
        return (DTIReport^)alerta;
    return nullptr;
}

int BotPersistance::Persistance::modificarAlerta(Alert^ alerta)
{
    /*
    for (int i = 0; i < listaReportesAlertas->Count; i++) {
        if (listaReportesAlertas[i]->id == alerta->id) {
            listaReportesAlertas[i] = alerta;
            PersistBinaryFile(fileBinAlertReport, listaReportesAlertas);
            return 1;
        }
    }
    return 0;
    */
    try
    {
        Object^ fotoParam = DBNull::Value;

        if (alerta->Photo != nullptr)
        {
            // Verificar explícitamente que sea un array de bytes
            array<Byte>^ photoBytes = dynamic_cast<array<Byte>^>(alerta->Photo);
            if (photoBytes != nullptr && photoBytes->Length > 0)
            {
                fotoParam = photoBytes;
            }
            // Si no es válido, mantener DBNull::Value
        }
        
        SqlParameter^ fotoParamSql = gcnew SqlParameter("@Foto", System::Data::SqlDbType::VarBinary, -1);
        fotoParamSql->Value = fotoParam;

        // Preparar campos opcionales como DBNull cuando estén vacíos
        Object^ objetoEncontradoParam = (dynamic_cast<ObjPerdido^>(alerta) != nullptr &&
            !String::IsNullOrEmpty(dynamic_cast<ObjPerdido^>(alerta)->ObjetoEncontrado)) ?
            (Object^)dynamic_cast<ObjPerdido^>(alerta)->ObjetoEncontrado :
            (Object^)DBNull::Value;

        Object^ tipoReporteParam = (dynamic_cast<DTIReport^>(alerta) != nullptr &&
            !String::IsNullOrEmpty(dynamic_cast<DTIReport^>(alerta)->tipoReporte)) ?
            (Object^)dynamic_cast<DTIReport^>(alerta)->tipoReporte :
            (Object^)DBNull::Value;

        array<SqlParameter^>^ params = gcnew array<SqlParameter^>
        {
            gcnew SqlParameter("@ID_Alerta", alerta->id),
                gcnew SqlParameter("@TipoAlerta", alerta->TipoAlerta),
                gcnew SqlParameter("@Descripcion", alerta->Description),
                gcnew SqlParameter("@Lugar", alerta->Lugar),
                gcnew SqlParameter("@Solucionado", alerta->Solucionado),
                gcnew SqlParameter("@ObjetoEncontrado",
                    dynamic_cast<ObjPerdido^>(alerta) != nullptr ?
                    dynamic_cast<ObjPerdido^>(alerta)->ObjetoEncontrado : ""),
                gcnew SqlParameter("@Tipo_reporte",
                    dynamic_cast<DTIReport^>(alerta) != nullptr ?
                    dynamic_cast<DTIReport^>(alerta)->tipoReporte : ""),
                fotoParamSql
        };

        return executeStoredProcedure("usp_UpdateAlerta", params);
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error modificando alerta: " + ex->Message);
    }
}

bool BotPersistance::Persistance::eliminarAlerta(int id)
{
    /*
    for (int i = 0; i < listaReportesAlertas->Count; i++) {
        if (listaReportesAlertas[i]->id == id) {
            listaReportesAlertas->RemoveAt(i);
            PersistBinaryFile(fileBinAlertReport, listaReportesAlertas);
            return true;
        }
    }
    return false;
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^>
        {
            gcnew SqlParameter("@ID_Alerta", id)
        };

        return executeStoredProcedureNonQuery("usp_DeleteAlerta", params);
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error eliminando alerta: " + ex->Message);
    }
}

Alert^ BotPersistance::Persistance::buscarAlertaDescrip(String^ descrip)
{
    /*
    for each (Alert ^ alerta in listaReportesAlertas) {
        if (alerta->Description == descrip) {
            return alerta;
        }
    }
    return nullptr;
    */
    try
    {
        array<SqlParameter^>^ params = gcnew array<SqlParameter^> {
            gcnew SqlParameter("@Descripcion", descrip)
        };

        SqlDataReader^ reader = executeStoredProcedureReader("usp_BuscarAlertaPorDescripcion", params);

        if (reader != nullptr && reader->Read())
        {
            String^ tipoAlerta = reader->GetString(reader->GetOrdinal("Tipo_alerta"));
            Alert^ alerta;

            if (tipoAlerta == "Objeto Perdido")
            {
                ObjPerdido^ obj = gcnew ObjPerdido();
                obj->ObjetoEncontrado = reader["Objeto_encontrado"]->ToString();
                alerta = obj;
            }
            else if (tipoAlerta == "DTI Reporte")
            {
                DTIReport^ dti = gcnew DTIReport();
                dti->tipoReporte = reader["Tipo_reporte"]->ToString();
                alerta = dti;
            }
            else if (tipoAlerta == "Altercado")
            {
                alerta = gcnew Altercado();

            }
            else
            {
                alerta = gcnew Alert();
            }

            alerta->id = reader->GetInt32(reader->GetOrdinal("ID_Alerta"));
            alerta->TipoAlerta = tipoAlerta;
            alerta->Fecha = reader->GetDateTime(reader->GetOrdinal("Fecha_alerta"));
            alerta->Description = reader["Descripcion"]->ToString();
            alerta->Lugar = reader["Lugar"]->ToString();
            alerta->Solucionado = reader->GetBoolean(reader->GetOrdinal("Solucionado"));
            alerta->UsuarioID = reader->GetInt32(reader->GetOrdinal("Usuario_ID"));
            alerta->UsuarioNombre = reader["Usuario_nombre"]->ToString();

            reader->Close();
            cerrarConexion();
            return alerta;
        }

        if (reader != nullptr) {
            reader->Close();
            cerrarConexion();
        }
        return nullptr;
    }
    catch (Exception^ ex)
    {
        cerrarConexion();
        throw gcnew Exception("Error buscando alerta por descripción: " + ex->Message);
    }
}

List<Alert^>^ BotPersistance::Persistance::GetAlertasPorUsuario(int usuarioID)
{
    List<Alert^>^ alertasUsuario = gcnew List<Alert^>();
    List<Alert^>^ todasAlertas = ShowAlertas();

    if (todasAlertas != nullptr) {
        for each (Alert ^ alerta in todasAlertas) {
            if (alerta->UsuarioID == usuarioID) {
                alertasUsuario->Add(alerta);
            }
        }
    }

    return alertasUsuario;
}

int BotPersistance::Persistance::GetCantidadAlertasPorUsuario(int usuarioID)
{
    List<Alert^>^ alertasUsuario = GetAlertasPorUsuario(usuarioID);
    return alertasUsuario != nullptr ? alertasUsuario->Count : 0;
}
