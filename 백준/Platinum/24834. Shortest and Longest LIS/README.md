# [Platinum V] Shortest and Longest LIS - 24834 

[문제 링크](https://acmicpc.net/problem/24834) 

### 성능 요약

메모리: 3968 KB, 시간: 36 ms

### 분류

해 구성하기, 방향 비순환 그래프, 그리디

### 제출 일자

2026년 01월 01일 20:20:47

### 문제 설명

<p>Gildong recently learned how to find the <a href="https://en.wikipedia.org/wiki/Longest_increasing_subsequence">longest increasing subsequence</a> (LIS) in $O(n\log{n})$ time for a sequence of length $n$. He wants to test himself if he can implement it correctly, but he couldn't find any online judges that would do it (even though there are actually many of them). So instead he's going to make a quiz for you about making permutations of $n$ distinct integers between $1$ and $n$, inclusive, to test his code with your output.</p>

<p>The quiz is as follows.</p>

<p>Gildong provides a string of length $n-1$, consisting of characters '<' and '>' only. The $i$-th (1-indexed) character is the comparison result between the $i$-th element and the $i+1$-st element of the sequence. If the $i$-th character of the string is '<', then the $i$-th element of the sequence is less than the $i+1$-st element. If the $i$-th character of the string is '>', then the $i$-th element of the sequence is greater than the $i+1$-st element.</p>

<p>He wants you to find two possible sequences (not necessarily distinct) consisting of $n$ distinct integers between $1$ and $n$, inclusive, each satisfying the comparison results, where the length of the LIS of the first sequence is minimum possible, and the length of the LIS of the second sequence is maximum possible.</p>

### 입력 

 <p>Each test contains one or more test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$).</p>

<p>Each test case contains exactly one line, consisting of an integer and a string consisting of characters '<' and '>' only. The integer is $n$ ($2 \le n \le 2 \cdot 10^5$), the length of the permutation you need to find. The string is the comparison results explained in the description. The length of the string is $n-1$.</p>

<p>It is guaranteed that the sum of all $n$ in all test cases doesn't exceed $2 \cdot 10^5$.</p>

### 출력 

 <p>For each test case, print two lines with $n$ integers each. The first line is the sequence with the minimum length of the LIS, and the second line is the sequence with the maximum length of the LIS. If there are multiple answers, print any one of them. Each sequence should contain all integers between $1$ and $n$, inclusive, and should satisfy the comparison results.</p>

<p>It can be shown that at least one answer always exists.</p>

