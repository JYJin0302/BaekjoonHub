# [Gold V] 동전 - 3363 

[문제 링크](https://acmicpc.net/problem/3363) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

브루트포싱, 구현

### 제출 일자

2021년 09월 30일 22:13:30

### 문제 설명

<p>You have a balance scale and 12 coins (numbered 1, 2, …, 12), one of which is counterfeit. The counterfeit coin is either lighter or heavier than the other, “normal” coins. Three weighings are performed on the balance scale. Write a program coins, which attempts to identify the counterfeit coin and determines if it is heavier or lighter.</p>

### 입력 

 <p>The data for each weighing is given on a line of the standard input in the form:</p>

<p>A B C D x E F G H</p>

<p>where A, B, C, D, E, F, G and H are the numbers of eight different coins, and x is one of the characters <, > or =, with the following meaning:</p>

<ul>
	<li><: The total weight of coins A, B, C and D is less than the total weight of coins E, F, G и H.</li>
	<li>>: The total weight of coins A, B, C and D is greater than the total weight of coins E, F, G и H.</li>
	<li>=: The total weight of coins A, B, C and D is equal to the total weight of coins E, F, G и H.</li>
</ul>

### 출력 

 <p>The program writes to the standard output the number of the counterfeit coin and the character ‘+’, when it is heavier than the others, or the character ‘–‘, when it is lighter.</p>

<p>If the data of the three weighings is contradictory the program has to output “impossible”.</p>

<p>If the data is not contradictory but is insufficient for determining the number of the counterfeit coin, or if it is heavier or lighter the program has to output “indefinite”.</p>

