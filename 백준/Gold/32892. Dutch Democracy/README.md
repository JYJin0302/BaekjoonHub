# [Gold II] Dutch Democracy - 32892 

[문제 링크](https://acmicpc.net/problem/32892) 

### 성능 요약

메모리: 6836 KB, 시간: 44 ms

### 분류

배낭 문제, 정렬

### 제출 일자

2025년 01월 12일 18:09:22

### 문제 설명

<p>The process of forming the Dutch government has taken more than half a year for three elections in a row. Perhaps we can streamline the initial stages of coalition building?</p>

<p>The first step after the election results is to find a group of parties (called a <em>coalition</em>) with enough seats to have a strict majority. Your task is to count the number of candidate coalitions that satisfy specific conditions. A coalition is considered a <em>candidate coalition</em> if it meets these two criteria:</p>

<p><strong>Strict Majority:</strong> The total number of seats held by the coalition must be strictly more than half of the total seats across all parties.</p>

<p><strong>No Superfluous Parties:</strong> The coalition must be minimal in the sense that removing any one party from the coalition would cause it to lose its strict majority.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 389px; height: 200px;"></p>

<p style="text-align: center;">Figure D.1: Illustration of Sample Input 2.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer $n$ ($1 \le n \le 60$), the number of parties.</li>
	<li>One line with $n$ integers $p$ ($1 \le p \le 10\,000$), the number of seats each party has.</li>
</ul>

### 출력 

 <p> Output the total number of candidate coalitions that satisfy the criteria above.</p>

