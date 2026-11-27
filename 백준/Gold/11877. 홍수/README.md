# [Gold III] 홍수 - 11877 

[문제 링크](https://acmicpc.net/problem/11877) 

### 성능 요약

메모리: 2260 KB, 시간: 96 ms

### 분류

해 구성하기, 그리디

### 제출 일자

2020년 12월 29일 22:40:24

### 문제 설명

<p>Mirko dreamt of a histogram last night that consists of N columns. Each column is one meter wide and the heights of the columns in meters are h<sub>1</sub>, h<sub>2</sub>, ..., h<sub>N</sub>.</p>

<p><img alt="" src="" style="float:right; height:302px; width:173px">The capacity of a histogram is the maximal amount of water that a histogram can hold so that the configuration of the water is "stable", or, in other words, that it doesn’t move under the influence of gravity. The image on the right depicts an example of a stable configuration.</p>

<p>Formally, let us denote the heights of water above the columns with v<sub>1</sub>, v<sub>2</sub>, ..., v<sub>N</sub>.</p>

<p>The configuration of the water is stable if the following holds:</p>

<ul>
	<li>h<sub>i</sub> + v<sub>i</sub> ≤ h<sub>i−1</sub> + v<sub>i−1</sub>, for each i ≥ 2 such that v<sub>i</sub> > 0</li>
	<li>h<sub>i</sub> + v<sub>i</sub> ≤ h<sub>i+1</sub> + v<sub>i+1</sub>, for each i ≤ N − 1 such that v<sub>i</sub> > 0</li>
	<li>v<sub>1</sub> = 0 and v<sub>N</sub> = 0</li>
</ul>

<p>When Mirko woke up, he wanted to know whether he could somehow choose the heights of columns that are a permutation of the set {1, 2, ..., N} such that the capacity of such histogram is equal to its lucky number X? Help Mirko and find one histogram that meets his requirements.</p>

### 입력 

 <p>The first line of input contains integers N and X (1 ≤ N ≤ 1 000 000, 1 ≤ X ≤ 10<sup>15</sup>).</p>

### 출력 

 <p>If a histogram of capacity exactly X does not exist, output −1. Otherwise, output numbers h<sub>1</sub>, h<sub>2</sub>, ..., h<sub>N</sub> that meet the given requirements in the first line separated by space. If there are multiple such solutions, output any.</p>

