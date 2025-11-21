-- Eliminar tablas si existen
IF OBJECT_ID('Puntos', 'U') IS NOT NULL DROP TABLE Puntos;
IF OBJECT_ID('Alertas', 'U') IS NOT NULL DROP TABLE Alertas;
IF OBJECT_ID('Robots', 'U') IS NOT NULL DROP TABLE Robots;
IF OBJECT_ID('ZonasTrabajo', 'U') IS NOT NULL DROP TABLE ZonasTrabajo;
IF OBJECT_ID('Usuarios', 'U') IS NOT NULL DROP TABLE Usuarios;
GO

-- Tabla de Usuarios
CREATE TABLE Usuarios (
    ID_Usuario INT PRIMARY KEY,
    Nombre_de_usuario NVARCHAR(100) NOT NULL UNIQUE,
    Contrasena NVARCHAR(100) NOT NULL,
    Cargo NVARCHAR(50) NOT NULL,
    Perdidas INT DEFAULT 0,
    Altercados INT DEFAULT 0,
    Reportes_dti INT DEFAULT 0,
    Fecha_creacion DATETIME DEFAULT GETDATE()
);
GO

-- Tabla de Zonas de Trabajo
CREATE TABLE ZonasTrabajo (
    ID_Zona INT PRIMARY KEY IDENTITY(1,1),
    Nombre_zona NVARCHAR(100) NOT NULL,
    X_min FLOAT NOT NULL,
    X_max FLOAT NOT NULL,
    Y_min FLOAT NOT NULL,
    Y_max FLOAT NOT NULL
);
GO

-- Tabla de Robots
CREATE TABLE Robots (
    ID_Robot INT PRIMARY KEY IDENTITY(1,1),
    Nombre_robot NVARCHAR(100) NOT NULL UNIQUE,
    Zona_asignada NVARCHAR(100),
    Posicion_X FLOAT DEFAULT 0,
    Posicion_Y FLOAT DEFAULT 0,
    Bateria INT DEFAULT 100,
    Disponibilidad BIT DEFAULT 1,
    Caracteristicas NVARCHAR(MAX),
    Alerta_asignada_ID INT DEFAULT 0,
    Tipo_mision NVARCHAR(50)
);
GO

-- Tabla de Alertas (Base)
CREATE TABLE Alertas (
    ID_Alerta INT PRIMARY KEY IDENTITY(1,1),
    Tipo_alerta NVARCHAR(50) NOT NULL, -- 'General', 'Objeto Perdido', 'Altercado', 'DTI Reporte'
    Fecha_alerta DATETIME NOT NULL,
    Descripcion NVARCHAR(MAX),
    Lugar NVARCHAR(200),
    Solucionado BIT DEFAULT 0,
    Usuario_ID INT,
    Usuario_nombre NVARCHAR(100),
    Foto VARBINARY(MAX),
    -- Campos específicos para Objeto Perdido
    Objeto_encontrado NVARCHAR(200),
    -- Campos específicos para DTI Report
    Tipo_reporte NVARCHAR(100)
);
GO

-- Tabla de Puntos (Posiciones)
CREATE TABLE Puntos (
    ID_Punto INT PRIMARY KEY IDENTITY(1,1),
    Coordenada_X FLOAT NOT NULL,
    Coordenada_Y FLOAT NOT NULL,
    Ubicacion NVARCHAR(200),
    Fecha_registro DATETIME DEFAULT GETDATE()
);
GO

-- Eliminar procedimientos almacenados si existen
IF OBJECT_ID('usp_RegistrarUsuario', 'P') IS NOT NULL DROP PROCEDURE usp_RegistrarUsuario;
IF OBJECT_ID('usp_GenerarIDUsuario', 'P') IS NOT NULL DROP PROCEDURE usp_GenerarIDUsuario;
IF OBJECT_ID('usp_LoginUser', 'P') IS NOT NULL DROP PROCEDURE usp_LoginUser;
IF OBJECT_ID('usp_QueryAllUsers', 'P') IS NOT NULL DROP PROCEDURE usp_QueryAllUsers;
IF OBJECT_ID('usp_ModificarUsuario', 'P') IS NOT NULL DROP PROCEDURE usp_ModificarUsuario;
IF OBJECT_ID('usp_BorrarUsuario', 'P') IS NOT NULL DROP PROCEDURE usp_BorrarUsuario;
IF OBJECT_ID('usp_ResetPassword', 'P') IS NOT NULL DROP PROCEDURE usp_ResetPassword;

