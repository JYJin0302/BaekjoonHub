# [Diamond V] River Game - 18304 

[문제 링크](https://acmicpc.net/problem/18304) 

### 성능 요약

메모리: 6132 KB, 시간: 0 ms

### 분류

비트마스킹, 비트필드를 이용한 DP, 다이나믹 프로그래밍, 플러드 필, 게임 이론, 그래프, 그래프 탐색, 스프라그–그런디 정리

### 제출 일자

2023년 02월 13일 16:16:31

### 문제 설명

<p>Together with an ornithologist friend, you are spending hours bird-watching in wetlands, waiting for a rare bird that you want to take a picture of.</p>

<p>In order to kill time, you devised a little game. The wetland is represented by an N × N grid made of 3 types of squares: firm ground, wet zone, and protected zone.</p>

<p>Connected wet zone squares form wet areas, which are maximal sets of wet zone squares such that we can go from any square of the area to any other square of the area by a path of connected wet zone squares. Two squares are considered connected when they share one edge, so that squares not on the border of the grid are connected to 4 other squares. Each wet area must be connected to both the left and right sides of the grid, and does not contain more than 2N wet zone squares. Two wet zone squares that belong to two different wet areas will always be at distance at least 3 from each other, the distance being counted by moving horizontally or vertically on the grid. For example, in the two examples below, the blue squares are at distance 3 from one another.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 557px; height: 202px;"></p>

<p>One after the other, you and your friend will each take turns placing a camera on the wetland with the following constraints:</p>

<ul>
	<li>The camera must be on a firm ground square.</li>
	<li>The camera must be adjacent to a wet zone square, so that you can take bird photos.</li>
	<li>The camera must not be on a protected zone square.</li>
	<li>There cannot be two cameras on the same square.</li>
	<li>No two cameras adjacent to the same wet area can be adjacent (again, the notion of adjacency means sharing an edge).</li>
</ul>

<p>The first player who cannot place a camera anymore loses the game.</p>

<p>Assuming both players play optimally, will the first player win or lose?</p>

### 입력 

 <p>The input consists of the following lines:</p>

<ul>
	<li>on the first line, the integer N;</li>
	<li>on the next N lines, a string representing a row of the grid: “*” represents a wet zone square, “.” represents a firm ground square and “x” represents a protected square.</li>
</ul>

### 출력 

 <p>The four words “First player will win” if the first player wins the game provided both players play optimally, or “Second player will win” otherwise.</p>

