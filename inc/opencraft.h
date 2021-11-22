#pragma once
#ifndef OPENCRAFT_H
#define OPENCRAFT_H

#include <geodesuka/engine.h>

using namespace geodesuka;
using namespace core;
using namespace gcl;
using namespace object;
// 
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


};

#endif // !OPENCRAFT_H
