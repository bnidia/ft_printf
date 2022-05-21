# ft_printf (Complexity 70 hours)
<img align="right" src="https://badge42.vercel.app/api/v2/cl3enoo9k004009muhk5a94tj/project/2398393" alt="bnidia's 42 ft_printf Score" />

### This project is pretty straightforward, you have to recode printf. You will learn what is and how to implement variadic functions. Once you validate it, you will reuse this function in your future projects.
<img align="right" src="https://github.com/bnidia/ft_printf/blob/master/ft_printf_test.gif" alt="test passing" />
I had to rewrite the printf library function with the keys **cspdiuxX**. The bonus part of the project is also implemented, which allows you to work with width, accuracy, space specifiers, +, -, #, 0. The full text of the task is here.

### Progress

The ft_printf function is significantly accelerated, due to the absence of the malloc function. All the necessary memory is allocated on the stack. And also acceleration occurs due to the use of a buffer of one kilobyte for the output string. Statistically, it is deduced that the average length of the string is from 45 to 75 characters, however, if we expect a very long output, then we can increase the buffer for the string, which is specified in the header file in the definition of BUF_SIZE

Also, this project taught me how to work with a variable number of arguments of the stdarg function

The project complies with the school code design rules The Norm v.3.0

### Этот проект довольно прост, вам нужно перекодировать printf. Вы узнаете, что такое вариационные функции и как их реализовать. Как только вы подтвердите его, вы будете повторно использовать эту функцию в своих будущих проектах.
<p>Этот проект средней сложности, школьная оценка - 70 часов работы.</p>
<p>Мне предстояло переписать библиотечную функцию <a href="https://www.opennet.ru/man.shtml?topic=printf&category=3&russian=0">printf</a> с ключами **cspdiuxX**. Так же реализована бонусная часть проекта которая позволяет работать с шириной, точностью, спецификаторами пробела, +, -, #, 0. Полный текст задания находится <a href="https://github.com/rustem-spb/ft_printf/blob/master/en.subject.pdf">здесь</a>.</p>
<img align="right" alt="Progress" src="https://github.com/bnidia/ft_printf/blob/master/passed.png" />
<p>Функция ft_printf значительно ускорена, за счет отсутствия функции malloc. Вся необходимая память выделяется на стеке. А так же ускорение происходит за счет использования буфера в один килобайт под выводимую строку. Статистически выведено, что <a href="https://ru.wikipedia.org/wiki/%D0%94%D0%BB%D0%B8%D0%BD%D0%B0_%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B8">средняя длина строки составляет от 45 до 75 знаков</a> Однако если мы ожидаем очень длинный вывод, то мы можем увеличить буфер под строку, который указан в заголовочном файле в определении BUF_SIZE </p>
<p>Также этот проект научил меня работать с <a href="https://www.opennet.ru/man.shtml?topic=va_arg&category=3&russian=0">переменным количеством аргументов функции stdarg</a></p>
<p>Проект соответствует школьным правилам оформления кода <a href="https://rbellero.notion.site/The-Norm-v-3-0-a32a9f8f32654610b90504289f92e0f1">The Norm v.3.0</a></p>

### Структура спецификатора формата
Спецификатор формата имеет вид:

> %[флаги][ширина][.точность][размер]тип

Обязательными составными частями являются символ начала спецификатора формата (%) и тип.

==== Флаги ====

| Знак           | Название знака | Значение                                                                                                    | В отсутствие этого знака        | Примечание                                                                                                                                                                                                                                                                                                                                                                                                                                           |
|----------------|----------------|-------------------------------------------------------------------------------------------------------------|---------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| <code>-</code> | минус          | выводимое значение выравнивается по левому краю в пределах минимальной ширины поля                          | по правому                      |                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| <code>+</code> | плюс           | всегда указывать знак (плюс или минус) для выводимого десятичного числового значения                        | только для отрицательных чисел  |                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| <code> </code> | пробел         | помещать перед результатом пробел, если первый символ значения не знак                                      | Вывод может начинаться с цифры. | Символ '''+''' имеет больший приоритет, чем пробел. Используется только для знаковых десятичных значений.                                                                                                                                                                                                                                                                                                                                            |
| <code>#</code> | решетка        | «альтернативная форма» вывода значения                                                                      |                                 | При выводе чисел в шестнадцатеричном или восьмеричном форматах перед числом будет указываться особенность формата (0x или 0 соответственно).                                                                                                                                                                                                                                                                                                         |
| <code>0</code> | ноль           | дополнять поле до ширины, указанной в поле *ширина* управляющей последовательности, символом <code>0</code> | дополнять пробелами             | Используется для типов <tt>d</tt>, <tt>i</tt>, <tt>o</tt>, <tt>u</tt>, <tt>x</tt>, <tt>X</tt>, <tt>a</tt>, <tt>A</tt>, <tt>e</tt>, <tt>E</tt>, <tt>f</tt>, <tt>F</tt>, <tt>g</tt>, <tt>G</tt>. Для типов <tt>d</tt>, <tt>i</tt>, <tt>o</tt>, <tt>u</tt>, <tt>x</tt>, <tt>X</tt>, если <tt>''точность''</tt> указана, этот флаг игнорируется. Для остальных типов поведение не определено. Если указан флаг минус '-', этот флаг так же игнорируется. |

### Модификатор ширины

*Ширина* (десятичное число или символ звёздочка) указывает минимальную ширину 
поля (включая знак для чисел). Если представление величины больше, чем 
ширина поля, то запись выходит за пределы поля (например, %2i для величины 
100 даст значение поля в три символа), если представление величины менее 
указанного числа, то оно будет дополнено (по умолчанию) пробелами слева, поведение может меняться в зависимости от других заданных флагов. Если в качестве ширины указана звёздочка, ширина поля указывается в списке аргументов перед значением для вывода (например, <code>printf( "%0*x", 8, 15 );</code>выведет текст <code>0000000f</code>). Если этим способом указан отрицательный модификатор ширины, считается что выставлен флаг -, а значение модификатора ширины установлено абсолютным.
