#define IDX_MAX 10001
#include<bits/stdc++.h>
using namespace std;

typedef struct Edge{
	int S,E,V;
	bool operator < (const struct Edge &temp)const{
		return V < temp.V;
	}
}Edge;

//int isused[IDX_MAX];
vector<int> parent;
int N,M;

bool CheckSame(int a, int b);
int find(int a);
void munion(int a, int b);

int solution(int n, vector<vector<int>> costs){
	int ans = 0;
	N = n;
	M = costs.size();

	vector<Edge> A;
	parent.resize(N,-1);

	for(int i=0;i<M;i++){
		int S = costs[i][0];
		int E = costs[i][1];
		int V = costs[i][2];
		A.push_back({S,E,V});
	}

	sort(A.begin(),A.end());

	for(int i=0;i<M;i++){
		Edge cur = A[i];
		if(!CheckSame(cur.S,cur.E)){
			munion(cur.S, cur.E);
			ans+=cur.V;
		}
	}  

	return ans;
}

bool CheckSame(int a, int b){
	return find(a) == find(b);
}

int find(int a){
	if(parent[a] < 0)
		return a;
	return parent[a] = find(parent[a]);
}

void munion(int a, int b){
	a = find(a);
	b = find(b);
	if(CheckSame(a,b)) return;
	parent[a] += parent[b];
	parent[b] = a;
}


/*
00:56 Problem Analysis.
11:44 solution() Completed.
15:46 union-find Completed.
17:30 TC passed.
WA...
21:06 간선의 갯수 M 추가함..
240503 21:14
*/