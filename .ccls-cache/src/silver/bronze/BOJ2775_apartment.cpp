#define IDX_MAX 15
#include<bits/stdc++.h>
using namespace std;

int A[IDX_MAX][IDX_MAX];
int S[IDX_MAX][IDX_MAX];

//void Init();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	S[0][1] = 1;
	for(int j=1;j<IDX_MAX;j++){
		A[0][j] = j;
		S[0][j] = S[0][j-1] + A[0][j];
	}

	for(int i=1;i<IDX_MAX;i++){
		for(int j=1;j<IDX_MAX;j++){
			A[i][j] = S[i-1][j];
			S[i][j] = S[i][j-1] + A[i][j];
		}
	}
	
	int T;
	int N,K;
	cin >> T;
	while(T--){
		cin >> K;
		cin >> N;
		//Init();
		cout << A[K][N] << "\n";
	}
	
	return 0;
}

/*
void Init(){
	
}
*/

/*
04:11 Problem Analysis.
09:06 main() Completed.
09:45 TC passed.
240418 09:48
*/