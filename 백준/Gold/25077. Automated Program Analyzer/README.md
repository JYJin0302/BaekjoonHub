# [Gold III] Automated Program Analyzer - 25077 

[문제 링크](https://acmicpc.net/problem/25077) 

### 성능 요약

메모리: 7564 KB, 시간: 388 ms

### 분류

자료 구조, 분리 집합, 값 및 좌표 압축

### 제출 일자

2025년 12월 24일 17:41:42

### 문제 설명

<p>Let $x_1, x_2, x_3, \dots$ be variables. $n$ constraints of form $x_i = x_j$ or $x_i \ne x_j$ are given. The task asks for whether it is possible to assign values to the variables so that all constraints can be satisfied. For example, if the constraints are $x_1 = x_2, x_2 = x_3, x_3 = x_4, x_1 \ne x_4$, then those constraints cannot be satisfied simultaneously.</p>

### 입력 

 <p>The first line of the input is an integer $t$ representing the number of instances to solve. The instances are independent. For each instance, the first line is an integer $n$ representing the number of constraints to be satisfied. In the following $n$ lines, each line has three integers $i,j,e$ representing an equality/inequality constraint. If $e = 1$, the constraint shall be $x_i = x_j$. If $e = 0$, the constraint shall be $x_i \ne x_j$.</p>

### 출력 

 <p>The output has $t$ lines. The $k$-th line of the output is a string <code>YES</code> or <code>NO</code>. Output <code>YES</code> if the constraints in that instance can be satisfied and <code>NO</code> otherwise.</p>

