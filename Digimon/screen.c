/*
2017-05-26
화면 출력함수들 집합
screen.h 참고 
*/


#include "tools.h"
#include "screen.h"
#include "login.h"
#include "training.h"

#define MAXSIZE 20

extern Player user;



void clearScreen()
{
	int Loop = 0;
	int Pass = 0;

	textcolor(BLACK,WHITE);
	for (Loop = 0; Loop < 37; Loop++)
	{
		if (Pass == 0 && Loop > 14)
		{
			Pass = 1;
			Loop = 22;
		}
		gotoxy(23, 3 + Loop);
		printf("                                              ");
	}
}

void upClearScreen()
{
	int Loop = 0;

	for (Loop = 0; Loop < 15; Loop++)
	{
		gotoxy(23, 3 + Loop);
		printf("                                              ");
	}
}
void downClearScreen()
{
	int Loop = 0;
	for (Loop = 22; Loop < 36; Loop++)
	{
		gotoxy(23, 3 + Loop);
		printf("                                              ");
	}
}

int mainScreen()
{
	int Loop = 0;
	textcolor(WHITE,BLACK);
	system("mode con: cols=95 lines=44");

	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                                                                                          ┃\n");
	printf("┃                   ┏━━━━━━━━━━━━━━━━━━━━━━━┓                     ┃\n");
	printf("┃                   ┃                                              ┃                     ┃\n");
	printf("┃                   ┃                                              ┃                     ┃\n");
	printf("┃                   ┃                                              ┃                     ┃\n");
	printf("┃                   ┃                                              ┃                     ┃\n");
	printf("┃                   ┃                                              ┃                     ┃\n");
	printf("┃     ⊙  ⊙  ⊙    ┃                                              ┃     ⊙  ⊙  ⊙      ┃\n");
	printf("┃                   ┃                                              ┃                     ┃\n");
	printf("┃     ⊙  ⊙  ⊙    ┃                                              ┃     ⊙  ⊙  ⊙      ┃\n");
	printf("┃                   ┃                                              ┃                     ┃\n");
	printf("┃                   ┃                                              ┃                     ┃\n");
	printf("┃                   ┃                                              ┃                     ┃\n");
	printf("┃                   ┃                                              ┃                     ┃\n");
	printf("┃                   ┃                                              ┃                     ┃\n");
	printf("┃                   ┃                                              ┃                     ┃\n");
	printf("┃                   ┃                                              ┃                     ┃\n");
	printf("┃                   ┗━━━━━━━━━━━━━━━━━━━━━━━┛                     ┃\n");
	printf("┃                                                                                          ┃\n");
	printf("┣━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━┫\n");
	printf("┃   ○   ┃                          ON : O   OFF : F                            ┃ |||||| ┃\n");
	printf("┣━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━┫\n");
	printf("┃                                                                                          ┃\n");
	printf("┃                   ┏━━━━━━━━━━━━━━━━━━━━━━━┓                     ┃\n");
	printf("┃                   ┃                                              ┃                     ┃\n");
	printf("┃                   ┃                                              ┃                     ┃\n");
	printf("┃                   ┃                                              ┃        ┏━┓       ┃\n");
	printf("┃      ┏━┓       ┃                                              ┃        ┃△┃       ┃\n");
	printf("┃      ┃↑┃       ┃                                              ┃        ┗━┛       ┃\n");
	printf("┃      ┃  ┃       ┃                                              ┃  ┏━┓      ┏━┓ ┃\n");
	printf("┃┏━━┛  ┗━━┓ ┃                                              ┃  ┃□┃      ┃○┃ ┃\n");
	printf("┃┃←          →┃ ┃                                              ┃  ┗━┛      ┗━┛ ┃\n");
	printf("┃┗━━┓  ┏━━┛ ┃                                              ┃        ┏━┓       ┃\n");
	printf("┃      ┃  ┃       ┃                                              ┃        ┃Ⅹ┃       ┃\n");
	printf("┃      ┃↓┃       ┃                                              ┃        ┗━┛       ┃\n");
	printf("┃      ┗━┛       ┃                                              ┃                     ┃\n");
	printf("┃                   ┃                                              ┃                     ┃\n");
	printf("┃                   ┃                                              ┃● start             ┃\n");
	printf("┃                   ┃                                              ┃● select            ┃\n");
	printf("┃                   ┗━━━━━━━━━━━━━━━━━━━━━━━┛                     ┃\n");
	printf("┃                                                                                          ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

	while (1)
	{
		if (GetAsyncKeyState(0x4F) && 0x0001 == TRUE)
		{
			sndPlaySoundA("music\\on.wav", SND_ASYNC | SND_NODEFAULT);
			textcolor(YELLOW2,BLACK);
			gotoxy(5, 21);
			printf("●");

			for (Loop = 0; Loop < 6; Loop++)
			{
				gotoxy(85 + Loop, 21);
				printf("|");
			}

			textcolor(GRAY1,BLACK);
			gameOn();
		}
		else if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
			shutDown();
	}

	return 0;
}

int gameOn()
{
	int Loop = 0;

	clearScreen();
	Sleep(1000);

	for (Loop = 0; Loop < 5; Loop++)
	{
		switch (Loop)
		{
		case 0:
			gotoxy(41, 8);
			printf("환");
			Sleep(200);
			gotoxy(41, 8);
			printf("  ");
			gotoxy(41, 9);
			printf("환");
			Sleep(200);
			gotoxy(41, 9);
			printf("  ");
			gotoxy(41, 10);
			printf("환");
			break;
		case 1:
			gotoxy(43, 8);
			printf("영");
			Sleep(200);
			gotoxy(43, 8);
			printf("  ");
			gotoxy(43, 9);
			printf("영");
			Sleep(200);
			gotoxy(43, 9);
			printf("  ");
			gotoxy(43, 10);
			printf("영");
			break;
		case 2:
			gotoxy(45, 8);
			printf("합");
			Sleep(200);
			gotoxy(45, 8);
			printf("  ");
			gotoxy(45, 9);
			printf("합");
			Sleep(200);
			gotoxy(45, 9);
			printf("  ");
			gotoxy(45, 10);
			printf("합");
			break;
		case 3:
			gotoxy(47, 8);
			printf("니");
			Sleep(200);
			gotoxy(47, 8);
			printf("  ");
			gotoxy(47, 9);
			printf("니");
			Sleep(200);
			gotoxy(47, 9);
			printf("  ");
			gotoxy(47, 10);
			printf("니");
			break;
		case 4:
			gotoxy(49, 8);
			printf("다");
			Sleep(200);
			gotoxy(49, 8);
			printf("  ");
			gotoxy(49, 9);
			printf("다");
			Sleep(200);
			gotoxy(49, 9);
			printf("  ");
			gotoxy(49, 10);
			printf("다");
			break;
		}
	}

	Sleep(500);

	while (1)
	{
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			break;
		}
		else if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			shutDown();
		}
		else
		{
			gotoxy(32, 32);
			printf("계속하려면 '○'를 눌러주세요");
			Sleep(500);
			gotoxy(32, 32);
			printf("                               ");
			Sleep(500);
		}
	}

	for (Loop = 0; Loop < 5; Loop++)
	{
		switch (Loop)
		{
		case 0:
			gotoxy(41, 10);
			printf("  ");
			gotoxy(41, 9);
			printf("환");
			Sleep(100);
			gotoxy(41, 9);
			printf("  ");
			gotoxy(41, 8);
			printf("환");
			Sleep(100);
			gotoxy(41, 8);
			printf("  ");
			break;
		case 1:
			gotoxy(43, 10);
			printf("  ");
			gotoxy(43, 9);
			printf("영");
			Sleep(100);
			gotoxy(43, 9);
			printf("  ");
			gotoxy(43, 8);
			printf("영");
			Sleep(100);
			gotoxy(43, 8);
			printf("  ");
			break;
		case 2:
			gotoxy(45, 10);
			printf("  ");
			gotoxy(45, 9);
			printf("합");
			Sleep(100);
			gotoxy(45, 9);
			printf("  ");
			gotoxy(45, 8);
			printf("합");
			Sleep(100);
			gotoxy(45, 8);
			printf("  ");
			break;
		case 3:
			gotoxy(47, 10);
			printf("  ");
			gotoxy(47, 9);
			printf("니");
			Sleep(100);
			gotoxy(47, 9);
			printf("  ");
			gotoxy(47, 8);
			printf("니");
			Sleep(100);
			gotoxy(47, 8);
			printf("  ");
			break;
		case 4:
			gotoxy(49, 10);
			printf("  ");
			gotoxy(49, 9);
			printf("다");
			Sleep(100);
			gotoxy(49, 9);
			printf("  ");
			gotoxy(49, 8);
			printf("다");
			Sleep(100);
			gotoxy(49, 8);
			printf("  ");
			break;
		}
	}

	clearScreen();
	Sleep(500);
	introScreen();

	return 0;
}

int shutDown()
{
	int Loop = 0;
	int Pass = 0;

	textcolor(WHITE,0);
	gotoxy(5, 21);
	printf("○");
	for (Loop = 0; Loop < 6; Loop++)
	{
		gotoxy(85 + Loop, 21);
		printf("|");
	}
	textcolor(WHITE,0);
	for (Loop = 0; Loop < 37; Loop++)
	{
		if (Pass == 0 && Loop > 14)
		{
			Pass = 1;
			Loop = 22;
		}
		gotoxy(23, 3 + Loop);
		printf("                                              ");
	}
	textcolor(WHITE,7);
	gotoxy(0, 43);
	exit(1);

	return 0;
}

