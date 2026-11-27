# [Platinum IV] Exam registration - 24858 

[문제 링크](https://acmicpc.net/problem/24858) 

### 성능 요약

메모리: 33280 KB, 시간: 396 ms

### 분류

이분 탐색, 그리디

### 제출 일자

2026년 01월 15일 17:19:22

### 문제 설명

<p>Usually everyone associates the New Year with a Christmas tree and a festive table, but students associate the New Year with exams session. It was December 31, and second-year students signed up for the exam.</p>

<p>There are $n$ days when they can take the exam. Each student signed up to take the exam on one of these days. So, on the $i$-th day $a_{i}$ students want to take the exam, but the maximum number of students who can take the exam on this day is $b_{i}$.</p>

<p>Teachers need all students to have the opportunity to take the exam, so some students may have to be moved to another day. Teachers can choose any number of students and assign each of them to take the exam on any day.</p>

<p>If a student wanted to take the exam on the $i$-th day, and the teachers eventually moved it to the $j$-th day, then <em>dissatisfaction</em> of this student will be equal to $|i - j|$.</p>

<p>Help the teachers distribute the students so that for all $i$ on the $i$-th day, no more than $b_i$ students took the exam, and the maximum dissatisfaction among the students was minimal.</p>

### 입력 

 <p>The first line of the input contains a single integer $n$ --- the number of days when the students can take the exam ($1 \le n \le 10^{6}$).</p>

<p>The second line of the input contains $n$ integers $a_{i}$ --- the number of students who want to take the exam on the $i$-th day ($1 \le a_i \le 10^{9}$).</p>

<p>The third line of the input contains $n$ integers $b_{i}$ --- the maximum number of students who can take the exam on the $i$-th day ($0 \le b_i \le 10^{9}$).</p>

### 출력 

 <p>Print a single integer --- for which minimum $k$ it is possible make the dissatisfaction of any student not to exceed $k$. If there is no solution, you should print $-1$.</p>

