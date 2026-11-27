# [Diamond IV] The Staging - 15621 

[문제 링크](https://acmicpc.net/problem/15621) 

### 성능 요약

메모리: 36852 KB, 시간: 592 ms

### 분류

순열 사이클 분할, 자료 구조, 구현, 세그먼트 트리

### 제출 일자

2026년 11월 21일 15:40:10

### 문제 설명

<p>Steven Byteberg is a movie director, specialising in action movies. Presently he is working on a new movie, whose theme is Byteonian Mafia wars. Byteberg wonders what should be the final shape of the movie climax scenes, which will be a spectacular gunfire exchange.</p>

<p>n gangsters participate in this scene, numbered, for simplicity, using consecutive numbers from 1 to n. When the tension reaches its critical point, each gangster pulls out his weapon and takes aim at another gangster. Nobody gets aimed at by more than one gangster. Gangsters are poor, but well trained-each can shoot only once, however this shot is always accurate and always deadly.</p>

<p>At some point, one of the thugs cannot withstand the tension any longer and the shooting starts.</p>

<p>The director has determined the initial order in which gangsters have to pull the triggers. Namely, the gangster i shoots towards the gangster p<sub>i</sub> at the precise moment t<sub>i</sub>, unless gangster i already has been killed by that time. The gangster is killed exactly at the same moment when someone shoots in his direction.</p>

<p>The director would like to know how many gangsters will be alive at the end of this scene. Byteberg is not yet completely certain concerning the order in which the gangsters have to shoot. From time to time he commands to change one of the values t<sub>i</sub>. After every such change he would like to know the number of gangsters who would survive, referring to the new order in which gangsters shoot (taking into account all changes made so far).</p>

### 입력 

 <p>The first line of input contains one integer n (2 ≤ n ≤ 200,000), denoting the number of gangsters involved in the scene. The second line contains n integers p<sub>1</sub>, p<sub>2</sub>, ..., p<sub>n</sub> (1 ≤ p<sub>i</sub> ≤ n, p<sub>i</sub> ≠ i, p<sub>i</sub> ≠ p<sub>j</sub> for i ≠ j) describing whom successive gangsters intend to shoot at.</p>

<p>The third line contains n integers u<sub>1</sub>, u<sub>2</sub>, ..., u<sub>n</sub> (1 ≤ u<sub>i</sub> ≤ 10<sup>9</sup>), describing the initial order in which the gangsters are shooting: the initial value t<sub>i</sub> is equal to u<sub>i</sub>.</p>

<p>The fourth line contains one integer q (0 ≤ q ≤ 200,000), denoting the number of the changes of the values of t<sub>1</sub>, ..., t<sub>n</sub> as planned by Byteberg. Next q lines contain a description of these changes. The i-th line contains two integers k<sub>i</sub> and v<sub>i</sub> (1 ≤ k<sub>i</sub> ≤ n, 1 ≤ v<sub>i</sub> ≤ 10<sup>9</sup>), describing that the i-th change consists in setting the value of t<sub>k<sub>i</sub></sub> to v<sub>i</sub>. Numbers u<sub>1</sub>, u<sub>2</sub>, ..., u<sub>n</sub>, v<sub>1</sub>, v<sub>2</sub>, ..., v<sub>q</sub> are pairwise distinct.</p>

### 출력 

 <p>Your program should produce exactly q+1 lines. The first line should contain the number of gangsters who survive the shooting, assuming the initial order of shooting. The i-th of the following q lines should present the number of survived gangsters, assuming that the order of shooting is determined by the sequence t<sub>1</sub>, ..., t<sub>n</sub> after performing all the changes-from the first to the i-th.</p>

