# [Platinum III] Summing Sums - 6150 

[문제 링크](https://acmicpc.net/problem/6150) 

### 성능 요약

메모리: 2412 KB, 시간: 12 ms

### 분류

분할 정복을 이용한 거듭제곱, 수학, 정수론

### 제출 일자

2024년 06월 24일 15:02:10

### 문제 설명

<p>The N (1 <= N <= 50,000) cows, conveniently numbered 1..N, are trying to learn some encryption algorithms. After studying a few examples, they have decided to make one of their own! However, they are not very experienced at this, so their algorithm is very simple:</p>

<p>Each cow i is given a starting number C_i (0 <= C_i < 90,000,000), and then all the cows perform the following process in parallel:</p>

<ul>
	<li>First, each cow finds the sum of the numbers of the other N-1 cows.</li>
	<li>After all cows are finished, each cow replaces her number with the sum she computed. To avoid very large numbers, the cows will keep track of their numbers modulo 98,765,431.</li>
</ul>

<p>They told Canmuu the moose about it in November; he was quite impressed.</p>

<p>Then one foggy Christmas Eve, Canmuu came to say:</p>

<p>"Your algorithm is too easy to break! You should repeat it T (1 <= T <= 1,414,213,562) times instead."</p>

<p>Obviously, the cows were very frustrated with having to perform so many repetitions of the same boring algorithm, so after many hours of arguing, Canmuu and the cows reached a compromise: You are to calculate the numbers after the encryption is performed!</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and T</li>
	<li>Lines 2..N+1: Line i+1 contains a single integer: C_i</li>
</ul>

### 출력 

 <ul>
	<li>Lines 1..N: Line i contains a single integer representing the number of cow i (modulo 98,765,431) at the end of the encryption.</li>
</ul>

