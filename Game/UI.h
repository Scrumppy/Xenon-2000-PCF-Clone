#pragma once

#include "EntityComponentSystem.h"

class UI : public Entity
{
public:
	UI();
	~UI();

	virtual void Init() = 0;
	virtual void Update() = 0;
};