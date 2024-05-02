#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// char ch[2] = {'I', 'O'};
	int ans=0;
	int N,M;
	string s;
	cin >> N;
	cin >> M;

	cin >> s;

	int size=0;
	for(int i=0;i<M;i++){
		char target = (size % 2 == 0) ? 'I' : 'O';
		// if(size%2 == 0) target = 'I';
		// else target = 'O';

		if(s[i] == target)
			size++;
		else{
			int numO = (size-1)/2;
			int cnt = numO - N + 1;
			if(cnt>0)
				ans+=cnt;
			size = (s[i] == 'I');	//새로운 시작
		}
		// cout << "	s[i] == target : " << (s[i] == target);
		// cout << "	size : " << size;
		// cout << "\n";
	}
	if(size>0){
		int numO = (size-1)/2;
		int cnt = numO - N + 1;
		if(cnt>0)
			ans+=cnt;
	}
	cout << ans << "\n";
	
	return 0;
}

/*
20:29 Problem Analysis.
30:00 main() Completed.
30:42 TC passed.
WA..

char target = (size % 2) ? 'O' : 'I';
에서
char target = (size % 2 == 0) ? 'I' : 'O';
로 변경..

36:00 반례
1 3 IOI -> 0
size가 3인 경우에서 끝나면, (=target이 올바른 상태에서 순회가 끝나면) 그 size값이 ans에 더해지지 않는 현상 fix.

if(size>0)을 for문 밖에 추가.

1 3 IOI라고 줄바꿈 없이 한줄에 다 쓰면 의도와 다른 결과 출력됨. 뭐지?

39:26 TC passed.
240502 39:26
*/