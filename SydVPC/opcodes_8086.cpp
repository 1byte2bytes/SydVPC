#include "opcodes_8086.h"
#include "nibbles.h"
#include "registers.h"

#include <stdint.h>

char getFirstDigit(uint32_t digit) {
	while (digit >= 10)
	{
		digit = digit / 10;
	}
	return digit;
}

int processOpcode(uint32_t regist) {
	char opcode = getFirstDigit(regist);
	AL = getAL(EAX);
	AH = getAH(EAX);

	if (opcode == OPCODE_AAA) {
		char AL_lownibble = getLowQuartet(AL);

		if ((AL_lownibble > 9) || (AF = 1)) {
			AL = AL + 6;
			AH = AH + 1;
			AF = 1;
			CF = 1;
		}
		else {
			AF = 0;
			CF = 0;
		}
		AH = getLowQuartet(AH);
	}
	else if (opcode == OPCODE_AAD) {
		AL = (AH * 10) + AL;
		AH = 0;
	}
}