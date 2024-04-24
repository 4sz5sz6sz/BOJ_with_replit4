#define DIST first
#define POS second
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Edge;
vector<vector<Edge>> A;
vector<int> indegree;
vector<int> dist;
vector<int> cost;
int N;

void Topological_sort();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	A.resize(N+1);
	indegree.resize(N+1);
	dist.resize(N+1);
	cost.resize(N+1);
	for(int cur=1;cur<=N;cur++){
		int w;
		cin >> w;
		cost[cur] = w;
		while(1){
			int prev;
			cin >> prev;
			if(prev == -1) break;
			A[prev].push_back({w,cur});
			indegree[cur]++;
		}
	}

	Topological_sort();

	for(int i=1;i<=N;i++){
		cout << dist[i] << "\n";
	}
	
	return 0;
}

void Topological_sort(){
	priority_queue<Edge> Q;		//maximum heap
	for(int i=1;i<=N;i++){
		if(indegree[i] == 0){
			Q.push({cost[i],i});
			dist[i] = cost[i];
		}
	}

	while(!Q.empty()){
		Edge cur = Q.top(); Q.pop();
		//if(cur.DIST != dist[cur.POS]) continue;	//max()
		//이 문장 넣으면. indegree 감소시키기가 어려움..
		for(Edge next:A[cur.POS]){
			indegree[next.POS]--;
			if(dist[cur.POS] + next.DIST > dist[next.POS]){
				dist[next.POS] = dist[cur.POS] + next.DIST;
			} //max()
			if(indegree[next.POS] == 0){
				Q.push({dist[next.POS],next.POS});
			}
		}
		
	}
}
/*
02:38 Problem Analysis.
07:34 input Completed.
08:22 main() Completed.
17:08 Topological_sort() Completed.
19:01 TC passed.
240424 19:07
*/