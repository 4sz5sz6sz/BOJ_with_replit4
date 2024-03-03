#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while(T--){

		int ansPos=101;
		int ansLen=-1;
		bool isodd;
		string s;
		cin >> s;

		if(s.size()==1){
			cout << s[0] << "\n";
			continue;
		}

		//홀수개만 탐색
		for(int i=s.size()-1;i>=s.size()/2+1-1;i--){
			int l = i;
			int r = i;
			while(s[l]==s[r]){
				l--; r++;
				if(l<0) break;
				if(r>=s.size()) break;
			}
			if(r<s.size()) continue;
			int curPos = l+1;
			int curLen = (r-1) - (l+1) + 1;

			if(curLen > ansLen){
				ansLen = curLen;
				ansPos = curPos;
				isodd = true;
			}
		}

		//짝수개만 탐색
		for(int i=s.size()-1;i>=(s.size()+3)/2-1;i--){
			//ABBAB일때 문제생김. 1 2부터 l r 탐색.
			int l = i-1;
			int r = i;
			while(s[l]==s[r]){
				l--; r++;
				if(l<0) break;
				if(r>=s.size()) break;
			}
			if(r<s.size()) continue;
			int curPos = l+1;
			int curLen = (r-1) - (l+1) + 1;

			if(curLen > ansLen){
				ansLen = curLen;
				ansPos = curPos;
				isodd = true;
			}
		}
		// cout << "	ansPos:	" << ansPos;
		// cout << "	ansLen:	" << ansLen;
		for(int i=0;i<s.size();i++){
			cout << s[i];
		}
		for(int i=ansPos-1;i>=0;i--){
			cout << s[i];
		}
		cout << "\n";
	}
	
	return 0;
}



/*
33:30 문제 분석
39:00 첫 컴파일
41:15 테스트 케이스 오답..
45:23
	if(curLen < ansLen){
	에서
	if(curLen > ansLen){
	로 수정.
46:19 테스트 케이스 통과

21% 틀렸습니다..

반례 발견.
ABBAB 입력 시, ABBAB 출력됨..

52:30
	for(int i=s.size()-1;i>=0;i--){
	에서
	for(int i=s.size()-1;i>=s.size()/2+1;i--){
	로 수정.

01:02:59
	for(int i=s.size()-1;i>=(s.size()+3)/2;i--){
	삽입.
01:04:56 테스트 케이스 통과

01:09:50 if(r<s.size()) continue; 삽입
반례 발견
	ABCBB -> ABCBBA 출력

240228 01:10:41

*/