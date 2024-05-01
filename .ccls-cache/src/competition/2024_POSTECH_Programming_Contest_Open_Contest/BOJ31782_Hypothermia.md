H번 - 저체온증
시간 제한	메모리 제한
2 초	1024 MB
문제
사람들이 $N$행 $M$열의 직사각형 모양으로 모여 있다. 초기에 각각의 사람의 상태는 정상 체온이거나 저체온증이고, 낮과 밤을 지나면서 사람들의 상태가 변화한다.

낮은 따뜻하기 때문에 저체온증인 사람이 정상 체온으로 회복할 수 있는 기회이다. 어떤 사람과 사방으로 인접한 두 명 이상의 사람이 정상 체온이라면 따뜻한 체온을 나눠 받아 저체온증에서 정상 체온으로 회복된다. 어떤 사람이 정상 체온으로 회복된 후에는 같은 방법으로 인접한 다른 사람들이 정상 체온으로 회복할 수 있으며, 이러한 체온 회복 과정은 낮 사이에 충분히 많이 반복될 수 있다.
밤은 춥기 때문에 정상 체온인 사람들이 저체온증에 걸릴 수 있다. 단, 밤 사이에 새롭게 저체온증에 걸리는 사람은 $K$명 이하이다.
낮과 밤이 계속 반복되며 사람들이 저체온증에 걸리거나 정상 체온으로 회복된다고 생각해 보자. 어떤 사람은 안타깝게도 저체온증에서 정상 체온으로 영영 회복할 수 없을 것이고, 어떤 사람은 근처에 정상 체온인 사람이 충분하여 밤에 어떠한 $K$명이 저체온증이 되는 것을 반복하더라도 낮이 되면 정상 체온으로 회복할 수 있을 것이다.

첫날 낮 사람들의 상태가 주어질 때 낮과 밤이 충분히 많이 반복된 후 최악의 경우에도 낮이 되면 정상 체온을 유지할 수 있는 사람의 수를 구하여라.

입력
첫 번째 줄에 사람들이 모인 직사각형 모양에서 행의 개수 $N$과 열의 개수 $M$, 밤에 새롭게 저체온증에 걸릴 수 있는 사람의 수의 최댓값 $K$가 공백으로 구분되어 주어진다. ($1\leq N,M\leq 2\,000$; $1\leq K\leq N\times M$)

두 번째 줄부터 $N$개의 줄에 각각 길이가 $M$인 문자열이 주어진다. 문자열에서 $i$번째 줄의 $j$번째 문자는 $i$번째 행 $j$번째 열에 위치한 사람의 초기 상태를 의미한다. O는 정상 체온, .는 저체온증을 나타낸다. 주어지는 모든 문자는 O 또는 .임이 보장된다.

출력
낮과 밤을 계속 반복하더라도 낮이 되면 정상 체온을 유지할 수 있는 사람의 수를 출력한다.

예제 입력 1 
5 7 1
O......
..O....
.O.....
.O...O.
....O.O
예제 출력 1 
35
첫 번째 낮에 모든 사람이 정상 체온으로 회복되며, 이후에는 밤에 어떠한 한 명이 저체온증에 걸리더라도 그다음 낮에 정상 체온으로 회복된다.

예제 입력 2 
5 7 2
O.....O
..O....
.O....O
.O...O.
......O
예제 출력 2 
12

### Solution



BFS로 풀기.
우선, 모든 칸 검사해보기.
현재 칸이 .인데, 주변 2칸이 O라면,
	cur칸을 O로 바꾸기.
	queue.push() 하기.

만약, cur칸의 주변이 .이면, 
	검사해보기.
	O로 바뀔 수 있다면,
		cur칸을 O로 바꾸기.
		큐에 삽입.

이러면, 전부 직사각형이 되었을 것이다.

flood fill 수행.

1번 사각형이

사각형의 가로 넓이 >= K && 세로 넓이 >= K를 만족해야 살아남는다.

vector<Pos>alive;

alive[i] = 0; 죽은 사각형.
alive[i] = 1; 생존한 사각형.

board[][] 전부 다 검사했을 때, 0이 아니면서, 생존한 사각형의 수를 전부 구해서 출력한다.