#define INF 0x3f3f3f3f
#define IDX_MAX 207
#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
int N,M;
vector<vector<ld>> dist_max(IDX_MAX,vector<ld>(IDX_MAX,-1));
vector<vector<ld>> dist_min(IDX_MAX,vector<ld>(IDX_MAX,INF));

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for(int i=0;i<M;i++){
		ld S,E,W;
		cin >> S >> E >> W;
		if(W > dist_max[S][E]){
			dist_max[S][E] = W;
			dist_max[E][S] = W;
		}
		if(W < dist_min[S][E]){
			dist_min[S][E] = W;
			dist_min[E][S] = W;
		}
	}

	for(int i=1;i<=N;i++)
		dist_min[i][i] = 0;

	for(int K=1;K<=N;K++){
		for(int S=1;S<=N;S++){
			for(int E=1;E<=N;E++){
				if(dist_min[S][K] + dist_min[K][E] < dist_min[S][E]){
					dist_min[S][E] = dist_min[S][K] + dist_min[K][E];
				}
			}
		}
	}

	ld ans = INF;
	for(int start=1;start<=N;start++){
		ld longest_time=-1;
		for(int from=1;from<=N;from++){
			for(int to=1;to<=N;to++){
				//if(dist_max[from][to] == -1) continue;
				ld remain_len = dist_max[from][to] + dist_min[start][from] - dist_min[start][to];
				ld spent_time;
				
				if(remain_len > 0){
					spent_time = (remain_len/2.0) + dist_min[start][to];
					longest_time = max(longest_time, spent_time);
				}
			}
		}
		ans = min(ans, longest_time);
	}

	cout << fixed;
	cout.precision(1);
	cout << ans << "\n";
	
	return 0;
}

/*
05:53 Problem Analysis.
19:46 main() Completed.
26:04 dist_min[i][i] = 0; 삽입.
39:10 
ld remain_len = dist_max[from][to] + dist_min[start][from] - dist_min[start][to]; 
식 변경.
240816 39:43
*/