#define IDX_MAX 5000001
#include<bits/stdc++.h>
using namespace std;

bool isprime[IDX_MAX];

int cntB,cntS;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	fill(isprime,isprime+IDX_MAX,true);
	isprime[1] = false;

	//에라토스테네스의 체
	for(int i=2;i<=sqrt(N);i++){
		for(int j=i*i;j<=N;j=j+i){
			isprime[j]=false;
		}
	}

	cntB = 0;
	cntS = 3;
	if(N==1) cout << "1 0\n";
	else if(N==2) cout << "0 2\n";
	else if(N==3) cout << "0 3\n";
	else{
		for(int cur=4;cur<=N;cur++){
			if(isprime[cur]){
				cntB--;
				cntS+=2;
			}
			else{
				cntB++;
			}
		}
		cout << cntB << " " << cntS << "\n";
	}
	
	return 0;
}

/*
08:14 Problem Analysis.
12:21 에라토스테네스의 체 Completed
14:30 main() Completed.
TC passed.

240316 18:43
*/