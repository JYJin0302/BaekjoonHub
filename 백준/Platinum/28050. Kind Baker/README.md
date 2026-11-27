# [Platinum III] Kind Baker - 28050 

[문제 링크](https://acmicpc.net/problem/28050) 

### 성능 요약

메모리: 3240 KB, 시간: 8 ms

### 분류

애드 혹, 비트마스킹, 해 구성하기

### 제출 일자

2023년 06월 25일 22:51:12

### 문제 설명

<p>Flora loves baking cakes, and for her company’s $K$-th birthday she promised to bring a special treat: a cake, with $K$ different combinations of toppings to choose from! Unfortunately, she doesn’t have much time, so she needs to simplify things a bit.</p>

<p>A cake can be described as a $100 \times 100$ grid of square cake pieces. A collection of pieces is connected if, for every pair of pieces in the collection, they are connected directly (they share a side) or indirectly (there is a sequence of pieces such that you can go from one piece to the other through directly connected pieces). The figure below depicts two collections of pieces (only a relevant part of the grid is shown). One collection is connected, while the other one is not.</p>

<table class="table table-bordered td-center">
	<tbody>
		<tr>
			<td><img alt="" src="" style="width: 137px; height: 141px;"></td>
			<td><img alt="" src="" style="width: 137px; height: 141px;"></td>
		</tr>
		<tr>
			<td>(a) Connected</td>
			<td>(b) Not connected</td>
		</tr>
	</tbody>
</table>

<p>Flora has a machine that accepts a connected collection of cake pieces and puts a certain topping on each of those pieces. A different topping is applied each time the machine runs. After using the machine a given number of times, each piece will have a (possibly empty) combination of toppings on it. Two pieces are considered to be of different types if they have a different combination of toppings. Flora wants to know the minimum number of times she has to use the machine to achieve exactly $K$ different types of cake pieces, and a possible way to choose a connected collection of cake pieces for each time she will use the machine.</p>

### 입력 

 <p>The input consists of a single line that contains an integer $K$ ($1 ≤ K ≤ 4000$) indicating the number of different types of pieces that the cake must have.</p>

### 출력 

 <p>The first line must contain an integer $T$ indicating the minimum number of times that Flora has to use the machine. Each of the next T lines describes a connected collection of cake pieces to drive into the machine the successive times that Flora will use it; the line must contain a positive integer $N$ followed by $N$ different pairs of integers $X_1, Y_1, X_2, Y_2, \dots , X_N , Y_N$ ($1 ≤ X_i , Y_i ≤ 100$ for $i = 1, 2, \dots , N$), indicating that the collection consists of the pieces with coordinates $(X_1, Y_1),(X_2, Y_2), \dots ,(X_N , Y_N )$. It is guaranteed that there exists at least one solution. The coordinates $(1, 1)$ identify the square piece in any corner of the cake.</p>

