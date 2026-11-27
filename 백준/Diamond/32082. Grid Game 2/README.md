# [Diamond IV] Grid Game 2 - 32082 

[문제 링크](https://acmicpc.net/problem/32082) 

### 성능 요약

메모리: 2024 KB, 시간: 176 ms

### 분류

유클리드 호제법, 게임 이론, 수학, 정수론, 누적 합, 스프라그–그런디 정리

### 제출 일자

2024년 10월 18일 12:01:14

### 문제 설명

<p>You are playing “Grid Game 2” with your friend. There is a grid with $10^9$ rows (numbered from $1$ to $10^9$) and $10^9$ columns (numbered from $1$ to $10^9$). The cell at row $r$ and column $c$ is denoted as $(r, c)$.</p>

<p>Each cell can have a colour of either black or white. Initially, there are exactly $N$ black cells (numbered from $1$ to $N$). Black cell $i$ is located at $(R_i , C_i)$. The rest of the cells are white.</p>

<p>You and your friend will alternately take turn playing on this grid, and you are playing in the first turn. In one turn, a player will choose a black cell $(r, c)$, then toggle cells $(r - x, c - y)$ for all $0 ≤ x, y < \min(r, c)$. If a cell is toggled, then the cell becomes black if it was a white cell, and the cell becomes white if it was a black cell.</p>

<p>For example, the following illustration shows how the grid changes after a player chooses a black cell $(5, 4)$ in their turn.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 347px; height: 150px;"></p>

<p>A player who is unable to play on their turn, i.e. no remaining black cells, loses the game, and the opposing player wins the game. If you and your friend are playing optimally, determine who will win the game.</p>

### 입력 

 <p>The first line consists of an integer $N$ ($1 ≤ N ≤ 200\, 000$).</p>

<p>Each of the next $N$ lines consists of two integers $R_i$ $C_i$ ($1 ≤ R_i , C_i ≤ 10^9$). For $1 ≤ i < j ≤ N$, $(R_i , C_i) \ne (R_j , C_j )$.</p>

### 출력 

 <p>Output <code>FIRST</code> if you will win the game, or <code>SECOND</code> otherwise.</p>

