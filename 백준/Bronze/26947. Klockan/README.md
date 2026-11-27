# [Bronze I] Klockan - 26947 

[문제 링크](https://acmicpc.net/problem/26947) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

브루트포싱, 수학

### 제출 일자

2024년 07월 04일 18:17:18

### 문제 설명

<p>Om någon frågar hur mycket klockan är, svarar de flesta "kvart över fem", <code>15:29</code> eller något liknande. Vill man göra det lite svårare så kan man annars svara med vinkeln mellan tim- och minutvisaren, eftersom man ur denna information entydigt kan bestämma klockslaget. Dock är det många människor som är ovana vid detta sätt att ange tider, så det vore bra att ha ett datorprogram som översätter till ett mer normalt format. Du ska skriva ett sådant program.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 706px; height: 300px;"></p>

<p style="text-align: center;">Klockan till vänster är <code>01:21</code> och den till höger är <code>03:08</code>.</p>

<p>Vi förutsätter att vår klocka saknar sekundvisare och endast visar ett helt antal minuter (det vill säga: båda visarna hoppar framåt bara på hel minut). Vinkeln avläses genom att utgå från timvisaren och sedan mäta hur många grader medurs minutvisaren ligger (se figuren). För att undvika decimaler anges vinkeln i tiondels grader (så att $85.5$ grader skrivs som $855$). Detta tal är alltid ett heltal mellan $0$ och $3595$ (inklusive) och är, som en följd av att endast hela minuter visas, alltid delbart med $5$.</p>

### 입력 

 <p>Indatan består av ett enda heltal mellan $0$ och $3595$ -- vinkel mellan de två visarna, i tiondels grader.</p>

### 출력 

 <p>Skriv ut det klockslag som vinkeln motsvarar, på formatet <code>hh:mm</code>. Om antalet timmar är ensiffrigt ska du ändå skriva ut en ledande nolla i svaret. Vi förutsätter att det är morgon, så alla tider ska dessutom ligga mellan <code>00:00</code> och <code>11:59</code> (inklusive).</p>

