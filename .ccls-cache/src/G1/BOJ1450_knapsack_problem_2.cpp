#define IDX_MAX 101
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N,C;
vector<ll> input;
// vector<ll> tmpinput;
vector<vector<ll>> v(2);
int arr[IDX_MAX];
int isused[IDX_MAX];

void Backtracking(int cur, int st, int en, int mode);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> C;
	for(int i=0;i<N;i++){
		ll num;
		cin >> num;
		input.push_back(num);
	}

	sort(input.begin(),input.end());

	Backtracking(0,0,N/2,0);
	Backtracking(0,N/2,N,1);

	sort(v[0].begin(),v[0].end());
	sort(v[1].begin(),v[1].end());

	ll ans=0;
	int j=v[1].size()-1;
	for(int i=0;i<v[0].size();i++){
		for(;j>=0;j--){
			// cout << "	i : " << i;
			// cout << "	j : " << j;
			// cout << "\n";
			if(v[0][i] + v[1][j] <= C){
				ans+=(j+1);
				break;	//i++;
			}
		}
		//ans+=(j+1);
	}

	cout << ans << "\n";
	
	return 0;
}

void Backtracking(int cur, int st, int en, int mode){
	int maxDepth = en - st;
	if(cur >= maxDepth){
		ll sum=0;
		for(int i=st;i<en;i++){
			if(arr[i])
				sum+=input[i];
		}
		v[mode].push_back(sum);
		// cout << "	sum : " << sum << "\n";
		return;
	}

	arr[st+cur]=1;
	Backtracking(cur+1, st, en, mode);
	arr[st+cur]=0;
	Backtracking(cur+1, st, en, mode);

	/*
	for(int i=st;i<en;i++){
		if(cur == 0 || arr[cur-1] < input[i]){
			arr[cur] = input[i];
			Backtracking(cur+1, st, en, mode);
		}
	}
	*/
	// cout << "	mode : " << mode << "\n";
}

/*
26:39 Problem Analysis.
39:49 main() Completed.
55:34 Backtracming() Completed.
백트래킹으로 0 또는 1의 값을 가지도록 해야함.
01:18:10 TC passed.
WA...
무게에서 int 오버플로우 난 듯.

240808 01:21:24
*/