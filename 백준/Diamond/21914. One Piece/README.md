# [Diamond III] One Piece - 21914 

[문제 링크](https://acmicpc.net/problem/21914) 

### 성능 요약

메모리: 21484 KB, 시간: 160 ms

### 분류

깊이 우선 탐색, 자료 구조, 그래프, 그래프 탐색, 수학, 확률론, 세그먼트 트리, 트리

### 제출 일자

2025년 11월 03일 14:11:05

### 문제 설명

<p>The Goa Kingdom is a network of $n$ islands (identified by numbers from $1$ to $n$), connected by $n - 1$ bidirectional bridges. The network is structured as a tree. Some islands contain valuable treasures, and Luffy is on a quest to find the treasures from all islands.</p>

<p>In order to ease the treasure hunting, he bought a detector from a local merchant. The detector should have shown the distance from each island to the closest treasure (in number of bridges); however, it seems to be horribly broken, and shows the distance from each island to the <strong>farthest</strong> treasure instead!</p>

<p>Nonetheless, he kept the distances that his broken detector showed for each of the islands, hoping that maybe not everything is lost. He now wonders which islands have a higher chance of containing a treasure.</p>

<p>Your task is to help Luffy by arranging the $n$ islands in order, from highest to lowest probability of containing a treasure, given that he now knows the distances shown by the detector for each of the $n$ islands. Initially, you can assume that each of the islands independently had a $50\%$ chance of containing a treasure; in other words, every subset of islands was equally likely to be the subset of the treasure islands.</p>

### 입력 

 <p>The first line of the input contains $n$ ($1 \le n \le 250\,000$), the number of islands. The following $n - 1$ lines describe the bridges. Each bridge connects two distinct islands. Finally, the last line contains $n$ non-negative integers, the distances (in number of bridges) shown on Luffy’s detector for each of the islands.</p>

<p>It is guaranteed that there is at least one <strong>non-empty</strong> subset that is consistent with the input data.</p>

### 출력 

 <p>Output a permutation of size $n$, the order of the islands from highest to lowest probability of containing a treasure. If two islands have the same probability of containing a treasure, output them in increasing order of their ids.</p>

