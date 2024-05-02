#define INF 0x3f3f3f3f
#define X first
#define Y second
#define IDX_MAX 1001
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Pos;
typedef struct Node{
	int CNT;
	Pos POS[2];
	bool operator<(const struct Node &temp)const {
		return CNT < temp.CNT;
	}
}Node;
Node DP[IDX_MAX][2];
// Pos POS[IDX_MAX][2];
Pos M[IDX_MAX];	//MISSION
int pre[IDX_MAX][2];


int N, W;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> W;
	for(int i=1;i<=W;i++){
		cin >> M[i].X >> M[i].Y;
	}

	for(int i=1;i<=W;i++){
		for(int j=0;j<2;j++){
			DP[i][j].CNT = INF;
		}
	}

	DP[0][0].POS[0] = {1,1};
	DP[0][0].POS[1] = {N,N};
	DP[0][1].POS[0] = {1,1};
	DP[0][1].POS[1] = {N,N};

	for(int i=1;i<=W;i++){
		Pos curM = M[i];
		for(int curDir=0;curDir<2;curDir++){
			//현재 움직이는 차량
			for(int prevDir=0;prevDir<2;prevDir++){
				//직전에 움직였던 차량
				Node prev = DP[i-1][prevDir];
				int ndist = abs(curM.X - prev.POS[curDir].X) + abs(curM.Y - prev.POS[curDir].Y);
				prev.CNT += ndist;
				prev.POS[curDir] = curM;
				//DP[i][curDir] = min(DP[i][curDir],prev);
				if(prev < DP[i][curDir]){
					DP[i][curDir] = prev;
					pre[i][curDir] = prevDir;
				}
			}
		}
	}

	
	for(int j=0;j<2;j++){
		for(int i=1;i<=W;i++){
			cout << DP[i][j].CNT << " ";
		}
		cout << "\n";
	}
	
	
	vector<int> ans2;
	int cur;
	if(DP[W][0] < DP[W][1])
		cur = 0;
	else
		cur = 1;
	//ans2.push_back(cur);

	for(int i=W;i>=1;i--){
		ans2.push_back(cur);
		cur = pre[i][cur];
	}
	
	reverse(ans2.begin(),ans2.end());

	int ans = min(DP[W][0].CNT, DP[W][1].CNT);
	cout << ans << "\n";
	for(int tmp:ans2) cout << tmp+1 << "\n";
	return 0;
}

/*
15:33 Problem Analysis.
56:01 main() Completed.

01:14:42 TC#1 9 출력 확인.
01:16:26 pre[i][curDir] = prevDir; 추가.
01:24:21 TC#1 passed.

포기.. 01:30:22

240502 01:24:52
*/