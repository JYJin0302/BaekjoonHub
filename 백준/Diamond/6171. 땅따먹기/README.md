# [Diamond V] 땅따먹기 - 6171 

[문제 링크](https://acmicpc.net/problem/6171) 

### 성능 요약

메모리: 4472 KB, 시간: 16 ms

### 분류

볼록 껍질을 이용한 최적화, 다이나믹 프로그래밍

### 제출 일자

2024년 07월 17일 17:05:49

### 문제 설명

<p>Farmer John is considering buying more land for the farm and has his eye on N (1 <= N <= 50,000) additional rectangular plots, each with integer dimensions (1 <= width_i <= 1,000,000; 1 <= length_i <= 1,000,000).</p>

<p>If FJ wants to buy a single piece of land, the cost is $1/square unit, but savings are available for large purchases. He can buy any number of plots of land for a price in dollars that is the width of the widest plot times the length of the longest plot. Of course, land plots cannot be rotated, i.e., if Farmer John buys a 3x5 plot and a 5x3 plot in a group, he will pay 5x5=25.</p>

<p>FJ wants to grow his farm as much as possible and desires all the plots of land. Being both clever and frugal, it dawns on him that he can purchase the land in successive groups, cleverly minimizing the total cost by grouping various plots that have advantageous width or length values.</p>

<p>Given the number of plots for sale and the dimensions of each, determine the minimum amount for which Farmer John can purchase all</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N+1: Line i+1 describes plot i with two space-separated integers: width_i and length_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: The minimum amount necessary to buy all the plots.</li>
</ul>

