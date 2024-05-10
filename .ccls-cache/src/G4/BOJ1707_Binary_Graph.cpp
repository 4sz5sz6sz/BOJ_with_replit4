#define IDX_MAX 20007
#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int>> A;
vector<int> dist;
int ans;
int flag;

void Init();
void DFS(int cur, int depth, int parent);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		cin >> N >> M;
		Init();
		for(int i=0;i<M;i++){
			int s,e;
			cin >> s >> e;
			A[s].push_back(e);
			A[e].push_back(s);
		}

		for(int i=1;i<=N;i++){
			sort(A[i].begin(),A[i].end());
		}
		for(int i=1;i<=N;i++){
			DFS(i,1,0);
		}
		
		if(ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
	return 0;
}

void Init(){
	A.clear();
	A.resize(N+1);
	dist.clear();
	dist.resize(N+1);
	ans = 1;
	flag = 0;
}

void DFS(int cur, int depth, int parent){
	if(dist[cur]) return;
	dist[cur] = depth;

	for(int next:A[cur]){
		if(next == parent) continue;
		if(dist[next] && dist[next]%2 == dist[cur]%2){
			flag=1;	//escape switch On.
			ans = 0;
			return;
		}
		DFS(next,depth+1,cur);
		if(flag) return;
	}
	//dist[cur]=0;
}

/*
04:30 main(), Init() Completed.
08:39 DFS() Completed.
10:57 TC passed.
TLE..
13:19 //dist[cur]=0; 주석처리.
WA..

19:30 sort(A[i].begin(),A[i].end()); 추가.
32:13 DFS를 모든 정점에 대해 수행.
240509 32:21
*/