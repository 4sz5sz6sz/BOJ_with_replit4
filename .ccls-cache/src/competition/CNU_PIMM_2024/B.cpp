#include<bits/stdc++.h>
using namespace std;

string s[27][27][27];
int cnt[27][27][27];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	cin >> N >> M;
	
	for(int i=0;i<N;i++){
		int num;
		string str;
		char c[7];
		cin >> num >> str;
		for(int j=0;j<7;j++){
			cin >> c[j];
		}

		s[c[0]-'A'][c[1]-'A'][c[2]-'A'] = str;
		cnt[c[0]-'A'][c[1]-'A'][c[2]-'A']++;
	}

	for(int i=0;i<M;i++){
		char c[3];
		for(int j=0;j<3;j++){
			cin >> c[j];
		}
		int result = cnt[c[0]-'A'][c[1]-'A'][c[2]-'A'];
		if(result == 0)
			cout << "!\n";
		else if(result >= 2)
			cout << "?\n";
		else
			cout << s[c[0]-'A'][c[1]-'A'][c[2]-'A'] << "\n";
	}
	
	return 0;
}

/*
06:08 문제 분석
15:35 테스트 케이스 통과
240310
*/