# [Diamond IV] Ascending Photo - 15599 

[문제 링크](https://acmicpc.net/problem/15599) 

### 성능 요약

메모리: 22644 KB, 시간: 148 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2023년 11월 20일 23:01:58

### 문제 설명

<p>The members of the No-Weather-too-Extreme Recreational Climbing society completed their 100th successful summit today! To commemorate the occasion, we took a picture of all the members standing together in one row, to use for marketing purposes.</p>

<p>However, the photograph looks messy; as usual, the members refused to order themselves in any kind of aesthetically pleasing way. We will need to reorder the picture.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 480px; height: 225px;"></p>

<p style="text-align: center;">Figure A.1: This picture has been cut up and pasted back together to solve Sample Input 1.</p>

<p>Our research tells us that having the climbers in ascending (non-decreasing) height order from left to right will be most visually appealing. We must cut up the picture we have and somehow paste it back together in this order.</p>

<p>Find the minimum number of cuts you need to make to put the photograph into ascending order.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer n (1 ≤ n ≤ 10<sup>6</sup>), the number of people in the photo.</li>
	<li>One line with n integers h<sub>1</sub>, . . . , h<sub>n</sub> (1 ≤ h<sub>i</sub> ≤ 2 · 10<sup>9</sup> for each i), the heights of the people in the photograph, from left to right.</li>
</ul>

### 출력 

 <p>Output the minimum number of cuts needed to rearrange the photograph into any one ascending (non-decreasing) height order from left to right.</p>

