#include "COBS.hpp"
#include <stdint.h>
#include <cmath>
#include <iostream>

template <class T>
COBS<T>::COBS(int data_size,int point_digit)
{
    this->point_digit = point_digit;
    this->data_size = data_size;
}
template <class T>
void COBS<T>::encode(float const* data,int data_length,uint8_t *encoded_data)
{
    int cobs_data_length = this->data_size*data_length+2;
    uint8_t *cobs_data = new uint8_t[cobs_data_length]();
    T *int_data = new T[data_length]();
    int i,j,index;
    float inflation_rate = std::pow(10.0,this->point_digit);
    //convert float data to int data.
    for(i=0;i<data_length;++i) int_data[i] = data[i]*inflation_rate;
    //Split a int16_t datum into two uint8_t data.
    for(i=0;i<data_length;++i){
        for(j=0;j<this->data_size;++j)cobs_data[this->data_size*i+j+1] = int_data[i]>>8*j;
    }
    //count zero position.
    j=1;
    index=0;
    for(i=1;i<cobs_data_length;++i){
        if(cobs_data[i]==0){
            cobs_data[index]=j;
            index = i;
            j=0;
        }
        ++j;
    }
    //deep_copy cobs_data to encoded_data
    for(i=0;i<cobs_data_length;++i) encoded_data[i] = cobs_data[i];
    //memory allocation
    delete[] cobs_data;
    delete[] int_data;
}
template <class T>
void COBS<T>::decode(uint8_t const* data,int data_length,float *decoded_data)
{
    int zero_position;
    int data_num = int((data_length-2)/this->data_size);
    uint8_t *_data = new uint8_t[data_length]();
    T *_decoded_data = new T[data_num]();
    int i,j;
    float inflated_rate = std::pow(10.0,-this->point_digit);
    //deep_copy data to _data
    for(i=0;i<data_length;++i) _data[i] = data[i];
    //descript zero
    i =data_length-1;
    for(zero_position=0;zero_position<i;zero_position+=data[zero_position])_data[zero_position]=0;
    //Merges two uint8_t data into one int16_t datum.
    for(i=0; i < data_num;++i)
    {
        for(j=0;j<this->data_size;++j)
        {
            _decoded_data[i] = _decoded_data[i] |  (_data[this->data_size*i+j+1]<<(8*j) );
        }
    }
    //deep_copy _decoded_data to decoded_data
    for(i=0;i<data_num;++i)decoded_data[i] = _decoded_data[i]*inflated_rate;
    //memory allocation
    delete[] _data;
    delete[] _decoded_data;
}
template <class T>
int COBS<T>::get_data_size()
{
    return this->data_size;
}

template class COBS<int8_t>;
template class COBS<int16_t>;
template class COBS<int32_t>;