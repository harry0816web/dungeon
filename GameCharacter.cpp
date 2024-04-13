#include "GameCharacter.h"

// constructor
GameCharacter::GameCharacter(){};
GameCharacter::GameCharacter(string n, int maxHp, int curHp, int atk, int def) : name(n), maxHealth(maxHp), currentHealth(curHp), attack(atk), defense(def){};

// states
bool GameCharacter::checkIsDead()
{
    return currentHealth <= 0;
}
int GameCharacter::takeDamage(int damage)
{
    return currentHealth -= damage;
}

// setter
void GameCharacter::setMaxHealth(int health) { maxHealth = health; }
void GameCharacter::setCurrentHealth(int health) { currentHealth = health; }
void GameCharacter::setAttack(int atk) { attack = atk; }
void GameCharacter::setDefense(int def) { defense = def; }

// getter
int GameCharacter::getMaxHealth() const { return maxHealth; }
int GameCharacter::getCurrentHealth() const { return currentHealth; }
int GameCharacter::getAttack() const { return attack; }
int GameCharacter::getDefense() const { return defense; }

// func....