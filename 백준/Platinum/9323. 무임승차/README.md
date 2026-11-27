# [Platinum IV] 무임승차 - 9323 

[문제 링크](https://acmicpc.net/problem/9323) 

### 성능 요약

메모리: 8972 KB, 시간: 128 ms

### 분류

데이크스트라, 다이나믹 프로그래밍, 그래프, 최단 경로

### 제출 일자

2022년 12월 18일 17:04:12

### 문제 설명

<p>Virgil is a loyal employee at a mysterious national security agency. He has a long commute to work by train every day, during which his mind is free to ponder his situation and the facts of life. Always the mathematician, he notices that, although he pays the fares for his journeys without fail, the conductors rarely check his tickets. In fact, through his years of experience he has a pretty good idea of what the chances are of being checked per section between each pair of cities.</p>

<p>Maybe he could just dodge the fares? Of course, if he gets caught in the train without a ticket he has to pay a ﬁne that will be much higher than the cost of a ticket would have been. But still... Perhaps it’s cheaper to not pay for (part of) the journey and pay the ﬁnes if and when he does get caught.</p>

<p>A ticket from city A to city B costs a certain start up cost s, plus a small amount p per kilometer on a shortest route between city A and B (the ticket is only valid on a shortest route). If you get caught without a ticket, you have to pay a ﬁne consisting of a constant y plus the small amount p per kilometer on the section of railway from the last city the train visited to the next city. The regulations dictate that you have to get off at the next stop if you get caught fare dodging, but being an employee of such a mysterious agency, Virgil is a master of disguise: the conductors will never recognise him and he can continue his journey as if he was never busted.</p>

<p>Help Virgil write a computer program that – based on his experience – calculates the route and which tickets to buy so that his expected daily costs are as small as possible.</p>

<p><img alt="" src="" style="height:171px; width:196px"></p>

<p>A visual representation of the third sample. The best route from 1 to 4 is to buy a ticket for section 1 to 2 for a cost of 20 (10 + 1 × 10), then dodge the fares for section 2 to 3 for an expected cost of 22 (0.1 × (100 + 1 × 120)), and ﬁnally buy a ticket for section 3 to 4 for a cost of 20 (10 + 1 × 10). This leads to a total expected cost of 62 (20 + 22 + 20) which is the best possible for this rail network.</p>

### 입력 

 <p>On the ﬁrst line one positive number: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>one line with seven space-separated integers:
	<ul>
		<li>n (2 ≤ n ≤ 200): the number of cities in the rail network;</li>
		<li>m (1 ≤ m ≤ n(n-1) / 2): the number of direct connections in the rail network;</li>
		<li>start (1 ≤ start ≤ n): the index of the city that Virgil lives in;</li>
		<li>end (1 ≤ end ≤ n, start ≠ end): the index of the city that Virgil works at;</li>
		<li>s (1 ≤ s ≤ 1 000): the start up cost of a ticket;</li>
		<li>p (1 ≤ p ≤ 1 000): the cost per kilometer of a ticket or ﬁne;</li>
		<li>y (s < y ≤ 1 000): the constant part of a ﬁne.</li>
	</ul>
	</li>
	<li>m lines with four space-separated integers, describing the bidirectional sections between cities, with on line i:
	<ul>
		<li>a<sub>i</sub> (1 ≤ a<sub>i</sub> ≤ n): the index of one city on the end of section i;</li>
		<li>b<sub>i</sub> (a<sub>i</sub> < b<sub>i</sub> ≤ n): the index of the other city of section i;</li>
		<li>c<sub>i</sub> (0 ≤ c<sub>i</sub> ≤ 100): the probability that a conductor will check your ticket on section i, expressed as a percentage;</li>
		<li>d<sub>i</sub> (1 ≤ d<sub>i</sub> ≤ 1 000): the distance traveled along section i between city a<sub>i</sub> and b<sub>i</sub> in kilometers;</li>
	</ul>
	</li>
</ul>

<p>For any two pairs (a<sub>i</sub>, b<sub>i</sub>) and (a<sub>j</sub>, b<sub>j</sub>) with i ≠ j, we have that (a<sub>i</sub>, b<sub>i</sub>) ≠ (a<sub>j</sub>, b<sub>j</sub>).</p>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>the lowest possible expected costs for a single trip between city start and end, rounded to exactly two decimals.</li>
</ul>

<p>The test cases are such that an absolute error of at most 10<sup>-6</sup> in the ﬁnal answer does not inﬂuence the result of the rounding.</p>

