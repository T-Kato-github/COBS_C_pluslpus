#pragma once
#include <stddef.h>
#include <stdint.h>

class COBS{
    private:
        int point_digit;
        int data_size;
    public:
        COBS(int data_size,int point_digit);
        void encode(float const* data,int data_length,uint8_t *encoded_data);
        void decode(uint8_t const* data,int data_length,float *decoded_data);
};
    