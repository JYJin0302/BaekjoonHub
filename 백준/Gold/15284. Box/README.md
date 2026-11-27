# [Gold IV] Box - 15284 

[문제 링크](https://acmicpc.net/problem/15284) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

브루트포싱, 많은 조건 분기, 기하학

### 제출 일자

2023년 09월 19일 15:31:58

### 문제 설명

<p>Bella is working in a factory that produces boxes. All boxes are in a shape of rectangular parallelepipeds. A net of the corresponding parallelepiped is cut out of a flat rectangular piece of cardboard of size w ×h. This net is a polygon with sides parallel to the sides of the rectangle of the cardboard. The net is bent along several lines and is connected along the edges of the resulting parallelepiped to form a box. The net is bent only along the edges of the resulting box.</p>

<table class="table" style="width:100%">
	<tbody>
		<tr>
			<td style="text-align:center; width:50%"><img alt="" src="" style="height:122px; width:141px"></td>
			<td style="text-align:center; width:50%"><img alt="" src="" style="height:63px; width:272px"></td>
		</tr>
		<tr>
			<td style="text-align:center; width:50%">The first example</td>
			<td style="text-align:center; width:50%">The third example</td>
		</tr>
	</tbody>
</table>

<p>Bella is a software developer and her task is to check whether it is possible to make a box of size a×b×c out of a cardboard of size w × h. Bella did write a program and boxes are being produced. Can you do the same?</p>

### 입력 

 <p>The first line contains three integers a, b, and c — the dimensions of the box.</p>

<p>The second line contains two integers w and h — the width and the height of the cardboard.</p>

<p>All integers are positive and do not exceed 10<sup>8</sup>.</p>

### 출력 

 <p>Print “Yes” if it is possible to cut a box a × b × c out of a cardboard of size w × h. Print “No” otherwise.</p>

