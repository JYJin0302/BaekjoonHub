# [Silver IV] 카드셋트 - 11507 

[문제 링크](https://acmicpc.net/problem/11507) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

자료 구조, 해시를 사용한 집합과 맵, 파싱, 집합과 맵, 문자열

### 제출 일자

2020년 12월 22일 11:03:19

### 문제 설명

<p>Recently, Pero has been into robotics, so he decided to make a robot that checks whether a deck of poker cards is complete.</p>

<p>He’s already done a fair share of work - he wrote a programme that recognizes the suits of the cards. For simplicity’s sake, we can assume that all cards have a suit and a number.</p>

<p>The suit of the card is one of the characters P, K, H, T, and the number of the card is an integer between 1 and 13. The robot labels each card in the format TXY where T is the suit and XY is the number. If the card’s number consists of one digit, then X = 0. For example, the card of suit P and number 9 is labelled P09.</p>

<p>A complete deck has 52 cards in total - for each of the four suits there is exactly one card with a number between 1 and 13.</p>

<p>The robot has read the labels of all the cards in the deck and combined them into the string S.</p>

<p>Help Pero finish the robot by writing a programme that reads the string made out of card labels and outputs how many cards are missing for each suit.</p>

<p>If there are two exact same cards in the deck, output GRESKA (Croatian for ERROR). </p>

### 입력 

 <p>The first and only line of input contains the string S (1 ≤ |S| ≤ 1000), containing all the card labels. </p>

### 출력 

 <p>If there are two exact same cards in the deck, output “GRESKA”.</p>

<p>Otherwise, the first and only line of output must consist of 4 space-separated numbers: how many cards of the suit P K, H, T are missing, respectively. </p>

