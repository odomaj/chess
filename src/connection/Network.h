#ifndef NETWORK_H
#define NETWORK_H

#include <winsock2.h>
#include <WS2tcpip.h>
#include <stdexcept>
#include <iostream>
#include "../gameboard/GameBoard.h"
#include "../io/IO.h"
#pragma comment(lib, "ws2_32.lib")

// Initialize Winsock
void initializeWinsock();

// Create a listening server socket
SOCKET createServerSocket(int port);

// Connect to a server socket
SOCKET connectToServer(const char* serverAddress, int port);

// Send and receive data
void sendData(SOCKET socket, const char* data, int length);
void receiveData(SOCKET socket, char* buffer, int length);

#endif // NETWORK_H