#include <Jiggle.h>

class Sandbox : public Jiggle::Application {
public:
	Sandbox(){

	}

	~Sandbox() {

	}
};

void main() {
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}
