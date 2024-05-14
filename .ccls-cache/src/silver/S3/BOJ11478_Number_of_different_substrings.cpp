#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	unordered_map<string,int> m;
	int ans=0;
	cin >> s;
	int N = s.size();

	for(int st=0;st<N;st++){
		for(int d=1;d<=N;d++){
			if(st+d-1 >= N) break;
			string cur = s.substr(st,d);
			if(m[cur]) continue;
			//cout << cur << "\n";
			m[cur]++;
			ans++;
		}
	}

	cout << ans << "\n";
	
	return 0;
}

/*
01:02 Problem Analysis.
11:43 TC passed.
240514 11:47
*/