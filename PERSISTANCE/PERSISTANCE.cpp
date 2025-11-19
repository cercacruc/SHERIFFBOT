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
            gcnew SqlParameter("@PosicionY", robot->PosicionRobot->y)
        };

        executeStoredProcedure("usp_AddRobot", params);
    }
    catch (Exception^ ex)
    {
        throw gcnew Exception("Error registrando robot: " + ex->Message);
    }
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
            gcnew SqlParameter("@PosicionY", robot->PosicionRobot->y)
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
   /*
    GetUsuarios();
    for each (DatosUsuario ^ usuario in listaUsuarios) {
        if (usuario->Nombre->Equals(nombre) && usuario->Contra->Equals(contra)) {
            return usuario;
        }
    }
    return nullptr;
    */

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
    for (int i = 0; i < listaUsuarios->Count; i++) {
        if (listaUsuarios[i]->Nombre->Equals(nombre)) {
            listaUsuarios->RemoveAt(i);
            //PersistTextFileUsers(fileUsersName, listaUsuarios);
            PersistBinaryFile(fileBinUsers, listaUsuarios);
            return true;
        }
    }
    return false;
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
        array<SqlParameter^>^ params = {
            gcnew SqlParameter("@Nombre", usuario),
            gcnew SqlParameter("@NuevaContra", nuevaContra)
        };

        int result = executeStoredProcedure("usp_ResetPassword", params);

        return result;  // 1 = actualizado, 0 = usuario no existe
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
    listaZonas->Add(zona);
    PersistTxtFileZonas(fileZonaTrabajo, listaZonas);
}

int BotPersistance::Persistance::modificarZona(ZonaTrabajo^ zona)
{
    for (int i = 0; i < listaZonas->Count; i++) {
        if (listaZonas[i]->ID == zona->ID) {
            listaZonas[i] = zona;
            PersistTxtFileZonas(fileZonaTrabajo, listaZonas);
            return 1;
        }
    }
    return 0;
}

bool BotPersistance::Persistance::eliminarZona(int id)
{
    for (int i = 0; i < listaZonas->Count; i++) {
        if (listaZonas[i]->ID == id) {
            listaZonas->RemoveAt(i);
            PersistTxtFileZonas(fileZonaTrabajo, listaZonas);
            return true;
        }
    }
    return false;
}

bool BotPersistance::Persistance::buscarZonaID(int id)
{
    for (int i = 0; i < listaZonas->Count; i++) {
        if (listaZonas[i]->ID == id) {
            return true;
        }
    }
    return false;
}

ZonaTrabajo^ BotPersistance::Persistance::buscarReturnZonaId(int id)
{
    ZonaTrabajo^ zonaEncontrada = nullptr;
    for (int i = 0; i < listaZonas->Count; i++) {
        if (listaZonas[i]->ID == id) {
            zonaEncontrada = listaZonas[i];
            return zonaEncontrada;
        }
    }
    return zonaEncontrada;
}

List<ZonaTrabajo^>^ BotPersistance::Persistance::GetZonas()
{
    if (listaZonas->Count == 0) {
        Object^ res = LoadZonasFormTxtFile(fileZonaTrabajo);
        if (res != nullptr) {
            listaZonas = (List<ZonaTrabajo^>^) res;
        }
    }
    return listaZonas;
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
    Robot^ robot = buscarRobotID(robotID);
    Alert^ alerta = buscarAlerta(alertaID);

    if (robot != nullptr && alerta != nullptr && robot->Disponibilidad)
    {
        robot->AlertaAsignadaID = alertaID;
        robot->TipoMision = "ALERTA";
        robot->Disponibilidad = false;
        robot->Zona = alerta->Lugar;

        return modificarRobotID(robot) == 1;
    }
    return false;
}

bool BotPersistance::Persistance::LiberarRobot(int robotID)
{
    Robot^ robot = buscarRobotID(robotID);

    if (robot != nullptr) {
        int alertaID = robot->AlertaAsignadaID;

        robot->AlertaAsignadaID = 0;
        robot->TipoMision = "";
        robot->Disponibilidad = true;
        robot->Zona = "BASE";

        // Actualizar el robot en la base de datos
        bool robotActualizado = modificarRobotID(robot) == 1;

        // Si el robot tenía una alerta asignada, marcarla como solucionada
        if (robotActualizado && alertaID > 0) {
            // Necesitarás una función para marcar la alerta como solucionada
            return MarcarAlertaSolucionada(alertaID);
        }

        return robotActualizado;
    }
    return false;
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
        objConexion->ConnectionString = "Server=200.16.7.140;DataBase='a20230612';User id='a20230612';Password='Yz2j7Mdt'";

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
        abrirConexion();
        SqlCommand^ comando = gcnew SqlCommand(procedureName, getObjConexion());
        comando->CommandType = System::Data::CommandType::StoredProcedure;

        if (parameters != nullptr) {
            for each (SqlParameter ^ param in parameters) {
                comando->Parameters->Add(param);
            }
        }

        return comando->ExecuteReader();
    }
    catch (Exception^ ex) {
        cerrarConexion();
        throw ex;
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
    listaReportesAlertas = (List<Alert^>^)LoadBinaryFile(fileBinAlertReport);
    if (listaReportesAlertas == nullptr) {
        listaReportesAlertas = gcnew List<Alert^>();
    }
    return listaReportesAlertas;
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
    for each (Alert ^ alerta in listaReportesAlertas) {
        if (alerta->id == id) {
            return alerta;
        }
    }
    return nullptr;
}

ObjPerdido^ BotPersistance::Persistance::buscarObjetoPerdido(int id)
{
    Alert^ objeto = buscarAlerta(id);
    if (objeto->GetType() == ObjPerdido::typeid)
        return (ObjPerdido^)objeto;
    return nullptr;
}

Altercado^ BotPersistance::Persistance::buscarAltercado(int id)
{
    Alert^ altercado = buscarAlerta(id);
    if (altercado->GetType() == Altercado::typeid)
        return (Altercado^)altercado;
    return nullptr;
}

DTIReport^ BotPersistance::Persistance::buscarDTIReport(int id)
{
    Alert^ reporte = buscarAlerta(id);
    if (reporte->GetType() == DTIReport::typeid)
        return (DTIReport^)reporte;
    return nullptr;
}

int BotPersistance::Persistance::modificarAlerta(Alert^ alerta)
{
    for (int i = 0; i < listaReportesAlertas->Count; i++) {
        if (listaReportesAlertas[i]->id == alerta->id) {
            listaReportesAlertas[i] = alerta;
            PersistBinaryFile(fileBinAlertReport, listaReportesAlertas);
            return 1;
        }
    }
    return 0;
}

bool BotPersistance::Persistance::eliminarAlerta(int id)
{
    for (int i = 0; i < listaReportesAlertas->Count; i++) {
        if (listaReportesAlertas[i]->id == id) {
            listaReportesAlertas->RemoveAt(i);
            PersistBinaryFile(fileBinAlertReport, listaReportesAlertas);
            return true;
        }
    }
    return false;
}

Alert^ BotPersistance::Persistance::buscarAlertaDescrip(String^ descrip)
{
    for each (Alert ^ alerta in listaReportesAlertas) {
        if (alerta->Description == descrip) {
            return alerta;
        }
    }
    return nullptr;
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
