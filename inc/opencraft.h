#pragma once
#ifndef OPENCRAFT_H
#define OPENCRAFT_H

#include <geodesuka/engine.h>

class opencraft : public geodesuka::core::app {
public:

	opencraft(geodesuka::engine* aEngine, int argc, char* argv[]);
	~opencraft();

	virtual void run() override;

private:

	geodesuka::core::gcl::context* Context;


};

#endif // !OPENCRAFT_H
