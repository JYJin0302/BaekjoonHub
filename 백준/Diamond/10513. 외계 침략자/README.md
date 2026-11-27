# [Diamond IV] 외계 침략자 - 10513 

[문제 링크](https://acmicpc.net/problem/10513) 

### 성능 요약

메모리: 4128 KB, 시간: 1168 ms

### 분류

다이나믹 프로그래밍, 정렬

### 제출 일자

2023년 08월 29일 15:49:29

### 문제 설명

<p>The aliens from outer space have (finally!) invaded Earth. Defend yourself, or be disintegrated! Or assimilated. Or eaten. We are not yet sure.</p>

<p>The aliens follow a known attack pattern. There are n attackers, the i-th one appears at time a<sub>i</sub>, at distance d<sub>i</sub> from you. He must be destroyed no later than at time b<sub>i</sub>, or else he will fire his weapon, which will definitely end the fight.</p>

<p>Your weapon is an area-blaster, which can be set to any given power. If fired with power R, it momentarily destroys all aliens at distance R or smaller. It also consumes R fuel cells.</p>

<p>Determine the minimal cost (measured in fuel cells) of destroying all the aliens, without being killed.</p>

### 입력 

 <p>The first line of input contains the number of test cases T. The descriptions of the test cases follow:</p>

<p>Each test case starts with a line containing the number of aliens n (1 ≤ n ≤ 300). Of the next n lines, the i-th one contains three integers a<sub>i</sub>, b<sub>i</sub>, d<sub>i</sub>, (1 ≤ a<sub>i</sub> < b<sub>i</sub> ≤ 10 000; 1 ≤ d<sub>i</sub> ≤ 10 000). The i-th alien appears at time a<sub>i</sub>, is idle until b<sub>i</sub>, and his distance from you is d<sub>i</sub>.</p>

### 출력 

 <p>For each test case, output one line containing the minimum number of cells needed to destroy all the aliens.</p>

