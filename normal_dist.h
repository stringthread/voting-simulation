#pragma once
#include <random>
using namespace std;
class normal_dist {
public:
	static random_device device;
	static default_random_engine engine;
	normal_distribution<float> dist;
	normal_dist(float ave = 0.f, float sd = 1.f) {
		set_param(ave, sd);
	}
	float operator()();
	void set_param(float ave, float sd);
};