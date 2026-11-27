# [Gold I] 수조 - 2130 

[문제 링크](https://acmicpc.net/problem/2130) 

### 성능 요약

메모리: 5224 KB, 시간: 24 ms

### 분류

이분 탐색, 누적 합, 스위핑

### 제출 일자

2021년 08월 18일 22:26:03

### 문제 설명

<p>During the next century certain regions on earth will experience severe water shortages. The old town of Ugbar has already started to prepare itself for the worst. Recently they created a network of pipes connecting the cisterns that distribute water in each neighbourhood, making it easier to fill them at once from a single source of water. But in case of water shortage the cisterns above a certain level will be empty since the water will flow to the cisterns below.</p>

<p><img alt="" src="" style="height:394px; width:500px"></p>

<p>You have been asked to write a program to compute the level to which cisterns will be filled with a certain volume of water, given the dimensions and position of each cistern. To simplify we will neglect the volume of water in the pipes.</p>

<p>Write a program which for each data set:</p>

<ul>
	<li>reads the description of cisterns and the volume of water,</li>
	<li>computes the level to which the cisterns will be filled with the given amount of water,</li>
	<li>writes the result.</li>
</ul>

### 입력 

 <p>The first line of the input contains the number of data sets k, 1 ≤ k ≤ 30. The data set follow.</p>

<p>The first line of each data set contains one integer n, the number of cisterns, 1 ≤ n ≤ 50 000. Each of the following n lines consists of 4 nonnegative integers, separated by single spaces: b, h, w, d - the base level of the cistern, its height, width and depth in meters, respectively. The integers satisfy 0 ≤ b ≤ 10<sup>6</sup> and 1 ≤ h·w·d ≤ 40 000. The last line of the data set contains an integer V - the volume of water in cubic meters to be injected into the network. Integer V satisfies 1 ≤ v ≤ 2·10<sup>9</sup>.</p>

### 출력 

 <p>The output should consist of exactly d lines, one line for each data set.</p>

<p>Line i, 1 ≤ i ≤ d, should contain the level that the water will reach, in meters, rounded up to two fractional digits, or the word 'OVERFLOW', if the volume of water exceeds the total capacity of the cisterns.</p>

<p>Your result must be accurate to within ±10<sup>-2</sup> absolute error.</p>

