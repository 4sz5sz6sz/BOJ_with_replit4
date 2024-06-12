#define IDX_MAX 123456*8
#include<bits/stdc++.h>
using namespace std;

bool isprime[IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while(1){
		int N;
		cin >> N;
		if(N==0) break;
		fill(isprime,isprime+IDX_MAX,true);
		isprime[0] = false;
		isprime[1] = false;
		int ans=0;

		for(int i=2;i<=sqrt(2*N);i++){
			for(int j=i*i;j<=2*N;j=j+i){
				isprime[j] = false;
			}
		}

		for(int i=N+1;i<=2*N;i++){
			if(isprime[i]){
				//cout << "	i	:	" << i;
				ans++;
			}
				
		}

		cout << ans << "\n";
		
	}
	
	return 0;
}

/*
02:06 Problem Analysis.
05:39 main() Completed.
240612 10:35
*/