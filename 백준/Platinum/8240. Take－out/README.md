# [Platinum III] Take-out - 8240 

[문제 링크](https://acmicpc.net/problem/8240) 

### 성능 요약

메모리: 42232 KB, 시간: 172 ms

### 분류

자료 구조, 스택

### 제출 일자

2025년 02월 18일 15:04:38

### 문제 설명

<p>Little Edna has received the take-out game as a present. Take-out is a single player game, in which the player is given a sequence of n adjacent blocks, numbered from 1 to n. Each block is either black or white, and there are k times as many white blocks as there are black ones.</p>

<p>The player's goal is to remove all the blocks by certain permissible moves.</p>

<p>A single move consists in removing exactly k white blocks and a single black block without changing the positions of other blocks. The move is permissible if there is no "gap" (a space left by a previously taken out block) between any two blocks being removed.</p>

<p>Help poor little Edna in finding any sequence of permissible moves that remove all the blocks.</p>

### 입력 

 <p>In the first line of the standard input there are two integers, n and k (2 ≤ n ≤ 1,000,000, 1 ≤ k ≤ n-1), separated by a single space, that denote the total number of blocks used in the game, and the number of white blocks per black node (to be removed in every move). In all the tests the condition k+1|n holds.</p>

<p>In the second line there is a string of n letters b or c. These tell the colours of successive blocks (in Polish): b (for biały) - white, c (for czarny) - black. You may assume that in all the tests there exists a sequence of permissible moves that takes out all the blocks.</p>

### 출력 

 <p>Your program should print \( \frac{n}{k+1} \) lines to the standard output. Successive lines should describe successive moves. Each line should contain k+1 integers, in increasing order, separated by single spaces, that denote the numbers of blocks to be removed in the move.</p>

