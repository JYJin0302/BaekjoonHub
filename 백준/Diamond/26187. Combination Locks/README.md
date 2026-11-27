# [Diamond III] Combination Locks - 26187 

[문제 링크](https://acmicpc.net/problem/26187) 

### 성능 요약

메모리: 2184 KB, 시간: 4 ms

### 분류

이분 매칭, 게임 이론

### 제출 일자

2023년 11월 15일 14:13:23

### 문제 설명

<p>Alice and Bob are playing with combination locks. Each of them has a combination lock that consists of $N$ rotating discs with digits <code>0</code> to <code>9</code> engraved on them. Their friend Charlie doesn't have a lock and has devised a game to keep them occupied. He will keep track of whether the corresponding digits of their locks match and will describe the current situation with a difference pattern string $S$. The $j$-th character of $S$ is either <code>'='</code> or <code>'.'</code> and indicates whether the $j$-th digits in Alice's and Bob's locks match or not, respectively.</p>

<p>Charlie will officiate the game, while Alice and Bob take turns with Alice starting first. On each move, a player has to change one digit of their combination lock. As Charlie only keeps track of the difference patterns, this pattern has to change for a move to be valid. He is also rather superstitious and has brought a list of patterns $P_i$ that must not appear during the game. Charlie's main task is to enforce the rule that no difference pattern repeats during the course of the game. The player who can't make a move loses the game.</p>

<p>Write a program that will determine the winner of the game if both players play optimally.</p>

### 입력 

 <p>The first line contains the number of test cases $T$. Each test case starts with a line containing two space-separated integers $N$ and $C$. This is followed by two lines that describe the starting configuration of Alice's and Bob's combination lock. A lock configuration is a string of $N$ digits. The following $C$ lines describe Charlie's superstitious patterns $P_i$. The superstitious list doesn't contain duplicates and it is guaranteed that the difference pattern of the starting lock configurations is not on the superstitious list.</p>

### 출력 

 <p>For every test case output one line with the name of the winner.</p>

