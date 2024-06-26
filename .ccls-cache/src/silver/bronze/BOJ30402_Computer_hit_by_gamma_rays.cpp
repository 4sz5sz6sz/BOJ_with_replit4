#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string ans;
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			char ch;
			cin >> ch;
			if(ch == 'w')
				ans = "chunbae";
			else if(ch == 'b')
				ans = "nabi";
			else if(ch == 'g')
				ans = "yeongcheol";
		}
	}

	cout << ans << "\n";
	
	return 0;
}

/*
03:50 main() Completed.
240626
*/