# [Platinum IV] 장난감 탱크 - 3043 

[문제 링크](https://acmicpc.net/problem/3043) 

### 성능 요약

메모리: 2932 KB, 시간: 4 ms

### 분류

그리디, 정렬

### 제출 일자

2024년 10월 08일 15:18:17

### 문제 설명

<p>Mirko found a collection of N toy tanks dating back to the Second World War on his grandfather's attic. He promptly called his friend Slavko to play with him. They made a battlefield – a wooden board consisting of squares in N rows and N columns. </p>

<p>Each tank can be moved to one of the four neighbouring squares in a single move. A tank can shoot at any square in the same row and column. The tank is said to be guarding the row and column it is in. </p>

<p>Additionally, no two tanks can be in the same square at any time. </p>

<p>After many hours of play and two previous attempts, Mirko's mom yelled at them to come down for lunch again, and they decided to rearrange the tanks so that each tank guards a different row and column (meaning also that each row and column contains only one tank). </p>

<p>However, they want to do this using the minimum number of moves. </p>

<p>Write a program that finds the minimum number of moves required to rearrange the tanks so that each row and each column contains a single tank, and one such shortest sequence of moves. </p>

### 입력 

 <p>The first line of input contains the integer N (5 ≤ N ≤ 500). </p>

<p>Each of the following N lines contains two integers R and C (1 ≤ R, S ≤ N), the row and column of a single tank at the moment of mom's call. No two tanks are on the same square. </p>

<p>Rows and columns are marked 1 through N, top-down and left-to-right. </p>

### 출력 

 <p>Output the minimum number of moves (call this number K) on the first line. </p>

<p>Each of the next K lines should contain the tank being moved and the direction it is moved in, separated by a single space. </p>

<p>Tanks are numbered 1 through N, in the order in which they are given in the input. </p>

<p>The direction can be one of four uppercase letters: 'L' for left, 'R' for right, 'U' for up and 'D' for down. </p>

<p>Note: The sequence need not be unique. </p>

