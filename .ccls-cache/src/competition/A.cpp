#include<bits/stdc++.h>
using namespace std;

int isused[30];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	string s;
	cin >> N >> s;
	//unordered_map<string,int> m;

	//step 1
	int cnt=0;

	string s2;
	for(int i=0;i<s.size();i++){
		char ch = s[i];
		if(!isused[ch-'a']){
			isused[ch-'a'] = 1;
			s2.push_back(ch);
		}
		else{
			cnt++;
		}
	}
	//cout << s2 << "\n";

	//step 2
	s2+=to_string(cnt+4);

	//step 3
	string s3 = to_string(N+1906);
	s3+=s2;

	reverse(s3.begin(),s3.end());

	string s4 = "smupc_";
	s4+=s3;

	cout << s4 << "\n";
	
	return 0;
}

/*
06:50 main() Completed.
09:25 TC passed.
240518 
*/