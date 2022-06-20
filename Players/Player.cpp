#include "Player.h"
#include "utilities.h"

Player::Player(const char* name,const char* job, int maxHP, int force) {
    Player::m_name = name;
    Player::m_job = job;
    Player::m_level = 1;
    Player::m_force = force <= 0 ? 5 : force;
    Player::m_maxHP = maxHP <= 0 ? 100 : maxHP;
    Player::m_HP = maxHP <= 0 ? 100 : maxHP;
    Player::m_coins = 0;
}

Player::Player() {
    Player::m_name = "";
    Player::m_job = "";
    Player::m_level = 1;
    Player::m_force = 0;
    Player::m_maxHP = 0;
    Player::m_HP = 0;
    Player::m_coins = 0;
}

void Player::levelUp() {
    if (m_level < 10) {
        m_level++;
    }
}

int Player::getLevel() const {
    return m_level;
}

void Player::buff(int amount) {
    if(amount <= 0)
        return;
    m_force += amount;
}

void Player::heal(int amount) {
    if(amount <= 0)
        return;
    if(m_HP + amount >= m_maxHP)
    {
        m_HP = m_maxHP;
        return;
    }
    m_HP += amount;
}

void Player::damage(int amount) {
    if(amount <= 0)
        return;
    if (m_HP > amount) {
        m_HP -= amount;
        return;
    }
    m_HP = 0;
}

bool Player::isKnockedOut() const{
    return m_HP == 0;
}

void Player::addCoins(int amount) {
    if(amount <= 0)
        return;
    m_coins += amount;
}

bool Player::pay(int amount) {
    if(amount <= 0)
        return true;
    if(m_coins - amount < 0)
        return false;
    m_coins -= amount;
    return true;
}

int Player::getAttackStrength() const{
    return (m_force + m_level);
}

void Player::printInfo(ostream &os) const {
    printPlayerDetails(os,m_name,m_job,m_level,m_force,m_HP,m_coins);
}

ostream& operator<<(ostream& os, const Player& player)
{
    player.printInfo(os);
    return os;
}


String Player::getName () const{
    return m_name;
}

int Player::getCoins() const{
    return m_coins;
}

String Player::getJob() const{
    return m_job;
}

int Player::getHP() const {
    return m_HP;
}

bool Player::isPlayerInGame() const {
    if(isKnockedOut() || getLevel() >= 10)
        return false;
    return true;
}