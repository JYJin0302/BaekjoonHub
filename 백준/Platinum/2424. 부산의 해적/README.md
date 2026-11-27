# [Platinum IV] 부산의 해적 - 2424 

[문제 링크](https://acmicpc.net/problem/2424) 

### 성능 요약

메모리: 16844 KB, 시간: 40 ms

### 분류

너비 우선 탐색, 그래프, 그래프 탐색, 구현, 시뮬레이션

### 제출 일자

2022년 05월 20일 23:38:31

### 문제 설명

<p>You have a treasure map that is arranged into a N × M grid. A grid square may be either sea or part of an island. In addition, the map shows the treasure and an enemy Viking ship that occupies one (sea) square. Finally, for convenience you have also drawn your own position.</p>

<p>Now you must set up a ﬁxed route to get the treasure. The route must start at your position, end at the treasure, and consist of a sequence of moves. In each move, you can go only to an (horizontally or vertically) adjacent square that is not part of an island. But beware: The Viking ship might follow you, using the same kind of moves! After each of your moves according to your route, the Viking ship may move or not. Your move and the Vikings’ reaction together is called a round.</p>

<p>After every round, the following checks are made:</p>

<ul>
	<li>If you are in line with the Viking ship (you are in the same vertical or horizontal line as the Viking ship with only sea between the Viking ship and you), you are dead.</li>
	<li>If you aren’t dead and at the treasure-spot, you get the treasure.</li>
</ul>

<p>Write a program that decides whether it is possible to set up a ﬁxed route in advance such that you can get the treasure by following this route and will not get killed by the Vikings – no matter how the Viking ship moves.</p>

### 입력 

 <p>The ﬁrst line of input contains two integers N and M, the dimensions of the map. Each of the following N lines contain M characters. Each character describes a square in the map, and is either . (sea), I (part of an island), V (the Viking ship), Y (your position), or T (the treasure). Each of V, Y, and T will occur exactly once.</p>

### 출력 

 <p>The only line of the output must contain the string YES, if it is possible to set up a route to get the treasure, or NO otherwise.</p>

