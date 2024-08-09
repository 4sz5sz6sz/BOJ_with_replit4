#define IDX_MAX 505
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll board[IDX_MAX][IDX_MAX];
ll nxtDP[IDX_MAX][IDX_MAX];
ll DP[IDX_MAX][IDX_MAX];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool OOB(int nx, int ny, int N, int M);
void Init();
void ShowArr();

int N,M;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll ans=0;
	cin >> N >> M;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> board[i][j];
		}
	}

	nxtDP[0][0] = 1;

	for(int loop=0;loop<N*M;loop++){
		Init();
		ll sum=0;
		for(int x=0;x<N;x++){
			for(int y=0;y<M;y++){
				if(!DP[x][y]) continue;
				for(int dir=0;dir<4;dir++){
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if(OOB(nx,ny,N,M)) continue;
					if(board[nx][ny] >= board[x][y]) continue;
					nxtDP[nx][ny] += DP[x][y];
				}
				sum+=DP[x][y];
			}
		}
		ans+=DP[N-1][M-1];
		if(sum==0){
			ans+=nxtDP[N-1][M-1];
			break;
		}
		//ShowArr();
	}

	//ShowArr();

	cout << ans;
	
	return 0;
}

bool OOB(int nx, int ny, int N, int M){
	return nx < 0 || ny < 0 || nx >= N || ny >= M;
}

void ShowArr(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout << DP[i][j] << "	";
		}
		cout << "\n";
	}
}

void Init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			DP[i][j] = nxtDP[i][j];
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			nxtDP[i][j] = 0;
		}
	}
}

/*
01:14 Problem Analysis.
07:04 main() Completed.
07:51 OOB() Completed.
TC 3인데 2로 출력하는 현상 발생.
15:41 dir 2 -> 4로 변경.
21:58 ShowArr() 확인해보니 2->1로 줄어드는 현상 발생.
본대탐험 문제처럼 수정해야할 듯.
30:34 TC passed. but 시간초과 가능성 있음..
TLE...
32:46 sum으로 break문 도입.
35:44 if(!DP[x][y]) 도입.
36% WA...
38:18 
	ans+=nxtDP[N-1][M-1];
	break;
	도입.
40:04 ll 형으로 변경.
36% WA...
ll ans=0; sum =0 으로 변경.
맞았습니다!!!
240809 42:14
*/