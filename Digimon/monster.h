/*
    2017-05-20
	디지몬구조체 및 디지몬과 관련된 함수 헤더 
	몬스터의 최대 도트수는 y=13, x=50정도이다.
*/

#ifndef __MONSTER_H__
#define __MONSTER_H__

typedef struct monster
{
	char name[20];     //이름
	
	int power;          //다른 사람과 배틀대비
	int hungry;         //배고프면 죽음, 힘도 줄어듬
	int stamina;        //스태미나 다쓰면 훈련못함, 먹을걸로 채움
	int weight;         //무게 저체중이거나 과체중이면 패널티
	int LV;             //진화 단계를 의미 레벨에따라 모습변경
	int evolution_gage[4]; //일정정도를 채워야 진화가능 //배열
	int current_evolution[4]; //현재 경험치
}monster;

char monsterModel[][15][15];              //몬스터들의 도트 모음배열
char monsterModel2[][15][15];             //입벌린 몬스터 도트 모음       
char foodModel[][8][8];					  //음식 도트모음 배열
char itemModel[][8][8];                   //상점 아이템 도트
void showMonster(char blockInfo[][15]);   //몬스터를 출력해주는 함수
void showModel(char blockInfo[][8]);       //음식을 출력해주는 함수
void monsterInit();                       //몬스터 스테이터스 초기화함수


#endif