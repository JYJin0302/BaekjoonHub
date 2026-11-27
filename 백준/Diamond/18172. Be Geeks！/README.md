# [Diamond V] Be Geeks! - 18172 

[문제 링크](https://acmicpc.net/problem/18172) 

### 성능 요약

메모리: 22048 KB, 시간: 536 ms

### 분류

분할 정복, 자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리, 희소 배열

### 제출 일자

2023년 10월 29일 13:38:21

### 문제 설명

<p>The musical band Be Geeks! got its name by no accident, as all the members are genuine math geeks. Among others, they love examining various properties of number sequences. Let’s see an example of their subject of interest.</p>

<ul>
	<li>Let A be a nonempty sequence of positive integers, A = (a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>N</sub>).</li>
	<li>Let G(i, j) = gcd(a<sub>i</sub>, a<sub>i+1</sub>, . . . , a<sub>j</sub>), where 1 ≤ i ≤ j ≤ N.</li>
	<li>Let M(i, j) = max(a<sub>i</sub>, a<sub>i+1</sub>, . . . , a<sub>j</sub>), where 1 ≤ i ≤ j ≤ N.</li>
	<li>Let P(i, j) = G(i, j) · M(i, j), where 1 ≤ i ≤ j ≤ N.</li>
	<li>Let F(A) = ΣP(i, j) over all pairs of integers 1 ≤ i ≤ j ≤ N.</li>
</ul>

<p>The function gcd stands for the greatest common divisor of the given values. The greatest common divisor of a nonempty sequence of integers is the biggest integer which divides each integer in the sequence evenly.</p>

### 입력 

 <p>The first line contains one integer N (1 ≤ N ≤ 2 · 10<sup>5</sup>). The next line contains N integers a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>N</sub> (1 ≤ a<sub>i</sub> ≤ 10<sup>9</sup>).</p>

### 출력 

 <p>Print the value of F(A) modulo 1 000 000 007.</p>

