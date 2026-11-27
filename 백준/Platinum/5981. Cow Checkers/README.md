# [Platinum III] Cow Checkers - 5981 

[문제 링크](https://acmicpc.net/problem/5981) 

### 성능 요약

메모리: 5928 KB, 시간: 4 ms

### 분류

게임 이론

### 제출 일자

2022년 01월 08일 23:43:18

### 문제 설명

<p>One day, Bessie decides to challenge Farmer John to a game of 'Cow Checkers'. The game is played on an M*N (1 <= M <= 1,000,000; 1 <= N <= 1,000,000) checkerboard that initially contains a single checker piece on the checkboard square coordinates (X, Y) (0 <= X < M; 0 <= Y < N). The bottom leftmost square of the checkerboard has coordinates (0, 0), and the top rightmost square has coordinates (M-1, N-1). Bessie always moves first, and then the two players alternate turns.  Each turn comprises one of three types of moves:</p>

<ol>
	<li>Move the checker piece to any square on the same row to the left of its current position.</li>
	<li>Move the checker piece to any square on the same column below its current position.</li>
	<li>Move the checker piece to any spot k squares below and k squares to the left of the current square (where k is any positive integer such that this new spot is still on the checkerboard).</li>
</ol>

<p>The first player unable to make a move (i.e., because the checker is at (0, 0)) loses. Given that Bessie always goes first, determine who will win the game if both play optimally.</p>

<p>Play and report the winner for T games (1 <= T <= 1,000) reading in a new X,Y starting value for each new game.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: M and N</li>
	<li>Line 2: A single integer: T</li>
	<li>Lines 3..T+2: Two space-separated integers: X and Y</li>
</ul>

### 출력 

 <p>Lines 1..T: Should contain either "Farmer John" or "Bessie" depending on who wins each  game.</p>

<p> </p>

