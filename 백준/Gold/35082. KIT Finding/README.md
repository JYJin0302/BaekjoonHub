# [Gold IV] KIT Finding - 35082 

[문제 링크](https://acmicpc.net/problem/35082) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2026년 02월 27일 11:28:06

### 문제 설명

<p>"<em>Find the Fox</em>" is a recent book that contains $200$ pages of word search puzzles comprising only the letters '<code>F</code>', '<code>O</code>' and '<code>X</code>'. The special feature of the book is that there is only a single occurrence of the word "<code>FOX</code>" throughout all of its pages.</p>

<p>Recall that in a word search the goal is to find hidden words (only one hidden word in this case) in a grid of letters. The words can occur horizontally or vertically or diagonally, as well as forwards or backwards, allowing for a total of $8$ different reading directions.</p>

<p>For this year's NWERC, we want to create a baby version of "<em>Find the Fox</em>". Your goal in this problem, therefore, is to create a word search grid with given dimensions and containing each of the letters '<code>K</code>', '<code>I</code>' and '<code>T</code>' a given number of times. Similar to the original book, this grid should contain exactly one occurrence of the word "<code>KIT</code>".</p>

<p style="text-align: center;"><img alt="" src="" style="width: 100px; height: 82px;"></p>

<p style="text-align: center;">Figure K.1: Illustration of Sample Output 1. Flip page for the solution.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
<li>One line with five integers $h$, $w$, $k$, $i$, and $t$ ($3 \le h,w \le 100$, $k,i,t \ge 1$, $k+i+t = h\cdot w$), where $h$ and $w$ are the height and width the word search grid should have, and $k$, $i$, and $t$ specify the required number of occurrences of '<code>K</code>', '<code>I</code>' and '<code>T</code>', respectively.</li>
</ul>

### 출력 

 <p>Output a word search grid according to the given rules. It can be shown that such a word search grid always exists.</p>

<p>If there are multiple valid solutions, you may output any one of them.</p>

