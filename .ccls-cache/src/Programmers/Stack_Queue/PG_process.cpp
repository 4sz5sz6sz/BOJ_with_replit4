#define DATA first
#define INDEX second
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> Node;	//data, index

int solution(vector<int> arr, int comm) {
	int N = arr.size();
	vector<int> rank(N);
	queue<Node> Q;
	priority_queue<int> PQ;	//Node 대신 int 저장해도 무방함.
	for(int i=0;i<N;i++){
		int cur = arr[i];
		Q.push({cur,i});
		PQ.push(cur);
	}

	int cnt=0;
	while(!Q.empty()){
		Node cur = Q.front(); Q.pop();
		if(cur.DATA == PQ.top()){
			rank[cur.INDEX] = ++cnt;
			PQ.pop();
		}
		else
			Q.push(cur);
	}
	
	return rank[comm];
}

/*
07:27 Problem Analysis.
13:09 solution() Completed.
240423 14:23
*/