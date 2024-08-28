#define NUM first
#define COUNT second
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> Node;
stack<Node> S;
vector<ll> input;
ll ans=0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		ll num;
		cin >> num;
		input.push_back(num);
	}

	for(int i=0;i<N;i++){
		ll cur = input[i];
		// cout << "	i :	" << i;
		// cout << "	cur :	" << cur;
		// cout << "	ans :	" << ans;
		// if(!S.empty())
		// 	cout << "	S.top().NUM :	" << S.top().NUM;
		// cout << "\n";
		while(1){
			if(S.empty()){
				S.push({cur,1});
				break;
			}
			else if(cur == S.top().NUM){
				ans+= S.top().COUNT;
				S.top().COUNT++;
	
				Node tmp = S.top(); S.pop();
				if(!S.empty())
					ans++;
				S.push(tmp);
				break;
			}
			else if(cur < S.top().NUM){
				//ans+=S.top().COUNT;
				ans++;
				S.push({cur,1});
				break;
			}
			else{
				ans += S.top().COUNT;
				S.pop();
			}
		}
	}

	cout << ans << "\n";
	return 0;
}

/*
13:38 Problem Analysis.
21:25 main() Completed.
25:58 TC passed.
28:39 13% WA...
32:50 반례 발견.
5
5 4 5 4 5
output : 8
ans : 7

36:51
//ans+=S.top().COUNT;
에서
ans++로 변경.

240828 36:55
*/