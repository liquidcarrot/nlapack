#include "routines.h"

void dtrtrs(const v8::FunctionCallbackInfo<v8::Value>& info) {
	char uplo = info[0]->Uint32Value();
	char trans = info[1]->Uint32Value();
	char diag = info[2]->Uint32Value();
	lapack_int n = info[3]->Uint32Value();
	lapack_int nrhs = info[4]->Uint32Value();
	double *a = reinterpret_cast<double*>(GET_CONTENTS(info[5].As<v8::Float64Array>()));
	lapack_int lda = info[6]->Uint32Value();
	double *b = reinterpret_cast<double*>(GET_CONTENTS(info[7].As<v8::Float64Array>()));
	lapack_int ldb = info[8]->Uint32Value();

	lapack_int i = LAPACKE_dtrtrs(LAPACK_ROW_MAJOR, uplo, trans, diag, n, nrhs, a, lda, b, ldb);

	info.GetReturnValue().Set(
		v8::Number::New(info.GetIsolate(), i)
	);
}

void strtrs(const v8::FunctionCallbackInfo<v8::Value>& info) {
	char uplo = info[0]->Uint32Value();
	char trans = info[1]->Uint32Value();
	char diag = info[2]->Uint32Value();
	lapack_int n = info[3]->Uint32Value();
	lapack_int nrhs = info[4]->Uint32Value();
	float *a = reinterpret_cast<float*>(GET_CONTENTS(info[5].As<v8::Float32Array>()));
	lapack_int lda = info[6]->Uint32Value();
	float *b = reinterpret_cast<float*>(GET_CONTENTS(info[7].As<v8::Float32Array>()));
	lapack_int ldb = info[8]->Uint32Value();

	lapack_int i = LAPACKE_strtrs(LAPACK_ROW_MAJOR, uplo, trans, diag, n, nrhs, a, lda, b, ldb);

	info.GetReturnValue().Set(
		v8::Number::New(info.GetIsolate(), i)
	);
}
