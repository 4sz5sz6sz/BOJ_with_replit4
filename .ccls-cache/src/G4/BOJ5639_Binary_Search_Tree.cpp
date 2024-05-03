#define IDX_MAX 1000001
#include<bits/stdc++.h>
using namespace std;

int tree[IDX_MAX];
//int tree[6000000];

int L[IDX_MAX];
int R[IDX_MAX];
//vector<int> TC;

int UPDATE(int node, int val);
void postorder_travelsal(int node);
// void preorder_travelsal(int node);
void action(int node);
void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int root=-1;
	int val;
	while(cin >> val){
		//if(val == -1) break;
		if(root == -1) root = val;
		//TC.push_back(val);	//FOR DEBUGGING
		UPDATE(root,val);
	}
	//ShowArr();
	postorder_travelsal(root);
	return 0;
}

int UPDATE(int node, int val){
	/*
	if(node == 1 && tree[node] == 0){
		tree[node] = val;
		return 0;
	}
	*/
	if(tree[node] == 0){
		tree[node] = val;
		return 0;
	}
	if(val < tree[node]){
		if(tree[L[node]] == 0)
			L[node] = val;
		UPDATE(L[node],val);
	}
	else{
		if(tree[R[node]] == 0)
			R[node] = val;
		UPDATE(R[node],val);
	}
	return 0;
}

void postorder_travelsal(int node){
	if(tree[node] == 0) return;
	postorder_travelsal(L[node]);
	postorder_travelsal(R[node]);
	cout << tree[node] << "\n";
	//action(node);
}

//void preorder_travelsal(int node){}

void action(int node){
	cout << tree[node] << "\n";
}

/*
void ShowArr(){
	for(int val:TC){
		cout << "	val : " << val;
		cout << "	L[val] : " << L[val];
		cout << "	R[val] : " << R[val];
		cout << "\n";
	}
}
*/

/*
11:03 Problem Analysis.
16:47 main() Completed.
20:27 UPDATE() Completed.
21:16 2 function Completed.
28:26 TC passed.

재개
런타임에러, out of bound 에러 발생..
아무래도, node*2 트릭은 쓰면 안 될 듯..
배열 대신 연결 리스트로 구현하기.

10:51 L[] R[] 도입함.
TC 배열 도입.


26:18 TC passed.

880ms나 소요된다.. tree[] L[] R[] 왔다갔다 하면서 참조해서 그런 듯..

240502 28:30 + 26:24
*/