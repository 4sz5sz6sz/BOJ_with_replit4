냅색문제
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	128 MB	9960	3840	2906	39.201%
문제
세준이는 N개의 물건을 가지고 있고, 최대 C만큼의 무게를 넣을 수 있는 가방을 하나 가지고 있다.

N개의 물건을 가방에 넣는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 C가 주어진다. N은 30보다 작거나 같은 자연수, C는 109보다 작거나 같은 음이 아닌 정수이다. 둘째 줄에 물건의 무게가 주어진다. 무게도 109보다 작거나 같은 자연수이다.

출력
첫째 줄에 가방에 넣는 방법의 수를 출력한다.

예제 입력 1 
2 1
1 1
예제 출력 1 
3
예제 입력 2 
1 1
1
예제 출력 2 
2
예제 입력 3 
1 2
1
예제 출력 3 
2
예제 입력 4 
2 1
2 2
예제 출력 4 
1
예제 입력 5 
2 2
1 1
예제 출력 5 
4
예제 입력 6 
30 30
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
예제 출력 6 
1073741824


### Solution
- two pointer
- 
두 그룹으로 나누기

백트래킹으로 1그룹 2그룹 생성하기.
1그룹 - 2그룹 매칭

arr[0][i]  arr[1][j]

i는 0부터 시작. j는 마지막부터 시작.

arr[0][i] + arr[1][j] <= C이라면,
	i++;
그렇지 않다면
	ans+=(j+1);
	j--;

