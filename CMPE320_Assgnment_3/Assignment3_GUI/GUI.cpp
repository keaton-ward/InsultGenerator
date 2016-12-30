#include "GUI.h"

using namespace Assignment3_GUI; //the project name in your header file

int main(int argc, char** argv) {
	int* result = addition(1, 2, 3, 4);
	Application::Run(gcnew GUI{});
	return 0;
}