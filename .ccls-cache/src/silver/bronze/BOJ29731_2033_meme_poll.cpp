#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<string> s(7);
	s[0] = "Never gonna give you up";
	s[1] = "Never gonna let you down";
	s[2] = "Never gonna run around and desert you";
	s[3] = "Never gonna make you cry";
	s[4] = "Never gonna say goodbye";
	s[5] = "Never gonna tell a lie and hurt you";
	s[6] = "Never gonna stop";
	
	int N;
	int ans=0;
	//cin >> N;
	cin >> N;
	cin.ignore();
	for(int i=0;i<N;i++){
		string input;
		int flag = 0;
		getline(cin,input);
		//cin >> input;
		for(int j=0;j<7;j++){
			if(input == s[j])
				flag = 1;
		}

		if(flag==0)
			ans = 1;
	}

	if(ans)
		cout << "Yes\n";
	else
		cout << "No\n";
	
	return 0;
}

/*
04:55
10:21 TC pass
11:11 초깃값 ans=1에서 0으로 변경
240714 11:25
*/