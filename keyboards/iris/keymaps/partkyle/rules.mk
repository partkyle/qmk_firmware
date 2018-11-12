RGBLIGHT_ENABLE = yes
BACKLIGHT_ENABLE = yes

COMMAND_ENABLE = no
CONSOLE_ENABLE = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
