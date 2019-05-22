//
// Created by zvezdomirov98 on 16.05.19.
//

#ifndef P02_MMORPG_GAMECHARACTER_H
#define P02_MMORPG_GAMECHARACTER_H

class GameCharacter {

public:
    void getAttacked(int opponent_ap);

    char* getName() const;

    void setName(const char *name);

    int getHp() const;

    int getMp() const;

    int getAp() const;

    int getDp() const;

protected:
    char *m_name;
    int m_hp;
    int m_mp;
    int m_ap;
    int m_dp;

    explicit GameCharacter(const char *m_name, int m_hp = 0,
                  int m_mp = 0, int m_ap = 0, int m_dp = 0);

    GameCharacter(const GameCharacter &);

    ~GameCharacter();
};

#endif //P02_MMORPG_GAMECHARACTER_H
