# [Platinum II] 카우보이 - 1832 

[문제 링크](https://acmicpc.net/problem/1832) 

### 성능 요약

메모리: 23656 KB, 시간: 40 ms

### 분류

비트마스킹, 비트필드를 이용한 DP, 다이나믹 프로그래밍, 수학, 확률론

### 제출 일자

2026년 01월 22일 18:02:06

### 문제 설명

<p>This is back in the Wild West where everybody is ﬁghting everybody. In particular, there are n cowboys, each with a revolver. These are rather civilized cowboys, so they have decided to take turns ﬁring their guns until only one is left standing. Each of them has a given probability of hitting his target, and they all know each other’s probability. Furthermore, they are geniuses and always know which person to aim at in order to maximize their winning chance, so they are indeed peculiar cowboys. If there are several equally good targets, one of those will be chosen at random. Note that a cowboy’s code of ethics forces him to do his best at killing one of his opponents, even if intentionally missing would have increased his odds (yes, this can happen!)</p>

### 입력 

 <p>On the ﬁrst line of the input is a single positive integer t, telling the number of test cases to follow. Each case consists of one line with an integer 2 ≤ n ≤ 13 giving the number of cowboys, followed by n positive integers giving hit percentages for the cowboys in the order of their turns.</p>

### 출력 

 <p>For each test case, output one line with the percent probabilities for each of them surviving, in the same order as the input. The numbers should be separated by a space and be correctly rounded to two decimal places.</p>

