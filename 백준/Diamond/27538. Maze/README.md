# [Diamond III] Maze - 27538 

[문제 링크](https://acmicpc.net/problem/27538) 

### 성능 요약

메모리: 175232 KB, 시간: 611 ms

### 분류

0-1 너비 우선 탐색, 너비 우선 탐색, 데이크스트라, 그래프, 그래프 탐색, 구현, 최단 경로

### 제출 일자

2026년 11월 27일 18:33:11

### 문제 설명

<p>President K loves solving mazes. He found cells from which he may create a maze. The cells are rectangular grid with $R$ horizontal rows and $C$ vertical columns. Each cell is colored either white or black. The cell in the $i$-th row ($1 ≤ i ≤ R$) from the top and the $j$-th column ($1 ≤ j ≤ C$) from the left is called Cell $(i, j)$.</p>

<p>President K will solve the maze under the condition that he can pass the white cells, but he cannot pass the black cells. More precisely, he will solve the maze in the following way.</p>

<ol>
	<li>Among the white cells, he will choose Cell $(S_r, S_c)$, which is the starting cell of the maze, and Cell $(G_r, G_c)$, which is the goal cell of the maze.</li>
	<li>It is possible to move from one cell to another white cell which is adjacent to the current cell in one of the four directions (top, bottom, left, or right). By repeating this, he will find a path from the starting cell to the goal cell.</li>
</ol>

<p>President K already fixed the starting cell and the goal cell. However, he noticed that in some situations of the colors of the cells, there might not be a path from the starting cell to the goal cell consisting of white cells only. He has a stamp of size $N \times N$. He will perform the following <strong>Operations</strong> several times so that there will be a path from the starting cell to the goal cell consisting of white cells only.</p>

<blockquote>
<p><strong>Operation</strong> He chooses a square region of $N \times N$ cells, and paint the cells in the region white. More precisely, he chooses integers $a$, $b$ satisfying $1 ≤ a ≤ R - N + 1$ and $1 ≤ b ≤ C - N + 1$, and for every pair $(i, j)$ of integers satisfying $a ≤ i ≤ a + N - 1$ and $b ≤ j ≤ b + N - 1$, he paints Cell $(i, j)$ white.</p>
</blockquote>

<p>Since his hands becomes dirty if he uses the stamp, he wants to minimize the number of operations. Given information of the colors of the cells, the size of the stamp, and the locations of the starting cell and the goal cell, write a program which calculates the minimum number of operations he has to perform so that there will be a path from the starting cell to the goal cell consisting of white cells only.</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<blockquote>
<p>$R$ $C$ $N$</p>

<p>$S_r$ $S_c$</p>

<p>$G_r$ $G_c$</p>

<p>$A_1$</p>

<p>$A_2$</p>

<p>$\vdots$</p>

<p>$A_R$</p>
</blockquote>

<p>$A_i$ ($1 ≤ i ≤ R$) is a string of length $C$ consisting of <code>.</code> or <code>#</code>. The $j$-th character ($1 ≤ j ≤ C$) of $A_i$ represents the color of Cell $(i, j)$. Its color is white if the character is <code>.</code>, and its color is black if the character is <code>#</code>.</p>

### 출력 

 <p>Write one line to the standard output. The output should contain the minimum number of operations President K has to perform so that there will be a path from the starting cell to the goal cell consisting of white cells only.</p>

