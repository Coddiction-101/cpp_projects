#include <iostream>
#include <conio.h>
using namespace std;

void clearScreen()
{
   cout << "\033[2J\033[H"; // ✅ No ] at the end
}

void moveCursor(int row, int col)
{
   cout << "\033[" << row << ";" << col << "H";
}

int main()
{
   clearScreen();
   int cursorRow = 10;
   int cursorCol = 20;

   cout << "Use array key to move. ESC to quit.\n";
   while (true)
   {
      moveCursor(cursorRow, cursorCol);
      cout << "*" << flush;

      if (_kbhit())
      {
         int ch = _getch();

         if (ch == 27)
            break;

         if (ch == 0 || ch == 224)
         {
            ch = _getch();

            moveCursor(cursorRow, cursorCol);
            cout << " ";

            if (ch == 72)
               cursorRow--; // UP
            if (ch == 80)
               cursorRow++; // DOWN
            if (ch == 75)
               cursorCol--; // Left
            if (ch == 77)
               cursorCol++; // Right

            // Bounderies
            if (cursorRow < 2)
               cursorRow = 2;
            if (cursorRow > 20)
               cursorRow = 20;
            if (cursorCol < 1)
               cursorCol = 1;
            if (cursorCol > 40)
               cursorCol = 40;
         }
      }
   }
   clearScreen();
   return 0;
}
