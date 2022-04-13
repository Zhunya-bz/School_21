## Get Next Line ##

[![saltmer's 42 get_next_line Score](https://badge42.vercel.app/api/v2/cl1mc7bhg006309kzftm5w40f/project/2164841)](https://github.com/JaeSeoKim/badge42)

Reading a line on a fd is way too tedious.


Вызов функции get_next_line в цикле позволяет читать текст, доступный в файловом дескрипторе, по одной строке за раз до его конца.

Функция возвращает только что прочитанную строку. Если читать больше нечего или произошла ошибка, возвращает NULL.

Работает корректно при чтении из файла и при чтении из стандартного ввода.

Размер буффера для чтения в функции get_next_line BUFFER_SIZE может меняться.

В данном проекте ипользуются статические переменные. 

##  Usage

```
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=10 *.c && ./a.out
```

Полный subject на английском приведен <a href="./en.subject.pdf">тут</a>.
