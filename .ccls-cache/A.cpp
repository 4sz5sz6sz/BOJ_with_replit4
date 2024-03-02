#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s;
	getline(cin,s);

	//시작과 끝이 따옴표지만, 1글자인 경우
	if(s.size()<=1){
		cout << "CE\n";
		return 0;
	}

	//시작과 끝이 따옴표가 아님
	if(s[0] != '"' || s[s.size()-1] != '"'){
		cout << "CE\n";
		return 0;
	}

	//빈 문자열
	if(s[0]== '"' && s[1] == '"'){
		cout << "CE\n";
		return 0;
	}

	for(int i=1;i<=s.size()-2;i++){
		cout << s[i];
	}
	
	return 0;
}

/*
240302 03:14
*/