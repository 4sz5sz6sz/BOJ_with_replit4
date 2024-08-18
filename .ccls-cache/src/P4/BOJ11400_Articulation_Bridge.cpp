#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Edge;
vector<vector<int>> A;
vector<int> vis;
vector<Edge> ans;
int N,M;
int cntOfVertex;

int DFS(int cur, int parent);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	A.resize(N+1);
	vis.resize(N+1);
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}

	for(int i=1;i<=N;i++)
		if(!vis[i])
			DFS(i,0);

	sort(ans.begin(),ans.end());
	cout << ans.size() << "\n";
	for(Edge cur:ans)
		cout << cur.X << " " << cur.Y << "\n";
	
	return 0;
}

int DFS(int cur, int parent){
	int ret = vis[cur] = ++cntOfVertex;
	for(int next:A[cur]){
		if(next == parent) continue;
		if(!vis[next]){
			int min_V = DFS(next,cur);
			if(min_V > vis[cur])
				ans.push_back({min(cur,next), max(cur,next)});
			ret = min(ret, min_V);
		}
		else
			ret = min(ret, vis[next]);
	}
	return ret;
}

/*
02:34 Problem Analysis.
08:10 main() Completed.
19:44 DFS() Completed.
21:20 TC passed.
240818 21:24
*/