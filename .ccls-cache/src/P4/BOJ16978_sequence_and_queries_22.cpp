#define IDX_MAX 100007
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef struct Query{
	ll k,l,r,index;
}Query;

ll tree[IDX_MAX*4];
vector<ll> ans;
vector<Query> qv[3];	//1-indexed

bool cmp1(struct Query &a, struct Query &b){
	return a.k < b.k;
}

ll update(int node, int st, int en, int idx, ll val);
ll query(int node, int st, int en, int l, int r);


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N,Q;
	cin >> N;


	for(int i=0;i<N;i++){
		ll num;
		cin >> num;
		update(1,1,N,i+1,num);
		//cout << query(1,1,N,1,N) << "\n";
	}

	cin >> Q;
	
	while(Q--){
		int comm;
		cin >> comm;
		if(comm == 1){
			ll idx, val;
			cin >> idx >> val;
			qv[1].push_back({val,0,0,idx});
		}
		else{
			ll val,l,r;
			cin >> val >> l >> r;
			qv[2].push_back({val,l,r,(ll)qv[2].size()});
		}
	}

	sort(qv[2].begin(),qv[2].end(),cmp1);
	ans.resize(qv[2].size());

	int curQ = 0;
	for(int i=0;i<=qv[1].size();i++){
		while(curQ < (int)qv[2].size() && qv[2][curQ].k == i){
			ans[qv[2][curQ].index] = query(1,1,N,qv[2][curQ].l,qv[2][curQ].r);
			// cout << "	ans[qv[2][curQ].index] :" << ans[qv[2][curQ].index] << "\n";
			// cout << "	qv[2][curQ].index :" << qv[2][curQ].index << "\n";
			curQ++;
		}
		if(i==qv[1].size()) break;
		ll val = qv[1][i].k;
		int index = qv[1][i].index;
		update(1,1,N,index,val);
		//cout << "***\n";
	}

	for(ll cur:ans)
		cout << cur << "\n";
	
	return 0;
}

ll update(int node, int st, int en, int idx, ll val){
	if(idx < st || en < idx) return tree[node];
	if(st == en) return tree[node] = val;
	int mid = (st+en)/2;
	return tree[node] = update(node*2,st,mid,idx,val) + update(node*2+1,mid+1,en,idx,val);
}

ll query(int node, int st, int en, int l, int r){
	if(r < st || en < l) return 0;
	if(l <= st && en <= r) return tree[node];
	int mid = (st+en)/2;
	return query(node*2,st,mid,l,r) + query(node*2+1,mid+1,en,l,r);
}


/*
18:50 Problem Analysis.
35:32 main() Completed.
39:06 2 function Completed.
전부 0 0 0 0으로 출력되는 현상 발생..
01:05:17
return update(node*2,st,mid,idx,val) + update(node*2+1,mid+1,en,idx,val);
에서
return tree[node] = update(node*2,st,mid,idx,val) + update(node*2+1,mid+1,en,idx,val);
로 변경..
01:06:03 TC passed.
240521 01:06:17
*/