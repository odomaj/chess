#include <iostream>
#include "Network.h"
#include <cstring>

int main() {
    try {
        // Initializations
        initializeWinsock();
        SOCKET serverSocket = createServerSocket(01134);
        SOCKET playerOne = accept(serverSocket, nullptr, nullptr);
        SOCKET playerTwo = accept(serverSocket, nullptr, nullptr);
        IO* io = new IO();
        GameBoard_t* board = new GameBoard_t();

        // Creating and serializing chess board
        StaticBoard_t staticBoard = board->getBoard();
        std::string serializedBoard = board->serializeBoard();

        // Sending initial board to clients
        char buffer[512];
        BoardMessage_t boardMessage;
        boardMessage.messageHeader = { 1, 1, 1 };
        boardMessage.board = staticBoard;
        serializeBoardMessage(buffer, &boardMessage);
        sendData(playerOne, buffer, sizeof(buffer));
        sendData(playerTwo, buffer, sizeof(buffer));

        // Receiving ACK from clients
        memset(buffer, 0, sizeof(buffer));
        receiveData(playerOne, buffer, sizeof(buffer));
        ACKMessage_t ack;
        deserializeACKMessage(buffer, &ack);
        if (ack.ack != 1) {
            std::cout << "Player One ACK error" << std::endl;
            return 0;
        }
        memset(buffer, 0, sizeof(buffer));
        receiveData(playerTwo, buffer, sizeof(buffer));
        ACKMessage_t ack2;
        deserializeACKMessage(buffer, &ack2);
        if (ack2.ack != 1) {
            std::cout << "Player Two ACK error" << std::endl;
            return 0;
        }

        // The game loop
        while (true) {
            // Sending message to request a move from player one
            memset(buffer, 0, sizeof(buffer));
            MessageHeader_t requestMoveP1 = { 1, 1, 1 };
            MessageHeader_t requestMoveP2 = { 0, 0, 0 };
            serializeMessageHeader(buffer, &requestMoveP1);
            sendData(playerOne, buffer, sizeof(buffer));
            memset(buffer, 0, sizeof(buffer));
            serializeMessageHeader(buffer, &requestMoveP2);
            sendData(playerTwo, buffer, sizeof(buffer));

            // Getting move from player one and performing move
            memset(buffer, 0, sizeof(buffer));
            receiveData(playerOne, buffer, sizeof(buffer));
            MoveMessage_t moveMessage;
            deserializeMoveMessage(buffer, &moveMessage);
            if (!board->move(moveMessage.move, WHITE)) {
                // Sending board message, with header indicating game is over
                memset(buffer, 0, sizeof(buffer));
                staticBoard = board->getBoard();
                serializedBoard = board->serializeBoard();
                boardMessage.board = staticBoard;
                boardMessage.messageHeader.magicWord = 0;
                serializeBoardMessage(buffer, &boardMessage);
                sendData(playerOne, buffer, sizeof(buffer));
                sendData(playerTwo, buffer, sizeof(buffer));
                break;
            }
            
            // Sending updated board to clients
            memset(buffer, 0, sizeof(buffer));
            staticBoard = board->getBoard();
            serializedBoard = board->serializeBoard();
            boardMessage.board = staticBoard;
            serializeBoardMessage(buffer, &boardMessage);
            sendData(playerOne, buffer, sizeof(buffer));
            sendData(playerTwo, buffer, sizeof(buffer));

            // Receiving ACK from clients
            memset(buffer, 0, sizeof(buffer));
            receiveData(playerOne, buffer, sizeof(buffer));
            deserializeACKMessage(buffer, &ack);
            if (ack.ack != 1) {
                std::cout << "Player one ACK error" << std::endl;
                return 0;
            }
            memset(buffer, 0, sizeof(buffer));
            receiveData(playerTwo, buffer, sizeof(buffer));
            deserializeACKMessage(buffer, &ack2);
            if (ack2.ack != 1) {
                std::cout << "Player Two ACK error" << std::endl;
                return 0;
            }

            // Sending message to request a move from player two
            memset(buffer, 0, sizeof(buffer));
            requestMoveP1 = { 0, 0, 0 };
            requestMoveP2 = { 1, 1, 1 };
            serializeMessageHeader(buffer, &requestMoveP2);
            sendData(playerTwo, buffer, sizeof(buffer));
            memset(buffer, 0, sizeof(buffer));
            serializeMessageHeader(buffer, &requestMoveP1);
            sendData(playerOne, buffer, sizeof(buffer));

            // Getting move from player two and performing move
            memset(buffer, 0, sizeof(buffer));
            receiveData(playerTwo, buffer, sizeof(buffer));
            MoveMessage_t moveMessage2;
            deserializeMoveMessage(buffer, &moveMessage2);
            if (!board->move(moveMessage2.move, BLACK)) {
                // Sending board message, with header indicating game is over
                memset(buffer, 0, sizeof(buffer));
                staticBoard = board->getBoard();
                serializedBoard = board->serializeBoard();
                boardMessage.board = staticBoard;
                boardMessage.messageHeader.magicWord = 0;
                serializeBoardMessage(buffer, &boardMessage);
                sendData(playerOne, buffer, sizeof(buffer));
                sendData(playerTwo, buffer, sizeof(buffer));
                break;
            }

            // Sending updated board to clients
            memset(buffer, 0, sizeof(buffer));
            staticBoard = board->getBoard();
            serializedBoard = board->serializeBoard();
            boardMessage.board = staticBoard;
            serializeBoardMessage(buffer, &boardMessage);
            sendData(playerOne, buffer, sizeof(buffer));
            sendData(playerTwo, buffer, sizeof(buffer));

            // Receiving ACK from clients
            memset(buffer, 0, sizeof(buffer));
            receiveData(playerOne, buffer, sizeof(buffer));
            deserializeACKMessage(buffer, &ack);
            if (ack.ack != 1) {
                std::cout << "Player one ACK error" << std::endl;
                return 0;
            }
            memset(buffer, 0, sizeof(buffer));
            receiveData(playerTwo, buffer, sizeof(buffer));
            deserializeACKMessage(buffer, &ack2);
            if (ack2.ack != 1) {
                // error?
                std::cout << "Player Two ACK error" << std::endl;
                return 0;
            }
        }

        // Closing sockets
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


// Maybe make a function to print board in reverse since PlayerTwo should have black pieces at bottom of board


