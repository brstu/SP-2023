#pragma once
#include <string>
#include <vector>
#ifndef PATIENT_H
#define PATIENT_H

class patient {
public:
	std::vector<std::string> illnessMap = { "heart disease","tooth decay", "ear studs" };
	std::string name;
	std::vector<int> illnesses;
	patient();
	explicit patient(const std::string& _name);
	void getData();
};

#endif