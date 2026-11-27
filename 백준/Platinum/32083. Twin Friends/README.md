# [Platinum II] Twin Friends - 32083 

[문제 링크](https://acmicpc.net/problem/32083) 

### 성능 요약

메모리: 8940 KB, 시간: 88 ms

### 분류

조합론, 다이나믹 프로그래밍, 수학, 누적 합

### 제출 일자

2024년 10월 17일 12:43:45

### 문제 설명

<p>You meet two new friends who are twins. The name of the elder twin is $A$, which consists of $N$ characters. While the name of the younger twin is $B$, which consists of $M$ characters. It is known that $N ≤ M$.</p>

<p>You want to call each of them with a nickname. For the elder twin, you want to pick any permutation of $A$ as the nickname. For the younger twin, you want to remove exactly $M - N$ characters from any permutation of $B$. Denote the nicknames of the elder twin and the younger twin as $A'$ and $B'$, respectively.</p>

<p>You want the nicknames to satisfy the following requirement. For each i that satisfies $1 ≤ i ≤ N$, $B'_i$ must be equal to either $A'_i$ or the next letter that follows alphabetically after $A'_i$ (if such a next letter exists).</p>

<p>Determine the number of different pairs of nicknames $(A' , B' )$ that satisfy the requirement. Two pairs of nicknames are considered different if at least one of the nicknames are different. As the result might be large, find the answer modulo $998\, 244\, 353$.</p>

### 입력 

 <p>The first line consists of two integers $N$ $M$ ($1 ≤ N ≤ M ≤ 200\, 000$).</p>

<p>The second line consists of a string $A$ of length $N$.</p>

<p>The third line consists of a string $B$ of length $M$.</p>

<p>All strings consist of only upper-case letters.</p>

### 출력 

 <p>Output a single integer representing number of different pairs $(A' , B' )$ that satisfy the requirement, modulo $998\, 244\, 353$.</p>

