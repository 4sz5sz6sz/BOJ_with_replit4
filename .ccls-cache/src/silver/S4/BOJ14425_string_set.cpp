#define NUM_CHAR 26
#define IDX_MAX 10000*500+4
#include<bits/stdc++.h>
using namespace std;

//typedef pair<int,int> Node;
// vector<vector<int>> tree;
// vector<int> chk;
int tree[IDX_MAX][NUM_CHAR];
int chk[IDX_MAX];

int ROOT = 1;
int unused = 2;

void Insert(string &s);
bool find(string &s);
int c2i(char c);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M;
	cin >> N >> M;
	// tree.resize(N*500*+5,vector<int>(NUM_CHAR,-1));
	// chk.resize(N*500+5);
	for(int i=0;i<IDX_MAX;i++)
		fill(tree[i],tree[i]+NUM_CHAR,-1);
			
	while(N--){
		string s;
		cin >> s;
		Insert(s);
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

void Insert(string &s){
	int cur = ROOT;
	for(char c:s){
		if(tree[cur][c2i(c)] == -1)
			tree[cur][c2i(c)] = unused++;
		cur = tree[cur][c2i(c)];
	}
	chk[cur] = true;
}

bool find(string &s){
	int cur = ROOT;
	for(char c:s){
		if(tree[cur][c2i(c)] == -1)
			return false;
		cur = tree[cur][c2i(c)];
	}
	return chk[cur];
}

int c2i(char c){
	return c-'a';
}


/*
03:58 main() Completed.
12:56 Set golobal variable
30:34 2 function completed.
41:00 tree를 -1로 초기화.
42:24 tree를 N*500*26*4개로 초기화.
42:36 TC passed.
51:14 vector에서 배열로 변경.
240820 51:19
*/