int introScreen()
{
	int Loop = 0;
	int Pass = 0;
	srand(time(NULL));

	textcolor(BLACK,WHITE);

	clearScreen();

	Pass = 0;

	sndPlaySoundA("music\\main_1.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);

	gotoxy(27, 6);
	printf("┏━━━┓");
	gotoxy(27, 7);
	printf("┗┓┏┓┃");
	gotoxy(27, 8);
	printf("╋┃┃┃┣┳━━┳┳┓┏┳━━┳━┓");
	gotoxy(27, 9);
	printf("╋┃┃┃┣┫┏┓┣┫┗┛┃┏┓┃┏┓┓");
	gotoxy(27, 10);
	printf("┏┛┗┛┃┃┗┛┃┃┃┃┃┗┛┃┃┃┃");
	gotoxy(27, 11);
	printf("┗━━━┻┻━┓┣┻┻┻┻━━┻┛┗┛");
	gotoxy(27, 12);
	printf("╋╋╋╋╋┏━┛┃");
	gotoxy(27, 13);
	printf("╋╋╋╋╋┗━━┛");

	Sleep(1000);

	upClearScreen();

	gotoxy(27, 28);
	printf("┏━━━┓");
	gotoxy(27, 29);
	printf("┗┓┏┓┃");
	gotoxy(27, 30);
	printf("╋┃┃┃┣┳━━┳┳┓┏┳━━┳━┓");
	gotoxy(27, 31);
	printf("╋┃┃┃┣┫┏┓┣┫┗┛┃┏┓┃┏┓┓");
	gotoxy(27, 32);
	printf("┏┛┗┛┃┃┗┛┃┃┃┃┃┗┛┃┃┃┃");
	gotoxy(27, 33);
	printf("┗━━━┻┻━┓┣┻┻┻┻━━┻┛┗┛");
	gotoxy(27, 34);
	printf("╋╋╋╋╋┏━┛┃");
	gotoxy(27, 35);
	printf("╋╋╋╋╋┗━━┛");

	Sleep(1000);

	downClearScreen();

	gotoxy(27, 6);
	printf("┏━━━┓");
	gotoxy(27, 35);
	printf("╋╋╋╋╋┗━━┛");
	Sleep(100);
	gotoxy(27, 7);
	printf("┗┓┏┓┃");
	gotoxy(27, 34);
	printf("╋╋╋╋╋┏━┛┃");
	Sleep(100);
	gotoxy(27, 8);
	printf("╋┃┃┃┣┳━━┳┳┓┏┳━━┳━┓");
	gotoxy(27, 33);
	printf("┗━━━┻┻━┓┣┻┻┻┻━━┻┛┗┛");
	Sleep(100);
	gotoxy(27, 9);
	printf("╋┃┃┃┣┫┏┓┣┫┗┛┃┏┓┃┏┓┓");
	gotoxy(27, 32);
	printf("┏┛┗┛┃┃┗┛┃┃┃┃┃┗┛┃┃┃┃");
	Sleep(100);
	gotoxy(27, 10);
	printf("┏┛┗┛┃┃┗┛┃┃┃┃┃┗┛┃┃┃┃");
	gotoxy(27, 31);
	printf("╋┃┃┃┣┫┏┓┣┫┗┛┃┏┓┃┏┓┓");
	Sleep(100);
	gotoxy(27, 11);
	printf("┗━━━┻┻━┓┣┻┻┻┻━━┻┛┗┛");
	gotoxy(27, 30);
	printf("╋┃┃┃┣┳━━┳┳┓┏┳━━┳━┓");
	Sleep(100);
	gotoxy(27, 12);
	printf("╋╋╋╋╋┏━┛┃");
	gotoxy(27, 29);
	printf("┗┓┏┓┃");
	Sleep(100);
	gotoxy(27, 13);
	printf("╋╋╋╋╋┗━━┛");
	gotoxy(27, 28);
	printf("┏━━━┓");
	Sleep(1000);

	textcolor(BLACK,WHITE);

	downClearScreen();

	while (1)
	{
		if (GetAsyncKeyState(VK_RIGHT) && 0x0001 == TRUE)
		{
			break;
		}
		else if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			shutDown();
		}
		else
		{
			gotoxy(32, 32);
			printf("계속하려면 '○'를 눌러주세요");
			Sleep(500);
			gotoxy(32, 32);
			printf("                               ");
			Sleep(500);
		}
	}

	Pass = 0;
	clearScreen();
	loginSelect();
	return 0;
}

int loginSelect()
{
	int Loop = 0;
	int Selmenu = 0;
	int KeyBCH = 0;

	gotoxy(23, 4);
	printf("현재 시각 ");
	gotoxy(37, 10);
	printf("로그인을 해 주세요");

	gotoxy(24, 27);
	printf("┏━━━━━━━━━━━━━━━━━━━━┓\n");
	gotoxy(24, 28);
	printf("┃                                        ┃\n");
	gotoxy(24, 29);
	printf("┃                로 그 인                ┃\n");
	gotoxy(24, 30);
	printf("┃                                        ┃");
	gotoxy(24, 31);
	printf("┗━━━━━━━━━━━━━━━━━━━━┛");

	gotoxy(24, 33);
	printf("┏━━━━━━━━━━━━━━━━━━━━┓\n");
	gotoxy(24, 34);
	printf("┃                                        ┃\n");
	gotoxy(24, 35);
	printf("┃               아이디 등록              ┃\n");
	gotoxy(24, 36);
	printf("┃                                        ┃");
	gotoxy(24, 37);
	printf("┗━━━━━━━━━━━━━━━━━━━━┛");

	textcolor(BLUE2,BLUE2);
	gotoxy(24, 27);
	printf("┏━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(24, 28);
	printf("┃");
	gotoxy(66, 28);
	printf("┃");
	gotoxy(24, 29);
	printf("┃");
	gotoxy(66, 29);
	printf("┃");
	gotoxy(24, 30);
	printf("┃");
	gotoxy(66, 30);
	printf("┃");
	gotoxy(24, 31);
	printf("┗━━━━━━━━━━━━━━━━━━━━┛");
	textcolor(BLACK,WHITE);

	//키보드 누른거 선택되는것 처럼 보이게해주는구간
	while(1)
	{
		KeyBCH = 0;

		clearReadBuffer(); 
		Sleep(100);
		if (GetAsyncKeyState(0x57) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			Selmenu--;
			if (Selmenu < 0)
				Selmenu++;
			gotoxy(10, 29);
			textcolor(RED2, 0);
			printf("↑");
			Sleep(50);
			gotoxy(10, 29);
			textcolor(WHITE, 0);
			printf("↑");

		}

		else if (GetAsyncKeyState(0x53) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			Selmenu++;
			if (Selmenu > 1)
				Selmenu--;
			gotoxy(10, 35);
			textcolor(RED2, 0);
			printf("↓");
			Sleep(50);
			gotoxy(10, 35);
			textcolor(WHITE, 0);
			printf("↓");

		}

		else if (GetAsyncKeyState(0x41) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			gotoxy(4, 32);
			textcolor(RED2, 0);
			printf("←");
			Sleep(50);
			gotoxy(4, 32);
			textcolor(WHITE, 0);
			printf("←");

		}
		else if (GetAsyncKeyState(0x44) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			gotoxy(16, 32);
			textcolor(RED2, 0);
			printf("→");
			Sleep(50);
			gotoxy(16, 32);
			textcolor(WHITE, 0);
			printf("→");

		}
		else if (GetAsyncKeyState(VK_LEFT) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			gotoxy(75, 31);
			textcolor(RED2, 0);
			printf("□");
			Sleep(50);
			gotoxy(75, 31);
			textcolor(WHITE, 0);
			printf("□");

		}
		else if (GetAsyncKeyState(VK_UP) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			gotoxy(81, 28);
			textcolor(RED2, 0);
			printf("△");
			Sleep(50);
			gotoxy(81, 28);
			textcolor(WHITE, 0);
			printf("△");

		}
		else if (GetAsyncKeyState(VK_DOWN) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			gotoxy(81, 34);
			textcolor(RED2, 0);
			printf("Ⅹ");
			Sleep(50);
			gotoxy(81, 34);
			textcolor(WHITE, 0);
			printf("Ⅹ");

		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			KeyBCH = 1;
			gotoxy(87, 31);
			textcolor(RED2, 0);
			printf("○");
			Sleep(50);
			gotoxy(87, 31);
			textcolor(WHITE, 0);
			printf("○");
			textcolor(0,WHITE);
			while(kbhit())getch();

			switch (Selmenu)
			{
			case 0:
				loginScreen();
				break;
			case 1:
				signinScreen();
				break;
			}
		}
		else if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			shutDown();
		}

		if (KeyBCH == 1)
		{
			switch (Selmenu)
			{
			case 0:
				textcolor(0,WHITE);
				gotoxy(24, 33);
				printf("┏━━━━━━━━━━━━━━━━━━━━┓");
				gotoxy(24, 34);
				printf("┃");
				gotoxy(66, 34);
				printf("┃");
				gotoxy(24, 35);
				printf("┃");
				gotoxy(66, 35);
				printf("┃");
				gotoxy(24, 36);
				printf("┃");
				gotoxy(66, 36);
				printf("┃");
				gotoxy(24, 37);
				printf("┗━━━━━━━━━━━━━━━━━━━━┛");

				textcolor(BLUE2,BLUE2);
				gotoxy(24, 27);
				printf("┏━━━━━━━━━━━━━━━━━━━━┓");
				gotoxy(24, 28);
				printf("┃");
				gotoxy(66, 28);
				printf("┃");
				gotoxy(24, 29);
				printf("┃");
				gotoxy(66, 29);
				printf("┃");
				gotoxy(24, 30);
				printf("┃");
				gotoxy(66, 30);
				printf("┃");
				gotoxy(24, 31);
				printf("┗━━━━━━━━━━━━━━━━━━━━┛");
				textcolor(0,WHITE);
				break;

			case 1:
				textcolor(0,WHITE);
				gotoxy(24, 27);
				printf("┏━━━━━━━━━━━━━━━━━━━━┓");
				gotoxy(24, 28);
				printf("┃");
				gotoxy(66, 28);
				printf("┃");
				gotoxy(24, 29);
				printf("┃");
				gotoxy(66, 29);
				printf("┃");
				gotoxy(24, 30);
				printf("┃");
				gotoxy(66, 30);
				printf("┃");
				gotoxy(24, 31);
				printf("┗━━━━━━━━━━━━━━━━━━━━┛");

				textcolor(BLUE2,BLUE2);
				gotoxy(24, 33);
				printf("┏━━━━━━━━━━━━━━━━━━━━┓");
				gotoxy(24, 34);
				printf("┃");
				gotoxy(66, 34);
				printf("┃");
				gotoxy(24, 35);
				printf("┃");
				gotoxy(66, 35);
				printf("┃");
				gotoxy(24, 36);
				printf("┃");
				gotoxy(66, 36);
				printf("┃");
				gotoxy(24, 37);
				printf("┗━━━━━━━━━━━━━━━━━━━━┛");
				textcolor(0,WHITE);
				break;
			}
		}
	}
	return 0;
}


int signinScreen()
{
	clearScreen();
	clearReadBuffer(); 
	makeID();
	makePW();
	loginScreen();
}

int loginScreen()
{
	clearScreen();
	islogin();
	playScreen();
}

