/*На данный момент реализован класс тамагочи - без задания конструктора и диструктора. они появятся в ближайшее время.
 * Написана программа для работы с классом.
 * Были проведены тесты:
 * 1) Ввод имени
 * 2) Проверка выбора ручного заполнения\ параметров по умолчанию - сытости и игривости питомца, вводом корректых и не
 * корректных значений.
 * 3) Заполнение параметров сытости и игривости корректными и не корректными числовыми значениями.
 * 4) Проверены операции Погладить, Поиграть, Покормить, Спать, Голос и Выход, а также - неккоректный номер операции.
 * 5) Проверен механизм предотвращения операции в случае выхода за пределы допустимых параметров: Операция при
 * нулевых сытости, игривости, сытости и игривости. Переполнение значений.
 * 6) Проверена команда Голос и Выход.
 * Программа выполнилняется и отображает ожидаемые результаты.
 */
#include <iostream>
#include <string>
class Tamagochi{

public:
    void GetName(){
        std::cout << "Give a name to your pet: ";
        std::cin >> name;
        std::cout << std::endl;
    }; // Присваиваем имя нашему питомцу.

    void SetSatiety(){
        std::cout << "Now enter starting value satiety for your pet (0 - 100): ";
        std::cin >> satiety;
        std::cout << std::endl;
        Limits(); // Возвращаем значение к 0 - 100.
    }; // Задаём сытость питомца.

    void SetPlayfulness(){
        std::cout << "Now enter starting value playfulness for your pet (0-100): ";
        std::cin >> playfulness;
        std::cout << std::endl;
        Limits(); // Возвращаем значение к 0 - 100.
    }; // Задаём игривость питомца.

    void ShowInfo(){
        std::cout << "The pet: " << name << std::endl;
        std::cout << "Satiety: " << satiety << "\tPlayfulness: " << playfulness <<std::endl;
    }; // Показывает имя питомца, его текущую сытость и игривость.

    void Stroke(){
        playfulness +=5;
        Limits(); // Возвращаем значение к 0 - 100.
        Success(); // Оповещаем пользователя об успешном завершении операции.
        ShowInfo(); // Выводим информацию о питомце
    }; // Погладить (+5 к игривости).

    void Play(){
        checkSatiety = satiety; // Присваиваем текущее значение сытости в дополнительную переменную.
        checkSatiety -= 10; // Вычитаем из временной переменной заданное значение.
        if (checkSatiety < 0){ // Проверяем дополнительную переменную на отрицательное значение.
            Check(); // Если значение отрицательное, выводим информацию, чего нехватает питомцу.
            ShowInfo(); // Выводим информацию о текущем состоянии питомца.
            return; // Завершаем действие без внесения изменений.
        } else{ // Если значение не отрицательное.
            satiety = checkSatiety; // Присваиваем основной переменной сытости значение дополнительной.
            playfulness += 10; //Увеличиваем сытость на заданное значение.
            Success();// Оповещаем пользователя об успешном завершении операции.
            Limits(); // Возвращаем значение к 0 - 100.
            ShowInfo();// Выводим информацию о питомце
            return;
        }

    }; // Поиграть (+10 к игривости, -10 к сыточти).

    void Feed(){
        satiety += 20;
        Limits();
        Success();
        ShowInfo();
    }; // Покормить (+20 к сытости).

    void Sleep(){
        checkPlayfulness = playfulness; // Присваиваем текущее значение игривости в дополнительную переменную.
        checkSatiety = satiety; // Присваиваем текущее значение сытости в дополнительную переменную.
        checkPlayfulness -= 20; // Уменьшаем значение игривости в доп. перменной.
        checkSatiety -= 10; // Уменьшаем значение сытости в доп переменной.
        if (checkSatiety < 0)
        {
            Check();
            return;
        } else if (checkPlayfulness < 0){ // Проверка на отрицательные значения.
            Check(); // Вывод причины отмены действия.
            ShowInfo();
            return;
        }else{ // Значение не отрицательное, операция выполняется.
            satiety = checkSatiety;
            playfulness = checkPlayfulness;
            Success();
            Limits();
            ShowInfo();
            return;
        }
    }; // Отправить спать (-10 к сытости, -20 к игривости).

