
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
class Item { ... }//210647
```

Приватные поля класса: 

```c++
private://210647
    int id;//210647
    double cost;//210647
    double weight;//210647
    int durability;//210647
    int age;//210647
```

Конструктор класса Item:

```c++
Item(int id, double cost, double weight, int durability, int age)//210647
    : id(id), cost(cost), weight(weight), durability(durability), age(age) {//210647
}
```

Метод для подсчета стоимости на грамм:

```c++
double CalculateCostPerGram() const {//210647
    return cost / weight;//210647
}
```

Метод для подсчета ”оставшегося времени существования”:

```c++
int CalculateRemainingLifetime() const {//210647
    return durability - age;//210647
}
```

Метод для вывода информации о предмете:

```c++
void Show() const {//210647
    std::cout << "Id: " << id << "\n";//210647
    std::cout << "Cost: $" << cost << "\n";//210647
    std::cout << "Weight: " << weight << " grams\n";//210647
    std::cout << "Durability: " << durability << " years\n";//210647
    std::cout << "Age: " << age << " years\n";//210647
}
```

Объекты класса Item и все возможные процедуры над ними:

```c++
int main() {
    Item item1(1, 70.0, 100.0, 5, 1);//210647
    Item item2(2, 50.0, 65.0, 3, 2);//210647
    Item item3(3, 20.0, 40.0, 4, 3);//210647

    cout << "===== Item1 =====" << "\n";//210647
    item1.Show();//210647
    cout << "Cost per gram: $" << item1.CalculateCostPerGram() << "\n";//210647
    cout << "Remaining lifetime: " << item1.CalculateRemainingLifetime() << " years\n";//210647
    cout << "\n";//210647

    cout << "===== Item 2 =====" << "\n";//210647
    item2.Show();//210647
    cout << "Cost per gram: $" << item2.CalculateCostPerGram() << "\n";//210647
    cout << "Remaining lifetime: " << item2.CalculateRemainingLifetime() << " years\n";//210647
    cout << "\n";//210647

    cout << "===== Item 3 =====" << "\n";//210647
    item3.Show();//210647
    cout << "Cost per gram: $" << item3.CalculateCostPerGram() << "\n";//210647
    cout << "Remaining lifetime: " << item3.CalculateRemainingLifetime() << " years\n";//210647
}
```

#### Результат работы программы ####

![img.png](images/img.png)

#### Вывод ####

Научились создавать простейшие DLL.
