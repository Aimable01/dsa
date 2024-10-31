#include <windows.h>
#include <string>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

// Global Variables
HWND hwndDisplay;
std::string input1 = "", input2 = "", operation = "";
bool isSecondNumber = false;

// Utility function to update display
void UpdateDisplay(HWND hwnd) {
    std::string displayText = input1 + operation + input2;
    SetWindowText(hwndDisplay, displayText.c_str());
}

// Function to perform the calculation
void Calculate() {
    if (input1.empty() || input2.empty() || operation.empty()) return;
    double num1 = std::stod(input1);
    double num2 = std::stod(input2);
    double result = 0.0;

    if (operation == "+") result = num1 + num2;
    else if (operation == "-") result = num1 - num2;
    else if (operation == "*") result = num1 * num2;
    else if (operation == "/") {
        if (num2 == 0) {
            MessageBox(NULL, "Error: Division by zero!", "Calculator Error", MB_ICONERROR);
            input1 = ""; input2 = ""; operation = ""; isSecondNumber = false;
            UpdateDisplay(hwndDisplay);
            return;
        }
        result = num1 / num2;
    }

    input1 = std::to_string(result);
    input2 = "";
    operation = "";
    isSecondNumber = false;

    // Trim trailing zeros for aesthetics
    size_t dotPos = input1.find('.');
    if (dotPos != std::string::npos) {
        input1.erase(input1.find_last_not_of('0') + 1, std::string::npos);
        if (input1.back() == '.') input1.pop_back();
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInstance;
    wc.lpszClassName = "CalculatorClass";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        "CalculatorClass",
        "Simple Calculator",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 320, 450,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE: {
        hwndDisplay = CreateWindow("STATIC", "", WS_CHILD | WS_VISIBLE | SS_RIGHT, 
                                   10, 10, 280, 40, hwnd, NULL, NULL, NULL);

        // Set positions for buttons with spacing
        int xPos = 10, yPos = 60;
        int buttonWidth = 60, buttonHeight = 50;
        int xSpacing = 20, ySpacing = 15;

        // Create number buttons
        for (int i = 1; i <= 9; ++i) {
            CreateWindow("BUTTON", std::to_string(i).c_str(), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 
                         xPos, yPos, buttonWidth, buttonHeight, hwnd, (HMENU)(i), NULL, NULL);
            xPos += buttonWidth + xSpacing;
            if (i % 3 == 0) { xPos = 10; yPos += buttonHeight + ySpacing; }
        }
        CreateWindow("BUTTON", "0", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, yPos, buttonWidth, buttonHeight, hwnd, (HMENU)0, NULL, NULL);
        CreateWindow("BUTTON", ".", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 90, yPos, buttonWidth, buttonHeight, hwnd, (HMENU)'.', NULL, NULL);

        // Create operation buttons
        CreateWindow("BUTTON", "+", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 250, 60, buttonWidth, buttonHeight, hwnd, (HMENU)'+', NULL, NULL);
        CreateWindow("BUTTON", "-", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 250, 125, buttonWidth, buttonHeight, hwnd, (HMENU)'-', NULL, NULL);
        CreateWindow("BUTTON", "*", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 250, 190, buttonWidth, buttonHeight, hwnd, (HMENU)'*', NULL, NULL);
        CreateWindow("BUTTON", "/", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 250, 255, buttonWidth, buttonHeight, hwnd, (HMENU)'/', NULL, NULL);
        CreateWindow("BUTTON", "=", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 320, 280, buttonHeight, hwnd, (HMENU)'=', NULL, NULL);
        CreateWindow("BUTTON", "C", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 250, 10, buttonWidth, 40, hwnd, (HMENU)'C', NULL, NULL);
    } break;

    case WM_COMMAND: {
        int wmId = LOWORD(wParam);
        if (wmId >= 0 && wmId <= 9) { // Number buttons
            if (!isSecondNumber) input1 += std::to_string(wmId);
            else input2 += std::to_string(wmId);
        } else if (wmId == '+' || wmId == '-' || wmId == '*' || wmId == '/') { // Operation buttons
            if (!input1.empty() && input2.empty()) {
                operation = (char)wmId;
                isSecondNumber = true;
            }
        } else if (wmId == '=') { // Equals button
            Calculate();
        } else if (wmId == 'C') { // Clear button
            input1 = ""; input2 = ""; operation = ""; isSecondNumber = false;
        } else if (wmId == '.') { // Decimal point
            if (!isSecondNumber && input1.find('.') == std::string::npos) input1 += '.';
            else if (isSecondNumber && input2.find('.') == std::string::npos) input2 += '.';
        }
        UpdateDisplay(hwnd);
    } break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
