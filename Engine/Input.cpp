#include "Input.h"
#include "GameEngine.h"
#include "InitError.h"
#include <iostream>

Input* Input::m_instance = nullptr;
SDL_GameController* controller = nullptr;

Input::Input()
{
	m_keyStates = SDL_GetKeyboardState(nullptr);
	m_controllerStates = nullptr;

	if (SDL_Init(SDL_INIT_GAMECONTROLLER) < 0)
	{
		std::cout << "ERROR: Game Controller failed to initialize" << std::endl;
		throw InitError();
	}
	if (SDL_NumJoysticks() < 1)
	{
		std::cout << "WARNING: No Gamepad detected" << std::endl;
	}
	else
	{
		controller = SDL_GameControllerOpen(0);
	}
}

Input::~Input()
{
	delete m_keyStates;
	delete m_controllerStates;
	delete m_instance;
}

void Input::Listen()
{
	switch (GameEngine::event.type)
	{
	case SDL_KEYDOWN:
		KeyDown();
		break;
	case SDL_KEYUP:
		KeyUp();
		break;
	case SDL_CONTROLLERBUTTONDOWN:
		ButtonUp();
		break;
	case SDL_CONTROLLERBUTTONUP:
		ButtonDown();
		break;
	}
}

bool Input::GetKeyDown(SDL_Scancode key)
{
	//Returns true if key is being pushed down
	if (m_keyStates[key] == 1)
	{
		return true;
	}
	return false;
}

bool Input::GetKeyUp(SDL_Scancode key)
{
	if (m_keyStates[key] == 0)
	{
		return true;
	}
	return false;
}

bool Input::GetButtonDown(SDL_GameControllerButton button)
{
	//Returns true if key is being pushed down
	if (m_keyStates[button] == 1)
	{
		std::cout << "Pressing a button" << std::endl;
		return true;
	}
	return false;
}

bool Input::GetButtonUp(SDL_GameControllerButton button)
{
	if (m_keyStates[button] == 0)
	{
		return true;
	}
	return false;
}

void Input::KeyUp()
{

}

void Input::KeyDown()
{

}

void Input::ButtonUp()
{
}

void Input::ButtonDown()
{
}
