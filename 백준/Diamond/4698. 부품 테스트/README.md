# [Diamond V] 부품 테스트 - 4698 

[문제 링크](https://acmicpc.net/problem/4698) 

### 성능 요약

메모리: 2924 KB, 시간: 24 ms

### 분류

이분 탐색, 유량, 그래프, 그리디, 누적 합, 정렬, 최대 유량 최소 컷 정리

### 제출 일자

2026년 02월 04일 16:51:24

### 문제 설명

<p>The engineers at ACM Corp. have just developed some new components. They plan to spend the next two months thoroughly reviewing and testing these new components. The components are categorized into several different classes, depending on their complexity and importance. Components in different classes may require different number of reviewers, whereas components in the same class always require the same number of reviewers.</p>

<p>There are also several different job titles at ACM Corp. Each engineer<br>
holds a single job title. All engineers holding a given job title have the same limit on the number of components that they can review. Note that an engineer can be assigned to review any collection of components and will be able to complete the task, regardless of which classes the components belong to. An engineer may review some components of the same class, and others from different classes, but an engineer cannot review the same component more than once.</p>

<p>Can the engineers complete their goal and finish testing all components in two months?</p>

### 입력 

 <p>There will be multiple test cases in the input.</p>

<p>The first line of each test case contains two integers n (1 ≤ n ≤ 10,000) and m (1 ≤ m ≤ 10, 000), where n is the number of component classes and m is the number of engineer job titles.</p>

<p>Each of the next n lines contains two integers j (1 ≤ j ≤ 100,000) and c (0 ≤ c ≤ 100,000), indicating that there are j components in this class and that each component requires at least c different reviewers.</p>

<p>Then each of the next m lines each contains two integers k (1 ≤ k ≤ 100, 000) and d (0 ≤ d ≤ 100, 000), indicating that there are k engineers with this job title and that each engineer may be assigned to review at most d components.</p>

<p>The input will end with a line with two 0s.</p>

### 출력 

 <p>For each test case, print a single line containing 1 if it is possible for the engineers to finish testing all of the components and 0 otherwise.</p>

