#pragma execution_character_set("utf-8")
#include <windows.h>
#include <vector>
#include <windows.h>
#include <CommCtrl.h>

#include <math.h>

#include <objbase.h>

#include <tchar.h>
#include <string>
#include <fstream>
using namespace std;

HINSTANCE hInst;
HWND hwndMain;
HWND hwndCardMaxTime;
HWND hwndDentMaxTime;
HWND hwndLorMaxTime;
HWND hwndPatientSymptoms;
HWND hwndPatientSurname;
std::vector<std::string> doctorInfo;
std::vector<std::string> patientInfo;


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR Planets[3][20] =
{
    TEXT("Cavity"), TEXT("Ear studs"), TEXT("Heart disease")

};
void CreateControls(HWND hwnd) {
    if (hwnd) {


        CreateWindow(
            TEXT("static"), TEXT("Doctors"),
            WS_VISIBLE | WS_CHILD,
            10, 10, 200, 20,
            hwnd, nullptr, nullptr, nullptr
        );
        CreateWindow(
            TEXT("static"), TEXT("Cardiologist"),
            WS_VISIBLE | WS_CHILD,
            10, 40, 200, 20,
            hwnd, nullptr, nullptr, nullptr
        );

        hwndCardMaxTime = CreateWindowEx(
            0, TEXT("EDIT"), TEXT(""),
            WS_CHILD | WS_VISIBLE | WS_BORDER,
            10, 70, 200, 30,
            hwnd, nullptr, hInst, nullptr
        );
        CreateWindow(
            TEXT("static"), TEXT("Dentist"),
            WS_VISIBLE | WS_CHILD,
            10, 130, 200, 20,
            hwnd, nullptr, nullptr, nullptr
        );

        hwndDentMaxTime = CreateWindowEx(
            0, TEXT("EDIT"), TEXT(""),
            WS_CHILD | WS_VISIBLE | WS_BORDER,
            10, 160, 200, 30,
            hwnd, nullptr, hInst, nullptr
        );

        CreateWindow(
            TEXT("static"), TEXT("Lor"),
            WS_VISIBLE | WS_CHILD,
            10, 190, 200, 20,
            hwnd, nullptr, nullptr, nullptr
        );

        hwndLorMaxTime = CreateWindowEx(
            0, TEXT("EDIT"), TEXT(""),
            WS_CHILD | WS_VISIBLE | WS_BORDER,
            10, 210, 200, 30,
            hwnd, nullptr, hInst, nullptr
        );


        CreateWindow(
            TEXT("static"), TEXT("Patients"),
            WS_VISIBLE | WS_CHILD,
            10, 250, 200, 20,
            hwnd, nullptr, nullptr, nullptr
        );

        hwndPatientSurname = CreateWindowEx(
            0, TEXT("EDIT"), TEXT(""),
            WS_CHILD | WS_VISIBLE | WS_BORDER,
            10, 280, 200, 30,
            hwnd, nullptr, hInst, nullptr
        );
        CreateWindow(L"BUTTON", L"Cavity", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
            10, 320, 200, 30, hwnd, (HMENU)4, nullptr, nullptr);
        CreateWindow(L"BUTTON", L"Heart Disease", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
            10, 360, 200, 30, hwnd, (HMENU)5, nullptr, nullptr);
        CreateWindow(L"BUTTON", L"Ear Pains", WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
            10, 400, 200, 30, hwnd, (HMENU)6, nullptr, nullptr);







        CreateWindow(
            TEXT("BUTTON"), TEXT("Add patient"),
            WS_VISIBLE | WS_CHILD,
            220, 400, 300, 30,
            hwnd, (HMENU)1, hInst, nullptr
        );

        CreateWindow(
            TEXT("BUTTON"), TEXT("Upload"),
            WS_VISIBLE | WS_CHILD,
            200, 460, 200, 30,
            hwnd, (HMENU)2, hInst, nullptr
        );

    }


}
const string Map[3] = {
"Cavity", "Ear studs", "Heart disease"
};

