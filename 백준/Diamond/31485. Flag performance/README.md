# [Diamond IV] Flag performance - 31485 

[문제 링크](https://acmicpc.net/problem/31485) 

### 성능 요약

메모리: 6772 KB, 시간: 132 ms

### 분류

조합론, 순열 사이클 분할, 다이나믹 프로그래밍, 수학

### 제출 일자

2024년 07월 24일 13:41:41

### 문제 설명

<p>You are in charge of a team of <em>sorted gymnastics</em>. This new discipline involves teams of $N$ members. Each team member dresses with a different colour (a number from $1$ to $N$) and holds a coloured flag. Flags have unique colours, also numbered from $1$ to $N$. A performance consists of exactly $K$ <em>steps</em>. At each step, two members exchange their flags. You are free to choose the initial configuration of the flags. The only constraint is that, at the end of the performance, each participant must hold the flag corresponding to the colour of his outfit.</p>

<p>Being the team captain, you would like the performance to be as unpredictable as possible. You consider $T$ possible initial configurations of flags among the team members, and wonder: in how many ways can the team perform the task for each of these initial configurations?</p>

<p>For each of the given $T$ initial configurations, compute the number of possible ways to do the performance. As the answers may be very large, return them modulo the prime number $1\, 000\, 000\, 007$.</p>

### 입력 

 <p>Each line consists of space-separated integers. The first input line contains the numbers $N$, $K$, and $T$. Then follow $T$ lines. The $k$<sup>th</sup> such line consists of $N$ distinct space-separated integers $c_{k,1}, c_{k,2}, \dots , c_{k,N}$, representing the $k$<sup>th</sup> initial configuration of flags among team members. Here, $c_{k,i}$ is colour number of the flag initially in the hands of the team member whose outfit colour is $i$.</p>

### 출력 

 <p>The output should contain $T$ lines. The $k$<sup>th</sup> such line should consist of a single number: the number of possible sequences of exchanges that start from the $k$<sup>th</sup> configuration and satisfy the constraints listed above, modulo $1\, 000\, 000\, 007$.</p>

