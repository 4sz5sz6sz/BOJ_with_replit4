#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<int> arr(26);
	int _max = 0;
	string s;
	while(cin >> s){
		//if(s=="zzz") break;
		for(char cur:s){
			arr[cur-'a']++;
			if(arr[cur-'a'] > _max)
				_max = arr[cur-'a'];
		}
	}

	for(int i=0;i<26;i++){
		if(arr[i]==_max)
			cout << (char)('a'+i);
	}
	
	return 0;
}

/*
03:26
240621 
*/