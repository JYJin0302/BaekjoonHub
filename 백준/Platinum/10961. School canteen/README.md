# [Platinum III] School canteen - 10961 

[문제 링크](https://acmicpc.net/problem/10961) 

### 성능 요약

메모리: 2948 KB, 시간: 1384 ms

### 분류

분할 정복을 이용한 거듭제곱, 선형대수학, 수학

### 제출 일자

2022년 06월 08일 23:51:12

### 문제 설명

<p>Once upon a time, there was a school canteen. And the cooks were very busy there. They had to prepare a menu for all n days of the school year, but they had to admit that they are able to make only k different meals.</p>

<p>Alas, the students are known to be picky eaters. (Which is a well established Czech tradition.) If they get the same meal for ℓ days consecutively, they rebel against the cooks. (defenestration, which is another fine Czech tradition.)</p>

<p>Count the number of menus, which avoid student rebellion.</p>

### 입력 

 <p>On the standard input, you will find a single line containing three space-separated integers: n, ℓ, and k. Here n is the number of days (0 ≤ n ≤ 2,000,000,000), ℓ the impatience of the students (the number of repeats of a single meal, which causes the students to rebel, 2 ≤ ℓ ≤ 200), and k is the number of possible meals (1 ≤ k ≤ 100).</p>

<p> </p>

### 출력 

 <p>The standard output shall contain a single integer: the number of possible menus modulo 4,000,000,009.</p>

