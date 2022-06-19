//
// Created by michalmaya on 10/05/2022.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


#include "string"
#include "ostream"
#include "utilities.h"

typedef std::string String;
typedef std::ostream ostream;

class Player {
public:
    explicit Player (const char* name ="",const char* job = "", int maxHP=100, int force=5);
    virtual ~Player () {} ;
    Player (const Player& player) = default;
    Player& operator= (const Player& other) = default;
    void levelUp();
    int getLevel() const;
    void buff(int amount);
    void damage(int amount);
    bool isKnockedOut() const;
    bool pay (int amount);
    String getName () const;
    int getCoins() const;
    String getJob() const;
    virtual void heal(int amount);
    virtual void addCoins (int amount);
    virtual int getAttackStrength () const;
    void printInfo(ostream& os) const;
    int getHP() const;
    bool isPlayerInGame() const;

    friend ostream& operator<<(ostream& os, const Player& player);


private:
    String m_name;
    String m_job;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

};

#endif //EX2_Player_H