# [Gold IV] Jet Set - 23776 

[문제 링크](https://acmicpc.net/problem/23776) 

### 성능 요약

메모리: 2168 KB, 시간: 0 ms

### 분류

구현

### 제출 일자

2024년 06월 20일 15:54:45

### 문제 설명

<p>Your wealthy friends love to brag about all their travelling. Every time you see them, they have visited some new exotic place you have never heard of. All of them are all too happy to tell you they have been <em>all</em> around the world---but you're not so sure about that. Have these jetsetters made a real <em>circumnavigation</em>?</p>

<p>There exist many different definitions of what exactly constitutes a circumnavigation, but for the purposes of this problem we consider a circumnavigation a journey starting and ending at the same point and visiting all meridians (lines of longitude) along the way. Note that the North and South Pole are part of every meridian.</p>

<p style="text-align: center;"><img alt="" src=""></p>

<p style="text-align: center;">Figure 1: Illustration of Sample Input 1, giving a circumnavigation starting and ending in Reykjavík, with additional waypoints in Athens, Jakarta, Honolulu and Chicago.</p>

<p>Amelia, one of your rich friends, gave you a log of her flights in the form of a list of waypoints. Her trip started at the first waypoint, visited the remaining waypoints in order, and finally went back from the last waypoint to the first. Between consecutive waypoints, Amelia always travelled along the shortest circular arc connecting the two points. Find out whether Amelia's trip can be considered a circumnavigation in the above sense, and if not find a meridian that Amelia never visited. In that case, always report exactly an integer-valued or half-integer-valued meridian.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer $n$ ($2 \le n \le 1\,000$), the number of waypoints.</li>
	<li>$n$ lines, each with two integers $\phi$ and $\lambda$ ($-90 < \phi < 90, -180 \le \lambda < 180$), the latitude and longitude of one of the waypoints.</li>
</ul>

<p>No two consecutive waypoints along the route are equal or antipodes (opposite points on the sphere) of each other.</p>

### 출력 

 <p>If the route is a valid circumnavigation, output <code>yes</code>. Otherwise, output <code>no</code>, followed by a longitude $\lambda$ ($-180 \le \lambda < 180$) which the route never visited. The longitude must end in either <code>.0</code> or <code>.5</code>.</p>