IF OBJECT_ID('usp_UpdateRobot', 'P') IS NOT NULL DROP PROCEDURE usp_UpdateRobot;
IF OBJECT_ID('usp_DeleteRobot', 'P') IS NOT NULL DROP PROCEDURE usp_DeleteRobot;
IF OBJECT_ID('usp_GetAllRobots', 'P') IS NOT NULL DROP PROCEDURE usp_GetAllRobots;
IF OBJECT_ID('usp_AddAlerta', 'P') IS NOT NULL DROP PROCEDURE usp_AddAlerta;
IF OBJECT_ID('usp_GetAlertasPorUsuario', 'P') IS NOT NULL DROP PROCEDURE usp_GetAlertasPorUsuario;
IF OBJECT_ID('usp_GetAllAlertas', 'P') IS NOT NULL DROP PROCEDURE usp_GetAllAlertas;
IF OBJECT_ID('usp_AddZona', 'P') IS NOT NULL DROP PROCEDURE usp_AddZona;
IF OBJECT_ID('usp_BuscarUsuarioPorID', 'P') IS NOT NULL DROP PROCEDURE usp_BuscarUsuarioPorID;
IF OBJECT_ID('usp_BuscarUsuarioPorNombre', 'P') IS NOT NULL DROP PROCEDURE usp_BuscarUsuarioPorNombre;
IF OBJECT_ID('usp_BuscarRobotPorID', 'P') IS NOT NULL DROP PROCEDURE usp_BuscarRobotPorID;
IF OBJECT_ID('usp_BuscarRobotPorNombre', 'P') IS NOT NULL DROP PROCEDURE usp_BuscarRobotPorNombre;
IF OBJECT_ID('usp_GetAllZonas', 'P') IS NOT NULL DROP PROCEDURE usp_GetAllZonas;
IF OBJECT_ID('usp_BuscarZonaPorID', 'P') IS NOT NULL DROP PROCEDURE usp_BuscarZonaPorID;
IF OBJECT_ID('usp_UpdateZona', 'P') IS NOT NULL DROP PROCEDURE usp_UpdateZona;
IF OBJECT_ID('usp_DeleteZona', 'P') IS NOT NULL DROP PROCEDURE usp_DeleteZona;
IF OBJECT_ID('usp_AddPunto', 'P') IS NOT NULL DROP PROCEDURE usp_AddPunto;
IF OBJECT_ID('usp_GetPunto', 'P') IS NOT NULL DROP PROCEDURE usp_GetPunto;
IF OBJECT_ID('usp_UpdateAlerta', 'P') IS NOT NULL DROP PROCEDURE usp_UpdateAlerta;
IF OBJECT_ID('usp_DeleteAlerta', 'P') IS NOT NULL DROP PROCEDURE usp_DeleteAlerta;
IF OBJECT_ID('usp_BuscarAlertaPorID', 'P') IS NOT NULL DROP PROCEDURE usp_BuscarAlertaPorID;
IF OBJECT_ID('usp_BuscarAlertaPorDescripcion', 'P') IS NOT NULL DROP PROCEDURE usp_BuscarAlertaPorDescripcion;
GO

-- Procedimientos Almacenados para Usuarios
CREATE PROCEDURE usp_RegistrarUsuario
    @ID INT,
    @Nombre NVARCHAR(100),
    @Contra NVARCHAR(100),
    @Cargo NVARCHAR(50),
    @Cant1 INT,
    @Cant2 INT,
    @Cant3 INT
