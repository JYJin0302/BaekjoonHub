# [Diamond III] 생산성 향상 - 11667 

[문제 링크](https://acmicpc.net/problem/11667) 

### 성능 요약

메모리: 2188 KB, 시간: 8 ms

### 분류

다이나믹 프로그래밍, 정렬

### 제출 일자

2023년 10월 31일 11:29:12

### 문제 설명

<p>ACME Inc. is reorganizing their factory, in order to maximize their productivity of useless trinkets. The new factory design consists of p independent and identical production lines. Each production line can be assigned some number of workers.</p>

<p>The actual work is of course all done by machines, so the production rate of a production line is independent of the actual number of workers assigned to it. However, the workers work in shifts, and due to local safety regulations, a production line can only be active while all of its workers are present (any worker who arrives before the last person to arrive, or leaves after the first person leaves, will be spending the inactive time having a coffee break). In other words, the productivity of a production line equals the length of the timespan during which all of the workers assigned to this production line are present. Crucially, the productivity of each line must be positive (i.e., the last worker to arrive for a line must arrive strictly before the first worker for that line leaves), since otherwise the workers feel that their jobs are meaningless.</p>

<p>Unfortunately, due to some pesky labor laws, ACME are not allowed to fire any of their workers, which means that each of their n workers must be assigned to some production line, even though this may actually decrease the overall productivity of the factory.</p>

<p>All these rules and regulations are making a headache for ACME management. Can you help them figure out the maximum possible total productivity (sum of productivities of the p production lines) of their new factory?</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line containing two integers n and p (1 ≤ p ≤ n ≤ 200), the number of employees and the number of production lines;</li>
	<li>n lines each containing two integers a and b (0 ≤ a < b ≤ 100 000), representing a worker that arrives at time a and leaves at time b.</li>
</ul>

<p>You may assume that there exists at least one valid assignment of workers to production lines.</p>

### 출력 

 <p>Output the maximum productivity level possible for the factory.</p>

