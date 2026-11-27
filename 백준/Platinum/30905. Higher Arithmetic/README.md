# [Platinum III] Higher Arithmetic - 30905 

[문제 링크](https://acmicpc.net/problem/30905) 

### 성능 요약

메모리: 2920 KB, 시간: 24 ms

### 분류

애드 혹, 많은 조건 분기, 해 구성하기, 구현, 수학

### 제출 일자

2024년 04월 28일 18:30:40

### 문제 설명

<p><img alt="" src="" style="width: 247px; height: 358px; float: right; margin-left:10px;">Captchas are getting more and more elaborate. It started with doing simple calculations like $7 + 2$, and now, it has evolved into having to distinguish chihuahuas from double chocolate chip muffins.</p>

<p>To combat the rise of smarter bots, the Internet Captcha Production Company (ICPC) has outdone itself this time: given a distorted image containing many integers, find the maximum value that can be expressed using each of the given integers exactly once, using addition, multiplication, and arbitrary parentheses.</p>

<p>After unsuccessfully trying to solve such a captcha for an hour straight, Katrijn is terribly frustrated. She decides to write a program that outputs a valid arithmetic expression with maximal value.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer $n$ ($1 \le n \le 10^5$), the number of integers in the captcha.</li>
	<li>One line with $n$ integers $a$ ($1 \le a \le 10^6$), the integers in the captcha.</li>
</ul>

### 출력 

 <p>Output a valid arithmetic expression with maximal value, where each integer from the input list is used exactly once. The usual order of operations applies. The output expression may use at most $10^6$ characters and must not contain any spaces. Such an expression exists for any possible input.</p>

<p>If there are multiple valid solutions, you may output any one of them.</p>

