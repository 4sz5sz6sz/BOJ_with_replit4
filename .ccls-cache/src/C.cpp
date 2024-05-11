#define INF 0x3f3f3f3f
#define IDX_MAX 307
#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
	int X,Y,W;
}Node;
int del[IDX_MAX][IDX_MAX];
int dist[IDX_MAX][IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	//int flag=0;

	cin >> N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> dist[i][j];
		}
	}

	for(int i=1;i<=N;i++){
		dist[i][i] = INF;
	}

	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(i==k) continue;
				if(j==k) continue;
				if(j==i) continue;
				if(dist[i][k] + dist[k][j] == dist[i][j])
					del[i][j] = 1;
				else if(dist[i][k] + dist[k][j] < dist[i][j]){
					cout << "-1\n";
					return 0;
				}
			}
		}
	}

	vector<Node> ans;

	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			if(del[i][j]) continue;
			ans.push_back({i,j,dist[i][j]});
		}
	}

	cout << ans.size() << "\n";
	for(Node cur:ans)
		cout << cur.X << " " << cur.Y << " " << cur.W << "\n";

	return 0;
}

/*
09:37 Problem Analysis.
18:43 main() Completed.
19:53 TC passed.
240511 19:59
*/