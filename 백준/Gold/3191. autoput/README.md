# [Gold II] autoput - 3191 

[문제 링크](https://acmicpc.net/problem/3191) 

### 성능 요약

메모리: 121912 KB, 시간: 100 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 07월 11일 18:35:17

### 문제 설명

<p>Imagine one simple road in a coordinate system. Road is going from left to right, following the configuration of the land and within one square it can: </p>

<ol style="list-style-type:lower-alpha">
	<li>stay on the same height </li>
	<li>go down or up by one square </li>
</ol>

<p>Car is driving on the road from left to right. The time needed to travel through a single square is either A seconds for the case a), or B seconds for the case b). </p>

<p>However, we can build a tunnel under some mountain or a viaduct above some valley. These objects have to be horizontal, and the time needed for a car to travel through a single square on a tunnel or viaduct is C seconds. </p>

<p>Write a program that will, for a given configuration of land, calculate the minimal time for a car to travel the whole road with optimal construction of tunnels and viaducts. Total number of objects built must not be greater than the given number K. </p>

<p style="text-align: center;"><img alt="" src="" style="width: 428px; height: 237px;"></p>

<p>Figure above corresponds to the third example. Original road is denoted by the thin line, and the optimal path is denoted by the thick line. Because the number of objects is restricted to 2, we could not build a tunnel under the first mountain. </p>

### 입력 

 <p>First line of input contains three integers A, B and C, 1 ≤ A,B,C ≤ 100. </p>

<p>Second line of input contains two integers N and K, 1 ≤ N ≤ 30,000, 1 ≤ K ≤ 1,000. </p>

<p>Third line of input contains a sequence of N characters that describes the configuration of the land, from left to right. Each character in the sequence is one of the following: </p>

<ul>
	<li>'D' in next square land is going DOWN </li>
	<li>'R' in next square land is staying on the SAME HEIGHT </li>
	<li>'G' in next square land is going UP </li>
</ul>

### 출력 

 <p>First and only line of output should contain the minimal time from the problem statement. </p>

