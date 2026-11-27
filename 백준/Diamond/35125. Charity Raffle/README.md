# [Diamond IV] Charity Raffle - 35125 

[문제 링크](https://acmicpc.net/problem/35125) 

### 성능 요약

메모리: 17652 KB, 시간: 732 ms

### 분류

조합론, 포함 배제의 원리, 수학

### 제출 일자

2026년 02월 03일 15:42:06

### 문제 설명

<p>You are joining a charity raffle in which several types of prizes can be won. The raffle is held in a somewhat unusual way: with one draw using a single draw ticket, two prizes of different types are randomly picked up. However, you don’t win both of them; you should choose one out of the two.</p>

<p>You have a certain number of draw tickets. You will use all of them and win the same number of prizes. As you don’t want too many prizes of the same type, when choosing out of the two prizes, you choose the one that you have won fewer so far. You may have won the same number of the two prize types, including cases where both are zero. The prize types are sequentially numbered, and you choose the one with the lower type number in that case.</p>

<p>Despite the above strategy, it is not certain that you can avoid winning too many prizes of the same type. You feel <em>unhappy</em> if there is a prize type for which the number of prizes you win exceeds a certain limit. You want to know how many possible combinations of prizes you may get that do <em>not</em> make you unhappy after using up all of your draw tickets. Two combinations of prizes are considered different when they differ in the count of at least one type of prize. You may assume that there is an unlimited supply of any type of prize.</p>

### 입력 

 <p>The input consists of a single test case of the following format.</p>

<blockquote>
<p>$n$ $k$ $m$</p>
</blockquote>

<p>The first integer $n$ ($2 ≤ n ≤ 10^6$) is the number of different types of prizes. The second integer $k$ ($1 ≤ k ≤ 10^6$) is the number of draw tickets you have. The third integer $m$ ($1 ≤ m ≤ k$) is the maximum number of prizes of a single type that does not make you unhappy.</p>

### 출력 

 <p>Output the number of possible combinations of prizes that do not make you unhappy, modulo $998\, 244\, 353$, which is a prime number.</p>

