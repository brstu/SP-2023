#pragma once
#ifndef DOCTOR_H
#define DOCTOR_H
#include <string>
#include <vector>
#include <queue>
#include <mutex>
#include "patient.h"

class doctor {
public:
	std::string name;
	int maxTime;
	int illnessNum;
	std::vector<std::string> methods;
	void cureProc(std::deque<patient>& patients, std::mutex& p_mutex, std::deque<patient>& curedPatients, std::mutex& curedMutex);
	void virtual getData() = 0;
};

#endif