#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class textEditor
{
private:
   vector<string> lines;
   int cursorRow = 0;
   int cursorCol = 0;
   string filename = "untitled.txt";

public:
   textEditor()
   {
      lines.push_back("");
   }

   void clearScreen()
   {
      cout << "\033[2J\033[H";
   }

   int moveCursor(int row, int col)
   {
      cout << "\033[" << (row + 1) << ";" << (col + 1) << "H";
   }

   void display()
   {
      clearScreen();

      for (int i = 0; i < lines.size(); i++)
      {
         cout << lines[i] << "\n";
      }

      moveCursor(24, 0);
      cout << "_______________________________________________________";
      moveCursor(25, 0);
      cout << " " << filename << " | Ctrl + S: Save | Ctrl + Q: Quit";

      // moving the cursor by position
      moveCursor(cursorRow, cursorCol);
      cout << flush;
   }
};

int main()
{
   textEditor editor;
   editor.display();

   cout << "\n\nPress any key...";
   _getch();

   return 0;
}
