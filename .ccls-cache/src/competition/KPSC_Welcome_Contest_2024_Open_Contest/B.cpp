#include<bits/stdc++.h>
using namespace std;

vector<string> arr;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string input;
	cin >> input;
	input = input.substr(0,5);
	int N;
	cin >> N;

	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		arr.push_back(s.substr(0,5));
	}

	int ans=0;
	for(int i=0;i<N;i++){
		if(arr[i] == input) ans++;
	}

	cout << ans << "\n";

	return 0;
}

/*
01:05 Problem Analysis
240512 
*/