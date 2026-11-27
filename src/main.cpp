#include "platform.hpp"

int main()
{
	olivia::platform::init("olivia", 800, 600);

	for (;;)
	{
		olivia::platform::poll_events();

		if (!olivia::platform::is_running())
			break;
	}

	olivia::platform::quit();
	return 0;
}