#include<bits/stdc++.h>
using namespace std;

typedef struct Edge{
	int S,E,W;
	bool operator<(struct Edge &temp){
		return W<temp.W;
	}
}Edge;

int N,M;
vector<int> parent;
vector<Edge> adj;

void munion(int a, int b);
bool CheckSame(int a, int b);
int find(int a);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while(1){
		int total=0;
		int sumOfON=0;
		cin >> N >> M;
		if(N == 0 && M == 0) break;
		parent.clear();
		parent.resize(N,-1);
		adj.clear();
		for(int i=0;i<M;i++){
			int S,E,W;
			cin >> S >> E >> W;
			adj.push_back({S,E,W});
			total+=W;
		}
		sort(adj.begin(),adj.end());
		for(int i=0;i<M;i++){
			Edge cur = adj[i];
			if(!CheckSame(cur.S,cur.E)){
				munion(cur.S,cur.E);
				sumOfON+=cur.W;
			}
		}

		int sumOfOFF = total - sumOfON;
		cout << sumOfOFF << "\n";
	}
	
	return 0;
}

void munion(int a, int b){
	a = find(a);
	b = find(b);
	if(CheckSame(a,b)) return;
	parent[a]+=parent[b];
	parent[b] = a;
}

bool CheckSame(int a, int b){
	return find(a) == find(b);
}

int find(int a){
	if(parent[a] < 0)
		return a;
	return parent[a] = find(parent[a]);
}


/*
02:51 Problem Analysis.
17:35 main() Completed.
21:25 3 functions Completed.
23:32 TC passed.
240812 23:37
*/