AS
BEGIN
    INSERT INTO Usuarios (ID_Usuario, Nombre_de_usuario, Contrasena, Cargo, Perdidas, Altercados, Reportes_dti)
    VALUES (@ID, @Nombre, @Contra, @Cargo, @Cant1, @Cant2, @Cant3);
END
GO

CREATE PROCEDURE usp_GenerarIDUsuario
    @Cargo NVARCHAR(50),
    @NuevoID INT OUTPUT
AS
BEGIN
    DECLARE @Prefijo NVARCHAR(2);
    DECLARE @MaxNumero INT = 0;
    
    -- Determinar prefijo según cargo
    SET @Prefijo = CASE 
        WHEN LOWER(@Cargo) = 'sheriff' THEN '11'
        WHEN LOWER(@Cargo) = 'estudiante' THEN '22'
        WHEN LOWER(@Cargo) = 'profesor' THEN '33'
        WHEN LOWER(@Cargo) = 'visitante externo' THEN '44'
        WHEN LOWER(@Cargo) = 'admin' THEN '99'
        ELSE '88'
    END;
    
    -- Encontrar el máximo número existente
    SELECT @MaxNumero = ISNULL(MAX(CAST(SUBSTRING(CAST(ID_Usuario AS NVARCHAR), 3, LEN(CAST(ID_Usuario AS NVARCHAR))-2) AS INT)), 0)
    FROM Usuarios 
    WHERE CAST(ID_Usuario AS NVARCHAR) LIKE @Prefijo + '%';
    
    -- Generar nuevo ID
    SET @NuevoID = CAST(@Prefijo + CAST((@MaxNumero + 1) AS NVARCHAR(10)) AS INT);
END
GO

CREATE PROCEDURE usp_LoginUser
    @Nombre NVARCHAR(100),
    @Contra NVARCHAR(100)
AS
BEGIN
    SELECT ID_Usuario, Nombre_de_usuario, Contrasena, Cargo, Perdidas, Altercados, Reportes_dti
    FROM Usuarios 
    WHERE Nombre_de_usuario = @Nombre AND Contrasena = @Contra;
END
GO

CREATE PROCEDURE usp_QueryAllUsers
AS
BEGIN
    SELECT ID_Usuario, Nombre_de_usuario, Contrasena, Cargo, Perdidas, Altercados, Reportes_dti
    FROM Usuarios;
END
GO

CREATE PROCEDURE usp_ModificarUsuario
    @ID INT,
    @Nombre NVARCHAR(100),
    @Contra NVARCHAR(100),
    @Cargo NVARCHAR(50),
    @Cant1 INT,
    @Cant2 INT,
    @Cant3 INT
AS
BEGIN
    UPDATE Usuarios 
    SET Nombre_de_usuario = @Nombre,
        Contrasena = @Contra,
        Cargo = @Cargo,
        Perdidas = @Cant1,
        Altercados = @Cant2,
        Reportes_dti = @Cant3
    WHERE ID_Usuario = @ID;
END
GO

CREATE PROCEDURE usp_BorrarUsuario
    @ID INT
AS
BEGIN
    DELETE FROM Usuarios WHERE ID_Usuario = @ID;
END
GO

CREATE PROCEDURE usp_ResetPassword
    @Nombre NVARCHAR(100),
    @NuevaContra NVARCHAR(100)
AS
BEGIN
    UPDATE Usuarios 
    SET Contrasena = @NuevaContra
    WHERE Nombre_de_usuario = @Nombre;
    
    RETURN @@ROWCOUNT;
END
GO

-- Procedimientos para Robots
-- Eliminar procedimientos existentes si existen
IF OBJECT_ID('usp_AddRobot', 'P') IS NOT NULL 
    DROP PROCEDURE usp_AddRobot;
GO

IF OBJECT_ID('usp_UpdateRobot', 'P') IS NOT NULL 
    DROP PROCEDURE usp_UpdateRobot;
GO

