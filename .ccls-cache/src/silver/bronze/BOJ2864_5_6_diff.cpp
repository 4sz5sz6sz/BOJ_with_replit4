#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string a,b;
	string A5,B5;
	string A6,B6;

	cin >> a >> b;
	A6 = A5 = a;
	B6 = B5 = b;
	for(int i=0;i<a.size();i++){
		if(a[i]=='5'){
			A6[i]='6';
		}
		else if(a[i]=='6'){
			A5[i]='5';
		}
	}
	for(int i=0;i<b.size();i++){
		if(b[i]=='5'){
			B6[i]='6';
		}
		else if(b[i]=='6'){
			B5[i]='5';
		}
	}

	int ans1 = stoi(A5) + stoi(B5);
	int ans2 = stoi(A6) + stoi(B6);
	cout << ans1 << " " << ans2 << "\n";
	
	return 0;
}

/*
240504 04:33

*/