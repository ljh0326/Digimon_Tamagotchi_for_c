
/*
	2017-05-20
	UI구성등 다양한 곳에 이용할 도구함수를 모아놓은 헤더이다.
*/
#ifndef __TOOL_H__
#define __TOOL_H__


#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <MMSystem.h>
#include <time.h>
#pragma comment(lib,"Winmm.lib")

// 색상 정의
#define BLACK	0
#define BLUE1	1
#define GREEN1	2
#define CYAN1	3
#define RED1	4
#define MAGENTA1 5
#define YELLOW1	6
#define GRAY1	7
#define GRAY2	8
#define BLUE2	9
#define GREEN2	10
#define CYAN2	11
#define RED2	12
#define MAGENTA2 13
#define YELLOW2	14
#define WHITE	15


void removeCursor(void);                    // 커서를 안보이게 한다
void gotoxy(int x, int y);                  //내가 원하는 위치로 커서 이동
void textcolor(int fg_color, int bg_color); //원하는 배경색이랑 글자수로 바꿀 수 있다.
void cls(int bg_color, int text_color);     // 화면 지우기고 원하는 배경색으로 설정한다.
COORD getxy();                               //커서위치 얻어오는함수
void clearReadBuffer();                    //버퍼클리어 함수

#endif