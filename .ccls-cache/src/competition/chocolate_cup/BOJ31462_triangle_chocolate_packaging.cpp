#define IDX_MAX 5002
#include<bits/stdc++.h>
using namespace std;

char board[IDX_MAX][IDX_MAX];	// 1-indexed
bool vis[IDX_MAX][IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for(int x=1;x<=N;x++){
		string s;
		cin >> s;
		for(int y=1;y<=x;y++){
			board[x][y] = s[y-1];
		}
	}

	//Red 검사.
	for(int x=1;x<=N;x++){
		for(int y=1;y<=x;y++){
			if(board[x][y] == 'R' && !vis[x][y]){
				if(board[x+1][y] == 'R' && !vis[x+1][y] && board[x+1][y+1] == 'R' && !vis[x+1][y+1]){
					vis[x][y] = vis[x+1][y] = vis[x+1][y+1] = true;
				}
			}
		}
	}

	//Blue 검사.
	for(int x=N;x>=1;x--){
		for(int y=1;y<=x;y++){
			if(board[x][y] == 'B' && !vis[x][y]){
				if(board[x-1][y] == 'B' && !vis[x-1][y] && board[x-1][y-1] == 'B' && !vis[x-1][y-1]){
					vis[x][y] = vis[x-1][y] = vis[x-1][y-1] = true;
				}
			}
		}
	}

	int ans=1;
	//전수 검사
	for(int x=1;x<=N;x++){
		for(int y=1;y<=x;y++){
			if(vis[x][y] == false){
				ans = 0;
			}
			if(ans==0) break;
		}
		if(ans==0) break;
	}

	cout << ans << "\n";

	return 0;
}

/*
06:15 문제 분석
17:40 main() 작성 완료. 첫 컴파일
19:00 테스트 케이스 통과
240301 19:04
*/