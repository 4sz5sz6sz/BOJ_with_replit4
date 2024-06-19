#define IDX_MAX 200007
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	string s;
	cin >> s;

	int len = s.size();
	int S[26][IDX_MAX];

	for(int ch = 0;ch<=25;ch++){
		if(s[0] == 'a'+ch)
			S[ch][0]=1;
		for(int i=1;i<len;i++){
			S[ch][i] = S[ch][i-1];
			if(s[i] == 'a'+ch)
				S[ch][i]++;
		}
	}
	
	
	cin >> N;
	for(int i=0;i<N;i++){
		char c;
		int ch,l,r;
		cin >> c >> l >> r;
		ch = c-'a';

		int ans = S[ch][r];
		if(l>0)
			ans-=S[ch][l-1];
		cout << ans << "\n";
	}
	
	return 0;
}



/*
01:16 Problem Analysis.
13:45
240619 13:48
*/