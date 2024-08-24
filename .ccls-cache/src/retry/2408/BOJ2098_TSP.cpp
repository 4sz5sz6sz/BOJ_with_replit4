#define INF 0x3f3f3f3f
#define IDX_MAX 16
#include<bits/stdc++.h>
using namespace std;

int N;
int W[IDX_MAX][IDX_MAX];
int DP[IDX_MAX][1<<IDX_MAX];

int TSP(int cur, int visit);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> W[i][j];
		}
	}

	cout << TSP(0,1) << "\n";
	
	return 0;
}

int TSP(int cur, int visit){
	if(visit == (1<<N)-1){
		if(!W[cur][0]) return INF;
		return W[cur][0];
	}
	if(DP[cur][visit]) return DP[cur][visit];

	DP[cur][visit] = INF;
	for(int i=0;i<N;i++){
		if(!W[cur][i]) continue;
		//if(DP[cur][visit | (1 << i)]) continue; //오답
		int tmp = TSP(i, visit | (1 << i));
		// cout << "	cur : " << cur;
		// cout << "	visit : " << visit;
		// cout << "	tmp : " << tmp;
		//cout << "	tmp : " << tmp;
		// cout << "\n";
		DP[cur][visit] = min(DP[cur][visit], tmp + W[cur][i]);
	}
	return DP[cur][visit];
}

/*
08:03 main() Completed, TSP() Completed.
11:43 INF 출력..
14:11
	if(visit == (1<<IDX_MAX)-1){
	for(int i=0;i<IDX_MAX;i++){
	를
	for(int i=0;i<N;i++){
	로 수정.
TC passed.
18:07 Wa..
//if(DP[cur][visit | (1 << i)]) continue; //오답
이 줄이 오답임.
정답 제출은 하지 않고 넘어가기.

240824 fail..
*/