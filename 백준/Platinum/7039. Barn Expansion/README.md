# [Platinum IV] Barn Expansion - 7039 

[문제 링크](https://acmicpc.net/problem/7039) 

### 성능 요약

메모리: 6420 KB, 시간: 32 ms

### 분류

애드 혹, 이분 탐색, 자료 구조, 집합과 맵, 정렬, 스위핑, 트리를 사용한 집합과 맵, 값 및 좌표 압축

### 제출 일자

2024년 04월 05일 17:56:12

### 문제 설명

<p>Farmer John has N (1 ≤ N ≤ 25,000) rectangular barns on his farm, all with sides parallel to the X and Y axes and integer corner coordinates in the range 0..1,000,000. These barns do not overlap although they may share corners and/or sides with other barns.</p>

<p>Since he has extra cows to milk this year, FJ would like to expand some of his barns. A barn has room to expand if it does not share a corner or a wall with any other barn. That is, FJ can expand a barn if all four of its walls can be pushed outward by at least some amount without bumping into another barn. If two barns meet at a corner, neither barn can expand.</p>

<p>Please determine how many barns have room to expand.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer, N</li>
	<li>Lines 2..N+1: Four space-separated integers A, B, C, and D, describing one barn. The lower-left corner of the barn is at (A,B) and the upper right corner is at (C,D).</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the number of barns that can be expanded.</li>
</ul>

