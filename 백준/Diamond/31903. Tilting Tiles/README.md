# [Diamond III] Tilting Tiles - 31903 

[문제 링크](https://acmicpc.net/problem/31903) 

### 성능 요약

메모리: 14944 KB, 시간: 1192 ms

### 분류

중국인의 나머지 정리, 순열 사이클 분할, 구현, KMP, 수학, 정수론, 문자열, Z

### 제출 일자

2024년 09월 19일 13:00:49

### 문제 설명

<p>You found a weird puzzle in a box with old toys in your attic. The puzzle forms a rectangular grid board made of $h \times w$ square cells. Some cells in that grid have a colored tile placed on them, as shown in Figure 1.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 200px; height: 200px;"></p>

<p style="text-align: center;"><b>Figure 1</b>: Color tiles correspond to the starting arrangement in Sample Input 1.</p>

<p>You are not yet sure what the exact goal of this puzzle is, but you started examining possible ways of rearranging the tiles. Their arrangement can be manipulated by tilting the grid in one of the four cardinal directions: to your left, to your right, towards you, or away from you. Tilting causes all the tiles to slide in the respective direction until they are blocked either by the boundary or by another tile. Given a starting and ending arrangement, determine whether there exists some sequence of tilts that transforms the former into the latter. Figure 2 illustrates tilting of the puzzle shown in Sample Input 1.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 846px; height: 150px;"></p>

<p style="text-align: center;"><b>Figure 2</b>: Solution to Sample Input 1.</p>

### 입력 

 <p>The first line of input contains two integers $h$ and $w$ ($1≤h,w≤500$) representing the height and width of the grid. Then follow $h$ lines giving the starting arrangement from the top row to the bottom row. Each of these lines contains a string of length $w$ describing cells on the row from left to right. If a cell is empty, the corresponding character is a dot (<code>.</code>). If there is a tile, the color of that tile is given, denoted by a lowercase letter (<code>a</code>-<code>z</code>). Different letters represent different colors, and tiles of the same color cannot be distinguished.</p>

<p>After the starting arrangement, there is one empty line and then follows a description of the ending arrangement, consisting of $h$ lines in the same format as for the starting arrangement.</p>

### 출력 

 <p>Output <code>yes</code> if a sequence of tilts exists that transforms the starting arrangement to the ending arrangement, and <code>no</code> otherwise.</p>

