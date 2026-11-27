# [Platinum I] Fortune Telling - 30934 

[문제 링크](https://acmicpc.net/problem/30934) 

### 성능 요약

메모리: 745140 KB, 시간: 888 ms

### 분류

조합론, 다이나믹 프로그래밍, 수학, 확률론

### 제출 일자

2024년 02월 01일 13:47:47

### 문제 설명

<p>Your fortune is to be told by a famous fortune teller. She has a number of tarot cards and a six-sided die. Using the die, she will choose one card as follows and that card shall tell your future.</p>

<p>Initially, the cards are lined up in a row from left to right. The die is thrown showing up one of the numbers from one through six with equal probability. When $x$ is the number the die shows up, the $x$-th card from the left and every sixth card following it, i.e., the $(x + 6k)$-th cards for $k = 0, 1, 2, \dots$, are removed and then remaining cards are slid left to eliminate the gaps. Note that if the number of cards remaining is less than $x$, no cards are removed. This removing and sliding procedure is repeated until only one card remains.</p>

<p>Figure G.1 illustrates how cards are removed and slid when the die shows up two.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 666px; height: 170px;"></p>

<p style="text-align: center;">Figure G.1. Removing and sliding cards</p>

<p>You are given the number of initial tarot cards. For each card initially placed, compute the probability that the card will remain in the end.</p>

### 입력 

 <p>The input is a single line containing an integer $n$, indicating the number of tarot cards, which is between $2$ and $3 \times 10^5$, inclusive.</p>

### 출력 

 <p>Output $n$ lines, the $i$-th of which should be an integer that is determined, as follows, by the probability of the $i$-th card from the left to remain in the end.</p>

<p>It can be proved that the probability is represented as an irreducible fraction $a/b$, where $b$ is not divisible by a prime number $998\, 244\, 353 = 2^{23} \times 7 \times 17 + 1$. There exists a unique integer $c$ such that $bc \equiv a \pmod {998\, 244\, 353}$ and $0 ≤ c < 998\, 244\, 353$. What should be output is this integer $c$.</p>

