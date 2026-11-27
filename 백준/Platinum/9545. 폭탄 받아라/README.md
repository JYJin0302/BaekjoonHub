# [Platinum V] 폭탄 받아라 - 9545 

[문제 링크](https://acmicpc.net/problem/9545) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

해 구성하기, 깊이 우선 탐색, 다이나믹 프로그래밍, 그래프, 그래프 탐색

### 제출 일자

2023년 08월 25일 10:16:14

### 문제 설명

<p>A digraph is a graph with orientation... oh, sorry, not this time. Let’s stop being nerds for a minute and talk about languages (human languages, not PHP).</p>

<p>Digraphs are pairs of characters that represent one phoneme (sound). For example, “ch” in English (as in “church”) is a single consonant sound. The languages of Central Europe are fond of digraphs: Hungarian “sz”, Czech “ch” and Polish “rz” are fine examples of them.</p>

<p>Digraphs are very annoying for people who do not use them natively. We will make up a letter-puzzle specifically for those people. Given a list of digraphs, construct a biggest possible square of lower case English letters such that its rows and columns do not contain any of these digraphs. This means that no two consecutive letters (read from top to bottom or from left to right) can form a digraph.</p>

### 입력 

 <p>The first line of input contains the number of test cases T. The descriptions of the test cases follow:</p>

<p>Each test case starts with an integer n, 0 ≤ n ≤ 676, denoting the number of forbidden digraphs. The n following lines contain the digraphs.</p>

### 출력 

 <p>For each test case print a square of the largest possible size which does not contain any of the digraphs. If it is possible to construct a square of size 20 × 20 or bigger, print only a 20 × 20 square.</p>

