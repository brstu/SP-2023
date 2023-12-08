#include "doctor.h"
#include <Windows.h>
#include <random>

void doctor::treatment(std::deque<patient>& patients, std::mutex& Mutex, std::deque<patient>& healthyPatients, std::mutex& healthyPatientMutex)
{
	/*while (healthyPatients.size() != 5) {
		Mutex.lock();
		patient p;
		if (patients.empty()) {
			Mutex.unlock();
			std::cout << name << std::endl;
			continue;
		}
		else {
			p = patients.front();
			patients.pop_front();
			Sleep(5);
		}
		Mutex.unlock();
		std::vector<int>::iterator it;
		it = std::ranges::find(p.diseases.begin(), p.diseases.end(), diseaseIndex);
		if (it == p.diseases.end()) {
			Mutex.lock();
			patients.push_front(p);
			Mutex.unlock();
			continue;
		}
		else {
			p.diseases.erase(it);
			std::random_device rd{};
			std::uniform_int_distribution distrib(0, 1);
			int index = distrib(rd);
			std::cout << name << actions[index] << p.name << std::endl;
			Sleep(1000 * treatmentTime);
			std::cout << name << " вылечил " << p.name << " от " << p.diseasesName[diseaseIndex - 1] << std::endl;
			if (p.diseases.empty()) {
				healthyPatientMutex.lock();
				healthyPatients.push_back(p);
				healthyPatientMutex.unlock();
			}
			else {
				Mutex.lock();
				patients.push_front(p);
				Mutex.unlock();
			}
		}
	}*/

	while (healthyPatients.size() != 5) {
		patient p;
		Mutex.lock();
		if (!patients.empty()) {
			p = patients.front();
			patients.pop_front();
			Sleep(5);
			Mutex.unlock();
		}
		else {
			Mutex.unlock();
			continue;
		}
		std::vector<int>::iterator it;
		it = std::ranges::find(p.diseases.begin(), p.diseases.end(), diseaseIndex);
		if (it == p.diseases.end()) {
			Mutex.lock();
			patients.push_back(p);
			Mutex.unlock();
			continue;
		}
		else {
			p.diseases.erase(it);
			std::random_device rd{};
			std::uniform_int_distribution distrib(0, 1);
			int index = distrib(rd);
			std::cout << name << actions[index] << p.name << std::endl;
			Sleep(1000 * treatmentTime);
			std::cout << name << " вылечил " << p.name << " от " << p.diseasesName[diseaseIndex - 1] << std::endl;
			if (p.diseases.empty()) {
				healthyPatientMutex.lock();
				std::cout << p.name << " выписывается из больницы" << std::endl;
				healthyPatients.push_back(p);
				healthyPatientMutex.unlock();
			}
			else {
				Mutex.lock();
				patients.push_back(p);
				Mutex.unlock();
			}
		}
	}
}
