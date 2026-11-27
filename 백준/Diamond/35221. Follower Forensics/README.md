# [Diamond IV] Follower Forensics - 35221 

[문제 링크](https://acmicpc.net/problem/35221) 

### 성능 요약

메모리: 38744 KB, 시간: 504 ms

### 분류

자료 구조, 분리 집합, 그리디, 작은 집합에서 큰 집합으로 합치는 테크닉

### 제출 일자

2026년 02월 03일 13:20:23

### 문제 설명

<p>Your social media company ConnectHub prides itself on how easily information spreads through its network.</p>

<p>Accounts can share posts directly with their followers using the share button, or with the accounts they follow by posting in the comments. ConnectHub is famous for the virality of its users: a post from any account was able to reach every other account, possibly through a chain of shares and comments.</p>

<p>But disaster struck: a database mishap wiped out all records of who follows whom. One piece of data may have survived, though — for each account, you have the number of its followers and the number of accounts it follows. Maybe even those numbers have been corrupted, but it's all you have.</p>

<p>Your task is to rebuild the missing database so that these counts are correct, and ConnectHub once again has full virality.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
<li>One line with an integer $n$, the number of accounts, where $1 \leq n \leq 100\,000$.</li>
<li>One line with $n$ integers $a_1,\ldots, a_n$ satisfying $0 \leq a_i \leq n$ for each $i$, where $a_i$ is the number of accounts followed by the $i$th account.</li>
<li>One line with $n$ integers $b_1,\ldots, b_n$ satisfying $0 \leq b_i \leq n$ for each $i$, where $b_i$ is the number of accounts following the $i$th account.</li>
</ul>

<p>Additionally, it is guaranteed that \[ \sum_{i=1}^n a_i + \sum_{i=1}^n b_i \leq 2\,000\,000. \]</p>

<p>Note that the input is not guaranteed to allow for any reconstruction, fully viral or not. For those familiar with that terminology, full virality is equivalent to weak connectivity.</p>

### 출력 

 <p>If a reconstruction is possible, output a network</p>

<ul>
<li>One line with two integers: the number $n$ of accounts, and the number $m$ of connections. This is the same $n$ as in the input.</li>
<li>Then $m$ lines, each consisting of two integers $a$ and $b$, specifying that account $a$ follows account $b$.</li>
</ul>

<p>Otherwise output "<code>impossible</code>".</p>

<p>Note that it is not allowed for an account to follow the same account twice, nor to follow itself.</p>

