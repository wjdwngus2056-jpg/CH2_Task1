#pragma once

using namespace std;

class Status
{
private:
	int level = 1;
	int status[4] = {};
	int status2[2] = {};
public:
	Status() {}

	void SetHP(int InputHP);
	void SetMP(int InputMP);
	void SetDamage(int InputDamage);
	void SetDefense(int InputDefense);

	void addStrength(int increase);
	void addIntelligence(int increase);
	void LevelUp();
	void HPup(int increase);
	void MPup(int increase);
	void DamageUp();
	void DefenseUp();

	void DisplayInfo();

};