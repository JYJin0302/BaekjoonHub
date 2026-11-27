# [Diamond V] Heroes of Coin Flipping - 20239 

[문제 링크](https://acmicpc.net/problem/20239) 

### 성능 요약

메모리: 81204 KB, 시간: 1108 ms

### 분류

자료 구조, 기댓값의 선형성, 수학, 확률론, 트리, 트라이

### 제출 일자

2023년 08월 12일 15:22:57

### 문제 설명

<p>It is year 2030. Professional coin flipping has become the most popular game on the Internet. Latest coin flipping World Championship gathered the record amount of participants from around the world! There are $2^k$ participants, competing in a single-elimination tournament for the title of the Coin Flipping World Champion. For simplicity, we will refer to participants as numbers from $1$ to $2^k$.</p>

<p>In the first stage, participants are split into pairs: 1 against 2, 3 against 4, ... $2^k - 1$ against $2^k$. The winner of each match advances to the next stage. Every next stage goes on similarly: remaining participants are sorted by their number, then split into pairs to play their matches. The last $k$-th stage is just one match that crowns the world's best coin flipper. All participants' coin-flipping skills are almost identical to each other: in a match with any two participants, the probability of one of them winning is exactly $\frac 12$.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 472px; height: 339px;"></p>

<p style="text-align: center;">An example of a single-elimination tournament with 8 participants. S$X$M$Y$ is a shorthand for the $Y$-th match of the $X$-th stage.</p>

<p>Hedy missed the live broadcast of the tournament, so she's going to watch all the recordings after the fact. She already knows the list of all participants (and their numbers), but doesn't know any match outcomes. Friends suggested Hedy $n$ matches to watch first (without spoiling the result, of course!). First she is going to watch these $n$ matches in a specific order, then watch all the remaining matches in random order.</p>

<p>Hedy considers a match <em>exciting</em> if she doesn't know the winner of that match before watching it. For example, after watching the final, both semifinals will not be exciting for her, because she will have already seen the semifinals winners competing in the final. </p>

<p>Find the expected number of exciting matches, averaged over all possible tournament outcomes and watch orders.</p>

### 입력 

 <p>The first line of the input contains two integers $k$ and $n$ ($1 \le k \le 30$; $0 \le n \le \min(2^k - 1, 10^5)$). Next $n$ lines describe the suggested matches in order Hedy is going to watch them. Each line contains two integers $s_i$ and $m_i$, the stage and the number of the match within that stage ($1 \le s_i \le k$; $1 \le m_i \le 2^{k-s_i}$; all pairs $(s_i, m_i)$ are distinct).</p>

### 출력 

 <p>Print a single real number --- the expected number of exciting matches. The absolute or relative error should not exceed $10^{-9}$.</p>

