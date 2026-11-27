# [Gold IV] Trapped - 27099 

[문제 링크](https://acmicpc.net/problem/27099) 

### 성능 요약

메모리: 2044 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 그래프, 그래프 탐색, 격자 그래프

### 제출 일자

2023년 06월 21일 14:31:00

### 문제 설명

<p>Consider a maze marked with row and column numbers:</p>

<pre>   1 2 3 4 5 6 7
  +-+-+-+-+-+-+-+
1 |           |
  + +-+-+-+-+-+ +
2 |             |
  + +-+-+-+-+-+ +
3 | |   |   | | |
  + +-+ + +-+ + +
4 | |     |     |
  +-+-+-+-+-+-+-+</pre>

<p>This maze has one exit (right hand side, first row).  It is possible to reach the exit from many locations in the maze but not all of them (for instance, row 4, column 2).</p>

<p>Your task is to decide how many cells are isolated from an exit.</p>

### 입력 

 <ul>
	<li>Line 1: two space-separated integers R,C (1 ≤ R,C ≤ 35) that tell the number of rows and columns for the maze</li>
	<li>Lines 2..2*R+2: An ASCII map of the matrix just as above.  Walls are marked by '_' and '|'.  Wall intersections (and potential wall intersections) are marked by '+'.</li>
</ul>

### 출력 

 <p>On a single line, output one integer that tells the number of cells from which one can not find a way to exit the maze.</p>

