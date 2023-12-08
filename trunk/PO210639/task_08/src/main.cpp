#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/hospitalLibrary.h"
#include <queue>
#include <Windows.h>
#include <mutex>

int recieveTime(std::ifstream& in, std::string temp);

std::string recieveName(std::ifstream& in, std::string temp);

void recieveDiseases(std::ifstream& in, std::string temp, patient& p);

void hospitalWork(doctor* d, std::deque<patient>& patients, std::mutex& Mutex, std::deque<patient>& healthyPatients, std::mutex& healthyPatientMutex);

int main() {
	srand(0);
	setlocale(LC_ALL, "rus");
	system("color f0");
	std::ifstream in("data.txt", std::ios::in);
	std::string temp;
	neurologist neurologistDoc;
	therapist therapistDoc;
	psychiatrist psychiatristDoc;
	std::deque<patient> patients;
	if (in.is_open()) {
		std::cout << "получение информации" << std::endl;

		neurologistDoc.treatmentTime = recieveTime(in, temp);
		therapistDoc.treatmentTime = recieveTime(in, temp);
		psychiatristDoc.treatmentTime = recieveTime(in, temp);

		for (int i = 0; i < 5; i++) {
			patient p(recieveName(in, temp));
			recieveDiseases(in, temp, p);
			patients.push_back(p);
		}
	}
	in.close();

	neurologistDoc.printInfo();
	psychiatristDoc.printInfo();
	therapistDoc.printInfo();

	for (int i = 0; i < 5; i++) {
		patients.front().printInfo();
		patient p = patients.front();
		patients.pop_front();
		patients.push_back(p);
	}

	std::cout << std::endl;

	std::mutex Mutex;
	std::mutex healthyPatientMutex;

	std::vector<doctor*> doctors;

	doctors.push_back(&neurologistDoc);
	doctors.push_back(&therapistDoc);
	doctors.push_back(&psychiatristDoc);


	std::deque<patient> healthyPatients;

	std::jthread t1(hospitalWork, std::ref(doctors[0]), std::ref(patients), std::ref(Mutex), std::ref(healthyPatients), std::ref(healthyPatientMutex));
	std::jthread t2(hospitalWork, std::ref(doctors[1]), std::ref(patients), std::ref(Mutex), std::ref(healthyPatients), std::ref(healthyPatientMutex));
	std::jthread t3(hospitalWork, std::ref(doctors[2]), std::ref(patients), std::ref(Mutex), std::ref(healthyPatients), std::ref(healthyPatientMutex));


	t1.join();
	t2.join();
	t3.join();

	std::cout << "Все пациенты здоровы" << std::endl;
	return 0;
}

int recieveTime(std::ifstream& in, std::string temp)
{
	getline(in, temp, '\n');
	int time;
	std::istringstream(temp) >> time;
	return time;
}

std::string recieveName(std::ifstream& in, std::string temp)
{
	getline(in, temp, '\n');
	return temp;
}

void recieveDiseases(std::ifstream& in, std::string temp, patient& p)
{
	getline(in, temp, '\n');

	int pos = 0;
	std::string delimiter = " ";
	std::string tempStr;
	while ((pos = temp.find(delimiter)) != std::string::npos) {
		tempStr = temp.substr(0, pos);
		int index;
		std::istringstream(tempStr) >> index;
		p.diseases.push_back(index);
		temp.erase(0, pos + delimiter.length());
	}
	int index;
	std::istringstream(temp) >> index;
	p.diseases.push_back(index);
}

void hospitalWork(doctor* d, std::deque<patient>& patients, std::mutex& Mutex, std::deque<patient>& healthyPatients, std::mutex& healthyPatientMutex)
{
	d->treatment(patients, Mutex, healthyPatients, healthyPatientMutex);
}
