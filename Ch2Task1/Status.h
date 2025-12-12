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

	void SetHP(int InputHP)
	{
		status[0] = InputHP;
	}

	void SetMP(int InputMP)
	{
		status[1] = InputMP;
	}

	void SetDamage(int InputDamage)
	{
		status[2] = InputDamage;
	}

	void SetDefense(int InputDefense)
	{
		status[3] = InputDefense;
	}

	void addStrength(int increase)
	{
		status2[0] += increase;
		status[0] += increase * 5;
		status[2] += increase * 3;
	}

	void addIntelligence(int increase)
	{
		status2[1] += increase;
		status[1] += increase * 5;
		status[2] += increase * 3;
	}
	
	void LevelUp()
	{
		cout << "Level UP!" << endl;
		level += 1;
	}

	void HPup(int increase)
	{
		status[0] += increase;
	}

	void MPup(int increase)
	{
		status[1] += increase;
	}

	void DamageUp()
	{
		status[2] *= 2;
	}

	void DefenseUp()
	{
		status[3] *= 2;
	}

	void DisplayInfo()
	{
		cout << "===================" << endl;
		cout << "[상태창]" << endl;
		cout << "===================" << endl;
		cout << "Level : " << level << endl;
		cout << "===================" << endl;
		cout << "HP : " << status[0] << endl;
		cout << "MP : " << status[1] << endl;
		cout << "공격력 : " << status[2] << endl;
		cout << "방어력 : " << status[3] << endl;
		cout << "힘 : " << status2[0] << " (스탯 당 HP 5, 공격력 3)" << endl;
		cout << "지능 : " << status2[1] << " (스탯 당 MP 5, 공격력 3)" << endl;
	}
};