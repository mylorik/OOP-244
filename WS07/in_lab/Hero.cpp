///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/05 19       
///////////////////////////////////////////////////////////

#include <cstring>
#include <iostream>
#include "Hero.h"


const auto max_rounds = 100;

namespace sict
{
	Hero::Hero()
	{
		m_name_[0] = '\0';
		m_health_ = 0;
		m_maximum_health_ = 0;
		m_attack_ = 0;
	}

	Hero::Hero(const char name[], const int maximum_health, const int attack)
	{
		strcpy(m_name_, name);
		m_health_ = maximum_health;
		m_maximum_health_ = maximum_health;
		m_attack_ = attack;
	}

	bool Hero::isAlive() const
	{
		return m_health_ > 0;
	}

	int Hero::attackStrength() const
	{
		return m_attack_;
	}

	std::ostream& operator<<(std::ostream& os, const Hero& hero)
	{
		os << hero.m_name_;
		return os;
	}

	// I feel that this is the better way of doing this than it asks as to do in the book
	// Actually, I would overload "-=" passing Heros parameters, so it would be 1 function, not 2.

	void damage(Hero& first, Hero& second)
	{
		if (first.m_health_ > 0 && second.m_health_ > 0)
		{
			first -= second.attackStrength();
			second -= first.attackStrength();
		}
		if (first.m_health_ <= 0)
			first.m_health_ = 0;
		if (second.m_health_ <= 0)
			second.m_health_ = 0;
	}

	// This is also made to check, if both heroes are alive, see, who won by max health
	int Hero::health_left() const
	{
		return m_health_;
	}

	void Hero::operator-=(const int attack_dmg)
	{
		auto dmg = 0;
		if (attack_dmg > 0)
			dmg = attack_dmg;
		m_health_ -= dmg;
	}

	const Hero& operator*(const Hero& first, const Hero& second)
	{
		std::cout << "Ancient Battle! " << first << " vs " << second << " : ";
		auto first_hero = first;
		auto second_hero = second;
		const Hero* winner = nullptr;
		auto rounds = 0;

		while (first_hero.isAlive() && second_hero.isAlive() && rounds < max_rounds)
		{
			rounds++;
			damage(first_hero, second_hero);
		}

		if (first_hero.isAlive())
			winner = &first;
		else if (second_hero.isAlive())
			winner = &second;
		else if (first_hero.health_left() > second_hero.health_left())
			winner = &first;
		else if (second_hero.health_left() > first_hero.health_left())
			winner = &second;
		else
			winner = &second;

		// It's still not perfect. there is still a possibility of equal battle, in that case, the Second hero wins 
		std::cout << "Winner is " << *winner << " in " << rounds << " rounds." << std::endl;
		return *winner;
	}
}
