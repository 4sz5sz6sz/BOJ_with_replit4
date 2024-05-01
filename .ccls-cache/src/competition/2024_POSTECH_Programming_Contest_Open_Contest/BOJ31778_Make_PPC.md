D번 - PPC 만들기
시간 제한	메모리 제한
1 초	1024 MB
문제
포닉스에게는 아끼던 문자열 $S$가 있다. $S$는 길이가 $N$이며 알파벳 대문자 C와 P만으로 이루어져 있는 문자열이다. 문자열 $S$의 $i$번째 문자는 $S_i$와 같이 나타낸다.

포닉스는 PPC에 참가하는 팀들을 위해 문자열 $S$로 대회장을 장식하려 한다. 포닉스는 대회 전, $S$에 다음과 같은 연산을 최대 $K$번 시행할 수 있다.

$1 \le i < j \le N$인 두 정수 $i$, $j$를 골라 $S_i$와 $S_j$를 바꾼다.
포닉스의 목표는 완성된 문자열 $S$에 PPC 부분문자열이 가장 많게 하는 것이다. PPC 부분문자열의 개수란, $1 \le i<j<k \le N$이고 $S_i=S_j=$ P, $S_k=$ C인 $(i,j,k)$의 개수를 의미한다.

포닉스가 만들 수 있는 PPC 부분문자열의 개수의 최댓값을 구하여라.

입력
첫 번째 줄에 문자열 $S$의 길이 $N$과 연산의 최대 사용 횟수 $K$가 공백으로 구분되어 주어진다. ($1\le K\le N\le 200\,000$)

두 번째 줄에 길이가 $N$인 문자열 $S$가 주어진다. $S$는 알파벳 대문자 C와 P만으로 이루어져 있음이 보장된다.

출력
포닉스가 만들 수 있는 PPC 부분문자열의 개수의 최댓값을 출력한다.

예제 입력 1 
3 1
CPP
예제 출력 1 
1
예제 입력 2 
8 2
CCPCPPCP
예제 출력 2 
21
예제 입력 3 
3 1
CPC
예제 출력 3 
0

### Solution
PPPCPCCC

4 = 1*4
4+4 = 2*4
3+3+3 = 3*3

투포인터로, 왼쪽의 C와 오른쪽의 P 교환.

왼쪽의 P의 갯수, 오른쪽의 C의 갯수 전부 미리 구해두기.


//현재 arr[i] == P라면,
arr[i]에 있는 P에 대해서,
내 왼쪽에 있는 P의 갯수, 내 오른쪽에 있는 C의 갯수 구하기.

ans+=(왼쪽 P의 갯수) * (오른쪽 C의 갯수)
