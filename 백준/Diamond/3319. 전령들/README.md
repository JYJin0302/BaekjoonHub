# [Diamond III] 전령들 - 3319 

[문제 링크](https://acmicpc.net/problem/3319) 

### 성능 요약

메모리: 23656 KB, 시간: 112 ms

### 분류

볼록 껍질을 이용한 최적화, 다이나믹 프로그래밍, 자료 구조, 트리

### 제출 일자

2024년 03월 29일 14:47:49

### 문제 설명

<p>Once upon a time, there were N medieval towns in the beautiful Moldavian territory, uniquely numbered from 1 through N. The town numbered with 1 was the capital city. The towns were connected by N-1 bidirectional roads, each road having a length expressed in kilometers. There was a unique way to travel between any pair of towns without going through a town twice (i.e. the graph of roads was a tree).</p>

<p>When a town was attacked, the situation had to be reported as soon as possible to the capital. The message was carried by harbingers, one of which resided in each town. Each harbinger was characterized by the amount of time required to start the journey and by his constant speed (expressed in minutes per kilometer) after departure.</p>

<p>The message from a town was always carried on the unique shortest path to the capital. Initially, the harbinger from the attacked town carried the message. In each town that he traversed, a harbinger had two options: either go to the next town towards the capital, or leave the message to the harbinger from this town. The new harbinger applied the same algorithm as above. Overall, a message could be carried by any number of harbingers before arriving in the capital.</p>

<p>Your task is to find, for each town, the minimum time required to send a message from that town to the capital. </p>

### 입력 

 <p>The first line of the standard input contains one integer N, the number of towns in Moldavia. Each of the following N-1 lines contains three integers u v d, separated by one space, describing a road of length d kilometers between towns numbered with u and v. Subsequently, N-1 pairs of integers follow, one per line. The ith pair, S<sub>i</sub> V<sub>i</sub>, describes the characteristics of the harbinger in the (i+1)th town: S<sub>i</sub> is the number of minutes to prepare for the journey, and V<sub>i</sub> is the number of minutes needed to travel one kilometer. There is no harbinger in the capital. </p>

<ul>
	<li>3 ≤ N ≤ 100 000</li>
	<li>0 ≤ S<sub>i</sub> ≤ 10<sup>9</sup></li>
	<li>1 ≤ V<sub>i</sub> ≤ 10<sup>9</sup></li>
	<li>The length of each road will not exceed 10 000</li>
</ul>

### 출력 

 <p>The standard output should consist of exactly one line containing N-1 integers. The ith number represents the minimum time, in minutes, required to send a message from the (i+1)th town to the capital. </p>

