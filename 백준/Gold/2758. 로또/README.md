# [Gold IV] 로또 - 2758 

[문제 링크](https://acmicpc.net/problem/2758) 

### 성능 요약

메모리: 2156 KB, 시간: 48 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2020년 08월 31일 18:30:59

### 문제 설명

<p>Lotto is a lottery, typically with an accumulating jackpot, in which participants play numbers of their choice in a random drawing. Lenny likes to play the lotto in Lincoln county Louisiana. In the game, he picks a list of nnumbers in the range from 1 to m. If his list matches the drawn list, he wins the big prize, a lifetime supply of large lemons. </p>

<p>Lenny has a scheme that he thinks is likely to be lucky. He likes to choose his list so that each number in it is at least twice as large as the one before it. So, for example, if n = 4 and m = 10, then the possible lucky lists Lenny could like are: </p>

<pre>1 2 4 8
1 2 4 9
1 2 4 10
1 2 5 10</pre>

<p>Thus Lenny has 4 lists to choose from. </p>

<p>Your job, given n and m, is to count how many lucky lists Lenny has to choose from. </p>

### 입력 

 <p>The first line of input is a single non-negative integer, which is the number of data sets to follow. All data sets should be handled identically. </p>

<p>The next lines, one per data set, contain two integers, n and m. You are guaranteed that 1 <= n <= 10 and 1 <= m <= 2000 and n <= m. </p>

### 출력 

 <p>For each data set, print a line like the following: </p>

<pre>Data set i: n m number</pre>

<p>where i is the data set number (beginning with 1), and numberis the maximum number of lucky lists corresponding to the provided values of n and m. </p>

