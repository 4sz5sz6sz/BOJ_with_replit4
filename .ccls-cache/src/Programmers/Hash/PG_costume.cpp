#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> m; // myindex[]
vector<int> A;  //1-indexed
int numOfWear;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	int N = clothes.size();
	A.push_back(0);
	for(int i=0;i<N;i++){
		if(m[clothes[i][1]] == 0){
			m[clothes[i][1]]=++numOfWear;
			A.push_back(0);
		}
		A[m[clothes[i][1]]]++;
	}

	for(int i=1;i<=numOfWear;i++){
		cout << A[i]+1;
		cout << "\n";
		answer*=A[i]+1;
	}


	answer--;
	return answer;
}

