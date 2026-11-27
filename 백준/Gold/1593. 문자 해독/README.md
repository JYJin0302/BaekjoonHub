# [Gold V] 문자 해독 - 1593 

[문제 링크](https://acmicpc.net/problem/1593) 

### 성능 요약

메모리: 7544 KB, 시간: 32 ms

### 분류

문자열, 슬라이딩 윈도우

### 제출 일자

2024년 02월 15일 12:46:09

### 문제 설명

<p>Deciphering the Mayan writing has proven to be a harder task than anticipated by the early investigations. After almost two hundred years, very little of it was actually understood. It has been only in the last three decades that real advances have been made. </p>

<p>Mayan writing is based on small drawings known as glyphs which represent sounds. Mayan words are normally written as glyphs put together at various positions. </p>

<p>One of several problems in deciphering Mayan writing arises in the order of reading. When placing several glyphs in order to form a word, Mayan writers sometimes decided the position based more on their own esthetic views than on any particular rule. This leads to the fact that, even though the sound for many glyphs is known, sometimes archaeologists are not sure how to pronounce a written word. </p>

<p>The archaeologists are looking for a special word W. They know the glyphs for it, but they don’t know all the possible ways of arranging them. Since they knew you were coming to IOI’06, they have asked for your help. They will provide you with the g glyphs from W and a sequence S of all the glyphs (in the order they appear) in the carvings they are studying. Help them by counting the number of possible appearances of the word W. </p>

<p>Write a program that, given the glyphs for W and the sequence S of glyphs in the carvings, counts the number of possible appearances of W in S; that is, every sequence of consecutive g glyphs in S that is a permutation of the glyphs in W. </p>

### 입력 

 <ul>
	<li>LINE 1: Contains 2 space-separated integers that represent g and |S|.</li>
	<li>LINE 2: Contains g consecutive characters that represent the glyphs in W. Valid characters are ‘a’-‘z’ and ‘A’-‘Z’; uppercase and lowercase characters are considered different. </li>
	<li>LINE 3: Contains |S| consecutive characters that represent the glyphs in the carvings. Valid characters are ‘a’-‘z’ and ‘A’-‘Z’; uppercase and lowercase characters are considered different. </li>
</ul>

### 출력 

 <ul>
	<li>LINE 1: Must contain the count of possible appearances of W in S. </li>
</ul>

