# [Diamond V] 문자 방정식 - 3409 

[문제 링크](https://acmicpc.net/problem/3409) 

### 성능 요약

메모리: 6080 KB, 시간: 300 ms

### 분류

깊이 우선 탐색, 다이나믹 프로그래밍, 그래프, 그래프 탐색, 파싱, 문자열, 트리

### 제출 일자

2023년 08월 17일 19:09:35

### 문제 설명

<p>You are given a text T and a pattern P. You want to check if you can erase some of the letters of T so that the remaining symbols produce exactly P. For example, the word programming can be partially erased to obtain pong or program or roaming (but not map, as the letters must remain in the same order). Both words consist of small letters of the English alphabet only</p>

<p>There is just one catch: the text T is encoded by a system of equations. The equations use special symbols (every symbol is denoted by a word in capital letters), each of them encoding some word over the alphabet {a, ..., z}. Each equation is of one of the following forms:</p>

<p>A = a word over {a, ..., z}<br>
or<br>
A = B + C</p>

<p>where A, B, C can be any special symbols, and the + sign denotes the concatenation of words. The system is:</p>

<ul>
	<li>unambiguous – for a ﬁxed symbol A, there is exactly one equation with A on the left-hand side, and</li>
	<li>acyclic – if you start from any symbol A and make substitutions according to the equations (right-hand side for left-hand side), you can never obtain an expression containing A again.</li>
</ul>

<p>Such a system always has a unique solution. For example, in the system:</p>

<ul>
	<li>START = FIRST + SECND</li>
	<li>FIRST = D + E</li>
	<li>SECND = F + E</li>
	<li>D = good</li>
	<li>E = times</li>
	<li>F = bad</li>
</ul>

<p>the symbol START encodes the word goodtimesbadtimes</p>

<p>Given a single word P as the pattern, a system of equations, and one particular starting symbol S of this system, determine whether the pattern P is present in the word encoded by S.</p>

### 입력 

 <p>The ﬁrst line of the input contains the number of test cases T. The descriptions of the test cases follow:</p>

<p>Each test case starts with a line containing a single integer k (1 ≤ k ≤ 500)—the number of equations. The next k lines contain equations. Each of them has one of the two forms given in the problem statement, with spaces separating words, plus signs, and equation signs. Each word (including symbol names) is at least one and at most ﬁve characters long.</p>

<p>The next line contains a single special symbol (a word in capital letters), while the ﬁnal line contains a non-empty word of at most 2 000 lowercase letters. These are the starting symbol and the pattern to ﬁnd, respectively.</p>

### 출력 

 <p>Print the answers to the test cases in the order in which they appear in the input. For each test case print the answer in a separate line: YES if the pattern appears in the given encoded word, and NO otherwise.</p>

