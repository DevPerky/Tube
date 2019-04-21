#include "tbpch.h"
#include <Tube.h>

class Sandbox : public Tube::Application{
public:

	Sandbox() {

	}

	~Sandbox() {

	}

};

Tube::Application* Tube::CreateApplication() {
	return new Sandbox();
}
