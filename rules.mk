ifeq ($(KEYBOARD), planck/rev7)
SRC += source.c
MOUSEKEY_ENABLE = yes
endif

ifeq ($(KEYBOARD), chosfox/geonixr2)
CFLAGS += -include rdmctmzt_common.h
endif
