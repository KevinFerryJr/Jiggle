#pragma once

#include "Core.h"

namespace Jiggle {
	class JIGGLE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
}