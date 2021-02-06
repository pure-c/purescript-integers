#include <math.h>
#include <stdlib.h>
#include <purescript.h>

PURS_FFI_FUNC_3(Data_Int_fromNumberImpl, Just, Nothing, _n) {
	purs_num_t n = purs_any_force_num(_n);
	return ceil(n) == n
		? purs_any_app(Just, purs_any_int(n))
		: Nothing;
}

PURS_FFI_FUNC_1(Data_Int_toNumber, _n) {
	purs_int_t n = purs_any_force_int(_n);
	return purs_any_num((purs_num_t) n);
}

PURS_FFI_FUNC_4(Data_Int_fromStringAsImpl, Just, Nothing, _radix, _str) {
	purs_int_t radix = purs_any_force_int(_radix);
	const purs_str_t *str = purs_any_force_string(_str);
	char *endptr = NULL;
	int out = strtol(str->data, &endptr, radix);
	if (str->data == endptr) {
		PURS_RC_RELEASE(str);
		return Nothing;
	} else if (str->data && *endptr != 0) {
		PURS_RC_RELEASE(str);
		return Nothing;
	}
	PURS_RC_RELEASE(str);
	return purs_any_app(Just, purs_any_int(out));
}

PURS_FFI_FUNC_2(Data_Int_toStringAs, _radix, _n) {
	purs_int_t n = purs_any_force_int(_n);
	purs_int_t radix = purs_any_force_int(_radix);
	switch (radix) {
	case 8:
		return purs_any_string(purs_str_new("%o", n));
	case 10:
		return purs_any_string(purs_str_new("%d", n));
	case 16:
		return purs_any_string(purs_str_new("%x", n));
	}
	purs_assert(0, "radix out of range: %d", radix);
}

PURS_FFI_FUNC_2(Data_Int_quot, _x, _y) {
	purs_int_t x = purs_any_force_int(_x);
	purs_int_t y = purs_any_force_int(_y);
	if (y == 0) {
		return purs_any_int(0);
	}
	return purs_any_int(x / y);
}

PURS_FFI_FUNC_2(Data_Int_rem, _x, _y) {
	purs_int_t x = purs_any_force_int(_x);
	purs_int_t y = purs_any_force_int(_y);
	if (y == 0) {
		return purs_any_NaN;
	}
	return purs_any_int(x % y);
}

PURS_FFI_FUNC_2(Data_Int_pow, _x, _y) {
	purs_int_t x = purs_any_force_int(_x);
	purs_int_t y = purs_any_force_int(_y);
	return purs_any_int(
		(purs_int_t) floor(pow((purs_num_t) x, (purs_num_t) y)));
}
