#pragma once
#include "header.h"
#include "normal_dist.h"

class Manager;

class Agent {
private:
	uint8_t type;//A(���@���p�O���[�v)��0
	float o_cost;//���[�̋@���p
	shared_ptr<Manager> manager;
	float score=0.f;//�Q�[���S�̂œ����X�R�A���v
public:
	Agent(){}
	Agent(uint8_t type,shared_ptr<Manager> manager);
	static int n_a;//A(���@���p�O���[�v)�̐l���FManager�œK�X�ύX
	static float o_avg[];//A,B���ꂼ��̋@���p���ϒl
	static constexpr int N = 100;//Agent����
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
	int do_vote();//���[����ꍇ1,���Ȃ��ꍇ0��Ԃ�
};
