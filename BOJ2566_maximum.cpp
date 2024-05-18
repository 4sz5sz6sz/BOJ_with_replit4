#define X first
#define Y second
#define IDX_MAX 11
#include<bits/stdc++.h>
using namespace std;

int A[IDX_MAX][IDX_MAX];
typedef pair<int,int> Pos;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N = 9;
	Pos ans = {0,0};
	int _max = -1;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> A[i][j];
			if(A[i][j] > _max){
				_max = A[i][j];
				ans = {i,j};
			}
		}
	}

	cout << _max << "\n";
	cout << ans.X << " " << ans.Y << "\n";
	
	return 0;
}

/*
02:49
240518 
*/