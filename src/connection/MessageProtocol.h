#include "../common/Util.h"

#include <cstdint>
#include <cstring>

#ifndef MESSAGEPROTOCOL_H_
#define MESSAGEPROTOCOL_H_

typedef struct
{
	uint16_t magicWord;
	uint16_t id;
	uint16_t length;
} MessageHeader_t;

typedef struct
{
	MessageHeader_t messageHeader;
	StaticBoard_t board;
} BoardMessage_t;

typedef struct
{
	MessageHeader_t messageHeader;
	Move_t move;
} MoveMessage_t;

typedef struct
{
	MessageHeader_t messageHeader;
	uint16_t ack;
} ACKMessage_t;

void serializeMessageHeader(char* buffer, MessageHeader_t* header);
void serializeBoardMessage(char* buffer, BoardMessage_t* board);
void serializeMoveMessage(char* buffer, MoveMessage_t* moveMessage);
void serializeACKMessage(char* buffer, ACKMessage_t* ackMessage);
void deserializeMessageHeader(char* buffer, MessageHeader_t* header);
void deserializeBoardMessage(char* buffer, BoardMessage_t* board);
void deserializeMoveMessage(char* buffer, MoveMessage_t* moveMessage);
void deserializeACKMessage(char* buffer, ACKMessage_t* ackMessage);
#endif