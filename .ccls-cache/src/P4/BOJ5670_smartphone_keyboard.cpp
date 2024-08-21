//#define IDX_MAX 100000*80+5
#define IDX_MAX 1000000+5
#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
int nxt[IDX_MAX][26];
int chk[IDX_MAX];

int N;
int ROOT = 1;
int unused = 2;

void Init();
void insert(string &s);
int c2i(char c);
int find(string &s);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << fixed;
	cout.precision(2);
	while(cin >> N){
		Init();
		int ans=0;
		vector<string>input(N);
		
		for(int i=0;i<N;i++){
			cin >> input[i];
			insert(input[i]);
		}

		for(int i=0;i<N;i++){
			string cur = input[i];
			int ret = find(cur);
			ans += ret;
			// cout << "\n";
			// cout << "	ret : " << ret;
			// cout << "\n\n";
		}
		// cout << "\n";

		cout << ans*1.0/N << "\n";
	}
	
	return 0;
}

void insert(string &s){
	int cur = ROOT;
	for(char c:s){
		if(nxt[cur][c2i(c)] == -1)
			nxt[cur][c2i(c)] = unused++;
		cur = nxt[cur][c2i(c)];
	}
	chk[cur] = true;
}

int find(string &s){
	int ret = 1;
	int cur = ROOT;
	// cout << "			s : " << s;
	// cout << "\n";
	for(int idx=0;idx<s.size();idx++){
		char c = s[idx];
		// cout << "		c : " << c;
		// cout << "\n";
		int cnt=0;
		for(int j=0;j<26;j++){
			if(idx==0) break;
			if(nxt[cur][j] != -1){
				// cout << "	next : " << (char)(j+'a');
				// cout << "\n";
				cnt++;
			}
		}
		if(chk[cur]) cnt++;
		if(nxt[cur][c2i(c)] == -1)
			return 0;	//return false;
		if(cnt>1) ret++;
		cur = nxt[cur][c2i(c)];
	}
	return ret;
}

void Init(){
	for(int i=0;i<IDX_MAX;i++)
		fill(nxt[i],nxt[i]+26,-1);
	fill(chk,chk+IDX_MAX,false);
	unused = 2;
}

int c2i(char c){
	return c-'a';
}

/*
04:46 Problem Analysis.
12:42 main() Completed.

04:51 insert() Completed.
07:58 find() Completed.
10:03 WA...
30:13 if(chk[cur]) cnt++; 추가.
31:01 TC passed.
33:05 MLE...
36:28 IDX_MAX 값을 100000*80+5에서 1000000+5로 수정.
240820 12:42 + 36:40
*/