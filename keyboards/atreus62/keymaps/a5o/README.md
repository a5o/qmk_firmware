# Atreus62 keymap

Atreus62 keymap with accented keys layer (unicodemap) for 
italian language.

To enable unicodemap modify the file rules.mk in atreus62 folder from:

    UNICODE_ENABLE = yes         # Unicode

to:

    UNICODEMAP_ENABLE = yes         # Unicode

To select unicode input types add the following lines to the config.h
file in atreus62 folder:

    #define UNICODE_SELECTED_MODES UC_MAC, UC_LNX, UC_WINC

remember to modify the DIODE_DIRECTION option to reflect the hardware
configuration:

    #define DIODE_DIRECTION COL2ROW
