# [Platinum II] 등고선 지도 - 8889 

[문제 링크](https://acmicpc.net/problem/8889) 

### 성능 요약

메모리: 17648 KB, 시간: 736 ms

### 분류

차분 배열 트릭, 자료 구조, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리, 스위핑, 값 및 좌표 압축

### 제출 일자

2023년 07월 12일 15:07:38

### 문제 설명

<p>Hallyeohaesang national park is located in the south of the Korean Peninsula. Hallyeohaesang is a unique marine ecosystem which extends along 120km. The park is studded with more than 360 islands, large and small. Specially, Hallyeosudo which is known as the most beautiful waterway ever has 69 uninhabited islands and 30 inhabited islands spread out across the sea like jewels. </p>

<p>Mr. Kim, a park superintendent, plans to conduct a survey about the elevations of all islands of the park. He has contour maps of the islands. A contour map shows elevations above sea level and surface features of the land by means of contour lines. A contour line is a closed curve which joins points of equal elevation above a given level (see Figure 1). </p>

<p>The contour lines of the islands in the park, do not intersect each other, and are simple convex closed curves like ellipses. In order to use a computer, he first converted the original contour maps to corresponding digital contour maps. In a digital contour map, a contour line is represented as the boundary of a rectilinear convex polygon (see Figure. 2). A rectilinear polygon is a polygon whose edges are either horizontal or vertical. A rectilinear polygon P is called convex if the intersection of the interior of P and a vertical or horizontal line is either empty or a line segment. A level is a predefined measure for elevation. The outermost contour line is at level 1. If the closest contour line surrounding a contour line c is at level k, then c is at level k+1. In Figure 2, the level of the highest contour line that we can see in the map is 5. </p>

<p><img alt="" src="" style="height:273px; width:643px"></p>

<p>Given a contour map with n contour lines that are represented as the boundaries of rectilinear convex polygons, write a program that computes the level of the highest contour line in the map.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line containing an integer m (1 ≤ m ≤ 20,000), where m is the number of rectilinear convex polygons representing contour lines, In the next m lines of each test case, each line contains 2k+1 integers k, x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub>, y<sub>2</sub>, ..., x<sub>k</sub>, and y<sub>k</sub> (4 ≤ k ≤ 100, 1 ≤ x<sub>i</sub>, y<sub>i</sub> ≤ 10<sup>9</sup>), where k is the number of vertices of a rectilinear convext polygon Q and (x<sub>i</sub>, y<sub>i</sub>)'s are coordinates of k vertices of Q, which are in counterclockwise order. Notice that the boundaries of any two rectilinear convex polygons do not intersect each others. </p>

<p> </p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain an integer, the level of the highest contour line in the map. </p>

