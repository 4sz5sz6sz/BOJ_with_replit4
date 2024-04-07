#define LOOP_MAX 100
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for(int loop=1;loop<=T;loop++){
		ll N;
		ll ans=0;
		cin >> N;
		vector<int> isused(10);
		if(N==0){
			cout << "Case #" << loop << ": ";
			cout << "INSOMNIA\n";
			continue;
		}

		int flag=0;
		
		for(int i=1;i<=LOOP_MAX;i++){	
			string s = to_string(N*i);
			for(int j=0;j<s.length();j++){
				isused[s[j]-'0'] = 1;
			}
			
			for(int j=0;j<=9;j++){
				if(isused[j] == 0) break;
				if(j==9){
					ans = N*i;
					flag = 1;
				} 
			}
			if(flag) break;
		}

		cout << "Case #" << loop << ": " << ans << "\n";
	}
	
	return 0;
}

/*
08:23 Problem Analysis.
19:53 main() Completed.
240407 20:19
*/