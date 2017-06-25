#include "Application2D.h"
#include "UnitTest.h"

int main() 
{
	UnitTest unitTest;
	if (unitTest.Test() == true)
	{
		Application2D* app = new Application2D();
		app->run("AIE", 1280, 720, false);
		delete app;
	}
	return 0;
}