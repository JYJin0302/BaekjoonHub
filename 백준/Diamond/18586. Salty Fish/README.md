# [Diamond II] Salty Fish - 18586 

[문제 링크](https://acmicpc.net/problem/18586) 

### 성능 요약

메모리: 96824 KB, 시간: 1016 ms

### 분류

다이나믹 프로그래밍, 자료 구조, 유량, 그래프, 집합과 맵, 작은 집합에서 큰 집합으로 합치는 테크닉, 최대 유량 최소 컷 정리, 트리, 트리를 사용한 집합과 맵, 트리DP

### 제출 일자

2026년 02월 10일 19:28:24

### 문제 설명

<p>Little Q has an apple tree with n nodes, labeled by 1, 2, . . . , n. The root of the tree is node 1, and the length of each edge is one unit. There are a<sub>i</sub> apples on the i-th node. The price of each apple is one dollar, so if you sell t apples, you will gain t dollars.</p>

<p>Skywalkert, a close friend of Little Q, lost most of his money betting on programming contests, so he wants to steal some apples from this apple tree and sell them to make money.</p>

<p>The security system takes pictures of the nodes once per hour using m cameras. Let us denote d(x, y) as the number of edges on the shortest path from node x to node y, and denote set p(x, k) as {y | y is in subtree of x and d(x, y) ≤ k}. Note that x ∈ p(x, k). The image from the i-th camera shows the picture of all the nodes in p(x<sub>i</sub>, k<sub>i</sub>). If the security system detects a change in any of these images, it sounds an alarm, and the thief will be caught by Little Q.</p>

<p>Skywalkert is also a gifted hacker. He can lock some cameras so that images from these cameras will never change. Specifically, if he wants to lock the i-th camera, he needs to pay c<sub>i</sub> dollars to do such a hack. Skywalkert will pay for all hacks after he steals the apples and sells them.</p>

<p>Please write a program to help Skywalkert earn the most money possible without being caught.</p>

### 입력 

 <p>The first line of the input contains an integer T (1 ≤ T ≤ 10 000), denoting the number of test cases.</p>

<p>Each test case starts by a line with two integers n and m (1 ≤ n, m ≤ 300 000), denoting the number of nodes and cameras.</p>

<p>The second line of a test case contains n − 1 integers f<sub>2</sub>, f<sub>3</sub>, . . . , f<sub>n</sub> (1 ≤ f<sub>i</sub> < i), denoting the parents of nodes 2, 3, . . . , n.</p>

<p>The third line of a test case contains n integers a<sub>1</sub>, a<sub>2</sub>, . . . , a<sub>n</sub> (1 ≤ a<sub>i</sub> ≤ 10<sup>9</sup>), denoting the number of apples on nodes 1, 2, . . . , n.</p>

<p>Each of the next m lines of a test case contains three integers x<sub>i</sub>, k<sub>i</sub>, and c<sub>i</sub> (1 ≤ x<sub>i</sub> ≤ n, 0 ≤ k<sub>i</sub> ≤ n, 1 ≤ c<sub>i</sub> ≤ 10<sup>9</sup>), denoting the parameters of each camera.</p>

<p>It is guaranteed that the sum of all n is at most 10<sup>6</sup>, and the sum of all m is at most 10<sup>6</sup>.</p>

### 출력 

 <p>For each test case, print a single line containing an integer denoting the maximum amount of dollars Skywalkert can earn.</p>

