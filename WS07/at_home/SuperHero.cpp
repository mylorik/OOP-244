#include <iostream>
#include <cstring>
#include "SuperHero.h"
using namespace std;
using namespace sict;

namespace sict
{
	SuperHero::SuperHero()
	{
		super_name_[0] = '\0';
		super_attack_ = 0;
		bonus_attack_ = 0;
		defend_ = 0;
	}


	SuperHero::SuperHero(const char* name, const int health, const int attack, const int bonus_attack,
	                     const int defend) : Hero(name, health, attack)
	{
		strcpy(super_name_, name);
		super_attack_ = attack;
		bonus_attack_ = bonus_attack;
		defend_ = defend;
	}

	int SuperHero::get_attack_damage() const
	{
		return bonus_attack_ + super_attack_;
	}

	int SuperHero::get_defend_strength() const
	{
		return defend_;
	}

	void super_hero_damage(SuperHero& first, SuperHero& second)
	{
		auto damage_a = second.get_attack_damage() - first.get_defend_strength();
		auto damage_b = first.get_attack_damage() - second.get_defend_strength();

		if (damage_a < 1)
		{
			damage_a = 1;
		}
		if (damage_b < 1)
		{
			damage_b = 1;
		}
		first -= damage_a;
		second -= damage_b;
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second)
	{
		cout << "Super Fight! " << first << " vs " << second << " : ";


		auto first_super_hero = first;
		auto second_super_hero = second;
		const SuperHero* winner = nullptr;

		unsigned int rounds = 0;
		while (first_super_hero.isAlive() && second_super_hero.isAlive() && rounds < 100)
		{
			rounds++;
			super_hero_damage(first_super_hero, second_super_hero);
		}

		if (first_super_hero.isAlive())
			winner = &first;
		else if (second_super_hero.isAlive())
			winner = &second;
		else if (first_super_hero.health_left() > second_super_hero.health_left())
			winner = &first;
		else if (second_super_hero.health_left() > first_super_hero.health_left())
			winner = &second;
		else
			winner = &second;

		cout << "Winner is " << *winner << " in " << rounds << " rounds." << endl;

		return *winner;
	}
}
