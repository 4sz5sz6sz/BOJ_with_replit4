#define IDX_MAX 10001
#define E first
#define S second
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Node;
vector<Node> A;
int isused[IDX_MAX];

int N;

int solution(vector<vector<int>> routes) {
	int answer = 0;
	N = routes.size();
	A.resize(N);
	for(int i=0;i<N;i++){
		A[i] = {routes[i][0], routes[i][1]};
		if(A[i].S > A[i].E) swap(A[i].S,A[i].E);
	}

	sort(A.begin(),A.end());

	for(int i=0;i<N;i++){
		if(!isused[i]){
			int pos = A[i].E;
			answer++;
			for(int j=0;j<N;j++){
				if(A[j].S <= pos && pos <= A[j].E)
					isused[j]=1;
			}
		}
	}

	return answer;
}

/*
11:25 Problem Analysis.
20:58 solution() Completed.
시간초과 나야 정상이었을 듯..
다른 사람 풀이를 보니, O(N)으로 풀이함.
240503 21:06
*/