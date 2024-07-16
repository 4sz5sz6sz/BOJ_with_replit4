#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while(1){
		string s;
		getline(cin,s);
		if(s=="END")
			break;
		int len = s.size();
		for(int i=len-1;i>=0;i--){
			cout << s[i];
		}
		cout << "\n";
	}
	
	return 0;
}

/*
01:26 Problem Analysis.
240716 03:01
*/