-- Crear procedimiento usp_AddRobot actualizado
CREATE PROCEDURE usp_AddRobot
    @Nombre NVARCHAR(100),
    @Zona NVARCHAR(100),
    @Bateria INT,
    @PosicionX FLOAT,
    @PosicionY FLOAT,
    @Caracteristicas NVARCHAR(MAX) = NULL
AS
BEGIN
    INSERT INTO Robots (Nombre_robot, Zona_asignada, Bateria, Posicion_X, Posicion_Y, Caracteristicas, Disponibilidad)
    VALUES (@Nombre, @Zona, @Bateria, @PosicionX, @PosicionY, @Caracteristicas, 1);
    
    RETURN SCOPE_IDENTITY();
END
GO

-- Crear procedimiento usp_UpdateRobot actualizado
CREATE PROCEDURE usp_UpdateRobot
    @ID INT,
    @Nombre NVARCHAR(100),
    @Zona NVARCHAR(100),
    @Bateria INT,
    @PosicionX FLOAT,
    @PosicionY FLOAT,
    @Caracteristicas NVARCHAR(MAX) = NULL,
    @Disponibilidad BIT = 1
AS
BEGIN
    UPDATE Robots 
    SET Nombre_robot = @Nombre,
        Zona_asignada = @Zona,
        Bateria = @Bateria,
        Posicion_X = @PosicionX,
        Posicion_Y = @PosicionY,
        Caracteristicas = @Caracteristicas,
        Disponibilidad = @Disponibilidad
    WHERE ID_Robot = @ID;
    
    RETURN @@ROWCOUNT;
END
GO

CREATE PROCEDURE usp_DeleteRobot
    @ID INT
AS
BEGIN
    DELETE FROM Robots WHERE ID_Robot = @ID;
    RETURN @@ROWCOUNT;
END
GO

CREATE PROCEDURE usp_GetAllRobots
AS
BEGIN
    SELECT ID_Robot, Nombre_robot, Zona_asignada, Bateria, Posicion_X, Posicion_Y,
           Disponibilidad, Caracteristicas, Alerta_asignada_ID, Tipo_mision
    FROM Robots;
END
GO

-- Procedimientos para Alertas
CREATE PROCEDURE usp_AddAlerta
    @TipoAlerta NVARCHAR(50),
    @Fecha DATETIME,
    @Descripcion NVARCHAR(MAX),
    @Lugar NVARCHAR(200),
    @UsuarioID INT,
    @UsuarioNombre NVARCHAR(100),
    @ObjetoEncontrado NVARCHAR(200) = NULL,
    @TipoReporte NVARCHAR(100) = NULL
AS
BEGIN
    INSERT INTO Alertas (Tipo_alerta, Fecha_alerta, Descripcion, Lugar, Usuario_ID, Usuario_nombre, Objeto_encontrado, Tipo_reporte)
    VALUES (@TipoAlerta, @Fecha, @Descripcion, @Lugar, @UsuarioID, @UsuarioNombre, @ObjetoEncontrado, @TipoReporte);
    
    RETURN SCOPE_IDENTITY();
END
GO

CREATE PROCEDURE usp_GetAlertasPorUsuario
    @UsuarioID INT
AS
BEGIN
    SELECT ID_Alerta, Tipo_alerta, Fecha_alerta, Descripcion, Lugar, Solucionado, 
           Usuario_ID, Usuario_nombre, Objeto_encontrado, Tipo_reporte
    FROM Alertas
    WHERE Usuario_ID = @UsuarioID;
END
GO

CREATE PROCEDURE usp_GetAllAlertas
AS
BEGIN
    SELECT ID_Alerta, Tipo_alerta, Fecha_alerta, Descripcion, Lugar, Solucionado, 
           Usuario_ID, Usuario_nombre, Objeto_encontrado, Tipo_reporte
    FROM Alertas;
END
GO

