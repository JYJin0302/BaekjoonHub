# [Platinum I] Schools - 11848 

[문제 링크](https://acmicpc.net/problem/11848) 

### 성능 요약

메모리: 23868 KB, 시간: 148 ms

### 분류

자료 구조, 그리디, 우선순위 큐, 정렬

### 제출 일자

2023년 02월 24일 16:17:18

### 문제 설명

<p>Recently Akim of some state decided to open exactly M music and S sports schools to support education in the state. There are N different cities in the state. For each of the cities both the number of students ready to study in music school and the number of students ready to study in sports school is known. Being a big fan of efficiency, Akim doesn't want to open more than one school in any city (it's possible that he won't open any school in some cities).</p>

<p>You, as Akim's consultant, are given a task of developing a plan that would maximize the number of students that would study in the newly opened schools in the state.</p>

### 입력 

 <p>First line of input contains three integer numbers: N (1 ≤ N ≤ 300000), M, S (0 ≤ min(M, S), M + S ≤ N) - the number of cities in the state, the number of music and sports schools that Akim wishes to open respectively.</p>

<p>Each of the following N lines contains two integer numbers: A<sub>i</sub> (1 ≤ A<sub>i</sub> ≤ 10<sup>5</sup>) and B<sub>i</sub> (1 ≤ B<sub>i</sub> ≤ 10<sup>5</sup>) - the number of students in the i-th city that wish to study in music and sports school respectively.</p>

### 출력 

 <p>Output one integer number - the number of students that will study in the newly opened schools in an optimal plan.</p>

