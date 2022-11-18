#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<ctime>
#include<time.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define IDR_WAVE1                       101

using namespace std;
int main() {
	HWND hwnd = GetForegroundWindow();
	ShowWindow(hwnd, 0);
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int xs = ltm->tm_hour;
	int fen = ltm->tm_min;
	int miao = ltm->tm_sec;
	int q1 = xs;
	int q2 = fen;
	q2 = fen + 46;
	if (fen >= 60) {
		q1 = q1 + 1;
		q2 = q2 - 60;
		if (q1 > 24) {
			q1 = 0;
		}
	}
	while (1) {
		time_t now = time(0);
		tm* ltm = localtime(&now);
		int xs = ltm->tm_hour;
		int fen = ltm->tm_min;
		int miao = ltm->tm_sec;
		if (xs == q1) {
			if (fen == q2) {
					PlaySound(MAKEINTRESOURCE(IDR_WAVE1), GetModuleHandle(NULL), SND_RESOURCE | SND_SYNC);
					return 0;
			}
		}
		Sleep(3999);
	}
	return 0;
}
