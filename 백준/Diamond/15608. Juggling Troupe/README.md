# [Diamond III] Juggling Troupe - 15608 

[문제 링크](https://acmicpc.net/problem/15608) 

### 성능 요약

메모리: 26536 KB, 시간: 272 ms

### 분류

애드 혹

### 제출 일자

2023년 11월 23일 13:23:43

### 문제 설명

<p>At the national centre for computing and advanced circus skills, technical demonstrations by students are strongly encouraged.</p>

<p>A troupe of n novice performers are at this very moment arrayed in a row attempting to put on a juggling show. Unfortunately, none of them are very confident in their craft, and they are struggling. Thus, as soon as an opportunity presents itself, they will try to reduce their part in the performance to make the task easier.</p>

<p>Whenever a juggler has more than one ball in their possession, they will throw one ball to each of their neighbours. In the case that a juggler does not have a neighbour in some direction, they will simply throw the ball offstage instead. Everybody throws their juggling balls simultaneously. The show ends when no juggler has more than one ball.</p>

<p>See Figure J.1 below for an illustration of this process.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 538px; height: 153px;"></p>

<p style="text-align: center;">Figure J.1: Illustration of Sample Input 1. A performance with n = 8 jugglers.</p>

<p>As a member of the audience, you are not impressed by this performance. However, you do wonder how many balls each of the jugglers will have left at the end of the show.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with a string s of length n (1 ≤ n ≤ 10<sup>6</sup>) over the characters 0, 1 and 2. The ith character in s represents the number of juggling balls initially held by the ith person.</li>
</ul>

### 출력 

 <p>Output a string s of length n over the characters 0 and 1, the ith giving the number of juggling balls the ith person has at the end of the show.</p>

