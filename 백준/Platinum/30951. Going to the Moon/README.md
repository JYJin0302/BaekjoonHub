# [Platinum III] Going to the Moon - 30951 

[문제 링크](https://acmicpc.net/problem/30951) 

### 성능 요약

메모리: 2052 KB, 시간: 24 ms

### 분류

기하학, 수학, 삼분 탐색

### 제출 일자

2024년 02월 22일 21:35:25

### 문제 설명

<p>Alice and Bob are playing a game in the sand outside their mansion. A circle representing the Moon is drawn somewhere, and they each also pick a place to stand (inside, on the edge, or outside the Moon). The goal of the game is that one of the players runs to the other as fast as possible, while also touching the Moon during the run.</p>

<p>Given the positions of the Moon, Alice, and Bob, find the length of the shortest path that starts at one of the players, touches (or crosses) the edge or the interior of the Moon, and ends at the position of the other player.</p>

### 입력 

 <p>The first line contains an integer $T$, the number of test cases. It's followed by $T$ lines, each containing 7 space-separated integers $x_A$, $y_A$, $x_B$, $y_B$, $x_C$, $y_C$, $r$, representing coordinates of Alice, $A = (x_A, y_A)$, Bob, $B = (x_B, y_B)$, the center of the circle, $C = (x_C, y_C)$, and its radius $r$.</p>

### 출력 

 <p>For each test case output a single decimal number representing the length of the shortest path from $A$ to $B$ that also touches at least one point inside or on the edge of a circle with the center $C$ and radius $r$. The solution will be considered correct if the relative or absolute error compared to the official solution is within $10^{-6}$.</p>

