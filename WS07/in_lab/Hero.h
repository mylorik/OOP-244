///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/05 19       
///////////////////////////////////////////////////////////

#ifndef HERO_H
#define HERO_H

#include <iostream>

namespace sict
{
	class Hero
	{
		char m_name_[41]{};
		int m_attack_;
		int m_maximum_health_;
		int m_health_;
	public:
		Hero();
		Hero(const char name[], int maximum_health, int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
		friend void damage(Hero& first, Hero& second);
		int health_left() const;
		void operator-=(int attack_dmg);
	};

	const Hero& operator*(const Hero& first, const Hero& second);
	std::ostream& operator<<(std::ostream&, const Hero&);
}

#endif
