# [Gold I] 고대 동굴 탐사 - 10273 

[문제 링크](https://acmicpc.net/problem/10273) 

### 성능 요약

메모리: 5256 KB, 시간: 352 ms

### 분류

방향 비순환 그래프, 다이나믹 프로그래밍, 그래프, 그래프 탐색, 위상 정렬

### 제출 일자

2020년 10월 18일 14:41:10

### 문제 설명

<p>You’re an intern at Greedy Cave Plundering Corporation. Your new job is to help with one of GCPC ’s projects: extracting valuable gemstones from a network of connected caves.</p>

<p>The history of the project so far:</p>

<ul>
	<li>Tom, one of the project managers, has hired Jill, a gemstone expert. She has already surveyed these caves and determined the value of all gemstones in each cave.</li>
	<li>Ruby, another project manager (PM), has been busy “guesstimating” a time frame, the budget and possible profits for this project.</li>
	<li>Evelyn and Jerry (also PMs) have hired two cave diggers and instructed them to extract thegemstones.</li>
	<li>The cave diggers needed equipment to extract the gemstones and transport them to the surface. So Jimmy (another PM) ordered some machines. Sadly, he did not communicate well with the cave diggers - he bought machines that are way too big for the current passage ways between caves.</li>
	<li>To fix this, Jimmy was fired and James, his successor, has ordered a very big drilling machine, so the cave diggers can widen the passage ways. However, James was fearful of cutting into his salary bonus, so he bought the cheapest machine he could find. Soon, after widening the passage way from the surface into cave 1, the cave diggers found out that the new drilling machine is very heavy and not so powerful, so it can only be used to widen a passage way that goes downwards. Once it has reached a lower cave, it can not be carried back up because of its weight.</li>
	<li>This is when Alice, the project manager in charge of budget planning, announced she would ignore further requests for more equipment.</li>
	<li>In an eight hour meeting discussing the problems of the project, it was decided to limit the project expenses. So, if further drilling would hurt profits or if the drilling machine reaches a cave where it can not go on, it will just be abandoned. Using the other machines, the cave diggers will then be able to harvest at least some of the gemstones. Afterwards, the dig site will probably be sold to another company. Ruby is already thinking about hiring her brother as a sales expert...</li>
</ul>

<p>This is where you come in. Tom has hired you to determine which passage ways should be widened and thereby which caves should be visited to maximize profits. Widening a passage way requires energy, materials and so on. You have to consider these costs. You will be given a map of all caves and passage ways. The map was created by the cave diggers, so it should be accurate. It contains only passage ways the drilling machine can handle, including the correct drilling direction. All caves in the map are reachable from cave one.</p>

### 입력 

 <p>The input starts with a line containing T, the number of test cases (1 ≤ T ≤ 10).</p>

<p>Each test case starts with a line containing two integers: N, the number of caves, and E, the number of passage ways (1 ≤ N ≤ 2 · 10<sup>4</sup>; 0 ≤ E ≤ 10<sup>5</sup>).</p>

<p>The second line contains N integers v<sub>1</sub> v<sub>2</sub> . . . v<sub>N</sub> . v<sub>i</sub> describes the value of all gemstones in cave i (0 ≤ v<sub>i</sub> ≤ 104).</p>

<p>Each of the next E lines contains three integers: a<sub>e</sub> b<sub>e</sub> c<sub>e</sub>. Such a line represents one of the possible direct passage ways from cave a<sub>e</sub> to cave b<sub>e</sub>, widening this passage way will cost c<sub>e</sub> (1 ≤ a<sub>e</sub>, b<sub>e</sub> ≤ N; 0 ≤ c<sub>e</sub> ≤ 10<sup>4</sup>). It is guaranteed that the input contains only valid digging directions, i.e. cave b<sub>e</sub> will be strictly deeper than a<sub>e</sub>.</p>

<p>You always start from cave number 1, because the digging machine is already there and there are no caves above.</p>

### 출력 

 <p>Output two lines for every test case. In the first line print two integers P and C, where P is the profit of the best possible route from top to bottom and C is the number of visited caves on that path. In the second line print the IDs of those caves, ordered from top to bottom.</p>

<p>If there are multiple solutions with optimal profit, print any.</p>

