#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int N,M;
ll mid;
ll sum;
vector<int> arr;

bool Screen();

long long solution(int n, vector<int> times) {
	N = n;
	M = (int)times.size();
	arr = times;
	sort(arr.begin(),arr.end());
	//ll _max=arr[0];
	for(int i=0;i<M;i++){
		sum += arr[i];
	}
	
	ll st = M;
	//ll st = ceil(N*1.0/M);
	//ll en = sum*M;
	ll en = 1000000000ll * M;
	while(st<=en){
		mid = (st+en)/2;
		if(Screen())	//성공
			en = mid-1;
		else
			st = mid+1;
	}
	return st;
}

bool Screen(){
	ll cnt=0;
	for(int i=0;i<M;i++){
		cnt+=(mid / arr[i]);
		if(cnt >= N) break;
	}
	return cnt >= N;
}

/*
11:01 Problem Analysis.
14:52 solution() Completed.
15:54 Screen() Completed.
16:12 TC passed.
TLE..

33:22 자정.. 잠정 중단..

240424 재개..
11:43
int mid를 ll mid로 고침.
바로 정답!!

240423 33:22+11:43
*/