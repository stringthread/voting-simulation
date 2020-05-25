#pragma once
#include "header.h"
#include "normal_dist.h"

class Manager;

class Agent {
private:
	uint8_t type;//A(高機会費用グループ)が0
	float o_cost;//投票の機会費用
	shared_ptr<Manager> manager;
	float score=0.f;//ゲーム全体で得たスコア合計
public:
	Agent(){}
	Agent(uint8_t type,shared_ptr<Manager> manager);
	static int n_a;//A(高機会費用グループ)の人数：Managerで適宜変更
	static float o_avg[];//A,Bそれぞれの機会費用平均値
	static constexpr int N = 100;//Agent総数
	static void next_n_a() {
		Agent::n_a += 10;
	}
	static void next_o_avg() {
		o_avg[0] +=50.f;
		if (o_avg[0] > 500.f)o_avg[0] = 50.f;
		gen_o_cost[0].set_param(Agent::o_avg[0], Agent::o_avg[0] / 2);
	}
	static normal_dist gen_o_cost[2];
	void reset();
	float get_score() { return score; }
	void add_score(float diff) { score += diff; }
	uint8_t get_type() { return type; }
	void set_type(uint8_t type) {
		this->type = type;
		this->o_cost = Agent::gen_o_cost[type]();
	}
	int do_vote();//投票する場合1,しない場合0を返す
};
