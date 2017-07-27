/*
    2017-05-20
	UI구성등 다양한 곳에 이용할 스크린에 관련된 함수들을 모아놓은 헤더이다.
*/


#ifndef __SCREEN_H__
#define __SCREEN_H__

int mainScreen();		 //메인 화면을(닌텐도) 찍는 함수
int gameOn();	    	 //화면이 켜지는 효과를 만든는 함수
int shutDown();		     //화면이 꺼지는 효과를 만드는 함수
int loginSelect();		 //아이디등록, 로그인 선택화면 
int introScreen();		 //인트로 화면
int playScreen();		 //플레이 화면 로그인이 되어있고 몬스터가있어야 메뉴선택 가능
int signinScreen();		 //아이디 등록 스크린
int loginScreen();		 //로그인화면 스크린
int playScreen();		 //게임화면
int selectMenu();		 //메뉴 선택
int saveScreen();		 //저장 화면
int traningMenuScreen(); //훈련 화면
int storeScreen();       //상점 화면
int foodSelectScreen();  //음식 선택화면
int eatBeef();           //고기먹는영상
int eatPeel();           //약먹는영상
int evolution1();        //진화영상들
int evolution2();
int evolution3();
int hintScreen();
int monsterMove();       //몬스터가 지속적으로 움직이는 영상 쓰레드필요 다음에 구현


void clearScreen();      // 게임 화면 클리어
void upClearScreen();    // 게임 화면 위 클리어
void downClearScreen();  // 아래 게임 화면 클리어

#endif