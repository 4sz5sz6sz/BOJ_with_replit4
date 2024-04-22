#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<int> vis;
int N;

vector<vector<int>> A;
void BFS(int start);
int solution(int n, vector<vector<int>> computers) {
	int cnt=0;
	N = n;
	vis.resize(N);
	A = computers;

	for(int i=0;i<N;i++){
		if(vis[i]) continue;
		BFS(i);
		cnt++;
	}

	return cnt;
}

void BFS(int start){
	queue<int> Q; Q.push(start);
	vis[start]=1;
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		for(int next=0;next<N;next++){
			if(cur==next) continue;
			if(vis[next] || A[cur][next] == 0) continue;
			Q.push(next); vis[next] = 1;
		}
	}
}

/*
03:00 solution() Completed
06:08 BFS() Completed
240420 08:26
*/