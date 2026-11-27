# [Gold II] 문자열 생성 2 - 6143 

[문제 링크](https://acmicpc.net/problem/6143) 

### 성능 요약

메모리: 2172 KB, 시간: 136 ms

### 분류

그리디, 문자열

### 제출 일자

2024년 06월 21일 15:36:18

### 문제 설명

<p>FJ is about to take his N (1 <= N <= 30,000) cows to the annual "Farmer of the Year" competition. In this contest every farmer arranges his cows in a line and herds them past the judges.</p>

<p>The contest organizers adopted a new registration scheme this year: simply register the initial letter of every cow in the order they will appear (e.g., If FJ takes Bessie, Sylvia, and Dora in that order, he just registers BSD). After the registration phase ends, every group is judged in increasing lexicographic order (i.e., alphabetical order) according to the string of the initials of the cows' names.</p>

<p>FJ is very busy this year and has to hurry back to his farm, so he wants to be judged as early as possible. He decides to rearrange his cows, who have already lined up, before registering them.</p>

<p>FJ marks a location for a new line of the competing cows. He then proceeds to marshal the cows from the old line to the new one by repeatedly sending either the first or last cow in the (remainder of the) original line to the end of the new line. When he's finished, FJ takes his cows for registration in this new order.</p>

<p>Given the initial order of his cows, determine the least lexicographic string of initials he can make this way.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N+1: Line i+1 contains a single initial ('A'..'Z') of the cow in the ith position in the original line</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>The least lexicographic string he can make. Every line (except perhaps the last one) contains the initials of 80 cows ('A'..'Z') in the new line.</li>
</ul>

<p> </p>

