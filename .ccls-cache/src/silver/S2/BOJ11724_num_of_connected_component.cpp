#include<bits/stdc++.h>
using namespace std;

int N,M;
int cnt;

vector<int> vis;
vector<vector<int>> A;

void BFS(int start);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;	
	vis.resize(N+1);
	A.resize(N+1);

	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}

	for(int i=1;i<=N;i++)
		if(vis[i]==0){
			BFS(i);
			cnt++;
		}

	cout << cnt << "\n";

	return 0;
}

void BFS(int start){
	queue<int> Q; Q.push(start);
	vis[start] = 1;
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		for(int next:A[cur]){
			if(!vis[next]){
				vis[next]=1;
				Q.push(next);
			}
		}
	}
}

/*
02:03 문제 분석
10:53 main() 작성 완료
24:29 테스트 케이스 통과
vim만 이용해서 작성

240309

*/