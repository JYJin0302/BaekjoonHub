# [Gold II] 소가 길을 건너간 이유 7 - 14461 

[문제 링크](https://acmicpc.net/problem/14461) 

### 성능 요약

메모리: 2648 KB, 시간: 12 ms

### 분류

데이크스트라, 그래프, 격자 그래프, 최단 경로

### 제출 일자

2020년 10월 09일 16:27:01

### 문제 설명

<p>Why did the cow cross the road? Well, one reason is that Farmer John's farm simply has a lot of roads, making it impossible for his cows to travel around without crossing many of them.</p>

<p>FJ's farm is arranged as an N×N square grid of fields (3 ≤ N ≤ 100), with a set of N−1 north-south roads and N−1 east-west roads running through the interior of the farm serving as dividers between the fields. A tall fence runs around the external perimeter, preventing cows from leaving the farm. Bessie the cow can move freely from any field to any other adjacent field (north, east, south, or west), as long as she carefully looks both ways before crossing the road separating the two fields. It takes her T units of time to cross a road (0 ≤ T ≤ 1,000,000).</p>

<p>One day, FJ invites Bessie to visit his house for a friendly game of chess. Bessie starts out in the north-west corner field and FJ's house is in the south-east corner field, so Bessie has quite a walk ahead of her. Since she gets hungry along the way, she stops at every third field she visits to eat grass (not including her starting field, but including possibly the final field in which FJ's house resides). Some fields are grassier than others, so the amount of time required for stopping to eat depends on the field in which she stops.</p>

<p>Please help Bessie determine the minimum amount of time it will take to reach FJ's house.</p>

### 입력 

 <p>The first line of input contains N and T. The next N lines each contain N positive integers (each at most 100,000) describing the amount of time required to eat grass in each field. The first number of the first line is the north-west corner.</p>

### 출력 

 <p>Print the minimum amount of time required for Bessie to travel to FJ's house.</p>

