# [Platinum IV] 이진수 XOR - 2196 

[문제 링크](https://acmicpc.net/problem/2196) 

### 성능 요약

메모리: 2552 KB, 시간: 8 ms

### 분류

너비 우선 탐색, 비트마스킹, 비트필드를 이용한 DP, 다이나믹 프로그래밍, 그래프, 그래프 탐색

### 제출 일자

2023년 01월 05일 16:07:39

### 문제 설명

<p>FJ no longer uses the barbaric custom of branding to mark the cows that he owns. Instead, he creates a binary code of B (1 <= B <= 16) bits for each cow and embosses it onto a metal strip that is fastened to each cow's ear.</p>

<p>The cows have taken in a stray and wish to create an ID strip for it. Unknown to FJ, they have created a machine that can make a new ID strip by combining two existing ID strips using the XOR operation (ID strips are not consumed by this machine, and the same ID strip can be used for both inputs).</p>

<p>The cows wish to create a specific ID strip for the stray or at least get as close to a desired ID as possible -- with the smallest possible number of bits differing between the goal ID strip and the best possible new ID strip.</p>

<p>Given a set of E (1 <= E <= 100) existing ID strips, the goal ID strip, and a large number of blank ID strips to hold intermediate results, calculate the closest possible ID strip that can be created from the existing ID strips.</p>

<p>If more than one ID is closest, choose the one that can be created in the fewest steps. If there is still a tie, choose the `smallest' ID (i.e., if you sorted all the IDs, the one that is first).<br>
 </p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: B and E.</li>
	<li>Line 2: The goal ID string, represented as a string of B 0's and 1's (with no spaces).</li>
	<li>Lines 3..E+2: Each line contains an existing ID string, represented as a string of B 0's and 1's (with no spaces).<br>
	 </li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the minimum number of steps required to create the best possible ID strip.</li>
	<li>Line 2: A single line with the best possible ID strip that can be created from the E existing ID strips</li>
</ul>

