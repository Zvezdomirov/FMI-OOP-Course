//
// Created by zvezdomirov98 on 16.05.19.
//
#include "GameCharacter.h"
#include <cstring>

GameCharacter::GameCharacter(const char *name,
                             int hp, int mp, int ap, int dp) :
        m_hp(hp), m_mp(mp), m_ap(ap), m_dp(dp), m_name(nullptr) {
    setName(name);
}

GameCharacter::~GameCharacter() {
    delete m_name;
}

char *GameCharacter::getName() const {
    return m_name;
}

void GameCharacter::setName(const char *name) {
    delete m_name;
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
}

int GameCharacter::getHp() const {
    return m_hp;
}

int GameCharacter::getMp() const {
    return m_mp;
}

int GameCharacter::getAp() const {
    return m_ap;
}

int GameCharacter::getDp() const {
    return m_dp;
}

GameCharacter::GameCharacter(const GameCharacter &copy) {
    m_name = nullptr;
    m_hp = copy.m_hp;
    m_mp = copy.m_mp;
    m_ap = copy.m_ap;
    m_dp = copy.m_dp;
    setName(copy.m_name);
}

void GameCharacter::getAttacked(int opponent_ap) {
    if (m_dp >= opponent_ap) {
        return;
    } else {
        m_hp -= (opponent_ap - m_dp);
    }
}
