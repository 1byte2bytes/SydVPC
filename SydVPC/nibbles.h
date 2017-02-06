#pragma once

char getLowQuartet(char byte) {
	return (byte & 0x0F) >> 4;
}

char getHighQuartet(char byte) {
	return (byte & 0x0F) << 4;
}