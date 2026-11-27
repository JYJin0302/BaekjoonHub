# [Platinum IV] Judicious Watching - 33036 

[문제 링크](https://acmicpc.net/problem/33036) 

### 성능 요약

메모리: 15032 KB, 시간: 196 ms

### 분류

그리디, 누적 합

### 제출 일자

2025년 01월 09일 18:53:24

### 문제 설명

<p>Jill loves having good grades in university, so she never misses deadlines for her homework assignments. But even more, she loves watching the series and discussing it with her best friend Johnny. And unfortunately, today she needs to choose between these two activities!</p>

<p>Jill needs to complete $n$ homework tasks. The $i$-th task would require $a_i$ minutes to complete and needs to be submitted to the teacher at most $d_i$ minutes from now. Also, there are $m$ new episodes of the series that Johnny and Jill want to discuss. The $j$-th episode lasts $l_j$ minutes. Jill can complete tasks in any order, but she needs to watch the episodes in the order they come. Neither completing a homework task nor watching an episode can be interrupted after starting. </p>

<p>Johnny and Jill need to agree on a time $t_k$ when they would have a call to discuss the series. They are not sure yet which time to choose. For each possible time, compute the maximum number of episodes Jill could watch before that time while still being able to complete all $n$ homework tasks in time.</p>

<p>Note that for the purpose of this problem we assume that discussing the series with Johnny at time $t_k$ does not consume significant time from Jill and <strong>can happen even if she is in the middle of completing any of her homework tasks</strong>.</p>

### 입력 

 <p>There are several test cases in the input. The input begins with the number of test cases $T$ ($1 \le T \le 1\,000$). </p>

<p>Each test case starts with a line with three integers $n$ ($1 \le n \le 200\,000$) --- the number of homework tasks, $m$ ($1 \le m \le 200\,000$) --- the number of episodes, and $q$ ($1 \le q \le 200\,000$) --- the number of possible times for the call with Jill.</p>

<p>The second line contains $n$ integers $a_i$ ($1 \le a_i \le 10^9$) --- the number of minutes it takes to complete the task. The next line contains $n$ integers $d_i$ ($1 \le d_i \le 10^{15}$) --- the deadline before which this task must be completed. The next line contains $m$ integers $l_j$ ($1 \le l_j \le 10^9$) --- the length of episodes in the order they need to be watched. The next line contains $q$ integers $t_k$ ($1 \le t_k \le 10^{15}$) --- the possible times of call with Jill. </p>

<p>It is possible to complete all tasks within their respective deadlines.</p>

<p>The sum of each of $n$, $m$, $q$ over all test cases in input doesn't exceed $200\,000$.</p>

### 출력 

 <p>For each test case output a single line with $q$ integers --- for each possible time $t_k$ the maximum number of episodes Jill can watch.</p>

