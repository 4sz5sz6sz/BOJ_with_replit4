#define MOD 1000000007ll
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL POW(LL a, LL b, LL MMM);
LL INV(LL b, LL MMM);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	//vector<LL> A(N);
	//vector<LL> B(N);

	LL ans=0;
	
	for(int i=0;i<N;i++){
		LL a,b;
		cin >> b >> a;
		ans = ans + (a*INV(b,MOD))%MOD;
	}

	cout << ans%MOD << "\n";
	
	return 0;
}

LL INV(LL b, LL MMM){
	return POW(b,MMM-2,MMM);
}

LL POW(LL a, LL b, LL MMM){
	LL ret=1;
	for(;b;b>>=1, a=(a*a)%MMM)
		if(b & 1)
			ret=(ret*a)%MMM;
	return ret;
}


/*
06:02 문제 분석
13:10 main() 작성 완료
14:54 INV() 작성 완료
18:17 POW() 작성 완료
19:28 테스트 케이스 오답..
27:45 a,b 에서 b,a로 수정.

오답..
cout << ans << "\n";
에서
cout << ans%MOD << "\n";
로 수정.

맞았습니다!!


240309 29:42
*/