-- Procedimiento para modificar alerta
CREATE PROCEDURE usp_UpdateAlerta
    @ID_Alerta INT,
    @TipoAlerta NVARCHAR(50),
    @Descripcion NVARCHAR(MAX),
    @Lugar NVARCHAR(200),
    @Solucionado BIT,
    @ObjetoEncontrado NVARCHAR(200) = NULL,
    @TipoReporte NVARCHAR(100) = NULL
AS
BEGIN
    UPDATE Alertas 
    SET Tipo_alerta = @TipoAlerta,
        Descripcion = @Descripcion,
        Lugar = @Lugar,
        Solucionado = @Solucionado,
        Objeto_encontrado = @ObjetoEncontrado,
        Tipo_reporte = @TipoReporte
    WHERE ID_Alerta = @ID_Alerta;
    
    RETURN @@ROWCOUNT;
END
GO

-- Procedimiento para eliminar alerta
CREATE PROCEDURE usp_DeleteAlerta
    @ID_Alerta INT
AS
BEGIN
    DELETE FROM Alertas WHERE ID_Alerta = @ID_Alerta;
    RETURN @@ROWCOUNT;
END
GO

-- Procedimiento para buscar alerta por ID
CREATE PROCEDURE usp_BuscarAlertaPorID
    @ID_Alerta INT
AS
BEGIN
    SELECT ID_Alerta, Tipo_alerta, Fecha_alerta, Descripcion, Lugar, Solucionado, 
           Usuario_ID, Usuario_nombre, Objeto_encontrado, Tipo_reporte
    FROM Alertas
    WHERE ID_Alerta = @ID_Alerta;
END
GO

-- Procedimiento para buscar alerta por descripción
CREATE PROCEDURE usp_BuscarAlertaPorDescripcion
    @Descripcion NVARCHAR(MAX)
AS
BEGIN
    SELECT ID_Alerta, Tipo_alerta, Fecha_alerta, Descripcion, Lugar, Solucionado, 
           Usuario_ID, Usuario_nombre, Objeto_encontrado, Tipo_reporte
    FROM Alertas
    WHERE Descripcion LIKE '%' + @Descripcion + '%';
END
GO

-- Procedimientos para Zonas
CREATE PROCEDURE usp_AddZona
    @Nombre NVARCHAR(100),
    @X_min FLOAT,
    @X_max FLOAT,
    @Y_min FLOAT,
    @Y_max FLOAT
AS
BEGIN
    INSERT INTO ZonasTrabajo (Nombre_zona, X_min, X_max, Y_min, Y_max)
    VALUES (@Nombre, @X_min, @X_max, @Y_min, @Y_max);
END
GO

-- Procedimiento para buscar usuario por ID
CREATE PROCEDURE usp_BuscarUsuarioPorID
    @ID INT
AS
BEGIN
    SELECT ID_Usuario, Nombre_de_usuario, Contrasena, Cargo, Perdidas, Altercados, Reportes_dti
    FROM Usuarios 
    WHERE ID_Usuario = @ID;
END
GO

-- Procedimiento para buscar usuario por Nombre
CREATE PROCEDURE usp_BuscarUsuarioPorNombre
    @Nombre NVARCHAR(100)
AS
BEGIN
    SELECT ID_Usuario, Nombre_de_usuario, Contrasena, Cargo, Perdidas, Altercados, Reportes_dti
    FROM Usuarios 
    WHERE Nombre_de_usuario = @Nombre;
END
GO

-- Buscar robot por ID
CREATE PROCEDURE usp_BuscarRobotPorID
    @ID INT
AS
BEGIN
    SELECT ID_Robot, Nombre_robot, Zona_asignada, Bateria, Posicion_X, Posicion_Y,
           Disponibilidad, Caracteristicas, Alerta_asignada_ID, Tipo_mision
    FROM Robots 
    WHERE ID_Robot = @ID;
END
GO

-- Buscar robot por Nombre
CREATE PROCEDURE usp_BuscarRobotPorNombre
    @Nombre NVARCHAR(100)
