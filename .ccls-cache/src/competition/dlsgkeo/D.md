D번 - 엉성한 도토리 분류기
시간 제한	메모리 제한
1 초	1024 MB
문제
엉성한 분류기를 이용하여 도토리를 크기별로 나누고자 한다.

분류기는 
$N$개의 구멍이 뚫린 기울어진 판자이다. 분류기의 구멍은 높은 쪽부터 차례로 
$1$번부터 
$N$번까지 번호가 매겨져 있다. 
$i$번 구멍의 크기는 
$a_i$이다.



분류기에 도토리를 넣으면 
$1$번 구멍부터 
$N$번 구멍까지 굴러간다. 분류기의 표면은 거칠기 때문에 도토리가 하나의 구멍을 지나고 나면 크기가 
$1$씩 줄어든다. 예를 들어 
$1$번 구멍을 지날 때 도토리의 크기가 
$10$이었다면, 
$1$번 구멍을 지나고 나서 
$2$번 구멍을 지날 때는 크기가 
$1$ 줄어 
$9$가 된다. 마찬가지로 도토리가 
$2$번 구멍을 지났다면 
$3$번 구멍을 지날 때 크기가 
$1$ 줄어 
$8$이 된다.

도토리는 현재 크기보다 크거나 같은 구멍을 지날 때 그 구멍으로 떨어진다. 

주어지는 
$Q$개의 도토리에 대하여, 각각의 도토리를 분류기에 넣었을 때 굴러떨어져 나오는 구멍 번호를 순서대로 출력하는 프로그램을 작성하라.

입력
첫 번째 줄에 분류기의 구멍 개수를 나타내는 정수 
$N$이 주어진다.

두 번째 줄에 각 구멍의 크기를 나타내는 
$N$개의 정수 
$a_1, a_2, \cdots, a_N$이 공백으로 구분되어 주어진다.

세 번째 줄에 분류해야 하는 도토리의 개수를 나타내는 정수 
$Q$가 주어진다. 

네 번째 줄에 분류기에 넣을 도토리의 크기를 나타내는 
$Q$개의 정수 
$s_1, s_2, \cdots, s_Q$가 공백으로 구분되어 주어진다.

주어진 입력 조건에서 도토리는 크기에 상관없이 어떤 구멍으로 빠져나올 수 있다.

출력
각 도토리를 분류기에 넣었을 때 굴러떨어져 나오는 구멍의 번호를 도토리가 주어지는 순서대로 공백으로 구분하여 출력한다.

제한

$1 \le N \le 10^5$ 

$1 \le a_i \le N$ 

$1 \le Q \le 10^5$ 

$1 \le s_i \le N$ 
예제 입력 1 
10
5 6 1 4 9 2 8 10 3 7
10
1 2 3 4 5 6 7 8 9 10
예제 출력 1 
1 1 1 1 1 2 2 5 5 5

### solution

stack으로 구현.

도토리에 pair<int,int> DATA, INDEX 기록해서 Node에 기록.

도토리를 크기 내림차순으로 정렬.

구멍 크기는, num+i으로 저장하기.
	//구멍 하나 지날때마다 1씩 크기 줄어드는 것을 미리 반영함.


i번째 구멍에서, 
	while (top이 현재 구멍에 넣을 수 있을 때 까지)
		pop();
		ans에 기록.

스택이 비었으면,
	ans 출력 후 프로그램 종료.
