#define INF 0x3f3f3f3f
#define IDX_MAX 200007
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
LL arr[IDX_MAX];
LL seg[IDX_MAX];	//값이 아닌, index를 저장함.

LL update(int node, int st, int en, int i, LL val);
LL find(int node, int st, int en, int l, int r);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	//fill(seg,seg+IDX_MAX,0);  bottom-up에서는 생략?
	arr[0] = INF;	//bottom-up에서 arr[0]의 활용이 필요할 듯

	for(int i=1;i<=N;i++){
		cin >> arr[i];
		update(1,1,N,i,arr[i]);
	}

	int M;
	cin >> M;
	for(int i=0;i<M;i++){
		LL a,b,c;
		cin >> a >> b >> c;
		if(a==1){
			update(1,1,N,b,c);
			arr[b] = c;
		}
		else if(a==2){
			cout << find(1,1,N,b,c) << "\n";
		}
	}

	for(int i=1;i<=N*2;i++){
		cout << seg[i] << " ";
	}
	
	return 0;
}

LL update(int node, int st, int en, int i, LL val){
	if(st==en) return seg[st] = i;
	int mid = (st+en)/2;
	if(i<=mid){
		/*
		ll ret=update(node*2,st,mid,i,val);
		if(arr[ret] <= arr[seg[node]])
		return seg[node] = ;
		*/
		return seg[node] = update(node*2,st,mid,i,val);
	}
	else
		return seg[node] = update(node*2+1,mid+1,en,i,val);
}

LL find(int node, int st, int en, int l, int r){
	if(en < l || r < st) return 0;	//일단 0 리턴해보기.
	else if(l <= st && en <= r) return seg[node];
	else{
		int mid=(st+en)/2;
		LL ret1 = find(node*2, st, mid, l, r);
		LL ret2 = find(node*2+1, mid+1, en, l, r);
		if(arr[ret1] <= arr[ret2]) return ret1;
		else return ret2;
	}
}


/*
05:10 문제 분석
11:20 main() 작성 완료.
17:42 update() 작성 완료.
28:01 find() 작성 완료.

29:44 테스트 케이스 오답..
3 3 5 5출력..

50:46 update가 제대로 안됨..
update()에서, i<=mid 하지 말고, 둘 다 호출해야 함.

240303 
*/