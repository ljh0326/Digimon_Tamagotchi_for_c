/*
	2017-06-06
	트레이닝에 관련 함수 헤더
*/

#ifndef __TRAINING_H__
#define __TRAINING_H__

int practiceTraining();    //연습 훈련과 관련된 함수와 결과함수
int PracticeResult(int ResultStage, int ResultScore, int ResultPlayTime, int ResultCollision); 
int easyTraining();        //이지 트레이닝 함수와 결과함수
int easyPracticeResult(int ResultStage, int ResultTapTapScore, int ResultPlayTime, int ResultCollision); 
int hardTraining();        //하드 트레이닝 함수와 결과함수
int hardTrainingResult(int ResultScore, int ResultCP5, int ResultCP6, int ResultCP7, int ResultCP8, int ResultCP9, int ResultLife); 

#endif __TRAINING_H__