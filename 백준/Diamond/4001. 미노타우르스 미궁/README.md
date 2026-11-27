# [Diamond IV] 미노타우르스 미궁 - 4001 

[문제 링크](https://acmicpc.net/problem/4001) 

### 성능 요약

메모리: 53960 KB, 시간: 396 ms

### 분류

이분 탐색, 그래프, 그래프 탐색, 격자 그래프, 누적 합

### 제출 일자

2024년 04월 02일 15:35:01

### 문제 설명

<p>The Minotaur is a half-bull half-man creature living in the Cretan Labyrinth. He terrorizes the whole Crete, especially the city of Minos. Every year seven young boys and girls are sent to the Labyrinth to please the Minotaur. After each sacriﬁce the Minotaur sleeps for a while.</p>

<p>Theseus, brave Greek hero half-god half-man, just came to Minos. The people of Minos ask him to kill the Minotaur. Unfortunately, the Minotaur is not an easy target to kill. Theseus doubts his ability to kill even sleeping Minotaur. So he decided to block the Minotaur inside his own Labyrinth.</p>

<p>The Labyrinth has a rectangular shape divided into square cells of equal size. Each cell is either empty of blocked. Blocked cells are impassable even for the Minotaur. The entrance to the Labyrinth is located in one corner of the Labyrinth, while the Minotaur’s lair is located in the opposite corner.</p>

<p>Theseus has only one chance to block the Minotaur — while he is asleep after sacriﬁce quickly build a square obstacle that blocks some of the Labyrinth’s cells. The cells that the obstacle is built on must be empty. The Minotaur is blocked if there is no way from his lair to the entrance of the Labyrinth. Certainly, the obstacle cannot block the Minotaur’s lair cell (you cannot build something a top of the Minotaur, even on a sleeping one), as well as the entrance cell (Theseus must not block the Labyrinth completely).</p>

<p>You have to calculate the minimum possible size of the square obstacle that is able to block the Minotaur.</p>

### 입력 

 <p>The ﬁrst line of the input ﬁle contains a pair of positive integer numbers w and h — the width and the height of the Labyrinth (2 ≤ w, h ≤ 1500).</p>

<p>The following h lines contain map of the Labyrinth. Each of them has length of w characters. Empty cells are denoted by dots (‘.’) and blocked cells — by number signs (‘#’).</p>

<p>The entrance is located in the upper-left corner (cell (1, 1)) and the Minotaur’s lair is located in the bottom-right corner (cell (w, h)). Both of these cells are empty and there is at least one way from the entrance to the Minotaur’s lair.</p>

### 출력 

 <p>Output three integer numbers l, x and y – the length of side of the minimum possible square obstacle that is able to block the Minotaur inside the Labyrinth, and the coordinates of its upper left cell. If there are multiple pairs of possible coordinates, output any of them. The obstacle must not contain any blocked cells, as well as the Labyrinth entrance or the Minotaur’s lair. If it is not possible to build a square obstacle that blocks the Minotaur, output a single word “Impossible”.</p>

