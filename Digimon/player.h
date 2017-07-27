/*
    2017-05-20
	플레이어에 관한 구조체및 관련 함수 헤더
*/

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "monster.h"
#include <stdlib.h>

typedef struct player
{
	char ID[20];
	char password[20];
	int credit;        //상점에서 아이템 살 수 있음
	int isMonster;     //몬스터가 있는지 없는지 falg
	int isItem[2];     //진화에 필요한 아이템 있는지 없는지
	monster monster;   //플레이어하나당 몬스터 한마리
}Player;

void init();

#endif