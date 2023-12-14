
# Лабораторная работа №3 #

## DLL: динамически загружаемые библиотеки ##

## Вариант 1 ##

## Реализация/ход работы ##

### Цель работы: Научиться создавать простейшие DLL ###

#### **Условие** ####

Создать библиотеку с классом Item. В классе Item должны быть поля id, cost, weight, durability и age. В классе также должен быть конструктор и методы для подсчёта стоимости на грамм, подсчёта ”оставшегося времени существования” (durability
age) и вывода всех полей в консоль. В основной программе необходимо создать три объекта этого класса и провести с ними все возможные процедуры.

Класс Item:

```c++
class Item { ... }//1
```

Приватные поля класса:

```c++
private://1
    int id;//1
    double cost;//1
    double weight;//1
    int durability;//1
    int age;//1
```

Конструктор класса Item:

```c++
Item(int id, double cost, double weight, int durability, int age)//1
    : id(id), cost(cost), weight(weight), durability(durability), age(age) {//1
}
```

Метод для подсчета стоимости на грамм:

```c++
double CalculateCostPerGram() const {//1
    return cost / weight;//1
}
```

Метод для подсчета ”оставшегося времени существования”:

```c++
int CalculateRemainingLifetime() const {//1
    return durability - age;//1
}
```

Метод для вывода информации о предмете:

```c++
void Show() const {
    std::cout << "Id: " << id << "\n";//1
    std::cout << "Cost: $" << cost << "\n";//1
    std::cout << "Weight: " << weight << " grams\n";//1
    std::cout << "Durability: " << durability << " years\n";//1
    std::cout << "Age: " << age << " years\n";//1
}
```

Объекты класса Item и все возможные процедуры над ними:

```c++
int main() {
    Item item1(1, 70.0, 100.0, 5, 1);//1
    Item item2(2, 50.0, 65.0, 3, 2);//1
    Item item3(3, 20.0, 40.0, 4, 3);//1

    cout << "===== Item1 =====" << "\n";//1
    item1.Show();
    cout << "Cost per gram: $" << item1.CalculateCostPerGram() << "\n";//1
    cout << "Remaining lifetime: " << item1.CalculateRemainingLifetime() << " years\n";//1
    cout << "\n";//1

    cout << "===== Item 2 =====" << "\n";//1
    item2.Show();//1
    cout << "Cost per gram: $" << item2.CalculateCostPerGram() << "\n";//1
    cout << "Remaining lifetime: " << item2.CalculateRemainingLifetime() << " years\n";//1
    cout << "\n";//1

    cout << "===== Item 3 =====" << "\n";//1
    item3.Show();
    cout << "Cost per gram: $" << item3.CalculateCostPerGram() << "\n";//1
    cout << "Remaining lifetime: " << item3.CalculateRemainingLifetime() << " years\n";//1
}
```

#### Результат работы программы ####

![img.png](images/img.png)

#### Вывод ####

Научились создавать простейшие DLL.
