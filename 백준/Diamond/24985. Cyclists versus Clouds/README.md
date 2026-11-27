# [Diamond V] Cyclists versus Clouds - 24985 

[문제 링크](https://acmicpc.net/problem/24985) 

### 성능 요약

메모리: 23584 KB, 시간: 2548 ms

### 분류

너비 우선 탐색, 기하학, 그래프, 그래프 탐색, 구현, 최단 경로

### 제출 일자

2025년 10월 09일 00:09:57

### 문제 설명

<p>In Nlogonia, several campaigns aim to transform the bicycle into the main mean of transportation in the country. One of the actions to promote bikes is a Hackathon focused on the development of applications to facilitate cyclists’ day-to-day.</p>

<p>Your university’s team has a promising idea. As Nlogonia is a very rainy country, sometimes those who go out in the rain do not intend to get wet but do so purely for lack of option. The idea then is to develop an application capable of generating a route between two points that guarantees that it is possible to make the journey without getting wet, such that there isn’t another route with the same guarantee that would take less time.</p>

<p>For the prototype to be presented at the Hackathon, consider that all points of interest are arranged in the Cartesian plane and have integer coordinates. Rain clouds are modeled as simple polygons (non-contiguous edges do not intersect) with each edge parallel to one of the axes. Each cloud moves one unit of distance per unit of time in one of the cardinal directions (North, South, East, or West). A cyclist also moves one unit of distance per unit of time in cardinal directions. The cyclist can change direction at any of the points of interest; changing directions happens instantly. In addition, during the journey the cyclist can stand still at any of the points of interest, protecting themselves from the rain for any integer amount of units of time desired. The cyclist gets wet if they are not stopped at a point of interest (protecting themselves from the rain) and there’s at least one cloud above them. A cloud is not considered to be above the cyclist when the cyclist is at its border.</p>

<p>While other team members are concerned with generating the data and creating the graphical interface for the Hackathon, your task is to develop the part of the software responsible for generating the best route for a cyclist who wants to travel between two points of interest without getting wet.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 232px; height: 237px;"></p>

<p>The picture above corresponds to the first two samples. In the first sample, as the cloud moves east, the cyclist can go directly to the destination, first moving west and then north, for a total of seven units of time. In the second sample, the cloud moves south, so the cyclist can only move one unit of distance west without getting wet. If the cyclist tried to move west a second time, the cloud would be above them. The fastest way then is to wait one unit of time after moving west, then move north following the border of the cloud, and finally west towards the destination, for a total of eight units of time.</p>

### 입력 

 <p>The first line contains four integers X<sub>o</sub>, Y<sub>o</sub>, X<sub>d</sub>, and Y<sub>d</sub> (0 ≤ X<sub>o</sub>, Y<sub>o</sub>, X<sub>d</sub>, Y<sub>d</sub> ≤ 100), indicating that the cyclist starts at point (X<sub>o</sub>, Y<sub>o</sub>) and wants to arrive to point (X<sub>d</sub>, Y<sub>d</sub>). The second line contains an integer N (0 ≤ N ≤ 100) representing the number of rain clouds. After these lines, there are N groups of lines, each group describing a cloud.</p>

<p>Within each group describing a cloud, the first line contains a character C and an integer V (4 ≤ V ≤ 100). The character C is one of the uppercase letters “<code>N</code>”, “<code>S</code>”, “<code>E</code>” or “<code>W</code>”, indicating respectively that the cloud moves in the direction North (y ascending), South (y descending), East (x ascending) or West (x descending). The value V represents the number of vertices of the polygon that models the cloud. Each of the next V lines contains two integers X and Y (0 ≤ X, Y ≤ 100), denoting that the point (X, Y ) is a vertex of the polygon. Vertices appear in clockwise order. All the given vertices are actual corners of the polygon.</p>

### 출력 

 <p>Output a single line with an integer indicating the minimum amount of units of time needed to travel from (X<sub>o</sub>, Y<sub>o</sub>) to (X<sub>d</sub>, Y<sub>d</sub>) without getting wet.</p>

