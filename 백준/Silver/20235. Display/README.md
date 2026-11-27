# [Silver III] Display - 20235 

[문제 링크](https://acmicpc.net/problem/20235) 

### 성능 요약

메모리: 2024 KB, 시간: 12 ms

### 분류

그리디, 구현

### 제출 일자

2023년 08월 11일 14:51:04

### 문제 설명

<p>St. Petersburg Supway tests new SupLED ticker displays. The display shows a monochrome sliding text line printed in SupFont. The text is only shown once and does not loop. Each SupFont character has a fixed size of $w \times h$ pixels, where each pixel is either <em>on</em> or <em>off</em>. There is a column of <em>off</em> pixels between consecutive characters of the text. The text sliding speed is one pixel per tick.</p>

<p>The main service life factor is the number of switches: when a pixel turns from <em>on</em> to <em>off</em> or vice versa. A pixel breaks after $s$ switches. If a pixel's state is not changed between two ticks, no switches occur.</p>

<p>The services team needs to estimate the shortest text that causes any of the pixels to break. All pixels are <em>off</em> before the text is shown.</p>

### 입력 

 <p>The first line of the input contains four integers $n$, $w$, $h$, and $s$ --- the number of characters in SupFont, width and height of each character, and the number of switches after which a pixel becomes broken ($1 \le n \le 94$; $1 \le w, h \le 30$; $1 \le s \le 10^6$).</p>

<p>The following lines contain SupFont character descriptions. The first line of each description contains an ASCII character (only characters with codes between 33 and 126, inclusive, are used). The character's image with $h$ lines of length $w$ follows, '<code>#</code>' denotes an <em>on</em> pixel, and '<code>.</code>' denotes an <em>off</em> pixel. Each image has at least one <em>on</em> pixel.</p>

<p>All described ASCII characters are distinct, but some of them may have the same image.</p>

### 출력 

 <p>Output a single line containing at most $s$ characters: the shortest text that, when shown on a display, causes some pixel to switch at least $s$ times. If there are multiple solutions, output any of them.</p>

