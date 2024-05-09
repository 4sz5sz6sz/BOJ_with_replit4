#define IDX_MAX 21
#include<bits/stdc++.h>
using namespace std;

int board[IDX_MAX][IDX_MAX];
int dist[IDX_MAX][IDX_MAX];
int sum;
int N;

void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> board[i][j];
		}
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			dist[i][j] = board[i][j];
		}
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){	//j = i->1
			sum += board[i][j];
		}
	}

	sum/=2;
	cout << "	sum : " << sum;
	cout << "\n";
/*
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				// if(i==k) continue;
				// if(j==k) continue;
				// if(i==j) continue;
				if(dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
*/
	ShowArr();


	for(int i=1;i<=N;i++){
		for(int k=1;k<=N;k++){
			for(int j=1;j<=N;j++){
				//if(j<=k) ;
				if(i==k) continue;
				if(j==k) continue;
				if(board[i][k] + board[k][j] == board[i][j]){
					cout << "	i : " << i;
					cout << "	k : " << k;
					cout << "	j : " << j;
					cout << "	board[i][j] : " << board[i][j];
					cout << "\n";
					sum-=board[i][j];
				}
				else if(board[i][k] + board[k][j] < board[i][j]){
					cout << "-1\n";
					return 0;
				}
			}
		}
	}


	cout << sum << "\n";
	
	return 0;
}

void ShowArr(){
	cout << "\n";
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

/*
06:41 Problem Analysis.
23:59 자정 STOP..
240508 
*/