# Opole-University-of-Technology-Projects

## Treść zadania:
W XXII edycji Ogólnopolskiego Konkursu Matematycznego dla klas 3 szkoły podstawowej 
pojawiło się następujące zadanie:
Alicja ma dwa magiczne grzyby. Po zjedzeniu kawałka pierwszego robi się 
dwa razy wyższa, a po zjedzeniu kawałka drugiego - kurczy się o 1 m. Alicja ma teraz 1 m 15 cm wzrostu i chciałaby urosnąć dokładnie o 5 cm. Ile 
co najmniej kawałków grzybów musi zjeść?
Prawidłowe rozwiązanie: Alicja najpierw powinna zjeść kawałek drugiego grzyba, po którym 
będzie mierzyła 15 cm, a następnie trzy kawałki pierwszego grzyba, po których będzie mierzyła odpowiednio 30 cm, 60 cm i 120 cm. Razem Alicja musi zjeść cztery kawałki grzybów.

### Zadanie:
Napisz program, który rozwiązuje problem ogólniejszy: jaka jest najmniejsza liczba kawałków grzybów, które musi zjeść Alicja, aby zmienić wzrost z początkowego x cm na końcowe 
y cm. Działanie grzybów jest zgodne z oryginalnym zadaniem, natomiast każdy grzyb składa 
się tylko z ośmiu kawałków. Może się więc zdarzyć, że oczekiwana zmiana wzrostu będzie 
niewykonalna.
Uwaga! Nie jest możliwy ujemny wzrost!


### Wejście:

W pierwszym wierszu standardowego wejścia jest liczba całkowita Z (1 < Z < 100) oznaczająca 
liczbę testów. W każdym z kolejnych Z wierszy standardowego wejścia jest jeden test – dwie 
oddzielone spacją liczby całkowite dodatnie x i y (1 ≤ x, y ≤ 100000) oznaczające odpowiednio 
początkowy i końcowy wzrost Alicji w centymetrach.

### Wyjście:
Standardowe wyjście powinno w kolejnych Z wierszach zawierać odpowiedzi dla kolejnych 
testów. Odpowiedź stanowi pojedyncza liczba całkowita oznaczająca najmniejszą liczbę kawałków grzybów, których zjedzenie (w odpowiedniej kolejności) pozwala zmienić wzrost
zgodnie z danymi. Jeśli rozwiązanie nie istnieje (przy pomocy dostępnych kawałków grzybów 
nie da się zmienić wzrostu z x na y) na standardowym wyjściu powinno zostać wypisane słowo 
NIE
