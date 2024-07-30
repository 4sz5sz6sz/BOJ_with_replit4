#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	cin.ignore();
	for(int i=1;i<=N;i++){
		string s;
		getline(cin,s);

		cout << i << ". " << s << "\n";
	}
	
	return 0;
}

/*
01:37 Problem Analysis.
03:31 main() Completed.
240730 03:37
*/