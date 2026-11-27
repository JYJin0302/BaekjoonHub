# [Gold II] 인간 대포 - 10473 

[문제 링크](https://acmicpc.net/problem/10473) 

### 성능 요약

메모리: 2192 KB, 시간: 0 ms

### 분류

데이크스트라, 기하학, 그래프, 최단 경로

### 제출 일자

2020년 10월 08일 22:54:40

### 문제 설명

<p>You are a world-famous circus performer, a human cannonball. This means that you climb into a big, fake cannon and launch yourself great distances to delight young and old alike. Today, you’re not alone. You are at the international human cannonball conference and exposition, where hundreds of similar circus performers have gathered together to share their experiences and practice their craft. While you normally have just one cannon to work with, at the conference there are usually lots of cannons to examine and try out.</p>

<p>The availability of several cannons creates some interesting opportunities for navigating the conference. If you want to travel quickly from point a to point b, you could just run straight from a to b, or, you could run to a nearby cannon and launch yourself somewhere else. From there, you can continue to run toward your destination or you can continue to use cannons in an effort to get to your destination more quickly. With cannons positioned like Figure E.1, you could follow a path like the one in Figure E.2 to get from a to b. The arrows show places where you launched yourself out of a cannon, and the lines show where you ran to the next cannon or to your destination.</p>

<p style="text-align: center;"><img alt="" src="" style="height:199px; width:305px"></p>

<p style="text-align: center;">Figure E.1: Illustration of the sample input. </p>

<p style="text-align: center;"><img alt="" src="" style="height:200px; width:299px"></p>

<p style="text-align: center;">Figure E.2: A suboptimal solution.</p>

<p>You run at a rate of 5 meters per second. All cannons launch you a distance of 50 meters, in any direction you’d like. Climbing into a cannon, launching yourself and landing takes a total of 2 seconds. Cannons are not obstacles; if a cannon is in your way, you can jump over or run around it without it slowing you down. Given your current location, a desired destination and the positions of available cannons, you want to plan how to get to the destination as quickly as possible.</p>

### 입력 

 <p>The input describes a single navigation problem. The first line gives a pair of real numbers, the X and Y coordinates where you’re currently located. The next line give the real-valued X and Y coordinates of the location you’d like to reach. This is followed by a line with an integer, n, the number of cannons available. The remaining n input lines each contain a pair of real values giving the X and Y coordinates for a cannon. All coordinates are measured in meters, and the value of n will be between 0 and 100, inclusive.</p>

### 출력 

 <p>Print a single line of output, the total number of seconds required to reach your destination as quickly as possible. Your answer must be accurate to within 0.001 seconds.</p>

