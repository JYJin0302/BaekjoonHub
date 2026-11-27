# [Diamond II] Gastronomic Event - 25063 

[문제 링크](https://acmicpc.net/problem/25063) 

### 성능 요약

메모리: 71676 KB, 시간: 368 ms

### 분류

비트 집합, 센트로이드, 배낭 문제, 트리

### 제출 일자

2023년 10월 10일 14:21:18

### 문제 설명

<p>SWERC organizers want to hold a gastronomic event.</p>

<p>The location of the event is a building with $n$ rooms connected by $n - 1$ corridors (each corridor connects two rooms) so that it is possible to go from any room to any other room.</p>

<p>In each room you have to set up the tasting of a typical Italian dish. You can choose from $n$ typical Italian dishes rated from $1$ to $n$ depending on how good they are ($n$ is the best possible rating). The $n$ dishes have distinct ratings.</p>

<p>You want to assign the $n$ dishes to the $n$ rooms so that the number of pleasing tours is maximal. A <em>pleasing tour</em> is a nonempty sequence of rooms so that:</p>

<ul>
	<li>Each room in the sequence is connected to the next one in the sequence by a corridor.</li>
	<li>The ratings of the dishes in the rooms (in the order given by the sequence) are increasing.</li>
</ul>

<p>If you assign the $n$ dishes optimally, what is the maximum number of pleasing tours?</p>

### 입력 

 <p>The first line contains an integer $n$ ($2 ≤ n ≤ 1\,000\,000$) — the number of rooms.</p>

<p>The second line contains $n - 1$ integers $p_2$, $p_3$, $\cdots$, $p_n$ ($1 ≤ p_i < i$). Each $p_i$ indicates that there is a corridor between room $i$ and room $p_i$. It is guaranteed that the building has the property that it is possible to go from any room to any other room.</p>

### 출력 

 <p>Print the maximum number of pleasing tours.</p>

