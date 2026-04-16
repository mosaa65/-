/*
 * =============================================================
 *  اسم الطالب : عمار الحميري
 *  رقم السؤال : 10
 *  وصف البرنامج: دالة تأخذ مصفوفة وعدد عناصرها ورقم من المستخدم
 *               تبحث عنه، وإذا وجدته تزيله من المصفوفة وتعرضها
 * =============================================================
 */

#include <iostream>
using namespace std;

// ====== إعلان الدوال ======
int  searchElement(int arr[], int size, int target);
void removeElement(int arr[], int &size, int index);
void printArray(int arr[], int size);

// ====== الدالة الرئيسية ======
int main() {

    cout << "======================================" << endl;
    cout << "   برنامج البحث وحذف عنصر من المصفوفة" << endl;
    cout << "======================================" << endl;

    // ------- إدخال المصفوفة -------
    int n;
    cout << "أدخل عدد العناصر: ";
    cin >> n;

    int arr[100];
    cout << "\nأدخل " << n << " رقم:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  العنصر [" << i + 1 << "]: ";
        cin >> arr[i];
    }

    // ------- عرض المصفوفة الأصلية -------
    cout << "\n--- المصفوفة الأصلية ---" << endl;
    printArray(arr, n);

    // ------- البحث عن الرقم -------
    int target;
    cout << "\nأدخل الرقم الذي تريد حذفه: ";
    cin >> target;

    int foundIndex = searchElement(arr, n, target);

    if (foundIndex == -1) {
        cout << "\n❌ الرقم " << target << " غير موجود في المصفوفة!" << endl;
    } else {
        cout << "\n✅ الرقم " << target
             << " موجود في الموقع [" << foundIndex << "]" << endl;

        removeElement(arr, n, foundIndex);

        cout << "\n--- المصفوفة بعد الحذف ---" << endl;
        printArray(arr, n);
    }

    cout << "\n======================================" << endl;
    return 0;
}

// ====== دالة البحث عن عنصر ======
// تعيد index العنصر إذا وجدته، أو -1 إذا لم تجده
int searchElement(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // وجدناه! أعد موقعه
        }
    }
    return -1; // لم نجده
}

// ====== دالة حذف عنصر ======
// تحذف العنصر وتزحزح ما بعده خطوة للخلف
void removeElement(int arr[], int &size, int index) {
    // ازحزح كل العناصر بعد index خطوة للخلف
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--; // نقص حجم المصفوفة بواحد
}

// ====== دالة طباعة المصفوفة ======
void printArray(int arr[], int size) {
    if (size == 0) {
        cout << "[ المصفوفة فارغة ]" << endl;
        return;
    }
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " ]" << endl;
    cout << "عدد العناصر: " << size << endl;
}
