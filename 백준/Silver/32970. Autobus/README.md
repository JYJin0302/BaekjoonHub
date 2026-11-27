# [Silver III] Autobus - 32970 

[문제 링크](https://acmicpc.net/problem/32970) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

브루트포싱, 파싱, 문자열

### 제출 일자

2025년 07월 25일 14:31:06

### 문제 설명

<p>Mr. Malnar decided to visit one of the few cities he has not yet visited, Wroclaw (Pol. <em>Wrocław</em>), located in the southwest of Poland. Since he hadn’t traveled by bus for a long time, he missed the experience; however, he was disappointed to learn that there is no direct bus line between Zagreb and Wroclaw.</p>

<p>The best alternative is transferring in the Austrian city of Graz. Mr. Malnar found a timetable, i.e., a list of bus lines operating on the routes <em>Zagreb-Graz</em> and <em>Graz-Wroclaw</em>. A bus on a specific route runs daily, departing exactly at the start of the departure time minute and arriving precisely at the end of the last minute of the arrival time. The time required for transferring is negligible, i.e., it is possible to board a bus if you arrive at the destination before the bus you wish to transfer to departs (the arrival time of the first bus must be strictly less than the departure time of the second bus).</p>

<p>Determine the shortest time required to travel from Zagreb to Wroclaw.</p>

### 입력 

 <p>The first line contains a positive integer $n$ ($1 ≤ n ≤ 200$), the number of bus lines.</p>

<p>In the next $n$ lines, the names of two cities connected by the symbol "<code>-</code>" are given in order, the first representing the departure city and the second the destination city, followed by the departure time and arrival time in the format <code>h:mm--h:mm</code>, where <code>h</code> represents the hours, and <code>mm</code> represents the minutes of that time. Note that <strong>two</strong> digits for minutes will always be shown. If the number of minutes is a single digit, a leading zero will be included. It is guaranteed that each trip (without transfers) will last at most $24$ hours.</p>

### 출력 

 <p>If it is possible to travel from Zagreb to Wroclaw, print the travel time in the first line in the format <code>h:mm</code> (described above).</p>

