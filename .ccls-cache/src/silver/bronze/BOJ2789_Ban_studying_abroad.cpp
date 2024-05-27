#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string input;
	string s = "CAMBRIDGE";

	cin >> input;

	for(int i=0;i<input.size();i++){
		bool flag = true;
		for(int j=0;j<s.size();j++){
			if(input[i] == s[j])
				flag = false;
		}
		if(flag)
			cout << input[i];
	}
	
	return 0;
}

/*
04:32
240527
*/