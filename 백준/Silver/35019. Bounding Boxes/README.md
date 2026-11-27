# [Silver V] Bounding Boxes - 35019 

[문제 링크](https://acmicpc.net/problem/35019) 

### 성능 요약

메모리: 2180 KB, 시간: 0 ms

### 분류

사칙연산, 구현, 수학, 정렬

### 제출 일자

2026년 01월 04일 14:32:43

### 문제 설명

<p>ICPC is considering sending out contest souvenirs via a delivery service. The delivery service provides multiple types of packing boxes, each shaped as a rectangular parallelepiped.</p>

<p>Unfortunately, there is no way to know which packing box type will be available on the shipping day, so ICPC needs to choose a souvenir box size that fits inside every packing box.</p>

<p>According to the shipment rules, the souvenir box must also be a rectangular parallelepiped. When placed inside a packing box, the souvenir box may be rotated, but its sides must remain parallel to the sides of the packing box. Extra space is not an issue, as it will be filled with plastic wrap.</p>

<p>Help ICPC determine the maximum possible volume of a souvenir box that fits inside all of the packing boxes.</p>

### 입력 

 <p>The first line contains a single integer $n$, denoting the number of packing box types provided by the delivery service ($1 \le n \le 1000$).</p>

<p>The $i$-th of the following $n$ lines contains three integers $w_i$, $h_i$, and $d_i$, denoting the width, height, and depth of the $i$-th packing box ($1 \le w_i, h_i, d_i \le 1000$).</p>

### 출력 

 <p>Print the largest possible volume of a souvenir box that fits inside all of the packing boxes. Remember that the souvenir box can be rotated, as long as its sides remain parallel to the sides of the packing box.</p>

