#include <string>
#include <vector>
#include<unordered_map>

using namespace std;
int N,M;
int cnt;
string arr;
string input = "AEIOU";
unordered_map<string,int> word_myIndex;

void Backtracking(int cur);

int solution(string word) {
	M = N = 5;
	Backtracking(0);
	return word_myIndex[word];
}

void Backtracking(int cur){
	if(cur>=M){
		return;
	}
	for(int i=0;i<5;i++){
		arr.push_back(input[i]);
		word_myIndex[arr]=++cnt;
		Backtracking(cur+1);
		arr.pop_back();
	}
}