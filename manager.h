#pragma once
#include "header.h"
#include "agent.h"
#include <iostream>
#include <fstream>
class Manager:public enable_shared_from_this<Manager> {
public:
	Manager();
	~Manager();
	const int M = 10000;
	static constexpr int N_GAMES = 100;
	void init();
	void reset();
	void do_game();
	float influence(uint8_t type);//���[�̉e����
	bool output(string str, bool nl = false);
	Agent agent[Agent::N];
	int n_v[N_GAMES][2];//A,B���ꂼ��̓��[��
	int i_game=0;//100��̓��[�̂����A����ڂ̓��[��(0-index)
	float f_n_inf(float x);//x: �O��ɓ��[�����l�̒���A�܂���B�̊����Breturn: �ő�l=1�Ƃ��Đ��K�����ꂽ���[�e����
	const char* filename = ".\\out.csv";
	ofstream ofs;
};