# [Gold IV] 페르마의 크리스마스 정리 - 4913 

[문제 링크](https://acmicpc.net/problem/4913) 

### 성능 요약

메모리: 9832 KB, 시간: 12 ms

### 분류

수학, 정수론, 누적 합, 에라토스테네스의 체, 소수 판정

### 제출 일자

2020년 12월 21일 17:56:24

### 문제 설명

<p>In a letter dated December 25, 1640; the great mathematician Pierre de Fermat wrote to Marin Mersenne that he just proved that an odd prime p is expressible as p = a<sup>2</sup> + b<sup>2</sup> if and only if p is expressible as p = 4c+1. As usual, Fermat didnt include the proof, and as far as we know, never wrote it down. It wasnt until 100 years later that no one other than Euler proved this theorem. To illustrate, each of the following primes can be expressed as the sum of two squares:</p>

<p>5=2<sup>2</sup>+1<sup>1</sup> 13=3<sup>2</sup>+2<sup>2</sup> 17=4<sup>2</sup>+1<sup>2</sup> 41=5<sup>2</sup>+4<sup>2</sup></p>

<p>Whereas the primes 11, 19, 23, and 31 cannot be expressed as a sum of two squares. Write a program to count the number of primes that can be expressed as sum of squares within a given interval.</p>

### 입력 

 <p>Your program will be tested on one or more test cases. Each test case is specified on a separate input line that specifies two integers L, U where -1,000,000 < L ≤ U < 1,000,000</p>

<p>The last line of the input file includes a dummy test case with both L = U = −1.</p>

### 출력 

 <p>For each test case, write the result using the following format:</p>

<pre>L U x y</pre>

<p>where L and U are as specied in the input. x is the total number of primes within the interval [L, U] (inclusive,) and y is the total number of primes (also within [L, U]) that can be expressed as a sum of squares.</p>

