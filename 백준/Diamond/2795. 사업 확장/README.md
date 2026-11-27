# [Diamond II] 사업 확장 - 2795 

[문제 링크](https://acmicpc.net/problem/2795) 

### 성능 요약

메모리: 20676 KB, 시간: 204 ms

### 분류

데이크스트라, 다이나믹 프로그래밍, 플로이드–워셜, 그래프, 최단 경로

### 제출 일자

2024년 05월 01일 13:03:21

### 문제 설명

<p>The elections are nearing, so President Amabo Kcarab is planning a tour of the States, with speeches in WDC and LA. To provide adequate security, the Secret Service needs to constantly monitor all cities that the President will pass through (including WDC and LA).</p>

<p>Of course, the federal budget needs to be spent responsibly, so the President will not be using AF1, but will be travelling by car. Also, the Secret Service will plan the President's tour from WDC to LA and back to WDC such that the least possible number of cities needs to be monitored.</p>

<p>For this problem, assume that the States consist of N cities, denoted by numbers from 1 to N, and M unidirectional Interstates, with each Interstate linking two different cities. WDC is city number 1, LA number 2.</p>

<p>Write a program to compute the minimum number of cities that need to be monitored such that there exists a path from WDC to LA and back to WDC passing only through monitored cities.</p>

### 입력 

 <p>The first line of input contains the two integers N and M (2 ≤ N ≤ 100, 2 ≤ M ≤ 200), the number of cities and the number of Interstates linking the cities, respectively.</p>

<p>Each of the following M lines contains two different integers A, B (1 ≤ A, B ≤ N), the beginning and ending city served by the given Interstate. No two Interstates link the same two cities in the same direction, but two Interstates can link the same two cities in opposite directions.</p>

### 출력 

 <p>The first and only line of output must contain the minimum number of cities that need to be monitored.</p>

<p>Note: Test data will ensure that a solution will always exist.</p>

