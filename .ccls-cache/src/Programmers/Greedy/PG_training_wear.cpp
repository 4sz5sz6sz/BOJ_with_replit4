#include<bits/stdc++.h>
using namespace std;

int solution(int N, vector<int> lost, vector<int> reserve) {
	vector<int> cnt(N+1,1);
	for(int cur:lost){
		cnt[cur]--;
	}
	for(int cur:reserve){
		cnt[cur]++;
	}

	for(int i=1;i<=N;i++){
		if(cnt[i]==0){
			if(i-1 >= 1 && cnt[i-1] >= 2){
				cnt[i-1]--;
				cnt[i]++;
			}
			else if(i+1 <= N && cnt[i+1] >= 2){
				cnt[i+1]--;
				cnt[i]++;
			}
		}
	}

	int ans=0;
	for(int i=1;i<=N;i++){
		if(cnt[i]>0) ans++;
	}
	
	return ans;
}

/*
07:44 Problem Analysis.
11:58 solution() Completed.
14:43 1-indexed 로 변경.
17:42
cnt[cur]--;
cnt[cur]++;
for(int cur:reserve){
for(int cur:lost){
변경.. 2개를 거꾸로 씀..
240423 20:12 
*/