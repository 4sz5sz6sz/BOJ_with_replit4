#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<int> p;

int find(int a);
void munion(int a, int b);
bool CheckSame(int a, int b);

int solution(int n, vector<vector<int>> wires) {
	int answer = INF;

	N = n;
	M = N-1;
	p.resize(N+1,-1);

	for(int del=0;del<M;del++){
		fill(p.begin(),p.end(),-1);
		for(int i=0;i<M;i++){
			if(i == del) continue;
			int S = wires[i][0];
			int E = wires[i][1];
			if(!CheckSame(S,E))
				munion(S,E);
		}
		int tmp = find(1);
		answer=min(answer,abs(N - 2 * (-p[tmp])));
	}
	return answer;
}

int find(int a){
	if(p[a] < 0)
		return a;
	return p[a] = find(p[a]);
}

void munion(int a, int b){
	a = find(a);
	b = find(b);
	if(CheckSame(a,b)) return;
	p[a]+=p[b];
	p[b]=a;
}

bool CheckSame(int a, int b){
	return find(a) == find(b);
}



/*
13:00 Problem Analysis, solution() Completed.
15:05 3 func() Completed.
240507 17:59
*/