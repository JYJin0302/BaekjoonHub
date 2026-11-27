# [Platinum I] Hole in One - 11673 

[문제 링크](https://acmicpc.net/problem/11673) 

### 성능 요약

메모리: 2028 KB, 시간: 88 ms

### 분류

브루트포싱, 기하학, 구현, 선분 교차 판정, 시뮬레이션

### 제출 일자

2023년 10월 13일 15:26:06

### 문제 설명

<p>Janine recently went to her local game store and bought “Hole in One”, a new mini-golf game for her computer. As indicated by the name, the objective of the game is to shoot a ball into a hole using just one shot. The game also borrows elements from brick breaker style games: in the playing field, several walls are placed that will be destroyed upon being hit by the ball. The score of a successful shot depends on the number of destroyed walls, so Janine wonders: what is the maximum number of walls that can be hit while performing a “Hole in One”?</p>

<p>For the purposes of this problem you can think of the playing field as a cartesian plane with the initial position of the ball at the origin. The walls are non-intersecting axis-parallel line segments in this plane (i.e., parallel to either the x axis or the y axis). The diameter of the ball is negligible so it is represented as a single point.</p>

<p style="text-align: center;"><img alt="" src="" style="height:194px; width:340px"></p>

<p style="text-align: center;">Figure H.1: Illustration of the first sample input: The ball first bounces off two walls at points 1 and 2. When it passes point 3 the wall has already vanished.</p>

<p>Whenever the ball hits a wall, two things happen:</p>

<ul>
	<li>The direction of the ball changes in the usual way: the angle of incidence equals the angle of reflection.</li>
	<li>The wall that the ball touched is destroyed. Following common video game logic, no rubble of the wall remains; it will be as though it vanished.</li>
</ul>

<p>The behaviour of the ball is also affected by the power of the shot. In particular, an optimal shot may need to first roll over the hole, then hit some more walls, and only later drop into the hole.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line with one integer n (0 ≤ n ≤ 8), the number of walls;</li>
	<li>one line with two integers x and y, the coordinates of the hole;</li>
	<li>n lines each with four integers x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub>, and y<sub>2</sub> (either x<sub>1</sub> = x<sub>2</sub>, or y<sub>1</sub> = y<sub>2</sub>, but not both), representing a wall with end points (x<sub>1</sub>, y<sub>1</sub>) and (x<sub>2</sub>, y<sub>2</sub>).</li>
</ul>

<p>The hole is not at the origin and not on a wall. The walls do not touch or intersect each other. No wall lies completely on the x axis or the y axis. All coordinates in the input are integers with absolute value at most 1 000.</p>

### 출력 

 <p>If there is no way to shoot the ball such that it reaches the hole, print “impossible”. Otherwise, print the maximum number of walls that can be destroyed in a single “Hole in One” shot.</p>

