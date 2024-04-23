#define INF 0x3f3f3f3f
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> A;
vector<int> dist;
int N;

void BFS(int start);
//int solution(int n, vector<vector<int>> edge);

/*
int main(){
	vector<vector<int>> edge;
	edge = {{3,6}, {4,3}, {3,2}, {1,3}, {1,2}, {2,4}, {5,2}};
	cout << solution(6,edge);
}
*/

int solution(int n, vector<vector<int>> edge) {
	N = n;
	A.resize(N+1);
	dist.resize(N+1,INF);
	for(int i=0;i<edge.size();i++){
		int S = edge[i][0];
		int E = edge[i][1];
		A[S].push_back(E);
		A[E].push_back(S);
	}

	BFS(1);

	int _max = -1;
	int ans=0;
	
	for(int i=1;i<=N;i++){
		// cout << "dist[i] :" << dist[i];
		// cout << "\n";
		if(dist[i] > _max){
			ans=1;
			_max=dist[i];
		}
		else if(dist[i] == _max)
			ans++;
	}

	return ans;
}

void BFS(int start){
	queue<int> Q; Q.push(start);
	dist[start] = 1;
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		for(int next:A[cur]){
			// cout << "	next	:" << next << "\n";
			if(dist[next] <= dist[cur]+1) continue;
			dist[next] = dist[cur] + 1;
			Q.push(next);
		}
	}
}

/*
03:09 Problem Analysis.
08:12 solution() Completed.
09:50 BFS() Completed.
14:37 _max 갱신.
28:01 
for(int i=0;i<N;i++){
에서
for(int i=0;i<edge.size();i++){
로 변경.
240419 30:25
*/