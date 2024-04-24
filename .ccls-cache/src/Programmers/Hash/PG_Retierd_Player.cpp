#include<bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	unordered_map<string,int> m;
	for(string cur: participant){
		m[cur]++;
	}
	for(string cur: completion){
		m[cur]--;
	}

	string answer;
	for(string cur: participant){
		if(m[cur] == 1) answer = cur;
	}
	return answer;
}

/*
02:00 Problem Analysis.
03:53 solution() Completed.
240423 04:28
*/