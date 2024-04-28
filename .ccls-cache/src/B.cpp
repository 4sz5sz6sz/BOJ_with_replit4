#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> A;
vector<vector<int>> A_copy;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	A.resize(N+1);
	for(int i=1;i<=N;i++){
		for(int j=0;j<3;j++){
			int num;
			cin >> num;
			if(num == -1) num = INF;
			A[i].push_back(num);
		}
	}

	A_copy = A;
	int ans=0;
	for(int i=1;i<=N;i++){
		sort(A_copy[i].begin(), A_copy[i].end());
		if(A[i] == A_copy[i] && A_copy[i][0] != INF) ans++;
	}

	cout << ans << "\n";
	
	return 0;
}

/*
B
07:00
240428 
*/