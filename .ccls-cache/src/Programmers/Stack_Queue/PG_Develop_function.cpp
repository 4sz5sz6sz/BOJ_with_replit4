#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	int N = speeds.size();
	vector<int> dp(N);
	vector<int> arr(N);

	for(int i=0;i<N;i++){
		arr[i] = ceil((100.0 - progresses[i])/speeds[i]);
	}

	dp[0] = arr[0];
	for(int i=1;i<N;i++){
		dp[i] = max(arr[i], dp[i-1]);
	}

	vector<int> ret;
	int cnt=1;
	for(int i=1;i<N;i++){
		if(dp[i] == dp[i-1]) cnt++;
		else{
			ret.push_back(cnt);
			cnt=1;
		}
	}
	ret.push_back(cnt);
	
	return ret;
}

/*
09:02 Problem Analysis.
10:58 solution() Completed.
18:57 TC passed.
240423 19:02
*/