#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

int getch();

#define ANSI_COLOR_BLACK   "\x1b[30m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define ANSI_BG_BLACK   "\x1b[40m"
#define ANSI_BG_RED     "\x1b[41m"
#define ANSI_BG_GREEN   "\x1b[42m"
#define ANSI_BG_YELLOW  "\x1b[43m"
#define ANSI_BG_BLUE    "\x1b[44m"
#define ANSI_BG_BAGNETA "\x1b[45m" #define ANSI_BG_CYAN    "\x1b[46m"
#define ANSI_BG_WHITE   "\x1b[47m"

int main(void)
{
	char map[52][205] = {
		"🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔚🔙🔙",
		"🧊🧊🧊🧊🧊🧊🧊🧊🧊🧊🧊🧊🧊▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ⛄ 🗻⛄ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"🧊▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🥶🗻🗻▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"🧊▪ 🧊🧊🐧🧊🧊▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ⛷ 🗻▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"🧊▪ ▪ ▪ 🧊🐧🧊▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🥶🗻🗻🗻▪ ▪ ▪ ⓖ ⓐ ⓣ ⓔ ▪ ▪ ▪ ▪ 🔙",
		"🧊▪ 🧊▪ ▪ 🧊🧊▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🥶🗻🗻🗻▪ ▪ ▪ ▪ ╔  ◃▹  ╗▪ ▪ ▪ ▪ 🔙",
		"🧊▪ 🧊🐧🧊▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ⛷ 🗻▪ ▪ ▪ ▪ ▪ ▪ ▪ ║ ૯  ૭ ║▪ ▪ ▪ ▪ 🔙",
		"🧊▪ 🧊🧊🧊🧊▪  ╭ ◃▹ ╮ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ⛷ 🗻▪ ▪ 🗻🗻▪ ▪ ▪ ▪ ║ ૫  ૨ ║▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪  ▵ ◖◗ ▿ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🏂🗻🗻🗻🗻🗻🗻🗻▪ ▪ ▪ ╚ ╗  ╔ ╝▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪  ╰ ◃▹ ╯ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪  ◢◣ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 👾💫▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 👻👹▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🏰🏰🏰🏰🏰🏰▪ 🏰🏰🏰🏰🏰🏰🏰🏰🏰🎪🏰▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🧛🧞▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🧱🧱🧱🧱🧱🧱▪ 🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 👽😈▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔥▪ 🔥🔥🔥🔥🔥▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🧛🧞▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔥▪ 🔥🔥🔥🔥▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 💀😱▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔥▪ ▪ 🔥🔥🔥▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 👣👥▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌋▪ 🌋▪ 🌋🌋▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🧟🧟▪ ▪ ▪ ▪ ▪ 🗿🗿🗿🗿▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔥▪ ▪ 🔥🔥🔥▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌋▪ 🌋🧗▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌋🌋▪ 🌋🔥▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌲🌳▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌳🌳▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🧚🦄🦄▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌲🌳▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌈🌈🌈▪ ▪ ▪ ▪ ▪ 🔙",
		" ◢◣  ◢◣  ◢◣  ◢◣  ◢◣ 🗻▪ 🗻🗻 ◢◣  ◢◣  ◢◣  ◢◣  ◢◣ ▪ ▪ ▪ ▪ ▪ 🌲🌳🌲🌳▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌻🟢🌺🌷🌼▪ ▪ ▪ ▪ 🔙",
		"◢  ◣◢  ◣◢  ◣◢  ◣◢ ▪ ▪ 🗻▪  ◣◢  ◣◢  ◣◢  ◣◢  ◣◢  ◣▪ ▪ ▪ ▪ ▪ 🌲🌳🌲🌳▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌾🍄💐🌹🥀▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🗻🗻🗻▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌲🌳🌲🌳▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🍀🎍🍃▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🗻🗻▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌲🌳🌲▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🗻🗻▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌲🌳▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🗻🗻▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌲🌳▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🗻🗻▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌲🌳▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ 🟧🌠▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🗻🗻▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌲▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ 🟧🟧▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🗻🗻▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌳▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ 🟧🟧🔆▪ ▪ ▪ ▪ ▪ ▪ ▪ 🗻🗻▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌲🌳▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ 🟧🟧🌵🕌🕌▪ ▪ ▪ ▪ ▪ 🗻🗻▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌲🌳▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ 🟨🟨🟨🕋🕋▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌲🌳🐍🐢🦠🦎🐯🦁🐯▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ 🐪🐫🟨🟨▪ 🟨🏺▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌲🌳🌲🌳🌲🌳🌲🌳🌲🌳🌲🌳🌲🌳🌲🌳🌲🌳🌲🌳▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ 🟨🟨🟨▪ 🟨🟨▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🚧🚧🚧🚧🚧🚧🚧🚧🚧▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ 🟨🟨▪ 🟨🟨🟨▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ 🟨🟨🟨🟨▪ ▪ ▪ ▪ ▪ ▪ 🌀▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ 🦴🦴🟨🟨▪ ▪ ▪ ▪ ▪ 🌀🌀🌀▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔯🛐🛅🛃🚭▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🔙",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌀🌀🌀🌀🌀▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🏰🏯▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🏊🌊🦈🌊",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌀🌀🌀▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🏫🏩💒🏥🚩▪ ▪ ▪ ▪ ▪ ▪ 🏊🌊🌊🌊",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌀▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🚰🎦🚻🏁🚩▪ ▪ ▪ ▪ ▪ ▪ ▪ 🦑🌊🌊",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ⛵",
		"🌠🎇🎆🌠🎇🎆🌠🎇🎆🌠🎇🎆🌠▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🐳🌊🌊🌊🌊",
		"🌌🌌🌌🌌🌌🌌🌌🌌🌌🌌🌌🌌🌌▪ ▪ ▪ 🌴🌱🌿🍀🎍🎋🍃🐉🐲🦕▪ 🐲🍃🌴🌱🌿🍀🎍🎋🌴🌱🌿🍀🐍🐢▪ ▪ ▪ ▪ ▪ ▪ 🌊🌊🌊🌊",
		"⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ▪ ▪ ▪ 🟩🟩🟩🟩🟩🟩🟩🟩🟩▪ 🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩▪ ▪ ▪ ▪ ▪ ▪ 🦈🌊🌊",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌊🌊",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🌊🌊",
		"▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ ▪ 🐧▪ ▪ ▪ ▪ ▪ ▪ 🧜🧜🌊🌊",
		"⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ ⛰ 🗻🗻🗻🗻🗻🗻🗻🗻🗻🗻🗻🗻🗻🗻🗻🗻🗻🗻🗻🌁🌁🌁🌁🌁🌁🚢🚢🚢🚢🏄🌊🌊🌊🌊",
	};
	// 세로 52, 가로 51 
	// 31 + 2 x 31 + 2 🟥🟧🟨🟩🟦🟫🟪⬛⬜🛡⚔🗡🔪🚬🧪🪓💍💰🔫💎⛲🦺♻🔰
	// 🗻🌁 🚢🏄🐳🌊⛵🌌🎇🎆🌠🌴🌱🌿🍀🎍🎋🍃🐉🐲🦕🟩🌿🍀🐍🚧🌳🌲🦴🟨🦑

	char emoji[11][5] = {"🟥", "🟧", "🟨", "🟩", "🟦", "🟫", "🟪", "⬛", "⬜", "🌑", "🗻"};
	char emoji_items[15][5] = {"🔪", "🚬", "🧪", "🪓", "💍", "💰", "🔫", "💎", "🎴", "🦺", "🏹"};
	char emoji2[11][5] = {"🟥", "🟧", "🟨", "🟩", "🟦", "🟫", "🟪", "⬛", "⬜", "🌵", "⛳"};
	char emoji3[11][5] = {"🟥", "🟧", "🟨", "🟩", "🟦", "🟫", "🟪", "⬛", "⬜", "🌵", "⛳"};
	char emoji4[11][5] = {"🟥", "🟧", "🟨", "🟩", "🟦", "🟫", "🟪", "⬛", "⬜", "🌵", "⛳"};


	// 
	char map2[32][129] = {
		"10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  ",
		"10  0   2   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   2   0   0   2   2   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   2   0   0   2   2   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   2   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   2   0   2   2   2   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   2   0   2   2   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   2   0   2   2   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   2   2   2   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   2   2   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   2   2   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   10  ",
		"10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  10  "
	};

	char four[5] = "\0";

	char level[5][5] = {"🤺", "🏇", "♖ ", "♕ ", "♔ " };

	int x = 4;
	int y = 16;

	char move = 0;
	char arrow_list[8][5] = {"↖", "↟", "↗", "↞", "↠", "↙", "↡", "↘"};
	char arrow = 0;

	char temp_char[5] = "\0";
	int emoji_num = 0;	
	
	for(;;)
	{
		printf(" ");
		for(int l = 0; l <= 128; l++)
		{
			// x axis Line Nunber
			if((l % 4) == 0)
				printf(ANSI_COLOR_YELLOW "%2d " ANSI_COLOR_RESET, ((l - 4) / 4));
		}

		printf("\n");

		for(int i = 0; i < 32; i++) // y
		{
			// y axis Line Nunber
			printf(ANSI_COLOR_YELLOW " %2d " ANSI_COLOR_RESET, i);

			for(int j = 0; j < 128;)  // x
			{
				// 여기가 답이 없다..
				for(int k = 0; k < 4;)
				{
					four[k] = map2[i][j];
					k++;
					j++;
				}

				j--;

				if(i == y && j == (x + 3))
					printf(ANSI_COLOR_BLACK "%4s " ANSI_COLOR_RESET , level[1]);
				else if(((y - 1) <= i && i <= (y + 1)) && ((x - 4) <= j && j <= (x + 7)))
					printf(ANSI_COLOR_BLACK "%4s " ANSI_COLOR_RESET , emoji[atoi(four)]);
				else
					printf("\x1b[100m" "%4s " ANSI_COLOR_RESET, emoji[atoi(four)]);

				j++;
			}
			printf("\n");

		}	

		printf("\n");
		printf("q  w  e  \n" );
		printf(" ↖ ↟↗   \n"  );
		printf("a↞  ↠ d  플레이어(x,y) %d,%d\n", (x / 4), y);
		printf(" ↙ ↡↘    이동방향: %s %s\n", arrow_list[arrow], emoji[atoi(temp_char)]);
		printf("z  x  c ");

		for(;;)
		{

			printf(" >> ");

			move = getch();

			printf("%c\n", move);

			if(move == 65 || move == 97) // ↞a
			{
				for(int m = 0; m < 4; m++)
					temp_char[m] = map2[y][x - 4 + m];

				if(atoi(temp_char) == 0)
				{
					x = x - 4;
					arrow = 3;
				}

				break;
			}
			else if(move == 68 || move == 100) // d↠
			{
				for(int m = 0; m < 4; m++)
					temp_char[m] = map2[y][x + 4 + m];

				if(atoi(temp_char) == 0)
				{
					x = x + 4;
					arrow = 4;
				}

				break;
			}
			else if(move == 'x' || move == 'X' || move == 's' || move == 'S') // x↡ 
			{
				for(int m = 0; m < 4; m++)
					temp_char[m] = map2[y + 1][x + m];

				if(atoi(temp_char) == 0)
				{
					y = y + 1;
					arrow = 6;
				}

				break;
			}
			else if(move == 87 || move == 119)// w↟
			{
				for(int m = 0; m < 4; m++)
					temp_char[m] = map2[y - 1][x + m];
				printf("%s\n", temp_char);

				if(atoi(temp_char) == 0)
				{
					y = y - 1;
					arrow = 1;
				}

				break;
			}
			else if(move == 81 || move == 113)// ↖q
			{
				for(int m = 0; m < 4; m++)
					temp_char[m] = map2[y - 1][x - 4 + m];
				printf("%s\n", temp_char);

				if(atoi(temp_char) == 0)
				{
					y = y - 1;
					x = x - 4;
					arrow = 0;
				}

				break;
			}
			else if(move == 69 || move == 101)// e↗
			{
				for(int m = 0; m < 4; m++)
					temp_char[m] = map2[y - 1][x + 4 + m];
				printf("%s\n", temp_char);

				if(atoi(temp_char) == 0)
				{
					y = y - 1;
					x = x + 4;
					arrow = 2;
				}

				break;
			}
			else if(move == 90 || move == 122)// ↙z
			{
				for(int m = 0; m < 4; m++)
					temp_char[m] = map2[y + 1][x - 4 + m];

				if(atoi(temp_char) == 0)
				{
					y = y + 1;
					x = x - 4;
					arrow = 5;
				}

				break;
			}
			else if(move == 67 || move == 99)// c↘
			{
				for(int m = 0; m < 4; m++)
					temp_char[m] = map2[y + 1][x + 4 + m];

				if(atoi(temp_char) == 0)
				{
					y = y + 1;
					x = x + 4;
					arrow = 7;
				}

				break;
			}
			else
			{
				printf("이동할 수 없는 지역입니다.\n다시 입력해주세요");
				break;
			}

		}

	system("clear");

	}

}

int getch()
{
    int c;
    struct termios oldattr, newattr;

    tcgetattr(STDIN_FILENO, &oldattr);           // 현재 터미널 설정 읽음
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);         // CANONICAL과 ECHO 끔
    newattr.c_cc[VMIN] = 1;                      // 최소 입력 문자 수를 1로 설정
    newattr.c_cc[VTIME] = 0;                     // 최소 읽기 대기 시간을 0으로 설정
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);  // 터미널에 설정 입력
    c = getchar();                               // 키보드 입력 읽음
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);  // 원래의 설정으로 복구
    return c;
}

