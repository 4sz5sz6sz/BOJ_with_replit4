#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<vector<int>> A;
	int N = answers.size();
	vector<int> ret;
	A.push_back({1,2,3,4,5});
	A.push_back({2,1,2,3,2,4,2,5});
	A.push_back({3,3,1,1,2,2,4,4,5,5});

	int _max = 0;
	
	for(int idx=0;idx<A.size();idx++){
		int MMM = A[idx].size();
		int cnt=0;
		for(int i=0;i<N;i++){
			if(A[idx][i%MMM] == answers[i]) cnt++;
		}
		if(cnt > _max){
			_max = cnt;
			ret.clear();
			ret.push_back(idx+1);
		}
		else if(cnt >= _max){
			ret.push_back(idx+1);
		}
	}
	
	return ret;
}

/*
04:29 Problem Analysis.
09:24 solution() Completed.
11:04 TC passed.
240423 11:12
*/