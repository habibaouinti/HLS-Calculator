
#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <ap_int.h>


typedef ap_int<5>    int_5;
typedef ap_uint<4>   uint_4;

typedef ap_int<10>   int_10;
typedef ap_uint<10>  uint_10;

typedef ap_uint<8>   uint_8;
typedef ap_uint<16>  uint_16;


const unsigned int seven_segment_neg = 0b10111111;
const unsigned int seven_segment_off = 0b11111111;

const unsigned int seven_segment_numbers[16] = {
		0b11000000,  // 00
		0b11111001,  // 01
		0b10100100,  // 02
		0b10110000,  // 03
		0b10011001,  // 04
		0b10010010,  // 05
		0b10000010,  // 06
		0b11111000,  // 07
		0b10000000,  // 08
		0b10010000,  // 09
		0b10001000,  // 10  or A
		0b10000011,  // 11  or B
		0b11000110,  // 12  or C
		0b10100001,  // 13  or D
		0b10000110,  // 14  or E
		0b10001110,  // 15  or F
		};

int_10 ops(
		int_5 a,
		int_5 b,


		uint_4 code);


void extract_results(
		bool  hex_dec,
		int_10 result,
		short int &d0,
		short int &d1,
		short int &d2,
		short int &d3);


void display_results(

		short int d0,
		short int d1,
		short int d2,
		short int d3,
		uint_4     select_digit,
		uint_8    *segment_data,
		uint_4    *segment_enable);

#endif //__SIMPLE_CALCULATOR_H__
