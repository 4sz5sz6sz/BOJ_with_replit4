#define IDX_MAX 2007
#include<bits/stdc++.h>
using namespace std;

vector<int> parent(IDX_MAX,-1);
vector<int> vis(IDX_MAX);
unordered_map<string,int> myGroup;
int numOfGroup=1;

int find(int a);
void munion(int a, int b);
bool CheckSame(int a, int b);
void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	
	myGroup["ChongChong"]=1;
	vis[1] = 1;
	int N;
	cin >> N;
	while(N--){
		string s1, s2;
		cin >> s1 >> s2;
		if(myGroup[s1]==0){
			myGroup[s1]=++numOfGroup;
		}
		if(myGroup[s2]==0){
			myGroup[s2]=++numOfGroup;
		}
		int a = myGroup[s1];
		int b = myGroup[s2];
		if(a>b) swap(a,b);
		if(find(a) == find(1) || find(b) == find(1)){
			munion(a,b);
			vis[a]=1;
			vis[b]=1;
		}
	}

	//int ans = find(myGroup["ChongChong"]);
	//cout << -parent[ans] << "\n";
	//ShowArr();
	int ans=0;
	for(int i=1;i<=numOfGroup;i++){
		if(vis[i])
			ans++;
	}
	cout << ans << "\n";
	
	return 0;
}

int find(int a){
	if(parent[a] < 0)
		return a;
	return parent[a] = find(parent[a]);
}
void munion(int a, int b){
	a = find(a);
	b = find(b);
	if(CheckSame(a,b)) return;
	parent[a] += parent[b]; 
	parent[b] = a;
}
bool CheckSame(int a, int b){
	return find(a) == find(b);
}

void ShowArr(){
	for(int i=1;i<=numOfGroup;i++){
		cout << "	i : " << i;
		cout << "	vis[i] : " << vis[i];
		cout << "	parent[i] : " << parent[i];
		cout << "\n";
	}
}



/*
03:45 Problem Analysis.
08:56 main() Completed.
11:58 Fucntion 3 Completed.
19:53 TC passed.
21:05 visit 삭제.
22:27 IDX_MAX 1001에서 2007로 상향
24:29 parent[ans] 삭제, vis[] 카운트해서 답하기.
31:23 ShowArr() 구현.

14
bnb2011 chansol
chansol chogahui05
jthis ChongChong
jthis jyheo98
jyheo98 lms0806
lms0806 pichulia
pichulia pjshwa
pjshwa r4pidstart
r4pidstart swoon
swoon tony9402
tony9402 bnb2011
aa bb
tony9402 tt
tt bb

-> 12


39:26
find(a) == 1에서 find(a) == find(1)로 변경.

애초에 유니온파인드가 필요없음...

240722 39:38
*/