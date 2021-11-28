#pragma once
#ifndef OPENCRAFT_H
#define OPENCRAFT_H

#include <geodesuka/engine.h>

#include <geodesuka/builtin/object/triangle.h>

using namespace geodesuka;
using namespace core;
using namespace gcl;
using namespace object;
using namespace builtin::object;

class opencraft : public app {
public:

	opencraft(engine* aEngine, int argc, char* argv[]);
	~opencraft();

	virtual void gameloop() override;

private:

	// Main context for game
	context* Context;
	system_window* Window;
	system_window* Window1;
	system_window* Window2;

	triangle *Triangle;

};

#endif // !OPENCRAFT_H
