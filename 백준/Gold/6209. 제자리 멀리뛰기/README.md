# [Gold II] 제자리 멀리뛰기 - 6209 

[문제 링크](https://acmicpc.net/problem/6209) 

### 성능 요약

메모리: 2216 KB, 시간: 12 ms

### 분류

이분 탐색, 그리디, 매개 변수 탐색

### 제출 일자

2024년 07월 18일 19:44:30

### 문제 설명

<p>Every year the cows hold an event featuring a peculiar version of hopscotch that involves carefully jumping from rock to rock in a river. The excitement takes place on a long, straight river with a rock at the start and another rock at the end, L units away from the start (1 <= L <= 1,000,000,000). Along the river between the starting and ending rocks, N (0 <= N <= 50,000) more rocks appear, each at an integral distance Di from the start (0 < Di < L).</p>

<p>To play the game, each cow in turn starts at the starting rock and tries to reach the finish at the ending rock, jumping only from rock to rock. Of course, less agile cows never make it to the final rock, ending up instead in the river.</p>

<p>Farmer John is proud of his cows and watches this event each year. But as time goes by, he tires of watching the timid cows of the other farmers limp across the short distances between rocks placed too closely together. He plans to remove several rocks in order to increase the shortest distance a cow will have to jump to reach the end. He knows he cannot remove the starting and ending rocks, but he calculates that he has enough resources to remove up to M rocks (0 <= M <= N).</p>

<p>FJ wants to know exactly how much he can increase the shortest distance *before* he starts removing the rocks. Help Farmer John determine the greatest possible shortest distance a cow has to jump after removing the optimal set of M rocks.</p>

### 입력 

 <ul>
	<li>Line 1: Three space-separated integers: L, N, and M</li>
	<li>Lines 2..N+1: Each line contains a single integer indicating how far some rock is away from the starting rock. No two rocks share the same position.</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the maximum of the shortest distance a cow has to jump after removing M rocks</li>
</ul>

