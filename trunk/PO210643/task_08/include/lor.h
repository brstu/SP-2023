#pragma once
#ifndef LOR_H
#define LOR_H

#include "doctor.h"

class	lor : public doctor {
public:
	lor();
	void getData() override;
};

#endif