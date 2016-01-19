#include "pstrf.h"
#include "fortran.h"

NAN_METHOD(dpstrf) {
	int uplo = info[0]->Uint32Value();
	int n = info[1]->Uint32Value();
	assert(info[2]->IsFloat64Array());
	void *a_data = info[2].As<v8::Float64Array>()->Buffer()->GetContents().Data();
	double *a = reinterpret_cast<double*>(a_data);
	int lda = info[3]->Uint32Value();
	assert(info[4]->IsInt32Array());
	void *piv_data = info[4].As<v8::Int32Array>()->Buffer()->GetContents().Data();
	int *piv = reinterpret_cast<int*>(piv_data);
	int rank = info[5]->Uint32Value();
	double tol = info[6]->NumberValue();
	assert(info[7]->IsFloat64Array());
	void *work_data = info[7].As<v8::Float64Array>()->Buffer()->GetContents().Data();
	double *work = reinterpret_cast<double*>(work_data);
	int i;
	FORTRAN_DOUBLE_ORDER(lda, n, a);
	IPIV_FORTRAN(lda, piv);
	dpstrf_(&uplo, &n, a, &lda, piv, &rank, &tol, work, &i);
	IPIV_C(lda, piv);
	FORTRAN_DOUBLE_ORDER(lda, n, a);
	info.GetReturnValue().Set(
		Nan::New<v8::Number>(i)
	);
}

NAN_METHOD(spstrf) {
	int uplo = info[0]->Uint32Value();
	int n = info[1]->Uint32Value();
	assert(info[2]->IsFloat32Array());
	void *a_data = info[2].As<v8::Float32Array>()->Buffer()->GetContents().Data();
	float *a = reinterpret_cast<float*>(a_data);
	int lda = info[3]->Uint32Value();
	assert(info[4]->IsInt32Array());
	void *piv_data = info[4].As<v8::Int32Array>()->Buffer()->GetContents().Data();
	int *piv = reinterpret_cast<int*>(piv_data);
	int rank = info[5]->Uint32Value();
	float tol = info[6]->NumberValue();
	assert(info[7]->IsFloat32Array());
	void *work_data = info[7].As<v8::Float32Array>()->Buffer()->GetContents().Data();
	float *work = reinterpret_cast<float*>(work_data);
	int i;
	FORTRAN_SINGLE_ORDER(lda, n, a);
	IPIV_FORTRAN(lda, piv);
	spstrf_(&uplo, &n, a, &lda, piv, &rank, &tol, work, &i);
	IPIV_C(lda, piv);
	FORTRAN_SINGLE_ORDER(lda, n, a);
	info.GetReturnValue().Set(
		Nan::New<v8::Number>(i)
	);
}
