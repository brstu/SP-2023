#pragma once
#ifndef DENTIST_H
#define DENTIST_H

#include "doctor.h"

class	dentist : public doctor {
public:
	dentist();
	void getData() override;
};

#endif