#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	LL X, Y;
	cin >> X >> Y;

	LL ans = 506*(2*X-Y);

	if(ans < 0 || X - Y > 0)
		cout << "-1\n";
	else
		cout << ans << "\n";
	
	return 0;
}



/*
31:47 문제 분석
우선, 음수처리 해보기.

34:11 제출
50점..
1
테스트 케이스 6에서 반례 발견.

40:17
X <= Y 라는 조건을 추가로 발견,

240308 40:20
*/