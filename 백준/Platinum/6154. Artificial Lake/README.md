# [Platinum I] Artificial Lake - 6154 

[문제 링크](https://acmicpc.net/problem/6154) 

### 성능 요약

메모리: 5160 KB, 시간: 28 ms

### 분류

애드 혹, 자료 구조, 그리디, 구현, 연결 리스트, 시뮬레이션, 정렬, 스택

### 제출 일자

2024년 07월 12일 18:20:17

### 문제 설명

<p>The oppressively hot summer days have raised the cows' clamoring to its highest level. Farmer John has finally decided to build an artificial lake. For his engineering studies, he is modeling the lake as a two-dimensional landscape consisting of a contiguous sequence of N soon-to-be-submerged levels (1 <= N <= 100,000) conveniently numbered 1..N from left to right.</p>

<p>Each level i is described by two integers, its width W_i (1 <= W_i <= 1,000) and height (like a relative elevation) H_i (1 <= H_i <= 1,000,000). The heights of FJ's levels are unique. An infinitely tall barrier encloses the lake's model on the left and right. One example lake profile is shown below.</p>

<pre>         *            *  :
         *             *  :
         *             *  8
         *    ***      *  7
         *    ***      *  6
         *    ***      *  5
         *    **********  4 <- height
         *    **********  3
         ***************  2
         ***************  1
Level    |  1 |2|  3   |</pre>

<p>In FJ's model, he starts filling his lake at sunrise by flowing water into the bottom of the lowest elevation at a rate of 1 square unit of water per minute. The water falls directly downward until it hits something, and then it flows and spreads as room-temperature water always does.  As in all good models, assume that falling and flowing happen instantly. Determine the time at which each elevation's becomes submerged by a single unit of water.</p>

<pre>     WATER              WATER OVERFLOWS                     
       |                       |                           
     * |          *      *     |      *      *            *
     * V          *      *     V      *      *            *
     *            *      *    ....    *      *~~~~~~~~~~~~*
     *    **      *      *~~~~** :    *      *~~~~**~~~~~~*
     *    **      *      *~~~~** :    *      *~~~~**~~~~~~*
     *    **      *      *~~~~**~~~~~~*      *~~~~**~~~~~~*
     *    *********      *~~~~*********      *~~~~*********
     *~~~~*********      *~~~~*********      *~~~~*********
     **************      **************      **************
     **************      **************      **************

     After 4 mins        After 26 mins       After 50 mins
     Lvl 1 submerged     Lvl 3 submerged     Lvl 2 submerged</pre>

<p>Warning: The answer will not always fit in 32 bits.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N+1: Line i+1 describes level i with two space-separated integers: W_i and H_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Lines 1..N: Line i contains a single integer that is the number of minutes that since sunrise when level #i is covered by water of height 1.</li>
</ul>

<p> </p>

