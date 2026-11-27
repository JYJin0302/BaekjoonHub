# [Gold I] 이런 문제는 유치원생도 해결할 수 있어 - 6531 

[문제 링크](https://acmicpc.net/problem/6531) 

### 성능 요약

메모리: 2184 KB, 시간: 12 ms

### 분류

다이나믹 프로그래밍, 파싱, 문자열

### 제출 일자

2022년 01월 30일 22:47:05

### 문제 설명

<p>
Surely you know someone who thinks he is very clever. You decide to
let him
down with the following problem:</p><p>
</p>
<ul>
<li>"Can you tell me what the syntax for a set is?", you ask him.</li>
<li>"Sure!", he replies, "a set encloses a
possibly empty list
of elements within two curly braces. Each element is either another set
or a letter of
the given alphabet. Elements in a list are separated by a comma." </li>
<li>"So if I give you a word, can you tell me if it is a
syntactically
correct
representation of a set?" </li>
<li>"Of course, any fool can do it!" is his answer.</li>
</ul>
Now you got him! You present him with the following grammar, defining
formally the syntax for a set (which was described informally by him):
<pre>Set          ::= "{" Elementlist "}"
Elementlist  ::= <empty> | List
List         ::= Element | Element "," List
Element      ::= Atom | Set
Atom         ::= "{" | "}" | ","
</pre>
<samp><empty></samp> stands for the empty word, i.e., the list in a set can be empty.<p></p><p>
Soon he realizes that this task is much harder than he has thought,
since the alphabet consists of the characters
which are also used for the syntax of the set. So he claims that it is
not possible to decide efficiently if a word
consisting of <samp>"{"</samp>, <samp>"}"</samp> and <samp>","</samp> is a syntactically correct
representation of a set or not.</p><p>
To disprove him, you need to write an efficient program that will
decide this
problem.

				</p>

### 입력 

 <p>The first line of the input file contains a number representing the
number of lines to follow. </p><p>
Each line consists of a word, for which your
program has to decide
if it is a syntactically correct representation of a set.
You may assume that each word consists of between <i>1</i> and <i>200</i>
characters
from the set { <samp>"{"</samp>, <samp>"}"</samp>, <samp>","</samp> }.
</p>

### 출력 

 <p>Output for each test case whether the word is a set or not.
Adhere to the format shown in the sample output.
</p>

