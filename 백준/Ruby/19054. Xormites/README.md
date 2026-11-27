# [Ruby IV] Xormites - 19054 

[문제 링크](https://acmicpc.net/problem/19054) 

### 성능 요약

메모리: 2336 KB, 시간: 92 ms

### 분류

게임 이론, 홀짝성

### 제출 일자

2023년 03월 08일 14:54:34

### 문제 설명

<p>Consider the following two-player game on a sequence of $N$ integers. The two players move in turns. In each move, the current player selects a value which is either at the beginning of the sequence or at the end of the sequence, adds it to this player's sum and removes the value from the sequence.</p>

<p>This is a well-known game. However, in this task, we will deal with the case in which the players add the values to a XOR sum, not a regular sum. Initially, the XOR sums of both players are equal to $0$, and when adding a new value, bitwise XOR operation is used in place of addition.</p>

<p>The game ends when the sequence is empty, at which point the player with the highest XOR sum wins. Note that it is also possible for the game to end in a draw. Figure out the outcome of the game, considering the players behave optimally.</p>

### 입력 

 <p>The first line contains an integer $T$, the number of test cases ($1 \le T \le 12$). Each test starts with a line containing an integer $N$ ($1 \le N \le 50\,000$), followed by another line containing a sequence of $N$ positive integers ($1 \le X \le 10^9$ for all integers $X$ in the sequence).</p>

### 출력 

 <p>Print $T$ lines, one per test case. The $i$-th line must contain the answer for the $i$-th test. The answer must be one of the following:</p>

<ul>
	<li>"<code>First</code>" if the first player to move wins.</li>
	<li>"<code>Second</code>" if the second player to move wins.</li>
	<li>"<code>Draw</code>" if the game ends in a draw.</li>
</ul>

