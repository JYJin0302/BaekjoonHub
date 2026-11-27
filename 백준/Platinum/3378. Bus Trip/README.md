# [Platinum II] Bus Trip - 3378 

[문제 링크](https://acmicpc.net/problem/3378) 

### 성능 요약

메모리: 6560 KB, 시간: 80 ms

### 분류

다이나믹 프로그래밍, 그래프, 정렬, 스위핑

### 제출 일자

2026년 02월 26일 14:49:37

### 문제 설명

<p>There are N towns, and M one-way direct bus routes (no intermediate stops) between them. The towns are numbered from 1 to N. A traveler who is located in the town 1 at time 0 needs to arrive in the town P. He will be picked from the bus station at town P exactly at time T. If he arrives earlier he will have to wait.</p>

<p>For each bus route i, we know the source and destination towns s<sub>i</sub> and t<sub>i</sub>, of course. We also know the departure and arrival times, but only approximately: we know that the bus departs from s<sub>i</sub> within the range [a<sub>i</sub>, b<sub>i</sub>] and arrives at t<sub>i</sub> within the range [c<sub>i</sub>, d<sub>i</sub>] (endpoints included in both cases).</p>

<p>The traveler does not like waiting, and therefore is looking for a travel plan which minimizes the maximal possible waiting time while still guaranteeing that he'll not miss connecting buses (that is, every time he changes buses, the latest possible arrival of the incoming bus must not be later than the earliest possible departure time of the outgoing bus).</p>

<p>When counting waiting time we have to assume the earliest possible arrival time and the latest possible departure time.</p>

<p>Write a program to help the traveler to find a suitable plan.</p>

### 입력 

 <p>The first line contains the integer numbers N (1 ≤ N ≤ 50,000), M (1 ≤ M ≤ 100,000), P (1 ≤ P ≤ N), and T (0 ≤ T ≤ 1,000,000,000).</p>

<p>The following M lines describe the bus routes. Each line contains the integer numbers s<sub>i</sub>, t<sub>i</sub>, a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub>, d<sub>i</sub>, where s<sub>i</sub> and t<sub>i</sub> are the source and destination towns of the bus route i, and a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub>, d<sub>i</sub> describe the departure and arrival times as explained above (1 ≤ s<sub>i</sub> ≤ N, 1 ≤ t<sub>i</sub> ≤ N, 0 ≤ a<sub>i</sub> ≤ b<sub>i</sub> < c<sub>i</sub> ≤ d<sub>i</sub> ≤ 1,000,000,000).</p>

### 출력 

 <p>The only line of the output should contain the maximal possible total waiting time for the most suitable possible travel plan. If it is not possible to guarantee arrival in town P by time T, the line should contain –1.</p>

