#include<bits/stdc++.h>
using namespace std;

bool solution(string s)
{
	stack<char> S;
	int N = s.size();
	for(int i=0;i<N;i++){
		char cur = s[i];
		if(cur == '(')
			S.push(cur);
		else{
			if(S.empty())
				return false;
			else
				S.pop();
		}
	}
	if(!S.empty()) return false;
	return true;
}

/*
05:58 solution Completed.
07:03 if(!S.empty()) return false; 삽입.
240423 07:10
*/