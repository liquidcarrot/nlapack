#include "routines.h"

void dpptri(const v8::FunctionCallbackInfo<v8::Value>& info) {
 	char uplo = info[0]->Uint32Value();
 	lapack_int n = info[1]->Uint32Value();
	double *ap = reinterpret_cast<double*>(GET_CONTENTS(info[2].As<v8::Float64Array>()));

	lapack_int i = LAPACKE_dpptri(LAPACK_ROW_MAJOR, uplo, n, ap);

	info.GetReturnValue().Set(
		v8::Number::New(info.GetIsolate(), i)
	);
}

void spptri(const v8::FunctionCallbackInfo<v8::Value>& info) {
	char uplo = info[0]->Uint32Value();
	lapack_int n = info[1]->Uint32Value();
	float *ap = reinterpret_cast<float*>(GET_CONTENTS(info[2].As<v8::Float32Array>()));

	lapack_int i = LAPACKE_spptri(LAPACK_ROW_MAJOR, uplo, n, ap);

	info.GetReturnValue().Set(
		v8::Number::New(info.GetIsolate(), i)
	);
}
