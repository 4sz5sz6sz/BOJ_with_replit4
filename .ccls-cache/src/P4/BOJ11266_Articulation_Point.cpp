#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int>> A;
vector<int> cut;
vector<int> vis;
int cnt;

int DFS(int cur, bool root);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	A.resize(N+1);
	cut.resize(N+1);
	vis.resize(N+1);
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}

	for(int i=1;i<=N;i++)
		if(!vis[i])
			DFS(i, true);

	vector<int> ans;
	for(int i=1;i<=N;i++)
		if(cut[i])
			ans.push_back(i);

	cout << ans.size() << "\n";
	for(int cur:ans)
		cout << cur << " ";
	
	return 0;
}

int DFS(int cur, bool root){
	int ret=INF;
	int min_V=INF;
	int child=0;
	vis[cur] = ++cnt;
	for(int next:A[cur]){
		if(!vis[next]){
			child++;
			min_V = DFS(next, false);
			if(!root && min_V >= vis[cur])
				cut[cur] = true;
		}
		else{
			min_V = vis[next];
		}
		ret = min(ret, min_V);
	}
	
	if(root && child >= 2)	//??
		cut[cur] = true;

	ret = min(ret, min_V);
	
	return ret;
}

/*
00:46 Problem Analysis.
05:49 main() Completed.
18:44 DFS() Completed.
29:57 TC passed.
240817 30:02
*/