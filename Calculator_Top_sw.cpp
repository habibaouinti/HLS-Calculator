#include <iostream>
#include "Calculator_Top.h"


void Calculator_Top_sw(
		int_5 a,
		int_5 b,

		bool hex_dec,
		uint_4 code,

		uint_4 select_digit,

		uint_16 *leds,

		uint_8 *segment_data,
		uint_4 *segment_enable
	)
{

	*leds = (code, hex_dec, (ap_uint<1>)0b0, b, a);

	//----------------------------------------------------
	int_10 result;

	if (code == 0) {
		result = a+b;
	} else if (code == 1) {
		result = a-b;
	} else if (code == 2) {
		result = a&b;
	} else if (code == 3) {
		result = a|b;
	} else if (code == 4) {
		result = ~(a&b);
	} else if (code == 5) {
		result = a^b;
	} else if (code == 6) {
		result = ~a;
	} else  {
		result = -a;
	}


	//-----------------------------------------------
	char d0, d1, d2, d3;

	int_10 r;

	if (result < 0) {
		d3 = 1;
		r = -result;
	} else {
		d3 = 0;
		r = result;
	}

	if (hex_dec == 0) {
		d0 = r-10*(r/10);
		r = r/10;
		d1 = r-10*(r/10);
		r = r/10;
		d2 = r-10*(r/10);
	} else {
		d0 = r-16*(r/16);
		r = r/16;
		d1 = r-16*(r/16);
		r = r/16;
		d2 = r-16*(r/16);
	}
	//--------------------------------------------------

	uint_8 segment_data_0 = seven_segment_numbers[d0];
	uint_8 segment_data_1 = seven_segment_numbers[d1];
	uint_8 segment_data_2 = seven_segment_numbers[d2];
	uint_8 segment_data_3;
	if (d3 == 0)
		segment_data_3 = seven_segment_off;
	else
		segment_data_3 = seven_segment_neg;



	if (select_digit == 1) {
		*segment_data = segment_data_0;
		*segment_enable = 0b1110;
	} else if (select_digit == 2) {
		*segment_data = segment_data_1;
		*segment_enable = 0b1101;
	} else if (select_digit == 4) {
		*segment_data = segment_data_2;
		*segment_enable = 0b1011;
	} else if (select_digit == 8) {
		*segment_data   = segment_data_3;
		*segment_enable = 0b0111;
	} else {
		*segment_data   = seven_segment_off;
		*segment_enable = 0b1111;
	}
}

