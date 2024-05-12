#define IDX_MAX 207
#include<bits/stdc++.h>
using namespace std;

int N,M;

vector<string> s;
int A[IDX_MAX][IDX_MAX];
int DP[IDX_MAX][IDX_MAX];
int isused[IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=1;j<=M;j++){
			char ch;
			cin >> ch;
			if(ch == '.')
				A[i][j] = 1;
		}
		string name;
		cin >> name;
		s.push_back(name);
	}

	vector<int> ans(N);

	for(int i=0;i<N;i++){
		for(int j=1;j<=M;j++){
			if(A[i][j]){
				DP[i][j] = DP[i][j-1] + A[i][j];
				ans[i] = max(ans[i], DP[i][j]);
			}
		}
	}

	for(int i=0;i<N;i++){
		isused[ans[i]] = 1;
	}

	int cnt=0;
	for(int i=0;i<=M;i++){
		if(isused[i]) cnt++;
	}

	cout << cnt << "\n";
	
	for(int i=0;i<N;i++){
		cout << ans[i] << " " << s[i] << "\n";
	}
	
	
	return 0;
}

/*

240512 08:59
*/