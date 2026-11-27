# [Platinum IV] Wooden Signs - 11681 

[문제 링크](https://acmicpc.net/problem/11681) 

### 성능 요약

메모리: 2052 KB, 시간: 8 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2023년 05월 06일 21:20:35

### 문제 설명

<p>A carpenter has received an order for a wooden directional sign. Each board must be aligned vertically with the previous one, either to the basis of the previous arrowhead or to the opposite side, being fixed there with a specially designed screw. The two boards must overlap.</p>

<p>The carpenter wrote down a sequence of integers to encode the sketch sent by the designer but the sequence does not determine a unique model and he has thrown away the original sketch. What looked like a trivial task turned out a big jigsaw to him.</p>

<p style="text-align: center;"><img alt="" src="" style="height:143px; width:537px"></p>

<p>The sequence (with 1 + N elements) encodes the (N) arrows from the bottom to the top of the sign. The first element is the position of the left side of the bottom arrow. The remaining N elements define the positions where the arrowheads start, from bottom to top: the i-th element is the position where the i-th arrowhead basis is. For instance, the two signs depicted (on the left and on the right) could be encoded by 2 6 5 1 4.</p>

<p>Since a board must be aligned vertically with the previous one (either to the basis of the previous arrowhead or to the opposite side), if the sequence was 2 6 5 1 4 3, the fifth arrow could be fixed (in any of the depicted signs) with a screw either at 1 (pointing to the right) or at 4 (pointing to the left), with the arrowhead basis at 3.</p>

<p>If the sequence was 2 3 1, the second arrow could only be fixed with a screw at 3, pointing to the left, because consecutive boards must overlap.</p>

<p style="text-align: center;"><img alt="" src="" style="height:125px; width:206px"></p>

<p>All arrowheads are similar and the designer told the carpenter that their bases stand in different vertical lines, as well as the left side of the bottom arrow, altogether forming a permutation of 1..(N +1). That is why the carpenter overlooked the details and just wrote down the permutation (e.g., 2 6 5 1 4 3).</p>

<p>Given the sequence of numbers the carpenter wrote down, compute the number of directional arrows signs that can be crafted. Since the number can be very large, you must write it modulo 2<sup>31</sup> −1 = 2147483647. The second integer in the sequence is always greater than the first one (the bottom arrow points to the right always).</p>

### 입력 

 <p>The first line has one integer N and the second line contains a permutation of the integers from 1 to N + 1. Integers in the same line are separated by a single space.</p>

### 출력 

 <p>The output has a single line with the number (modulo 2<sup>31</sup> − 1 = 2147483647) of distinct signs that can be described by the given permutation.</p>

