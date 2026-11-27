# [Diamond III] 최단 경로들 - 5250 

[문제 링크](https://acmicpc.net/problem/5250) 

### 성능 요약

메모리: 22144 KB, 시간: 148 ms

### 분류

데이크스트라, 자료 구조, 그래프, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리, 집합과 맵, 최단 경로, 트리

### 제출 일자

2024년 04월 23일 21:35:11

### 문제 설명

<p>Nikola lives in Bittown and he is in love with his girlfriend Anita from a town called Hextown. Nikola knows the country map very well, and he found the shortest path between these two towns. He calls this path lucky path. The map of the country can be described as a collection of towns connected with bidirectional roads.</p>

<p>One day the president of this country decided that there are going to be some works on the roads. In order to uphold the traffic in the country, only one road is going to be closed per day. </p>

<p>For each road on the lucky path, Nikola wants to know the length of the shortest path between Anita and him if that road is closed.</p>

### 입력 

 <p>The first line of input contains four integers: n — the number of cities; m — the number of roads between these towns; a — index of town Bittown where Nikola lives; b — the index of town Hextown where Anita lives. Towns are indexed with numbers 1, 2,…, n. Next m lines specify roads: each line contains three integers: u, v and w – there exist road between towns u and v with length w. Last line of the input contains number k followed by k numbers a = v<sub>1</sub>, v<sub>2</sub>, …, v<sub>k</sub> = b – the lucky path that Nikola uses. </p>

### 출력 

 <p>For every integer t = 1 … k – 1, in separate line, print the length of the shortest path between cities a and b, if the road (v<sub>t</sub>, v<sub>t+1</sub>) is closed. If there is no such path, output “-1” without quotes. </p>

