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
	int treatmentTime;
	int diseaseIndex;
	std::vector<std::string> actions;
	void treatment(std::deque<patient>& patients, std::mutex& Mutex, std::deque<patient>& healthyPatients, std::mutex& healthyPatientMutex);
	void virtual printInfo() = 0;
};

#endif