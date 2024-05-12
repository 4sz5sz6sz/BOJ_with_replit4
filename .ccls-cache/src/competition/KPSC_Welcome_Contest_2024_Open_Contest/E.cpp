#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	cin >> N >> M;
	string s;
	cin >> s;
	for(int Q=0;Q<M;Q++){
		int comm,l,r;
		cin >> comm >> l >> r;
		l--; r--;
		if(comm == 1){
			int cnt=1;
			for(int i=l+1;i<=r;i++){
				if(s[i] != s[i-1])
					cnt++;
			}
			cout << cnt << "\n";
		}
		else{
			for(int i=l;i<=r;i++){
				s[i]++;
				if(s[i] == 'Z' + 1)
					s[i] = 'A';
			}
		}
		//cout << "	s : " << s << "\n";
	}
	
	return 0;
}

/*
06:31 Problem Analysis.
09:22 main() Completed.
11:14 TC passed.
240512 11:26
*/