///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/05 19       
///////////////////////////////////////////////////////////

#ifndef SUPERHERO_H
#define SUPERHERO_H

#include "Hero.h"

namespace sict
{
	class SuperHero : public Hero
	{
		int super_attack_;
		int bonus_attack_;
		int defend_;
		char super_name_[41]{};

	public:
		SuperHero();
		SuperHero(const char* name, int health, int attack, int bonus_attack, int defend);

		int get_attack_damage() const;
		int get_defend_strength() const;
	};

	void super_hero_damage(SuperHero& first, SuperHero& second);
	const SuperHero& operator*(const SuperHero&, const SuperHero&);
}
#endif
