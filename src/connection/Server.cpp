#include <iostream>
#include "Network.h"
#include <cstring>

int main() {
    try {
        // initializations
        initializeWinsock();
        SOCKET serverSocket = createServerSocket(01134);
        SOCKET playerOne = accept(serverSocket, nullptr, nullptr);
        SOCKET playerTwo = accept(serverSocket, nullptr, nullptr);
        IO* io = new IO();
        GameBoard_t* board = new GameBoard_t();

        // creating and serializing chess board
        StaticBoard_t staticBoard = board->getBoard();
        std::string serializedBoard = board->serializeBoard();
        std::vector<char> vec(serializedBoard.begin(), serializedBoard.end());
        vec.push_back('\0');
        char* serializedBoardChar = vec.data();

        // testing receiving message header from client
        char buffer[256];
        receiveData(playerOne, buffer, sizeof(buffer));
        MessageHeader_t messageHeader;
        deserializeMessageHeader(buffer, &messageHeader);
        std::cout << "Received from client: " << messageHeader.magicWord << std::endl;
        memset(buffer, 0, sizeof(buffer));
        receiveData(playerTwo, buffer, sizeof(buffer));
        MessageHeader_t messageHeader2;
        deserializeMessageHeader(buffer, &messageHeader2);
        std::cout << "Received from client: " << messageHeader2.magicWord << std::endl;

        // testing sending initial board to clients
        memset(buffer, 0, sizeof(buffer));
        BoardMessage_t boardMessage;
        boardMessage.messageHeader = { 1, 1, 1 };
        boardMessage.board = staticBoard;
        serializeBoardMessage(buffer, &boardMessage);
        sendData(playerOne, buffer, sizeof(buffer));
        sendData(playerTwo, buffer, sizeof(buffer));

        // testing receiving ack from client
        char ackBuffer[256];
        receiveData(playerOne, ackBuffer, sizeof(ackBuffer));
        ACKMessage_t ack;
        deserializeACKMessage(ackBuffer, &ack);
        std::cout << "ACK received from client: " << ack.ack << std::endl;
        memset(ackBuffer, 0, sizeof(ackBuffer));
        receiveData(playerTwo, ackBuffer, sizeof(ackBuffer));
        ACKMessage_t ack2;
        deserializeACKMessage(ackBuffer, &ack2);
        std::cout << "ACK received from client: " << ack2.ack << std::endl;

        // testing receiving move
        char moveBuffer[256];
        receiveData(playerOne, moveBuffer, sizeof(moveBuffer));
        MoveMessage_t moveMessage;
        deserializeMoveMessage(moveBuffer, &moveMessage);

        std::cout << "Move received from client: " << "(" 
            << moveMessage.move.start.x << ", " << moveMessage.move.start.y 
            << ") to (" << moveMessage.move.end.x << ", " 
            << moveMessage.move.end.y << ")" << std::endl;

        memset(moveBuffer, 0, sizeof(moveBuffer));
        receiveData(playerTwo, moveBuffer, sizeof(moveBuffer));
        MoveMessage_t moveMessage2;
        deserializeMoveMessage(moveBuffer, &moveMessage2);

        std::cout << "Move received from client: " << "(" 
            << moveMessage2.move.start.x << ", " << moveMessage2.move.start.y 
            << ") to (" << moveMessage2.move.end.x << ", " 
            << moveMessage2.move.end.y << ")" << std::endl;

        // closing sockets
        closesocket(playerOne);
        closesocket(playerTwo);
        closesocket(serverSocket);
        WSACleanup();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}