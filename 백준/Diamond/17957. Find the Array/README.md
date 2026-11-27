# [Diamond III] Find the Array - 17957 

[문제 링크](https://acmicpc.net/problem/17957) 

### 성능 요약

메모리: 13976 KB, 시간: 76 ms

### 분류

애드 혹, 이분 탐색, 비트마스킹, 분할 정복

### 제출 일자

2023년 08월 05일 01:12:08

### 문제 설명

<p>There is an array a of length n, consisting of <strong>distinct</strong> integers. It is guaranteed that every element of the array is a positive integer less than or equal to 10<sup>9</sup>. You have to find out the values of all the elements of it.</p>

<p>To do so, you can make up to 30 queries of the following two types:</p>

<ul>
	<li>“1 i” (1 ≤ i ≤ n) — ask the value of a<sub>i</sub></li>
	<li>“2 k i<sub>1</sub>, i<sub>2</sub>, . . . , i<sub>k</sub>” (2 ≤ k ≤ n, 1 ≤ i<sub>j</sub> ≤ n, all i<sub>j</sub> must be distinct) — the number k and k positions in the array. As the answer to this query you will receive k·(k−1)/2 integers — |a<sub>i<sub>c</sub></sub> − a<sub>i<sub>d</sub></sub>| for every c < d. In other words, you will receive k·(k−1)/2 absolute values of differences between all pairs of elements that are on positions i<sub>1</sub>, i<sub>2</sub>, . . . , i<sub>k</sub>. Note that the answer on query 2 is randomly shuffled.</li>
</ul>

<p>Once you know the answer, print it using the following query:</p>

<ul>
	<li>“3 a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>n</sub>” (1 ≤ a<sub>i</sub> ≤ 10<sup>9</sup>) — the elements of the array a. After this query, your program must terminate. This query doesn’t count (i.e. you can make up to 30 queries of either of the first two types plus 1 query of the third type).</li>
</ul>

### 입력 

 Empty

### 출력 

 Empty

