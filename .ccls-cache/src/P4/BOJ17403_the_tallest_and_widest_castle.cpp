#define IDX_MAX 1001
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef struct Pos{
	ll X,Y,INDEX;
}Pos;

bool cmp1(struct Pos &a, struct Pos &b);	//원점 잡기
bool cmp2(struct Pos &a, struct Pos &b);	//반시계 정렬
bool cmp3(struct Pos &a, struct Pos &b);	//인덱스 순 정렬

ll CCW(Pos a, Pos m, Pos b);
ll GetDist(Pos a, Pos b);

int isused[IDX_MAX];
int N;
int curFloor;
int numOfCh;

vector<Pos> ch;
vector<Pos> input;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i=0;i<N;i++){
		int a,b;
		cin >> a >> b;
		input.push_back({a,b,i});
	}

/*
	cout << "\n";
	cout << CCW(input[0],input[3],input[7]);
	cout << "\n";
*/	

	if(N <= 2){
		for(int i=0;i<N;i++){
			cout << isused[i] << " ";
		}
		return 0;
	}
	//int T=1;
	while(1){
		sort(input.begin(),input.end(),cmp1);
		if(isused[input[1].INDEX]) break;
		sort(input.begin()+1,input.end(),cmp2);
		ch.clear();
		ch.push_back(input[0]);
		ch.push_back(input[1]);
		for(int i=2;i<N;i++){
			if(isused[input[i].INDEX]) continue;
			while(ch.size()>=2 && CCW(input[i],ch[ch.size()-1],ch[ch.size()-2]) >= 0)
				ch.pop_back();
			ch.push_back(input[i]);
		}

		if(ch.size() <= 2) break;
		++curFloor;
		for(Pos cur:ch){
			isused[cur.INDEX] = curFloor;
			//cout << "	curFloor: " << curFloor << "\n";
			numOfCh++;
		}
	}

	sort(input.begin(),input.end(),cmp3);
	for(Pos cur:input){
		cout << isused[cur.INDEX] << " ";
	}
	
	
	return 0;
}

bool cmp1(struct Pos &a, struct Pos &b){
	if(isused[a.INDEX] != isused[b.INDEX]) return isused[a.INDEX] < isused[b.INDEX];
	if(a.X != b.X) return a.X < b.X;
	return a.Y < b.Y;
}

bool cmp2(struct Pos &a, struct Pos &b){
	if(isused[a.INDEX] != isused[b.INDEX]) return isused[a.INDEX] < isused[b.INDEX];
	if(CCW(input[0],a,b) != 0) return CCW(input[0],a,b) > 0;
	return GetDist(input[0],a) < GetDist(input[0],b);
	/*
	return (CCW(input[0],a,b) > 0) || (CCW(input[0],a,b) == 0 && (GetDist(input[0],a) < GetDist(input[0],b)));
	*/
}

bool cmp3(struct Pos &a, struct Pos &b){
	return a.INDEX < b.INDEX;
}

/*
int CCW(Pos a, Pos m, Pos b){
	ll ret = (a.X-m.X) * (b.X-m.X);
	ret -= (a.Y-m.Y) * (b.Y-m.Y);
	return (ret<0 - ret>0);
}
*/
ll CCW(Pos a, Pos b, Pos c){
	ll ret = a.Y*b.X + b.Y*c.X + c.Y*a.X;
	ret -= a.X*b.Y + b.X*c.Y + c.X*a.Y;
	return ret;
}

ll GetDist(Pos a, Pos b){
	ll A = a.X-b.X;
	ll B = a.Y-b.Y;
	return A*A + B*B;
}


/*
10:09 hash Test..
17:03 Problem Analysis.
34:44 main() Completed.
01:16:47 TC passed.
WA..
if(ch.size() <= 2) break; 삽입.
01:21:53
return A*A - B*B;
에서
return A*A + B*B;
로 수정..
240508 01:21:53
*/