#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;
	int len = s.size();
	

	for(int i=0;i<len;i++){
		if(s[i] <= 'Z')
			s[i] = s[i]-'A'+'a';
		else
			s[i] = s[i]-'a'+'A';
	}

	cout << s << "\n";
	
	return 0;
}

/*
02:03
240704
*/