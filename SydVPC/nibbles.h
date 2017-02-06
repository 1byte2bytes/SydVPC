#pragma once
#include <stdint.h>

char getAL(uint16_t regist) {
	return regist & 0xFF;
}

char getAH(uint16_t regist) {
	char AX = regist & 0xFFFF;
	return regist >> 8;
}

char getLowQuartet(char byte) {
	return (byte & 0x0F) >> 4;
}

char getHighQuartet(char byte) {
	return (byte & 0x0F) << 4;
}