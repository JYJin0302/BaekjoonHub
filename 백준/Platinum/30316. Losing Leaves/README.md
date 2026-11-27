# [Platinum III] Losing Leaves - 30316 

[문제 링크](https://acmicpc.net/problem/30316) 

### 성능 요약

메모리: 185556 KB, 시간: 504 ms

### 분류

그리디, 트리

### 제출 일자

2025년 02월 21일 20:11:08

### 문제 설명

<p>Here at the Benelux Advanced Phone Company (BAPC), we are the proud owners of the largest telephone network in the Benelux area. Unfortunately, our network has become too large for us to manage properly. As such, we have decided to sell part of our network.</p>

<p>The network of the BAPC consists of interconnected transmission nodes. One transmission node is marked as the central switch. All other nodes have exactly one upstream transmission node. For each transmission node, if we follow the upstream connections, we will finally end up at the central switch. A node is considered a customer transmission node when it is a leaf, i.e. when it has no downstream nodes.</p>

<p>When selling parts of our network, integrity must be maintained. That means that whenever we sell a transmission node $X$, we also have to sell nodes downstream of $X$.</p>

<p>Overall, BAPC decided to sell exactly $k$ transmission nodes. While there may be many options to choose these $k$ nodes, we actually want to make our lives as easy as possible: After selling, we want to minimize the number of customer transmission nodes in our network, while maintaining the network's integrity.</p>

<p>As an example, consider the second sample case, visualized in Figure L.1. The three striped red nodes are sold, and the two bold green nodes are the remaining customer nodes.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 200px; height: 346px;"></p>

<p style="text-align: center;">Figure L.1: Visualization of the second sample input.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers $n$ and $k$ ($0\leq k < n\leq 10^6$), the number of transmission nodes, and the number of nodes to sell.</li>
	<li>$n-1$ lines, the \(i\)th of which contains one integer \(p_i\) (\(0 \leq p_i < i\)) indicating that transmission node \(i\) (\(1 \leq i < n\)) has an outgoing connection to node \(p_i\).</li>
</ul>

<p>The transmission nodes are numbered from \(0\) to \(n - 1\), inclusive. Node $0$ is always the central switch.</p>

### 출력 

 <p>Output the minimum number of customer transmission nodes after selling $k$ transmission nodes. Note that if the central switch is the only remaining node, it also counts as a customer node.</p>

