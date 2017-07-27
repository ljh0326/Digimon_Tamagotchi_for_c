/*
2017- 05 -23
로그인기능 을 구현하기 위해 있는 함수들의 집합
*/
#include "player.h"

#ifndef __LOGIN_H__
#define __LOGIN_H__

int restriction(char * text); //비밀번호 생성 제약
void makeID();                //아이디 만드는함수
void makePW();                //비밀번호 만드는 함수
void islogin();               //로그인 하는 함수

#endif