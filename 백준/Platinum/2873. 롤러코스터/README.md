# [Platinum III] 롤러코스터 - 2873 

[문제 링크](https://acmicpc.net/problem/2873) 

### 성능 요약

메모리: 5928 KB, 시간: 100 ms

### 분류

해 구성하기, 그리디, 구현, 홀짝성

### 제출 일자

2020년 12월 23일 17:41:32

### 문제 설명

<p>Mirko has grown tired of all the books, so he decided to go to the amusement park with his friends, despite not liking roller coasters. While his friends are having the time of their lives riding the coasters, Mirko is sitting on a bench, waiting and thinking about the possible paths of the coasters. </p>

<p>The amusement park’s area can be represented as a table of R rows by C columns. A roller coaster has to start from the upper left corner and end at the lower right corner of the table. Each cell can be visited at most once, but not all cells need to be visited. It can continue its path from the current cell to the adjacent one above, below, to the left, or to the right of it. </p>

<p>Each cell has a positive integer value associated with it, specifying how amusing that cell is to visitors. The total amusement value of the coaster is the sum of amusement values of all cells that the coaster visits. Help Mirko determine any one of the most amusing coasters (ones with the maximum sum). </p>

### 입력 

 <p>The first line of input contains two integers R and C (2 ≤ R, C ≤ 1000), the dimensions of the table. </p>

<p>Each of the next R lines contains C positive integers smaller than 1000, specifying the amusement values of the respective table cells.</p>

### 출력 

 <p>The first and only line of output must contain a sequence of letters with no blanks. The letters specify the sequence of directions that the coaster follows, starting from the upper left and ending at the lower right corner. The directions up, right, down, left are marked by letters ‘U’, ‘R’, ‘D’, ‘L’, respectively. </p>

<p>Note: The solution isn’t guaranteed to be unique. </p>

