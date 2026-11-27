# [Diamond V] Biking Duck - 10519 

[문제 링크](https://acmicpc.net/problem/10519) 

### 성능 요약

메모리: 42736 KB, 시간: 216 ms

### 분류

기하학, 구현, 삼분 탐색

### 제출 일자

2023년 10월 07일 18:54:02

### 문제 설명

<p>Gladstone Gander is walking through Duckburg and needs to get to his date with Daisy Duck as soon as possible. If he doesn’t get there in time, Donald might show up and take his place instead.</p>

<p>Duckburg has recently started providing a very eco-friendly way of public transport: bikes. At many bike stations throughout the city, one can pick up a free bike, ride it to another bike station, and drop it there. This gives Gladstone two ways of transportion: on foot or by bike. Biking is faster, of course, but he must pick up and leave the bikes at the designated stations. Gladstone can walk or bike between any two points in a straight line.</p>

<p>Gladstone possesses a map of the (rectangular) center of Duckburg. His current position is on this map and so is the meeting point with Daisy. The map also contains the locations of all bike stations within the boundaries of the map.</p>

<p>There can be way more bike stations though, that are not within the boundaries of the map. Considering his luck, you can assume that the moment Gladstone walks (or bikes) off the map, he encounters a bike station if that suits him well. The bike stations not on the map can be located anywhere outside the map, they do not have to lie on integer coordinates.</p>

<p>That leaves Gladstone with the task of figuring out which route to take. Can you help him out? Given the map and his infinite amount of luck, what is the fastest time to his date with Daisy?</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line with two integers vwalk and vbike (1 ≤ v<sub>walk</sub> < v<sub>bike</sub> ≤ 1 000), the speeds of walking and of biking;</li>
	<li>one line with four integers x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub> and y<sub>2</sub> (−10<sup>6</sup> ≤ x<sub>1</sub> < x<sub>2</sub> ≤ 10<sup>6</sup>; −10<sup>6</sup> ≤ y<sub>1</sub> < y<sub>2</sub> ≤ 10<sup>6</sup>), the bounding coordinates of the map of the center of Duckburg;</li>
	<li>one line with two integers x<sub>G</sub> and y<sub>G</sub>, Gladstone’s position;</li>
	<li>one line with two integers x<sub>D</sub> and y<sub>D</sub>, Daisy’s position;</li>
	<li>one line with one integer n (0 ≤ n ≤ 1 000), the number of known bike stations;</li>
	<li>n lines with two integers xstation and ystation each, the coordinates of the known bike stations.</li>
</ul>

<p>All coordinates are on the map of the center, i.e., x<sub>1</sub> ≤ x ≤ x<sub>2</sub> and y<sub>1</sub> ≤ y ≤ y<sub>2</sub>.</p>

### 출력 

 <p>Output one line with the shortest possible time for Gladstone to get to Daisy. Your answer should have an absolute or relative error of at most 10<sup>−6</sup>.</p>

