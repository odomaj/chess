#include <iostream>
#include "Network.h"

int main() {
    try {
        initializeWinsock();
        SOCKET clientSocket = connectToServer("127.0.0.1", 01134);

        // Send/Receive data
        const char* message = "Hello, server!";
        sendData(clientSocket, message, strlen(message) + 1);

        char response[256];
        receiveData(clientSocket, response, sizeof(response));
        std::cout << "Received from server: " << response << std::endl;

        closesocket(clientSocket);
        WSACleanup();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
