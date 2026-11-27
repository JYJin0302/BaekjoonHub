# [Diamond V] Eradication Sort - 32564 

[문제 링크](https://acmicpc.net/problem/32564) 

### 성능 요약

메모리: 23108 KB, 시간: 52 ms

### 분류

볼록 껍질을 이용한 최적화, 다이나믹 프로그래밍, 자료 구조, 키네틱 세그먼트 트리, 리 차오 트리, 세그먼트 트리

### 제출 일자

2026년 02월 26일 12:55:24

### 문제 설명

<p>The members of the No-Weather-too-Extreme Recreational Climbing society completed their first successful summit seven years ago to this day!</p>

<p>At the time, we took a picture of all the members standing together in one row. However, the photograph looks messy, as the climbers were not standing in order of height, and we have no way to reorder them.</p>

<p>We will need to cut some of the climbers out of the picture.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 768px; height: 271px;"></p>

<p style="text-align: center;">Figure E.1: This picture of 7 (formerly 11) climbers was edited to solve Sample Input 3.</p>

<p>An optimal solution minimises the size and number of visible gaps in the photo. We define the <em>cost</em> as the sum of the squares of the lengths of gaps left in the edited photo. For example, if two individual climbers are removed from the photo and one pair of adjacent climbers are removed, the total <em>cost</em> is $1^2 + 1^2 + 2^2 = 6$.</p>

<p>Find the minimum possible cost you can reach by removing climbers.</p>

### 입력 

 <ul>
	<li>The number of people in the photo $n$ ($1 \le n \le 10^6$).</li>
	<li>$n$ integers representing the heights of people in the photo, $h_1 \ldots h_n$ ($0 \le h \le 10^6$).</li>
</ul>

### 출력 

 <p>Output the minimum <em>cost</em> achieved by removing climbers from the photo, such that the remaining climbers in the photo make a <strong>non-decreasing</strong> sequence.</p>

