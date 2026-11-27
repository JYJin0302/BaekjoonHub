# [Platinum V] 드래곤 죽이기 - 10605 

[문제 링크](https://acmicpc.net/problem/10605) 

### 성능 요약

메모리: 2372 KB, 시간: 16 ms

### 분류

자료 구조, 분리 집합, 그래프, 그래프 탐색, 그리디, 정렬

### 제출 일자

2020년 10월 18일 15:43:18

### 문제 설명

<p>There are N cities and M roads in Dragons Country. Cities are numbered 1 through N, and each road connects exactly two cities. There are totally K dragons D1, D2, . . . , DK in these N cities. Dragon Di lives in city Ci and has initially Si heads. It grows Ni new heads every minute while alive! A dragon is alive if it has positive number of heads. </p>

<p>We want to hire a number of warriors to kill all dragons. We specify the initial city of each warrior. Then on each minute, each warrior can either go through a road from his current city to an adjacent city, or select an alive dragon in his current city and cut off one of its heads. We can specify the strategy of each warrior on each minute, and after they are done, any alive dragon Di will grow its Ni new heads.</p>

<p>We want to find the minimum number of warriors with which all dragons can be killed in a finite amount of time.</p>

### 입력 

 <p>There are multiple test cases in the input. For each test case, the first line contains three space-separated integers N, M and K (1 ⩽ N ⩽ 300, 0 ⩽ M ⩽ N(N − 1)/2, and 1 ⩽ K ⩽ 1000). Each of the next M lines contains two integers a and b (1 ⩽ a ≠ b ⩽ N) indicating a road between cities a and b. The i-th line of the next K lines describes dragon Di with three space-separated integers Ci, Si and Ni (1 ⩽ Ci ⩽ N, 1 ⩽ Si ⩽ 10<sup>5</sup>, 0 ⩽ Ni ⩽ 10<sup>5</sup>). The input terminates with a line containing 0 0 0 which should not be processed.</p>

### 출력 

 <p>For each test case, output a line containing the minimum number of warriors who can eventually kill all dragons.</p>

