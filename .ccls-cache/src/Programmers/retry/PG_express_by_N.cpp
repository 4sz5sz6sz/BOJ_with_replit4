#define INF 9
#define IDX_MAX 1000000
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int dp[IDX_MAX];

int solution(int N, int number){
	for(int i=0;i<IDX_MAX;i++)
		dp[i] = INF;

	dp[N*1]=1;
	dp[N*11]=2;
	dp[N*111]=3;
	dp[N*1111]=4;
	dp[N*11111]=5;
	dp[N*111111]=6;
	dp[10101]=8;

	queue<ll> Q; 
	Q.push(N*1);
	Q.push(N*11);
	Q.push(N*111);
	Q.push(N*1111);
	Q.push(N*11111);
	Q.push(N*111111);

	while(!Q.empty()){
		ll cur = Q.front(); Q.pop();
		for(ll i=1;i<IDX_MAX;i++){
			if(dp[i] >= INF) continue;

			for(int dir=0;dir<4;dir++){
				ll next=-1;
				if(dir==0){
					//dp[cur+i] = dp[cur] + dp[i];
					next = cur+i;
				}

				else if(dir==1){
					if(cur-i > 0){
						//dp[cur-i] = dp[cur] + dp[i];
						next = cur-i;
					}

				}

				else if(dir==2){
					//dp[cur/i] = dp[cur] + dp[i];
					next = cur/i;
				}
				
				else{
					//continue;	//For Debugging
					if(cur*i < IDX_MAX){
						//dp[cur*i] = dp[cur] + dp[i];
						next = cur*i;
					}
				}
				
				if(next <= 0) continue;
				if(dp[cur] + dp[i] > 8) continue;
				if(dp[cur] + dp[i] >= dp[next]) continue;
				Q.push(next); dp[next] = dp[cur] + dp[i];
			}
		}
	}
	int ret = dp[number];
	if(ret > 8) ret = -1;
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solution(1,32000) << "\n";
	
	
	return 0;
}

/*
10:19 Problem Analysis.
34:26 solve() Completed.
세그먼트 폴트 오류..

43:09 
if(dp[cur] + dp[i] > 8) continue;
추가하니 정상작동.

45:13 TC passed.

main()을 제일 밑에다 쓰는게 편리한 듯.
함수 명은 무조건 solution으로 고정.

55:30 int i에서 int ll로 수정.
58:57
	//continue;	//For Debugging 
	뒤늦게 주석처리..

01:16:42 gg..

브루트 포스가 아니라 dp로 풀었어야 함.

240422 
*/