#include <Jiggle.h>

class Sandbox : public Jiggle::Application {
public:
	Sandbox(){

	}

	~Sandbox() {

	}
};

Jiggle::Application* Jiggle::CreateApplication()
{
	return new Sandbox();
}