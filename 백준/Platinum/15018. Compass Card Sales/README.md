# [Platinum I] Compass Card Sales - 15018 

[문제 링크](https://acmicpc.net/problem/15018) 

### 성능 요약

메모리: 20884 KB, 시간: 216 ms

### 분류

자료 구조, 구현, 연결 리스트, 우선순위 큐, 집합과 맵, 시뮬레이션, 트리를 사용한 집합과 맵, 값 및 좌표 압축

### 제출 일자

2023년 06월 02일 02:22:27

### 문제 설명

<p>Katla has recently stopped playing the collectible card game Compass. As you might remember, Compass is a game where each card has a red, a green and a blue angle, each one between 0 and 359, as well as an ID. Since she has stopped playing, Katla has decided to sell all her cards. However, she wants to keep her deck as unique as possible while selling off the cards. Can you help her figure out the order in which she should sell the cards?</p>

<p>To decide how unique a card is in the deck, she proceeds as follows. For each of the three colors she finds the closest other card in both directions, and then computes the angle between these two other cards. For instance if she has three cards with red angles 42, 90 and 110, then the uniqueness values of their red angles are 340, 68, and 312, respectively. If two cards A and B have the same angle, B is considered the closest to A in both directions so that the uniqueness value of A (and B) for that color is 0.</p>

<p>By summing the uniqueness values over the three colours, Katla finds how unique each card is. When selling a card, Katla sells the currently least unique card (smallest uniqueness value). If two cards have the same uniqueness value, she will sell the one with the higher ID first. After each card is sold, the uniqueness values of the remaining cards are updated before selling the next card.</p>

### 입력 

 <p>The first line of input contains an integer n, the number of cards (1 ≤ n ≤ 10<sup>5</sup>). Then follows n lines. Each of these n lines contains 4 integers r, g, b, id (0 ≤ r, g, b < 360, 0 ≤ id < 2<sup>31</sup>), giving the red, green and blue angles as well as the ID of a card. No two cards have the same ID.</p>

### 출력 

 <p>Output n lines, containing the IDs of the cards in the order they are to be sold, from first (least unique) to last (most unique).</p>

