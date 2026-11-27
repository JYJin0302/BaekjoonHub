# [Diamond IV] Saving the Jelly - 25292 

[문제 링크](https://acmicpc.net/problem/25292) 

### 성능 요약

메모리: 6568 KB, 시간: 7012 ms

### 분류

이분 매칭, 해 구성하기, 그래프

### 제출 일자

2023년 08월 09일 08:18:16

### 문제 설명

<p>Mr. Jolly teaches football (or soccer, for US speakers) to $\mathbf{N}$ children numbered from $1$ to $\mathbf{N}$. He has taken to leaving sweets on the field where the games take place, one for each child. After the game is finished, each child can grab and eat one sweet as their reward.</p>

<p>The children are tired after games, so each child wants to grab the sweet closest to them (using Euclidean distance). This could lead to fights — if the same sweet is closest to two or more children. To avoid that, after the game all the children stop where they are, and Mr. Jolly calls out their names, one by one. When a child's name is called, they grab the closest sweet to them (out of the ones that weren't already grabbed, of course). In the case where two or more sweets are tied for the smallest distance, Mr. Jolly can decide which one the child grabs.</p>

<p style="text-align: center;"><img alt="" src=""></p>

<p>This has worked very well for Mr. Jolly for a while now, but today disaster struck! While laying out the sweets, Mr. Jolly accidentally dropped his blueberry jelly that he planned to eat after all the children go home. So now there are $\mathbf{N}$ children on the field, and $\mathbf{N}+1$ sweets. The sweets are numbered from $1$ to $\mathbf{N} + 1$, with sweet $1$ being Mr. Jolly's blueberry jelly. Is there a way for Mr. Jolly to save his blueberry jelly by calling the children's names in such an order that the blueberry jelly is the one sweet left over?</p>

### 입력 

 <p>The first line of the input gives the number of test cases, $\mathbf{T}$. $\mathbf{T}$ test cases follow. Each test begins with a line containing a single integer, $\mathbf{N}$, the number of children on the field. The next $\mathbf{N}$ lines describe the positions of the children. Each of these lines contains two integers, $\mathbf{X_i}$ and $\mathbf{Y_i}$, representing the position of the $i$⁠-th child after the game ends. Then there are $\mathbf{N}+1$ more lines that describe the positions of sweets after the game, where the first of the sweets is Mr. Jolly's blueberry jelly. Each of these lines contains two integers, $\mathbf{X_j}$ and $\mathbf{Y_j}$, representing the position of the $j$⁠-th sweet.</p>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y</code>, where $x$ is the test case number (starting from 1) and $y$ is <code>IMPOSSIBLE</code> if there is no way Mr. Jolly can choose the children (and break ties for the closest sweet) to leave his blueberry jelly uneaten. Otherwise, if Mr. Jolly can save his blueberry jelly, $y$ is <code>POSSIBLE</code>. If Mr. Jolly can save his jelly, output $\mathbf{N}$ additional lines representing the order the children will go and which jellies they will pick. The $i$⁠-th line should contain two integers $A_i$ and $B_i$ representing that child $A_i$ will go next and will pick sweet $B_i$. The sweet $B_i$ must be the closest (or tied for the closest) sweet to child $A_i$ when they go to pick their sweet.</p>

