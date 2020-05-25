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
	float influence(uint8_t type);//“Š•[‚Ì‰e‹¿—Í
	bool output(string str, bool nl = false);
	Agent agent[Agent::N];
	int n_v[N_GAMES][2];//A,B‚»‚ê‚¼‚ê‚Ì“Š•[”
	int i_game=0;//100‰ñ‚Ì“Š•[‚Ì‚¤‚¿A‰½‰ñ–Ú‚Ì“Š•[‚©(0-index)
	float f_n_inf(float x);//x: ‘O‰ñ‚É“Š•[‚µ‚½l‚Ì’†‚ÌA‚Ü‚½‚ÍB‚ÌŠ„‡Breturn: Å‘å’l=1‚Æ‚µ‚Ä³‹K‰»‚³‚ê‚½“Š•[‰e‹¿—Í
	const char* filename = ".\\out.csv";
	ofstream ofs;
};