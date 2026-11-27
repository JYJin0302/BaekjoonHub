# [Diamond IV] 상인 - 5466 

[문제 링크](https://acmicpc.net/problem/5466) 

### 성능 요약

메모리: 23340 KB, 시간: 328 ms

### 분류

다이나믹 프로그래밍, 자료 구조, 그리디, 세그먼트 트리

### 제출 일자

2024년 04월 24일 19:42:39

### 문제 설명

<p>The traveling salesman has decided that optimally scheduling his trips on land is an intractable computational problem, so he is moving his business to the linear world of the Danube River. He has a very fast boat that can get him from anywhere to anywhere along the river in no time, but unfortunately the boat has terrible fuel consumption. It costs the salesman U dollars for every meter traveled upstream (towards the source of the river) and D dollars for every meter traveled downstream (away from the source of the river).</p>

<p>There are N trade fairs that the salesman would like to visit along the river. Each trade fair is held for one day only. For each trade fair X, the traveling salesman knows its date TX, measured in the number of days since he purchased his boat. He also knows the fair’s location LX, measured as the distance in meters from the source of the river downstream to the fair, as well as the number of dollars MX that the salesman is going to gain if he attends this trade fair. He has to start and end his journey at his waterfront home on the river, which is at location S, measured also in meters downstream from the source of the river.</p>

<p>Help the traveling salesman choose which trade fairs to attend (if any) and in what order, so that he may maximize his profit at the end of his travels. The traveling salesman’s total profit is defined as the sum of the dollars he gained at the fairs he attended, minus the total sum of dollars he spent traveling up and down the river.</p>

<p>Keep in mind that if trade fair A is held earlier than trade fair B, the salesman can visit them only in this order (i.e., he cannot visit B and then visit A). However, if two fairs are held on the same date, the salesman can visit them both in any order. There is no limit to how many fairs the salesman can visit in a day, but naturally he can't visit the same fair twice and reap the gains twice. He can pass through fairs he has already visited without gaining anything.</p>

<p>Write a program that, given the date, location and profitability of all fairs, as well as the location of the traveling salesman’s home and his costs of traveling, determines the maximum possible profit he can make by the end of his journey. </p>

### 입력 

 <p>Your program must read from standard input the following data:</p>

<ul>
	<li>The first line contains the integers N, U, D and S, in this order, separated by single spaces.</li>
	<li>The next N lines describe the N fairs in no particular order. The kth of these N lines describes the kth fair and contains three integers separated by single spaces: the day of the fair Tk, its location Lk, and its profitability for the salesman Mk.</li>
</ul>

<p>NOTE: All locations given in the input will be different. That is to say, no two fairs will happen at the same location and no fair will happen at the salesman’s home.</p>

<ul>
	<li>1 ≤ N ≤ 500,000 The number of fairs</li>
	<li>1 ≤ D ≤ U ≤ 10 The cost of traveling one meter upstream (U) or downstream (D)</li>
	<li>1 ≤ S ≤ 500,001 The location of the salesman’s home</li>
	<li>1 ≤ Tk ≤ 500,000 The day on which fair k is held</li>
	<li>1 ≤ Lk ≤ 500,001 The location of fair k</li>
	<li>1 ≤ Mk ≤ 4,000 The number of dollars the salesman would earn if he attends fair k </li>
</ul>

### 출력 

 <p>Your program must write to standard output a single line containing a single integer: the maximum profit the salesman can possibly make by the end of his journey. </p>

