#define IDX_MAX (10001*10)
#include<bits/stdc++.h>
using namespace std;

int N;
int ROOT = 1;
int unused=2;
vector<string> arr;
int nxt[IDX_MAX][10];
int chk[IDX_MAX];

void Init();
void insert(string &s);
int find(string &s);
int c2i(char c);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		cin >> N;
		Init();
		for(int i=0;i<N;i++){
			string s;
			cin >> s;
			arr.push_back(s);
			insert(s);
		}
		bool ans=false;
		for(string s:arr){
			if(find(s))
				ans = true;
		}
		if(!ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
	return 0;
}

void Init(){
	arr.clear();
	unused = 2;
	for(int i=0;i<IDX_MAX;i++)
		fill(nxt[i],nxt[i]+10,-1);
	for(int i=0;i<IDX_MAX;i++)
		chk[i]=false;
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

int find(string &s){	//검색 기능이 아니라, 접두사 갯수 찾는 함수.
	int cur = ROOT;
	int cnt=0;
	for(char c:s){
		if(nxt[cur][c2i(c)] == -1)
			return false;
		if(chk[cur]) cnt++;
		cur = nxt[cur][c2i(c)];
	}
	return cnt;
}

int c2i(char c){
	return c-'0';
}


/*
01:00 Problem Analysis.
04:49 main() Completed.
07:46 Init() Completed.
10:39 insert() Completed.
14:04 find() Completed.
16:53 TC passed.
240824 16:57
*/