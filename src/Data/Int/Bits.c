#include <purescript.h>

PURS_FFI_FUNC_2(Data_Int_Bits_and, n1, n2) {
	return purs_any_int(purs_any_force_int(n1) & purs_any_force_int(n2));
}

PURS_FFI_FUNC_2(Data_Int_Bits_or, n1, n2) {
	return purs_any_int(purs_any_force_int(n1) | purs_any_force_int(n2));
}

PURS_FFI_FUNC_2(Data_Int_Bits_xor, n1, n2) {
	return purs_any_int(purs_any_force_int(n1) ^ purs_any_force_int(n2));
}

PURS_FFI_FUNC_2(Data_Int_Bits_shl, n1, n2) {
	return purs_any_int(purs_any_force_int(n1) << purs_any_force_int(n2));
}

PURS_FFI_FUNC_2(Data_Int_Bits_shr, n1, n2) {
	return purs_any_int(purs_any_force_int(n1) >> purs_any_force_int(n2));
}

PURS_FFI_FUNC_2(Data_Int_Bits_zshr, n1, n2) {
	// XXX is this right?
	return purs_any_int((unsigned) purs_any_force_int(n1) >> purs_any_force_int(n2));
}

PURS_FFI_FUNC_1(Data_Int_Bits_complement, n) {
	return purs_any_int(~purs_any_force_int(n));
}
