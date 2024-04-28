#define IDX_MAX 500000
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll tree[IDX_MAX*4+7];
//int l=1,r=0;
int curL = 1, curR = 0;
int curN;
int Q;

ll update(int node, int st, int en, int idx, ll val);
ll find(int node, int st, int en, int l, int r);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	for(int i=0;i<Q;i++){
		int comm;
		ll val;
		cin >> comm;
		if(comm == 1){
			cin >> val;
			curR++;
			update(1,1,IDX_MAX,curR,val);
			//cout << "update()" << update(1,l,r,r,val) << "\n";
			
		}
		else{
			int mid = (curL+curR-1)/2;
			ll ans1 = find(1,1,IDX_MAX,curL,mid);
			ll ans2 = find(1,1,IDX_MAX,mid+1,curR);
			/*
			cout << "	curL : " << curL;
			cout << "	curR : " << curR;
			cout << "	mid : " << mid;
			cout << "	ans1 : " << ans1;
			cout << "	ans2 : " << ans2;
			cout << "\n";
			*/
			if(ans1<=ans2){
				curL=mid+1;
				cout << ans1 << "\n";
			}
			else{
				curR = mid;
				cout << ans2 << "\n";
			}
		}
	}

	for(int i=curL;i<=curR;i++){
		cout << find(1,1,IDX_MAX,i,i) << " ";
	}

	return 0;
}

ll update(int node, int st, int en, int idx, ll val){
	if(idx < st || en < idx) return tree[node];
	if(st>=en) return tree[node] = val;
	int mid = (st+en)/2;
	return tree[node] = update(node*2,st,mid,idx,val) + update(node*2+1,mid+1,en,idx,val);
}

ll find(int node, int st, int en, int l, int r){
	if(en < l || r < st) return 0;
	//if(st>=en) return tree[node];
	if(l <= st && en <= r) return tree[node];
	int mid = (st+en)/2;
	return find(node*2,st,mid,l,r) + find(node*2+1,mid+1,en,l,r);
}


/*
33:27 새로운 아이디어, l과 r값 조정.
48:02 Problem Analysis.
58:53 main() Completed.
01:06:54 update() find() Completed.

01:25:21 Wa..
l r 범위는 변동시키면 안될 듯.. curL curR 만들기.
01:29:43 curL curR 구현 완료.
01:31:13 TC passed.
240428 
*/