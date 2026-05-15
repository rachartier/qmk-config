ifeq ($(KEYBOARD), planck/rev7)
SRC += source.c
MOUSEKEY_ENABLE = yes
endif

ifeq ($(KEYBOARD), chosfox/geonixr2)
VIA_ENABLE = yes
endif
