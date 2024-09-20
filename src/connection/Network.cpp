#include "Network.h"

// Initialize Winsock
void initializeWinsock() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        throw std::runtime_error("WSAStartup failed");
    }
}

// Create a server socket and bind it to a port
SOCKET createServerSocket(int port) {
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        throw std::runtime_error("Socket creation failed");
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        throw std::runtime_error("Bind failed");
    }

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        throw std::runtime_error("Listen failed");
    }

    return serverSocket;
}

// Connect to a server
SOCKET connectToServer(const char* serverAddress, int port) {
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        throw std::runtime_error("Socket creation failed");
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    // Use inet_addr for address conversion
    serverAddr.sin_addr.s_addr = inet_addr(serverAddress);
    if (serverAddr.sin_addr.s_addr == INADDR_NONE) {
        throw std::runtime_error("Invalid address");
    }

    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        throw std::runtime_error("Connect failed");
    }

    return clientSocket;
}

// Send data over a socket
void sendData(SOCKET socket, const char* data, int length) {
    if (send(socket, data, length, 0) == SOCKET_ERROR) {
        throw std::runtime_error("Send failed");
    }
}

// Receive data from a socket
void receiveData(SOCKET socket, char* buffer, int length) {
    if (recv(socket, buffer, length, 0) == SOCKET_ERROR) {
        throw std::runtime_error("Receive failed");
    }
}
