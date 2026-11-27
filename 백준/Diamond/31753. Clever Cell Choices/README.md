# [Diamond III] Clever Cell Choices - 31753 

[문제 링크](https://acmicpc.net/problem/31753) 

### 성능 요약

메모리: 2236 KB, 시간: 56 ms

### 분류

이분 매칭, 게임 이론, 그래프, 그래프 탐색

### 제출 일자

2024년 06월 03일 13:11:13

### 문제 설명

<p>Two players play the following game on an $N \times M$ grid:</p>

<ul>
	<li>Initially each cell of the grid is either empty or occupied.</li>
	<li>Players take turns placing a stone on an empty cell, occupying the cell. Each new stone must be adjacent to the last placed stone, with the exception of the starting stone that can be placed on any empty cell. A stone is adjacent to another stone if they are located in two cells that share a side.</li>
	<li>The game ends whenever a player cannot place a stone according to the above rules. In that case, the player who cannot place a stone loses the game, and the other player wins.</li>
</ul>

<p>A winning starting cell is a cell such that the first player wins the game if they place their starting stone there, assuming both players play optimally. Given a description of the initial grid, you must tell how many winning starting cells it has.</p>

### 입력 

 <p>The first line contains two integers $N$ and $M$ ($1 ≤ N, M ≤ 50$) indicating the dimensions of the grid.</p>

<p>Each of the next $N$ lines contains a string of length $M$. In the $i$-th string, the $j$-th character describes the initial state of cell $(i, j)$. The character is either “<code>.</code>” (dot) denoting an empty cell, or “<code>#</code>” (hash) representing an occupied cell.</p>

### 출력 

 <p>Output a single line with an integer indicating the number of winning starting cells.</p>

