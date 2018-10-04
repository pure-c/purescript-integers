#include <math.h>
#include <stdlib.h>
#include <purescript.h>

PURS_FFI_FUNC_3(Data_Int_fromNumberImpl, Just, Nothing, _n, {
	purs_any_num_t n = purs_any_get_num(_n);
	return ceil(n) == n
		? purs_any_app(Just, purs_any_int_new(n))
		: Nothing;
});

PURS_FFI_FUNC_1(Data_Int_toNumber, _n, {
	purs_any_int_t n = purs_any_get_int(_n);
	return purs_any_num_new((purs_any_num_t) n);
});

PURS_FFI_FUNC_4(Data_Int_fromStringAsImpl, Just, Nothing, _radix, _str, {
	purs_any_int_t radix = purs_any_get_int(_radix);
	const void * nptr = purs_any_get_string(_str);
	char * endptr = NULL;
	int out = strtol(nptr, &endptr, radix);
	if (nptr == endptr) {
		return Nothing;
	} else if (nptr && *endptr != 0) {
		return Nothing;
	} else {
		return purs_any_app(Just, purs_any_int_new(out));
	}
});

PURS_FFI_FUNC_2(Data_Int_toStringAs, _radix, _n, {
	purs_any_int_t n = purs_any_get_int(_n);
	purs_any_int_t radix = purs_any_get_int(_radix);
	switch (radix) {
	case 8:
		return purs_any_string_new("%o", n);
	case 10:
		return purs_any_string_new("%d", n);
	case 16:
		return purs_any_string_new("%x", n);
	}
	purs_assert(0, "radix out of range: %d", radix);
});

PURS_FFI_FUNC_2(Data_Int_quot, _x, _y, {
	purs_any_int_t x = purs_any_get_int(_x);
	purs_any_int_t y = purs_any_get_int(_y);
	if (y == 0) {
		return purs_any_int_new(0);
	} else {
		return purs_any_int_new(x / y);
	}
});

PURS_FFI_FUNC_2(Data_Int_rem, _x, _y, {
	purs_any_int_t x = purs_any_get_int(_x);
	purs_any_int_t y = purs_any_get_int(_y);
	if (y == 0) {
		return purs_any_NaN;
	} else {
		return purs_any_int_new(x % y);
	}
});

PURS_FFI_FUNC_2(Data_Int_pow, _x, _y, {
	purs_any_int_t x = purs_any_get_int(_x);
	purs_any_int_t y = purs_any_get_int(_y);
	return purs_any_int_new(
		(purs_any_int_t) floor(
			pow(
				(purs_any_num_t) x,
				(purs_any_num_t) y)));
});
