
#include "Calculator_Top.h"

int_10 ops(
		int_5 a,
		int_5 b,

		uint_4 code) {


	int_10 result;



	switch (code) {

	case 0:
		result = a + b;
		break;
	case 1:
		result = a - b;
		break;
	case 2:
		result = a & b;
		break;
	case 3:
		result = a | b;
		break;
	case 4:
		result = ~(a & b);
		break;
	case 5:
		result = a ^ b;
		break;
	case 6:
		result = ~a;
		break;
	case 7:
		result = -a;
		break;
	default:
		result = a+b;
		break;
	}

	return result;
}
