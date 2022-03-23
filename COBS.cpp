#include "Arduino.h"
#include "COBS.hpp"
#include <stddef.h>

template void COBS::encode<int16_t>(int16_t *data,uint8_t *result_data,size_t data_len,size_t result_data_len);
template void COBS::encode<int32_t>(int32_t *data,uint8_t *result_data,size_t data_len,size_t result_data_len);
template void COBS::encode<uint16_t>(uint16_t *data,uint8_t *result_data,size_t data_len,size_t result_data_len);
template void COBS::encode<uint32_t>(uint32_t *data,uint8_t *result_data,size_t data_len,size_t result_data_len);


template void COBS::decode<int16_t>(uint8_t *data,int16_t *result_data,size_t data_len);
template void COBS::decode<int32_t>(uint8_t *data,int32_t *result_data,size_t data_len);
template void COBS::decode<uint16_t>(uint8_t *data,uint16_t *result_data,size_t data_len);
template void COBS::decode<uint32_t>(uint8_t *data,uint32_t *result_data,size_t data_len);




COBS::COBS(uint16_t data_byte){
	this->data_byte = data_byte;
}

template <typename T> void COBS::encode(T *data,uint8_t *result_data,size_t data_len,size_t result_data_len)
{
	//len(result_data) == data_len * this->data_byte + 2(COBS)
	uint16_t now_position = 0;
	uint16_t pre_zero_position = 0;
	
	for(uint16_t i = now_position;i<data_len;i++){
		for(uint16_t j = 1;j <(this->data_byte)+1;j++){
			now_position = 2*i+j;
			result_data[now_position] = data[i]>>(8*((this->data_byte)-j));
			//check zero and insert zero position into result array
			if(result_data[now_position]==0){
				result_data[pre_zero_position] = now_position-pre_zero_position;
				pre_zero_position = now_position;
			}
		}
	}		
	result_data[pre_zero_position] = result_data_len-1 - pre_zero_position;
	result_data[result_data_len-1]=0;
}

template <typename T> void COBS::decode(uint8_t *data,T *result_data,size_t result_data_len)
{
	uint16_t zero = 0;
	uint16_t zero_position = 0;
	uint16_t now_position = zero_position;

	//0の復元
	do{
		zero_position = data[zero_position]+zero_position;
		data[now_position] = 0;
		now_position = zero_position;
	}while(data[zero_position] != 0);
	//decode
	now_position = 0;
	for(uint16_t i = now_position;i<result_data_len;i++){
		for(uint16_t j = 1;j < (this->data_byte)+1;++j){
			now_position = 2*i+j;
			result_data[i] = result_data[i] | ( ( data[now_position] | zero ) << (8*((this->data_byte)-j)) );
		}
	}
}