# [Gold II] Karte - 32971 

[문제 링크](https://acmicpc.net/problem/32971) 

### 성능 요약

메모리: 174068 KB, 시간: 168 ms

### 분류

비트마스킹, 브루트포싱, 그리디

### 제출 일자

2025년 07월 25일 14:42:37

### 문제 설명

<p>On Vito’s table, there are $N$ red cards labeled with numbers from $1$ to $N$ and $M$ blue cards labeled with numbers from $1$ to $M$. Each pair of red and blue cards $(c, p)$ (where $c$ represents a red card and $p$ a blue card) can create a <em>COMBO</em> move.</p>

<p>The strength of a deck of cards is defined as:</p>

<p style="text-align: center;"><em>strength</em> = (<em>number of COMBO moves</em>) - $X$ · (<em>number of red cards</em>) − $Y$ · (<em>number of blue cards</em>)</p>

<p>where the <em>number of COMBO moves</em> is the number of pairs $(c, p)$ such that the red card $c$ and the blue card $p$ are in the chosen deck. Vito can include any card from the table in his deck. Help Vito find the value of the strongest deck he can build. Vito can also choose an empty deck of cards.</p>

### 입력 

 <p>The first line contains $4$ natural numbers $N$, $M$, $X$, $Y$ ($1 ≤ N, M ≤ 21$, $0 ≤ X, Y ≤ 30$).</p>

<p>In the next $N$ lines, there is a sequence of $$M characters ($0$ or $1$), where the $j$-th character indicates whether the $i$-th red card and the $j$-th blue card create a <em>COMBO</em> move.</p>

### 출력 

 <p>In the first and only line, output the value of the strongest deck of cards that Vito can build.</p>

