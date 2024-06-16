#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for(int loop=0;loop<T;loop++){
		int N;
		int sum=0;
		int ans=0;
		string s;

		cin >> N;
		cin >> s;
		vector<int> arr(N+1);
		
		for(int i=0;i<=N;i++){
			arr[i] = s[i]-'0';
		}
		
		for(int curIdx=0;curIdx<=N;curIdx++){
			if(arr[curIdx] != 0 && sum < curIdx){
				ans+=curIdx-sum;
				//arr[curIdx] -= curIdx-sum;
				sum+=curIdx-sum;
			}
			sum+=arr[curIdx];
			// cout << "	ans : " << ans;
			// cout << "	sum : " << sum;
			// cout << "\n";
		}

		cout << "Case #" << loop+1 << ": " << ans << "\n";
	}
	
	return 0;
}

/*
13:33 Problem Analysis.
29:28 main() Completed.
240616 29:36
*/