# [Platinum II] Far, Far Away - 16617 

[문제 링크](https://acmicpc.net/problem/16617) 

### 성능 요약

메모리: 3308 KB, 시간: 44 ms

### 분류

다이나믹 프로그래밍, 자료 구조, 플로이드–워셜, 그래프, 매개 변수 탐색, 최단 경로, 희소 배열

### 제출 일자

2026년 01월 03일 17:12:12

### 문제 설명

<p>As you know, the purpose of a journey is not to reach the destination but to make the trip. You want to make a trip with as many legs as possible. However, each leg of the trip costs some money and your budget is limited. Find the longest path!</p>

### 입력 

 <p>The first line contains two integers n (1 ≤ n ≤ 100), which is the number of locations, and m (1 ≤ m ≤ 10<sup>9</sup>), which is the amount of available money.</p>

<p>The next n lines describe the legs. Each of these lines contains n integers, where the j<sup>th</sup> integer of the i<sup>th</sup> line c<sub>ij</sub> is the cost of a leg from location i to location j (1 ≤ c<sub>ij</sub> ≤ 10<sup>9</sup> for each 1 ≤ i, j ≤ n). Your trip must start at location 1 and may end at any location.</p>

### 출력 

 <p>Display the maximum number of legs a trip from location 1 can have such that the sum of the costs of its legs is at most m. A trip may repeatedly visit the same location (including start and destination) and repeatedly use the same leg (paying its cost multiple times).</p>

