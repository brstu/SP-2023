#include "doctor.h"
#include <Windows.h>
#include <random>

void doctor::cureProc(std::deque<patient>& patients, std::mutex& p_mutex, std::deque<patient>& curedPatients, std::mutex& curedMutex)
{
	while (curedPatients.size() != 4) {
		patient patient;
		if (true) {
			std::scoped_lock<std::mutex> lock(p_mutex);
			if (!patients.empty()) {
				patient = patients.front();
				patients.pop_front();
				Sleep(5);
			}
			else {
				continue;
			}
		}
		std::vector<int>::iterator it;
		it = std::ranges::find(patient.illnesses.begin(), patient.illnesses.end(), illnessNum);
		if (it == patient.illnesses.end()) {
			std::scoped_lock<std::mutex> lock(p_mutex);
			patients.push_back(patient);
			continue;
		}
		else {
			patient.illnesses.erase(it);
			std::random_device rand_device{};
			std::uniform_int_distribution dist(0, 1);
			int index = dist(rand_device);
			std::cout << name << methods[index] << patient.name << std::endl;
			Sleep(1000 * maxTime);
			std::cout << name << " cured " << patient.name << "'s  " << patient.illnessMap[illnessNum - 1] << std::endl;
			if (patient.illnesses.empty()) {
				std::scoped_lock<std::mutex> lock(curedMutex);
				std::cout << patient.name << " is safe and sound" << std::endl;
				curedPatients.push_back(patient);
			}
			else {
				std::scoped_lock<std::mutex> lock(p_mutex);
				patients.push_back(patient);
			}
		}
	}
}