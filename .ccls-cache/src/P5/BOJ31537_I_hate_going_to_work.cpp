//#define IDX_MAX 1000005
#define MOD 1000000007
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<LL> A;
vector<LL> B;
vector<LL> fact;

LL POW(LL a, LL b, LL MMM);
LL INV(LL b, LL MMM);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	LL N,M;
	cin >> N >> M;
	A.resize(N+1);
	B.resize(N+1);
	fact.resize(M+1,1);

	LL sumB=0;
	for(int i=1;i<=N;i++){
		cin >> A[i];
		B[i] = M - A[i];
		sumB+=B[i];
	}

	for(int i=2;i<=M;i++){
		fact[i] = (fact[i-1]*i)%MOD;
	}

	if(sumB>M){
		cout << "0\n";
		return 0;
	}

	LL nominator = fact[M];
	LL denominator=1;
	for(int i=1;i<=N;i++){
		denominator = (denominator * fact[B[i]])%MOD;
	}
	denominator = (denominator * fact[M-sumB])%MOD;

	cout << (nominator * INV(denominator, MOD))%MOD << "\n";
	
	return 0;
}

LL POW(LL a, LL b, LL MMM){
	LL ret = 1;
	for(;b;b>>=1, a=(a*a)%MMM){
		if(b & 1)
			ret = (ret * a)%MMM;
	}
	return ret;
}

LL INV(LL b, LL MMM){
	return POW(b,MMM-2,MMM);
}


/*
25:10 Problem Analysis
35:45 main() Completed
38:04 POW(), INV() Completed

39:27 테스트 케이스 오답..
	for(int i=2;i<=N;i++){
	에서
	for(int i=2;i<=M;i++){
	로 수정.

41:39 TC passed.

42:51 런타임 에러..
47:03
	fact[M-sumB]
	런타임 에러 날만한 곳이 여기밖에 없음.
	M과 sumB를 LL로 변경.
	
240313 47:58
*/