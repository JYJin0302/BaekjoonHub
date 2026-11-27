# [Diamond V] Metro quiz - 31484 

[문제 링크](https://acmicpc.net/problem/31484) 

### 성능 요약

메모리: 134184 KB, 시간: 3068 ms

### 분류

비트마스킹, 비트필드를 이용한 DP, 다이나믹 프로그래밍, 자료 구조, 해시를 사용한 집합과 맵, 수학, 집합과 맵

### 제출 일자

2024년 07월 23일 14:59:01

### 문제 설명

<p>Two Olympics spectators are waiting in a queue. They each hold a copy of the metro map of Paris, and they devised a little game to kill time. First, player A thinks of a metro line (chosen uniformly at random among all metro lines) that player B will need to guess. In order to guess, player B repeatedly asks whether the line stops at a metro station of her choice, and player A answers truthfully. After enough questions, player B will typically know with certainty which metro line player A had in mind. Of course, player B wants to minimise the number of questions she needs to ask.</p>

<p>You are given the map of the $N$ metro lines (numbered from $1$ to $N$), featuring a total of $M$ metro stations (numbered from $0$ to $M - 1$) and indicating, for each line, those stations at which the line stops. Please compute the expected number of questions that player B needs to ask to find the answer, in the optimal strategy.</p>

<p>In other words, given a strategy $S$, note $Q_{S,j}$ the number of questions asked by the strategy if the metro line in the solution is line $j$. Then, note</p>

<p>$$E_S = \mathbb{E}[Q_S] = \frac{1}{N}\sum_{j=1}^{N}{Q_{S,j}}$$</p>

<p>the expected value of $Q_{S,j}$ assuming that $j$ is uniformly chosen from the set of all metro lines. Your task is to compute $\min_S$ $E_S$.</p>

<p>If it is not always possible for player B to know which line player A had in mind with certainty, output <code>not possible</code>.</p>

### 입력 

 <p>The first line contains the number $N$. The second line contains the number $M$. Then follow $M$ lines: the $k$<sup>th</sup> such line contains first a positive integer $n \le N$, then a space, and then $n$ space-separated integers $s_1,s_2, \dots ,s_n$; these are the metro stations at which line $k$ stops. A line stops at a given station at most once.</p>

### 출력 

 <p>The output should contain a single line, consisting of a single number: the minimum expected number of questions that player B must ask in order to find the correct metro line, or <code>not possible</code> (in lowercase characters). Answers within $10^{-4}$ of the correct answer will be accepted.</p>

