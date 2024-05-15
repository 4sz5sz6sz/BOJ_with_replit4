#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> Pos;

int N;
vector<Pos> ch;
vector<Pos> v;

bool cmp1(const Pos &a, const Pos &b);
bool cmp2(const Pos &a, const Pos &b);
ld dist(const Pos &a, const Pos &b);
int CCW(Pos a, Pos m, Pos b);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i=0;i<N;i++){
		ll a,b;
		cin >> a >> b;
		v.push_back({a,b});
	}

	sort(v.begin(),v.end(),cmp1);
	sort(v.begin()+1,v.end(),cmp2);

	ch.push_back(v[0]);
	ch.push_back(v[1]);
	for(int i=2;i<N;i++){
		while(ch.size()>=2 && CCW(v[i],ch[ch.size()-1],ch[ch.size()-2]) >= 0)
			ch.pop_back();
		ch.push_back(v[i]);
	}

	ld ans = 0;
	int len = ch.size();
	for(int i=0;i<len;i++){
		ans+=dist(ch[i],ch[(i+1)%len]);
	}

	cout << fixed;
	cout.precision(2);
	cout << ans << "\n";
	
	return 0;
}

bool cmp1(const Pos &a, const Pos &b){
	if(a.X != b.X) return a.X < b.X;
	return a.Y < b.Y;
}

bool cmp2(const Pos &a, const Pos &b){
	return (CCW(v[0],a,b) > 0) || (CCW(v[0],a,b) == 0 && dist(v[0],a) < dist(v[0],b));
}

ld dist(const Pos &a, const Pos &b){
	ll A = (a.X - b.X);
	ll B = (a.Y - b.Y);
	return sqrt(A*A + B*B);
}

int CCW(Pos a, Pos m, Pos b){
	ll ret = (a.X - m.X) * (b.Y - m.Y);
	ret -= (b.X - m.X) * (a.Y - m.Y);
	return (ret<0) - (ret>0);
}


/*
00:52 Probem Analysis.
07:41 main() Completed.
16:15 4 function Completed.

cin >> a >> b; 누락..
N에서 int len = ch.size();로 대체.

20:33 TC passed.
240515 20:41
*/