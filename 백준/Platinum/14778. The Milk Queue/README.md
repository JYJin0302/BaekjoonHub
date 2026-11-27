# [Platinum II] The Milk Queue - 14778 

[문제 링크](https://acmicpc.net/problem/14778) 

### 성능 요약

메모리: 2268 KB, 시간: 4 ms

### 분류

그리디, 정렬

### 제출 일자

2024년 05월 03일 13:52:26

### 문제 설명

<p>Every morning, Farmer John's N (1 <= N <= 25,000) cows all line up for milking. In an effort to streamline the milking process, FJ has designed a two-stage milking process where the line of cows progresses through two barns in sequence, with milking taking part sequentially in both barns. Farmer John milks cows one by one as they go through the first barn, and his trusty sidekick Farmer Rob milks the cows (in the same order) as they are released from the first barn and enter the second barn.</p>

<p>Unfortunately, Farmer John's insistence that the cows walk through both barns according to a single ordering leads to some inefficiencies. For example, if Farmer John takes too long to milk a particular cow, Farmer Rob might end up sitting idle with nothing to do for some time. On the other hand, if Farmer John works too fast then we might end up with a long queue of cows waiting to enter the second barn.</p>

<p>Please help Farmer John decide on the best possible ordering of cows to use for the milking, so that the last cow finishes milking as early as possible. For each cow i we know the time A(i) required for milking in the first barn and the time B(i) required for milking in the second barn. Both A(i) and B(i) are in the range 1...20,000.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer, N.</li>
	<li>Lines 2..1+N: Line i+1 contains two space-separated integers A(i) and B(i) for cow i.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: The minimum possible time it takes to milk all the cows, if we order them optimally.</li>
</ul>

