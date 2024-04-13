#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	string exp;
	string ans;

	cin >> s;
	cin >> exp;

	int len = exp.length();
	int s_len = s.length();
	
	for(int i=0;i<s_len;i++){
		ans.push_back(s[i]);
		//cout << s[i] << "@@\n";
		if(s[i] == exp[len-1]){
			int flag=0;
			for(int j=0;j<len;j++){
				if(exp[len-1-j] == ans[ans.length()-1-j])
					continue;
				else{
					flag=1;
					break;
				}
			}
			if(flag==0){
				for(int j=0;j<len;j++)
					ans.pop_back();
			}
		}
	}

	if(ans.length() == 0)
		cout << "FRULA\n";
	else
		cout << ans << "\n";
	
	return 0;
}

/*
53:07 Problem Analysis.
01:00:57 main() Completed

01:02:07
	mirkovnizCC44
	로 출력되는 현상 발생..
01:05:11
	if(exp[len-1-j] == ans[i-1-j])
	에서
	if(exp[len-1-j] == ans[ans.length()-1-j])
	로 수정.

01:05:26 TC passed.
	
240413 01:05:32
*/