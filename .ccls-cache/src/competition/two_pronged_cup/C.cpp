#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
LL POW(LL a, LL b){
	LL ret=1;
	while(b--){
		ret*=a;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	
	LL ans=1;

	for(int i=N/2+1;i<=N;i++){
		ans*=i;
	}

	ans/=POW(2,N/2);

	cout << ans << "\n";
	
	return 0;
}

/*
08:14 문제 분석
22:40 테스트 케이스 통과
240303 22:45
*/