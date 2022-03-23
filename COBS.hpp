#pragma once
#include "Arduino.h"
#include <stddef.h>

class COBS{
	private:
		int end_flag = 0;
		int cobs_byte = 2;
		uint16_t data_byte;
	public:
		COBS(uint16_t data_byte);
		template <typename T> void encode(T *data,uint8_t *result_data,size_t data_len,size_t result_data_len);
		template <typename T> void decode(uint8_t *data,T *result_data,size_t data_len);
};