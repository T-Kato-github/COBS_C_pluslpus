#include "display_array.hpp"
#include <iostream>
#include <stdint.h>
void display_array(uint8_t const* arr,int len)
{
	int *_data = new int[len]();
	for(int i=0;i<len;++i) _data[i] = arr[i];
	for(int i=0;i<len;++i)
	{
		std::cout<<_data[i]<<" ";
	}
	std::cout<<std::endl;
}
void display_array(char const* arr,int len)
{
	int *_data = new int[len]();
	for(int i=0;i<len;++i) _data[i] = arr[i];
	for(int i=0;i<len;++i)
	{
		std::cout<<_data[i]<<" ";
	}
	std::cout<<std::endl;
	delete[] _data;
}
void display_array(int16_t const* arr,int len)
{
	int *_data = new int[len]();
	for(int i=0;i<len;++i) _data[i] = arr[i];
	for(int i=0;i<len;++i)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}
void display_array(int const* arr,int len)
{
	for(int i=0;i<len;++i)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}
void display_array(float const* arr,int len)
{
	for(int i=0;i<len;++i)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}