# [Diamond IV] Suffixes may Contain Prefixes - 21936 

[문제 링크](https://acmicpc.net/problem/21936) 

### 성능 요약

메모리: 17996 KB, 시간: 16 ms

### 분류

다이나믹 프로그래밍, KMP, 문자열

### 제출 일자

2025년 11월 01일 14:54:43

### 문제 설명

<p>You are playing a game on character strings. At the start of a game, a string of lowercase letters, called the <em>target string</em>, is given. Each of the players submits one string of lowercase letters, called a <em>bullet string</em>, of the specified length. The winner is the one whose bullet string marks the highest score.</p>

<p>The score of a bullet string is the sum of the points of all of its suffixes. When the bullet string is “b<sub>1</sub>b<sub>2</sub>...b<sub>n</sub>”, the point of its suffix s<sub>k</sub> starting with the k-th character (1 ≤ k ≤ n), “b<sub>k</sub>b<sub>k+1</sub>...b<sub>n</sub>”, is the length of its longest common prefix with the target string. That is, with the target string “t<sub>1</sub>t<sub>2</sub>...t<sub>m</sub>”, the point of s<sub>k</sub> is p when t<sub>j</sub> = b<sub>k+j−1</sub> for 1 ≤ j ≤ p and either p = m, k + p − 1 = n, or t<sub>p+1</sub> ≠ b<sub>k+p</sub> holds.</p>

<p>You have to win the game today by any means, as Alyssa promises to have a date with the winner! The game is starting soon. Write a program in a hurry that finds the highest achievable score for the given target string and the bullet length.</p>

### 입력 

 <p>The input consists of a single test case with two lines. The first line contains the non-empty target string of at most 2000 lowercase letters. The second line contains the length of the bullet string, a positive integer not exceeding 2000.</p>

### 출력 

 <p>Output the highest achievable score for the given target string and the given bullet length.</p>

