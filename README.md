# Лабораторная работа. Утилита WordCount

> [!WARNING]
> Решение делать в ветке hw1, после чего необходимо сделать pull request в main

## Задача.	

Реализовать [утилиту](https://ru.wikipedia.org/wiki/%D0%A3%D1%82%D0%B8%D0%BB%D0%B8%D1%82%D0%B0) WordCount подсчитывающую количество строк, слов и байт для указанного файла и выводить эту информацию в поток вывода. 	
Программа должна поддерживать следующие опции:

**-l, --lines**    вывод количества строк

**-c, --bytes**    вывод размера файла в байтах

**-w, --words**    вывод количества слов

Название файла и опции передаются через аргументы командной строки в следующем формате:

_**WordCount.exe [OPTION] filename**_

Формат вывода (без заданных опций):
  lines words bytes filename
  
### Примеры запуска программы:
_WordCount.exe filename1_
 
_WordCount.exe filename1 filename2_

_WordCount.exe --words --lines filename1_

_WordCount.exe -l -c filename1_
 
_WordCount.exe -lwc filename1 filename2_

_WordCount.exe  filename1 filename2 -lw --bytes_ 

## Примечание.
Для реализации утилиты потребуется воспользоваться стандартной библиотекой ввода\вывода ([описание](https://en.cppreference.com/w/cpp/io/basic_ifstream)).
Пример того, как можно организовать парсинг (разбор) аргументов командной строки, можно посмотреть [здесь](http://www.cplusplus.com/articles/DEN36Up4/).


