# [Silver IV] 반복수열 - 2331 

[문제 링크](https://acmicpc.net/problem/2331) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현, 수학

### 제출 일자

2021년 08월 01일 22:26:22

### 문제 설명

<p>The cows are calculating the "life cycle" for each of their identification tag numbers.</p>

<p>Take any positive integer N (1 <= N <= 9999), say 57, square all the digits and add them up:  5^2 + 7^2 to get 25 + 49 = 74. Now do the same procedure with the result 74 to get the next number in the sequence 65. Continuing to apply this procedure to a sequence of terms eventually repeats one number of the sequence.</p>

<p>When starting with 57, the sequence repeats for the first time with 37, which is the next number in this part of the sequence:</p>

<p>57, 74, 65, 61, </p>

<p>From then on the sequence is trapped in a "life cycle":</p>

<p>37, 58, 89, 145, 42, 20, 4, 16, 37, . . .</p>

<p>If we cube the digits instead of squaring them the sequence has a similar fate. Your job is to write a program that computes how long the sequence lasts until it falls into a life cycle given a starting positive integer and a power P (1 <= P <= 5).</p>

### 입력 

 <p>A single line with two space-separated integers: N and P.</p>

### 출력 

 <p>Length of the sequence until it enters a life cycle, not including the first number in the cycle.</p>

