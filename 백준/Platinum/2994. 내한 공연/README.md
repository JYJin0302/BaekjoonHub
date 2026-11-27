# [Platinum V] 내한 공연 - 2994 

[문제 링크](https://acmicpc.net/problem/2994) 

### 성능 요약

메모리: 4468 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍, 배낭 문제, 역추적

### 제출 일자

2021년 06월 11일 22:41:52

### 문제 설명

<p>"The Drinking Musicians", a widely known and popular folk group, are coming to your town. The musicians are known not only by their playing skills, but also their rough character. They never arrive on time, don't know which town they're in, and frequently have trouble finding the stage. </p>

<p>Additionally, during the concert, each of the musicians at one point takes a break. If three or more of them are on a break at the same time, they start stirring trouble in town and the rest of the group start panicking and playing the wrong chords. </p>

<p>The concert will be T minutes long, during which each of the N members will take a break. The length of the break is known for each member. </p>

<p>Help the organizer of the concert by writing a program that determines how to schedule the breaks of the member so that, at any given moment, at most two are absent from the stage. All breaks must be entirely during the concert. </p>

### 입력 

 <p>The first line of input contains the integers T and N (1 ≤ T ≤ 5000, 1 ≤ N ≤ 500), the length of the concert in minutes and the number of musicians in the group. </p>

<p>The next line contains N integers separated by single spaces, the length of the break in minutes for each member. </p>

<p>Note: The input data will be such that a solution, although not necessarily unique, will always exist. </p>

### 출력 

 <p>For each musician output one integer, the number of minutes the musician will spend on stage before going on the break. </p>

<p>Output the musicians in the same order they were given in the input. </p>

