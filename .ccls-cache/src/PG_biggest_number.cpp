#include<bits/stdc++.h>
using namespace std;

int N;
vector<string> A;
bool cmp(const string &a, const string &b);

string solution(vector<int> numbers) {
	string answer = "";
	N = numbers.size();
	for(int i=0;i<N;i++){
		A.push_back(to_string(numbers[i]));
	}

	sort(A.begin(),A.end(),cmp);

	for(int i=0;i<N;i++){
		for(int j=0;j<A.size();j++)
			answer.push_back(A[i][j]);
	}

	return answer;
}

bool cmp(const string &a, const string &b){
	return 
}

/*
09:22 Problem Analysis.
20:15 정렬 함수 만들다가. 
자정 STOP..
*/