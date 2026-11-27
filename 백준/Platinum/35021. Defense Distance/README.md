# [Platinum IV] Defense Distance - 35021 

[문제 링크](https://acmicpc.net/problem/35021) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

해 구성하기, 수학, 문자열

### 제출 일자

2026년 01월 04일 14:33:42

### 문제 설명

<p>The NWRRC security server has a final access check for teams that try to submit their solutions to the secret hidden problem.</p>

<p>To pass the check, the team must enter three passwords $s$, $t$, and $u$ that the system will accept. Each password must be a non-empty string consisting of at most $5000$ lowercase English letters.</p>

<p>The rules of the server are public:</p>

<ul>
<li>The distance between $s$ and $t$ should be equal to $a$.</li>
<li>The distance between $s$ and $u$ should be equal to $b$.</li>
<li>The distance between $t$ and $u$ should be equal to $c$.</li>
</ul>

<p>The <em>distance</em> between two strings $s_1$ and $s_2$ is the minimum number of single-character operations (insert one character, remove one character, or replace one character) needed to convert string $s_1$ into string $s_2$. This metric is also known as the Levenshtein distance.</p>

<p>The server gives access to the hidden problem if and only if all described conditions are satisfied. Your goal is to construct a triple of passwords to unlock the hidden problem or determine that it is impossible.</p>

### 입력 

 <p>The only line contains three integers $a$, $b$, and $c$, denoting the required distances between each pair of passwords ($0 \le a, b, c \le 1000$).</p>

### 출력 

 <p>If there are no three passwords with the required properties, print "<code>No</code>" in the only line.</p>

<p>Otherwise, print "<code>Yes</code>" in the first line. Then print passwords $s$, $t$, and $u$ in the following three lines. Each password should consist of at least $1$ and at most $5000$ lowercase English letters.</p>

<p>If there are multiple triples of passwords that meet the requirements, print any of them.</p>

