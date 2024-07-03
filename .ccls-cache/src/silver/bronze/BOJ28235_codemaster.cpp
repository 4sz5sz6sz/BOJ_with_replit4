#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str;
	cin >> str;

	string ans;
	if(str == "SONGDO")
		ans = "HIGHSCHOOL";
	else if(str == "CODE")
		ans = "MASTER";
	else if(str == "2023")
		ans = "0611";
	else
		ans = "CONTEST";

	cout << ans << "\n";
	
	return 0;
}

/*
02:07
240703
*/