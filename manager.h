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
	float influence(uint8_t type);//投票の影響力
	bool output(string str, bool nl = false);
	Agent agent[Agent::N];
	int n_v[N_GAMES][2];//A,Bそれぞれの投票数
	int ave_n_v[2] = {0,0};//投票者に占めるA,Bの比率を各回平均したもの
	int i_game=0;//100回の投票のうち、何回目の投票か(0-index)
	float f_n_inf(float x);//x: 前回に投票した人の中のAまたはBの割合。return: 最大値=1として正規化された投票影響力
	const char* filename = ".\\out.csv";
	ofstream ofs;
};