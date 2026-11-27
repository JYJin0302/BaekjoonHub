# [Diamond IV] Biketopia’s Cyclic Track - 33136 

[문제 링크](https://acmicpc.net/problem/33136) 

### 성능 요약

메모리: 31404 KB, 시간: 264 ms

### 분류

애드 혹, 깊이 우선 탐색, 그래프, 그래프 탐색

### 제출 일자

2025년 07월 21일 15:46:41

### 문제 설명

<p>Biketopia is a country proud of its thriving bike culture. There are $N$ cities and $M$ two-way roads in the country. Each road is fully prepared for cyclists and connects a different pair of cities, in such a way that it is possible to travel between any two cities using one or more roads. Besides, each city is an endpoint of at least three roads.</p>

<p>With the annual bicycle racing tournament approaching, Biketopia needs to select a cyclic track along the roads to serve as the competition route. This track must form a closed loop of roads, passing through at least three distinct cities. While the track can pass through the same city multiple times, no road can be used more than once.</p>

<p>On race day, the roads selected for the track will be closed to the public, but the cities on the track will remain accessible. In past tournaments, some cities became unreachable due to road closures, causing significant disruptions. This is where your help is needed. Your task is to find a cyclic track such that, even after the track’s roads are closed, it remains possible to travel between any two cities in the country.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 265px; height: 200px;"></p>

<p>As an example, consider the illustration above, which corresponds to the first sample. The roads highlighted with dotted lines ($14$, $9$ and $12$) indicate the chosen competition track. This track forms a closed loop, visiting three different cities ($4$, $7$ and $8$). Note that it remains possible to travel between any pair of cities using the remaining roads. Additionally, another possible track is shown with dashed lines, illustrating that the solution is not unique.</p>

### 입력 

 <p>The first line contains two integers $N$ ($4 ≤ N ≤ 2 \cdot 10^5$) and $M$ ($6 ≤ M ≤ 3 \cdot 10^5$), indicating respectively the number of cities and the number of two-way roads. Each city is identified by a distinct integer from $1$ to $N$, and each road is identified by a distinct integer from $1$ to $M$.</p>

<p>The $i$-th of the next $M$ lines describes road $i$ with two integers $U$ and $V$ ($1 ≤ U, V ≤ N$ and $U \ne V$), indicating that the endpoints of the road are cities $U$ and $V$.</p>

<p>It is guaranteed that there is at most one road between each pair of cities, each city is an endpoint of at least three roads, and it is possible to travel between any two cities using one or more roads.</p>

### 출력 

 <p>If a valid track exists, output two lines. The first line must contain the number of roads in the track, and the second line must contain the identifiers of these roads listed in the order they appear in the track. If there are multiple solutions, output any of them.</p>

<p>If no valid track exists, output a line with the character “<code>*</code>” (asterisk) instead.</p>

