#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/hospitalDLL.h"
#include <queue>
#include <Windows.h>
#include <mutex>
#include <algorithm>
#include <random>

int getMaxtime(std::ifstream& in, std::string temp);

std::string getName(std::ifstream& in, std::string temp);

void getIllness(std::ifstream& in, std::string temp, patient& patient);

void management(doctor* d, std::deque<patient>& patients, std::mutex& p_mutex, std::deque<patient>& curedPatients, std::mutex& curedMutex);

int main() {
	std::random_device rand_device;
	std::ifstream in("HospitalData.txt", std::ios::in);
	cardiologist card_doctor;
	dentist dent_doctor;
	lor lor_doctor;
	std::deque<patient> patients;
	if (in.is_open()) {
		std::string temp;

		card_doctor.maxTime = getMaxtime(in, temp);
		dent_doctor.maxTime = getMaxtime(in, temp);
		lor_doctor.maxTime = getMaxtime(in, temp);

		for (int i = 0; i < 4; i++) {
			patient patient(getName(in, temp));
			getIllness(in, temp, patient);
			patients.push_back(patient);
		}
	}
	in.close();

	card_doctor.getData();
	dent_doctor.getData();
	lor_doctor.getData();


	for (int i = 0; i < 4; i++) {
		patients.front().getData();
		patient patient = patients.front();
		patients.pop_front();
		patients.push_back(patient);
	}

	std::cout << std::endl;

	std::mutex p_mutex;
	std::mutex curedMutex;

	std::vector<doctor*> doctors;

	doctors.push_back(&card_doctor);
	doctors.push_back(&dent_doctor);
	doctors.push_back(&lor_doctor);


	std::deque<patient> curedPatients;

	std::jthread t1(management, std::ref(doctors[0]), std::ref(patients), std::ref(p_mutex), std::ref(curedPatients), std::ref(curedMutex));
	std::jthread t2(management, std::ref(doctors[1]), std::ref(patients), std::ref(p_mutex), std::ref(curedPatients), std::ref(curedMutex));
	std::jthread t3(management, std::ref(doctors[2]), std::ref(patients), std::ref(p_mutex), std::ref(curedPatients), std::ref(curedMutex));


	t1.join();
	t2.join();
	t3.join();

	std::cout << "All patients are cured" << std::endl;
	return 0;
}

int getMaxtime(std::ifstream& in, std::string temp)
{
	getline(in, temp, '\r');
	int time;
	std::istringstream(temp) >> time;
	return time;
}

std::string getName(std::ifstream& in, std::string temp)
{
	getline(in, temp, '\r');
	return temp;
}

void getIllness(std::ifstream& in, std::string temp, patient& patient)
{


	getline(in, temp, '\r');

	int pos = 0;
	std::string delimiter = ",";
	while ((pos = temp.find(delimiter)) != std::string::npos) {
		std::string tempStr;
		tempStr = temp.substr(0, pos);
		int index;
		std::istringstream(tempStr) >> index;
		patient.illnesses.push_back(index);
		temp.erase(0, pos + delimiter.length());
	}
	int index;
	std::istringstream(temp) >> index;
	patient.illnesses.push_back(index);
}

void management(doctor* d, std::deque<patient>& patients, std::mutex& p_mutex, std::deque<patient>& curedPatients, std::mutex& curedMutex)
{
	d->cureProc(patients, p_mutex, curedPatients, curedMutex);
}