#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int W,H;
	int N,D;

	cin >> W >> H;
	cin >> N >> D;

	vector<int> lane(N+1);
	vector<int> p(N+1);

	for(int i=1;i<=N;i++){
		cin >> lane[i];
	}

	for(int i=1;i<=N;i++){
		cin >> p[i];
	}
	int k;	//도착 지점이 속한 레인.
	//find K
	for(int i=1;i<=N;i++){
		if(D < lane[i]){
			k = i;
			break;
		}
	}

	int _min = INF;

	for(int X=1;X<=N;X++){
		//ans1 : 이동거리 가로
		int ans1=0, ans2=0, ans3=0;
		ans1 = W*p[X];
	
		//ans2 : 좌측 이동 거리_세로
		ans2=0;
		for(int i=1;i<X;i++){
			ans2+=(lane[i] - lane[i-1]) * p[i];
		}
	
		//ans3 : 우측 이동 거리_세로
		//X<=K
		if(X<=k){
			for(int i=X;i<=k;i++){
				ans3+=(lane[i] - lane[i-1]) * p[i];
			}
			ans3 += (D-lane[k])*p[k];
		}
	
		//X>K
		else{
			for(int i=X-1;i>k;i--){
				ans3+=(lane[i] - lane[i-1]) * p[i];
			}
			ans3 += (lane[k]-D)*p[k];
		}
		// cout << "	k :	" << k;
		// cout << "	ans1 :	" << ans1;
		// cout << "	ans2 :	" << ans2;
		// cout << "	ans3 :	" << ans3;
		// cout << "	sum :	" << ans1 + ans2 + ans3;
		// cout << "\n";
		
		_min = min(_min,ans1+ans2+ans3);
	}

	cout << _min << "\n";
	
	return 0;
}

/*
53:50 문제 분석
01:13:27 첫 컴파일
오답..
01:26:27 ans3 값이 이상하게 계산된 사실 발견.
a <= n <a_i의 정의를 잘못 해석함.. 다시 올바르게 잡음.

ans3 += (D-lane[k-1])*p[k];
에서
ans3 += (D-lane[k])*p[k];
로 변경.

01:43:46
if(D <= lane[i]){
에서
if(D < lane[i]){
로 변경

240309 01:44:08
*/