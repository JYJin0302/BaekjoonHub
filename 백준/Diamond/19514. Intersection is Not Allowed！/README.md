# [Diamond I] Intersection is Not Allowed! - 19514 

[문제 링크](https://acmicpc.net/problem/19514) 

### 성능 요약

메모리: 4644 KB, 시간: 304 ms

### 분류

조합론, 가우스 소거법, 린드스트롬–게셀–비엔노 보조정리, 선형대수학, 수학

### 제출 일자

2026년 01월 22일 15:22:16

### 문제 설명

<p>Consider a board of $N \times N$ squares. There are $K \le N$ pieces on the board. The pieces are initially placed on some of the top squares of the board.</p>

<p>A piece located at square $(r, c)$ can move either one square to the right to $(r, c + 1)$ or one square down to $(r + 1, c)$.</p>

<p>Your task is to count how many different ways there are to move all pieces to the given positions at the bottom of the board, so that the paths of any two different pieces have no common squares. Two ways are considered different if there exists a piece which has different routes in these ways. As the number of ways can be rather large, find it modulo $10^{9} + 7$.</p>

### 입력 

 <p>The first line of input contains an integer $T$, the number of test cases ($1 \le T \le 400$).</p>

<p>Each test case begins with a line containing two integers $N$ and $K$ representing the size of the chessboard and the number of pieces, respectively ($1 \le N \le 10^5$, $1 \le K \le 100$).</p>

<p>The second line contains $K$ integers $a_1$, $a_2$, $\ldots$, $a_K$ representing the initial positions of the pieces ($1 \le a_1 < a_2 < \ldots < a_K \le N$). Formally, the pieces are initially located at squares $(1, a_1)$, $(1, a_2)$, $\ldots$, $(1, a_K)$.</p>

<p>The third line contains $K$ integers $b_1$, $b_2$, $\ldots$, $b_K$ representing the final positions of the pieces ($1 \le b_1 < b_2 < \ldots < b_K \le N$). Formally, the pieces should be moved to $(N, b_1)$, $(N, b_2)$, $\ldots$, $(N, b_K)$.</p>

<p>The sum of all $N$ in the input does not exceed $2 \cdot 10^7$.</p>

<p>The sum of all $K$ in the input does not exceed $2 \cdot 10^4$.</p>

### 출력 

 <p>Print $T$ lines, one for each test case. Each line must contain the number of different ways to move the pieces modulo $10^{9} + 7$.</p>

