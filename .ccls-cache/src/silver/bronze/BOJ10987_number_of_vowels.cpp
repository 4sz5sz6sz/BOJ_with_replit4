#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string vow = "aeiou";

	string s;
	cin >> s;
	int N = s.size();
	int ans=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<(int)vow.size();j++){
			if(s[i] == vow[j])
				ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}

/*
01:57
240628
*/