#include <iostream>
#include "Network.h"
#include <cstring>

int main() {
    try {
        initializeWinsock();
        SOCKET clientSocket = connectToServer("127.0.0.1", 01134);
        IO* io = new IO();

        // testing sending a message header to server
        char buffer[256];
        MessageHeader_t messageHeader = { 1, 1, 1 };
        serializeMessageHeader(buffer, &messageHeader);
        sendData(clientSocket, buffer, sizeof(buffer));

        // getting the initial board
        char board[256];
        receiveData(clientSocket, board, sizeof(board));
        BoardMessage_t boardMessage;
        deserializeBoardMessage(board, &boardMessage);
        StaticBoard_t staticBoard = boardMessage.board;
        GameBoard_t gameBoard = staticBoard;
        std::string serializedBoard = gameBoard.serializeBoard();
        io -> printBoard(serializedBoard);

        // testing sending ack message to server
        char ackBuffer[256];
        ACKMessage_t ack;
        ack.messageHeader = messageHeader;
        uint16_t newACK = 5;
        ack.ack = newACK;
        serializeACKMessage(ackBuffer, &ack);
        sendData(clientSocket, ackBuffer, sizeof(ackBuffer));

        // testing sending move to server
        Move_t playerMove = io->getMove();
        char moveBuffer[256];
        MoveMessage_t moveMessage;
        moveMessage.messageHeader = messageHeader;
        moveMessage.move = playerMove;
        serializeMoveMessage(moveBuffer, &moveMessage);
        sendData(clientSocket, moveBuffer, sizeof(moveBuffer));

        // closing sockets
        closesocket(clientSocket);
        WSACleanup();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}