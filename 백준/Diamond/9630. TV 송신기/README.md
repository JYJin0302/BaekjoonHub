# [Diamond I] TV 송신기 - 9630 

[문제 링크](https://acmicpc.net/problem/9630) 

### 성능 요약

메모리: 50168 KB, 시간: 204 ms

### 분류

애드 혹, 자료 구조, 기하학, 스택

### 제출 일자

2025년 02월 06일 22:11:45

### 문제 설명

<p>The mayor has decided that it is high time to implement a new system of television transmitters. The city can be represented as a segment of the length D on which there are buildings of different heights. The width of a building is negligible. On top of some buildings, television transmitters are set, their dimensions are also negligible. </p>

<p>Television transmitters emit a television signal in all directions around them. The signal is spread through space in straight lines and cannot pass through buildings. A certain point in the city is considered covered if it is reached by a signal from an existing transmitter. </p>

<p><img alt="" src="" style="height:338px; width:654px"></p>

<p>Find the segment of the city covered by television signal and output its length. </p>

### 입력 

 <p>The first line of input contains the integer N (1 ≤ N ≤ 3·10<sup>5</sup>), the number of buildings, and the integer D (1 ≤ D ≤ 10<sup>9</sup>), the city length. </p>

<p>Each of the following N lines contains three numbers which describe the i<sup>th</sup> building: </p>

<ol>
	<li>a number which determines whether there is a transmitter on top of the building: 0 (no) or 1 (yes) </li>
	<li>an integer X<sub>i</sub> (0 ≤ X<sub>i</sub> ≤ D), the distance between the building and the left end of the city </li>
	<li>an integer H<sub>i</sub> (1 ≤ H<sub>i</sub> ≤ 10<sup>9</sup>), the building height </li>
</ol>

<p>The buildings are sorted in ascending order by the distance from the left end of the city. No two buildings will be located on the same distance from the left end of the city. </p>

### 출력 

 <p>The first and only line of output must contain the required length from the text. </p>

<p>Note: the maximum permissible deviation from the official solution is 10<sup>-3</sup>. </p>

