ifeq ($(strip $(KEYBOARD)), ymdk_np21)
		SRC +=
endif

ifeq ($(strip $(KEYBOARD)), ergodox_ez)
		TAP_DANCE_ENABLE = yes
		SRC +=
endif

ifeq ($(strip $(KEYBOARD)), redox_w)
		SRC +=
endif

ifeq ($(strip $(KEYBOARD)), unigo66)
		SRC +=
endif

EXTRAFLAGS+=-flto
