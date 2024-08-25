#define INF 0x3f3f3f3f
#define IDX_MAX 16
#include <bits/stdc++.h>
using namespace std;

int W[IDX_MAX][IDX_MAX];
int DP[IDX_MAX][(1<<16)-1];
int N;

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
		if(visit & (1<<i)) continue;
		int tmp = TSP(i,visit | (1<<i));
		DP[cur][visit] = min(DP[cur][visit], tmp + W[cur][i]);
	}
	return DP[cur][visit];
}

/*
03:08 main() Completed.
10:31 TSP() Completed.
TC passed.
240825 10:36
*/