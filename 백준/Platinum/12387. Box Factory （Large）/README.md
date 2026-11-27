# [Platinum II] Box Factory (Large) - 12387 

[문제 링크](https://acmicpc.net/problem/12387) 

### 성능 요약

메모리: 2240 KB, 시간: 68 ms

### 분류

다이나믹 프로그래밍, 누적 합

### 제출 일자

2025년 03월 09일 12:13:29

### 문제 설명

<p>You own a factory with two assembly lines. The first assembly line makes boxes, and the second assembly line makes toys to put in those boxes. Each type of box goes with one type of toy and vice-versa.</p>

<p>At the beginning, you pick up a box from the first assembly line and a toy from the second assembly line. You then have a few options.</p>

<ul>
	<li>You can always throw out the box and pick up the next one.</li>
	<li>You can always throw out the toy and pick up the next one.</li>
	<li>If the box and toy are the same type, you can put the toy in the box, and send it out to customers.</li>
</ul>

<p>You always pick boxes up in the order in which they are made, and similarly for toys. You know the order in which boxes and toys are made, and you want to plan out a strategy that will allow you to send as many boxed toys as possible to customers.</p>

<p> </p>

<p>Warning: The two assembly lines make a <em>lot</em> of boxes and toys. However, they tend to make one kind of thing for a long period of time before switching.</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <strong>T</strong>.  <strong>T</strong> test cases follow.</p>

<p>Each test case begins with a line contains two integers <strong>N</strong> and <strong>M</strong>. It is followed by a line containing 2 * <strong>N</strong> integers <strong>a<sub>1</sub></strong>, <strong>A<sub>1</sub></strong>, <strong>a<sub>2</sub></strong>, <strong>A<sub>2</sub></strong>, ..., <strong>a<sub>N</sub></strong>, <strong>A<sub>N</sub></strong>, and another line containing 2 * <strong>M</strong>integers <strong>b<sub>1</sub></strong>, <strong>B<sub>1</sub></strong>, <strong>b<sub>2</sub></strong>, <strong>B<sub>2</sub></strong>, ..., <strong>b<sub>M</sub></strong>, <strong>B<sub>M</sub></strong>.</p>

<p>This means that the first assembly line will make <strong>a<sub>1</sub></strong> boxes of type <strong>A<sub>1</sub></strong>, then <strong>a<sub>2</sub></strong> boxes of type <strong>A<sub>2</sub></strong>, etc., until it finishes with <strong>a<sub>N</sub></strong> boxes of type <strong>A<sub>N</sub></strong>. Similarly, the second assembly will make <strong>b<sub>1</sub></strong> toys of type <strong>B<sub>1</sub></strong>, followed by <strong>b<sub>2</sub></strong> toys of type <strong>B<sub>2</sub></strong>, etc., until it finishes with <strong>b<sub>M</sub></strong> toys of type <strong>B<sub>M</sub></strong>.</p>

<p>A toy can be matched with a box if and only if they have the same type number.</p>

<h3>Limits</h3>

<ul>
	<li>1 ≤ <strong>T</strong> ≤ 100.</li>
	<li>1 ≤ <strong>a<sub>i</sub></strong>, <strong>b<sub>i</sub></strong> ≤ 10<sup>16</sup>.</li>
	<li>1 ≤ <strong>A<sub>i</sub></strong>, <strong>B<sub>i</sub></strong> ≤ 100.</li>
	<li>1 ≤ <strong>N, M</strong> ≤ 100.</li>
</ul>

### 출력 

 <p>For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1), and y is the largest number of boxed toys that you can send out to customers.</p>

