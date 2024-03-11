#define MXN 100007
#define MXDEPTH 20
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int D[MXN][MXDEPTH];
vector<int> depth;

int N,M;

void construct_LCA(int cur, int parent);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	adj.resize(N+1); depth.resize(N+1);
	
	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	construct_LCA(1,0);

	cin >> M;

	while(M--){
		int A,B;
		cin >> A >> B;

		if(depth[A] > depth[B]) swap(A,B);
		for(int i=MXDEPTH-1;i>=0;i--){
			if(depth[A] <= depth[D[B][i]])
				B = D[B][i];
		}

		int lca = A;
		if(A!=B){
			for(int j=MXDEPTH-1;j>=0;j--){
				//??
				if(D[A][j] != 0 && D[A][j] != D[B][j]){
					A = D[A][j];
					B = D[B][j];
				}
			}
			lca = D[A][0];
		}
		cout << lca << "\n";
	}
	
	return 0;
}

void construct_LCA(int cur, int parent){
	depth[cur] = depth[parent]+1;
	D[cur][0] = parent;
	for(int i=1;i<MXDEPTH;i++){
		D[cur][i] = D[D[cur][i-1]][i-1];
	}

	for(int next:adj[cur])
		if(next != parent)
			construct_LCA(next,cur);
}

/*
03:01 Problem Analysis
19:38 main() Completed
23:01 construct_LCA() Completed

for(int i=MXDEPTH-1;i>=0;i--){
	if(depth[A] <= depth[D[B][i]])
제대로 작성함.		

36:53 TC passed

240311 37:21
*/