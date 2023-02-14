
/*

Name: Junayad Bin Forhad
E-mail: jbin-forhad@myseneca.ca
Student ID: 160158218
Date: 21/07/2022

*/

#include "PlayerBase.cpp"

// PlayerYouth is a subclass of PlayerBase

template <typename T>
class PlayerYouth : public PlayerBase<T>
{
private:
    std::vector<T> attackCards;

public:
    PlayerYouth();
    PlayerYouth(std::string name);
    PlayerYouth(const PlayerYouth &player);
    PlayerYouth &operator=(const PlayerYouth &player);
    ~PlayerYouth();
    void addAttackCards(int cards);
    void addAttackCard();
    T sumAttackCards() const;
    T sumAllCards() const;
    void cleanUp();
};
