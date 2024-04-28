직사각형 언어 제한클래스 구현
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	512 MB	2372	736	584	31.739%
문제
직사각형의 정보를 저장할 클래스 Rectangle을 구현하시오.

C++14, C++17
클래스 이름: Rectangle
생성자
Rectangle(width, height): 직사각형의 가로 길이를 width, 세로 길이를 height 설정한다. width는 1,000보다 작거나 같은 자연수, height는 2,000보다 작거나 같은 자연수이다.
멤버 변수
int width: 직사각형의 가로 길이
int height: 직사각형의 세로 길이
멤버 함수
int get_width() const: 직사각형의 가로 길이를 리턴한다.
int get_height() const: 직사각형의 세로 길이를 리턴한다.
void set_width(int width): 직사각형의 가로 길이를 width로 변경한다. 만약, width가 0보다 작거나 같거나, 1,000보다 크면 변경하지 않는다.
void set_height(int height): 직사각형의 세로 길이를 height로 변경한다. 만약, height가 0보다 작거나 같거나, 2,000보다 크면 변경하지 않는다.
int area() const: 직사각형의 넓이를 리턴한다.
int perimeter() const: 직사각형의 둘레 길이를 리턴한다.
bool is_square() const: 정사각형이면 true, 아니면 false를 리턴한다.

### Solution
