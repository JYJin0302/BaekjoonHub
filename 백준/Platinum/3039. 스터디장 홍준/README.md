# [Platinum I] 스터디장 홍준 - 3039 

[문제 링크](https://acmicpc.net/problem/3039) 

### 성능 요약

메모리: 26352 KB, 시간: 140 ms

### 분류

이분 탐색, 자료 구조, 세그먼트 트리, 값 및 좌표 압축

### 제출 일자

2024년 10월 15일 16:13:45

### 문제 설명

<p>It's exam time in Mirko's village. Everyone wants to pass the exam with as little effort as possible, which is not easy. Mirko realized that it would be best for him to find someone who knows more than him and learn from them. Everyone followed and now everyone is looking for someone to learn from. </p>

<p>We can model how well a student is prepared for the exam with two integers, A and B. The number A represents how well a student understands the subject, while the number B is proportional to the quantity of their knowledge. </p>

<p>As the head of the village, Mirko decided that a student will ask another student for help only if that student has both numbers greater than or equal to the first student's numbers (no student will ask someone who doesn't understand the subject as well as themselves or who knows less). </p>

<p>Additionally, students will try to minimize the difference in knowledge quantity (so that students don't bother those that are way better). If this choice is not unique, they will try to minimize the difference in understanding. </p>

<p>Mirko's village has recently become a very popular suburb and new students keep moving in (in time for the exam). With Mirko's strict rules, they get confused about Mirko's rules and don't know where to go). They decided to ask a programmer from a neighbouring village for help. </p>

### 입력 

 <p>The first line of input contains an integer N (1 ≤ N ≤ 200 000), the number of queries and arrivals in the village. Each of the following N lines contains either: </p>

<ul>
	<li>"D A B", a student has moved in whose knowledge is A and B</li>
	<li>"P i", the i-th student to move in wants to know whom to ask for help </li>
</ul>

<p>The numbers A and B are between 1 and 2·10<sup>9</sup>. No two students have both numbers equal. </p>

### 출력 

 <p>For each query ("P i" line), output which student the i-th student should ask for help. The students are numbered in the order they moved into the village (starting from 1). If a student cannot be helped, output "NE". </p>

