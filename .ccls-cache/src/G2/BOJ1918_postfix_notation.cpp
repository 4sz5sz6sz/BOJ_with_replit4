#define OLD 0
#define NEW 1
#include<bits/stdc++.h>
using namespace std;

stack<char> S;
string str;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> str;
	int len = str.length();
	for(int i=0;i<len;i++){
		char cur = str[i];
		if('A' <= cur && cur <= 'Z'){
			cout << cur;
		}
		else if(cur == '('){
			S.push(cur);
		}
		else if(cur == ')'){
			while(!S.empty() && S.top() != '('){
				//cout << "0";
				cout << S.top();
				S.pop();
			}
			S.pop();
		}
		else{
			while(!S.empty()){
				char op[2];
				op[0] = S.top();
				op[1] = cur;
				int pri[2];
				for(int i=0;i<2;i++){
					if(op[i] == '+' || op[i] == '-')
						pri[i] = 2;
					else if(op[i] == '*' || op[i] == '/')
						pri[i] = 1;
					else
						pri[i] = 3;
				}
				if(pri[OLD] <= pri[NEW]){
					//if(S.top() != '(')
					cout << S.top();
					S.pop();
				}
				else
					break;
			} 
			S.push(cur);
		}
	}

	while(!S.empty()){
		//cout << "0";
		if(S.top() != '(')
			cout << S.top();
		S.pop();
	}
	
	return 0;
}

/*
06:38 Problem Analysis.
17:37 main() Completed.
28:12
	if(cur == '+' || cur == '-')
	에서
	if(op[i] == '+' || op[i] == '-')
	로 수정.
49:20 TC passed.
57:23
	else if(cur == ')'){
	...
		S.pop();

	S.pop() 추가.

	정답입니다!!
240412 57:23
*/