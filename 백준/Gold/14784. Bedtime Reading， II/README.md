# [Gold IV] Bedtime Reading, II - 14784 

[문제 링크](https://acmicpc.net/problem/14784) 

### 성능 요약

메모리: 11792 KB, 시간: 44 ms

### 분류

브루트포싱, 그래프, 그래프 탐색, 구현, 수학, 정수론, 에라토스테네스의 체, 소수 판정

### 제출 일자

2024년 05월 01일 18:58:04

### 문제 설명

<p>Bessie rubbed her eyes again. "The headache's gone. Can you go over that part about number chains again, Farmer John?" </p>

<p>"Sure!" FJ exclaimed. "Let's continue with that sigma function, the one that is the sum of a number's divisors. First, though, let's exclude the number itself from the sum and call our new function bess(), in your honor. Now bess(12) = 1+2+3+4+6 = 16. If we continue and compute bess(16), we find it is 1 + 2 + 4 + 8 = 15. Then bess(15) = 1 + 3 + 5 = 9 and bess(9) = 1 + 3 = 4. Then bess(4) = 1 + 2 = 3 and bess(3) = 1. For better or worse, bess(1) is 0. Not much of a chain, really." </p>

<p>"But look," continued FJ. "We see that bess(6) = 1 + 2 + 3 = 6 and bess(28) = 28. Those form little tiny chains called 'perfect numbers'. Moving to bigger numbers, bess(220) = 284 and -- get this -- bess(284) = 220 -- a chain of length 2! Some chains are even longer." </p>

<p>"It's so late; I'm not sure I can do the math," mooed Bessie. </p>

<p>"No problem," said FJ. "We'll ask the programmers to write a program that accepts a start and end integer (1 <= start <= end <= 1,000,000) and finds all the possible number chains whose starting value is in the interval (start..end). No intermediate value is allowed to exceed 2,000,000, though some might be larger than the 'end' integer. No chain is longer than 50 elements. Print only chains whose smallest element comes first (i.e., no intermediate value is less than the start value of the chain). We must ask them, though, to compute the answers with their program and not just print them. We'll supply test data that is reasonable to finish in 1.0 CPU seconds."</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: start and end</li>
</ul>

### 출력 

 <ul>
	<li>Lines 1..?: Each line contains a space-separated list that represents one chain of numbers calculated using the described bess() function.</li>
</ul>

