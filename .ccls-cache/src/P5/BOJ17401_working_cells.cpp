#define MMM 1000000007ll
#define IDX_MAX 21
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T,N,D;
vector<vector<vector<ll>>> vM;
vector<vector<ll>> bigM;
vector<vector<ll>> UnitMatrix(IDX_MAX,vector<ll>(IDX_MAX));

void Init();
void ShowArr();
vector<vector<ll>> mul_matrix(vector<vector<ll>> m1, vector<vector<ll>> m2);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T >> N >> D;
	Init();
	for(int i=0;i<T;i++){
		int M;
		cin >> M;
		vector<vector<ll>> tmpM(IDX_MAX,vector<ll>(IDX_MAX));
		for(int j=0;j<M;j++){
			ll S,E,W;
			cin >> S >> E >> W;
			tmpM[S][E] = W;
		}
		vM.push_back(tmpM);
	}

	vector<vector<ll>> totalM = UnitMatrix;

	for(int i=0;i<T;i++){
		totalM = mul_matrix(totalM, vM[i]);
	}

	bigM = UnitMatrix;
	vector<vector<ll>> chunk = totalM;
	ll loop = D/T;
	while(loop){
		if(loop & 1){
			// cout << "1*\n";
			bigM = mul_matrix(bigM, chunk);
			loop--;
		}
		else{
			// cout << "2*\n";
			chunk = mul_matrix(chunk, chunk);
			loop/=2;
		}
		
	}
	

	for(int i=0;i<D%T;i++){
		bigM = mul_matrix(bigM,vM[i]);
	}

	ShowArr();

	return 0;
}



void Init(){
	for(int i=0;i<=N;i++)
		UnitMatrix[i][i] = 1;
}

void ShowArr(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout << bigM[i][j] << " ";
		}
		cout << "\n";
	}
}

vector<vector<ll>> mul_matrix(vector<vector<ll>> m1, vector<vector<ll>> m2){
	vector<vector<ll>> ret(IDX_MAX,vector<ll>(IDX_MAX));
	for(int x=0;x<=N;x++){
		for(int y=0;y<=N;y++){
			for(int k=0;k<=N;k++){
				ret[x][y] = (ret[x][y] + m1[x][k] * m2[k][y])%MMM;
			}
			ret[x][y] %= MMM;
		}
	}
	return ret;
}

/*
03:17 Problem Analysis.
26:48 mul_matrix() Completed.

error...
vector<vector<ll>> ret(IDX_MAX,vector<ll>(IDX_MAX));
ret 초기화 제대로 시킴.

38:19
vector<vector<ll>> chunk = UnitMatrix;
에서
vector<vector<ll>> chunk = totalM;
로 변경.
40:00 TC passed.
40:03 WA...
1 2 0 
0 
-> 
1 0 
0 1 
출력됨.
52:49 오버플로우 방지 용으로 %MMM 위치 변경.
240815 53:01
*/