# Дискретные задачи многокритериальной оптимизации.

## Несколько начальных понятий.

1. Пусть есть множество каких-то объектов. У каждого объекта есть какие-то критерии. Наша задача - выбрать из этого множества лучшие объекты по критериям. 
3. Для каждого критерия надо выбрать, лучший "воображаемый" объект должен минимизировать его, или максимизировать.      
4. Множество Парето - такое подмножество объектов, для которых нельзя во всем множестве выбрать объект, который будет не хуже, чем они, по всем критериям.
    
### На простых примерах: 
   1. Большое и кислое яблоко | маленькое, но сладкое яюлоко.
   
   В случае, когда мы хотим и сладкое и большое яблоко, - это множество Парето.
    
   2. Дорогой, но крепкий телефон | дешевый, но хрупкий телефон. 
    
   В случае, когда наша цель минимизировать затраты и максимизироать надежность, - это множество Парето.
   
   3. Маленькая и красивая тарелка | Большая и красивая тарелка. 
   
       В случае, когда мы хотим и тарелку
       
       побольше, и чтобы кушать было приятно, это *не* множество Парето.
       
       Почему? - Потому что для маленькой и красивой тарелки можно найти тарелку лучше.
       
       **Но** в этом примере есть множество Парето. Оно состоит из одной тарелки, большой и красивой.
       
       Для нее нельзя найти тарелку, которая будет лучше по всем параметрам.
       
### Визуальное представление

   ![image](images/example.png)
   
   В этом примере у объектов есть два критерия, X и Y. 
   
   MAX у осей критериев означает, что чем больше значение критерия, которому принадлежит ось, тем он лучше.
    
    
## Первая программа будет обрабатывать несколько точек и находить среди них множество Парето. 

## *Только для того случая, когда чем больше все критерии - тем объект желательней для нас.*

### Буду называть такой случай ALLMAX, ALL - все, MAX - максимум => максимизируем по всем параметрам.

### *Каков алгоритм?*

У каждой точки будет свой идентификатор, просто номер.

Посмотрев на мое определение 
множества Парето, можно понять, что
надо проверить для каждой точки,
есть ли точки, которые не хуже нее
по **всем** критериям. Проверять 
буду по порядку номеров.

*Буду называть такие точки просто
теми, которые лучше,а те, что
по некоторым критериям лучше,
а по некоторым - хуже, - несравнимыми.*

*Те, что не лучше по всем критериям,
буду называть худшими 
для другой точки*

Так и сделаю. Для каждой точки проверю все остальные.
Если для какой-то точки нашлась точка лучше,
то она не входит в множество, а если она
несравнима со всеми, и не хуже никакой,
то она входит в множество Парето. 

Таким образом, у меня останутся только те
точки, которые входят в множество Парето.

Посмотрим в файл pf.h

В ней функция 
find_and_alloc_Pareto перебирает для 
каждой точки все остальные и сравнивает их.
Для сравнения используется функция check.

В файле main.cpp в функции main
Происходит общение с пользователем
в результате которого программа получает 
количество критериев объектов и количество 
самих объектов. Потом вызывается функция
find_and_alloc_Pareto (описана выше) и ее
результат записывается в переменную Pareto.
Затем вызывается функция printMultitude, которая
только перебирает объекты множества и выводит их
на экран.

## Работа первой программы
---


Enter number of parameters for each object

3

Enter number of objects

5

Enter parameters of object 1

1 2 3

Enter parameters of object 2

3 2 1

Enter parameters of object 3

1 1 1

Enter parameters of object 4

2 2 5

Enter parameters of object 5

5 2 2

Pareto multitude:

2 2 5 

5 2 2 

---

## Что дальше?

### После того, как было положено начало в виде рабочей программы, появилось несколько идей для оптимизации

#### 1. Структура данных list была выбрана не просто так. В будущем можно будет оптимально по времени добавлять новые объекты к множеству.

#### 2. Кажется, что если отсортировать список по модулю векторов, образованных критериями объектов, алгоритм будет быстрее находить неподходящие множеству Парето элементы, так как если если модуль одного вектора больше, чем вектор второго, то второй точно не может быть лучше.

#### 3. Сейчас программа работает только с ALLMAX случаями. Можно свести задачи с произвольным выбором по MAX или MIN по каждому параметру к задачам ALLMAX, поменяв знак у MIN критериев на противоположный.

## Вторая программа будет сортировать точки по модулям перед поиском множества Парето и будет искать не только для MAX, но и для MIN критериев.

-----

Идея сортировать список оказалась нерабочей, так как, 
при наличии отрицательных весов, точки с меньшими модулями могут
быть лучше других, с большими модулями.

![image](/images/bigger_module_is_not_better.png)



