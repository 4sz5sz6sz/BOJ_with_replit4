#include<bits/stdc++.h>
using namespace std;

int cnt[10];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str;
	int N;
	cin >> str;
	N = str.length();

	for(int i=0;i<N;i++){
		int cur = str[i] - '0';
		cnt[cur]++;
	}

	int ans=0;
	
	for(int i=0;i<=9;i++){
		if(i==6 || i==9) continue;
		ans=max(ans,cnt[i]);
		//cout << "	i : " << i;
		//cout << "	cnt[i] : " << cnt[i] << "\n";
	}

	ans = max(ans,(cnt[6] + cnt[9] + 1)/2);

	cout << ans << "\n";
	
	return 0;
}

/*
어떤 숫자 등장할 때 마다 cnt[]에 기록.
단, 6과 9가 등장한 횟수는 묶어서 세준다.
(cnt[6] + cnt[9] + 1) / 2 가 하나의 숫자 등장횟수로 취급된다.

6과 9를 제외하고 ans에 최댓값 저장.

max() 연산해서 ans 최댓값으로 갱신
	ans과 (6,9 등장횟수 + 1) / 2

ans 출력.

04:04 Problem Analysis
07:45 main() Completed.
14:51 i=0부터 시작.
240403 14:56
*/