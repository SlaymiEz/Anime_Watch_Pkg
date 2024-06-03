#include <ncurses.h>
#include <string.h>
#include <stdio.h>

#define MENU_ITEMS 5

const char *menu_items[MENU_ITEMS] = {
        "Search for anime",
        "Browse anime list",
        "Watch anime",
        "Settings",
        "Exit"
};

int main() {
    initscr();  // Initialize ncurses
    curs_set(0);  // Hide the cursor
    noecho();  // Don't echo key presses
    keypad(stdscr, TRUE);  // Enable arrow keys

    int selected = 0;
    while (1) {
        clear();  // Clear the screen
        for (int i = 0; i < MENU_ITEMS; i++) {
            if (i == selected) {
                attron(A_STANDOUT);  // Highlight the selected item
                mvprintw(i, 0, "%s", menu_items[i]);
                attroff(A_STANDOUT);
            } else {
                mvprintw(i, 0, "%s", menu_items[i]);
            }
        }
        refresh();  // Update the screen

        int c = getch();  // Get a character from the user
        switch (c) {
            case KEY_UP:
                if (selected > 0) {
                    selected--;
                }
                break;
            case KEY_DOWN:
                if (selected < MENU_ITEMS - 1) {
                    selected++;
                }
                break;
            case '\n':  // Enter key
                switch (selected) {
                    case 0:
                        // Search for anime
                        mvprintw(10, 0, "Searching for anime...\n");
                        mvprintw(11, 0, "Press any key to continue...");
                        refresh();
                        getch();  // Wait for the user to press a key
                        break;
                    case 1:
                        // Browse anime list
                        mvprintw(10, 0, "Browsing anime list...\n");
                        mvprintw(11, 0, "Press any key to continue...");
                        refresh();
                        getch();  // Wait for the user to press a key
                        break;
                    case 2:
                        // Watch anime
                        mvprintw(10, 0, "Watching anime...\n");
                        mvprintw(11, 0, "Press any key to continue...");
                        refresh();
                        getch();  // Wait for the user to press a key
                        break;
                    case 3:
                        // Settings
                        mvprintw(10, 0, "Settings...\n");
                        mvprintw(11, 0, "Press any key to continue...");
                        refresh();
                        getch();  // Wait for the user to press a key
                        break;
                    case 4:
                        // Exit
                        endwin();  // Clean up ncurses
                        return 0;
                }
                break;
        }
    }

    endwin();  // Clean up ncurses
    return 0;
}