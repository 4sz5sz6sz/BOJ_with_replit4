1~32,000 까지의 정점이 있는 그래프로 해석하기.
N부터 시작해서, number로 도달해야 한다.

연산은 5가지가 있다.
- 더하기
- 빼기
	- N - cur
	- cur - N
- 곱하기
- 나누기
	- N / cur
	- cur / N
- N 하나 더 붙이기
	N*11
	N*111
	N*1111

typedef pair<int,int> Edge;	//DIST, POS

{1,5}
{2,10} {2,25} {2,55} 등등..
{3, 55 + 5}
...
..
{6,xxx}
6까지 생성한다.

간선 최대 5^5개? 예상된다.

5 -> 10 으로 갈려면, 추가비용 1이 든다.
5 -> 125 으로 갈려면, 추가비용 2이 든다.

다익스트라 도중, cur.DIST + next.DIST >= 7이라면, 
	목적지 도달 성공했으면 
		return;
	그렇지 않다면
		break;

next.POS >= IDX_MAX 이라면 pass.



9999/99 = 101
99999/99 = 1010


반례 메모)
-4가 나오는 경우가 있다..
5/5-5

5-5/5로 대체 가능하긴 함.

일단 거르기


/*
34:11 MakeEdge() Completed.
58:45 TC passed.
01:10:14 자정 stop..

재개..
10:21 반례 발견. 9 10101 -> -1 출력되는 현상 발생.
17:42 cur.POS 값 추적해보니, 10101 자체가 Q에 안 들어감.
다익스트라 처음 돌릴 때, N값 말고 11*N ... 111111*N도 넣어주기.

시작할 떄 노드 6개 넣어줌. 정답!!

21:16 AC.
240506 01:10:14 + 21:42
*/