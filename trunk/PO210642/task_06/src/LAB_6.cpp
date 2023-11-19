#include <iostream>
#include <string>
#include <locale>

int main() {
    setlocale(LC_ALL, "Russian");

    const int POINTS_PER_QUESTION = 2;
    int totalPoints = 0;

    // Вопрос 1
    std::cout << "1. Что такое системное программирование?" << std::endl;
    std::cout << "a) Разработка программного обеспечения для конечного пользователя" << std::endl;
    std::cout << "b) Разработка программного обеспечения для работы с железом компьютера" << std::endl;
    std::cout << "c) Разработка веб-приложений" << std::endl;
    char answer1;
    std::cin >> answer1;
    if (answer1 == 'b') {
        totalPoints += POINTS_PER_QUESTION;
    }

    // Вопрос 2
    std::cout << "2. Какое из перечисленных ниже является системным вызовом?" << std::endl;
    std::cout << "a) printf()" << std::endl;
    std::cout << "b) open()" << std::endl;
    std::cout << "c) sqrt()" << std::endl;
    char answer2;
    std::cin >> answer2;
    if (answer2 == 'b') {
        totalPoints += POINTS_PER_QUESTION;
    }

    // Вопрос 3
    std::cout << "3. Что такое компилятор?" << std::endl;
    std::cout << "a) Программа для выполнения других программ" << std::endl;
    std::cout << "b) Программа для трансляции исходного кода в машинный код" << std::endl;
    std::cout << "c) Программа для создания графических интерфейсов" << std::endl;
    char answer3;
    std::cin >> answer3;
    if (answer3 == 'b') {
        totalPoints += POINTS_PER_QUESTION;
    }

    // Вопрос 4
    std::cout << "4. Что такое операционная система?" << std::endl;
    std::cout << "a) Программа для рисования графики" << std::endl;
    std::cout << "b) Программа для управления ресурсами компьютера" << std::endl;
    std::cout << "c) Программа для создания баз данных" << std::endl;
    char answer4;
    std::cin >> answer4;
    if (answer4 == 'b') {
        totalPoints += POINTS_PER_QUESTION;
    }

    // Вопрос 5
    std::cout << "5. Какие бывают типы памяти в компьютерной архитектуре?" << std::endl;
    std::cout << "a) Только оперативная память" << std::endl;
    std::cout << "b) Оперативная и постоянная память" << std::endl;
    std::cout << "c) Только постоянная память" << std::endl;
    char answer5;
    std::cin >> answer5;
    if (answer5 == 'b') {
        totalPoints += POINTS_PER_QUESTION;
    }

    // Вопрос 6
    std::cout << "6. Что такое многозадачность?" << std::endl;
    std::cout << "a) Возможность использования нескольких процессоров" << std::endl;
    std::cout << "b) Возможность выполнения нескольких задач одновременно" << std::endl;
    std::cout << "c) Возможность подключения нескольких устройств в сеть" << std::endl;
    char answer6;
    std::cin >> answer6;
    if (answer6 == 'b') {
        totalPoints += POINTS_PER_QUESTION;
    }

    // Вопрос 7
    std::cout << "7. Что такое файловая система?" << std::endl;
    std::cout << "a) Программа для создания файлов" << std::endl;
    std::cout << "b) Способ организации данных на носителе информации" << std::endl;
    std::cout << "c) Программа для копирования файлов" << std::endl;
    char answer7;
    std::cin >> answer7;
    if (answer7 == 'b') {
        totalPoints += POINTS_PER_QUESTION;
    }

    // Вопрос 8
    std::cout << "8. Какие из перечисленных ниже являются основными задачами операционной системы?" << std::endl;
    std::cout << "a) Управление процессами, управление памятью, управление вводом/выводом" << std::endl;
    std::cout << "b) Рисование графики, создание баз данных, обработка текста" << std::endl;
    std::cout << "c) Изготовление отчетов, воспроизведение музыки, создание презентаций" << std::endl;
    char answer8;
    std::cin >> answer8;
    if (answer8 == 'a') {
        totalPoints += POINTS_PER_QUESTION;
    }

    // Вопрос 9
    std::cout << "9. Какие языки программирования чаще всего используются для системного программирования?" << std::endl;
    std::cout << "a) Только скриптовые языки" << std::endl;
    std::cout << "b) Высокоуровневые и низкоуровневые языки" << std::endl;
    std::cout << "c) Только низкоуровневые языки" << std::endl;
    char answer9;
    std::cin >> answer9;
    if (answer9 == 'b') {
        totalPoints += POINTS_PER_QUESTION;
    }

    // Вопрос 10
    std::cout << "10. Что такое поток в контексте системного программирования?" << std::endl;
    std::cout << "a) Путь доступа к файлу" << std::endl;
    std::cout << "b) Выполняющаяся программа" << std::endl;
    std::cout << "c) Параллельный поток выполнения внутри процесса" << std::endl;
    char answer10;
    std::cin >> answer10;
    if (answer10 == 'c') {
        totalPoints += POINTS_PER_QUESTION;
    }

    // Выводим результат
    std::cout << "Вы набрали " << totalPoints << " баллов." << std::endl;

    // Анализируем результат
    if (totalPoints >= 15) {
        std::cout << "Отлично! Ваши знания системного программирования на высоком уровне." << std::endl;
    }
    else if (totalPoints >= 10) {
        std::cout << "Хорошо! Ваши знания системного программирования выше среднего." << std::endl;
    }
    else {
        std::cout << "Попробуйте еще раз. Вам есть куда расти в системном программировании." << std::endl;
    }

    return 0;
}
