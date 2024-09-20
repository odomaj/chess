#include <iostream>
#include "Network.h"

int main() {
    try {
        initializeWinsock();
        SOCKET serverSocket = createServerSocket(01134);
        SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);

        char buffer[256];
        receiveData(clientSocket, buffer, sizeof(buffer));
        std::cout << "Received from client: " << buffer << std::endl;

        const char* reply = "Hello, client!";
        sendData(clientSocket, reply, strlen(reply) + 1);

        closesocket(clientSocket);
        closesocket(serverSocket);
        WSACleanup();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
