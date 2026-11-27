# [Diamond II] Lone Knight - 27585 

[문제 링크](https://acmicpc.net/problem/27585) 

### 성능 요약

메모리: 22692 KB, 시간: 3384 ms

### 분류

자료 구조, 분리 집합, 그래프

### 제출 일자

2024년 01월 21일 20:45:32

### 문제 설명

<p>In the game of chess, a knight moves as shown in the picture below; each move is one square horizontally and two squares vertically or two squares horizontally and one square vertically. A rook can move any number of squares horizontally or vertically, but not both in the same move. If a square can be reached by a rook in one move, that square is said to be attacked by the rook.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 151px; height: 150px;"> <img alt="" src="" style="width: 151px; height: 150px;"></p>

<p>Consider an infinite chess board, with squares that can be indexed by integer coordinates.  There is a white knight on the board on a square, and it wants to go to another square. However, there are also a number of black rooks on the board. The knight can make as many moves as it needs to get to its target square, but it cannot stop on a square that is attacked by or occupied by a rook.  The rooks don't move.</p>

<p>Can the white knight reach its target square? You are to answer that question many times!</p>

### 입력 

 <p>The first line of input contains two integers $n$ and $q$ ($1 \leq n, q \leq 1\,000$), where $n$ is the number of black rooks and $q$ is the number of queries.</p>

<p>Each of the next $n$ lines contains two integers $x$ and $y$. This indicates that there is a black rook at $(x,y)$. No two rooks share the same square.</p>

<p>Each of the next $q$ lines contains four integers $x_s$, $y_s$, $x_t$ and $y_t$. This is a query, where the white knight starts at square $(x_s,y_s)$ and wants to move to square $(x_t,y_t)$.</p>

<p>All square coordinates in the input are no larger than $10^9$ in absolute value.  It is guaranteed that in every query the knight's initial and target squares are not attacked by or occupied by any rook, and the target square is not the same as the initial square.</p>

### 출력 

 <p>For each query, output on a single line <code>1</code> if the knight can reach the target square, or <code>0</code> otherwise.</p>

