#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	while(N--){
		string s;
		cin >> s;
		int len = s.length();
		for(int i=0;i<len;i++){
			if(s[i]<='Z'){
				s[i]=s[i]-'A'+'a';
			}
			cout << s[i];
		}
		cout << "\n";
	}
	
	return 0;
}

/*
02:39 main() Completed
240404 03:53
*/