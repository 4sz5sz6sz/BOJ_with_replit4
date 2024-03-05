#define MOD 1000000007ll
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
vector<LL> arr;

LL POW(LL a, LL b, LL MMM);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	LL ans=0;
	int N;
	cin >> N;

	arr.resize(N);
	for(int i=0;i<N;i++)
		cin >> arr[i];

	sort(arr.begin(),arr.end());

	//cout << "POW : 	" << POW(2,5,999) << "\n";
	
	for(int i=0;i<N;i++)
		ans += (arr[i]*(POW(2,i,MOD)-1))%MOD;

	
	for(int i=0;i<N;i++)
		ans = (ans+MOD*MOD-(arr[i]*((POW(2,N-1-i,MOD))-1)))%MOD;
	
	cout << ans%MOD << "\n";
	
	return 0;
}

LL POW(LL a, LL b, LL MMM){
	LL ret=1;
	for(;b;b>>=1,a=(a*a)%MMM)
		if(b&1)
			ret=(ret*a)%MMM;
	return ret;
}

/*
17:35 문제 분석
20:29 작성 완료.
테스트 케이스 오답, 사잇값 갯수 고려 안해서 오답나옴.
35:05 사잇값 고려해서 식 다시 작성함.
틀렸습니다...
2^100000 을 표현하는 법?
38:13 POW() 함수 작성해야할 듯.
56:53 POW() 함수 구현 완료.
	ans = (ans+(arr[i]*((1<<i)-1)))%MOD;
	삭제하기.

58:10 테스트 케이스 통과.

과도한 MOD 때문인가?

01:06:21
MOD 조금 줄이고, 마지막에 MOD 하도록 변경.

5% 틀렸습니다..

음수가 나올 수도 있나? 빼는 과정에서 음수가 나올 수 있으므로, 보정값 넣어주기.

01:10:17 보정값 넣음.

240305 01:10:24
*/