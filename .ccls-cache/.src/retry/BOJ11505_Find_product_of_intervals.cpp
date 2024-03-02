#define IDX_MAX 1000000
#define MOD 1000000007
#include<bits/stdc++.h>
using namespace std;

typedef long double LD;
typedef long long LL;
LL BIT[IDX_MAX+1];
LL arr[IDX_MAX+1];

void add(int idx,LD val);
LL sum(int idx);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,M,K;
	cin >> N >> M >> K;

	for(int i=1;i<=N;i++){
		cin >> arr[i];
		add(i,arr[i]);
	}

	for(int i=0;i<M+K;i++){
		LL a,b,c;
		cin >> a >> b >> c;
		if(a==1){
			add(b,(LD)c/arr[b]);
			arr[b] = c;
		}
		else if(a==2){
			cout << (LD)sum(c) / sum(b-1) << "\n";
		}
	}
	
	return 0;
}

void add(int idx,LD val){
	while(idx<=IDX_MAX){
		BIT[idx]=(BIT[idx]*val)%MOD;
		idx+=(idx&-idx);
	}
}

LL sum(int idx){
	LL s = 1;
	while(idx>0){
		s=(s*BIT[idx])%MOD;
		idx-=(idx&-idx);
	}
	return s;
}


/*
02:19 문제 분석
09:23 분모가 0인 경우는 어떻게 해결할 것인가?
35:41 포기..
240302 
*/