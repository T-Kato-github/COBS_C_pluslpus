/**
 * @file COBS.hpp
 * @author Tatsuma Kato
 * @brief Class for encoding or decoding based on COBS. 
 * @version 0.1
 * @date 2022-08-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <stddef.h>
#include <stdint.h>
/**
 * @brief 
 * Class for encoding or decoding based on COBS.
 */
class COBS{
    private:
        int point_digit;
        int data_size;
    public:
        /**
         * @brief Construct a new COBS object
         * 
         * @param data_size Number of bytes used per data. The larger the number of bytes, the more digits per data that can be expressed.
         * @param point_digit Variable to limit the number of decimal places.
         */
        COBS(int data_size,int point_digit);
        /**
         * @brief 
         * Encode numerical data based on COBS.
         * @param data Data array to be encoded.
         * @param data_length Number of elements in the data array to be encoded.
         * @param encoded_data Array for encoding results.
         */
        void encode(float const* data,int data_length,uint8_t *encoded_data);
        /**
         * @brief 
         * Decode numerical data based on COBS.
         * @param data Data array to be decoded. 
         * @param data_length Number of elements in the data array to be decoded. 
         * @param decoded_data Array for decoding results. 
         */
        void decode(uint8_t const* data,int data_length,float *decoded_data);
};
    