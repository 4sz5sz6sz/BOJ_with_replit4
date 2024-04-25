#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int b, int y) {
	vector<int> ret;
	int sum = b+y;
	for(int i=1;i<=sqrt(sum);i++){
		if(sum % i == 0){
			int j = sum / i;
			if(2*(i+j-2) == b){
				ret.push_back(j);
				ret.push_back(i);
				break;
			}
		}
	}
	
	return ret;
}

/*
09:19 Problem Analysis.
12:26 solution() Completed.
240424 
*/