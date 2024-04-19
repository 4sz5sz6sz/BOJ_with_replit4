#define IDX_MAX 51
#include<bits/stdc++.h>
using namespace std;

int A[IDX_MAX][2];
int ans[IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for(int i=0;i<N;i++){
		cin >> A[i][0] >> A[i][1];
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==j) continue;
			if(A[i][0] < A[j][0] && A[i][1] < A[j][1])
				ans[i]++;
		}
	}

	for(int i=0;i<N;i++)
		cout << ans[i]+1 << " ";
	
	
	return 0;
}


/*
04:50 Problem Analysis.
07:02 main() Completed.
07:23 TC passed.
240418 07:28
*/