#pragma once
#ifndef NEUROLOGIST_H
#define NEUROLOGIST_H

#include "doctor.h"

class neurologist : public doctor {
public:
	neurologist();
	void printInfo() override;
};

#endif