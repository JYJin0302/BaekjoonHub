# [Platinum V] 승리 - 3032 

[문제 링크](https://acmicpc.net/problem/3032) 

### 성능 요약

메모리: 2060 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 게임 이론

### 제출 일자

2021년 12월 27일 22:17:12

### 문제 설명

<p>Even though she saw Zvonko steal Mirko's microprocessor in the second task, Mirko's sister Ivana did not tell Mirko because she likes Zvonko. She suggested to him that they go see a movie together so that she would "forget" about the incident. </p>

<p>Zvonko does not care much for girls because they take away precious time he usually spends practicing his math-fu. He suggested that the two of them play a game and, if Ivana wins, they will go see a movie together. Ivana agreed, being good at jump rope and she sometimes even kicks a football around with her two brothers. </p>

<p>Zvonko laid N positive integers in a circle on the floor and explained the rules: </p>

<ul>
	<li>The first player takes any number. </li>
	<li>The second player takes either of the two numbers adjacent to the one the first player took. </li>
	<li>The next player takes a number adjacent to any of the numbers taken so far, and so on until they run out of numbers. The player to take more odd numbers (not divisible by 2) wins. </li>
</ul>

<p>Zvonko plays optimally; he always looks for a strategy that leads to certain victory or a draw. Zvonko does not know how well Ivana plays. Being a true cavalier, he let Ivana have the first move. </p>

<p>But Ivana only cares about sitting next to Zvonko in front of the big screen so she seeks help playing. </p>

<p>Write a program that finds how many different first moves Ivana can make, so that she has a chance of winning afterwards.</p>

### 입력 

 <p>The first line of input contains an integer N (1 ≤ N ≤ 100), how many numbers there are in the circle.</p>

<p>The second line contains N integers separated by single spaces. All numbers will be between 1 and 1000 (inclusive). No two numbers will be the same. </p>

### 출력 

 <p>Output the desired number on a single line. </p>

<p> </p>

