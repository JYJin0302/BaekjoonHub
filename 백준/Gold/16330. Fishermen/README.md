# [Gold II] Fishermen - 16330 

[문제 링크](https://acmicpc.net/problem/16330) 

### 성능 요약

메모리: 14440 KB, 시간: 152 ms

### 분류

이분 탐색, 자료 구조, 누적 합, 정렬

### 제출 일자

2023년 11월 16일 13:17:03

### 문제 설명

<p>The ocean can be represented as the first quarter of the Cartesian plane.</p>

<p>There are n fish in the ocean. Each fish has its own coordinates. There may be several fish at one point. There are also m fishermen.</p>

<p>Each fisherman has its own x-coordinate. The y-coordinate of each fisherman is equal to 0.Each fisherman has a fishing rod of length l. Therefore, he can catch a fish at a distance less than or equal to l. The distance between a fisherman in position x and a fish in position (a, b) is |a − x| + b.</p>

<p>Find for each fisherman how many fish he can catch.</p>

### 입력 

 <p>The first line contains three integers n, m, and l (1 ≤ n, m ≤ 2 · 10<sup>5</sup>, 1 ≤ l ≤ 10<sup>9</sup>) — the number of fish, the number of fishermen, and the length of the fishing rod, respectively.</p>

<p>Each of the next n lines contains two integers x<sub>i</sub> and y<sub>i</sub> (1 ≤ x<sub>i</sub>, y<sub>i</sub> ≤ 10<sup>9</sup>) — the fish coordinates.</p>

<p>Next line contains m integers a<sub>i</sub> (1 ≤ a<sub>i</sub> ≤ 10<sup>9</sup>) — the fishermen coordinates.</p>

### 출력 

 <p>For each fisherman, output the number of fish that he can catch, on a separate line.</p>

