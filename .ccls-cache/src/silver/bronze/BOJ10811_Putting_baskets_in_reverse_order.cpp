#include<bits/stdc++.h>
using namespace std;

int N,M;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	vector<int> A(N+1);

	for(int i=1;i<=N;i++){
		A[i] = i;
	}

	while(M--){
		int l,r;
		cin >> l >> r;
		reverse(A.begin()+l,A.begin()+r+1);
	}

	for(int i=1;i<=N;i++)
		cout << A[i] << " ";
	
	return 0;
}

/*
02:37 Problem Analysis.
05:55 TC passed.
240525 06:02
*/