#include <iostream>
#include <Windows.h>
#include "Status.h"
#include "Potion.h"

using namespace std;

void SetHPMP(Status& status, int& HP, int& MP)
{
    while (1)
    {
        cout << "캐릭터 능력치 설정" << endl << endl;

        cout << "HP 설정 : ";
        cin >> HP;
        cout << "MP 설정 : ";
        cin >> MP;

        if (HP <= 50)
        {
            cout << "HP가 너무 낮습니다." << endl;
            Sleep(1000);
            system("cls");
        }
        else if (MP <= 50)
        {
            cout << "MP가 너무 낮습니다." << endl;
            Sleep(1000);
            system("cls");
        }
        else
        {
            status.SetHP(HP);
            status.SetMP(MP);
            break;
        }
    }
}

void SetDamageDefense(Status& status, int& Damage, int& Defense)
{
    while (1)
    {
        system("cls");
        cout << "캐릭터 능력치 설정" << endl << endl;

        cout << "공격력 설정 : ";
        cin >> Damage;
        cout << "방어력 설정 : ";
        cin >> Defense;

        if (Damage <= 0) 
        {
            cout << "공격력이 너무 낮습니다." << endl;
            Sleep(1000);
            system("cls");
        }
        else if (Defense <= 0)
        {
            cout << "방어력이 너무 낮습니다." << endl;
            Sleep(1000);
            system("cls");
        }
        else
        {
            status.SetDamage(Damage);
            status.SetDefense(Defense);
            break;
        }
    }
}

void StatusManagement(int mode, Status& status, Potion& potion, int& exp)
{
    switch (mode)
    {
    case 1:
        system("cls");
        cout << "HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
        status.HPup(20);
        potion.UseHPPotion();
        potion.getHPPotion();
        break;
    case 2:
        system("cls");
		cout << "MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
        status.MPup(20);
        potion.UseMPPotion();
        potion.getMPPotion();
        break;
    case 3:
        system("cls");
        cout << "공격력이 2배 증가되었습니다." << endl;
        status.DamageUp();
        break;
    case 4:
        system("cls");
        cout << "방어력이 2배 증가되었습니다." << endl;
        status.DefenseUp();
        break;
    case 5:
        system("cls");
        status.DisplayInfo();
        potion.DisplayPotionCount();
        break;
    case 6:

        exp += 1;
		int levelupChoice = 0;

        if (exp == 6)
        {
            while (levelupChoice != 1 && levelupChoice != 2)
            {
                system("cls");
                cout << "===================" << endl;
                cout << "Level UP 능력치 선택" << endl;
                cout << "1. 힘 10 UP (HP + 20, 공격력 + 20)" << endl;
                cout << "2. 지능 10 UP  (MP + 20, 공격력 + 20)" << endl;
                cout << "===================" << endl;
                cout << "메뉴 선택 : ";
                cin >> levelupChoice;

                if (levelupChoice < 1 || levelupChoice > 2)
                {
                    cout << "잘못된 선택지입니다. 다시 선택해주세요." << endl;
                }
				else
                {
                    system("cls");
                    switch (levelupChoice)
                    {
                    case 1:
                        cout << "힘이 10 증가하였습니다. (HP + 50, 공격력 + 30)" << endl;
                        status.addStrength(10);
                        break;
                    case 2:
                        cout << "지능이 10 증가하였습니다. (MP + 50, 공격력 + 30)" << endl;
                        status.addIntelligence(10);
                    }
                    potion.addHPPotion(1);
                    potion.addMPPotion(1);
                    status.LevelUp();
                }
            }
            exp = 0;
        }
        else
        {
            system("cls");
            cout << "현재 경험치 : " << exp << " / 6" << endl;
            break;
        }
    }
}

int main()
{
    Status status;
    Potion potion;
    int inputHP, inputMP, inputDamage, inputDefense;
    int mode = -1;
    int exp = 0;

    SetHPMP(status, inputHP, inputMP);
    SetDamageDefense(status, inputDamage, inputDefense);

	system("cls");
    potion.setPotion(5);
    cout << "첫 방문 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl << endl;

    while (mode != 0)
    {
		cout << "===================" << endl;
        cout << "[스탯 관리 시스템]" << endl;
        cout << "1. HP UP" << endl;
        cout << "2. MP UP" << endl;
		cout << "3. 공격력 UP" << endl;
        cout << "4. 방어력 UP" << endl;
        cout << "5. 현재 능력치" << endl;
        cout << "6. Level UP" << endl;
		cout << "0. 종료" << endl;
        cout << "===================" << endl;
        cout << "메뉴 선택 : ";
        cin >> mode;

        StatusManagement(mode, status, potion, exp);
    }

    system("cls");
	cout << endl << "시스템을 종료합니다." << endl;

    return 0;
}


