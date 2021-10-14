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

enum Actions
        {
    Exit,
    Pet,
    Play,
    Feed,
    Sleep,
    Say,
        };



class Tamagochi{

public:
    // Конструктор по умолчанию устонавливает сытость и игривость на 100.
    Tamagochi (std::string type, std::string answer = "Who am I?", int maxPlayfulness = 100, int maxSatiety = 100, int addPlayfulnessForPet = 5,
              int addPlayfulnessForPlay = 10, int subSatietyForPlay = -10, int addSatietyForFeed = 20, int subSatietyForSleep = -10,
              int subPlayfulnessForSleep = -20);
    // Диструктор, в данном классе нет обращений к внешней памяти, поэтому очищать нечего.
    ~Tamagochi(){};

    void SetName();// Присваиваем имя нашему питомцу.
    void SetSatiety(); // Задаём сытость питомца.
    void SetPlayfulness(); // Задаём игривость питомца.
    void ShowInfo(); // Показывает имя питомца, его текущую сытость и игривость.
    void Pet(); // Погладить (+5 к игривости).
    void Play(); // Поиграть (+10 к игривости, -10 к сыточти).
    void Feed(); // Покормить (+20 к сытости).
    void Sleep(); // Отправить спать (-10 к сытости, -20 к игривости).
    void Say(); // Подать голос
    int GetAddPlayfilnessForPet(){return ADD_PLAYFILNESS_FOR_PET;};
    int GetAddPlayfilnessForPlay(){return ADD_PLAYFILNESS_FOR_PLAY;};
    int GetSubSatietyForPlay(){return SUB_SATIETY_FOR_PLAY;};
    int GetAddSatietyForFeed(){return ADD_SATIETY_FOR_FEED;};
    int GetSubSatietyForSleep(){return SUB_SATIETY_FOR_SLEEP;};
    int GetSubPlayfilnessForSleep(){return SUB_PLAYFILNESS_FOR_SLEEP;};


private:
    const std::string TYPE = "";
    //Pet
    const int ADD_PLAYFILNESS_FOR_PET = 5;
    //Play
    const int ADD_PLAYFILNESS_FOR_PLAY = 10;
    const int SUB_SATIETY_FOR_PLAY = -10;
    //Feed
    const int ADD_SATIETY_FOR_FEED = 20;
    //Sleep
    const int SUB_SATIETY_FOR_SLEEP = -10;
    const int SUB_PLAYFILNESS_FOR_SLEEP = -20;
    //Say
    const std::string ANSWER = "Miau";
    //Name
protected:
    std::string name; // Хранит имя питомца.
    //Parameters
    int playfulness;
    int satiety;
    //Max Parameters
    const int MAX_PLAYFULNESS = 100;
    const int MAX_SATIETY = 100;

    bool CheckMax(const int PARAMETR, const int MAX);
    bool Check(const int PARAMETER,const int SUB); // Функция берёт параметр состояния Сытости или Игривости а также
    // Вычитаемое из неё значение, и производит проверку на то чтобы значение параметра не опустилось ниже 0.
    void MessageNotEnoughPlayfilness(); // Сообщение о недостатке Игривости.
    void MessageNotEnoughSatiety(); // Сообщение о недостатке Сытости.
    void MessageSuccess(); // Сообщение об успехе выполнения действия.

};

void Tamagochi::SetName(){
    std::cout << "Give a name to your pet: ";
    std::cin >> name;
    std::cout << std::endl;
};

void Tamagochi::SetSatiety(){
    while (true)
    {
        std::cout << "Now enter starting value satiety for your pet (0 - 100): ";
        std::cin >> satiety;
        if (CheckMax(satiety,MAX_SATIETY))
        {
            std::cout << std::endl;
            break;
        } else
        {
            std::cout << "----------------------------------------------" << std::endl;
            std::cout << "Your value is not correct" << std::endl;
        }
    }
};

void Tamagochi::SetPlayfulness(){
    while (true)
    {

        std::cout << "Now enter starting value playfulness for your pet (0-100): ";
        std::cin >> playfulness;
        if (CheckMax(playfulness,MAX_PLAYFULNESS))
        {
            std::cout << std::endl;
            break;
        } else
        {
            std::cout << "------------------------------------------------" << std::endl;
            std::cout << "Your value is not correct" << std::endl;
        }
    }
};

void Tamagochi::ShowInfo(){
    std::cout << "The pet: " << name << std::endl;
    std::cout << "Satiety: " << satiety << "\tPlayfulness: " << playfulness <<std::endl;
};

void Tamagochi::Pet(){
    playfulness += ADD_PLAYFILNESS_FOR_PET;
    if (!CheckMax(playfulness,MAX_PLAYFULNESS))
    {
        playfulness = MAX_PLAYFULNESS;
    }
    MessageSuccess();
};

void Tamagochi::Play(){
    if (Check(satiety,SUB_SATIETY_FOR_PLAY))
    {
        playfulness += ADD_PLAYFILNESS_FOR_PLAY;
        satiety += SUB_SATIETY_FOR_PLAY;
        if (!CheckMax(playfulness,MAX_PLAYFULNESS))
        {
            playfulness = MAX_PLAYFULNESS;
        }
        MessageSuccess();
    } else MessageNotEnoughSatiety();
};

