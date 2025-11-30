#include "pch.h"
#include "Controlador.h"
#include <mqtt/async_client.h>
#include <iostream>

AutoRobot::AutoRobot(const std::string& address, const std::string& topic) : brokerAddress(address), topicCmd(topic), client(nullptr) {

}

AutoRobot::~AutoRobot() {
    disconnect();
    if (client != nullptr) {
        delete client;
        client = nullptr;
    }
}

bool AutoRobot::connect() {
    try {
        if (client == nullptr) {
            client = new mqtt::async_client(brokerAddress, "");
            // Generar client ID único
            std::string clientId = "CarController_" + std::to_string(time(nullptr));
            client = new mqtt::async_client(brokerAddress, clientId);
        }

        mqtt::connect_options opts;
        opts.set_clean_session(true);
        opts.set_keep_alive_interval(20);
        opts.set_automatic_reconnect(true);

        // Timeout de conexión
        auto tok = client->connect(opts);

        // Esperar con timeout
        if (tok->wait_for(std::chrono::seconds(10))) {
            std::cout << "Conectado al broker MQTT: " << brokerAddress << std::endl;
            return true;
        }
        else {
            std::cerr << "Timeout en la conexión MQTT" << std::endl;
            return false;
        }
    }
    catch (const mqtt::exception& ex) {
        std::cerr << "Error conectando a " << brokerAddress << ": " << ex.what() << std::endl;
        return false;
    }
}
void AutoRobot::disconnect() {
    try {
        if (client != nullptr && client->is_connected())
            client->disconnect()->wait();
    }
    catch (...) {}
}

void AutoRobot::publish(const std::string& payload) {
    if (client == nullptr || !client->is_connected()) {
        std::cerr << "Cliente no conectado, no se puede publicar: " << payload << std::endl;
        return;
    }

    try {
        auto msg = mqtt::make_message(topicCmd, payload);
        msg->set_qos(0); // Cambiar a QoS 0 para mejor rendimiento
        client->publish(msg)->wait_for(std::chrono::seconds(2));
        std::cout << "Mensaje publicado: " << payload << std::endl;
    }
    catch (const mqtt::exception& ex) {
        std::cerr << "Error publicando mensaje: " << ex.what() << std::endl;
    }
}

void AutoRobot::avanzar() {
    publish("w");
}
void AutoRobot::retroceder() {
    publish("s");
}
void AutoRobot::izquierda() {
    publish("a");
}
void AutoRobot::derecha() {
    publish("d");
}
void AutoRobot::giroDerecha() {
    publish("e");
}
void AutoRobot::giroIzquierda() {
    publish("q");
}
void AutoRobot::parar() {
    publish("x");
}