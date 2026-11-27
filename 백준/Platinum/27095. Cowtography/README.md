# [Platinum V] Cowtography - 27095 

[문제 링크](https://acmicpc.net/problem/27095) 

### 성능 요약

메모리: 2172 KB, 시간: 4 ms

### 분류

임의 정밀도 및 큰 수 연산, 그래프, 그래프 탐색, 구현, 재귀

### 제출 일자

2023년 06월 21일 17:43:52

### 문제 설명

<p>Farmer John wants to draw a map of his land, which is divided into rectangular fields. Each field is colored with a number (an integer in [1..1,000,000]).  His goal is to design a map in which every adjacent pair of fields is colored differently.</p>

<p>Unfortunately, Farmer John's land is described in a rather unusual manner.  His entire farm is a square, 1 kilometer on a side.  The description of the layout of his farm is given by a sequence of lines, each of which contains one word or number per line.</p>

<p>The 1-by-1 kilometer square comprising the entire farm is described in the file as a series of one or more regions.  A region can be specified by either:</p>

<ul>
	<li>A number giving the color of the region under consideration</li>
	<li>The number "-1", indicating that the region under consideration is to be split evenly in half with a vertical line.  Following the "-1" command will be descriptions of the left and then right halves, each described as a region.</li>
	<li>The number "-2", indicating that the region under consideration is to be split evenly in half with a horizontal line.  Following the "-2" command will be a description of the upper and then lower halves, each described as a region.</li>
</ul>

<p>There are no more than 100 regions on Farmer John's property.</p>

<p>Your task is to determine the greatest number of adjacent regions colored with the same color.</p>

### 입력 

 <p>As above, a series of lines containing a number, the string 'hsplit', or the string 'vsplit'.</p>

### 출력 

 <p>A single line with an integer that tells the greatest number of adjacent fields have the same color.</p>

