# [Diamond V] Unfair Game - 10632 

[문제 링크](https://acmicpc.net/problem/10632) 

### 성능 요약

메모리: 2412 KB, 시간: 12 ms

### 분류

많은 조건 분기, 게임 이론, 스프라그–그런디 정리

### 제출 일자

2023년 11월 02일 19:13:43

### 문제 설명

<p>Rabbit Hanako and Fox Jiro are great friends going to JAG primary school. Today they decided to play the following game during the lunch break.</p>

<p>This game is played by two players with \(N\) heaps of some number of stones. The players alternatively take their turn to play the game. Jiro is a kind gentleman, so he yielded the first turn to Hanako. In each turn, the player must take some stones, satisfying the following conditions:</p>

<ul>
	<li>
	<p>If the player is Hanako, she must take between \(1\) to \(A\) stones, inclusive, from a heap.</p>
	</li>
	<li>
	<p>If the player is Jiro, he must take between \(1\) to \(B\) stones, inclusive, from a heap.</p>
	</li>
</ul>

<p>The winner is the player who takes the last stone. Jiro thinks it is rude to go easy on her because he is a perfect gentleman. Therefore, he does him best. Of course, Hanako also does so.</p>

<p>Jiro is worried that he may lose the game. Being a cadet teacher working at JAG primary school as well as a professional competitive programmer, you should help him by programming. Your task is to write a program calculating the winner, assuming that they both play optimally.</p>

### 입력 

 <p>The first line contains three integers \(N\), \(A\), and \(B\). \(N\) (\(1 \leq N \leq 10^5\)) is the number of heaps. \(A\) and \(B\) (\(1 \leq A, B \leq 10^9\)) are the maximum numbers of stones that Hanako and Jiro can take in a turn, respectively. Then \(N\) lines follow, each of which contains a single integer \(S_i\) (\(1 \leq S_i \leq 10^9\)), representing the number of stones in the \(i\)-th heap at the beginning of the game.</p>

### 출력 

 <p>Output a line with "Hanako" if Hanako wins the game or "Jiro" in the other case.</p>

