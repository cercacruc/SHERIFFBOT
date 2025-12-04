from machine import Pin
from config.config import CONFIG
from robot import get_robot
from utils.communication import CommunicationManager
from config.student_config import COMMUNICATION_CFG
import uasyncio
import utime
import ujson

# ====================================================
# ================= ROBOT SETUP ======================
# ====================================================
ROBOT_TYPE = 'mecanum'
led = Pin("LED", Pin.OUT)
robot = get_robot(ROBOT_TYPE, CONFIG[ROBOT_TYPE])
robot.set_control_mode(closed_loop = False)
comm = CommunicationManager(COMMUNICATION_CFG)
connection_established = False #nueva variable
led.on()

mensajes_recibidos = 0
# ====================================================
# =================  COMM FUNCTIONS ==================
# ====================================================
async def publisher_task():
    """Solo para debug ahora"""
    counter = 0
    while True:
        if counter % 50 == 0:  # Cada 2.5 segundos
            print(f"⏰ Pico funcionando... Mensajes recibidos: {mensajes_recibidos}")
        counter += 1
        await uasyncio.sleep_ms(50)

async def subscription_task():
    """Suscripción a mensajes"""
    topic_subs = "R08/teleop/cmd"
    
    print("=" * 50)
    print("🤖 INICIANDO SUSCRIPCIÓN MQTT")
    print(f"📡 Topic: {topic_subs}")
    print(f"🌐 Broker: {COMMUNICATION_CFG['MQTT'].get('mqtt_server', 'broker.hivemq.com')}")
    print("=" * 50)
    
    # Suscribirse
    comm.add_callback(topic_subs, msgCallback)
    comm.subscribe(topic_subs)
    print("✅ Suscrito al topic")
    
    while True:
        comm.check_incoming()
        await uasyncio.sleep_ms(10)

def msgCallback(msg):
    """Función para controlar movimiento de robot"""
    global mensajes_recibidos
    
    try:
        msg_str = msg.decode('utf-8') if isinstance(msg, bytes) else str(msg)
        msg_str = msg_str.strip().lower()
        
        mensajes_recibidos += 1
        print(f"🎯 MENSAJE #{mensajes_recibidos} RECIBIDO: '{msg_str}'")
        
        # Mapeo de comandos
        command_map = {
            'w': 'ADELANTE',
            's': 'ATRÁS', 
            'a': 'IZQUIERDA',
            'd': 'DERECHA',
            'x': 'DETENER',
            'q': 'GIRO IZQUIERDA',
            'e': 'GIRO DERECHA'
        }
        
        if msg_str in command_map:
            print(f"🚗 EJECUTANDO: {command_map[msg_str]}")
            robot.simple_teleop(msg_str)
            print("✅ COMANDO EJECUTADO CORRECTAMENTE")
        else:
            print(f"❌ COMANDO DESCONOCIDO: '{msg_str}'")
            
        led.toggle()
        
    except Exception as e:
        print(f"💥 ERROR EN CALLBACK: {e}")
        
# También verifica la conexión MQTT
def check_mqtt_connection():
    try:
        # Intentar publicar un mensaje de prueba
        comm.publish("car/debug", "PICO_CONECTADA")
        print("✅ MQTT: Cliente conectado y publicando")
        return True
    except Exception as e:
        print(f"❌ MQTT ERROR: {e}")
        return False

def msgCallbackDict(msg):
    """Función para controlar movimiento y velocidad de robot"""
    
    try:
        data = ujson.loads(msg)
        cmd = data["cmd"]
        speed = data["speed"]
        print(f"Comando recibido: {cmd}, velocidad: {speed}", end="\r")
        robot.simple_teleop(cmd, int(speed))
    except Exception as e:
        print("Error en callback:", e)

# En main_async, verifica la conexión al inicio
async def main_async():
    """Función principal asíncrona"""
    # Crear tareas concurrentes
    tasks = [
        uasyncio.create_task(publisher_task()),
        uasyncio.create_task(subscription_task())
    ]
    
    await uasyncio.gather(*tasks)

# ====================================================
# ================= ENTRY POINT ======================
# ====================================================
if __name__ == "__main__":
    try:
        uasyncio.run(main_async())
    except KeyboardInterrupt:
        print("Programa terminado")
    finally:
        robot.stop()
        
def print_connection_status():
    print("=" * 50)
    print("🤖 ROBOT INICIALIZADO Y LISTO")
    print("📡 Esperando conexión de laptop...")
    print("⏳ El robot enviará 'LAPTOP_CONECTADA' al primer comando")
    print("=" * 50)

print_connection_status()