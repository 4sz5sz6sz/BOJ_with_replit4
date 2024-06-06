#define IDX_MAX 15
#include<bits/stdc++.h>
using namespace std;

int board[IDX_MAX][IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		reverse(s.begin(),s.end());
		cout << s << "\n";
	}

	return 0;
}

/*
04:08
240606
*/