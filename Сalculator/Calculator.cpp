#include "Calculator.h"
#include <Windows.h>
using namespace Ņalculator;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Calculator);
    return 0;
}