#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		int N,M,start;
		cin >> N >> M >> start;
		vector<int> comm(M);
		vector<int> cur(N+1);
		vector<int> next(N+1);	//Init
		
		vector<int> r(M);

		for(int i=0;i<M;i++){
			char tmp;
			cin >> r[i] >> tmp;
			if(tmp=='?') tmp = '2';
			comm[i] = tmp-'0';
		}

		cur[start]=1;
		for(int i=0;i<M;i++){
			next.clear(); next.resize(N+1);
			if(comm[i]==0 || comm[i] == 2){
				for(int j=1;j<=N;j++){
					if(cur[j] > 0){
						int nxt_pos = (j + r[i] ) % N;
						if(nxt_pos == 0) nxt_pos = N;
						next[nxt_pos] = 1;
					}
				}
			}

			if(comm[i]==1 || comm[i] == 2){
				for(int j=1;j<=N;j++){
					if(cur[j] > 0){
						int nxt_pos = (j - r[i] + N) % N;
						if(nxt_pos == 0) nxt_pos = N;
						next[nxt_pos] = 1;
					}
				}
			}
			cur.clear(); cur.resize(N+1);
			for(int j=1;j<=N;j++){
				cur[j] = next[j];
			}
		}

		vector<int> ans;
		for(int i=1;i<=N;i++){
			if(cur[i]>0)
				ans.push_back(i);
		}
		cout << ans.size() << "\n";
		for(int temp:ans){
			cout << temp << " ";
		}
		cout << "\n";
		
	}
	
	
	return 0;
}



/*
22:00 문제 읽기
34:50 문제 분석
37:25 문제 재분석
50:25 main() Completed.
52:34 TC 5개 중 3개 정답..
56:23
	next.clear(); next.resize(N+1);
	cur.clear(); cur.resize(N+1);
	삽입.
	TC 5개 전부 통과.
240318 56:37
*/