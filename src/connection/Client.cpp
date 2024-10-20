#include <iostream>
#include "Network.h"
#include <cstring>

int main() {
    try {
        initializeWinsock();
        SOCKET clientSocket = connectToServer("127.0.0.1", 01134);
        IO* io = new IO();

        // Getting the initial board
        char board[512];
        receiveData(clientSocket, board, sizeof(board));
        BoardMessage_t boardMessage;
        deserializeBoardMessage(board, &boardMessage);
        StaticBoard_t staticBoard = boardMessage.board;
        GameBoard_t gameBoard = staticBoard;
        std::string serializedBoard = gameBoard.serializeBoard();
        io -> printBoard(serializedBoard);

        // Sending ACK message to the server
        char buffer[512];
        ACKMessage_t ack;
        MessageHeader_t messageHeader = { 1, 1, 1 };
        ack.messageHeader = messageHeader;
        uint16_t newACK = 1;
        ack.ack = newACK;
        serializeACKMessage(buffer, &ack);
        sendData(clientSocket, buffer, sizeof(buffer));

        // The game loop
        while (true) {
            // Sending a move if requested
            memset(buffer, 0, sizeof(buffer));
            MessageHeader_t moveRequested;
            receiveData(clientSocket, buffer, sizeof(buffer));
            deserializeMessageHeader(buffer, &moveRequested);
            if (moveRequested.magicWord == 1) {
                Move_t playerMove = io->getMove();
                memset(buffer, 0, sizeof(buffer));
                MoveMessage_t moveMessage;
                moveMessage.messageHeader = messageHeader;
                moveMessage.move = playerMove;
                serializeMoveMessage(buffer, &moveMessage);
                sendData(clientSocket, buffer, sizeof(buffer));
            }

            // Receiving the updated board
            memset(board, 0, sizeof(board));
            receiveData(clientSocket, board, sizeof(board));
            deserializeBoardMessage(board, &boardMessage);
            if (boardMessage.messageHeader.magicWord == 0) {
                std::cout << "GAME OVER" << std::endl;
                break;
            }
            staticBoard = boardMessage.board;
            gameBoard = staticBoard;
            serializedBoard = gameBoard.serializeBoard();
            std::cout << std::endl;
            io->printBoard(serializedBoard);

            // Sending ACK
            memset(buffer, 0, sizeof(buffer));
            serializeACKMessage(buffer, &ack);
            sendData(clientSocket, buffer, sizeof(buffer));
        }

        // closing sockets
        closesocket(clientSocket);
        WSACleanup();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
