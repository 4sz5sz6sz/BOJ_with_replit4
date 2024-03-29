A번 - Furiosa AI 영상 처리 가속 100점성공서브태스크스페셜 저지
시간 제한	메모리 제한
1 초	1024 MB
문제


1세대 WARBOY제품

Furiosa AI에서 출시한 NPU(Neural Processing Unit)인 WARBOY는 세계적으로 가장 우수한 성능을 가진 NPU 중 하나로 인정받고 있다. 특히 1세대 제품 WARBOY는 이미지 분류와 객체 검증 등 영상 처리 가속에 있어 매우 빠른 속도를 제공한다. Furiosa AI는 올해 2세대 제품인 Renegade를 출시할 예정이다.

GPU가 그래픽을 처리하기 위한 목적으로 만들어진 기능을 AI에도 사용한다면, NPU는 구조 자체가 AI에 최적화되어 있다. Furiosa AI의 WARBOY 제품은 이미 전세계적으로 가장 공신력 있는 AI 반도체 벤치마크 대회인 ’엠엘퍼프(MLPerf)’에서 이미지 분류, 객체 검증 등의 영상 처리 가속 속도 항목에서 가장 좋은 결과를 보여주었다.

재현이와 우영이는 각자 컴퓨터를 한 대씩 가지고 있다. 두 사람은 MatKor의 활동을 위해 두 개의 영상 처리 작업을 해야 하는데, 각자의 컴퓨터로 하나의 작업을 하는데 걸리는 시간은 각각 $m$, $n$이다.

이를 지켜보던 종우는 두 명에게 Renegade 제품 하나를 주었다. 컴퓨터에 이 제품을 탑재하면 작업 속도를 $a$배로 만들어 준다.

재현이와 우영이는 두 컴퓨터 중 하나에만 Renegade 제품을 탑재할 수 있으며, 한 컴퓨터에서 동시에 최대 한 개의 영상 처리 작업을 할 수 있다. 하나의 영상 처리 작업을 하는 도중에는 이 작업을 멈출 수 없다.

재현이와 우영이가 가장 빠르게 영상 처리 작업을 모두 마치기 위해 소요되는 시간을 구해보자.

입력
첫 번째 줄에 정수 $a$의 값이 주어진다. $(1\le a\le 10)$ 

두 번째 줄에 정수 $m$과 $n$이 공백으로 구분되어 주어진다. $(1\le m,n\le 100)$ 

출력
두 개의 영상을 가장 빠르게 처리했을 때, 걸리는 시간을 출력하라.

정답과의 절대오차 또는 상대오차가 $10^{-6}$ 이하이면 정답으로 인정된다.

서브태스크
번호	배점	제한
1	27	
$a = 1$ 

2	36	
$m$과 $n$은 $a$의 배수

3	37	
추가적인 제한 조건 없음

예제 입력 1 
1
2 3
예제 출력 1 
3
우영이의 컴퓨터에 Renegade를 장착하고, 두 컴퓨터에 각각 하나씩 작업하면 작업 종료까지 총 $3$의 시간이 소요된다.

예제 입력 2 
1
2 5
예제 출력 2 
4
재현이의 컴퓨터에 Renegade를 장착하고, 재현이의 컴퓨터로 두 작업을 모두 처리하면 각각 $2$씩, 총 $4$의 시간이 소요된다.

예제 입력 3 
3
15 12
예제 출력 3 
8
우영이의 컴퓨터에 Renegade를 장착하고, 우영이의 컴퓨터로 두 작업을 모두 처리하면 각각 $4$씩, 총 $8$의 시간이 소요된다.

예제 입력 4 
7
97 98
예제 출력 4 
27.7142857
재현이의 컴퓨터에 Renegade를 장착하고, 재현이의 컴퓨터로 두 작업을 모두 처리하면 각각 

$\frac{97}{7}$씩, 총 

$\frac{194}{7}$의 시간이 소요된다.



n/a * 2
m/a * 2
n/a + m/a
셋 중 최솟값 출력하기.

