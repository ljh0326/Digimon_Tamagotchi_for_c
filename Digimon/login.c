/*
	login.h 참조 
*/

#include "login.h"
#include "player.h"
#include "tools.h"
#include "screen.h"

#include <stdio.h>
#include <string.h>


#define  MAXSIZE 30
extern Player user;

void makeID()    //아이디 만드는함수
{
	char fileName[MAXSIZE] = " ";
	char ID[MAXSIZE];
	char reID[MAXSIZE]; 
	char temp[MAXSIZE];
	int  Loop = 0;

	FILE * fp;
	clearReadBuffer(); 
	gotoxy(35,6);
	printf("새로운 아이디 입력");

	gotoxy(35,7);
	fflush(stdin);
	gets(ID);


	//아이디 생성후 초기세이브파일생성
	strcpy(temp,ID);
	strcpy(fileName, strcat(temp,".txt"));

	gotoxy(29,28);
	//파읽을 읽어서 NULL값이 아니면, 
	if((fp = fopen(fileName, "r")) != NULL)
	{
		gotoxy(35,28);
		printf("이미 등록된 아이디입니다");
		gotoxy(34,29);
		printf("다른 아이디로 등록해주세요");
		exit(0);
	}

	//파일 읽어서 NULL이면 파일등록
	else
	{
		fp = fopen(fileName, "w+b");

		if (fp == NULL)
		{
			printf("오류가 났습니다. 다시만들어주세요\n");
			exit(0);
		}
		else
		{
			//비밀번호까지 등록하면 뜨도록 변경
			printf("중복된 아이디가 없습니다.");
		}
	}

	Sleep(2000);

	for (Loop = 22; Loop < 35; Loop++)
	{
		gotoxy(23, 4 + Loop);
		printf("                                              ");
	}

	fclose(fp);
	strcpy(user.ID, ID);
}

int restriction(char * text)
{
	int i;

	//flag[0] = 숫자판별 flag[1] = 영문판별
	int flag[2] = {0};

	if(strlen(text)-1 >= 8 && strlen(text)-1 <= 13)
	{
		for(i = 0; i < strlen(text)-1; i++)
		{
			if(isdigit(text[i]))
				flag[0] = 1;
			if(isalpha(text[i]))
				flag[1] = 1;
		}

		if(flag[0] == 1 && flag[1] == 1)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

void makePW()    //비밀번호 만드는 함수
{
	char password[MAXSIZE];
	char repassword[MAXSIZE]; 
	char fileName[MAXSIZE] = " ";
	char temp[MAXSIZE];

	int  Loop = 0;

	FILE * fp;

	strcpy(temp,user.ID);
	strcpy(fileName, strcat(temp,".txt"));

	fp = fopen(fileName, "w+b");

	gotoxy(35, 9);
	printf("비밀번호를 등록합니다.\n");
	while(1)
	{
		gotoxy(31, 29);
		printf("◎비밀번호는 영문, 숫자 포함");
		gotoxy(28, 30);
		printf("최소한 8자리 최대 12자리이어야 합니다.\n");

		gotoxy(35, 11);
		fflush(stdin);
		printf("새로운 비밀번호 입력");
		gotoxy(35, 12);
		printf("                     ");

		fflush(stdin); 
		gotoxy(35,12);
		gets(password);

		if(restriction(password))
		{
			gotoxy(35,11);
			printf("비밀번호 한번더 입력");
			gotoxy(35,12);
			printf("            ");
			fflush(stdin);
			gotoxy(35,12);
			gets(repassword);
			clearScreen();

			if(!strcmp(password,repassword))
			{
				for (Loop = 22; Loop < 35; Loop++)
				{
					gotoxy(23, 4 + Loop);
					printf("                                              ");
				}
				gotoxy(34,32);
				printf("비밀번호가 등록되었습니다.\n");
				strcpy(user.password, password);
				user.isMonster = 0;
				user.credit = 0;
				user.isItem[0] = 0;
				user.isItem[1] = 0;
				user.isItem[2] = 0;
				fwrite(&user, sizeof(user), 1,fp); 
				fclose(fp);
				return;
			}
			else
			{
				for (Loop = 22; Loop < 35; Loop++)
				{
					gotoxy(23, 4 + Loop);
					printf("                                              ");
				}
				gotoxy(34,32);
				printf("비밀번호를 정확히 입력하세요.\n");
				Sleep(1000);
				continue;
			}		
		}
	}
}

void islogin()
{
	FILE * fp;

	char fileName[MAXSIZE] = " ";
	char temp[MAXSIZE];
	char id[MAXSIZE];
	char password[MAXSIZE];

	int count = 1;

	gotoxy(35,6);
	printf("아이디 입력");
	gotoxy(35,7);
	scanf("%s", id);

	strcpy(fileName,strcat(id,".txt"));

	fp = fopen(fileName,"r+b");

	if(fp == NULL)
	{
		gotoxy(35,6);
		printf("아이디가 없습니다");
		gotoxy(35,7);
		printf("아이디를 등록해주세요");
		Sleep(1000);
		signinScreen();
	}

	fread(&user, sizeof(user), 1, fp);

	fclose(fp);

	gotoxy(35,8);
	printf("비밀번호 : ");
	gotoxy(35,9);
	scanf("%s",&password);


		while(strcmp(password,user.password) != 0)
		{
			gotoxy(35,32);
			printf("비밀번호가 %d번 틀렸습니다. ",count);
			gotoxy(35,33);
			printf("다시입력해주세요");
			Sleep(1000);
			clearScreen();
			
			gotoxy(35,8);
			printf("비밀번호 : ");
			gotoxy(35,9);
			scanf("%s",&password);

			count++;

			if(count > 5)
			{
				gotoxy(35,32);
				printf("비밀번호가 5회이상 틀렸습니다.\n");
				gotoxy(35,33);
				printf("프로그램을 종료합니다.\n");
				downClearScreen();
				exit(0);
			}
		}

	gotoxy(35,32);
	printf("로그인에 성공하셨습니다.");
	Sleep(1000);

}