#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL GCD(LL A, LL B);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	LL A,B;

	cin >> A >> B;

	if(A<B) swap(A,B);

	int len = GCD(A,B);
	
	for(int i=0;i<len;i++){
		cout << "1";
	}
	
	return 0;
	
}

LL GCD(LL A, LL B){
	return B?GCD(B,A%B):A;
}



/*
03:37 문제 분석
04:38 main() 작성 완료.
12:11 문제 잘못 읽은거 바로잡음.
13:48 테스트 케이스 통과

240306 13:52
*/