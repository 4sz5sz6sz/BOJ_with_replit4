#define DIST first
#define POS second
#define MXN 40007
#define MXDEPTH 20
#define INF 0x3f3f3f3f3f3f3f3f
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,int> Edge;

int N,M,Q;
vector<vector<Edge>> adj;
vector<LL> dist;
vector<int> depth;
int D[MXN][MXDEPTH];

void Init();
void construct_LCA(int cur, int parent);
void BFS(int start);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	M = N-1;

	Init();

	for(int i=0;i<M;i++){
		int s,e;
		LL w;
		cin >> s >> e >> w;
		adj[s].push_back({w,e});
		adj[e].push_back({w,s});
	}

	BFS(1);
	construct_LCA(1,0);

	cin >> Q;
	
	while(Q--){
		int A,B;
		cin >> A >> B;
		
		if(depth[A] > depth[B]) swap(A,B);
		int tempA = A;
		int tempB = B;

		for(int i=MXDEPTH-1;i>=0;i--){
			if(depth[A] <= depth[D[B][i]])
				B = D[B][i];
		}

		int lca = A;

		if(A!=B){
			for(int j=MXDEPTH-1;j>=0;j--){
				if(D[A][j] != 0 && D[A][j] != D[B][j]){
					A = D[A][j];
					B = D[B][j];
				}
			}
			lca = D[A][0];
		}
		// cout << "	lca :	" << lca;
		// cout << "	dist[tempA] :	" << dist[tempA];
		// cout << "	dist[tempB] :	" << dist[tempB];
		// cout << "	dist[lca] :	" << dist[lca];
		//cout << "\n";
		
		cout << dist[tempA] + dist[tempB] - 2 * dist[lca] << "\n";
	}
	
	return 0;
}

void Init(){
	adj.resize(N+1);
	dist.resize(N+1,INF);
	depth.resize(N+1);
}

void construct_LCA(int cur, int parent){
	depth[cur] = depth[parent] + 1;
	D[cur][0] = parent;
	for(int i=1;i<MXDEPTH;i++){
		D[cur][i] = D[D[cur][i-1]][i-1];
	}
	
	for(Edge next:adj[cur]){
		if(next.POS!=parent)
			construct_LCA(next.POS,cur);
	}
}

void BFS(int start){
	queue<Edge> Q; Q.push({0,start});
	dist[start]=0;

	while(!Q.empty()){
		Edge cur = Q.front(); Q.pop();
		for(Edge next:adj[cur.POS]){
			if(dist[next.POS] != INF) continue;
			dist[next.POS]=dist[cur.POS] + next.DIST;
			Q.push({dist[next.POS],next.POS});
		}
	}
}

/*
05:56 Problem Analysis
17:51 main(), Init() Completed
21:02 construct_LCA() Completed
25:31 BFS() Completed
28:42 adj를 int 에서 Edge형으로 변경.
if(dist[next.POS] != INF) continue; 삽입.
34:37 tempA,tempB 도입.
35:36 TC passed
틀렸습니다...

42:31
if(depth[A] > depth[B]) swap(A,B);
이후에
tempA tempB에 백업하기로 변경.

4% 틀렸습니다...

240312 재개
04:59

	int형에서 LL형으로 변경.
	
	for(int i=MXDEPTH-1;i>=1;i--){
	에서
	for(int i=1;i<MXDEPTH;i++){
	로 변경.



240311 50:26 + 05:48
*/