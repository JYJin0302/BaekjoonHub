# [Platinum I] 마트료시카 - 8884 

[문제 링크](https://acmicpc.net/problem/8884) 

### 성능 요약

메모리: 3568 KB, 시간: 388 ms

### 분류

다이나믹 프로그래밍, 정렬

### 제출 일자

2024년 01월 24일 18:23:19

### 문제 설명

<p>Matryoshkas are sets of traditional Russian wooden dolls of decreasing size placed one inside the other. A matryoshka doll can be opened to reveal a smaller ﬁgure of the same sort inside, which has, in turn, another ﬁgure inside, and so on.</p>

<p><img alt="" src="" style="float:right; height:200px; width:261px">The Russian Matryoshka Museum recently exhibited a collection of similarly designed matryoshka sets, differing only in the number of nested dolls in each set. Unfortunately, some over-zealous (and obviously unsupervised) children separated these sets, placing all the individual dolls in a row. There are n dolls in the row, each with an integer size. You need to reassemble the matryoshka sets, knowing neither the number of sets nor the number of dolls in each set. You know only that every complete set consists of dolls with consecutive sizes from 1 to some number m, which may vary between the different sets.</p>

<p>When reassembling the sets, you must follow these rules:</p>

<ul>
	<li>You can put a doll or a nested group of dolls only inside a larger doll.</li>
	<li>You can combine two groups of dolls only if they are adjacent in the row.</li>
	<li>Once a doll becomes a member of a group, it cannot be transferred to another group or permanently separated from the group. It can be temporarily separated only when combining two groups.</li>
</ul>

<p>Your time is valuable, and you want to do this reassembly process as quickly as possible. The only time-consuming part of this task is opening and subsequently closing a doll, so you want to minimize how often you do this. For example, the minimum number of openings (and subsequent closings) when combining group [1, 2, 6] with the group [4] is two, since you have to open the dolls with sizes 6 and 4. When combining group [1, 2, 5] with the group [3, 4], you need to perform three openings.</p>

<p>Write a program to calculate the minimum number of openings required to combine all disassembled matryoshka sets.</p>

### 입력 

 <p>The input consists of a single test case. A test case consists of two lines. The ﬁrst line contains one integer n (1 ≤ n ≤ 500) representing the number of individual dolls in the row. The second line contains n positive integers specifying the sizes of the dolls in the order they appear in the row. Each size is between 1 and 500 inclusive.</p>

### 출력 

 <p>Display the minimum number of openings required when reassembling the matryoshka sets. If reassembling cannot be done (some of the kids might have been excessively zealous and taken some dolls), display the word impossible.</p>

