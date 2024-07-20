#define BIG_NUM 0x3f3f3f3f3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		ll ans=0;
		ll N;
		cin >> N;
		if(N<=1) N=2;
		int flag = false;
		for(ll num=N;1;num++){
			flag=true;
			if(num > BIG_NUM) break;
			for(int i=2;i<=sqrt(num);i++){
				if(num%i==0) {
					flag=false;
					break;
				}
			}
			if(flag){
				ans = num;
				break;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}

/*
07:50 TC passed.
09:41 0 입력시 1 출력되는 현상 fix.
10:59 num = N+1에서 N으로 수정.
240720 11:55
*/