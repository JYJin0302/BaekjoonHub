# [Diamond IV] Last Guess - 26185 

[문제 링크](https://acmicpc.net/problem/26185) 

### 성능 요약

메모리: 3384 KB, 시간: 4 ms

### 분류

서큘레이션, 유량, 그래프

### 제출 일자

2026년 01월 20일 13:33:35

### 문제 설명

<p>If you spent any amount of time on social media at the end of last year, you are probably familiar with the word finding game <em>Wordle</em>, in which you need to find a five-letter English word using at most six guesses. After each guess, the letters in that guess are marked in either green, yellow or black to provide information about the hidden word:</p>

<ul>
	<li>Green indicates that the letter is in the hidden word and appears in the same position.</li>
	<li>Yellow indicates that the letter is in the hidden word, but in a different position.</li>
	<li>Black indicates that the letter has no more occurrences in the hidden word.</li>
	<li>If a letter appears more than once in the guessed word, first all the green markings for that letter are placed. Then, from left to right in the guessed word, yellow markings are placed for each remaining occurrence of the letter in the hidden word. Finally, black markings are placed for any surplus of the letter in the guessed word. See Figure L.1 for an example.</li>
</ul>

<p style="text-align: center;"><img alt="" src="" style="width: 200px; height: 152px;"></p>

<p style="text-align: center;">Figure L.1: Illustration of Sample Input 1, where "<code>upper</code>" is the only valid last guess.</p>

<p>In this problem, we consider a variant of Wordle where you need to find a hidden word of length $\ell$ in at most $g$ guesses. Additionally, there is <em>no</em> requirement that the hidden word or any of the guesses are words of any language; any string consisting of lowercase English letters is fine.</p>

<p>In your current play of this variant, you have already used all but one of your guesses, and now you need to find the hidden word using your final guess. Find any word that could be the hidden word based on the information you have.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers $g$ and $\ell$ ($2\le g\le 500$, $1\le \ell\le 500$), the maximal number of guesses allowed in the game and the length of the word.</li>
	<li>$g-1$ lines, each with two strings $s$ and $t$ of length $\ell$, where $s$ is one of the guesses so far and $t$ gives the colours for that guess according to the rules above. The string $s$ consists of lowercase English letters (<code>a</code>-<code>z</code>) and the string $t$ consists of uppercase letters '<code>G</code>', '<code>Y</code>', and '<code>B</code>' indicating green, yellow, and black respectively.</li>
</ul>

<p>It is guaranteed that the input describes a valid state of a Wordle game before the last guess and that a valid solution exists, in the form of a length $\ell$ word consisting of lowercase English letters.</p>

### 출력 

 <p>Output a valid last guess that gives you a chance of winning.</p>

<p>If there are multiple valid solutions, you may output any one of them.</p>

