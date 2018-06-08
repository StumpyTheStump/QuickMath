#include "MathAppApp.h"

int main() {
	
	// allocation
	auto app = new MathAppApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}