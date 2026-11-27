# [Diamond IV] 핀볼 - 9244 

[문제 링크](https://acmicpc.net/problem/9244) 

### 성능 요약

메모리: 16828 KB, 시간: 168 ms

### 분류

자료 구조, 기하학, 집합과 맵, 스위핑, 트리를 사용한 집합과 맵

### 제출 일자

2024년 04월 20일 14:35:54

### 문제 설명

<p>Maria is quite addicted to pinball. She can shoot the ball to any position at the top of the board, but she cannot predict where the ball will end when it falls down, because it hits many bumpers on its way down.</p>

<p>She decided to model the pinball table as line segments and assume e that the ball is a point that falls from inﬁnite height. The ball falls straight vertically unless there is a segment immediately below it, in which case it follows the direction of the segment downwards until its end.</p>

<p>As you would expect the segments are closed, that is an endpoint is part of its segment. Pairs of segments do not intersect, not even at endpoints, and none is vertical or horizontal. Segments are not given in any speciﬁc order.</p>

### 입력 

 <p>The first line contains an integer N (0 ≤ N ≤ 100,000), the number of segments. Then N lines follow, each with four integers x<sub>1</sub> y<sub>1</sub> x<sub>2</sub> y<sub>2</sub>, the coordinates of a segment (-1,000,000 ≤ x<sub>i</sub>, y<sub>i</sub> ≤ 1,000,000). The last line contains an integer x<sub>0</sub> (-1,000,000 ≤ x<sub>0</sub> ≤ 1,000,000), the initial x-coordinate of the ball.</p>

### 출력 

 <p>Output a single integer x<sub>T</sub>, the ﬁnal x-coordinate of the ball.</p>

<p> </p>

