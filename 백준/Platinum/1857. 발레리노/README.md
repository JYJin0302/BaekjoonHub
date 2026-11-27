# [Platinum I] 발레리노 - 1857 

[문제 링크](https://acmicpc.net/problem/1857) 

### 성능 요약

메모리: 2072 KB, 시간: 0 ms

### 분류

너비 우선 탐색, 데이크스트라, 다이나믹 프로그래밍, 그래프, 그래프 탐색, 집합과 맵

### 제출 일자

2024년 05월 25일 20:42:03

### 문제 설명

<p>FJ has installed a beautiful pond for his cows' aesthetic enjoyment and exercise.</p>

<p>The rectangular pond has been partitioned into square cells of M rows and N columns (1 <= M <= 30; 1 <= N <= 30). Some of the cells have astonishingly sturdy lilypads; others have rocks; the remainder are just beautiful, cool, blue water.</p>

<p>Bessie is practicing her ballet moves by jumping from one lilypad to another and is currently located at one of the lilypads. She wants to travel to another lilypad in the pond by jumping from one lilypad to another.</p>

<p>Surprising only to the uninitiated, Bessie's jumps between lilypads always appear as a chess-knight's move: one move in one direction and then two more in the orthogonal direction (or perhaps two in one direction and then one in the orthogonal direction).</p>

<p>Farmer John is observing Bessie's ballet drill and realizes that sometimes she might not be able to jump to her destination lilypad because intermediary lilypads are missing.</p>

<p>Ever thrifty, he wants to place additional lilypads so she can complete her quest (perhaps quickly, perhaps by using a large number of intermediate lilypads). Of course, lilypads cannot be placed where rocks already intrude on a cell.</p>

<p>Help Farmer John determine the minimum number of additional lilypads he has to place, and in how many ways he can place that minimum number.</p>

### 입력 

 <p>* Line 1: Two space-separated integers: M and N</p>

<p>* Lines 2..M+1: Line i+1 describes row i of the pond using N space-separated integers with these values: 0 indicates empty water; 1 indicates a lilypad in place; 2 indicates rock in place; 3 indicates the lilypad Bessie starts on; 4 indicates the lilypad Bessie wants to travel to.</p>

### 출력 

 <p>* Line 1: One integer: the minimum number of additional lilypads required. If it is not possible to help Bessie jump to her destination, print -1.</p>

<p>* Line 2: One integer: the total number of possible ways the additional lilypads can be positioned.  This number is guaranteed to fit into a single 64-bit signed integer. Do not output this line if line 1 contains -1.</p>

