#include<bits/stdc++.h>
using namespace std;
int sum[2];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int tmp;
		cin >> tmp;
		sum[0]+= tmp;
	}
	for(int i=0;i<N;i++){
		int tmp;
		cin >> tmp;
		sum[1]+= tmp;
	}
	cout << sum[1] << " " << sum[0];
	return 0;
}

/*
06:02 문제 분석
240303 
*/