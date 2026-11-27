# [Silver III] 문제 30069 - 30069 

[문제 링크](https://acmicpc.net/problem/30069) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

그리디, 수학

### 제출 일자

2024년 07월 25일 13:54:00

### 문제 설명

<p>Bitlandijos prekybos tinklas „Baxima“ nori modernizuoti savo parduotuves ir įrengti išmanius kasos aparatus. Vienas iš išmaniosios kasos komponentų yra robotas, gebantis automatiškai grąžinti grąžą bitais (Bitlandijos valiuta).</p>

<p>Bitų banknotai turi šiuos nominalus: $1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024$.</p>

<p>Dienos pradžioje kasa yra tuščia. Toliau yra registruojamos visos transakcijos: į kasą įdedamų banknotų nominalai. Trūksta tik programinės įrangos, kuri suskaičiuotų, kaip geriausia parinkti grąžą kiekvienam klientui.</p>

<p>Parašykite progamą, kuri rastų, kokiais nominalais robotas turi duoti grąžą, kad kiekvienam klientui būtų atiduodama kuo mažiau banknotų.</p>

### 입력 

 <p>Pirmoje eilutėje įrašytas transakcijų skaičius $T$. Sekančiose $T$ eilučių įrašyta po vieną skaičių $t_i$:</p>

<ul>
	<li>Jei $t_i > 0$, tai jis bus lygus vienam iš galimų Bito valiutos nominalų, ir reiškia, kad į kasą įdedamas šio nominalo banknotas.</li>
	<li>Jei $t_i < 0$, tai reiškia, jog klientui reikalinga grąža, ir iš kasos reikia išimti atitinkamus banknotus.</li>
</ul>

### 출력 

 <p>Kiekvienai grąžos transakcijai ($t_i < 0$), jūs turite išvesti po eilutę, kurioje būtų įrašyti grąžai panaudoti banknotai, nuo didžiausio iki mažiausio. Nepamirškite, jog robotas turi grąžinti pinigus taip, kad banknotų skaičius būtų kuo mažesnis.</p>

<p>Laikykite, kad kasoje visuomet bus pakankamai banknotų, kad pavyktų duoti grąžą klientui.</p>

