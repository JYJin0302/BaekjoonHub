# [Platinum I] Wireless Communication Network - 24960 

[문제 링크](https://acmicpc.net/problem/24960) 

### 성능 요약

메모리: 189844 KB, 시간: 508 ms

### 분류

데카르트 트리, 다이나믹 프로그래밍, 자료 구조, 그리디, 스택, 트리, 트리DP

### 제출 일자

2025년 09월 18일 15:52:31

### 문제 설명

<p>We are setting up a wireless communication network in a mountain range. Communication stations are to be located on the summits. The summits are on a straight line and have different altitudes.</p>

<p>To minimize the cost, our communication network should have a tree structure, which is a connected graph with the least number of edges. The structure of the network, that is, which stations to communicate with which other stations, should be decided in advance.</p>

<p>We construct the communication network as follows.</p>

<ol>
	<li>Initially, each station forms a tree consisting of only that station.</li>
	<li>In each step, we merge two trees that are adjacent by making a link between two stations in different trees. Two trees are called <em>adjacent</em> when all the summits in between a summit in one tree and a summit in the other belong to one of these two trees. Stations to link are those on the highest summits of the two trees; they are uniquely determined because the altitudes of the summits are distinct.</li>
	<li>Repeat the step 2 until all the stations are connected, directly or indirectly.</li>
</ol>

<p>Figure D.1 depicts an example of the tree formation for Sample 1.</p>

<p>When a station detects an emergency event, an alert message should be broadcast to all the stations. On receiving a message, each station relays the message to all the stations with direct links, except for one from which it has come. The diameter of the network, that is, how many hops are sufficient to distribute messages initiated at any stations, depends on the choice of the two trees in the step 2 above.</p>

<p>To estimate the worst case delay of broadcast, we want to find the largest diameter of the network possibly constructed by the above procedure.</p>

<table class="table table-bordered">
	<tbody>
		<tr>
			<td><img alt="" src="" style="width: 311px; height: 100px;"></td>
			<td>Obtained after some repetitions of step 2 with a certain series of choices. There are three trees, $T_1$, $T_2$, and $T_3$. Here, the station h forms the tree $T_3$ consisting of only the station $h$.</td>
		</tr>
		<tr>
			<td><img alt="" src="" style="width: 311px; height: 101px;"></td>
			<td>Obtained by linking stations $g$ and $h$ in step 2. Trees $T_2$ and $T_3$, with top summits $g$ and $h$ respectively, are adjacent.</td>
		</tr>
		<tr>
			<td><img alt="" src="" style="width: 311px; height: 100px;"></td>
			<td>Obtained by linking stations $b$ and $h$ in the next step 2, merging two adjacent trees. Now all the stations form a single tree.</td>
		</tr>
	</tbody>
</table>

<p style="text-align: center;">Figure D.1. The tree formation for Sample 1</p>

### 입력 

 <p>The input consists of a single test case of the following format.</p>

<p>$\begin{align*}& n \\ & h_1 \\ & \vdots \\ & h_n \end{align*}$</p>

<p>Here, $n$ is the number of communication stations ($3 ≤ n ≤ 10^6$), and $h_i$ is an integer representing the altitude of the $i$-th station ($1 ≤ h_i ≤ n$). The altitudes of the stations are distinct, that is, $h_i \ne h_j$ if $i \ne j$.</p>

### 출력 

 <p>Output in a line a single integer representing the largest possible diameter of the tree.</p>

