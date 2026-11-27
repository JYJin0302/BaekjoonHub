# [Gold I] Fixing Fractions - 30903 

[문제 링크](https://acmicpc.net/problem/30903) 

### 성능 요약

메모리: 2024 KB, 시간: 64 ms

### 분류

비트마스킹, 브루트포싱, 수학, 정수론

### 제출 일자

2024년 04월 28일 14:19:54

### 문제 설명

<p>Maths is hard.<sup>[citation needed]</sup> But it could be easier! And the internet™ has found some excellent ways to make it easier. Take a look at the following true equations:</p>

<p style="text-align: center;"><img alt="" src="" style="width: 256px; height: 55px;"></p>

<p>Following the patterns, we come to the conclusion that the following equation should also be true:\vspace{-0.75\baselineskip}</p>

<p style="text-align: center;"><img alt="" src="" style="width: 64px; height: 31px;"></p>

<p>However, this is actually wrong in boring old standard maths. Therefore, we define a new kind of funky maths where it is allowed to cancel out digits on the left side of the equality sign. This surely will make everyone's life easier. Except yours, since you have to evaluate if two given fractions are equal in our new funky maths.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with four integers $a$, $b$, $c$, and $d$ ($1\leq a,b,c,d<10^{18}$), describing the two fractions $\frac{a}{b}$ and $\frac{c}{d}$.</li>
</ul>

### 출력 

 <p>If there exist integers $a'$ and $b'$ obtained from $a$ and $b$ by cancelling out the same digits and with $\frac{a'}{b'} = \frac{c}{d}$ in standard mathematics, output "<code>possible</code>", followed by $a'$ and $b'$. Otherwise, output "<code>impossible</code>".</p>

<p>If there are multiple valid solutions, you may output any one of them.</p>

<p>Note that neither $a'$ nor $b'$ is allowed to contain leading zeroes after cancelling digits.</p>

