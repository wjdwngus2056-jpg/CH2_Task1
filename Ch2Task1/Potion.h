#pragma once

class Potion
{
private:
	int countHPP = 0;
	int countMPP = 0;
public:
	Potion() {}

	void DisplayPotionCount();
	int getHPPotion();
	int getMPPotion();

	void setPotion(int count);
	void addHPPotion(int count);
	void addMPPotion(int count);
	void UseHPPotion();
	void UseMPPotion();
};