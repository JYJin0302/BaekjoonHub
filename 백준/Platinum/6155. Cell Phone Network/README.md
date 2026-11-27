# [Platinum III] Cell Phone Network - 6155 

[문제 링크](https://acmicpc.net/problem/6155) 

### 성능 요약

메모리: 2772 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 트리, 트리DP

### 제출 일자

2024년 07월 13일 12:08:11

### 문제 설명

<p>Farmer John has decided to give each of his cows a cell phone in hopes to encourage their social interaction. This, however, requires him to set up cell phone towers on his N (1 <= N <= 10,000) pastures (conveniently numbered 1..N) so they can all communicate.</p>

<p>Exactly N-1 pairs of pastures are adjacent, and for any two pastures A and B (1 <= A <= N; 1 <= B <= N; A != B) there is a sequence of adjacent pastures such that A is the first pasture in the sequence and B is the last. Farmer John can only place cell phone towers in the pastures, and each tower has enough range to provide service to the pasture it is on and all pastures adjacent to the pasture with the cell tower.</p>

<p>Help him determine the minimum number of towers he must install to provide cell phone service to each pasture.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N: Each line specifies a pair of adjacent pastures with two space-separated integers: A and B</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer indicating the minimum number of towers to install</li>
</ul>

