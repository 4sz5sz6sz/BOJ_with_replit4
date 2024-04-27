#include<bits/stdc++.h>
using namespace std;

enum Con{
	CON_K,
	CON_U,
	CON_G,
	CON_P
};

typedef struct Country{
	int P, M, S;	//득점, 실점, 승점 
	int IDX;
	int GOAL;
	int isKorea;	//한국이면 1, 아니면 0
	bool operator<(struct Country &temp){
		if(S != temp.S) return S > temp.S;
		if(P-M != temp.P - temp.M) return P-M > temp.P - temp.M;
		if(P != temp.P) return P > temp.P;
		return isKorea < temp.isKorea;	//동점일 때, 한국은 무조건 후순위로.
	}
}Country;


vector<Country> arr(4);
vector<Country> arr_copy(4);
vector<string> name = {"korea","uruguay","ghana","portugal"};
int N;

void ShowRank();
void ShowArr();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for(int i=0;i<4;i++){
		//int P,M,S;
		cin >> arr[i].P >> arr[i].M >> arr[i].S;
		arr[i].IDX = i;
		arr[i].GOAL = 0;
		if(i == 0) arr[i].isKorea = 1;
		else arr[i].isKorea = 0;
	}

	cin >> N;
	ShowRank();
	for(int i=0;i<N;i++){
		string comm;
		cin >> comm;
		arr_copy = arr;
		if(comm == "korea"){
			arr[CON_K].P++;
			arr[CON_P].M++;
			arr[CON_K].GOAL++;
		}
		else if(comm == "uruguay"){
			arr[CON_U].P++;
			arr[CON_G].M++;
			arr[CON_U].GOAL++;
		}
		else if(comm == "ghana"){
			arr[CON_G].P++;
			arr[CON_U].M++;
			arr[CON_G].GOAL++;
		}
		else{
			arr[CON_P].P++;
			arr[CON_K].M++;
			arr[CON_P].GOAL++;
		}
		ShowRank();
	}
	
	
	return 0;
}

void ShowRank(){
	arr_copy = arr;
	if(arr_copy[CON_P].GOAL > arr_copy[CON_K].GOAL)
		arr_copy[CON_P].S+=3;
	else if(arr_copy[CON_P].GOAL < arr_copy[CON_K].GOAL)
		arr_copy[CON_K].S+=3;
	else{
		arr_copy[CON_P].S+=1;
		arr_copy[CON_K].S+=1;
	}

	if(arr_copy[CON_U].GOAL > arr_copy[CON_G].GOAL)
		arr_copy[CON_U].S+=3;
	else if(arr_copy[CON_U].GOAL < arr_copy[CON_G].GOAL)
		arr_copy[CON_G].S+=3;
	else{
		arr_copy[CON_U].S+=1;
		arr_copy[CON_G].S+=1;
	}
	//ShowArr();
	
	sort(arr_copy.begin(),arr_copy.end());
	if(arr_copy[0].isKorea == 1 || arr_copy[1].isKorea == 1) cout << "cry\n";
	else
		cout << "unhappy\n";
}

void ShowArr(){
	for(int i=0;i<4;i++){
		cout << "	name[i] : " << name[i];
		cout << "\n";
		cout << "	arr_copy[i].P : " << arr_copy[i].P;
		cout << "	arr_copy[i].M : " << arr_copy[i].M;
		cout << "	arr_copy[i].S : " << arr_copy[i].S;
		cout << "\n";
	}
}

/*
23:40 Problem Analysis.
41:47 main() Completed.
43:23 ShowRank() completed.
55:56 TC passed.
Wa...
01:05:47
연장전 승패 결과가, 누적되지 않는 현상 발생.
한vs포 와, 우vs가  의 결과가 동시에 나타나지 않는다는 현상 발생.
승패 결과 판정을 main()에서 ShowArr()로 이동.

01:10:29
	arr_copy[CON_U].S+=1;
	arr_copy[CON_G].P+=1;
	에서
	arr_copy[CON_U].S+=1;
	arr_copy[CON_G].S+=1;
	로 수정.

01:12:19 TC passed.
WA..

01:17:19
arr[CON_K].P++;
arr[CON_P].M++;
arr[CON_K].S++;
에서
arr[CON_K].P++;
arr[CON_P].M++;
arr[CON_K].GOAL++;
로 변경.

01:17:48 TC pass.ed
01:19:28 주석 제거.

240427 01:17:53
*/