int playScreen()
{
	struct tm *t;
	time_t timer;
	int Hour = 0, Min = 0, Sec = 0;
	int KeyBCH = 0;
	int Selmenu = 0;

	clearScreen();
	PlaySound(NULL, 0, 0);
	sndPlaySoundA("music\\gameplay.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);

	if(user.isMonster == 0)
	{
		monsterInit();
		clearScreen();
	}

	gotoxy(26,34);
	printf("┏━━━━┓");
	gotoxy(26,35);
	printf("┃  힌트  ┃");
	gotoxy(26,36);
	printf("┗━━━━┛"); 

	gotoxy(40,34);
	printf("┏━━━━┓");
	gotoxy(40,35);
	printf("┃  훈련  ┃");
	gotoxy(40,36);
	printf("┗━━━━┛"); 

	gotoxy(54,34);
	printf("┏━━━━┓");
	gotoxy(54,35);
	printf("┃  식사  ┃");
	gotoxy(54,36);
	printf("┗━━━━┛"); 

	gotoxy(26,37);
	printf("┏━━━━┓");
	gotoxy(26,38);
	printf("┃  상점  ┃");
	gotoxy(26,39);
	printf("┗━━━━┛"); 

	gotoxy(40,37);
	printf("┏━━━━┓");
	gotoxy(40,38);
	printf("┃  저장  ┃");
	gotoxy(40,39);
	printf("┗━━━━┛"); 

	gotoxy(54,37);
	printf("┏━━━━┓");
	gotoxy(54,38);
	printf("┃  옵션  ┃");
	gotoxy(54,39);
	printf("┗━━━━┛"); 

	while(1)
	{
		KeyBCH = 0;
		Sleep(100);
		
		if (GetAsyncKeyState(0x57) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			Selmenu -= 3;
			if (Selmenu < 0)
				Selmenu +=6;
			gotoxy(10, 29);
			textcolor(RED2, 0);
			printf("↑");
			Sleep(50);
			gotoxy(10, 29);
			textcolor(WHITE, 0);
			printf("↑");
			getch();
		}

		else if (GetAsyncKeyState(0x53) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			Selmenu+=3;
			if (Selmenu > 5)
				Selmenu-=6;
			gotoxy(10, 35);
			textcolor(RED2, 0);
			printf("↓");
			Sleep(50);
			gotoxy(10, 35);
			textcolor(WHITE, 0);
			printf("↓");
		}

		else if (GetAsyncKeyState(0x41) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			Selmenu--;
			if(Selmenu == -1)
				Selmenu += 6;
			gotoxy(4, 32);
			textcolor(RED2, 0);
			printf("←");
			Sleep(50);
			gotoxy(4, 32);
			textcolor(WHITE, 0);
			printf("←");
		}
		else if (GetAsyncKeyState(0x44) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			Selmenu++;
			if(Selmenu == 6)
				Selmenu -= 6;
			gotoxy(16, 32);
			textcolor(RED2, 0);
			printf("→");
			Sleep(50);
			gotoxy(16, 32);
			textcolor(WHITE, 0);
			printf("→");
		}
		else if (GetAsyncKeyState(VK_LEFT) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			gotoxy(75, 31);
			textcolor(RED2, 0);
			printf("□");
			Sleep(50);
			gotoxy(75, 31);
			textcolor(WHITE, 0);
			printf("□");
		}
		else if (GetAsyncKeyState(VK_UP) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			gotoxy(81, 28);
			textcolor(RED2, 0);
			printf("△");
			Sleep(50);
			gotoxy(81, 28);
			textcolor(WHITE, 0);
			printf("△");
		}
		else if (GetAsyncKeyState(VK_DOWN) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			gotoxy(81, 34);
			textcolor(RED2, 0);
			printf("Ⅹ");
			Sleep(50);
			gotoxy(81, 34);
			textcolor(WHITE, 0);
			printf("Ⅹ");
		}
		else if (GetAsyncKeyState(VK_RIGHT) && 0x0001 == TRUE)
		{
			KeyBCH = 1;
			gotoxy(87, 31);
			textcolor(RED2, 0);
			printf("○");
			Sleep(50);
			gotoxy(87, 31);
			textcolor(WHITE, 0);
			printf("○");
			textcolor(0,WHITE);

			switch (Selmenu)
			{
			case 0:
				while(kbhit())getch();
				hintScreen();
				break;
			case 1:
				while(kbhit())getch();
				traningMenuScreen();
				break;
			case 2:
				while(kbhit())getch();
				foodSelectScreen();
				break;
			case 3:
				while(kbhit())getch();
				storeScreen();
				break;
			case 4:
				while(kbhit())getch(); 
				saveScreen();
				break;
			case 5:
				//세팅
				break;
			}
		}

		else if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			shutDown();
		}


		if (KeyBCH == 1)
		{
			clearReadBuffer(); 
			switch (Selmenu)
			{
			case 0:
				textcolor(0,WHITE);
				gotoxy(26,34);
				printf("┏━━━━┓");
				gotoxy(26,35);
				printf("┃  힌트  ┃");
				gotoxy(26,36);
				printf("┗━━━━┛"); 

				gotoxy(40,34);
				printf("┏━━━━┓");
				gotoxy(40,35);
				printf("┃  훈련  ┃");
				gotoxy(40,36);
				printf("┗━━━━┛"); 

				gotoxy(54,34);
				printf("┏━━━━┓");
				gotoxy(54,35);
				printf("┃  식사  ┃");
				gotoxy(54,36);
				printf("┗━━━━┛"); 

				gotoxy(26,37);
				printf("┏━━━━┓");
				gotoxy(26,38);
				printf("┃  상점  ┃");
				gotoxy(26,39);
				printf("┗━━━━┛"); 

				gotoxy(40,37);
				printf("┏━━━━┓");
				gotoxy(40,38);
				printf("┃  저장  ┃");
				gotoxy(40,39);
				printf("┗━━━━┛"); 

				gotoxy(54,37);
				printf("┏━━━━┓");
				gotoxy(54,38);
				printf("┃  옵션  ┃");
				gotoxy(54,39);
				printf("┗━━━━┛"); 

				textcolor(RED2,WHITE);
				gotoxy(26,34);
				printf("┏━━━━┓");
				gotoxy(26,35);
				printf("┃");
				gotoxy(36,35);
				printf("┃");
				gotoxy(26,36);
				printf("┗━━━━┛"); 
				textcolor(0,WHITE);
				break;

			case 1:
				textcolor(0,WHITE);
				gotoxy(26,34);
				printf("┏━━━━┓");
				gotoxy(26,35);
				printf("┃  힌트  ┃");
				gotoxy(26,36);
				printf("┗━━━━┛"); 

				gotoxy(40,34);
				printf("┏━━━━┓");
				gotoxy(40,35);
				printf("┃  훈련  ┃");
				gotoxy(40,36);
				printf("┗━━━━┛"); 

				gotoxy(54,34);
				printf("┏━━━━┓");
				gotoxy(54,35);
				printf("┃  식사  ┃");
				gotoxy(54,36);
				printf("┗━━━━┛"); 

				gotoxy(26,37);
				printf("┏━━━━┓");
				gotoxy(26,38);
				printf("┃  상점  ┃");
				gotoxy(26,39);
				printf("┗━━━━┛"); 

				gotoxy(40,37);
				printf("┏━━━━┓");
				gotoxy(40,38);
				printf("┃  저장  ┃");
				gotoxy(40,39);
				printf("┗━━━━┛"); 

				gotoxy(54,37);
				printf("┏━━━━┓");
				gotoxy(54,38);
				printf("┃  옵션  ┃");
				gotoxy(54,39);
				printf("┗━━━━┛"); 

				textcolor(RED2,WHITE);

				gotoxy(40,34);
				printf("┏━━━━┓");
				gotoxy(40,35);
				printf("┃");
				gotoxy(50,35);
				printf("┃");
				gotoxy(40,36);
				printf("┗━━━━┛"); 
				break;

			case 2:
				textcolor(0,WHITE);
				gotoxy(26,34);
				printf("┏━━━━┓");
				gotoxy(26,35);
				printf("┃  힌트  ┃");
				gotoxy(26,36);
				printf("┗━━━━┛"); 

				gotoxy(40,34);
				printf("┏━━━━┓");
				gotoxy(40,35);
				printf("┃  훈련  ┃");
				gotoxy(40,36);
				printf("┗━━━━┛"); 

				gotoxy(54,34);
				printf("┏━━━━┓");
				gotoxy(54,35);
				printf("┃  식사  ┃");
				gotoxy(54,36);
				printf("┗━━━━┛"); 

				gotoxy(26,37);
				printf("┏━━━━┓");
				gotoxy(26,38);
				printf("┃  상점  ┃");
				gotoxy(26,39);
				printf("┗━━━━┛"); 

				gotoxy(40,37);
				printf("┏━━━━┓");
				gotoxy(40,38);
				printf("┃  저장  ┃");
				gotoxy(40,39);
				printf("┗━━━━┛"); 

				gotoxy(54,37);
				printf("┏━━━━┓");
				gotoxy(54,38);
				printf("┃  옵션  ┃");
				gotoxy(54,39);
				printf("┗━━━━┛"); 

				textcolor(RED2,WHITE);

				gotoxy(54,34);
				printf("┏━━━━┓");
				gotoxy(54,35);
				printf("┃");
				gotoxy(64,35);
				printf("┃");
				gotoxy(54,36);
				printf("┗━━━━┛"); 
				break;

			case 3:
				textcolor(0,WHITE);
				gotoxy(26,34);
				printf("┏━━━━┓");
				gotoxy(26,35);
				printf("┃  힌트  ┃");
				gotoxy(26,36);
				printf("┗━━━━┛"); 

				gotoxy(40,34);
				printf("┏━━━━┓");
				gotoxy(40,35);
				printf("┃  훈련  ┃");
				gotoxy(40,36);
				printf("┗━━━━┛"); 

				gotoxy(54,34);
				printf("┏━━━━┓");
				gotoxy(54,35);
				printf("┃  식사  ┃");
				gotoxy(54,36);
				printf("┗━━━━┛"); 

				gotoxy(26,37);
				printf("┏━━━━┓");
				gotoxy(26,38);
				printf("┃  상점  ┃");
				gotoxy(26,39);
				printf("┗━━━━┛"); 

				gotoxy(40,37);
				printf("┏━━━━┓");
				gotoxy(40,38);
				printf("┃  저장  ┃");
				gotoxy(40,39);
				printf("┗━━━━┛"); 

				gotoxy(54,37);
				printf("┏━━━━┓");
				gotoxy(54,38);
				printf("┃  옵션  ┃");
				gotoxy(54,39);
				printf("┗━━━━┛"); 

				textcolor(RED2,WHITE);

				gotoxy(26,37);
				printf("┏━━━━┓");
				gotoxy(26,38);
				printf("┃");
				gotoxy(36,38);
				printf("┃");
				gotoxy(26,39);
				printf("┗━━━━┛"); 
				break;

			case 4:
				textcolor(0,WHITE);
				gotoxy(26,34);
				printf("┏━━━━┓");
				gotoxy(26,35);
				printf("┃  힌트  ┃");
				gotoxy(26,36);
				printf("┗━━━━┛"); 

				gotoxy(40,34);
				printf("┏━━━━┓");
				gotoxy(40,35);
				printf("┃  훈련  ┃");
				gotoxy(40,36);
				printf("┗━━━━┛"); 

				gotoxy(54,34);
				printf("┏━━━━┓");
				gotoxy(54,35);
				printf("┃  식사  ┃");
				gotoxy(54,36);
				printf("┗━━━━┛"); 

				gotoxy(26,37);
				printf("┏━━━━┓");
				gotoxy(26,38);
				printf("┃  상점  ┃");
				gotoxy(26,39);
				printf("┗━━━━┛"); 

				gotoxy(40,37);
				printf("┏━━━━┓");
				gotoxy(40,38);
				printf("┃  저장  ┃");
				gotoxy(40,39);
				printf("┗━━━━┛"); 

				gotoxy(54,37);
				printf("┏━━━━┓");
				gotoxy(54,38);
				printf("┃  옵션  ┃");
				gotoxy(54,39);
				printf("┗━━━━┛"); 

				textcolor(RED2,WHITE);

				gotoxy(40,37);
				printf("┏━━━━┓");
				gotoxy(40,38);
				printf("┃");
				gotoxy(50,38);
				printf("┃");
				gotoxy(40,39);
				printf("┗━━━━┛"); 
				break;

			case 5:
				textcolor(0,WHITE);
				gotoxy(26,34);
				printf("┏━━━━┓");
				gotoxy(26,35);
				printf("┃  힌트  ┃");
				gotoxy(26,36);
				printf("┗━━━━┛"); 

				gotoxy(40,34);
				printf("┏━━━━┓");
				gotoxy(40,35);
				printf("┃  훈련  ┃");
				gotoxy(40,36);
				printf("┗━━━━┛"); 

				gotoxy(54,34);
				printf("┏━━━━┓");
				gotoxy(54,35);
				printf("┃  식사  ┃");
				gotoxy(54,36);
				printf("┗━━━━┛"); 

				gotoxy(26,37);
				printf("┏━━━━┓");
				gotoxy(26,38);
				printf("┃  상점  ┃");
				gotoxy(26,39);
				printf("┗━━━━┛"); 

				gotoxy(40,37);
				printf("┏━━━━┓");
				gotoxy(40,38);
				printf("┃  저장  ┃");
				gotoxy(40,39);
				printf("┗━━━━┛"); 

				gotoxy(54,37);
				printf("┏━━━━┓");
				gotoxy(54,38);
				printf("┃  옵션  ┃");
				gotoxy(54,39);
				printf("┗━━━━┛"); 

				textcolor(RED2,WHITE);

				gotoxy(54,37);
				printf("┏━━━━┓");
				gotoxy(54,38);
				printf("┃");
				gotoxy(64,38);
				printf("┃");
				gotoxy(54,39);
				printf("┗━━━━┛"); 
				textcolor(0,WHITE);
				break;
			}
		}
		textcolor(BLACK,WHITE);
		gotoxy(24,25);
		printf("환영합니다 %s님",user.ID);
		gotoxy(24,27);
		printf("몬스터 이름 : %s",user.monster.name); 
		gotoxy(62,27);
		printf("LV : %d", user.monster.LV);
		gotoxy(31,3);
		showMonster(monsterModel[user.monster.LV]);
		gotoxy(24,29);
		textcolor(BLACK,WHITE);
		printf("Hungry : ");
		gotoxy(55,29);
		printf("Credit : %d",user.credit);

		//진화조건들 while문돌면서 계속 확인
		if(user.monster.LV == 0 && user.isItem[2] == 1) evolution1();

		if(user.monster.LV == 1 && user.isItem[0] == 1 
			&& (float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100 >= 100)
			evolution2();

		if(user.monster.LV == 2 && user.isItem[1] == 1 
			&& (float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100 >= 100)
			evolution3();

		if(user.monster.hungry <= 0) user.monster.LV = 4;

		//헬스창
		if(user.monster.hungry >= 80) 
		{
			gotoxy(33,29);
			textcolor(RED2,WHITE);
			printf("♥ ♥ ♥ ♥ ♥");
		}
		else if(user.monster.hungry < 80 && user.monster.hungry >= 60)
		{
			gotoxy(33,29);
			textcolor(RED2,WHITE);
			printf("♥ ♥ ♥ ♥ ♡");
		}
		else if(user.monster.hungry < 60 && user.monster.hungry >= 40)
		{
			gotoxy(33,29);
			textcolor(RED2,WHITE);
			printf("♥ ♥ ♥ ♡ ♡");
		}
		else if(user.monster.hungry < 40 && user.monster.hungry >= 20)
		{
			gotoxy(33,29);
			textcolor(RED2,WHITE);
			printf("♥ ♥ ♡ ♡ ♡");
		}
		else if(user.monster.hungry < 20 && user.monster.hungry >= 1)
		{
			gotoxy(33,29);
			textcolor(RED2,WHITE);
			printf("♥ ♡ ♡ ♡ ♡");
		}
		else
		{
			gotoxy(33,29);
			textcolor(RED2,WHITE);
			printf("♡ ♡ ♡ ♡ ♡");
		}

		gotoxy(24,31);
		textcolor(BLACK,WHITE);
		printf("Evolution_gage :");

		if(user.monster.LV > 0)
		{
			//진화정보
			if((float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100 >= 100)
			{
				gotoxy(36,31);
				textcolor(WHITE,RED2);
				printf("▣▣▣▣▣▣▣▣▣▣");
			}
			else if((float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  < 10 
				&& (float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  >= 0) 
			{
				gotoxy(41,31);
				textcolor(RED2,WHITE);
				printf("▦▦▦▦▦▦▦▦▦▦");
			}
			else if((float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  >= 10  
				&& (float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  < 20)
			{
				gotoxy(41,31);
				textcolor(WHITE,RED2);
				printf("▣");
				gotoxy(43,31);
				textcolor(RED2,WHITE);
				printf("▦▦▦▦▦▦▦▦▦");
			}
			else if((float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  < 30 
				&& (float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  >= 20)
			{
				gotoxy(41,31);
				textcolor(WHITE,RED2);
				printf("▣▣");
				gotoxy(45,31);
				textcolor(RED2,WHITE);
				printf("▦▦▦▦▦▦▦▦");
			}
			else if((float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  < 40 
				&& (float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  >= 30)
			{
				gotoxy(41,31);
				textcolor(WHITE,RED2);
				printf("▣▣▣");
				gotoxy(47,31);
				textcolor(RED2,WHITE);
				printf("▦▦▦▦▦▦▦");
			}
			else if((float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  >= 40 
				&& (float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  < 50)
			{
				gotoxy(41,31);
				textcolor(WHITE,RED2);
				printf("▣▣▣▣");
				gotoxy(49,31);
				textcolor(RED2,WHITE);
				printf("▦▦▦▦▦▦");
			}
			else if((float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  >= 50 
				&& (float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  < 60)
			{
				gotoxy(41,31);
				textcolor(WHITE,RED2);
				printf("▣▣▣▣▣");
				gotoxy(51,31);
				textcolor(RED2,WHITE);
				printf("▦▦▦▦▦");
			}
			else if((float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  >= 60 
				&& (float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  < 70)
			{
				gotoxy(41,31);
				textcolor(WHITE,RED2);
				printf("▣▣▣▣▣▣");
				gotoxy(53,31);
				textcolor(RED2,WHITE);
				printf("▦▦▦▦");
			}
			else if((float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  >= 70 
				&& (float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  < 80)
			{
				gotoxy(41,31);
				textcolor(WHITE,RED2);
				printf("▣▣▣▣▣▣▣");
				gotoxy(55,31);
				textcolor(RED2,WHITE);
				printf("▦▦▦");
			}
			else if((float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  >= 80 
				&& (float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  < 90)
			{
				gotoxy(41,31);
				textcolor(WHITE,RED2);
				printf("▣▣▣▣▣▣▣▣");
				gotoxy(57,31);
				textcolor(RED2,WHITE);
				printf("▦▦");
			}
			else if((float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  >= 90 
				&& (float)user.monster.current_evolution[user.monster.LV] / user.monster.evolution_gage[user.monster.LV] * 100  < 99)
			{
				gotoxy(41,31);
				textcolor(WHITE,RED2);
				printf("▣▣▣▣▣▣▣▣▣");
				gotoxy(59,31);
				textcolor(RED2,WHITE);
				printf("▦");
			}
		}
		else
		{
			gotoxy(41,31);
			textcolor(BLACK,WHITE);
			printf("연습 훈련을 해주세요");
		}

		textcolor(BLACK,WHITE);
		timer = time(NULL);
		t = localtime(&timer);
		Hour = t->tm_hour;
		Min = t->tm_min;
		Sec = t->tm_sec;
		gotoxy(50,25);
		printf("현재시간");
		gotoxy(60, 25);
		printf("%02d:%02d:%02d ", Hour, Min, Sec);
	}
	return 0;
}

int saveScreen()
{
	char fileName[MAXSIZE] = " ";
	char temp[MAXSIZE];
	int answer;
	FILE * fp;

	strcpy(temp,user.ID);
	strcpy(fileName, strcat(temp,".txt"));
	fp = fopen(fileName, "w+b");

	clearScreen();
	gotoxy(35, 9);
	printf("저장하시겠습니까?");
	gotoxy(35, 10);
	printf("예 : 1 아니요 : 0");
	gotoxy(36, 11);
	scanf("%d",&answer);

	if(answer == 1)
	{
		fwrite(&user, sizeof(user), 1,fp); 
		fclose(fp);
		upClearScreen();
		gotoxy(35, 9);
		printf("저장되었습니다");
		upClearScreen();
		return;
	}
	else{
		clearScreen();
		return;
	}
}

int traningMenuScreen()
{
	int SelMode = 0;
	int Loop = 0;
	int Pass = 0;
	int KeyHit = 0;
	int LastMode = 0;

	clearScreen();

	sndPlaySoundA("music\\training.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);

	gotoxy(38, 6);
	textcolor(WHITE,BLACK);
	printf("※모 드 선 택※");

	textcolor(BLACK,WHITE);
	gotoxy(39, 8);
	printf("┏━━━━━┓");
	gotoxy(39, 9);
	printf("┃이지  훈련┃");
	gotoxy(39, 10);
	printf("┗━━━━━┛");

	gotoxy(27, 11);
	printf("┏━━━━━┓         ┏━━━━━┓");
	gotoxy(27, 12);
	printf("┃연습  모드┃         ┃하드  훈련┃");
	gotoxy(27, 13);
	printf("┗━━━━━┛         ┗━━━━━┛");

	gotoxy(39, 14);
	printf("┏━━━━━┓");
	gotoxy(39, 15);
	printf("┃뒤로  가기┃");
	gotoxy(39, 16);
	printf("┗━━━━━┛");

	textcolor(RED2,WHITE);
	gotoxy(27, 11);
	printf("┏━━━━━┓");
	gotoxy(27, 12);
	printf("┃");
	gotoxy(39, 12);
	printf("┃");
	gotoxy(27, 13);
	printf("┗━━━━━┛");

	textcolor(BLACK,WHITE);
	gotoxy(25, 28);
	printf("◎ 연습모드는 충돌을 무시합니다");
	gotoxy(25, 31);
	printf("◎ 연습모드는 경험치 획득이 불가능합니다");
	gotoxy(25, 34);
	printf("◎ 충돌을 무시하지만 충돌한 횟수는");
	gotoxy(28, 35);
	printf("결과창에서 볼 수 있습니다");
	gotoxy(25, 37);
	printf("◎ 훈련이 어려울 때 하기 좋은 모드입니다");

	while (1)
	{
		if (GetAsyncKeyState(0x41) & 0x0001 == TRUE)
		{
			SelMode--;
			if (SelMode < 0)
				SelMode++;
			KeyHit = 1;
		}

		if (GetAsyncKeyState(0x44) & 0x0001 == TRUE)
		{
			SelMode++;
			if (SelMode > 3)
				SelMode--;
			KeyHit = 1;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			clearScreen();
			while(kbhit())getch();
			switch (SelMode)
			{
			case 0:
				practiceTraining();
				break;
			case 1:
				easyTraining();
				break;
			case 2:
				hardTraining();
				break;
			case 3:
				return;
			}
		}

		if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			shutDown();
		}

		if (KeyHit == 1 && LastMode != SelMode)
		{
			upClearScreen();
			switch (SelMode)
			{
			case 0:
				downClearScreen();
				gotoxy(38, 6);
				textcolor(WHITE,BLACK);
				printf("※모 드 선 택※");

				textcolor(BLACK,WHITE);
				gotoxy(39, 8);
				printf("┏━━━━━┓");
				gotoxy(39, 9);
				printf("┃이지  훈련┃");
				gotoxy(39, 10);
				printf("┗━━━━━┛");

				gotoxy(27, 11);
				printf("┏━━━━━┓         ┏━━━━━┓");
				gotoxy(27, 12);
				printf("┃연습  모드┃         ┃하드  훈련┃");
				gotoxy(27, 13);
				printf("┗━━━━━┛         ┗━━━━━┛");

				textcolor(RED2,WHITE);
				gotoxy(27, 11);
				printf("┏━━━━━┓");
				gotoxy(27, 12);
				printf("┃");
				gotoxy(39, 12);
				printf("┃");
				gotoxy(27, 13);
				printf("┗━━━━━┛");

				textcolor(BLACK,WHITE);
				gotoxy(39, 14);
				printf("┏━━━━━┓");
				gotoxy(39, 15);
				printf("┃뒤로  가기┃");
				gotoxy(39, 16);
				printf("┗━━━━━┛");
				textcolor(BLACK,WHITE);
				gotoxy(25, 28);
				printf("◎ 연습모드는 충돌을 무시합니다");
				gotoxy(25, 31);
				printf("◎ 연습모드는 경험치 획득이 불가능합니다");
				gotoxy(25, 34);
				printf("◎ 충돌을 무시하지만 충돌한 횟수는");
				gotoxy(28, 35);
				printf("결과창에서 볼 수 있습니다");
				gotoxy(25, 37);
				printf("◎ 훈련이 어려울 때 하기 좋은 모드입니다");
				break;
			case 1:
				downClearScreen();
				gotoxy(38, 6);
				textcolor(GREEN2,MAGENTA1);
				printf("※모 드 선 택※");

				textcolor(BLACK,WHITE);

				gotoxy(39, 8);
				printf("┏━━━━━┓");
				gotoxy(39, 9);
				printf("┃이지  훈련┃");
				gotoxy(39, 10);
				printf("┗━━━━━┛");

				gotoxy(50, 11);
				printf("┏━━━━━┓");
				gotoxy(50, 12);
				printf("┃하드  훈련┃");
				gotoxy(50, 13);
				printf("┗━━━━━┛");

				gotoxy(27, 11);
				printf("┏━━━━━┓");
				gotoxy(27, 12);
				printf("┃연습  모드┃");
				gotoxy(27, 13);
				printf("┗━━━━━┛");

				textcolor(BLUE2,WHITE);
				gotoxy(39, 8);
				printf("┏━━━━━┓");
				gotoxy(39, 9);
				printf("┃");

				gotoxy(51, 9);
				printf("┃");
				gotoxy(39, 10);
				printf("┗━━━━━┛");

				textcolor(BLACK,WHITE);
				gotoxy(39, 14);
				printf("┏━━━━━┓");
				gotoxy(39, 15);
				printf("┃뒤로  가기┃");
				gotoxy(39, 16);
				printf("┗━━━━━┛");
				textcolor(BLACK,WHITE);
				gotoxy(25, 28);
				printf("◎ 이지훈련모드는 목숨이 2개 주어집니다");
				gotoxy(25, 31);
				printf("◎ 이지훈련모드는 체크포인트가 존재합니다");
				gotoxy(25, 34);
				printf("◎ 생명이 1이상일때 죽을 경우 체크포인트에서");
				gotoxy(25, 35);
				printf("   부활합니다");
				gotoxy(25, 37);
				printf("◎ 이지훈련모드는 생명아이템이 존재합니다");
				break;
			case 2:
				downClearScreen();
				gotoxy(38, 6);
				textcolor(RED2,YELLOW2);
				printf("※모 드 선 택※");

				textcolor(BLACK,WHITE);
				gotoxy(39, 8);
				printf("┏━━━━━┓");
				gotoxy(39, 9);
				printf("┃이지  훈련┃");
				gotoxy(39, 10);
				printf("┗━━━━━┛");

				gotoxy(27, 11);
				printf("┏━━━━━┓         ┏━━━━━┓");
				gotoxy(27, 12);
				printf("┃연습  모드┃         ┃하드  훈련┃");
				gotoxy(27, 13);
				printf("┗━━━━━┛         ┗━━━━━┛");

				textcolor(GREEN2,WHITE);
				gotoxy(50, 11);
				printf("┏━━━━━┓");
				gotoxy(50, 12);
				printf("┃");
				gotoxy(62, 12);
				printf("┃");
				gotoxy(50, 13);
				printf("┗━━━━━┛");

				textcolor(BLACK,WHITE);
				gotoxy(39, 14);
				printf("┏━━━━━┓");
				gotoxy(39, 15);
				printf("┃뒤로  가기┃");
				gotoxy(39, 16);
				printf("┗━━━━━┛");

				textcolor(BLACK,WHITE);
				gotoxy(25, 28);
				printf("◎ 하드훈련모드는 충돌시 목숨이 1 줄어듭니다");
				gotoxy(25, 31);
				printf("◎ 목숨은 시작 시 3개로 주어집니다");
				gotoxy(25, 34);
				printf("◎ 하드훈련모드는 등급이 표시됩니다");
				gotoxy(25, 37);
				printf("◎ 경험치,크레딧을 가장많이 얻을수 있습니다");
				break;

			case 3:

				gotoxy(38, 6);
				textcolor(13, 11);
				printf("※뒤 로 가 기※");

				textcolor(BLACK,WHITE);
				gotoxy(39, 8);
				printf("┏━━━━━┓");
				gotoxy(39, 9);
				printf("┃이지  훈련┃");
				gotoxy(39, 10);
				printf("┗━━━━━┛");

				gotoxy(27, 11);
				printf("┏━━━━━┓         ┏━━━━━┓");
				gotoxy(27, 12);
				printf("┃연습  모드┃         ┃하드  훈련┃");
				gotoxy(27, 13);
				printf("┗━━━━━┛         ┗━━━━━┛");

				textcolor(BLACK,WHITE);
				gotoxy(39, 14);
				printf("┏━━━━━┓");
				gotoxy(39, 15);
				printf("┃뒤로  가기┃");
				gotoxy(39, 16);
				printf("┗━━━━━┛");

				textcolor(MAGENTA2,WHITE);
				gotoxy(39, 14);
				printf("┏━━━━━┓");
				gotoxy(39, 15);
				printf("┃");
				gotoxy(39, 15);
				printf("┃");
				gotoxy(39, 16);
				printf("┗━━━━━┛");
				textcolor(BLACK,WHITE);
				gotoxy(25, 28);
				printf("◎ 메뉴로 돌아갑니다");
			}
			textcolor(BLACK,WHITE);
			LastMode = SelMode;
		}
		KeyHit = 0;
	}
	return 0;
}

int storeScreen()
{
	int SelMode = 0;
	int Loop = 0;
	int Pass = 0;
	int KeyHit = 0;
	int LastMode = 0;

	sndPlaySoundA("music\\market.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);

	clearScreen();
	textcolor(RED2,BLACK);
	gotoxy(27,7);
	printf(" ######  ##     ##  #######  ########  ");
	textcolor(RED2,BLACK);
	gotoxy(27,8);
	printf("##    ## ##     ## ##     ## ##     ## ");
	textcolor(RED2,BLACK);
	gotoxy(27,9);
	printf("##       ##     ## ##     ## ##     ## ");
	textcolor(RED2,BLACK);
	gotoxy(27,10);
	printf(" ######  ######### ##     ## ########  ");
	textcolor(RED2,BLACK);

	gotoxy(27,11);
	printf("      ## ##     ## ##     ## ##        ");
	textcolor(RED2,BLACK);
	gotoxy(27,12);
	printf("##    ## ##     ## ##     ## ##        ");
	textcolor(RED2,BLACK);
	gotoxy(27,13);
	printf(" ######  ##     ##  #######  ##        ");

	gotoxy(27,26);
	textcolor(RED2,WHITE);
	if(user.isItem[0] == 0) showModel(itemModel[0]);
	else showModel(itemModel[2]);

	gotoxy(49,26);
	textcolor(YELLOW2,WHITE);
	if(user.isItem[1] == 0) showModel(itemModel[1]);
	else
	{ 
		textcolor(RED2,WHITE);
		showModel(itemModel[2]);
	}

	textcolor(RED2,WHITE);
	gotoxy(24,34);
	printf("┏━━━━━━━━━┓");
	gotoxy(24,35);
	printf("┃ 용기의 문장 구입 ┃");
	gotoxy(24,36);
	printf("┗━━━━━━━━━┛"); 

	textcolor(BLACK,WHITE);
	gotoxy(47,34);
	printf("┏━━━━━━━━┓");
	gotoxy(47,35);
	printf("┃ 빛의 문장 구입 ┃");
	gotoxy(47,36);
	printf("┗━━━━━━━━┛"); 

	gotoxy(39, 37);
	printf("┏━━━━━┓");
	gotoxy(39, 38);
	printf("┃뒤로  가기┃");
	gotoxy(39, 39);
	printf("┗━━━━━┛");
	gotoxy(24,34);

	while (1)
	{
		while(kbhit())getch();
		if (GetAsyncKeyState(0x41) & 0x0001 == TRUE)
		{
			SelMode--;
			if (SelMode < 0)
				SelMode++;
			KeyHit = 1;
		}

		if (GetAsyncKeyState(0x44) & 0x0001 == TRUE)
		{
			SelMode++;
			if (SelMode > 2)
				SelMode--;
			KeyHit = 1;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			clearScreen();
			switch (SelMode)
			{
			case 0:
				if(user.isItem[0] == 0 && user.credit > 500)
				{
					user.isItem[0] = 1;
					user.credit -= 500;
				}
				else
					continue;
				break;
			case 1:
				if(user.isItem[1] == 0 && user.credit > 1000)
				{
					user.isItem[1] = 1;
					user.credit -= 1000;
				}
				else
					continue;
				break;
			case 2:
				return;
				break;
			}
		}

		if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			shutDown();
		}

		if (KeyHit == 1 && LastMode != SelMode)
		{
			switch (SelMode)
			{

			case 0:
				textcolor(RED2,BLACK);
				gotoxy(27,7);
				printf(" ######  ##     ##  #######  ########  ");
				textcolor(RED2,BLACK);
				gotoxy(27,8);
				printf("##    ## ##     ## ##     ## ##     ## ");
				textcolor(RED2,BLACK);
				gotoxy(27,9);
				printf("##       ##     ## ##     ## ##     ## ");
				textcolor(RED2,BLACK);
				gotoxy(27,10);
				printf(" ######  ######### ##     ## ########  ");
				textcolor(RED2,BLACK);

				gotoxy(27,11);
				printf("      ## ##     ## ##     ## ##        ");
				textcolor(RED2,BLACK);
				gotoxy(27,12);
				printf("##    ## ##     ## ##     ## ##        ");
				textcolor(RED2,BLACK);
				gotoxy(27,13);
				printf(" ######  ##     ##  #######  ##        ");

				gotoxy(27,26);
				textcolor(RED2,WHITE);
				if(user.isItem[0] == 0) showModel(itemModel[0]);
				else showModel(itemModel[2]);

				gotoxy(49,26);
				textcolor(YELLOW2,WHITE);
				if(user.isItem[1] == 0) showModel(itemModel[1]);
				else
				{ 
					textcolor(RED2,WHITE);
					showModel(itemModel[2]);
				}
				textcolor(BLACK,WHITE);
				gotoxy(24,34);
				printf("┏━━━━━━━━━┓");
				gotoxy(24,35);
				printf("┃ 용기의 문장 구입 ┃");
				gotoxy(24,36);
				printf("┗━━━━━━━━━┛"); 

				gotoxy(47,34);
				printf("┏━━━━━━━━┓");
				gotoxy(47,35);
				printf("┃ 빛의 문장 구입 ┃");
				gotoxy(47,36);
				printf("┗━━━━━━━━┛"); 

				gotoxy(39, 37);
				printf("┏━━━━━┓");
				gotoxy(39, 38);
				printf("┃뒤로  가기┃");
				gotoxy(39, 39);
				printf("┗━━━━━┛");


				textcolor(RED2,WHITE);
				gotoxy(24,34);
				printf("┏━━━━━━━━━┓");
				gotoxy(24,35);
				printf("┃ 용기의 문장 구입 ┃");
				gotoxy(24,36);
				printf("┗━━━━━━━━━┛"); 
				textcolor(BLACK,WHITE);

				break;
			case 1:
				textcolor(RED2,BLACK);
				gotoxy(27,7);
				printf(" ######  ##     ##  #######  ########  ");
				textcolor(RED2,BLACK);
				gotoxy(27,8);
				printf("##    ## ##     ## ##     ## ##     ## ");
				textcolor(RED2,BLACK);
				gotoxy(27,9);
				printf("##       ##     ## ##     ## ##     ## ");
				textcolor(RED2,BLACK);
				gotoxy(27,10);
				printf(" ######  ######### ##     ## ########  ");
				textcolor(RED2,BLACK);

				gotoxy(27,11);
				printf("      ## ##     ## ##     ## ##        ");
				textcolor(RED2,BLACK);
				gotoxy(27,12);
				printf("##    ## ##     ## ##     ## ##        ");
				textcolor(RED2,BLACK);
				gotoxy(27,13);
				printf(" ######  ##     ##  #######  ##        ");

				gotoxy(27,26);
				textcolor(RED2,WHITE);
				if(user.isItem[0] == 0) showModel(itemModel[0]);
				else showModel(itemModel[2]);

				gotoxy(49,26);
				textcolor(YELLOW2,WHITE);
				if(user.isItem[1] == 0) showModel(itemModel[1]);
				else
				{ 
					textcolor(RED2,WHITE);
					showModel(itemModel[2]);
				}
				textcolor(BLACK,WHITE);
				gotoxy(24,34);
				printf("┏━━━━━━━━━┓");
				gotoxy(24,35);
				printf("┃ 용기의 문장 구입 ┃");
				gotoxy(24,36);
				printf("┗━━━━━━━━━┛"); 

				gotoxy(47,34);
				printf("┏━━━━━━━━┓");
				gotoxy(47,35);
				printf("┃ 빛의 문장 구입 ┃");
				gotoxy(47,36);
				printf("┗━━━━━━━━┛"); 

				gotoxy(39, 37);
				printf("┏━━━━━┓");
				gotoxy(39, 38);
				printf("┃뒤로  가기┃");
				gotoxy(39, 39);
				printf("┗━━━━━┛");

				textcolor(RED2,WHITE);
				gotoxy(47,34);
				printf("┏━━━━━━━━┓");
				gotoxy(47,35);
				printf("┃ 빛의 문장 구입 ┃");
				gotoxy(47,36);
				printf("┗━━━━━━━━┛"); 
				textcolor(BLACK,WHITE);
				break;

			case 2:
				textcolor(RED2,BLACK);
				gotoxy(27,7);
				printf(" ######  ##     ##  #######  ########  ");
				textcolor(RED2,BLACK);
				gotoxy(27,8);
				printf("##    ## ##     ## ##     ## ##     ## ");
				textcolor(RED2,BLACK);
				gotoxy(27,9);
				printf("##       ##     ## ##     ## ##     ## ");
				textcolor(RED2,BLACK);
				gotoxy(27,10);
				printf(" ######  ######### ##     ## ########  ");
				textcolor(RED2,BLACK);

				gotoxy(27,11);
				printf("      ## ##     ## ##     ## ##        ");
				textcolor(RED2,BLACK);
				gotoxy(27,12);
				printf("##    ## ##     ## ##     ## ##        ");
				textcolor(RED2,BLACK);
				gotoxy(27,13);
				printf(" ######  ##     ##  #######  ##        ");

				gotoxy(27,26);
				textcolor(RED2,WHITE);
				if(user.isItem[0] == 0) showModel(itemModel[0]);
				else showModel(itemModel[2]);

				gotoxy(49,26);
				textcolor(YELLOW2,WHITE);
				if(user.isItem[1] == 0) showModel(itemModel[1]);
				else
				{ 
					textcolor(RED2,WHITE);
					showModel(itemModel[2]);
				}
				textcolor(BLACK,WHITE);
				gotoxy(24,34);
				printf("┏━━━━━━━━━┓");
				gotoxy(24,35);
				printf("┃ 용기의 문장 구입 ┃");
				gotoxy(24,36);
				printf("┗━━━━━━━━━┛"); 

				gotoxy(47,34);
				printf("┏━━━━━━━━┓");
				gotoxy(47,35);
				printf("┃ 빛의 문장 구입 ┃");
				gotoxy(47,36);
				printf("┗━━━━━━━━┛"); 

				gotoxy(39, 37);
				printf("┏━━━━━┓");
				gotoxy(39, 38);
				printf("┃뒤로  가기┃");
				gotoxy(39, 39);
				printf("┗━━━━━┛");

				textcolor(RED2,WHITE);
				gotoxy(39, 37);
				printf("┏━━━━━┓");
				gotoxy(39, 38);
				printf("┃뒤로  가기┃");
				gotoxy(39, 39);
				printf("┗━━━━━┛");

				textcolor(BLACK,WHITE);
				break;
			}
			textcolor(BLACK,WHITE);
			LastMode = SelMode;
		}
		KeyHit = 0;
	}

	PlaySound(NULL, 0, 0);
	return 0;
}

int foodSelectScreen()
{
	int SelMode = 0;
	int Loop = 0;
	int Pass = 0;
	int KeyHit = 0;
	int LastMode = 0;

	clearScreen();
	gotoxy(25,7);
	printf("음식을 선택하세요");
	gotoxy(25,10);
	printf("※고기는 포만감 20을 채워줍니다 20원");
	gotoxy(25,11);
	printf("※알약은 포만감 100을 채워줍니다 60원");
	textcolor(RED2,WHITE);
	gotoxy(24,27);
	printf("┏━━━━━━━━━┓");
	gotoxy(24,28);
	printf("┃                  ┃");
	gotoxy(24,29);
	printf("┃                  ┃");
	gotoxy(24,30);
	printf("┃                  ┃");
	gotoxy(24,31);
	printf("┃                  ┃");
	gotoxy(24,32);
	printf("┃                  ┃");
	gotoxy(24,33);
	printf("┃                  ┃");
	gotoxy(24,34);
	printf("┃                  ┃");
	gotoxy(24,35);
	printf("┃                  ┃");
	gotoxy(24,36);
	printf("┗━━━━━━━━━┛"); 

	gotoxy(27,28);
	textcolor(RED1,WHITE);
	showModel(foodModel[0]);

	gotoxy(49,28);
	textcolor(RED2,WHITE);
	showModel(foodModel[2]);

	textcolor(BLACK,WHITE);

	gotoxy(39, 37);
	printf("┏━━━━━┓");
	gotoxy(39, 38);
	printf("┃뒤로  가기┃");
	gotoxy(39, 39);
	printf("┗━━━━━┛");
	gotoxy(24,34);

	while (1)
	{
		if (GetAsyncKeyState(0x41) & 0x0001 == TRUE)
		{
			SelMode--;
			if (SelMode < 0)
				SelMode++;
			KeyHit = 1;
		}

		if (GetAsyncKeyState(0x44) & 0x0001 == TRUE)
		{
			SelMode++;
			if (SelMode > 2)
				SelMode--;
			KeyHit = 1;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			clearScreen();
			while(kbhit())getch();
			switch (SelMode)
			{
			case 0:
				if(user.credit>20){
					user.credit-=20;
					user.monster.hungry += 20;
					if(user.monster.hungry > 100) user.monster.hungry = 100;
					eatBeef();
				}
				else
				{
					gotoxy(35,7);
					printf("크레딧이 부족합니다");
					Sleep(500);
					gotoxy(25,13);
					printf("              ");
					continue;
				}
				break;
			case 1:
				if(user.credit>60)
				{
					user.credit-=60;
					user.monster.hungry = 100;
					eatPeel();
				}
				else
				{
					gotoxy(35,7);
					printf("크레딧이 부족합니다");
					Sleep(500);
					gotoxy(25,13);
					printf("              ");
					continue;
				}
				break;
			case 2:
				return;
				break;
			}
		}

		if (GetAsyncKeyState(0x46) && 0x0001 == TRUE)
		{
			shutDown();
		}

		if (KeyHit == 1 && LastMode != SelMode)
		{
			switch (SelMode)
			{

			case 0:
				gotoxy(25,7);
				printf("음식을 선택하세요");
				gotoxy(25,10);
				printf("※고기는 포만감 20을 채워줍니다 20원");
				gotoxy(25,11);
				printf("※알약은 포만감 100을 채워줍니다 60원");

				textcolor(WHITE,WHITE);
				gotoxy(46,27);
				printf("┏━━━━━━━━━┓");
				gotoxy(46,28);
				printf("┃                  ┃");
				gotoxy(46,29);
				printf("┃                  ┃");
				gotoxy(46,30);
				printf("┃                  ┃");
				gotoxy(46,31);
				printf("┃                  ┃");
				gotoxy(46,32);
				printf("┃                  ┃");
				gotoxy(46,33);
				printf("┃                  ┃");
				gotoxy(46,34);
				printf("┃                  ┃");
				gotoxy(46,35);
				printf("┃                  ┃");
				gotoxy(46,36);
				printf("┗━━━━━━━━━┛"); 

				textcolor(RED2,WHITE);
				gotoxy(24,27);
				printf("┏━━━━━━━━━┓");
				gotoxy(24,28);
				printf("┃                  ┃");
				gotoxy(24,29);
				printf("┃                  ┃");
				gotoxy(24,30);
				printf("┃                  ┃");
				gotoxy(24,31);
				printf("┃                  ┃");
				gotoxy(24,32);
				printf("┃                  ┃");
				gotoxy(24,33);
				printf("┃                  ┃");
				gotoxy(24,34);
				printf("┃                  ┃");
				gotoxy(24,35);
				printf("┃                  ┃");
				gotoxy(24,36);
				printf("┗━━━━━━━━━┛"); 

				gotoxy(27,28);
				textcolor(RED1,WHITE);
				showModel(foodModel[0]);

				gotoxy(49,28);
				textcolor(RED2,WHITE);
				showModel(foodModel[2]);

				textcolor(BLACK,WHITE);

				gotoxy(39, 37);
				printf("┏━━━━━┓");
				gotoxy(39, 38);
				printf("┃뒤로  가기┃");
				gotoxy(39, 39);
				printf("┗━━━━━┛");
				gotoxy(24,34);
				break;
			case 1:
				gotoxy(25,7);
				printf("음식을 선택하세요");
				gotoxy(25,10);
				printf("※고기는 포만감 20을 채워줍니다 20원");
				gotoxy(25,11);
				printf("※알약은 포만감 100을 채워줍니다 60원");


				textcolor(WHITE,WHITE);
				gotoxy(24,27);
				printf("┏━━━━━━━━━┓");
				gotoxy(24,28);
				printf("┃                  ┃");
				gotoxy(24,29);
				printf("┃                  ┃");
				gotoxy(24,30);
				printf("┃                  ┃");
				gotoxy(24,31);
				printf("┃                  ┃");
				gotoxy(24,32);
				printf("┃                  ┃");
				gotoxy(24,33);
				printf("┃                  ┃");
				gotoxy(24,34);
				printf("┃                  ┃");
				gotoxy(24,35);
				printf("┃                  ┃");
				gotoxy(24,36);
				printf("┗━━━━━━━━━┛"); 

				textcolor(RED2,WHITE);
				gotoxy(46,27);
				printf("┏━━━━━━━━━┓");
				gotoxy(46,28);
				printf("┃                  ┃");
				gotoxy(46,29);
				printf("┃                  ┃");
				gotoxy(46,30);
				printf("┃                  ┃");
				gotoxy(46,31);
				printf("┃                  ┃");
				gotoxy(46,32);
				printf("┃                  ┃");
				gotoxy(46,33);
				printf("┃                  ┃");
				gotoxy(46,34);
				printf("┃                  ┃");
				gotoxy(46,35);
				printf("┃                  ┃");
				gotoxy(46,36);
				printf("┗━━━━━━━━━┛"); 

				gotoxy(49,28);
				textcolor(RED2,WHITE);
				showModel(foodModel[2]);

				gotoxy(27,28);
				textcolor(RED1,WHITE);
				showModel(foodModel[0]);

				textcolor(BLACK,WHITE);

				gotoxy(39, 37);
				printf("┏━━━━━┓");
				gotoxy(39, 38);
				printf("┃뒤로  가기┃");
				gotoxy(39, 39);
				printf("┗━━━━━┛");
				gotoxy(24,34);
				break;

			case 2:

				textcolor(WHITE,WHITE);
				gotoxy(46,27);
				printf("┏━━━━━━━━━┓");
				gotoxy(46,28);
				printf("┃                  ┃");
				gotoxy(46,29);
				printf("┃                  ┃");
				gotoxy(46,30);
				printf("┃                  ┃");
				gotoxy(46,31);
				printf("┃                  ┃");
				gotoxy(46,32);
				printf("┃                  ┃");
				gotoxy(46,33);
				printf("┃                  ┃");
				gotoxy(46,34);
				printf("┃                  ┃");
				gotoxy(46,35);
				printf("┃                  ┃");
				gotoxy(46,36);
				printf("┗━━━━━━━━━┛"); 

				gotoxy(49,28);
				textcolor(RED2,WHITE);
				showModel(foodModel[2]);

				gotoxy(27,28);
				textcolor(RED1,WHITE);
				showModel(foodModel[0]);

				gotoxy(39, 37);
				printf("┏━━━━━┓");
				gotoxy(39, 38);
				printf("┃뒤로  가기┃");
				gotoxy(39, 39);
				printf("┗━━━━━┛");

				textcolor(RED2,WHITE);
				gotoxy(39, 37);
				printf("┏━━━━━┓");
				gotoxy(39, 38);
				printf("┃뒤로  가기┃");
				gotoxy(39, 39);
				printf("┗━━━━━┛");

				textcolor(BLACK,WHITE);
				break;
			}
			textcolor(BLACK,WHITE);
			LastMode = SelMode;
		}
		KeyHit = 0;
	}
}

int eatBeef()
{
	clearScreen();

	gotoxy(23,10);
	textcolor(RED1,WHITE);
	showModel(foodModel[0]);

	gotoxy(39,3);
	textcolor(BLACK,WHITE);
	showMonster(monsterModel[user.monster.LV]);

	gotoxy(39,3);
	textcolor(WHITE,WHITE);
	showMonster(monsterModel[user.monster.LV]);

	gotoxy(39,3);
	textcolor(BLACK,WHITE);
	showMonster(monsterModel2[user.monster.LV]);

	Sleep(500);
	gotoxy(39,3);
	textcolor(WHITE,WHITE);
	showMonster(monsterModel2[user.monster.LV]);

	gotoxy(39,3);
	textcolor(BLACK,WHITE);
	showMonster(monsterModel[user.monster.LV]);

	gotoxy(23,10);
	textcolor(WHITE,WHITE);
	showModel(foodModel[0]);

	gotoxy(23,10);
	textcolor(RED1,WHITE);
	showModel(foodModel[1]);

	Sleep(500);
	gotoxy(39,3);
	textcolor(WHITE,WHITE);
	showMonster(monsterModel[user.monster.LV]);

	gotoxy(39,3);
	textcolor(BLACK,WHITE);
	showMonster(monsterModel2[user.monster.LV]);

	Sleep(500);
	gotoxy(39,3);
	textcolor(WHITE,WHITE);
	showMonster(monsterModel2[user.monster.LV]);

	gotoxy(39,3);
	textcolor(BLACK,WHITE);
	showMonster(monsterModel[user.monster.LV]);

	gotoxy(23,10);
	textcolor(WHITE,WHITE);
	showModel(foodModel[1]);

	gotoxy(23,10);
	textcolor(RED1,WHITE);
	showModel(foodModel[4]);

	Sleep(500);
	upClearScreen();
	textcolor(BLACK,WHITE);
	return;
}

int eatPeel()
{
	clearScreen();

	gotoxy(23,10);
	textcolor(RED2,WHITE);
	showModel(foodModel[2]);

	gotoxy(39,3);
	textcolor(BLACK,WHITE);
	showMonster(monsterModel[user.monster.LV]);

	gotoxy(39,3);
	textcolor(WHITE,WHITE);
	showMonster(monsterModel[user.monster.LV]);

	gotoxy(39,3);
	textcolor(BLACK,WHITE);
	showMonster(monsterModel2[user.monster.LV]);

	Sleep(500);
	gotoxy(39,3);
	textcolor(WHITE,WHITE);
	showMonster(monsterModel2[user.monster.LV]);

	gotoxy(39,3);
	textcolor(BLACK,WHITE);
	showMonster(monsterModel[user.monster.LV]);

	gotoxy(23,10);
	textcolor(WHITE,WHITE);
	showModel(foodModel[2]);

	gotoxy(23,10);
	textcolor(RED2,WHITE);
	showModel(foodModel[3]);

	Sleep(500);
	gotoxy(39,3);
	textcolor(WHITE,WHITE);
	showMonster(monsterModel[user.monster.LV]);

	gotoxy(39,3);
	textcolor(BLACK,WHITE);
	showMonster(monsterModel2[user.monster.LV]);

	Sleep(500);
	gotoxy(39,3);
	textcolor(WHITE,WHITE);
	showMonster(monsterModel2[user.monster.LV]);

	gotoxy(39,3);
	textcolor(BLACK,WHITE);
	showMonster(monsterModel[user.monster.LV]);

	gotoxy(23,10);
	textcolor(WHITE,WHITE);
	showModel(foodModel[3]);

	gotoxy(23,10);
	textcolor(RED2,WHITE);
	showModel(foodModel[4]);

	Sleep(500);
	upClearScreen();
	textcolor(BLACK,WHITE);
	return;
}

int evolution1()
{
	int i;
	user.monster.LV = 1;

	sndPlaySoundA("music\\evolution1.wav", SND_ASYNC | SND_NODEFAULT);
	clearScreen();

	textcolor(BLACK,WHITE);
	gotoxy(31,3);
	showMonster(monsterModel[user.monster.LV-1]);

	gotoxy(38,29);
	printf("엇 %s의 상태가?", user.monster.name);

	gotoxy(31,3);
	Sleep(500);
	textcolor(WHITE,WHITE);
	showMonster(monsterModel[user.monster.LV-1]);
	gotoxy(31,3);
	textcolor(BLACK,WHITE);
	showMonster(monsterModel[user.monster.LV]);
	gotoxy(31,3);
	Sleep(500);
	textcolor(WHITE,WHITE);
	showMonster(monsterModel[user.monster.LV]);

	for(i = 15; i > 0; i -= 1){
		textcolor(BLACK,WHITE);
		gotoxy(31,3);
		showMonster(monsterModel[user.monster.LV-1]);
		gotoxy(31,3);
		Sleep(i*10);
		textcolor(WHITE,WHITE);
		showMonster(monsterModel[user.monster.LV-1]);
		gotoxy(31,3);
		textcolor(BLACK,WHITE);
		showMonster(monsterModel[user.monster.LV]);
		gotoxy(31,3);
		Sleep(i*10);
		textcolor(WHITE,WHITE);
		showMonster(monsterModel[user.monster.LV]);
	}

	gotoxy(31,3);
	textcolor(BLACK,WHITE);
	showMonster(monsterModel[user.monster.LV]);

	gotoxy(32,29);
	printf("축하합니다 %s가 진화했습니다", user.monster.name);

	for(i = 0; i < 3; i++)
	{
		gotoxy(31,3);
		textcolor(BLACK,WHITE);
		showMonster(monsterModel[user.monster.LV]);
		Sleep(500);

		gotoxy(31,3);
		textcolor(WHITE,WHITE);
		showMonster(monsterModel[user.monster.LV]);

		gotoxy(31,3);
		textcolor(BLACK,WHITE);
		showMonster(monsterModel2[user.monster.LV]);

		Sleep(500);
		gotoxy(31,3);
		textcolor(WHITE,WHITE);
		showMonster(monsterModel2[user.monster.LV]);

		gotoxy(31,3);
		textcolor(BLACK,WHITE);
		showMonster(monsterModel[user.monster.LV]);
	}

	downClearScreen();
	return;
}

int evolution2()
{
	int i;

	sndPlaySoundA("music\\evolution2.wav", SND_ASYNC | SND_NODEFAULT);
	user.monster.LV = 2;
	clearScreen();

	textcolor(BLACK,WHITE);
	gotoxy(31,3);
	showMonster(monsterModel[user.monster.LV-1]);

	gotoxy(38,29);
	printf("엇 %s의 상태가?",user.monster.name);

	gotoxy(31,3);
	Sleep(500);
	textcolor(WHITE,WHITE);
	showMonster(monsterModel[user.monster.LV-1]);
	gotoxy(31,3);
	textcolor(BLACK,WHITE);
	showMonster(monsterModel[user.monster.LV]);
	gotoxy(31,3);
	Sleep(500);
	textcolor(WHITE,WHITE);
	showMonster(monsterModel[user.monster.LV]);

	for(i = 15; i > 0; i -= 1){
		textcolor(BLACK,WHITE);
		gotoxy(31,3);
		showMonster(monsterModel[user.monster.LV-1]);
		gotoxy(31,3);
		Sleep(i*10);
		textcolor(WHITE,WHITE);
		showMonster(monsterModel[user.monster.LV-1]);
		gotoxy(31,3);
		textcolor(BLACK,WHITE);
		showMonster(monsterModel[user.monster.LV]);
		gotoxy(31,3);
		Sleep(i*10);
		textcolor(WHITE,WHITE);
		showMonster(monsterModel[user.monster.LV]);
	}

	gotoxy(31,3);
	textcolor(BLACK,WHITE);
	showMonster(monsterModel[user.monster.LV]);

	gotoxy(32,29);
	printf("축하합니다 %s가 진화했습니다",user.monster.name);

	for(i = 0; i < 3; i++)
	{
		gotoxy(31,3);
		textcolor(BLACK,WHITE);
		showMonster(monsterModel[user.monster.LV]);
		Sleep(500);

		gotoxy(31,3);
		textcolor(WHITE,WHITE);
		showMonster(monsterModel[user.monster.LV]);

		gotoxy(31,3);
		textcolor(BLACK,WHITE);
		showMonster(monsterModel2[user.monster.LV]);

		Sleep(500);
		gotoxy(31,3);
		textcolor(WHITE,WHITE);
		showMonster(monsterModel2[user.monster.LV]);

		gotoxy(31,3);
		textcolor(BLACK,WHITE);
		showMonster(monsterModel[user.monster.LV]);
	}

	downClearScreen();
	return;
}

int evolution3()
{
	int i;

	sndPlaySoundA("music\\evolution3.wav", SND_ASYNC | SND_NODEFAULT);
	user.monster.LV = 3;
	clearScreen();

	textcolor(BLACK,WHITE);
	gotoxy(31,3);
	showMonster(monsterModel[user.monster.LV-1]);

	gotoxy(38,29);
	printf("엇 %s의 상태가?", user.monster.name);

	gotoxy(31,3);
	Sleep(500);
	textcolor(WHITE,WHITE);
	showMonster(monsterModel[user.monster.LV-1]);
	gotoxy(31,3);
	textcolor(BLACK,WHITE);
	showMonster(monsterModel[user.monster.LV]);
	gotoxy(31,3);
	Sleep(500);
	textcolor(WHITE,WHITE);
	showMonster(monsterModel[user.monster.LV]);

	for(i = 15; i > 0; i -= 1){
		textcolor(BLACK,WHITE);
		gotoxy(31,3);
		showMonster(monsterModel[user.monster.LV-1]);
		gotoxy(31,3);
		Sleep(i*10);
		textcolor(WHITE,WHITE);
		showMonster(monsterModel[user.monster.LV-1]);
		gotoxy(31,3);
		textcolor(BLACK,WHITE);
		showMonster(monsterModel[user.monster.LV]);
		gotoxy(31,3);
		Sleep(i*10);
		textcolor(WHITE,WHITE);
		showMonster(monsterModel[user.monster.LV]);
	}

	gotoxy(31,3);
	textcolor(BLACK,WHITE);
	showMonster(monsterModel[user.monster.LV]);

	gotoxy(32,29);
	printf("축하합니다 %s가 진화했습니다",user.monster.name);

	for(i = 0; i < 3; i++)
	{
		gotoxy(31,3);
		textcolor(BLACK,WHITE);
		showMonster(monsterModel[user.monster.LV]);
		Sleep(500);

		gotoxy(31,3);
		textcolor(WHITE,WHITE);
		showMonster(monsterModel[user.monster.LV]);

		gotoxy(31,3);
		textcolor(BLACK,WHITE);
		showMonster(monsterModel2[user.monster.LV]);

		Sleep(500);
		gotoxy(31,3);
		textcolor(WHITE,WHITE);
		showMonster(monsterModel2[user.monster.LV]);

		gotoxy(31,3);
		textcolor(BLACK,WHITE);
		showMonster(monsterModel[user.monster.LV]);
	}

	downClearScreen();
	return;
}

int hintScreen()
{
	int LOOP;
	clearScreen();

	gotoxy(23,28);
	printf("◎디지몬 세계에 오신것을 환영합니다");
	gotoxy(23,29);
	printf("◎진화는 총 3단계가 있으며 크레딧과 경험치는");
	gotoxy(23,30);
	printf("◎훈련을 통해 획득할 수 있습니다");
	gotoxy(23,31);
	printf("◎처음진화는 연습훈련을 진행하면 할 수있습니다");
	gotoxy(23,32);
	printf("◎그 다음 진화부터는 아이템이 필요합니다");
	gotoxy(23,33);
	printf("◎디지몬의 포만감을 유지시켜줘야 합니다");
	gotoxy(23,34);
	printf("◎포만감은 식사를 통해 채워집니다");
	gotoxy(23,35);
	printf("◎식사는 일정 크레딧이필요합니다");
	gotoxy(23,36);
	printf("◎hard traning은 경험치와 크레딧이 랜덤입니다");
	gotoxy(23,37);
	printf("◎힌트창을 끄려면 아무키나 누르세요");
	for(LOOP = 0; LOOP < 5; LOOP++)
	{
		textcolor(WHITE,3+LOOP);
		gotoxy(27,6);
		printf(" /$$   /$$ /$$$$$$ /$$   /$$ /$$$$$$$$");
		gotoxy(27,7);
		printf("| $$  | $$|_  $$_/| $$$ | $$|__  $$__/");
		gotoxy(27,8);
		printf("| $$  | $$  | $$  | $$$$| $$   | $$   ");
		gotoxy(27,9);
		printf("| $$$$$$$$  | $$  | $$ $$ $$   | $$   ");
		gotoxy(27,10);
		printf("| $$__  $$  | $$  | $$  $$$$   | $$   ");
		gotoxy(27,11);
		printf("| $$  | $$  | $$  | $$ \  $$$   | $$   ");
		gotoxy(27,12);
		printf("| $$  | $$ /$$$$$$| $$  \  $$   | $$   ");
		gotoxy(27,13);
		printf("|__/  |__/|______/|__/   \__/   |__/   ");

		Sleep(300);

		textcolor(WHITE,13-LOOP);
		gotoxy(27,6);
		printf("$$\\     $$\\ $$$$$$\\$$\\  $$  \\$$$$$$$$\\");
		gotoxy(27,7);
		printf("$$ |  $$ |\\_$$  _|$$$\\  $$ |\\__$$  __|");
		gotoxy(27,8);
		printf("$$ |  $$ |  $$ |  $$$$\\ $$ |   $$ |   ");
		gotoxy(27,9);
		printf("$$$$$$$$ |  $$ |  $$ $$\\$$ |   $$ |   ");
		gotoxy(27,10);
		printf("$$  __$$ |  $$ |  $$ \\$$$$ |   $$ |   ");
		gotoxy(27,11);
		printf("$$ |  $$ |  $$ |  $$ |\\$$$ |   $$ |   ");
		gotoxy(27,12);
		printf("$$ |  $$ |$$$$$$\\ $$ | \\$$ |   $$ |   ");
		gotoxy(27,13);
		printf("\\__|  \\__|\\______|\\__|  \\__|   \\__|   ");

		Sleep(300);
	}

	getch();
	clearScreen();
	return;
}

int monsterMove()
{
	int LOOP;
	clearScreen();

	for(LOOP = 40; LOOP >= 24; LOOP -= 2)
	{
		if(LOOP%3 == 0)
		{
			gotoxy(LOOP,3);
			showMonster(monsterModel2[user.monster.LV]);
			Sleep(1000);
			upClearScreen();
			continue;
		}
		gotoxy(LOOP,3);
		showMonster(monsterModel[user.monster.LV]);
		Sleep(1000);
		upClearScreen();
	}

	for(LOOP = 24; LOOP <= 40; LOOP += 2)
	{
		if(LOOP%3 == 0)
		{
			gotoxy(LOOP,3);
			showMonster(monsterModel2[user.monster.LV]);
			Sleep(1000);
			upClearScreen();
			continue;
		}
		gotoxy(LOOP,3);
		showMonster(monsterModel[user.monster.LV]);
		Sleep(1000);
		upClearScreen();
	}
}
