# [Diamond V] Disposable Switches - 18083 

[문제 링크](https://acmicpc.net/problem/18083) 

### 성능 요약

메모리: 164188 KB, 시간: 2560 ms

### 분류

볼록 껍질을 이용한 최적화, 다이나믹 프로그래밍, 그래프, 최단 경로

### 제출 일자

2023년 07월 31일 19:07:45

### 문제 설명

<p>Having recently been hired by Netwerc Industries as a network engineer, your first task is to assess their large and dated office network. After mapping out the entire network, which consists of network switches and cables between them, you get a hunch that, not only are some of the switches redundant, some of them are not used at all! Before presenting this to your boss, you decide to make a program to test your claims.</p>

<p>The data you have gathered consists of the map of the network, as well as the length of each cable. While you do not know the exact time it takes to send a network packet across each cable, you know that it can be calculated as ℓ/v + c, where</p>

<ul>
	<li>ℓ is the length of the cable,</li>
	<li>v is the propagation speed of the cable, and</li>
	<li>c is the overhead of transmitting the packet on and off the cable.</li>
</ul>

<p>You have not been able to measure v and c. The only thing you know about them is that they are real numbers satisfying v > 0 and c ≥ 0, and that they are the same for all cables. You also know that when a network packet is being transmitted from one switch to another, the network routing algorithms will ensure that the packet takes an <em>optimal path</em>—a path that minimises the total transit time.</p>

<p>Given the map of the network and the length of each cable, determine which switches could never possibly be part of an optimal path when transmitting a network packet from switch 1 to switch n, no matter what the values of v and c are.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers n, m (2 ≤ n ≤ 2 000, 1 ≤ m ≤ 10<sup>4</sup>), the number of switches and the number of cables in the network. The switches are numbered from 1 to n.</li>
	<li>m lines, each with three integers a, b and ℓ (1 ≤ a, b ≤ n, 1 ≤ ℓ ≤ 10<sup>9</sup>), representing a network cable of length ℓ connecting switches a and b.</li>
</ul>

<p>There is at most one cable connecting a given pair of switches, and no cable connects a switch to itself. It is guaranteed that there exists a path between every pair of switches.</p>

### 출력 

 <p>First output a line with an integer k, the number of switches that could never possibly be part of an optimal path when a packet is transmitted from switch 1 to switch n. Then output a line with k integers, the indices of the k unused switches, in increasing order.</p>

