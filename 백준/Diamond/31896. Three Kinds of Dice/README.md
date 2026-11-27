# [Diamond V] Three Kinds of Dice - 31896 

[문제 링크](https://acmicpc.net/problem/31896) 

### 성능 요약

메모리: 13964 KB, 시간: 120 ms

### 분류

기하학, 볼록 껍질, 선형 계획법, 수학, 확률론

### 제출 일자

2024년 09월 22일 00:58:18

### 문제 설명

<p>See how they roll! According to a famous story, Warren Buffett once challenged Bill Gates to a simple game of dice. He had three dice; the first player could examine them and choose one of the three. The second player would then choose one of the remaining dice, and both players would roll their dice against each other, aiming for the highest numbers. Warren offered to let Bill go first, but this made Bill suspicious so he opted to go second. It turned out to be a wise choice: these were <em>intransitive dice</em>. The first die had an advantage when rolling against the second, the second had an advantage when rolling against the third, but the first did not have an advantage when rolling against the third!</p>

<p>To formalize this: define a “die” as any shape with at least one face such that each face shows a positive integer. When a die is rolled, one of its faces is selected uniformly at random. When two dice roll against each other, the die whose selected face shows a higher number earns $1$ point; if both numbers are equal, each die earns $\frac{1}{2}$ points. For dice $D$ and $D'$ , define $score(D, D' )$ as the expected number of points $D$ earns from a single roll against $D'$. If $score(D, D') > \frac{1}{2}$, we say that $D$ has an advantage over $D'$; if $score(D, D') = \frac{1}{2}$, the two dice are tied. For example, if $D$ is the first die in the sample input and $D'$ is the second, $score(D, D') = \frac{4}{9}$ and $score(D' , D) = \frac{5}{9}$, so $D'$ has an advantage over $D$.</p>

<p>Given two dice $D_1$ and $D_2$ such that $D_1$ has an advantage over $D_2$, you want a third die $D_3$ that forms an intransitive trio with the other two. Among all $D_3$ that have an advantage over or tie with $D_1$, compute the lowest possible $score(D_3, D_2)$. If this is less than $\frac{1}{2}$, you can make an intransitive trio! Similarly, among all $D_3$ such that $D_2$ has an advantage over or ties with $D_3$, compute the highest possible $score(D_3, D_1)$.</p>

### 입력 

 <p>The input contains two lines, each describing one die. One of the dice (the first or the second) has an advantage over the other. The die with the advantage is $D_1$ and the other is $D_2$.</p>

<p>The first integer on a line gives $n$ ($1 ≤ n ≤ 10^5$), the number of faces on the die. Then follow $n$ integers $f_i$ ($1 ≤ f_i ≤ 10^9$ for each $1 ≤ i ≤ n$), giving the integer on each face.</p>

### 출력 

 <p>Output one line containing the lowest $score(D_3, D_2)$ and the highest $score(D_3, D_1)$ under the above conditions. The two scores do not need to use the same die $D_3$. Your answer should have an absolute error of at most $10^{-6}$.</p>

