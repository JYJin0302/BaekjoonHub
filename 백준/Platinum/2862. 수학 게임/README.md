# [Platinum I] 수학 게임 - 2862 

[문제 링크](https://acmicpc.net/problem/2862) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 게임 이론, 수학

### 제출 일자

2021년 12월 07일 22:44:26

### 문제 설명

<p>Mirko and Slavko’s favourite pastime is competing against each other in mathematical games. This time they took a heap of N pebbles and settled on the following rules: </p>

<ol>
	<li>Mirko is the first to play, then Slavko, then Mirko again, then Slavko and so on; </li>
	<li>Mirko can take any number of pebbles (between 1 and N, inclusive) from the heap during his first move; </li>
	<li>In each of the following turns the current player must take at least 1 pebble and is allowed to take at most double the amount of pebbles taken during the previous turn by the other player; naturally, one cannot take more pebbles than the remaining amount in the heap; </li>
	<li>The player who takes the last pebble is the winner.</li>
</ol>

<p>Both Mirko and Slavko play optimally (if it is possible for one player to beat the other, that player will always win). We need to find the minimum number of pebbles that Mirko must take during his first turn such that he is guaranteed to win the game. </p>

### 입력 

 <p>The first and only line of input contains the positive integer N (2 ≤ N ≤ 10<sup>15</sup>), the number of pebbles in the starting heap. </p>

### 출력 

 <p>The first and only line of output must contain the required minimum number of pebbles that Mirko needs to remove during his first turn. </p>