void Tamagochi::Feed(){
    satiety += ADD_SATIETY_FOR_FEED;
    if (!CheckMax(satiety,MAX_SATIETY))
    {
        satiety = MAX_SATIETY;
    }
    MessageSuccess();
};

void Tamagochi::Sleep(){
    if (Check(playfulness,SUB_PLAYFILNESS_FOR_SLEEP))
    {
        if (Check(satiety,SUB_SATIETY_FOR_SLEEP))
        {
            playfulness += SUB_PLAYFILNESS_FOR_SLEEP;
            satiety += SUB_SATIETY_FOR_SLEEP;
            MessageSuccess();
        } else MessageNotEnoughSatiety();
    } else MessageNotEnoughPlayfilness();
};

void Tamagochi::Say(){
    std::cout << TYPE << " " << name << " say:\t" << ANSWER << std::endl;
};

bool Tamagochi::Check(const int PARAMETER,const int SUB) {
    int tempParameter = PARAMETER;
    return (tempParameter + SUB) >= 0 ? true : false;
};

bool Tamagochi::CheckMax(const int PARAMETR, const int MAX ){
    int temp = PARAMETR;
    return (temp <= MAX) ? true : false;
};

void Tamagochi::MessageNotEnoughPlayfilness(){
    std::cout << TYPE << " " << name << " say: I can not do it, I need to play!" << std::endl << std::endl; // Питомец грустный.
    ShowInfo();
};

void Tamagochi::MessageNotEnoughSatiety(){
    std::cout << TYPE << " " << name << " say: I can not do it, I need to eat!" << std::endl << std::endl; // Питомец голодный.
    ShowInfo();
};

void Tamagochi::MessageSuccess(){
    std::cout << TYPE << " " << name << " say: I have done it!" << std::endl << std::endl; // Питомец смог выполнить действие
    ShowInfo(); // Вывод информации о питомце.
}

Tamagochi::Tamagochi (std::string type, std::string answer, int maxPlayfulness, int maxSatiety, int addPlayfulnessForPet,
                     int addPlayfulnessForPlay, int subSatietyForPlay, int addSatietyForFeed, int subSatietyForSleep,
                     int subPlayfulnessForSleep)
        :
        TYPE(type),
        ANSWER(answer),
        MAX_PLAYFULNESS(maxPlayfulness),
        MAX_SATIETY(maxSatiety),

        ADD_PLAYFILNESS_FOR_PET(addPlayfulnessForPet),

        ADD_PLAYFILNESS_FOR_PLAY(addPlayfulnessForPlay),
        SUB_SATIETY_FOR_PLAY(subSatietyForPlay),

        ADD_SATIETY_FOR_FEED(addSatietyForFeed),

        SUB_SATIETY_FOR_SLEEP(subSatietyForSleep),
        SUB_PLAYFILNESS_FOR_SLEEP(subPlayfulnessForSleep)

{
    satiety = MAX_SATIETY;
    playfulness = MAX_PLAYFULNESS;
};


class Cat : public Tamagochi
{
public:
    Cat() : Tamagochi("Cat","Miau!" ){};
    ~Cat(){};
};
class Dog : public Tamagochi
{
public:
    Dog() : Tamagochi("Dog","Gav! Gav!",120, 150, 10, 20, -10, 25, -20, -40){};
    ~Dog(){};
};
class Parrot : public Tamagochi
{
public:
    Parrot() : Tamagochi("Parrot", "Give me foood!", 80, 50,)
};
int main() {

    Cat pet;// Заводим нового питомца.

    pet.SetName(); // Даём Имя.

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
        std::cout << "Stroke your pet (" << pet.GetAddPlayfilnessForPet() << " playfulness) - enter 1" << std::endl;
        std::cout << "Play with your pet (" << pet.GetAddPlayfilnessForPlay() << " playfulness, " << pet.GetSubSatietyForPlay() << " satiety ) - enter 2" << std::endl;
        std::cout << "Feed your pet (" << pet.GetAddSatietyForFeed() << " satiety) - enter 3" << std::endl;
        std::cout << "Let your pet sleep (" << pet.GetSubSatietyForSleep() << " satiety, " << pet.GetSubPlayfilnessForSleep() << " playfulness) - enter 4" << std::endl;
        std::cout << "Ask your pet to vote - enter 5" << std::endl;
        std::cout << "Exit - enter 0" << std::endl;
        std::cout << "Enter your answer: " << std::endl;
        std::cin >> choose;
        std::cout << std::endl;
        switch (choose) {
            case Pet:
                pet.Pet();
                break;
            case Play:
                pet.Play();
                break;
            case Feed:
                pet.Feed();
                break;
            case Sleep:
                pet.Sleep();
                break;
            case Say:
                pet.Say();
                break;
            case Exit:
                break;
            default:
                std::cout << "You choose incorrect value. Try again! " << std::endl;
        }
    }
     }