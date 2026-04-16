/*
 * =============================================================
 *  اسم الطالب : عمار الحميري
 *  رقم السؤال : 9
 *  وصف البرنامج: يطلب من المستخدم إدخال أرقام (ينتهي بصفر)
 *               ثم باستخدام دالة يرتبها تصاعدياً وتنازلياً
 * =============================================================
 */

#include <iostream>
using namespace std;

// ====== إعلان الدوال ======
void sortAscending(int arr[], int size);
void sortDescending(int arr[], int size);
void printArray(int arr[], int size);

// ====== الدالة الرئيسية ======
int main() {

    cout << "======================================" << endl;
    cout << "   برنامج ترتيب الأرقام تصاعدياً وتنازلياً" << endl;
    cout << "======================================" << endl;
    cout << "(أدخل 0 للإنهاء)" << endl << endl;

    int arr[100];
    int count = 0;
    int input;

    // ------- الخطوة 1: إدخال الأرقام حتى يدخل المستخدم 0 -------
    do {
        cout << "أدخل رقم: ";
        cin >> input;
        if (input != 0) {
            arr[count] = input;
            count++;
        }
    } while (input != 0);

    if (count == 0) {
        cout << "لم تدخل أي أرقام!" << endl;
        return 0;
    }

    // ------- الخطوة 2: عرض الأرقام قبل الترتيب -------
    cout << "\n--- الأرقام المدخلة ---" << endl;
    printArray(arr, count);

    // ------- الخطوة 3: ترتيب تصاعدي -------
    // نعمل نسخة للترتيب التصاعدي
    int ascArr[100];
    for (int i = 0; i < count; i++) ascArr[i] = arr[i];
    sortAscending(ascArr, count);

    cout << "\n--- الترتيب التصاعدي (من الأصغر للأكبر) ---" << endl;
    printArray(ascArr, count);

    // ------- الخطوة 4: ترتيب تنازلي -------
    int descArr[100];
    for (int i = 0; i < count; i++) descArr[i] = arr[i];
    sortDescending(descArr, count);

    cout << "\n--- الترتيب التنازلي (من الأكبر للأصغر) ---" << endl;
    printArray(descArr, count);

    cout << "\n======================================" << endl;
    return 0;
}

// ====== دالة الطباعة ======
void printArray(int arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

// ====== دالة الترتيب التصاعدي (Bubble Sort) ======
void sortAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // تبديل العنصرين
                int temp   = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ====== دالة الترتيب التنازلي ======
void sortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { // اتجاه معاكس
                int temp   = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
