#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> m;

bool cmp1(string a, string b){
	if(m[a] != m[b]) return m[a]>m[b];
	if(a.size() != b.size()) return a.size()>b.size();
	return a<b;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<string> arr;
	int N,M;
	cin >> N >> M;
	while(N--){
		string s;
		cin >> s;
		int len = s.size();
		if(len < M) continue;
		if(m[s]==0) 
			arr.push_back(s);
		m[s]++;		
	}

	sort(arr.begin(),arr.end(),cmp1);
	for(int i=0;i<arr.size();i++){
		cout << arr[i] << "\n";
	}
	
	return 0;
}

/*
01:49 Problem Analysis.
05:55 main() Completed.
10:13 cmp1 Completed.
240724 12:24
*/