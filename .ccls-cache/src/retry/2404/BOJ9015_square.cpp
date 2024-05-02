#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;


typedef struct Point{
	int X,Y;
	bool operator<(struct Point &temp){
		if(X!=temp.X) return X < temp.X;
		return Y < temp.Y;
	}
}Point;

typedef struct Node{
	int S,E,V;
	bool operator<(struct Node &temp){
		return V > temp.V;
	}
}Node;

vector<Point> arr;

int N;

int dist(Point a, Point b);
bool FindPoint(Point target);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		arr.clear();
		int ans = 0;
		cin >> N;
		for(int i=0;i<N;i++){
			int x,y;
			cin >> x >> y;
			arr.push_back({x,y});
		}

		sort(arr.begin(),arr.end());

		/*
		for(int i=0;i<N;i++){
			cout << arr[i].X << "	" << arr[i].Y << "\n";
		}
		*/

		vector<Node> A;
		for(int i=0;i<N-1;i++){
			for(int j=i+1;j<N;j++){
				A.push_back({i,j,dist(arr[i],arr[j])});
			}
		}

		sort(A.begin(),A.end());
		/*
		for(int i=0;i<N-1;i++){
			for(int j=i+1;j<N;j++){
				Point p1 = arr[i];
				Point p2 = arr[j];

				if(dist(p1,p2)<ans) continue;
				//if(p1<p2) swap(p1,p2);

				int dx = p1.X - p2.X;
				int dy = p1.Y - p2.Y;

				Point pa, pb, pc, pd;
				pa.X = p1.X - dy;
				pa.Y = p1.Y + dx;

				pb.X = p2.X - dy;
				pb.Y = p2.Y + dx;

				pc.X = p1.X + dy;
				pc.Y = p1.Y - dx;

				pd.X = p2.X + dy;
				pd.Y = p2.Y - dx;

				if(FindPoint(pa) && FindPoint(pb)){
					// cout << "**";
					if(dist(pa,pb) > ans)
						ans = dist(pa,pb);
				}

				else if(FindPoint(pc) && FindPoint(pd)){
					// cout << "**";
					if(dist(pc,pd) > ans)
						ans = dist(pc,pd);
				}
				// cout << "	i :	" << i;
				// cout << "	j :	" << j;
				// cout << "	ans :	" << ans;
				// cout << "\n";
				
			}
		}
		*/

		for(Node cur:A){
			Point p1 = arr[cur.S];
			Point p2 = arr[cur.E];

			if(cur.V<ans) break;
			//if(p1<p2) swap(p1,p2);

			int dx = p1.X - p2.X;
			int dy = p1.Y - p2.Y;

			Point pa, pb, pc, pd;
			pa.X = p1.X - dy;
			pa.Y = p1.Y + dx;

			pb.X = p2.X - dy;
			pb.Y = p2.Y + dx;

			pc.X = p1.X + dy;
			pc.Y = p1.Y - dx;

			pd.X = p2.X + dy;
			pd.Y = p2.Y - dx;

			if(FindPoint(pa) && FindPoint(pb)){
				// cout << "**";
				if(dist(pa,pb) > ans)
					ans = dist(pa,pb);
			}

			else if(FindPoint(pc) && FindPoint(pd)){
				// cout << "**";
				if(dist(pc,pd) > ans)
					ans = dist(pc,pd);
			}
		}

		if(ans == 0){
			cout << "0\n";
		}
		else{
			cout << ans << "\n";
		}
	}
}

int dist(Point a, Point b){
	int A = a.X - b.X;
	int B = a.Y - b.Y;
	return A*A + B*B;
}
bool FindPoint(Point target){
	int l = 0;
	int r = N-1;
	while(l<=r){
		int mid = (l+r)/2;

		if(arr[mid].X == target.X && arr[mid].Y == target.Y)
			return true;
		
		else if(arr[mid]<target){
			l = mid+1;
		}
		else if(target<arr[mid]){
			r = mid-1;
		}
	}
	return false;
}

/*
20:43 문제 분석
31:53 main() 작성 완료.
41:26 함수 2개 작성 완료. 첫 컴파일.
operator< 작성 해야함.. 컴파일 오류..

01:09:15 배열이 오름차순 정렬이 안되어있었음..
sort(arr.begin(),arr.end());
삽입.

-> 테스트 케이스 통과.
틀렸습니다...

01:16:59
	int dx = abs(p1.X - p2.X);
	에서
	int dx = p1.X - p2.X;
	로 수정.

-> 시간초과...

01:19:41
if(FindPoint(pc) && FindPoint(pd)){
에서
else if(FindPoint(pc) && FindPoint(pd)){
로 수정.

01:25:55 if(dist(p1,p2)<ans) continue; 삽입.

01:43:25
크루스칼 알고리즘처럼, A[] 도입.
-> 여전히 시간초과...

if(cur.V<ans) break; 수정
-> 시간초과..

01:51:24 포기... 

240229 01:43:29
*/