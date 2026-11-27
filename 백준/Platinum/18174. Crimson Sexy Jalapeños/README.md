# [Platinum III] Crimson Sexy Jalapeños - 18174 

[문제 링크](https://acmicpc.net/problem/18174) 

### 성능 요약

메모리: 13812 KB, 시간: 2824 ms

### 분류

게임 이론, 스프라그–그런디 정리

### 제출 일자

2023년 10월 29일 13:41:31

### 문제 설명

<p>The central piece of the Tainted chocolate game is a classic chocolate bar divided into square pieces by a rectangular grid of grooves parallel to the sides of the bar. Some squares have been tainted with extremely bitter substance that makes the tainted square (nearly) indigestible.</p>

<p>The game is played by two players who alternate in their moves. In a valid move, one player is obliged to consume some part of the chocolate bar. It is allowed to divide the current chocolate bar along one of the grooves into two smaller bars and then eat just one of them. The player who consumes a bar containing at least one tainted square loses the game.</p>

<p>The positions of all tainted squares are known at the beginning of the game. All other squares are safe to eat. Each player tries to avoid eating a bar of chocolate containing one or more tainted squares, because when this happens, the player involuntarily makes their personal most disgusted grimace becoming a source of great amusement not only to the other player but also to other people watching the game.</p>

<p>In this problem, you are to write a program to play the Tainted chocolate game. We neglect the part of the code which simulates players grimaces and chocolate consumption, and instead focus only on the winning moves.</p>

<p>A valid move is described by a directional string and a positive integer X. The directional string is one of the four strings “top”, “bottom”, “left”, or “right”. The description means that the bar is divided by the X-th groove, counted from that side of the currently remaining bar which is specified by the given directional string. The player then consumes the part on that side.</p>

### 입력 

 <p>The first line of input contains integers R, C, K (1 ≤ R, C ≤ 10<sup>4</sup>; 1 ≤ K ≤ 100). R is the number of rows, C is the number of columns, and K is the number of tainted squares in the chocolate bar. Each of the next K lines contains two integer values A and B (1 ≤ A ≤ R, 1 ≤ B ≤ C), the coordinates of one tainted square. The coordinates of the top-left corner square are (1, 1).</p>

<p>The rest of the input depends on your output. For each of your valid moves, there will appear one input line containing either an opponent’s valid move description or the string “yuck!” which indicates the opponent lost the game. In the latter case your program should terminate.</p>

### 출력 

 <p>After reading the chocolate bar description, you may decide whether you want to start the game. If you want to play second, print one line containing the string “pass”. This special string may only appear on the very first line of your output.</p>

<p>Then, for each of your moves, print one line containing a description of a valid move. Your program will be given a Wrong Answer if it produces anything else than a sequence of valid moves leading to the victory.</p>

<p>After printing each move description, flush the output buffer. For example, you may use fflush(stdout) or cout.flush() in C++, System.out.flush() in Java, or stdout.flush() in Python.</p>

