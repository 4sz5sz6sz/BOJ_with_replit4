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
		int len = s.size();
		if(len >= 6 && len <= 9){
			cout << "yes\n";
		}
		else
			cout << "no\n";
	}
	
	return 0;
}

/*
240630 01:50
*/