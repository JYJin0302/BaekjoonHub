# [Platinum III] 동전 게임 - 6000 

[문제 링크](https://acmicpc.net/problem/6000) 

### 성능 요약

메모리: 17676 KB, 시간: 32 ms

### 분류

다이나믹 프로그래밍, 게임 이론

### 제출 일자

2022년 01월 07일 22:55:51

### 문제 설명

<p>Farmer John's cows like to play coin games so FJ has invented with a new two-player coin game called Xoinc for them.</p>

<p>Initially a stack of N (5 <= N <= 2,000) coins sits on the ground; coin i from the top has integer value C_i (1 <= C_i <= 100,000).</p>

<p>The first player starts the game by taking the top one or two coins (C_1 and maybe C_2) from the stack. If the first player takes just the top coin, the second player may take the following one or two coins in the next turn. If the first player takes two coins then the second player may take the top one, two, three or four coins from the stack. In each turn, the current player must take at least one coin and at most two times the amount of coins last taken by the opposing player. The game is over when there are no more coins to take.</p>

<p>Afterwards, they can use the value of the coins they have taken from the stack to buy treats from FJ, so naturally, their purpose in the game is to maximize the total value of the coins they take. Assuming the second player plays optimally to maximize his own winnings, what is the highest total value that the first player can have when the game is over?</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N+1: Line i+1 contains a single integer: C_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer representing the maximum value that can be made by the first player.</li>
</ul>

<p> </p>

