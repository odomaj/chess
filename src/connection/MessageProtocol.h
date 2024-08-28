#include "Util.h"

#include <cstdint>

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

#endif