# [Diamond IV] Loops - 30607 

[문제 링크](https://acmicpc.net/problem/30607) 

### 성능 요약

메모리: 28448 KB, 시간: 136 ms

### 분류

애드 혹, 해 구성하기, 방향 비순환 그래프, 그래프, 위상 정렬

### 제출 일자

2024년 09월 26일 13:18:02

### 문제 설명

<p>Consider four integers $A$, $B$, $C$, and $D$, such that $A < B < C < D$. Let's put them in the corners of a square in some order and draw a loop $A - B - C - D - A$. Depending on the arrangement of the integers, we can get different loop shapes, but some arrangements produce the same shape:</p>

<p style="text-align: center;"><img alt="" src="" style="width: 387px; height: 72px;"></p>

<p>There are three possible loop shapes we can get:</p>

<p style="text-align: center;"><img alt="" src="" style="width: 154px; height: 68px;"></p>

<p>Now consider an $n\times m$ matrix filled with distinct integers from $1$ to $nm$, inclusive. Each $2\times 2$ square in this matrix can be seen as a square with integers in its corners. Let's build a loop for each of these squares like we did before:</p>

<p style="text-align: center;"><img alt="" src="" style="width: 129px; height: 92px;"></p>

<p>Your task is to perform the inverse operation. You are given the shape types for all $(n-1)(m-1)$ loops, and you need to build an $n\times m$ matrix filled with distinct integers from $1$ to $nm$, inclusive, that produces these shapes.</p>

### 입력 

 <p>The first line contains two integers $n$ and $m$ ($2\le n, m\le 500$).</p>

<p>Each of the next $n-1$ lines contains a string of $m-1$ characters without spaces. Each character is a digit from $1$ to $3$, denoting the type of the shape of the corresponding loop.</p>

### 출력 

 <p>Print an $n\times m$ matrix filled with distinct integers from $1$ to $nm$, inclusive, that produces the shapes of the loops in the input.</p>

<p>It can be shown that such a matrix always exists. If there are multiple answers, print any of them.</p>

