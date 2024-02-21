#include <Jiggle.h>

class SpringBox : public Jiggle::Application {
public:
	SpringBox(){

	}

	~SpringBox() {

	}
};

Jiggle::Application* Jiggle::CreateApplication()
{
	return new SpringBox();
}