#define INF 0x3f3f3f3f
#define IDX_MAX 101
#include<bits/stdc++.h>
using namespace std;

int dist[IDX_MAX][IDX_MAX][IDX_MAX];

void Init();
void ShowArr();
int N,M,Q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M >> Q;
	Init();
	for(int i=0;i<M;i++){
		int s,e,w;
		cin >> s >> e >> w;
		for(int k=1;k<=N;k++){
			if(k==s || k==e) continue;
			dist[k][s][e] = w;
		}
	}

	for(int loop=1;loop<=N;loop++){
		for(int k=1;k<=N;k++){
			if(k==loop) continue;
			for(int s=1;s<=N;s++){
				if(s==loop) continue;
				for(int e=1;e<=N;e++){
					if(e==loop) continue;
					if(dist[loop][s][k] + dist[loop][k][e] < dist[loop][s][e]){
						dist[loop][s][e] = dist[loop][s][k] + dist[loop][k][e];
					}
				}
			}
		}
	}

	//ShowArr();

	for(int i=0;i<Q;i++){
		int s,e,exclusion;
		cin >> s >> exclusion >> e;
		if(dist[exclusion][s][e] == INF)
			cout << "No\n";
		else
			cout << dist[exclusion][s][e] << "\n";
	}
	
	return 0;
}

void Init(){
	for(int loop=1;loop<=IDX_MAX-1;loop++){
		for(int i=1;i<=IDX_MAX-1;i++){
			for(int j=1;j<=IDX_MAX-1;j++){
				dist[loop][i][j] = INF;
			}
		}
	}
}

void ShowArr(){
	cout << "**ShowArr()**\n";
	for(int loop=1;loop<=N;loop++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(dist[loop][i][j] == INF)
					cout << "INF ";
				else
					cout << dist[loop][i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n\n";
	}
}


/*
10:06 Problem Analysis
18:27 main() Completed
19:53 Init() COmpleted
31:08 
	cin >> s >> e >> exclusion;
	에서
	cin >> s >> exclusion >> e;
	로 변경
240314 31:26
*/