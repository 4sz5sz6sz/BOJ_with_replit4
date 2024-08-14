#define WEIGHT_MAX 5
#define N_MAX 10
#define IDX_MAX (WEIGHT_MAX*N_MAX)
#define MMM 1000003ll
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N,S,E,T;
vector<vector<ll>> chunk(IDX_MAX,vector<ll>(IDX_MAX));
vector<vector<ll>> ans(IDX_MAX,vector<ll>(IDX_MAX));
// ll chunk[IDX_MAX][IDX_MAX];
// ll ans[IDX_MAX][IDX_MAX];


vector<vector<ll>> mul_matrix(vector<vector<ll>> m1, vector<vector<ll>> m2);
void ShowArr();
void Init();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> S >> E >> T;
	S--; E--;
	for(int i=0;i<N;i++){
		for(int j=0;j<WEIGHT_MAX-1;j++){
			chunk[i*WEIGHT_MAX+j+1][i*WEIGHT_MAX+j] = 1;
		}
	}
	
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		for(int j=0;j<N;j++){
			ll cur = s[j]-'0';
			if(cur == 0) continue;
			chunk[i*WEIGHT_MAX+0][j*WEIGHT_MAX+cur-1]=1;
		}
	}
	//ans = chunk;
	Init();
	// ShowArr();

	while(T){
		// cout << "	T : " << T;
		
		// if(T==1){
		// 	//memcpy(ans,chunk,sizeof(chunk[0][0])*IDX_MAX);
		// 	ans = chunk;
		// 	T--;
		// }
		if(T&1){
			ans = mul_matrix(ans, chunk);
			T--;
		}
		else{
			chunk = mul_matrix(chunk,chunk);
			T/=2;
		}
		// cout << "	T : " << T << "\n";
		// ShowArr();
	}
	cout << ans[S*WEIGHT_MAX+0][E*WEIGHT_MAX+0] << "\n";
	
	return 0;
}

vector<vector<ll>> mul_matrix(vector<vector<ll>> m1, vector<vector<ll>> m2){
	vector<vector<ll>> ret(IDX_MAX,vector<ll>(IDX_MAX));
	for(int x=0;x<IDX_MAX;x++){
		for(int y=0;y<IDX_MAX;y++){
			for(int k=0;k<IDX_MAX;k++){
				ret[x][y] += m1[x][k] * m2[k][y];
			}
			ret[x][y] %= MMM; 
		}
	}
	//cout << "***\n";
	return ret;
}

void ShowArr(){
	cout << "**ShowArr()**\n";
	for(int i=0;i<WEIGHT_MAX*N;i++){
		for(int j=0;j<WEIGHT_MAX*N;j++){
			cout << chunk[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";

	for(int i=0;i<WEIGHT_MAX*N;i++){
		for(int j=0;j<WEIGHT_MAX*N;j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void Init(){
	for(int x=0;x<IDX_MAX;x++){
		ans[x][x] = 1;
	}
}


/*
49:58 study
01:13:28 main() Completed.
01:25:34 mul_matrix() Completed.

02:05:09

chunk[i*WEIGHT_MAX+0][j*WEIGHT_MAX+cur]=1;
에서
chunk[i*WEIGHT_MAX+0][j*WEIGHT_MAX+cur-1]=1;
로 변경.

02:10:43
if(T==1)일 때, 두 행렬 곱하도록 변경
02:11:32 TC passed.
240814 02:11:38
*/