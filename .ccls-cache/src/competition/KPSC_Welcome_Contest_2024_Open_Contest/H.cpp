#define IDX_MAX 10
#include<bits/stdc++.h>
using namespace std;

int ans;
int N;
int M = 4;

//int arr[IDX_MAX];
string arr;
string isused = "MRDR";
unordered_map<string,int> m;

void Backtracking(int cur, int target);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;

	Backtracking(0,0);

	cout << ans;
	
	return 0;
}

void Backtracking(int cur, int target){
	if(cur >= N){
		if(target != M) return;
		if(m[arr]) return;
		m[arr]=1;
		ans++;
		return;
	}

	for(char ch = 'A';ch<='Z';ch++){
		arr.push_back(ch);
		if(target < 4 && ch == isused[target]){
			Backtracking(cur+1, target+1);
		}
		else
			Backtracking(cur+1, target);
		
		arr.pop_back();
	}
}

/*
15:00 구현 완료.
16:48 6 -> 9526 획득.

10140 - 중복 카운팅 = 9526
26*5 - 4H1 + 1 = 126

10140 - 
*/