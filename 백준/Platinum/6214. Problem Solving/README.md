# [Platinum V] Problem Solving - 6214 

[문제 링크](https://acmicpc.net/problem/6214) 

### 성능 요약

메모리: 2380 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 05월 05일 15:55:55

### 문제 설명

<p>In easier times, Farmer John's cows had no problems. These days, though, they have problems, lots of problems; they have P (1 <= P <= 300) problems, to be exact. They have quit providing milk and have taken regular jobs like all other good citizens.  In fact, on a normal month they make M (1 <= M <= 1000) money.</p>

<p>Their problems, however, are so complex they must hire consultants to solve them. Consultants are not free, but they are competent: consultants can solve any problem in a single month. Each consultant demands two payments: one in advance (1 <= payment <= M) to be paid at the start of the month problem-solving is commenced and one more payment at the start of the month after the problem is solved (1 <= payment <= M). Thus, each month the cows can spend the money earned during the previous month to pay for consultants. Cows are spendthrifts: they can never save any money from month-to-month; money not used is wasted on cow candy.</p>

<p>Since the problems to be solved depend on each other, they must be solved mostly in order. For example, problem 3 must be solved before problem 4 or during the same month as problem 4.</p>

<p>Determine the number of months it takes to solve all of the cows' problems and pay for the solutions.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: M and P.</li>
	<li>Lines 2..P+1: Line i+1 describes problem i with two space-separated integers: B_i and A_i. B_i is the payment to the consult BEFORE the problem is solved; A_i is the payment to the consult AFTER the problem is solved.</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: The number of months it takes to solve and pay for all the cows' problems.</li>
</ul>

