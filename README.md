# spiral_print.c의 문제정의

N x N의 칸을 가지는 격자가 있습니다. 각 칸에는 맨 위부터 차례대로 번호를 매깁니다.
N=3이라면 다음과 같은 배치입니다.

1 2 3

4 5 6

7 8 9

이 격자를 9부터 시작하여 반시계 방향으로 돌리며 나선모양으로 방문하면 다음과 같을 것입니다.

9 6 3 2 1 4 7 8 5

위의 규칙을 적용하여 사용자로부터 N 값을 입력받아서, N x N 격자의 칸들을 위와 같은 순서로 방문한 결과를 출력하는 프로그램입니다. (단, N은 1부터 100 사이의 자연수입니다.)

#사용언어
C언어

#작업환경
Ubuntu 15.04의 vim에서 작업하였고 gcc를 사용하여 컴파일하였습니다. // gcc -o [runfilename] spiral_print.c

#실행방법
실행할 폴더에 위치해두고 [ ./runfilename ]과 같이 입력합니다.(실행파일 이름은 가상으로 만들었습니다.)
