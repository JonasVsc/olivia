#include "platform.hpp"
#include "types.hpp"

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_hints.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_video.h>

namespace olivia::platform
{
	struct Platform_T
	{
		bool running = false;
		SDL_Window* window = nullptr;
	};

	static Platform_T platform{};

	Result init(const char* title, uint32_t width, uint32_t height)
	{
#ifdef linux
		if (!SDL_SetHint(SDL_HINT_VIDEO_DRIVER, "x11"))
			return eError;
#endif

		if (!SDL_Init(SDL_INIT_VIDEO))
			return eError;

		SDL_Window* window =
			SDL_CreateWindow(title, static_cast<int>(width),
							 static_cast<int>(height), SDL_WINDOW_VULKAN);

		if(!window)
			return eError;

		platform.window = window;
		platform.running = true;

		return eSuccess;
	}

	void quit()
	{
		if(platform.window)
			SDL_DestroyWindow(platform.window);
		
		SDL_Quit();
	}

	void poll_events()
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
				platform.running = false;
				break;
			default:
				break;
			}
		}
	}

    bool is_running()
	{
		return platform.running;
	}

} // namespace olivia::platform