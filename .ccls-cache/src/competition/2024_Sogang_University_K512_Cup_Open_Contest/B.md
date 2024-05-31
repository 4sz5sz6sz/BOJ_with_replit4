B번 - K512에 바이러스 퍼뜨리기
시간 제한	메모리 제한
2 초	512 MB
문제
K512는 내일 열릴 K512컵 준비를 위해 한창 분주하다. K512에는 총 
$N$개의 컴퓨터가 각각 
$1$번부터 
$N$번의 번호를 가지고 있다.

장난을 좋아하는 승형이는 K512에 비치된 PC에 바이러스를 퍼뜨려 K512컵을 망치기 위한 계략을 세웠다. 그러나 이 사실을 알아챈 근수는 PC를 치료해 다시 감염되지 않은 상태로 만들기 위해 노력하고자 한다. 초기에 모든 컴퓨터는 감염되지 않은 상태이다. 승형이가 감염시키는 컴퓨터와 근수가 치료하는 컴퓨터의 번호가 주어질 때, K512에 비치된 감염되지 않은 PC의 수를 알아내 보자.

입력
첫 번째 줄에 K512에 비치된 컴퓨터의 개수 
$N(1 \le N \le 2 \times 10^5)$과 쿼리의 개수 
$Q(1 \le Q \le 2 \times 10^5)$개가 주어진다.

두 번째 줄부터 
$Q+1$번째 줄까지 다음과 같은 쿼리가 주어진다.


$1$ 
$x$: 승형이가 
$x$번 컴퓨터를 감염시킨다. 단, 승형이는 이미 감염된 컴퓨터를 다시 감염시킬 수 있다. 이때는 아무 일도 벌어지지 않는다. 
$(1 \le x \le N)$ 

$2$ 
$x$: 근수가 
$x$번 컴퓨터를 치료하여 감염되지 않은 상태로 만든다. 단, 근수는 감염되지 않은 멀쩡한 컴퓨터를 치료할 수 있다. 이때는 아무 일도 벌어지지 않는다. 
$(1 \le x \le N)$ 

$3$ : 현재 K512의 감염되지 않은 컴퓨터의 개수를 출력한다.
출력

$3$번 쿼리가 주어질 때마다 해당하는 정답을 출력한다. 
$3$번 쿼리는 1개 이상 주어진다.

예제 입력 1 
10 10
1 3
1 6
1 3
3
2 3
2 7
1 7
3
1 9
3
예제 출력 1 
8
8
7
노트
입출력 방식이 느리면 여러 줄을 입력받거나 출력할 때 시간 초과를 받을 수 있으므로, 언어별로 다음 방법을 사용하는 것이 권장된다.

C++: cin/cout을 사용하고자 한다면, main 함수의 첫 줄에 아래 두 줄을 입력하고, 출력할 때 endl 대신 개행 문자(\n)를 사용해야 한다. 단, 이렇게 하면 더 이상 scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.
cin.tie(nullptr);
sync_with_stdio(false);
Python: input 대신 아래 코드를 사용한다.
sys.stdin.readline.rstrip()
Java, Kotlin: Scanner와 System.out.println 대신 BufferedReader와 BufferedWriter를 사용한다. BufferedWriter.flush는 프로그램 종료 전에 한 번만 하면 된다.

### Solution
- 세그먼트 트리
	- 구간 합

구간 합의 변동이 빈번히 일어나므로 단순 구간합 배열은 O(N^2)이 된다.
