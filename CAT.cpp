#include <iostream>

class Cat{

    private:
    int lives {2};

    public:
    Cat() : lives() { lives = 10;}


    void reportLives()
    {
        std::cout << "Cat has ";
        std::cout << lives;
        std::cout << " lives" << std::endl;
    }

    void loseLife()
    {
        lives = lives - 1;
    }

    Cat& operator+=(int increment)
    {
        lives = lives + increment;
        return *this;
    }
};

int main(){

Cat kittie;
(kittie += 1) += 4;

std::cout << "hello world" << std::endl;
kittie.reportLives();

return 0;
}