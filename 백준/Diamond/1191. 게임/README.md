# [Diamond V] 게임 - 1191 

[문제 링크](https://acmicpc.net/problem/1191) 

### 성능 요약

메모리: 11316 KB, 시간: 64 ms

### 분류

너비 우선 탐색, 다이나믹 프로그래밍, 자료 구조, 게임 이론, 그래프, 그래프 탐색, 해시를 사용한 집합과 맵, 구현

### 제출 일자

2024년 04월 12일 16:55:34

### 문제 설명

<p>Two players, A and B, play a game on a square board of size n × n. The squares of the board are either white or black. The game is played only on the white squares — the black ones are excluded from the game. Each player has one piece, initially placed at this player’s starting point — one of the white squares on the board. The starting point of A is diﬀerent than that of B.</p>

<p>In each move a player moves his piece to one of the neighboring white squares (either up, down, left or right). If the player moves his piece to the square currently occupied by his opponent’s piece, he gets an extra move (this way he jumps over the opponent). Note that in this case the direction of the second move can be diﬀerent than that of the ﬁrst move.</p>

<p>Player A moves ﬁrst, then players alternate. The goal of the game is to reach the opponent’s starting point. The player whose piece reaches his opponent’s starting point ﬁrst, wins the game. Even if the player’s last move consists of two jumps, and he only jumps over his opponent’s starting point (since it is occupied by his opponent), the player wins. We want to determine which player has a winning strategy (a player has a winning strategy if he can win regardless of his opponent’s moves).</p>

<table class="table table-bordered" style="width: 100%;">
	<tbody>
		<tr>
			<td style="width: 50%; text-align: center;"><img alt="" src="" style="width: 142px; height: 143px;"></td>
			<td style="width: 50%; text-align: center;"><img alt="" src="" style="width: 141px; height: 143px;"></td>
		</tr>
		<tr>
			<td style="width: 50%;">Figure 1. If A moves to the right on his first three moves, B will move up the first three moves. Thus, on the third move player B will reach the square with A’s piece and will be allowed to move again. Because of this, B will reach A’s starting point first and will win the game.</td>
			<td style="width: 50%;">Figure 2. A can start by moving one step to the right and one step down. Then, depending on the first two moves of B, he will either go down or right and evade B. This way A will reach B’s starting point first, thus winning the game. In fact we proved that A has a winning strategy.</td>
		</tr>
	</tbody>
</table>

<p>Write a program, that:</p>

<ul>
	<li>reads the layout of the grid and the starting points of the two players from the standard input,</li>
	<li>ﬁnds the player who has a winning strategy,</li>
	<li>writes the result to the standard output.</li>
</ul>

### 입력 

 <p>The first line of the standard input contains one integer t the number of test cases (1 ≤ t ≤ 10). After it the description of t tests appears. Each test is described as follows. In the first line of the test there is one integer n (2 ≤ n ≤ 300), the length of the side of the grid. Then next n lines contain the description of the grid. Each line consists of n characters (with no whitespaces between them). Each character is either ’<code>.</code>’ (a white square), ’<code>#</code>’ (a black square), ’<code>A</code>’ (the starting point of A) or ’<code>B</code>’ (the starting point of B).</p>

<p>You may assume that there exists a path of white squares between the starting points of A and B.</p>

### 출력 

 <p>For each test case exactly one line should be printed to standard output containing a single character ’<code>A</code>’ or ’<code>B</code>’, indicating the player who has a winning strategy.</p>

