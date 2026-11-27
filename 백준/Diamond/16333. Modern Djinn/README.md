# [Diamond V] Modern Djinn - 16333 

[문제 링크](https://acmicpc.net/problem/16333) 

### 성능 요약

메모리: 2792 KB, 시간: 44 ms

### 분류

무작위화

### 제출 일자

2023년 11월 16일 14:10:13

### 문제 설명

<p>You are certainly no leader, but a president. Lucky for you, you own a modern djinn, a spiritual creature that makes your wishes come true. One such wish is to pretend to have democracy in your society.</p>

<p>Society is simple. It consists of N people numbered from 1 to N, some of which are “happy”, and some are regular (“unhappy”). Human nature is very tricky. People are happy only when others aren’t. You have M wishes, numbered from 1 to M, X → Y denoting that person X wants person Y to be unhappy. A person X is happy if and only if at least one of his wishes is satisfied. Democracy is also not that complex. Some may say that you need to have at least half of the people happy (or half of the wishes solved) in order to have democracy, but that it is not true at all. As I said earlier, you are a good president, not a good leader. You have access to media so you define democracy. Therefore, out of all M wishes, you decided to make at least ⌊M/4⌋ + 1 wishes come true.</p>

<p>All that is left is to decide which wishes you want to grant, the djinn will handle the rest.</p>

### 입력 

 <p>The input will contain multiple test cases. The first number T, will represent the number of test cases. The next lines will describe the test cases in order.</p>

<p>The first line of a test case contains 2 positive integers N and M, the number of people and the number of wishes. Next M lines of a test case contain pairs of 2 integers X Y separated by a space denoting a wish of the form: X wants Y to be unhappy.</p>

### 출력 

 <p>For each test case on the first line output a number K, representing the number of wishes that were granted. On the second line output K distinct integers separated by spaces representing the indices of the wishes that were granted. These can be printed in any order.</p>

