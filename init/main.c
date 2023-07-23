#include "driver/vga.h"
#include "driver/keyboard.h"
#include "cpu/interrupt.h"

#include "mm/memory.h"
#include "lris/string.h"
#include "lris/printk.h"
#include "peripheral/getty.h"
#include "lris/assert.h"

char *logo = "\n" \
"       :::        :::::::::  ::::::::::: ::::::::\n" \
"      :+:        :+:    :+:     :+:    :+:    :+:\n" \
"     +:+        +:+    +:+     +:+    +:+\n" \
"    +#+        +#++:++#:      +#+    +#++:++#++\n" \
"   +#+        +#+    +#+     +#+           +#+\n" \
"  #+#        #+#    #+#     #+#    #+#    #+#\n" \
" ########## ###    ### ########### ########\n";

extern void unittest (void);

void kernel_init (void)
{
	vga_init ();
	mm_init ();
	interrupt_init ();
	keyboard_init ();

	unittest ();

	vga_set_color (VGA_COLOR_BLACK, VGA_COLOR_LIGHT_CYAN);
	printk ("\n\n%s\n\n\n", logo);
	vga_set_color (VGA_COLOR_BLACK, VGA_COLOR_WHITE);

	getty_init ();

	while (1)
	{
		keyboard_handler ();
	}
}
