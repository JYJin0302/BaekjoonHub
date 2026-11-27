# [Platinum V] Corral the Cows - 26986 

[문제 링크](https://acmicpc.net/problem/26986) 

### 성능 요약

메모리: 6140 KB, 시간: 120 ms

### 분류

브루트포싱, 누적 합, 정렬, 스위핑, 값 및 좌표 압축

### 제출 일자

2024년 04월 08일 20:13:16

### 문제 설명

<p>Farmer John wishes to build a corral for his cows. Being finicky beasts, they demand that the corral be square and that the corral contain at least C (1 ≤ C ≤ 500) clover fields for afternoon treats. The corral's edges must be parallel to the X,Y axes.</p>

<p>FJ's land contains a total of N (C ≤ N ≤ 500) clover fields, each a block of size 1 x 1 and located at with its lower left corner at integer X and Y coordinates each in the range 1..10,000. Sometimes more than one clover field grows at the same location; such a field would have its location appear twice (or more) in the input. A corral surrounds a clover field if the field is entirely located inside the corral's borders.</p>

<p>Help FJ by telling him the side length of the smallest square containing C clover fields.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: C and N</li>
	<li>Lines 2..N+1: Each line contains two space-separated integers that are the X,Y coordinates of a clover field.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single line with a single integer that is length of one edge of the minimum size square that contains at least C clover fields.</li>
</ul>

