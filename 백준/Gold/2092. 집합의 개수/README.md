# [Gold II] 집합의 개수 - 2092 

[문제 링크](https://acmicpc.net/problem/2092) 

### 성능 요약

메모리: 2156 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 03월 26일 14:52:51

### 문제 설명

<p>Bessie was poking around the ant hill one day watching the ants march to and fro while gathering food. She realized that many of the ants were siblings, indistinguishable from one another. She also realized the sometimes only one ant would go for food, sometimes a few, and sometimes all of them. This made for a large number of different sets of ants!</p>

<p>Being a bit mathematical, Bessie started wondering. Bessie noted that the hive has T (1 <= T <= 1,000) families of ants which she labeled 1..T (A ants altogether). Each family had some number Ni (1 <= Ni <= 100) of ants.</p>

<p>How many groups of sizes S, S+1, ..., B (1 <= S <= B <= A) can be formed?</p>

<p>While observing one group, the set of three ant families was seen as {1, 1, 2, 2, 3}, though rarely in that order. The possible sets of marching ants were:</p>

<ul>
	<li>3 sets with 1 ant: {1} {2} {3}</li>
	<li>5 sets with 2 ants: {1,1} {1,2} {1,3} {2,2} {2,3}</li>
	<li>5 sets with 3 ants: {1,1,2} {1,1,3} {1,2,2} {1,2,3} {2,2,3}</li>
	<li>3 sets with 4 ants: {1,2,2,3} {1,1,2,2} {1,1,2,3}</li>
	<li>1 set with 5 ants: {1,1,2,2,3}</li>
</ul>

<p>Your job is to count the number of possible sets of ants given the data above.</p>

### 입력 

 <ul>
	<li>Line 1: 4 space-separated integers: T, A, S, and B</li>
	<li>Lines 2..A+1: Each line contains a single integer that is an ant type present in the hive</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: The number of sets of size S..B (inclusive) that can be created. A set like {1,2} is the same as the set {2,1} and should not be double-counted. Print only the LAST SIX DIGITS of this number, with no leading zeroes or spaces.</li>
</ul>

