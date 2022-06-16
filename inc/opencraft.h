#pragma once
#ifndef OPENCRAFT_H
#define OPENCRAFT_H

#include <geodesuka/engine.h>

#include <geodesuka/builtin/object/triangle.h>

#include <geodesuka/builtin/stage/example.h>

using namespace geodesuka;
using namespace core;
using namespace gcl;
using namespace object;
using namespace builtin::object;

class opencraft : public app {
public:

	opencraft(engine* aEngine, int aCmdArgCount, char* aCmdArgList[]);
	~opencraft();

protected:

	virtual void run() override;

private:

	system_window::property Property;

	// Main context for game
	context* Context;
	builtin::stage::example *Example;
	//system_window* Window1;
	//system_window* Window2;
	//system_window* Window3;
	//system_window* Window4;
	//system_display* Display;
	//triangle *Triangle;

};

#endif // !OPENCRAFT_H
