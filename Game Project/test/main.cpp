#include "testApp.h"

int main() {
	
	// allocation
	auto app = new testApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;
	//checking memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return 0;
}