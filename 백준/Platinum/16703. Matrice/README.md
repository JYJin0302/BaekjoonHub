# [Platinum V] Matrice - 16703 

[문제 링크](https://acmicpc.net/problem/16703) 

### 성능 요약

메모리: 11072 KB, 시간: 36 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2023년 11월 03일 16:03:27

### 문제 설명

<p>Agent Sue Thomas and her son are looking for trinities in a grid. The word trinity is a neologism referring to a particular triangular (as the morpheme “tri” suggests) shape composed of cells in the grid.</p>

<p>Each trinity is a result of taking a square-shaped area of the cells and removing all cells that lie either above or below one of the two diagonals of the area. The diagonal may be either the main diagonal (southeast-northwest direction) or the main antidiagonal (southwest-northeast direction). A valid trinity consists of at least three grid cells and all its cells contain the same character.</p>

### 입력 

 <p>The first input line contains two numbers N and M (1 ≤ N, M ≤ 1000), describing the number of rows and columns in the grid, respectively. Each of next N lines contains M characters, whose ASCII codes are between 33 and 126, inclusively.</p>

### 출력 

 <p>Output the number of different valid trinities in the input grid.</p>