AS
BEGIN
    SELECT ID_Robot, Nombre_robot, Zona_asignada, Bateria, Posicion_X, Posicion_Y,
           Disponibilidad, Caracteristicas, Alerta_asignada_ID, Tipo_mision
    FROM Robots 
    WHERE Nombre_robot = @Nombre;
END
GO

-- Procedimientos adicionales para Zonas
CREATE PROCEDURE usp_GetAllZonas
AS
BEGIN
    SELECT ID_Zona, Nombre_zona, X_min, X_max, Y_min, Y_max
    FROM ZonasTrabajo;
END
GO

CREATE PROCEDURE usp_BuscarZonaPorID
    @ID INT
AS
BEGIN
    SELECT ID_Zona, Nombre_zona, X_min, X_max, Y_min, Y_max
    FROM ZonasTrabajo 
    WHERE ID_Zona = @ID;
END
GO

CREATE PROCEDURE usp_UpdateZona
    @ID INT,
    @Nombre NVARCHAR(100),
    @X_min FLOAT,
    @X_max FLOAT,
    @Y_min FLOAT,
    @Y_max FLOAT
AS
BEGIN
    UPDATE ZonasTrabajo 
    SET Nombre_zona = @Nombre,
        X_min = @X_min,
        X_max = @X_max,
        Y_min = @Y_min,
        Y_max = @Y_max
    WHERE ID_Zona = @ID;
    
    RETURN @@ROWCOUNT;
END
GO

CREATE PROCEDURE usp_DeleteZona
    @ID INT
AS
BEGIN
    DELETE FROM ZonasTrabajo WHERE ID_Zona = @ID;
    RETURN @@ROWCOUNT;
END
GO

-- Procedimientos para Puntos
CREATE PROCEDURE usp_AddPunto
    @X FLOAT,
    @Y FLOAT,
    @Ubicacion NVARCHAR(200)
AS
BEGIN
    INSERT INTO Puntos (Coordenada_X, Coordenada_Y, Ubicacion)
    VALUES (@X, @Y, @Ubicacion);
END
GO

CREATE PROCEDURE usp_GetPunto
    @X FLOAT,
    @Y FLOAT
AS
BEGIN
    SELECT ID_Punto, Coordenada_X, Coordenada_Y, Ubicacion
    FROM Puntos 
    WHERE Coordenada_X = @X AND Coordenada_Y = @Y;
END
GO

-- Insertar datos iniciales
INSERT INTO ZonasTrabajo (Nombre_zona, X_min, X_max, Y_min, Y_max) VALUES
('Zona A', 0, 100, 0, 100),
('Zona B', 100, 200, 0, 100),
('Zona C', 0, 100, 100, 200);
GO

-- Insertar usuario admin por defecto
INSERT INTO Usuarios (ID_Usuario, Nombre_de_usuario, Contrasena, Cargo) 
VALUES (990, 'admin', 'admin123', 'admin');
GO

-- Mensaje de confirmación
PRINT '✅ Base de datos BotSecurityDB creada exitosamente con todas las tablas y procedimientos.';
PRINT '✅ Usuario admin creado: admin / admin123';
PRINT '✅ 3 zonas de trabajo creadas por defecto.';
PRINT '✅ Todos los procedimientos almacenados creados correctamente.';
GO

-- Procedimiento para borrar usuario por nombre
CREATE PROCEDURE usp_BorrarUsuarioPorNombre
    @Nombre NVARCHAR(100)
AS
BEGIN
    DELETE FROM Usuarios WHERE Nombre_de_usuario = @Nombre;
    RETURN @@ROWCOUNT;
END
GO

-- Procedimiento para borrar robot por nombre
CREATE PROCEDURE usp_BorrarRobotPorNombre
    @Nombre NVARCHAR(100)
AS
BEGIN
    DELETE FROM Robots WHERE Nombre_robot = @Nombre;
    RETURN @@ROWCOUNT;
END
GO



SELECT * FROM Usuarios;

SELECT * FROM Alertas;

SELECT * FROM Robots;