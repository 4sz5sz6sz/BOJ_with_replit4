#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	unordered_map<string,int> m;
	int N,M;
	cin >> N >> M;
	while(N--){
		string s;
		cin >> s;
		m[s] = 1;
	}

	int ans=0;
	while(M--){
		string s;
		cin >> s;
		if(m[s])
			ans++;
	}

	cout << ans << "\n";
	
	return 0;
}

/*
01:14
240603
*/