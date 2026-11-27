# [Platinum V] Game - 7403 

[문제 링크](https://acmicpc.net/problem/7403) 

### 성능 요약

메모리: 3620 KB, 시간: 192 ms

### 분류

자료 구조, 게임 이론, 해시를 사용한 집합과 맵, 집합과 맵

### 제출 일자

2026년 03월 12일 15:12:03

### 문제 설명

<p>There is a legend that mathematicians in the XVIII century enjoyed playing the following game. </p>

<p>The game was played by three mathematicians. One of them was the game master. First of all, the game master declared some positive integer number $N$. After that he chose two different integer numbers $X$ and $Y$ ranging from 1 to $N$ and told their sum to one player and their product to the other player. Each player knew whether he was told the sum or the product of the chosen numbers.</p>

<p>After that the players in turn informed the game master whether they knew the numbers he had chosen. First the player who was told the sum said whether he knew the numbers, after that the player who was told the product did, and so on.</p>

<p>For example the dialog could look like this.</p>

<p>Game master: "Let $N$ be 10".</p>

<p>After that he chooses two numbers ranging from 1 to 10 and tells their sum to player $S$ and their product to player $P$.</p>

<p>Player $S$: "I don't know these numbers."</p>

<p>Player $P$: "I don't know these numbers."</p>

<p>Player $S$: "I don't know these numbers."</p>

<p>Player $P$: "I don't know these numbers."</p>

<p>Player $S$: "Oh, now I know these numbers. You have chosen 3 and 6."</p>

<p>Given $N$ and $M$ --- the number of times the players have said "I don't know these numbers", you have to find all possible pairs of numbers that could have been chosen by the game master.</p>

### 입력 

 <p>The first line of the input file contains $N$ and $M$ ($2 \le N \le 200$, $0 \le M \le 100$).</p>

### 출력 

 <p>First output the number of possible pairs of numbers that could have been chosen by the game master from the range 1 to $N$ if both players altogether had said "I don't know these numbers" $M$ times. After that output these pairs in arbitrary order, one on a line.</p>

