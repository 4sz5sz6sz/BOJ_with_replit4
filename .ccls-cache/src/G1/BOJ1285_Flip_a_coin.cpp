#define INF 0x3f3f3f3f
#define IDX_MAX 21
#include<bits/stdc++.h>
using namespace std;

int N;
int ans=INF;
int board[IDX_MAX][IDX_MAX];
int board_copy[IDX_MAX][IDX_MAX];

void CopyBoard();
void flip_col(int col);
void flip_row(int row);
int GetNumOfT(int row);
int GetTotal();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int x=0;x<N;x++){
		string s;
		cin >> s;
		for(int y=0;y<N;y++){
			if(s[y] == 'T')
				board[x][y] = 1;
		}
	}

	for(int bit=0;bit<1<<N;bit++){
		int mask = bit;
		CopyBoard();
		for(int a=0;mask;mask>>=1,a++)
			if(mask & 1)
				flip_col(a);
		
		for(int row=0;row<N;row++){
			int cntT = GetNumOfT(row);
			if(cntT > N-cntT)
				flip_row(row);
		}

		ans = min(GetTotal(), ans);
	}

	cout << ans << "\n";
	
	return 0;
}

void CopyBoard(){
	for(int x=0;x<N;x++){
		for(int y=0;y<N;y++){
			board_copy[x][y] = board[x][y];
		}
	}
}

void flip_col(int col){
	for(int x=0;x<N;x++){
		board_copy[x][col]^=1;
	}
}

void flip_row(int row){
	for(int y=0;y<N;y++){
		board_copy[row][y]^=1;
	}
}

int GetNumOfT(int row){
	int cnt=0;
	for(int y=0;y<N;y++){
		cnt+=board_copy[row][y];
	}
	return cnt;
}

int GetTotal(){
	int cnt=0;
	for(int x=0;x<N;x++){
		for(int y=0;y<N;y++){
			cnt+=board_copy[x][y];
		}
	}
	return cnt;
}


/*
06:23 Problem Analysis.
15:32 main() Completed.
20:10 4 func() Completed.
21:21 TC passed.
240507 21:50
*/