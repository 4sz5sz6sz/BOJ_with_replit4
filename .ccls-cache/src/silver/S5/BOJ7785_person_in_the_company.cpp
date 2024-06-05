#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	unordered_map<string,int> m;
	int N;
	cin >> N;
	while(N--){
		string s1,s2;
		cin >> s1 >> s2;
		if(s2 == "enter"){
			m[s1] = 1;
		}
		else{
			m.erase(s1);
			//m[s1] = 0;
		}
	}

	unordered_map<string,int>::iterator iter;
	vector<string> arr;
	for(iter = m.begin(); iter!=m.end();iter++){
		arr.push_back(iter->first);
	}

	sort(arr.begin(),arr.end(),greater<string>());
	for(string cur:arr){
		cout << cur << "\n";
	}
	
	return 0;
}

/*
09:45
240605
*/