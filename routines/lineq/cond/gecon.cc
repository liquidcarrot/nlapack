#include "routines.h"

void dgecon(const v8::FunctionCallbackInfo<v8::Value>& info) {
	char norm = info[0]->Uint32Value();
	lapack_int n = info[1]->Uint32Value();
	double *a = reinterpret_cast<double*>(GET_CONTENTS(info[2].As<v8::Float64Array>()));
	lapack_int lda = info[3]->Uint32Value();
	double anorm = info[4]->NumberValue();
	double *rcond = reinterpret_cast<double*>(GET_CONTENTS(info[5].As<v8::Float64Array>()));

	lapack_int i = LAPACKE_dgecon(LAPACK_ROW_MAJOR, norm, n, a, lda, anorm, rcond);

	info.GetReturnValue().Set(
		v8::Number::New(info.GetIsolate(), i)
	);
}

void sgecon(const v8::FunctionCallbackInfo<v8::Value>& info) {
	char norm = info[0]->Uint32Value();
	lapack_int n = info[1]->Uint32Value();
	float *a = reinterpret_cast<float*>(GET_CONTENTS(info[2].As<v8::Float64Array>()));
	lapack_int lda = info[3]->Uint32Value();
	float anorm = info[4]->NumberValue();
	float *rcond = reinterpret_cast<float*>(GET_CONTENTS(info[5].As<v8::Float64Array>()));

	lapack_int i = LAPACKE_sgecon(LAPACK_ROW_MAJOR, norm, n, a, lda, anorm, rcond);

	info.GetReturnValue().Set(
		v8::Number::New(info.GetIsolate(), i)
	);
}
