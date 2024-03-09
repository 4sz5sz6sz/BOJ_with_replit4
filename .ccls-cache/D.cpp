#define INF 0x3f3f3f3f3f3f3f3f
#define X first
#define Y second
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> Pos;

vector<vector<Pos>> v(2);
vector<vector<Pos>> ch(2);

int loop;

bool cmp1(Pos a, Pos b);
bool cmp2(Pos a, Pos b);
LL dist(Pos a, Pos b);
int CCW(Pos a, Pos m, Pos b);

bool cmp1(Pos a, Pos b){
	if(a.X != b.X) return a.X<b.X;
	else return a.Y<b.Y;
}

bool cmp2(Pos a, Pos b){
	return CCW(v[loop][0],a,b) > 0 || CCW(v[loop][0],a,b) == 0 && dist(v[loop][0],a) < dist(v[loop][0],b);
}

LL dist(Pos a, Pos b){
	LL A = a.X - b.X;
	LL B = a.Y - b.Y;
	return A*A + B*B;
}

int CCW(Pos a, Pos m, Pos b){
	LL t = (a.X - m.X) * (b.Y - m.Y) - (b.X - m.X) * (a.Y - m.Y);
	return (t<0) - (t>0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Pos posA, posB;
	LL sA, sB;

	cin >> posA.X >> posA.Y >> sA;
	cin >> posB.X >> posB.Y >> sB;

	int N[2];

	cin >> N[0] >> N[1];

	//Make 2 Convex Hull
	for(loop=0;loop<2;loop++){
		for(int i=0;i<N[loop];i++){
			LL a,b;
			cin >> a >> b;
			v[loop].push_back({a,b});
		}

		if(N[loop]==1){
			ch[loop].push_back(v[loop][0]);
			continue;
		}

		sort(v[loop].begin(),v[loop].end(),cmp1);
		sort(v[loop].begin()+1,v[loop].end(),cmp2);

		ch[loop].push_back(v[loop][0]);
		ch[loop].push_back(v[loop][1]);

		for(int i=2;i<N[loop];i++){
			while(ch[loop].size() >= 2 && CCW(v[loop][i],ch[loop][ch[loop].size()-1],ch[loop][ch[loop].size()-2]) >= 0)
				ch[loop].pop_back();
			ch[loop].push_back(v[loop][i]);
		}
	}
	

	LL ans = INF;
	Pos ans1;
	Pos ans2;

	/*
	for(int p1=0;p1<ch[0].size();p1++){
		for(int p2=0;p2<ch[1].size();p2++){
			if(dist(ch[0][p1],ch[1][p2]) < ans){
				ans = dist(ch[0][p1],ch[1][p2]);
				ans1 = ch[0][p1];
				ans2 = ch[1][p2];
			}
		}
	}
	*/

	//볼록껍질 생략
	for(int p1=0;p1<v[0].size();p1++){
		for(int p2=0;p2<v[1].size();p2++){
			if(dist(v[0][p1],v[1][p2]) < ans){
				ans = dist(v[0][p1],v[1][p2]);
				ans1 = v[0][p1];
				ans2 = v[1][p2];
			}
		}
	}

	cout << ans << "\n";
	cout << ans1.X << " " << ans1.Y << "\n";
	cout << ans2.X << " " << ans2.Y << "\n";
	
	
	return 0;
}


/*
06:14 문제 분석
24:27 main() 작성 완료.
33:35 함수 4개 작성 완료.
34:40 2번째 테스트 케이스에서 세그멘테이션 폴트 발생.

	ch[loop].push_back(v[loop][i]);
ch[loop].pop_back();
에서
	ch[loop].pop_back();
ch[loop].push_back(v[loop][i]);
로 변경.

37:05 테스트 케이스 전부 통과.

10점..

48:41 반례 발견.

CCW() == 0일 때, 반례가 발생할 수 있다.
일직선 상에 있는 점도 볼록껍질에 포함되어야 한다.


while(ch[loop].size() >= 2 && CCW(v[loop][i],ch[loop][ch[loop].size()-1],ch[loop][ch[loop].size()-2]) >= 0)
에서
while(ch[loop].size() >= 2 && CCW(v[loop][i],ch[loop][ch[loop].size()-1],ch[loop][ch[loop].size()-2]) > 0)
로 변경.

240309 49:42
*/