    void Say(){
        std::string say;
        std::cout << "Enter what " << name << " have to say: ";
        std::cin >> say;
        std::cout << std::endl << name << " say: " << say << std::endl;
        Success();
        ShowInfo();
    }; // Подать голос


private:

    void Check(){
        if ((checkSatiety<0)&&(checkPlayfulness<0)){ // Проверка доп переменных на отрицательное значение.
            std::cout << name << " say: I can not do it, I need to eat and play!" << std::endl << std::endl; // Питомец голодный и злой! Не так просто его довести, но всё же..
            checkSatiety = 1; // Присваиваем дополнительной переменной не нулевое значение.
            checkPlayfulness = 1;// Чтобы при вызове проверки с одним аргументом, не применялся вывод для двух.
        } else if ((checkSatiety<0)){ // Проверка доп переменных на отрицательное значение.
            std::cout << name << " say: I can not do it, I need to eat!" << std::endl << std::endl; // Питомец голодный.
            checkSatiety = 1;
        } else if (checkPlayfulness<0){ // Проверка доп переменных на отрицательное значение
            std::cout << name << " say: I can not do it, I need to play!" << std::endl << std::endl; // Питомец грустный.
            checkPlayfulness = 1;
        }
    }; // Проверка параметров сытости и игривости питомца к возможности выполнения действий.

    void Limits(){
        if(satiety>100) satiety = 100;
        if(playfulness>100) playfulness = 100;
        if(satiety<0) satiety = 0;
        if(playfulness<0) playfulness = 0;
    }; // Возврат значений в диапозон от 0 до 100.

    void Success(){
        std::cout << std::endl << name << " say: I have done it! " << std::endl << std::endl;
    }; // Сообщение об успешно выполненой операции.

    std::string name; // Хранит имя питомца.
    int satiety = 100; // Сытость.
    int playfulness = 100; // Игривость.
    int

};


int main() {
    Tamagochi pet; // Заводим нового питомца.

    pet.GetName(); // Даём Имя.

    std::string startAnswer; // Переменная для принятия ответа о ручном задании сытости и игривости.

    while (true){
        std::cout << "Do you want set the starting values?  Yes\\No " << std::endl;
        std::cout << "Enter your answer: ";
        std::cin >> startAnswer;
        std::cout << std::endl;
        if ((startAnswer == "Yes")){
            pet.SetSatiety();
            pet.SetPlayfulness();
            break;
        } else if ((startAnswer == "No")||(startAnswer == "no")||(startAnswer == "n")){
            break;}
            else {std::cout << "Your answer is incorrect, try again!" << std::endl;}
    } // Цикл запрашивающий- желает ли пользователь ввести значения сытости и игривости
    // Если ответ положительный - пользователь вводит эти значения.
    // Если ответ отрицательный - применяется максимальное значение.
    // Если ответ не корректный - повтор.
    pet.ShowInfo(); // Вывод информации о питомце.

    int choose = 1; // Переменная - выбора вариантов действий и выхода из цикла.

    while (choose){
        std::cout << "MENU" << std::endl;
        std::cout << "You can: " << std::endl;
        std::cout << "Stroke your pet (+5 playfulness) - enter 1" << std::endl;
        std::cout << "Play with your pet (+10 playfulness, -10 satiety ) - enter 2" << std::endl;
        std::cout << "Feed your pet (+20 satiety) - enter 3" << std::endl;
        std::cout << "Let your pet sleep (-10 satiety, -20 playfulness) - enter 4" << std::endl;
        std::cout << "Ask your pet to vote - enter 5" << std::endl;
        std::cout << "Exit - enter 0" << std::endl;
        std::cout << "Enter your answer: " << std::endl;
        std::cin >> choose;
        std::cout << std::endl;
        switch (choose) {
            case 1:
                pet.Stroke();
                break;
            case 2:
                pet.Play();
                break;
            case 3:
                pet.Feed();
                break;
            case 4:
                pet.Sleep();
                break;
            case 5:
                pet.Say();
                break;
            case 0:
                break;
            default:
                std::cout << "You choose incorrect value. Try again! " << std::endl;
        }
    }
}
