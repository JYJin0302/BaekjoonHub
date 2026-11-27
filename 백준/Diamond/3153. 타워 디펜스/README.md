# [Diamond V] 타워 디펜스 - 3153 

[문제 링크](https://acmicpc.net/problem/3153) 

### 성능 요약

메모리: 5868 KB, 시간: 4 ms

### 분류

2-SAT, 그래프, 강한 연결 요소

### 제출 일자

2024년 04월 21일 16:33:50

### 문제 설명

<p>We are being attacked on a map represented by a rectangular grid of R×S squares. The attackers are barefoot robbers, and we use small cannons on small wooden towers to defend ourselves. </p>

<p>Each tower is equipped with two cannons, placed to fire in a 90 degree angle. More precisely, cannons on one tower can be set to fire in one of the following four configurations: </p>

<ol>
	<li>fire left and down; </li>
	<li>fire down and right; </li>
	<li>fire right and up; </li>
	<li>fire up and left. </li>
</ol>

<p>A cannon ball that hits the attacker destroys him and continues to fly in the same direction. A cannon ball which hits a castle stops and does no damage to the castle (because castles are big and strong). But, when a cannon ball hits a tower, it destroys it (because towers are small and fragile). </p>

<p>We want to turn the cannons on the towers so that, when we fire exactly one shot from every cannon, we destroy all the attackers, and all our towers remain undamaged. </p>

### 입력 

 <p>The first line contains two integers R and S (1 ≤ R, S ≤ 100), the dimensions of the map. </p>

<p>The next R lines contain S characters each, the map. </p>

<p>Each character on the map can be the uppercase letter 'T' (tower), lowercase letter 'n' (attacker), the character '#' (castle) or the character '.' (empty). </p>

<p>Note: There will always be a solution, although not necessarily unique. </p>

### 출력 

 <p>Output the map in the same format as in the input, replacing 'T' characters with the orientations of the cannons – each tower should be replaced with one of the digits '1', '2', '3' or '4', corresponding to the four orientations as described above.</p>

