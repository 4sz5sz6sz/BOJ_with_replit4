#define BIG_NUM 11111111111111111ll
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		ll N,K;
		cin >> N >> K;
		vector<ll> ans;
		for(ll mask = BIG_NUM;mask;){
			ll cnt = K/mask;
			// cout << "	K :" << K;
			// cout << "	mask :" << mask;
			// cout << "	cnt :" << cnt;
			// cout << "\n";
			if(cnt==0){
				mask/=10;
				continue;
			}
			
			if(cnt>=10){ //예외처리
				cnt=9;
				ans.push_back(mask * cnt);
				K-=mask*cnt;
			}
			else{
				ans.push_back(mask * cnt);
				K-=mask*cnt;
				mask/=10;
			}
		}
		cout << ans.size() << "\n";
		for(ll cur:ans)
			cout << cur << " ";
		cout << "\n";
	}
	
	return 0;
}

/*
10:00 Problem Analysis.
14:00 main() Completed.
16:00 TC passed.
30:00 예외처리 완료.
240511 30:00
*/