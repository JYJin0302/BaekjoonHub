# [Gold IV] 소수 경로 - 1963 

[문제 링크](https://acmicpc.net/problem/1963) 

### 성능 요약

메모리: 2040 KB, 시간: 4 ms

### 분류

너비 우선 탐색, 그래프, 그래프 탐색, 수학, 정수론, 에라토스테네스의 체, 소수 판정

### 제출 일자

2021년 08월 11일 22:40:56

### 문제 설명

<p>The ministers of the cabinet were quite upset by the message from the Chief of Security stating that they would all have to change the four-digit room numbers on their offices.</p>

<p>— It is a matter of security to change such things every now and then, to keep the enemy in the dark.</p>

<p>— But look, I have chosen my number 1033 for good reasons. I am the Prime minister, you know!</p>

<p>— I know, so therefore your new number 8179 is also a prime. You will just have to paste four new digits over the four old ones on your ofﬁce door.</p>

<p>— No, it’s not that simple. Suppose that I change the ﬁrst digit to an 8, then the number will read 8033 which is not a prime!</p>

<p>— I see, being the prime minister you cannot stand having a non-prime number on your door even for a few seconds.</p>

<p>— Correct! So I must invent a scheme for going from 1033 to 8179 by a path of prime numbers where only one digit is changed from one prime to the next prime.</p>

<p>Now, the minister of finance, who had been eavesdropping, intervened.</p>

<p>— No unnecessary expenditure, please! I happen to know that the price of a digit is one pound.</p>

<p>— Hmm, in that case I need a computer program to minimize the cost. You don’t know some very cheap software gurus, do you?</p>

<p>— In fact, I do. You see, there is this programming contest going on...</p>

<p>Help the prime minister to ﬁnd the cheapest prime path between any two given four-digit primes! The first digit must be nonzero, of course. Here is a solution in the case above.</p>

<pre>1033
1733
3733
3739
3779
8779
8179</pre>

<p>The cost of this solution is 6 pounds. Note that the digit 1 which got pasted over in step 2 can not be reused in the last step – a new 1 must be purchased.</p>

### 입력 

 <p>One line with a positive number: the number of test cases (at most 100). Then for each test case, one line with two numbers separated by a blank. Both numbers are four-digit primes (without leading zeros).</p>

### 출력 

 <p>One line for each case, either with a number stating the minimal cost or containing the word Impossible.</p>

