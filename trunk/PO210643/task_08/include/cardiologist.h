#pragma once
#ifndef CARDIOLOGIST_H
#define CARDIOLOGIST_H

#include "doctor.h"

class	cardiologist : public doctor {
public:
	cardiologist();
	void getData() override;
};

#endif