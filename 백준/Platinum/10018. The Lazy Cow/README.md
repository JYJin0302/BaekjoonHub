# [Platinum II] The Lazy Cow - 10018 

[문제 링크](https://acmicpc.net/problem/10018) 

### 성능 요약

메모리: 14760 KB, 시간: 236 ms

### 분류

자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리, 스위핑

### 제출 일자

2023년 06월 28일 20:19:34

### 문제 설명

<p>It's a hot summer day, and Bessie the cow is feeling quite lazy.  She wants to locate herself at a position in her field so that she can reach as much delicious grass as possible within only a short distance.</p><p>There are N patches of grass (1 <= N <= 100,000) in Bessie's field. The ith such patch contains g_i units of grass (1 <= g_i <= 10,000) and is located at a distinct point (x_i, y_i) in the field (0 <= x_i, y_i <= 1,000,000).  Bessie would like to choose a point in the field as her initial location (possibly the same point as a patch of grass, and possibly even a point with non-integer coordinates) so that a maximum amount of grass is within a distance of K steps from this location (1 <= K <= 2,000,000).</p><p>When Bessie takes a step, she moves 1 unit north, south, east, or west of her current position.  For example, to move from (0,0) to (3,2), this requires 5 total steps.  Bessie does not need to take integer-sized steps -- for example, 1 total step could be divided up as half a unit north and half a unit east.</p><p>Please help Bessie determine the maximum amount of grass she can reach, if she chooses the best possible initial location.</p>

### 입력 

 <ul><li>Line 1: The integers N and K.</li><li>Lines 2..1+N: Line i+1 describes the ith patch of grass using 3 integers: g_i, x_i, y_i.</li></ul>

### 출력 

 <ul><li>Line 1: The maximum amount of grass Bessie can reach within K steps, if she locates herself at the best possible initial position.</li></ul>

