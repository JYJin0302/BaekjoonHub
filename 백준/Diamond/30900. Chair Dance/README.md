# [Diamond V] Chair Dance - 30900 

[문제 링크](https://acmicpc.net/problem/30900) 

### 성능 요약

메모리: 11884 KB, 시간: 192 ms

### 분류

애드 혹, 자료 구조, 분리 집합, 확장 유클리드 호제법, 수학, 정수론

### 제출 일자

2024년 04월 29일 21:43:53

### 문제 설명

<p>In a deterministic version of <em>Musical Chairs</em><sup>1</sup>, there are $n$ chairs placed in a circle. The chairs are numbered from $1$ to $n$ in clockwise order. Initially, the $i$th player sits on the $i$th chair. During the game, the game master gives commands to all players at once.</p>

<p>The first type of command tells each player to move $x$ chairs farther in clockwise order, so they must move from chair $i$ to chair $i+x$.</p>

<p>The second type of command tells each player to move from chair $i$ to chair $i\cdot{}x$. Both these calculations are done modulo $n$, where a remainder of $0$ corresponds to chair $n$.</p>

<p>If two or more people want to move to the same chair, then the player needing to travel the least in clockwise direction to reach the chair gets to take the seat, and the other players trying to reach the same chair are out of the game. This is illustrated in Figure C.1, where the larger circles represent the chairs and their numbers are written on their inside. The smaller circles represent the players. The next command (<code>* 10</code>) tells player $10$ (now on seat $11$) and player $4$ (now on seat $5$) to move to chair $2$. However, since player $10$ needs to travel less, this player gets to take the seat. Note that the other $10$ players will also move to some other chairs, but this is omitted from the figure for the sake of readability.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 279px; height: 300px;"></p>

<p style="text-align: center;">Figure C.1: Illustration of Sample Input 1 at the fourth command, where players $4$ and $10$ need to move to chair $2$. Because player $10$ needs to travel less in clockwise direction, this player gets to take the seat.</p>

<p>The jury wasted most of their free time designing this game and now need to go back to work. Fortunately, the game is deterministic, so you can play the game without the help of the jury.</p>

<hr>
<p><sup>1</sup>You do not need to know the original game, but you can try to play it after the contest is over.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers $n$ and $q$ ($2\leq n,q\leq5\cdot10^5$), the number of chairs and the number of commands.</li>
	<li>$q$ lines, each containing one of three command types:
	<ul>
		<li>"<code>+</code> $x$": The player on chair $i$ moves to chair $i+x$.</li>
		<li>"<code>*</code> $x$": The player on chair $i$ moves to chair $i\cdot{}x$.</li>
		<li>"<code>?</code> $x$": Tell us the number of the player on chair $x$.</li>
	</ul>
	</li>
	<li>All of the values $x$ will satisfy $1 \leq x \leq n$.</li>
</ul>

### 출력 

 <p>For each command of type '<code>?</code>', output the number of the player on the requested chair. If the chair is currently empty, output $-1$ instead.</p>

