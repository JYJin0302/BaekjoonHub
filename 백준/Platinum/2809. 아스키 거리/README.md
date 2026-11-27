# [Platinum I] 아스키 거리 - 2809 

[문제 링크](https://acmicpc.net/problem/2809) 

### 성능 요약

메모리: 113924 KB, 시간: 1216 ms

### 분류

아호-코라식, 자료 구조, 문자열, 트리, 트라이

### 제출 일자

2025년 08월 07일 16:26:08

### 문제 설명

<p>Mirko‟s ASCII street is made of N lowercase letters of the English alphabet. The city government occasionally replaces the tiles in the street. However, the letter tiles are in high demand, so the government has only M different tile patterns available.</p>

<p>The i<sup>th</sup> tile pattern consists of L<sub>i</sub> letters. A tile cannot be rotated or broken into pieces, and it can only be placed such that the tile letters coincide with the contiguous letter subsequence in the street. Tiles can overlap and we can use multiple tiles of the same pattern.</p>

<p>A street cell is untileable if it cannot be covered by any tile. Compute the number of untileable cells.</p>

### 입력 

 <p>The first line of input contains the positive integer N (1 ≤ N ≤ 300 000), the length of the street.</p>

<p>The second line of input contains N lowercase English letters, the letter sequence in the street.</p>

<p>The third line of input contains the positive integer M (1 ≤ M ≤ 5000), the number of tile patterns.</p>

<p>Each of the next M lines contains a description of a tile pattern with length L<sub>i</sub> (1 ≤ L<sub>i</sub> ≤ 5000). The tile pattern descriptions consist of lowercase English letters.</p>

### 출력 

 <p>The first and only line of output must contain the required number of untileable cells.</p>

<p> </p>

