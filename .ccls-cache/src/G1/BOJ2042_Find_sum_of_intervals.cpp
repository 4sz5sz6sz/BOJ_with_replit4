#define IDX_MAX 1000000
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL BIT[IDX_MAX+1];
LL arr[IDX_MAX+1];

void add(int idx, LL val);
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
			add(b,c-arr[b]);
			arr[b] = c;
		}
		else if(a==2){
			cout << sum(c) - sum(b-1) << "\n";
		}
	}
	
	return 0;
}

void add(int idx, LL val){
	while(idx<=IDX_MAX){
		BIT[idx] += val;
		idx += (idx & -idx);
	}
}

LL sum(int idx){
	LL s=0;
	while(idx>0){
		s+=BIT[idx];
		idx -= (idx & -idx);
	}
	return s;
}

/*
04:15 main() 작성 완료.
06:51 함수 2개 작성 완료.

240302 07:20
*/