#define ROOT 1
#define DIST first
#define POS second
#define MXN 100007
#define MXDEPTH 20
#define INF 0x3f3f3f3f3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,int> Edge;

vector<int> depth;
vector<LL> dist;
vector<vector<Edge>> adj;
int D[MXN][MXDEPTH];
LL dist_max[MXN][MXDEPTH];
LL dist_min[MXN][MXDEPTH];

void Init();
void BFS(int start);
void construct_LCA(int cur, int parent);
void ShowArr();

int N,M,Q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	Init(); M = N-1;

	for(int i=0;i<M;i++){
		int a,b;
		LL v;
		cin >> a >> b >> v;
		adj[a].push_back({v,b});
		adj[b].push_back({v,a});
	}

	BFS(1);
	construct_LCA(1,0);

	cin >> Q;
	while(Q--){
		int A,B;
		cin >> A >> B;
		if(depth[A] > depth[B]) swap(A,B);
		// int tempA = A;
		// int tempB = B;

		LL ans1=INF, ans2=-INF;

		for(int i=MXDEPTH-1;i>=0;i--){
			if(depth[A] <= depth[D[B][i]]){
				ans1 = min(ans1, dist_min[B][i]);
				ans2 = max(ans2, dist_max[B][i]);
				B = D[B][i];
			}
		}

		int lca = A;

		if(A!=B){
			for(int j=MXDEPTH-1;j>=0;j--){
				if(D[A][j] != 0 && D[A][j]!=D[B][j]){
					ans1 = min(ans1, dist_min[A][j]);
					ans2 = max(ans2, dist_max[A][j]);
					ans1 = min(ans1, dist_min[B][j]);
					ans2 = max(ans2, dist_max[B][j]);
					A = D[A][j];
					B = D[B][j];
				}
			}
			ans1 = min(ans1, dist_min[A][0]);
			ans2 = max(ans2, dist_max[A][0]);
			ans1 = min(ans1, dist_min[B][0]);
			ans2 = max(ans2, dist_max[B][0]);
			lca = D[A][0];
		}
		/*
		for(int i=0;i<MXDEPTH;i++){
			if(tempA == lca) break;
			//if(D[tempA][i] == lca){
			if(1){
				cout << "	dist_min[tempA][i] :	" << dist_min[tempA][i] << "\n";
				cout << "	dist_max[tempA][i] :	" << dist_max[tempA][i] << "\n";
				ans1 = dist_min[tempA][i];
				ans2 = dist_max[tempA][i];
				break;
			}
			if(D[tempA][i] == 0) break;
		}

		for(int i=0;i<MXDEPTH;i++){
			if(tempB == lca) break;
			if(D[tempB][i] == lca || D[tempB][i] == 0){
			//if(1){
				cout << "	dist_min[tempB][i] :	" << dist_min[tempB][i] << "\n";
				cout << "	dist_max[tempB][i] :	" << dist_max[tempB][i] << "\n";
				ans1 = min(ans1,dist_min[tempB][i]);
				ans2 = max(ans2,dist_max[tempB][i]);
				break;
			}
		}
		*/

		if(ans1 == INF) ans1 = 0;
		if(ans2 == -INF) ans2 = 0;

		// cout << "	lca :" << lca << "\n";
		cout << ans1 << " " << ans2 << "\n";
	}

	// ShowArr();

	return 0;
}

void Init(){
	depth.resize(N+1);
	adj.resize(N+1);
	dist.resize(N+1,INF);
	dist[0] = 0;
	for(int i=0;i<MXN;i++){
		for(int j=0;j<MXDEPTH;j++){
			dist_min[i][j] = INF;
		}
	}
}

void BFS(int start){
	queue<Edge> Q; Q.push({0,start});
	dist[start]=0;

	while(!Q.empty()){
		Edge cur = Q.front(); Q.pop();
		for(Edge next:adj[cur.POS]){
			if(dist[cur.POS] + next.DIST >= dist[next.POS]) continue;
			dist[next.POS] = dist[cur.POS] + next.DIST;
			Q.push({dist[next.POS],next.POS});
		}
	}
}

void construct_LCA(int cur, int parent){
	depth[cur] = depth[parent]+1;
	D[cur][0] = parent;
	dist_max[cur][0] = dist[cur]-dist[parent];
	dist_min[cur][0] = dist[cur]-dist[parent];

	for(int i=1;i<MXDEPTH;i++){
		int p = D[cur][i-1];
		int pp = D[p][i-1];
		D[cur][i] = pp;
		if(pp==0) break;
		dist_max[cur][i] = max(dist_max[cur][i-1], dist_max[p][i-1]);
		dist_min[cur][i] = min(dist_min[cur][i-1], dist_min[p][i-1]);
	}

	for(Edge next:adj[cur]){
		if(next.POS != parent){
			construct_LCA(next.POS, cur);
		}
	}
}

void ShowArr(){

	cout << "*** D[][] ***\n";
	for(int i=1;i<=N;i++){
		for(int j=0;j<MXDEPTH;j++){
			cout << "	" << D[i][j];
		}
		cout << "\n";
	}
	cout << "\n";

	cout << "*** dist_max[][] ***\n";
	for(int i=1;i<=N;i++){
		for(int j=0;j<MXDEPTH;j++){
			cout << "	" << dist_max[i][j];
		}
		cout << "\n";
	}
}

/*
31:16 Problem Analysis
35:00 Set Global variable
44:18 Problem Analysis. lca 구한 뒤
56:11 main() Completed
01:03:39 BFS() Completed
01:08:27 construct_LCA() Completed
01:08:53 첫 컴파일
01:33:44 construct_LCA 재작성 완료.

점심식사, 재개
13:38 첫 실행
테스트 케이스 일부 오답..
23:44 ShowArr()로 dist_max[][] 확인해보니, 100 100 100... 조상이 2^20까지 꽉 차있음.
	if(p==0) break; 삽입

41:18
	if(tempA == lca) break; 삽입

42:24 TC 3번 오답..
58:57 if(pp==0) break; 위치 잘못된것 발견.
01:24:10
	for문 역순 순회 내부에서,
	ans1 = min(ans1, dist_min[A][j]);
	ans2 = max(ans2, dist_max[A][j]);
	ans1 = min(ans1, dist_min[B][j]);
	ans2 = max(ans2, dist_max[B][j]);
	삽입.
01:26:26 TC passed
240313 01:33:44 + 01:26:26
*/