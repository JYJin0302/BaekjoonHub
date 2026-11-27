# [Gold II] Lottery Fun Time - 24958 

[문제 링크](https://acmicpc.net/problem/24958) 

### 성능 요약

메모리: 2496 KB, 시간: 8 ms

### 분류

그리디, 구현

### 제출 일자

2025년 09월 16일 17:02:12

### 문제 설명

<p><img alt="" src="" style="width: 227px; height: 119px; float: right;">The biggest fun of lottery is not in receiving the (usually a tiny amount of) prize money, but in dreaming of the big fortune you may possibly (that is, virtually never) receive.</p>

<p>You have a number of lottery tickets at hand, each with a six-digit number. All the numbers are different, of course. Tomorrow is the drawing day and the prizes are the following.</p>

<ul>
	<li>The first prize of 300,000 yen is won by the ticket with exact match of all the six digits with the six-digit first prize winning number.</li>
	<li>The second prizes of 4,000 yen are won by all of the tickets with their last four digits matching the four-digit second prize winning number.</li>
	<li>The third prizes of 500 yen are won by all of the tickets with their last two digits matching any of the three two-digit third prize winning numbers.</li>
</ul>

<p>The six digits on the lottery tickets and all of the winning numbers may start with zeros.</p>

<p>The last two digits of all the prize winning numbers are made different so that tickets winning the third prize cannot also win the first nor the second prizes. Note that this rule also made the last two digits of the first and the second prize winning numbers different.</p>

<p>To enjoy the climax of the lottery fun time, you decided to calculate the possible maximum amount you may win with your tickets. You have too many tickets to hand-calculate it, but it should also be your joy to write a program for making the calculation.</p>

### 입력 

 <p>The first line of the input has a positive integer $n$ ($n ≤ 10^5$), which is the number of tickets you have at hand. Each of the following $n$ lines has the six-digit number on one of your tickets. All the $n$ numbers are different from one another.</p>

### 출력 

 <p>Output in a line a single integer, which is the maximum possible total of winning prizes with the tickets you have.</p>

