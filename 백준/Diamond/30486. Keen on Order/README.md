# [Diamond V] Keen on Order - 30486 

[문제 링크](https://acmicpc.net/problem/30486) 

### 성능 요약

메모리: 68056 KB, 시간: 20 ms

### 분류

비트마스킹, 비트필드를 이용한 DP, 다이나믹 프로그래밍

### 제출 일자

2023년 11월 13일 17:05:14

### 문제 설명

<p>Nloglonia is hosting a movie festival that spans N days. There are K distinct movies, and on each of the N days, one of them will be displayed. Each of the available movies might be displayed on multiple days or not displayed at all during the festival.</p>

<p>The festival schedule is given as an integer array V of size N, with 1 ≤ V<sub>i</sub> ≤ K, indicating which movie will be shown on each day. Bob wants to watch all K movies, and he firmly believes that the order in which he watches them will significantly affect his experience. So now he wonders: is it true that for every order of the movies, he would be able to pick K days to visit the festival and watch those movies in that given order? More formally, is it true that every permutation of 1, 2, . . . , K is a subsequence of V ? If this is not the case, Bob also wants you to find some permutation (any one) that is not.</p>

### 입력 

 <p>The first line contains two integers N and K (1 ≤ N, K ≤ 300), indicating respectively the number of days the movie festival lasts and the number of movies available for display.</p>

<p>The second line contains N integers V<sub>1</sub>, V<sub>2</sub>, . . . , V<sub>N</sub> (1 ≤ V<sub>i</sub> ≤ K for i = 1, 2, . . . , N), indicating that the movie Vi will be displayed on day i.</p>

### 출력 

 <p>Output a single line with K integers showing a permutation of 1, 2, . . . , K which is not a subsequence of V . If every permutation is a subsequence of V , output the character “*” (asterisk) instead.</p>

