# Programowanie Systemowe
Sprawozdania przyszykowane przez Pawła Rumpla o nr Indexu 283849. Repetytorium jest przyszykowane w ten sposób żeby można było uruchomić make a po tym uruchomić programy przyszykowane podczas laboratoriów.

## Zamiana worker i server
Zaistniał problem polegający na tym, że logika działania funkcji server() i worker() jest zamieniona. Problem występuje wyłącznie w tych funkcjach. Użytkownik uruchamiający program nie zauważy tego problemu, ponieważ wpisanie „klient” uruchamia server, a wpisanie „server” uruchamia worker — w efekcie wszystko działa zgodnie z oczekiwaniami.
