#include "manager.h"
Manager::Manager() {
	ofs.open(filename);
}
Manager::~Manager() {
	ofs.close();
	delete[] &agent;
}
void Manager::init() {
	int i = 0;
	for (; i < Agent::n_a; i++) {
		agent[i] = Agent(0, shared_from_this());
	}
	for (; i < Agent::N; i++) {
		agent[i] = Agent(1, shared_from_this());
	}
}
void Manager::reset(){
	int i = 0;
	for (; i < Agent::n_a; i++) {
		agent[i].set_type(0);
	}
	for (; i < Agent::N; i++) {
		agent[i].set_type(1);
	}
}
void Manager::do_game() {
	for (i_game = 0; i_game < N_GAMES; i_game++) {
		n_v[i_game][0] = 0;
		n_v[i_game][1] = 0;
		for (int i = 0; i < 100; i++) {
			n_v[i_game][agent[i].get_type()]+=agent[i].do_vote();
		}
		uint8_t loser;
		float share;
		if (n_v[i_game][0] > n_v[i_game][1]) {
			loser = 1;
			share = M / Agent::n_a;
		} else if(n_v[i_game][0] < n_v[i_game][1]) {
			loser = 0;
			share = M / (Agent::N - Agent::n_a);
		} else {
			loser = -1;
			share = M / Agent::N;
		}
		for (int i = 0; i < 100; i++) {
			if (agent[i].get_type() != loser)agent[i].add_score(share);
		}
		output(to_string(n_v[i_game][0]/*+n_v[i_game][1]*/),i_game==N_GAMES-1);
	}
}
float Manager::influence(uint8_t type) {
	float ret = (float)M / (type == 0 ? (Agent::n_a) : (Agent::N - Agent::n_a));
	if (i_game == 0) {
		ret *= f_n_inf((float)(type==0?(Agent::n_a):(Agent::N-Agent::n_a)) / (Agent::N));
	} else {
		ret *= f_n_inf((float)(n_v[i_game - 1][type]) / (n_v[i_game - 1][0] + n_v[i_game - 1][1]));
	}
	return ret;
}
float Manager::f_n_inf(float x) {
	return 1.f - pow(x, 2);
}
bool Manager::output(string str,bool nl) {
	if (!ofs)return false;
	ofs << str;
	if (nl)ofs << endl;
	else ofs << ",";
	return true;
}
int main() {
	shared_ptr<Manager> manager=make_shared<Manager>();
	manager->init();
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 1; k++) {
				manager->do_game();
			}
			Agent::next_o_avg();
			for (int k = 0; k < Agent::N; k++) {
				manager->agent[k].reset();
			}
		}
		Agent::next_n_a();
		manager->reset();
	}
	return 0;
}