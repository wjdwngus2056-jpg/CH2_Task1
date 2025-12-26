#include <iostream>
#include "Potion.h"

using namespace std;

void Potion::DisplayPotionCount()
{
	cout << "HP 포션 개수 : " << countHPP << " / 5" << endl;
	cout << "MP 포션 개수 : " << countMPP << " / 5" << endl;
}

int Potion::getHPPotion()
{
	cout << "현재 HP 포션 수 : " << countHPP << endl;
	return countHPP;
}

int Potion::getMPPotion()
{
	cout << "현재 MP 포션 수 : " << countMPP << endl;
	return countMPP;
}

void Potion::setPotion(int count)
{
	countHPP = count;
	countMPP = count;
}

void Potion::addHPPotion(int count)
{
	if (countHPP >= 5)
	{
		cout << "HP 포션 지급 불가 : 포션이 가득 찼습니다." << endl;
	}
	else
	{
		countHPP += count;
		cout << "HP 포션이 " << count << "개 지급됩니다." << endl;
	}
}

void Potion::addMPPotion(int count)
{
	if (countMPP >= 5)
	{
		cout << "MP 포션 지급 불가 : 포션이 가득 찼습니다." << endl;
	}
	else
	{
		countMPP += count;
		cout << "MP 포션이 " << count << "개 지급됩니다." << endl;
	}
}

void Potion::UseHPPotion()
{
	if (countHPP > 0)
	{
		countHPP -= 1;
	}
	else
	{
		cout << "HP 포션이 없습니다." << endl;
	}
}

void Potion::UseMPPotion()
{
	if (countMPP > 0)
	{
		countMPP -= 1;
	}
	else
	{
		cout << "MP 포션이 없습니다." << endl;
	}
}