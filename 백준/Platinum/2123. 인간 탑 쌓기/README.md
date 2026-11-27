# [Platinum V] 인간 탑 쌓기 - 2123 

[문제 링크](https://acmicpc.net/problem/2123) 

### 성능 요약

메모리: 2416 KB, 시간: 16 ms

### 분류

그리디, 정렬

### 제출 일자

2022년 01월 16일 22:55:00

### 문제 설명

<p>Farmer John's N (1 <= N <= 50,000) cows (numbered 1..N) are planning to run away and join the circus. Their hoofed feet prevent them from tightrope walking and swinging from the trapeze (and their last attempt at firing a cow out of a cannon met with a dismal failure). Thus, they have decided to practice performing acrobatic stunts.</p>

<p>The cows aren't terribly creative and have only come up with one acrobatic stunt: standing on top of each other to form a vertical stack of some height. The cows are trying to figure out the order in which they should arrange themselves ithin this stack.</p>

<p>Each of the N cows has an associated weight (1 <= W_i <= 10,000) and strength (1 <= S_i <= 1,000,000,000). The risk of a cow collapsing is equal to the combined weight of all cows on top of her (not including her own weight, of course) minus her strength (so that a stronger cow has a lower risk). Your task is to determine an ordering of the cows that minimizes the greatest risk of collapse for any of the cows.</p>

### 입력 

 <ul>
	<li>Line 1: A single line with the integer N.</li>
	<li>Lines 2..N+1: Line i+1 describes cow i with two space-separated integers, W_i and S_i.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer, giving the largest risk of all the cows in any optimal ordering that minimizes the risk.</li>
</ul>

