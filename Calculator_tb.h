#ifndef __CALCULATOR_TB_H__
#define __CALCULATOR_TB_H__



#include "Calculator_Top.h"

void Calculator_Top(
		int_5 a,
		int_5 b,

		bool hex_dec,
		uint_4 code,

		uint_4 select_digit,

		uint_16 *leds,

		uint_8 *segment_data,
		uint_4 *segment_enable
	);


void Calculator_Top_sw(
		int_5 a,
		int_5 b,

		bool hex_dec,
		uint_4 code,

		uint_4 select_digit,

		uint_16 *leds,

		uint_8 *segment_data,
		uint_4 *segment_enable
	);

#endif //__CALCULATOR_TB_H__
