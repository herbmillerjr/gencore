#pragma once
#include <SDL.h>
#include "actor.h"

using Keys=std::unordered_map<SDL_Keycode,bool>;

class State
{
public:
	State();
	void KeyDown(SDL_Keycode key);
	void KeyUp(SDL_Keycode key);
	const ::Keys& Keys() const;
	virtual void Update()=0;
	virtual void Present()=0;
protected:
	::Keys keys;
};

class TestState : public State
{
public:
	TestState();
	void Update() override;
	void Present() override;
protected:
	Player player;
};