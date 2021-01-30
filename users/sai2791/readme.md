Copyright 2019 Steven Inglis sai2791@googlemail.com @sai2791

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Overview

This is my personal userspace.

24/02/2019
Implement on key task switching (Alt-tab in the windows world) Using gui_tab

30/1/2019
- New kemaps added desk_l and desk_r, should add these to my keymaps
- maybe move the window moving, and screen moving stuff to a layer

# Shared Keys
- System wide Mac lock screen Keys (KC_LOCKSCR)
- System wide Mac Desktop Left key (DESK_L)
- System wide Mac Desktop Right Key (DESK_R)
- System wide GUI TAB key (GUI_TAB)

# Shared Keyboards
- ergodox_ez  Doesnt use the sai2791.c
- radox_w     Doesnt use the sai2791.c
- ymdk_np21   Doesnt use the sai2791.c

# Notes to myself

- fn_action removed
- Desk_L and Desk_R are not working on the keyboard needs to be investigated, the lock
screen seems to be working fine.  Checking the code it appears that the define is not in the dev branch
gui tab stuff mostly taken from https://www.reddit.com/r/olkb/comments/9ncbhu/brainstorming_for_a_onekey_alttab_function_what/
