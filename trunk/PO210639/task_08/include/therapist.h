#pragma once
#ifndef THERAPIST_H
#define THERAPIST_H

#include "doctor.h"

class therapist : public doctor {
public:
	therapist();
	void printInfo() override;
};

#endif