//
// Created by zvezdomirov98 on 12.05.19.
//

#ifndef P02_MMORPG_GAMECHARACTER_H
#define P02_MMORPG_GAMECHARACTER_H

class GameCharacter {

public:
    void getAttacked(int);

    char *getName() const;

    int getHp() const;

    int getMp() const;

    int getAp() const;

    int getDp() const;

protected:
    GameCharacter(char *name, int hp, int mp, int ap, int dp);

private:
    char *name;
    int hp;
    int mp;
    int ap;
    int dp;
};

void GameCharacter::getAttacked(int opponentAP) {
    if (opponentAP - dp < 0) {
        return;
    }
    hp -= (opponentAP - dp);
}

GameCharacter::GameCharacter(
        char *name, int hp,
        int mp, int ap, int dp)
        : name(name), hp(hp), mp(mp), ap(ap), dp(dp) {}

char *GameCharacter::getName() const {
    return name;
}

int GameCharacter::getHp() const {
    return hp;
}

int GameCharacter::getMp() const {
    return mp;
}

int GameCharacter::getAp() const {
    return ap;
}

int GameCharacter::getDp() const {
    return dp;
}

#endif //P02_MMORPG_GAMECHARACTER_H
