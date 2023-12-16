#pragma once
#ifndef PSYCHIATRIST_H
#define PSYCHIATRIST_H

#include "doctor.h"

class psychiatrist : public doctor {
public:
	psychiatrist();
	void printInfo() override;
};

#endif