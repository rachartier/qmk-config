ifeq ($(KEYBOARD), planck/rev7)
SRC += source.c
MOUSEKEY_ENABLE = yes
endif

ifeq ($(KEYBOARD), chosfox/geonixr2)
DYNAMIC_KEYMAP_ENABLE = yes
endif
