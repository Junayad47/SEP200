
/*

Name: Junayad Bin Forhad
E-mail: jbin-forhad@myseneca.ca
Student ID: 160158218
Date: 21/07/2022

*/

#include "PlayerBase.cpp"

template <typename T>
class PlayerAdult : public PlayerBase<T>
{
private:
    std::vector<T> attackCards;

public:
    PlayerAdult();
    PlayerAdult(std::string name);
    PlayerAdult(const PlayerAdult &player);
    PlayerAdult &operator=(const PlayerAdult &player);
    ~PlayerAdult();
    void addAttackCards(int cards);
    void addAttackCard();
    T sumAttackCards() const;
    T sumAllCards() const;
    void cleanUp();
};