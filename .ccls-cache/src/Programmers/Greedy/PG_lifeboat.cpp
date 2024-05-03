#define IDX_MAX 50000
#include<bits/stdc++.h>

using namespace std;

int isused[IDX_MAX];

int solution(vector<int> A, int W) {
	int N = A.size();
	sort(A.begin(),A.end());
	int ans=0;
	int r = N-1;
	for(int l=0;l<r;l++){
		if(isused[l]) continue;
		for(;l<r;r--){
			if(A[l] + A[r] <= W){
				isused[l] = isused[r] = 1;
				l++;
				ans++;
			}
		}
	}

	for(int i=0;i<N;i++){
		if(!isused[i]) ans++;
	}

	return ans;
}

/*
07:16 Problem Analysis.
17:09 TC passed.
240503 19:11
*/