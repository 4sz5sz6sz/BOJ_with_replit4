#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	string input;

	cin >> N;
	cin >> input;
	cin >> M;

	while(M--){
		int l,r;
		cin >> l >> r;
		l--; r--;
		string s = input.substr(l,r-l+1);
		int len = s.size();
		int ans = 0;
		for(int st=0;st<N;st++){
			int cnt=0;
			for(int d=0;d<N;d++){
				int p1 = st-d;
				int p2 = st+1+d;
				if(p1 < 0 || p2 >= len) break;
				if(s[p1] == s[p2])
					cnt++;
			}
			ans = max(ans, cnt);
		}
		cout << ans << "\n";
	}

	return 0;
}

/*
05:20 Problem Anaylsis.
12:59 TC passed.
240519 13:02
*/