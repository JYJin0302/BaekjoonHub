# [Diamond V] Photo Op - 33503 

[문제 링크](https://acmicpc.net/problem/33503) 

### 성능 요약

메모리: 24020 KB, 시간: 320 ms

### 분류

자료 구조, 집합과 맵

### 제출 일자

2025년 07월 05일 18:37:02

### 문제 설명

<p>Farmer John's farm is full of lush vegetation and every cow wants a photo of its natural beauty. Unfortunately, Bessie still has places to be, but she doesn't want to disrupt any photo ops.</p>

<p>Bessie is currently standing at $(X,0)$ on the XY-plane and she wants to get to $(0,Y)$ ($1\le X,Y\le 10^6$). Unfortunately, $N$ ($1 \leq N \leq 3 \cdot 10^5$) other cows have decided to pose on the $X$ axis. More specifically, cow $i$ will be positioned at $(x_i,0)$ with a photographer at $(0,y_i)$ where $(1 \leq x_i,y_i \leq 10^6)$ ready to take their picture. They will begin posing moments before time $s_i$ ($1 \leq s_i < T$) and they will keep posing for a very long time (they have to get their picture just right). Here, $1\le T\le N+1$.</p>

<p>Bessie knows the schedule for every cow's photo op, and she will take the shortest Euclidean distance to get to her destination, without crossing the line of sight from any photographer to their respective cow (her path will consist of one or more line segments).</p>

<p>If Bessie leaves at time $t$, she will avoid the line of sights for all photographer/cow pairs that started posing at time $s_i \le t$, and let the distance to her final destination be $d_t$. Determine the values of $\lfloor d_t\rfloor$ for each integer $t$ from $0$ to $T-1$ inclusive.</p>

### 입력 

 <p>The first line of input contains $N$ and $T$, representing the number of cows posing on the $x$-axis and the timeframe that Bessie could leave at.</p>

<p>The second line of input contains $X$ and $Y$, representing Bessie's starting $X$ coordinate and her target $Y$ coordinate respectively.</p>

<p>The next $N$ lines contain $s_i$ $x_i$ and $y_i$. It is guaranteed that all $x_i$ are distinct from each other and $X$, and all $y_i$ are distinct from each other and $Y$. All $s_i$ will be given in increasing order, where $s_i \leq s_{i+1}$.</p>

### 출력 

 <p>Print $T$ lines, with the $t$th (0-indexed) line containing $\lfloor d_t\rfloor$.</p>

