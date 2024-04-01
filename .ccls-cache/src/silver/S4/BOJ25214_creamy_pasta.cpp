#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<int> A(N+1);
	vector<int> DP(N+1);
	vector<int> minA(N+1);

	minA[0] = 0x3f3f3f3f;
	
	for(int i=1;i<=N;i++){
		cin >> A[i];
		minA[i] = min(A[i],minA[i-1]);
		DP[i] = max(DP[i-1],A[i] - minA[i-1]);
		cout << DP[i] << " ";
	}
	
	return 0;
}

/*
18:22 Problem Analysis.
22:01 main() Complted.
240401 22:34
*/