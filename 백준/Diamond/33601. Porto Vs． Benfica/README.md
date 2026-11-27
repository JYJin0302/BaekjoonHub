# [Diamond III] Porto Vs. Benfica - 33601 

[문제 링크](https://acmicpc.net/problem/33601) 

### 성능 요약

메모리: 67868 KB, 시간: 384 ms

### 분류

너비 우선 탐색, 데이크스트라, 그래프, 그래프 탐색, 최소 공통 조상, 최단 경로, 작은 집합에서 큰 집합으로 합치는 테크닉, 트리

### 제출 일자

2025년 05월 12일 12:59:50

### 문제 설명

<p>FC Porto and SL Benfica are the two largest football teams in Portugal. Naturally, when the two play each other, a lot of people travel from all over the country to watch the game. This includes the Benfica supporters’ club, which is going to travel from Lisbon to Porto to watch the upcoming game. To avoid tensions between them and the Porto supporters’ club, the national police want to delay their arrival to Porto as much as they can.</p>

<p>The road network in Portugal can be modelled as a simple, undirected, unweighted, connected graph with $n$ vertices and $m$ edges, where vertices represent towns and edges represent roads. Vertex $1$ corresponds to Lisbon, i.e., the starting vertex of the supporters’ club, and vertex $n$ is Porto, i.e., the destination vertex of the supporters’ club. The supporters’ club wants to minimize the number of roads they take to reach Porto.</p>

<p>The police are following the supporters’ club carefully, and so they always know where they are. To delay their arrival, at any point the police can pick exactly one road and block it, as long as the supporters’ club isn’t currently traversing it. They can do this exactly once, and once they do that, the road is blocked forever. Once the police block a road, the supporters’ club immediately learns that that road is blocked, and they can change their route however they prefer. Furthermore, the supporters’ club knows that the police are planning on blocking some road and can plan their route accordingly.</p>

<p>Assuming that both the supporters’ club and the police always make optimal choices, determine the minimum number of roads the supporters’ club needs to traverse to go from Lisbon to Porto. If the police can block the supporters’ club from ever reaching Porto, then output <code>-1</code>.</p>

### 입력 

 <p>The first line contains two integers $n$ and $m$ ($2 ≤ n ≤ 200\, 000$, $n−1 ≤ m ≤ \min\{n(n-1)/2, 200\, 000\}$) — the number of towns and the number of roads in the road network of Portugal.</p>

<p>Each of the next $m$ lines contains two integers $s_i$ and $t_i$ ($1 ≤ s_i , t_i ≤ n$) — the two towns connected by the $i$-th road.</p>

<p>It is guaranteed that the road network is connected, each road connects two distinct towns, and that there are no repeated roads.</p>

### 출력 

 <p>Print the minimum number of roads the supporters’ club needs to traverse to travel from Lisbon to Porto.</p>

