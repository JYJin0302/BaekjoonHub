# [Diamond V] Jackdaws And Crows - 18089 

[문제 링크](https://acmicpc.net/problem/18089) 

### 성능 요약

메모리: 25672 KB, 시간: 556 ms

### 분류

애드 혹, 자료 구조, 세그먼트 트리, 집합과 맵

### 제출 일자

2023년 08월 02일 14:45:43

### 문제 설명

<p>Nick is a bird watcher and often visits the forum “CrowFinders” to discuss his hobby with like-minded people. CrowFinders has a voting system where users can upvote or downvote comments, which increases or decreases their score by 1. This means that each comment can end up with any integer score (including negative scores). Once when Nick was browsing a heated discussion about the classification of jackdaws as crows, he found something very pleasing: a chain of comments that alternated between positive and negative scores. But a few days later, he found that the comment chain was no longer alternating. Now Nick wants to make it alternating again.</p>

<p>A comment chain is alternating if the scores s<sub>1</sub>, s<sub>2</sub>, . . . , s<sub>n</sub> of the comments all are non-zero, and every pair of adjacent scores s<sub>i</sub>, s<sub>i+1</sub> have opposite signs. In particular, a single comment with a non-zero score or even a comment chain without any comment is an alternating comment chain.</p>

<p>There are two operations Nick can do to make the comment chain alternating:</p>

<ol>
	<li>Create a fake account and upvote/downvote some of the comments. This increases/decreases their respective scores by 1. Each fake account can only upvote/downvote each comment at most once, but it can vote on any subset of the comments. It takes c seconds to create an account and use it to vote (regardless of how many comments are upvoted/downvoted).</li>
	<li>Report one specific comment to remove it from the chain. Thinking of convincing reasons for the report takes r seconds. (Nick is an excellent arguer, so once the report is filed, the comment is guaranteed to be removed.)</li>
</ol>

<p>Nick can apply these operations in any order, any number of times. How fast can he make the comment chain alternating?</p>

<p>For example, consider Sample Input 1 below, where the scores in the comment chain are 8, 8, 2, −2, and it takes Nick 10 seconds to create an account and 50 seconds to file a report for one comment. In this case it is optimal to first create 3 fake accounts and use them to upvote the fourth comment and downvote the third, followed by reporting the first comment. This results in the scores 8, −1, 1, which is an alternating chain. The time used for this is 80 seconds.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with three integers n, c, and r (1 ≤ n ≤ 5 · 10<sup>5</sup>, 1 ≤ c, r ≤ 10<sup>9</sup>), the number of comments in the chain, the time it takes to create a fake account and the time it takes to report one comment respectively.</li>
	<li>One line with n integers s<sub>1</sub>, . . . , s<sub>n</sub> (−10<sup>9</sup> ≤ s<sub>i</sub> ≤ 10<sup>9</sup> for all i), the current score of each comment in the chain.</li>
</ul>

### 출력 

 <p>Output the smallest time to make the comment chain alternating by applying the operations above.</p>

