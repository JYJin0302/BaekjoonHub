# [Platinum IV] Dividing the Path - 7041 

[문제 링크](https://acmicpc.net/problem/7041) 

### 성능 요약

메모리: 14020 KB, 시간: 56 ms

### 분류

덱, 덱을 이용한 구간 최댓값 트릭, 다이나믹 프로그래밍, 자료 구조, 슬라이딩 윈도우

### 제출 일자

2024년 01월 25일 00:21:24

### 문제 설명

<p>Farmer John's cows have discovered that the clover growing along the ridge of the hill in his field is particularly good. To keep the clover watered, Farmer John is installing water sprinklers along the ridge of the hill. </p>

<p>To make installation easier, each sprinkler head must be installed along the ridge of the hill (which we can think of as a one-dimensional number line of length L (1 <= L <= 1,000,000); L is even). </p>

<p>Each sprinkler waters the ground along the ridge for some distance in both directions. Each spray radius is an integer in the range A..B (1 <= A <= B <= 1000). Farmer John needs to water the entire ridge in a manner that covers each location on the ridge by exactly one sprinkler head. Furthermore, FJ will not water past the end of the ridge in either direction. </p>

<p>Each of Farmer John's N (1 <= N <= 1000) cows has a range of clover that she particularly likes (these ranges might overlap). The ranges are defined by a closed interval (S,E). Each of the cow's preferred ranges must be watered by a single sprinkler, which might or might not spray beyond the given range. </p>

<p>Find the minimum number of sprinklers required to water the entire ridge without overlap. </p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and L </li>
	<li>Line 2: Two space-separated integers: A and B </li>
	<li>Lines 3..N+2: Each line contains two integers, S and E (0 <= S < E <= L) specifying the start end location respectively of a range preferred by some cow. Locations are given as distance from the start of the ridge and so are in the range 0..L.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: The minimum number of sprinklers required. If it is not possible to design a sprinkler head configuration for Farmer John, output -1.</li>
</ul>

