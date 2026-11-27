# [Platinum IV] 석양이 진다... - 13352 

[문제 링크](https://acmicpc.net/problem/13352) 

### 성능 요약

메모리: 7804 KB, 시간: 48 ms

### 분류

기하학, 구현, 무작위화

### 제출 일자

2021년 09월 17일 22:33:29

### 문제 설명

<p>You are a newly designed and created robot. As a robot, you are excellent at shooting lasers: your lasers always go perfectly straight, go infinitely far, and are infinitely thin. To test you, the scientist who made you set out a number of targets for you to hit with your laser beam. The targets (point-like objects) are set up in a large, open room.</p>

<p>Unfortunately, you are running low on battery. You only have enough charge left to fire two shots. The targets are transparent, so you might be able to shoot multiple targets with your laser beam. In fact, you are able to hit an infinite number of targets with a single shot, as long as they are on a straight line. In addition, you can move anywhere before and between the two shots. Can you figure out if it is possible to hit all targets with at most two shots from your laser beams?</p>

### 입력 

 <p>The first line contains an integer N, satisfying 1 ≤ N ≤ 100 000, the number of targets.</p>

<p>The following N lines each contain two integers X<sub>i</sub> and Y<sub>i</sub>, satisfying −10<sup>9</sup> ≤ X<sub>i</sub>, Y<sub>i</sub> ≤ 10<sup>9</sup>. Each pair (X<sub>i</sub>, Y<sub>i</sub>) specifies the coordinates of one of the N targets. No two targets are placed at the same coordinates.</p>

<p>You may assume that height does not play a role in this problem.</p>

### 출력 

 <p>Output a single line containing a single word: “success” if it is possible to line up the two shots so that they hit all the targets, and “failure” if it is not.</p>

