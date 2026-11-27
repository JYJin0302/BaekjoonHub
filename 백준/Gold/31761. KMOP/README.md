# [Gold IV] KMOP - 31761 

[문제 링크](https://acmicpc.net/problem/31761) 

### 성능 요약

메모리: 33276 KB, 시간: 112 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 06월 03일 18:50:11

### 문제 설명

<p>You probably know the KMP algorithm. You may also know that “<code>KMP</code>” is an acronym that stands for “<code>Knuth Morris Pratt</code>”, who jointly published the algorithm in 1977. How do you pronounce “<code>KMP</code>”? Of course, you can just say “<code>Knuth Morris Pratt</code>”, but what about pronouncing the acronym itself? Since “<code>KMP</code>” is not a pronounceable word, you are forced to say the letters one by one. In this problem we are interested in pronounceable acronyms.</p>

<p>We need a few definitions to formalize the requirement. A phrase is a list of words and a word is a sequence of letters. Each letter is either a vowel or a consonant. Deciding whether a letter is a vowel or a consonant depends on the language and other elements. For simplicity, we say that the six letters “<code>A</code>”, “<code>E</code>”, “<code>I</code>”, “<code>O</code>”, “<code>U</code>” and “<code>Y</code>” are vowels, while all the rest are consonants. Although it is debatable whether a given word is pronounceable, we say that a word is pronounceable when it does not contain more than two contiguous consonants. For instance, “<code>LEMPEL</code>” is a pronounceable word, while “<code>DIJKSTRA</code>” is not.</p>

<p>Given a phrase composed of $N$ words, an acronym for the phrase is the concatenation of N prefixes, one prefix for each word, in the order they appear in the phrase. Each prefix must have at least one and at most three letters. Your task is to determine the minimum length a pronounceable acronym can have.</p>

<p>As an example with $N = 3$ consider the phrase “<code>KNUTH MORRIS PRATT</code>”. There are $27$ possible acronyms for this phrase, such as “<code>KMP</code>”, “<code>KMPR</code>”, “<code>KMPRA</code>”, “<code>KMOP</code>”, “<code>KMOPR</code>” and “<code>KNUMORPRA</code>”, among others. Some of these acronyms are pronounceable (“<code>KMOP</code>” and “<code>KMOPR</code>”), while some others not (“<code>KMP</code>”, “<code>KMPR</code>”, “<code>KMPRA</code>” and “<code>KNUMORPRA</code>”). Since the only three-letter acronym “<code>KMP</code>” is not pronounceable, it follows that “<code>KMOP</code>” is a minimum-length pronounceable acronym for the phrase.</p>

### 입력 

 <p>The first line contains a positive integer $N$ indicating the number of words in the phrase.</p>

<p>Each of the next $N$ lines contains a non-empty string made of uppercase letters representing a word in the phrase. Words are given in the order they appear in the phrase. The sum of the lengths of all the strings is at most $10^6$.</p>

### 출력 

 <p>Output a single line with an integer indicating the minimum length a pronounceable acronym can have, or the character “<code>*</code>” (asterisk) if no pronounceable acronym exists for the phrase.</p>

