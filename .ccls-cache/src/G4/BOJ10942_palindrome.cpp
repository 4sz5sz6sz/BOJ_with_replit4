#define IDX_MAX 2001
#include<bits/stdc++.h>
using namespace std;

int N,M;
int A[IDX_MAX];
bool DP[IDX_MAX][IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];

	for(int i=0;i<N;i++){
		DP[i][i] = true;
		if(i+1>=N) continue;
		if(A[i] == A[i+1])
			DP[i][i+1] = true;
	}

	for(int d=2;d<N;d++){
		for(int i=0;i<N;i++){
			if(i+d>=N) break;
			int j = i+d;
			if(DP[i+1][j-1] && A[i] == A[j])
				DP[i][j] = true;
		}
	}
	
	cin >> M;
	while(M--){
		int S,E;
		cin >> S >> E;
		S--; E--;
		cout << DP[S][E] << "\n";
	}
	
	return 0;
}

/*
07:32 Problem Analysis.
13:13 main() Completed.
14:27 TC passed.
240503 14:30
*/