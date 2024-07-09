#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;
	int len = s.size();
	for(int i=len-1;i>=0;i--)
		cout << s[i];
	
	return 0;
}

/*
01:14
240705 02:13
*/