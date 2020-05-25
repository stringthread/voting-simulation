#include "normal_dist.h"
float normal_dist::operator()() {
	dist.reset();
	float ret = dist(engine);
	return ret;
}
void normal_dist::set_param(float ave, float sd) {
	normal_distribution<float>::param_type param(ave, sd);
	dist.param(param);
}
random_device normal_dist::device;
default_random_engine normal_dist::engine(normal_dist::device());
