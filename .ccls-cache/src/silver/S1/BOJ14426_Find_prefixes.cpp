#define IDX_MAX 10000*500+5
#include <bits/stdc++.h>
using namespace std;

int nxt[IDX_MAX][26];
//int chk[IDX_MAX][26];
int ROOT = 1;
int unused = 2;

void insert(string &s);
bool find(string &s);
int c2i(char c);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	cin >> N >> M;

	for(int i=0;i<IDX_MAX;i++)
		fill(nxt[i],nxt[i]+26,-1);

	while(N--){
		string s;
		cin >> s;
		insert(s);
	}

	int ans=0;
	
	while(M--){
		string s;
		cin >> s;
		if(find(s))
			ans++;
	}

	cout << ans << "\n";
	
	return 0;
}

void insert(string &s){
	int cur = ROOT;
	for(char c:s){
		if(nxt[cur][c2i(c)] == -1)
			nxt[cur][c2i(c)] = unused++;
		cur = nxt[cur][c2i(c)];
	}
	//chk[cur] = true;
}

bool find(string &s){
	int cur = ROOT;
	for(char c:s){
		if(nxt[cur][c2i(c)] == -1)
			return false;
		cur = nxt[cur][c2i(c)];
	}
	return true;
}

int c2i(char c){
	return c - 'a';
}


/*
01:58 Problem Analysis.
31:20 TC passed.
240820 31:23
*/