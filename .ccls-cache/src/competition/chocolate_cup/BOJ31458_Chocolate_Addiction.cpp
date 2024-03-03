#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while(T--){
		int numL=0;
		int numR=0;
		int input;
	
		string s;
		cin >> s;
		int flag=0;
		for(int i=0;i<s.size();i++){
			if(s[i]!='!'){
				input = s[i]-'0';
				flag=1;
				continue;
			}
			if(flag==0) numL++;
			else numR++;
		}
	
		if(numR > 0) input=1;
	
		if(numL&1) input^=1;
	
		cout << input << "\n";
	}
	
	return 0;
}

/*
06:49 문제 분석
11:14 첫 컴파일
14:31 테스트 케이스 통과
240301 14:37
*/