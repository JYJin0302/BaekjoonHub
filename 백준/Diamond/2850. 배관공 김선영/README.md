# [Diamond I] 배관공 김선영 - 2850 

[문제 링크](https://acmicpc.net/problem/2850) 

### 성능 요약

메모리: 26888 KB, 시간: 284 ms

### 분류

많은 조건 분기, 커넥션 프로파일 DP, 다이나믹 프로그래밍

### 제출 일자

2024년 02월 27일 18:12:06

### 문제 설명

<p>Mirko, the mad plumber, was hired to construct a water supply network between two locations in a city. The city map can be represented as a R × S grid. Some cells are not suitable for placing water pipes. Locations Mirko needs to connect are placed directly above the top left cell of the grid, and directly below the bottom right cell.</p>

<p>Each suitable cell Mirko can either leave empty or use it for placing one of the following 6 pipe types: </p>

<p style="text-align: center;"><img alt="" src="" style="width: 321px; height: 46px;"></p>

<p>Find the number of ways that pipes can be placed to connect the two locations with a continuous pipe (water must not be spilled). All placed pipe parts must be in use.</p>

<p>Output the solution modulo 10007.</p>

### 입력 

 <p>The first line of input contains the integers R and S (2 ≤ R, S ≤ 10), the number of rows and columns of the city grid, respectively. Each of the next R lines contains exactly S characters: ‘.’ if the cell is suitable for placing pipes, and ‘#’ if not.</p>

### 출력 

 <p>The first and only line of output must contain the required number of ways modulo 10007.</p>

