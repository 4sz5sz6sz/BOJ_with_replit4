#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

vector<int> dist;
int F,S,G,U,D;
void BFS(int start);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	
	cin >> F >> S >> G >> U >> D;

	dist.resize(F+1,INF);
	BFS(S);

	if(dist[G] == INF)
		cout << "use the stairs\n";
	else
		cout << dist[G] << "\n";
	return 0;
}

void BFS(int start){
	queue<int> Q; Q.push(start);
	dist[start]=0;
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		// cout << "	cur :	" << cur;
		// cout << "	dist[cur] :	" << dist[cur];
		// cout << "\n";
		for(int dir=0;dir<2;dir++){
			if(dir==0 && cur + U <= F && dist[cur] + 1 < dist[cur+U]){	//U
				dist[cur+U] = dist[cur]+1;
				Q.push(cur+U);
			}
			if(dir==1 && cur - D >= 1 && dist[cur] + 1 < dist[cur-D]){	//D
				dist[cur-D] = dist[cur]+1;
				Q.push(cur-D);
			}
		}
	}
}


/*
03:43 Problem Analysis.
06:16 main() Completed.
10:17 BFS() Completed.
16:36
	Q.push(cur+D);
	에서
	Q.push(cur-D);
	로 수정.
240406 10:25
*/