#pragma once
#include <string>
#include <mqtt/async_client.h>

class AutoRobot {
private:
    mqtt::async_client* client;
    std::string brokerAddress;
    std::string topicCmd;

public:
    AutoRobot(const std::string& address, const std::string& topic);
    ~AutoRobot();

    bool connect();
    void disconnect();

    void avanzar();
    void retroceder();
    void izquierda();
    void derecha();
    void giroDerecha();
    void giroIzquierda();
    void parar();

private:
    void publish(const std::string& payload);
};