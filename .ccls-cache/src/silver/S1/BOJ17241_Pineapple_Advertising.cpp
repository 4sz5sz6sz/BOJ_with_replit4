#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> A;
vector<int> dist;
int cnt;

void BFS(int start);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M,Q;
	cin >> N >> M >> Q;
	A.resize(N+1);
	dist.resize(N+1,INF);

	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}

	for(int i=0;i<Q;i++){
		int start;
		cin >> start;
		cnt = 0;
		//if(dist[start]>1)
		BFS(start);
		cout << cnt << "\n";
	}
	
	return 0;
}

void BFS(int start){
	queue<int> Q; Q.push(start);
	if(dist[start] <= 0) return; 
	if(dist[start] > 1)
		cnt++;
	dist[start]=0;
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		for(int next:A[cur]){
			if(dist[next]<=1) continue;
			dist[next] = dist[cur]+1;
			if(dist[cur] < 1){
				Q.push(next);
				cnt++;
				//cout << "	next : " << next << "\n";
			}
			
		}
	}
}

/*
04:53 Problem Analysis.
07:30 main() Completed.
12:00 BFS() Completed.
24:51 BFS() Completed. (2), TC passed.

vis[]로 하는게 훨씬 나았을 듯.
240325 25:06
*/