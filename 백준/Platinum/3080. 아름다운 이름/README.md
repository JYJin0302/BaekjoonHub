# [Platinum III] 아름다운 이름 - 3080 

[문제 링크](https://acmicpc.net/problem/3080) 

### 성능 요약

메모리: 11104 KB, 시간: 80 ms

### 분류

자료 구조, 재귀, 문자열, 트리, 트라이

### 제출 일자

2023년 03월 03일 22:49:24

### 문제 설명

<p>Teacher Herkabe has decided to rank his students again. This time, he wants his list to also be aesthetically pleasant, so he has decided that similar names (those beginning with the same letter or sequence of letters) must be close to one another on the list. Therefore, he has devised the following rule:</p>

<p>For every two names on the list that begin with the same letter sequence, all names between them on the list must also begin with that letter sequence.</p>

<p>For example, consider the names MARTHA and MARY (characters from a beautiful story). They both begin with the sequence MAR, so names beginning with the same sequence (like MARCO and MARVIN) can appear in between (but not MAY, for example).</p>

<p>Notice that the lexicographically sorted ordering always satisfies this rule, but it is by no means the only valid ordering. Your task is determining how many different orderings satisfy the rule, i.e. how many options teacher Herkabe has for his ranking list.</p>

### 입력 

 <p>The first line of input contains the positive integer N (3 ≤ N ≤ 3000), the number of names.</p>

<p>Each of the following N lines contains a single name: a sequence of between 1 and 3000 (inclusive) uppercase English letters. The names are distinct and given in no particular order.</p>

### 출력 

 <p>The first and only line of output must contain the required number of possible ranking lists, modulo 1 000 000 007.</p>