void AddPatient() {
    wchar_t symptoms[256], psurname[256];
    int tmp = -1;

    GetWindowText(hwndPatientSymptoms, symptoms, 256);
    GetWindowText(hwndPatientSurname, psurname, 256);

    BOOL cavityChecked = SendMessage(GetDlgItem(hwndMain, 4), BM_GETCHECK, 0, 0) == BST_CHECKED;
    BOOL heartDiseaseChecked = SendMessage(GetDlgItem(hwndMain, 5), BM_GETCHECK, 0, 0) == BST_CHECKED;
    BOOL earPainsChecked = SendMessage(GetDlgItem(hwndMain, 6), BM_GETCHECK, 0, 0) == BST_CHECKED;


    std::wstring selectedSymptoms;
    if (cavityChecked) selectedSymptoms += L" 1 ";
    if (heartDiseaseChecked) selectedSymptoms += L" 2 ";
    if (earPainsChecked) selectedSymptoms += L" 3";

    for (int i = 0; i < 3; i++) {
        if (wcscmp(symptoms, Planets[i]) == 0) {
            selectedSymptoms += i;
            break;
        }
    }

    if (wcslen(selectedSymptoms.c_str()) > 0 && wcslen(psurname) > 0) {
        std::wstring patientData = psurname;
        patientData += L"\r ";
        patientData += selectedSymptoms;

        patientInfo.emplace_back(patientData.begin(), patientData.end());

        SetWindowText(hwndPatientSymptoms, L"");
        SetWindowText(hwndPatientSurname, L"");
        SendMessage(GetDlgItem(hwndMain, 4), BM_SETCHECK, BST_UNCHECKED, 0);
        SendMessage(GetDlgItem(hwndMain, 5), BM_SETCHECK, BST_UNCHECKED, 0);
        SendMessage(GetDlgItem(hwndMain, 6), BM_SETCHECK, BST_UNCHECKED, 0);
    }
}



void SaveToFile() {
    TCHAR card[20];
    TCHAR dent[20];
    TCHAR lor[20];
    GetWindowText(hwndCardMaxTime, card, 20);
    GetWindowText(hwndDentMaxTime, dent, 20);
    GetWindowText(hwndLorMaxTime, lor, 20);

    if (wcslen(card) > 0 && wcslen(dent) > 0 && wcslen(lor) > 0) {
        std::wstring doctorData = card;
        doctorData += L"\r ";

        doctorData += dent;
        doctorData += L"\r ";

        doctorData += lor;

        doctorInfo.emplace_back(doctorData.begin(), doctorData.end());

        SetWindowText(hwndCardMaxTime, TEXT(""));
        SetWindowText(hwndDentMaxTime, TEXT(""));
        SetWindowText(hwndLorMaxTime, TEXT(""));

    }
    std::ofstream outFile("HospitalData.txt");

    if (outFile.is_open()) {
        for (const std::string& doctor : doctorInfo) {
            outFile << doctor << "\r";
        }

        for (const std::string& patient : patientInfo) {
            outFile << patient << "\r";
        }

        outFile.close();
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    hInst = hInstance;
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, _T("Hospital Simulator"), nullptr };
    RegisterClassEx(&wc);
    hwndMain = CreateWindow(wc.lpszClassName, _T("????????? ????????"), WS_OVERLAPPEDWINDOW, 100, 100, 600, 560, nullptr, nullptr, wc.hInstance, nullptr);
    CreateControls(hwndMain);
    ShowWindow(hwndMain, SW_SHOWDEFAULT);
    UpdateWindow(hwndMain);

    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT) {
        if (PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    default:break;
    case WM_COMMAND:
        if (HIWORD(wParam) == BN_CLICKED) {
            int controlId = LOWORD(wParam);

            if (controlId == 4 || controlId == 5 || controlId == 6) {
                bool checked;
                checked = static_cast<bool>(SendMessage(GetDlgItem(hwndMain, controlId), BM_GETCHECK, 0, 0));
                SendMessage(GetDlgItem(hwndMain, controlId), BM_SETCHECK, checked == BST_CHECKED ? BST_UNCHECKED : BST_CHECKED, 0);
            }
        }


        switch (LOWORD(wParam)) {

        case 1:
            AddPatient();
            break;
        case 2:
            SaveToFile();
            MessageBox(nullptr, TEXT("Data saved into HospitalData.txt"), TEXT("Success"), MB_OK | MB_ICONINFORMATION);
            break;
        default:break;
        }


        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
