#define IDX_MAX 10000000
#include<bits/stdc++.h>
using namespace std;

int N,M;
int ans;
vector<int> isused;
string arr;
string input;
vector<int> isprime(IDX_MAX+1,1);

void Backtracking(int depth);
void Eratosthenes();

int solution(string numbers){
	N = numbers.size();
	isused.resize(N);

	for(int i=0;i<N;i++){
		input[i] = numbers[i];
	}

	Eratosthenes();

	for(M=1;M<=N;M++){
		Backtracking(0);
	}
	
	int ret = ans;
	return ret;
}

void Backtracking(int depth){
	if(depth >= M){
		int number = stoi(arr);
		if(isprime[number]==1){
			ans++;
			isprime[number]++;	//중복 방지.
		} 
		return ;
	}

	for(int i=0;i<N;i++){
		if(!isused[i]){
			if(input[i] == '0' && depth==0) continue;	//첫자리가 0이면 pass.
			isused[i] = 1;
			arr.push_back(input[i]);
			Backtracking(depth+1);
			isused[i] = 0;
			arr.pop_back();
		}
	}
}

void Eratosthenes(){
	isprime[1] = 0;
	for(int i=2;i<=sqrt(IDX_MAX);i++){
		for(int j=i*i;j<=IDX_MAX;j = j + i){
			isprime[j] = 0;
		}
	}
}

/*
02:35 Problem Analysis.
06:27 solution() Completed.
15:08 Backtracking() Completed.
17:45 Eratosthenes() Completed.
24:09 core dump.. segmentation fault error 발생..
27:36 중복 방지 코드 작성.

240423 28:15
*/