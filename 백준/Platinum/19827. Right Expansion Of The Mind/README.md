# [Platinum V] Right Expansion Of The Mind - 19827 

[문제 링크](https://acmicpc.net/problem/19827) 

### 성능 요약

메모리: 13988 KB, 시간: 64 ms

### 분류

애드 혹, 비트마스킹, 자료 구조, 집합과 맵, 문자열

### 제출 일자

2026년 01월 01일 16:21:09

### 문제 설명

<p>One day $n$ people decided to expand their mind.</p>

<p>Initially, the mind of the $i$-th person is two strings $s_i$ and $t_i$ consisting of lowercase English letters. After the expansion, the mind of the person becomes an infinite to the right string $w_i=s_i+t_i+t_i+\cdots$. That is, $w_i$ is a concatenation of $s_i$ and the infinite number of $t_i$. For example, if $s_i=\text{mi}$ and $t_i=\text{nd}$, the corresponding $w_i=\text{mindndndnd}\dots$.</p>

<p>Two persons with expanded mind are <em>interested</em> in each other, if the mind of the first person forms a subsequence of the mind of the second person, and the mind of the second person forms a subsequence of the mind of the first person. The infinite string $a$ is called a subsequence of the infinite string $b$ if there is an infinite sequence of indices $1 \leq i_1 < i_2 < i_3 < \ldots$, such that for each $j$ it is $a_j=b_{i_j}$. For example, the infinite string "<code>baaa</code>$\dots$" is a subsequence of an infinite string "<code>cabababab</code>$\dots$".</p>

<p>After having the mind expanded, people decided to split into groups in such way, that any two persons in one group are interested in each other. Your task is to split them into the groups, so that the number of groups is minimal possible.</p>

### 입력 

 <p>The first line contains one integer $n$ --- the number of people that have decided to get their mind expanded ($1 \le n \le 100\,000$).</p>

<p>Each of the following $n$ lines contains two non-empty strings $s_i$ and $t_i$, consisting of lowercase English letters. They represent the minds of every person before the mind expansion.</p>

<p>It is guaranteed that the total length of all strings doesn't exceed $1\,000\,000$.</p>

### 출력 

 <p>The first line must contain one integer --- the minimum number of groups.</p>

<p>Then print each group in the following way: first print the number of people in this group and then the indices of them.</p>

<p>Each of the indices must be printed exactly once. The groups and indices of the people in the group can be printed in any order. If there are multiple ways to split the people, you can print any of them.</p>

