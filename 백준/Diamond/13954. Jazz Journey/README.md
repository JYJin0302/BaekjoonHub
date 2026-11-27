# [Diamond V] Jazz Journey - 13954 

[문제 링크](https://acmicpc.net/problem/13954) 

### 성능 요약

메모리: 111048 KB, 시간: 2220 ms

### 분류

그리디

### 제출 일자

2023년 09월 01일 19:22:50

### 문제 설명

<p>Ivan is planning a large European tour with his jazz band. There are a total of n cities in Europe, numbered with integers 1 through n. Ivan is planning d concerts in cities a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>d</sub> in that exact order, never having two consecutive concerts in the same city (a<sub>i</sub> ≠ a<sub>i+1</sub> ), possibly visiting some of the cities many times and, finally, ending the tour in the same city where it begun (a<sub>1</sub> = a<sub>d</sub> ).</p>

<p>Ivan always takes a direct flight between cities a<sub>i</sub> and a<sub>i+1</sub> . However, he is trying to be smart with his ticket purchases in order to save money. As you may know, airlines price tickets based on supply and demand and, for example, it may be possible that one-way tickets are more expensive than round trip tickets between same cities.</p>

<p>Generally, there are two kinds of tickets available for purchase:</p>

<ul>
	<li>One-way ticket from the origin city a to destination city b can be used to fly from a to b once (but not in the opposite direction).</li>
	<li>Round trip ticket from the origin city a to destination city b can be used to fly once from a to b, and once from b to a. The return segment (from b to a) does not need to be used. However, the segments have to be flown in order — it is not allowed for Ivan to use the return segment of a ticket to fly from b to a unless he has used the first segment of that ticket to fly from a to b before.</li>
</ul>

<p>You are given a list of available airfares, find the least amount of money Ivan needs to spend on tickets to be able to complete his journey. Ivan can purchase an arbitrary number of tickets for each airfare. Once again, Ivan needs to take a direct flight from a<sub>i</sub> to a<sub>i+1</sub> for every i = 1, 2, . . . , d − 1. You may assume that is possible to complete the journey using the airfares.</p>

### 입력 

 <p>The first line contains two integers n and d (2 ≤ n, d ≤ 300 000) — the number of cities in Europe and the number of concerts. The following line contains integers a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>d</sub> (1 ≤ a<sub>i</sub> ≤ n, a<sub>i</sub> ≠ a<sub>i+1</sub> , a<sub>1</sub> = a<sub>d</sub> ) — the planned tour schedule.</p>

<p>The following line contains an integer m (3 ≤ m ≤ 300 000) — the number of airfares. The k-th of the following m lines contains four tokens s<sub>k</sub> , d<sub>k</sub> , t<sub>k</sub> , p<sub>k</sub> , describing the k-th airfare as follows:</p>

<ul>
	<li>s<sub>k</sub> and d<sub>k</sub> (1 ≤ s<sub>k</sub> , d<sub>k</sub> ≤ n, s<sub>k</sub> ≠ d<sub>k</sub> ) are the origin and the destination city respectively,</li>
	<li>t<sub>k</sub> is an uppercase letter “O” or “R” denoting a one-way or round trip ticket respectively,</li>
	<li>k (1 ≤ p<sub>k</sub> ≤ 10<sup>9</sup> ) is the ticket price, an integer.</li>
</ul>

### 출력 

 <p>Output the least amount of money necessary to purchase tickets that allow Ivan to complete the planned tour.</p>

