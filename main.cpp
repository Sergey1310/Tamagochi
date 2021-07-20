#include <iostream>
#include <string>
class Tamagochi{

public:
    void getName(){
        std::cout << "Give a name to your pet: ";
        std::cin >> name;
        std::cout << std::endl;
    };
    void setSatiety(){
        std::cout << "Now enter starting value satiety for your pet: ";
        std::cin >> satiety;
        std::cout << std::endl;
    };
    void setPlayfulness(){
        std::cout << "Now enter starting value playfulness for your pet: ";
        std::cin >> playfulness;
        std::cout << std::endl;
    };
    void showInfo(){
        std::cout << "The pet: " << name << std::endl;
        std::cout << "Satiety: " << satiety << "\tPlayfulness: " << playfulness <<std::endl;
    };
    void stroke(){
        playfulness +=5;
        limits();
        success();
        showInfo();
    };
    void play(){
        checkSatiety = satiety;
        checkSatiety -= 10;
        if (checkSatiety < 0){
            check();
            showInfo();
            return;
        } else{
            satiety = checkSatiety;
            playfulness += 10;
            success();
            limits();
            showInfo();
            return;
        }

    };
    void feed(){
        satiety += 20;
        limits();
        success();
        showInfo();
    };
    void sleep(){
        checkPlayfulness = playfulness;
        checkSatiety = satiety;
        checkPlayfulness -= 20;
        checkSatiety -= 10;
        if (checkSatiety < 0)
        {
            check();
            return;
        } else if (checkPlayfulness < 0){
            check();
            showInfo();
            return;
        }else{
            satiety = checkSatiety;
            playfulness = checkPlayfulness;
            success();
            limits();
            showInfo();
            return;
        }
    };
    void say(){
        std::string say;
        std::cout << "Enter what " << name << " have to say: ";
        std::cin >> say;
        std::cout << std::endl << name << " say: " << say << std::endl;
        success();
        showInfo();
    };


private:
    void check(){
        if ((checkSatiety<0)&&(checkPlayfulness<0)){
            std::cout << name << " say: I can not do it, I need to eat and play!" << std::endl << std::endl;
            checkSatiety = 1;
            checkPlayfulness = 1;
        } else if ((checkSatiety<0)){
            std::cout << name << " say: I can not do it, I need to eat!" << std::endl << std::endl;
            checkSatiety = 1;
        } else if (checkPlayfulness<0){
            std::cout << name << " say: I can not do it, I need to play!" << std::endl << std::endl;
            checkPlayfulness = 1;
        }
    };
    void limits(){
        if(satiety>100) satiety = 100;
        if(playfulness>100) playfulness = 100;
    };
    void success(){
        std::cout << std::endl << name << " say: I have done it! " << std::endl << std::endl;
    };
    std::string name;
    int satiety = 100;
    int playfulness = 100;
    int checkSatiety = 0;
    int checkPlayfulness = 0;

};


int main() {
    Tamagochi pet;
    pet.getName();
    std::string startAnswer;
    while (true){
    std::cout << "Do you want set the starting values?  Yes\\No " << std::endl;
    std::cout << "Enter your answer: ";
    std::cin >> startAnswer;
    std::cout << std::endl;
    if ((startAnswer == "Yes")||(startAnswer == "yes")||(startAnswer == "y")){
        pet.setSatiety();
        pet.setPlayfulness();
        break;
    } else if ((startAnswer == "No")||(startAnswer == "no")||(startAnswer == "n")){break;}
    else {std::cout << "Your answer is incorrect, try again!" << std::endl;}
    }
    pet.showInfo();
    int choose = 1;
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
                pet.stroke();
                break;
            case 2:
                pet.play();
                break;
            case 3:
                pet.feed();
                break;
            case 4:
                pet.sleep();
                break;
            case 5:
                pet.say();
                break;
            default:
                std::cout << "You choose incorrect value. Try again! " << std::endl;
        }
    }
}
