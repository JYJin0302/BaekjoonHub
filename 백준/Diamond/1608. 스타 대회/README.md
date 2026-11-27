# [Diamond IV] 스타 대회 - 1608 

[문제 링크](https://acmicpc.net/problem/1608) 

### 성능 요약

메모리: 23648 KB, 시간: 192 ms

### 분류

방향 비순환 그래프, 그래프, 강한 연결 요소, 위상 정렬

### 제출 일자

2026년 02월 14일 15:45:25

### 문제 설명

<p>The International X-Game Federation organises a tournament in which programmes that play this game participate.  programmes numbered from  to  take part in the competition. The rules of the tournament are as follows: while there remains more than one programme in the tournament, two of them (distinct) are randomly chosen to play a game. The defeated one (there are no draws in the X-Game) drops out of the tournament and the whole procedure is repeated. The sole programme which stays in the tournament after all  games have been played is the winner.</p>

<p>The federation has a table of results of previous tournaments. It is known, that the programmes play deterministically (i.e. in repeatable fashion) and in exactly the same way as in previous tournaments. So, if two programmes have already played one against another then their next game will end with the same result. If, however, they have never played against each other, the outcome of the game cannot be predicted - both have a chance of winning. The federation would like to know a list of all programmes which have a chance of winning the tournament.</p>

<p>Write a programme which:</p>

<ul>
	<li>reads from the standard input the number of participating programmes and the table of results of their previous games,</li>
	<li>determines all programmes which have a chance of winning the tournament,</li>
	<li>writes the outcome to the standard output.</li>
</ul>

### 입력 

 <p>The first line of the input contains an integer n, 1 ≤ n ≤ 100 000. The next n lines contain the table of results of previous games: (i+1)st line contains an integer ki, 0 ≤ ki ≤ n, followed by ki numbers of programmes, not equal to i, in increasing order - those are the numbers of programmes, with which the programme i has previously won. The numbers in lines are separated by single spaces. The number of all known results of previous games does not exceed 1 000 000.</p>

### 출력 

 <p>The first and only line of the standard output should contain the number w of programmes which have a chance of winning the tournament, followed by w numbers identifying those programmes, in increasing order. The numbers should be separated by single spaces.</p>

<p> </p>

