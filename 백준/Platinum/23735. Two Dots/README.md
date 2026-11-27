# [Platinum III] Two Dots - 23735 

[문제 링크](https://acmicpc.net/problem/23735) 

### 성능 요약

메모리: 23200 KB, 시간: 136 ms

### 분류

자료 구조, 기하학, 스택

### 제출 일자

2025년 10월 09일 00:16:27

### 문제 설명

<p><strong><em>"Only 1% can solve this problem!!!"</em></strong></p>

<p>One day, Yunee saw an advertisement for the game named "Two Dots". The goal of this game was to connect all pairs of points with the same colors.</p>

<p>The rules are as follows. The game area is a square of size $L\times L$. $N$ points are on the square, some completely inside and others on the boundary. They are divided into $N/2$ pairs by their colors. You can connect a pair of points by drawing a curved line connecting them. The lines must lie completely inside the square and never cross each other.</p>

<p>Yunee found that the problem in the advertisement could never be solved. Mad at this, Yunee is going to report this ad as a false advertisement by proving that the problem cannot be solved. If the problem can't be solved, then only 0% can solve this problem!!!</p>

<p>Help Yunee write a program to determine whether it is possible to solve a given problem.</p>

<p style="text-align: center;"><img alt="" src="" style="max-width: 100%; width: 600px;"></p>

### 입력 

 <p>The first line contains an integer $L$ $(1\leq L \leq 100,000)$ and an even integer $N$ $(2\leq N\leq \min[300,000, (L+1)^2])$. $L$ is the side length of the game area and $N$ is the number of points. The four vertices of the game area are $(0, 0), (L, 0), (L, L)$ and $(0, L)$.</p>

<p>The next $N$ lines describe the points. The $i$-th line contains the coordinate $x, y$ and the color $c$ of the $i$-th point $(0 \leq x, y \leq L, 1 \leq c \leq N/2)$. The coordinates of the $N$ points are distinct. There are exactly two points with each color $c=1,\cdots,N/2$.</p>

### 출력 

 <p>Output <code>1%</code> if it is possible to solve the problem, and <code>0%</code> otherwise.</p>

