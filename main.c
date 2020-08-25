#include <SDL.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_bool done = SDL_FALSE;

	SDL_Window *window = SDL_CreateWindow("ime_test",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			100, 100,
			0);

	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = 100;
	rect.h = 100;

	SDL_StartTextInput();
	SDL_SetTextInputRect( &rect );
	while (!done) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					/* quitting */
					done = SDL_TRUE;
					break;
				case SDL_TEXTINPUT:
					/* new finalised text has been entered */
					printf("Input: %s\n", event.text.text);
					break;
				case SDL_TEXTEDITING:
					/* new still-in-composition text has been entered */
					printf("Current composition text: %s (cursor position within text: %d, selection length: %d)\n",
							event.edit.text,
							event.edit.start,
							event.edit.length);
					break;
			}
		}
		SDL_Delay(30);
	}

	SDL_DestroyWindow( window );
	SDL_Quit();

	return 0;
}

