#define IDX_MAX 201
#include<bits/stdc++.h>
using namespace std;

int N,M;
int DP[IDX_MAX][IDX_MAX];
int W[IDX_MAX];
int V[IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for(int i=1;i<=M;i++){
		cin >> W[i] >> V[i];
	}

	for(int weight=1;weight<=N;weight++){
		for(int bag=1;bag<=M;bag++){
			if(weight-W[bag]>=0)
				DP[bag][weight] = max(DP[bag-1][weight], DP[bag-1][weight-W[bag]] + V[bag]);
			else
				DP[bag][weight] = DP[bag-1][weight];
		}
	}

	cout << DP[M][N] << "\n";
	
	return 0;
}

/*
13:33 Problem Analysis.
18:06 main() Completed.
19:54 TC passed.
240416 19:58
*/