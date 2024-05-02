IOIOI 부분 성공서브태스크다국어
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	40565	11353	9236	29.713%
문제
N+1개의 I와 N개의 O로 이루어져 있으면, I와 O이 교대로 나오는 문자열을 PN이라고 한다.

P1 IOI
P2 IOIOI
P3 IOIOIOI
PN IOIOI...OI (O가 N개)
I와 O로만 이루어진 문자열 S와 정수 N이 주어졌을 때, S안에 PN이 몇 군데 포함되어 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. 둘째 줄에는 S의 길이 M이 주어지며, 셋째 줄에 S가 주어진다.

출력
S에 PN이 몇 군데 포함되어 있는지 출력한다.

제한
1 ≤ N ≤ 1,000,000
2N+1 ≤ M ≤ 1,000,000
S는 I와 O로만 이루어져 있다.
서브태스크
번호	배점	제한
1	50	
N ≤ 100, M ≤ 10 000.

2	50	
추가적인 제약 조건이 없다.

예제 입력 1 
1
13
OOIOIOIOIIOII
예제 출력 1 
4
OOIOIOIOIIOII
OOIOIOIOIIOII
OOIOIOIOIIOII
OOIOIOIOIIOII
예제 입력 2 
2
13
OOIOIOIOIIOII
예제 출력 2 
2
OOIOIOIOIIOII
OOIOIOIOIIOII

### Solution
- string
- stack?

stack에다가, IOIOIOIOI 담기.

현재 size가 짝수라면, 
	I만 담기.
홀수라면
	O만 담기

push() 기준에 미달이라면.

	stack에서 while() pop(); 진행.
		size가 8이다 -> 사실상 7 -> (7-1)/2 -> O가 3개
			N==2라면,
			ans+= (O의 갯수) - N + 1
		size가 9이다 -> O가 4개.	
	//size가 2라면, 알아서 ans+=0가 되게끔 설계됨.
//pop() 안 해도 될 듯.. size로만 따져도 될 듯..

바로 다음 s[i]부터 검사 진행.

//애초에 스택을 안 써도 될 듯.. push()과 pop() 대신에, size값만 증가시키면 된다..

x y
1 0
2 0
3 1
4 1
5 2
6 2
7 3
8 3
9 4
10 4

y = f(x)식 세우기
y = (x-1)/2