# [Diamond V] Dictionary Game - 13893 

[문제 링크](https://acmicpc.net/problem/13893) 

### 성능 요약

메모리: 424008 KB, 시간: 568 ms

### 분류

자료 구조, 게임 이론, 하켄부시 게임, 스프라그–그런디 정리, 문자열, 트리, 트라이

### 제출 일자

2023년 11월 06일 16:23:20

### 문제 설명

<p>We all know the famous game scrabble, where we want to make words using tiles. We will play a game with words. But it is reverse of scrabble. Here instead of making words we want to destroy them. It is a two player game.</p>

<p>The game starts with a dictionary of words. At each move, the current player chooses a word of his choice (not necessarily from the dictionary). The constraints for choosing the word is, it must match the prefix of any (one or more) of the current dictionary words.</p>

<p>When a player chooses a word as its move, all the dictionary words that has a prefix equal to the chosen word, are split into two parts:</p>

<ol>
	<li>The matched part without the last character of the chosen word.</li>
	<li>The unmatched part starting from the last character of the chosen word.</li>
</ol>

<p>We remove all the unmatched part from the dictionary and keep only the matched part in the dictionary. The words that don't have matched prefix with the chosen word are kept intact in the dictionary. In this situation the next player makes its move in the same fashion. If the chosen word is of length 1, then all the dictionary words starting with that character will be removed.</p>

<p>For example, if we have a dictionary consisting the following words:</p>

<p>bangladesh<br>
bangalore<br>
band<br>
bandana</p>

<p>Now if the first player chooses the word “bang” then after the move the dictionary will become:<br>
ban<br>
ban<br>
band<br>
bandana</p>

<p>A player loses, when it cannot make a valid move. Given the dictionary of words, who will win if both players played optimally? To make it more interesting, can you find out who will win if you update the dictionary by adding new words?</p>

<p>Formally, you will be given few operations where you need to add a new word to the dictionary. After adding you need to calculate the winner between player 1 and 2 for the current dictionary. These added words are permanent. Means each of these added words will remain in the dictionary for that particular test case.</p>

### 입력 

 <p>First line consists of an integer T, which is the number of test cases (T ≤ 10).</p>

<p>Each case will start with an integer N (0 < N ≤ 50 000), the number of words in the dictionary.</p>

<p>Next N lines will contain dictionary words DW. Length of each DW will be less than or equal to 40.</p>

<p>Next line will contain an integer number Q, the number of operations (0 < Q ≤ 50 000).</p>

<p>Next Q lines will contain query words QW. Each QW is the word that you now want to add to the current dictionary. Let’s call these “Query words”. Length of each QW will be less than or equal to 40. All the dictionary words and query words will only consist of lower case letters.</p>

### 출력 

 <p>For each query word QW, you have to find out who will win, if you add QW to the current dictionary. First print the case number, then for each query print “1” or “2” based on whether player 1 or 2 will win.</p>

