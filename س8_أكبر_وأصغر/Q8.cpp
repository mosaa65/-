/*
 * =============================================================
 *  اسم الطالب : عمار الحميري
 *  رقم السؤال : 8
 *  وصف البرنامج: يستخدم دالة تأخذ مصفوفة وعدد عناصرها
 *               وتعيد أكبر وأصغر رقم في المصفوفة
 * =============================================================
 */

#include <iostream>
using namespace std;

// ====== إعلان الدوال (Function Declarations) ======
int findMax(int arr[], int size);
int findMin(int arr[], int size);

// ====== الدالة الرئيسية ======
int main() {

    cout << "======================================" << endl;
    cout << "   برنامج إيجاد أكبر وأصغر رقم بالمصفوفة" << endl;
    cout << "======================================" << endl;

    int n;
    cout << "أدخل عدد العناصر: ";
    cin >> n;

    int arr[100];
    cout << "\nأدخل " << n << " رقم:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  العنصر [" << i + 1 << "]: ";
        cin >> arr[i];
    }

    // ------- عرض المصفوفة -------
    cout << "\n--- المصفوفة ---" << endl;
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << " ]" << endl;

    // ------- استدعاء الدوال -------
    int maxVal = findMax(arr, n);
    int minVal = findMin(arr, n);

    cout << "\n--- النتائج ---" << endl;
    cout << "  أكبر رقم في المصفوفة: " << maxVal << endl;
    cout << "  أصغر رقم في المصفوفة: " << minVal << endl;

    cout << "\n======================================" << endl;
    return 0;
}

// ====== تعريف دالة إيجاد الأكبر ======
int findMax(int arr[], int size) {
    int maxVal = arr[0]; // نفترض أن أول عنصر هو الأكبر
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i]; // وجدنا أكبر منه، نحدّث
        }
    }
    return maxVal;
}

// ====== تعريف دالة إيجاد الأصغر ======
int findMin(int arr[], int size) {
    int minVal = arr[0]; // نفترض أن أول عنصر هو الأصغر
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i]; // وجدنا أصغر منه، نحدّث
        }
    }
    return minVal;
}
