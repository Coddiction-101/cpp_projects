#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
   cout << "Press any key (ESC to quit): \n\n";

   while (true)
   {
      if (_kbhit())
      {
         int ch = _getch();

         if (ch == 27)
         {
            cout << "\nExisting...\n";
            break;
         }

         cout << "you pressed: " << ch << " (" << (char)ch << ")\n";
      }
   }
   return 0;
}
