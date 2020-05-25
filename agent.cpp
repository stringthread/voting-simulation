#include "agent.h"
#include "manager.h"
float Agent::o_avg[] = { 100.0f,50.0f };
int Agent::n_a = 10;
normal_dist Agent::gen_o_cost[] = { normal_dist(Agent::o_avg[0],Agent::o_avg[0] / 2),normal_dist(Agent::o_avg[1],Agent::o_avg[1] / 2) };
Agent::Agent(uint8_t type,shared_ptr<Manager> manager){
	this->type = type;
	this->manager = manager;
	this->o_cost = Agent::gen_o_cost[type]();
}
void Agent::reset() {
	score = 0.f;
	o_cost = gen_o_cost[type]();
}
int Agent::do_vote() {
	return manager->influence(type) < o_cost ? 0 : 1;
}