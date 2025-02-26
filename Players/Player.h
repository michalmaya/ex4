//
// Created by michalmaya on 10/05/2022.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


#include "string"
#include "ostream"

typedef std::string String;
typedef std::ostream ostream;

class Player {
public:
    explicit Player (const char* name, const char* job, int order, int maxHP=100, int force=5);
    Player() = default;
    virtual ~Player () = default;
    Player (const Player& player) = default;
    Player& operator= (const Player& other) = default;

    void levelUp();
    int getLevel() const;

    void weaken(int amount);
    void buff(int amount);

    void damage(int amount);
    bool isKnockedOut() const;
    bool isWon() const;

    bool pay (int amount);

    String getName () const;
    int getCoins() const;
    String getJob() const;
    int getOrder() const;
    int getHP() const;

    virtual void heal(int amount);
    virtual void addCoins (int amount);
    virtual int getAttackStrength () const;

    void printInfo(ostream& os) const;



    friend ostream& operator<<(ostream& os, const Player& player);


private:
    String m_name;
    String m_job;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
    int m_order;

};

#endif //EX2_Player_H