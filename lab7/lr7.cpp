#include <windows.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Point {
protected:
    int X, Y;
    COLORREF Color;
public:
    Point(int XN, int YN, COLORREF Color) : X(XN), Y(YN), Color(Color) {}
    virtual void Show(HDC hdc) {}
    virtual void Hide(HDC hdc) {}
    void Local(int& XL, int& YL) { XL = X; YL = Y; }
    void MoveTo(int newX, int newY, HDC hdc); // Метод для перемещения
    void ChangeColor(COLORREF newColor, HDC hdc); // Метод для смены цвета
};

class Krug : public Point {
protected:
    int Radius;
    int SectorStart, SectorEnd; // Углы начала и конца сектора
public:
    Krug(int XN, int YN, int R, COLORREF Color)
        : Point(XN, YN, Color), Radius(R), SectorStart(0), SectorEnd(360) {
    }
    void Show(HDC hdc) override;
    void Hide(HDC hdc) override;
    void ChangeSector(int start, int end, HDC hdc); // Метод для изменения сектора
};

class Ring : public Krug {
    int Width;
public:
    Ring(int XN, int YN, int R, COLORREF Color, int Wid)
        : Krug(XN, YN, R, Color), Width(Wid) {
    }
    void Show(HDC hdc) override;
};

void Point::MoveTo(int newX, int newY, HDC hdc) {
    Hide(hdc); // Скрываем фигуру в текущей позиции
    X = newX;  // Обновляем координаты
    Y = newY;
    Show(hdc); // Показываем фигуру в новой позиции
}

void Point::ChangeColor(COLORREF newColor, HDC hdc) {
    Hide(hdc); // Скрываем фигуру
    Color = newColor; // Меняем цвет
    Show(hdc); // Показываем фигуру с новым цветом
}

void Krug::Show(HDC hdc) {
    HBRUSH hBrush = CreateSolidBrush(Color);
    SelectObject(hdc, hBrush);
    // Рисуем сектор круга
    Pie(hdc, X - Radius, Y - Radius, X + Radius, Y + Radius,
        static_cast<int>(X + Radius * cos(SectorStart * 3.14 / 180)),
        static_cast<int>(Y - Radius * sin(SectorStart * 3.14 / 180)),
        static_cast<int>(X + Radius * cos(SectorEnd * 3.14 / 180)),
        static_cast<int>(Y - Radius * sin(SectorEnd * 3.14 / 180)));
    DeleteObject(hBrush);
}

void Krug::Hide(HDC hdc) {
    COLORREF oldColor = Color;
    Color = GetBkColor(hdc);
    Show(hdc);
    Color = oldColor;
}

void Krug::ChangeSector(int start, int end, HDC hdc) {
    Hide(hdc); // Скрываем фигуру
    SectorStart = start; // Меняем углы сектора
    SectorEnd = end;
    Show(hdc); // Показываем фигуру с новым сектором
}

void Ring::Show(HDC hdc) {
    // Рисуем внешний круг с сектором
    HBRUSH hBrush = CreateSolidBrush(Color);
    SelectObject(hdc, hBrush);
    Pie(hdc, X - Radius, Y - Radius, X + Radius, Y + Radius,
        static_cast<int>(X + Radius * cos(SectorStart * 3.14 / 180)),
        static_cast<int>(Y - Radius * sin(SectorStart * 3.14 / 180)),
        static_cast<int>(X + Radius * cos(SectorEnd * 3.14 / 180)),
        static_cast<int>(Y - Radius * sin(SectorEnd * 3.14 / 180)));
    DeleteObject(hBrush);

    // Рисуем внутренний "вырезанный" круг
    hBrush = CreateHatchBrush(HS_DIAGCROSS, GetBkColor(hdc));
    SelectObject(hdc, hBrush);
    Pie(hdc, X - (Radius - Width), Y - (Radius - Width), X + (Radius - Width), Y + (Radius - Width),
        static_cast<int>(X + (Radius - Width) * cos(SectorStart * 3.14 / 180)),
        static_cast<int>(Y - (Radius - Width) * sin(SectorStart * 3.14 / 180)),
        static_cast<int>(X + (Radius - Width) * cos(SectorEnd * 3.14 / 180)),
        static_cast<int>(Y - (Radius - Width) * sin(SectorEnd * 3.14 / 180)));
    DeleteObject(hBrush);
}

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
    static TCHAR szAppName[] = TEXT("Shapes");
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    if (!RegisterClass(&wndclass)) {
        MessageBox(NULL, TEXT("This program requires Windows NT!"), szAppName, MB_ICONERROR);
        return 0;
    }

    hwnd = CreateWindow(szAppName, TEXT("Shapes"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    static Krug testKrug(150, 40, 50, RGB(255, 0, 0));
    static Ring testRing(450, 80, 90, RGB(0, 0, 255), 10);
    HDC hdc;
    PAINTSTRUCT ps;

    switch (message) {
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        testKrug.Show(hdc);
        testRing.Show(hdc);
        EndPaint(hwnd, &ps);
        return 0;
    case WM_KEYDOWN:
        hdc = GetDC(hwnd);
        // Перемещаем фигуры
        testKrug.MoveTo(rand() % 800, rand() % 600, hdc);
        testRing.MoveTo(rand() % 800, rand() % 600, hdc);

        // Меняем цвет фигур
        testKrug.ChangeColor(RGB(rand() % 256, rand() % 256, rand() % 256), hdc);
        testRing.ChangeColor(RGB(rand() % 256, rand() % 256, rand() % 256), hdc);

        // Меняем сектор круга и кольца
        testKrug.ChangeSector(rand() % 360, rand() % 360, hdc);
        testRing.ChangeSector(rand() % 360, rand() % 360, hdc);

        ReleaseDC(hwnd, hdc);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}