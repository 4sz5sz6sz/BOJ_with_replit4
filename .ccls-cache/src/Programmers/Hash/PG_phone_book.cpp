#include<bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
	//bool ret;
	int N = phone_book.size();
	sort(phone_book.begin(),phone_book.end());
	for(int i=0;i<N-1;i++){
		if(phone_book[i].size() < phone_book[i+1].size()){
			for(int j=0;j<phone_book[i].size();j++){
				if(phone_book[i][j] != phone_book[i+1][j]) break;
				if(j==phone_book[i].size()-1) return false;
			}
		}
	}

	/*
	for(int i=0;i<N;i++){
		cout << phone_book[i] << "\n";
	}
	*/
	
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<string> phone_book = {"119", "97674223", "1195524421"};
	cout << solution(phone_book);
	
	return 0;
}

/*
04:21 Problem Analysis.
07:56 solution() Completed.
14:05 2중 for문 내부의, 리턴 조건 변경.
14:24 TC passed.
240423 
*/