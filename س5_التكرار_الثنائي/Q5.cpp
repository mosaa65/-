/*
 * =============================================================
 *  اسم الطالب : عمار الحميري
 *  رقم السؤال : 5
 *  وصف البرنامج: يجد جميع الأعداد المتكررة في مصفوفة
 *               ثنائية الأبعاد (4×4) ويعرضها
 * =============================================================
 */

#include <iostream>
using namespace std;

int main() {

    cout << "======================================" << endl;
    cout << "   برنامج إيجاد الأرقام المكررة في المصفوفة 4×4" << endl;
    cout << "======================================" << endl;

    const int SIZE = 4;
    int matrix[SIZE][SIZE];

    // ------- الخطوة 1: إدخال المصفوفة -------
    cout << "\nأدخل عناصر المصفوفة (4 صفوف × 4 أعمدة):\n" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "  matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
        cout << endl;
    }

    // ------- الخطوة 2: عرض المصفوفة -------
    cout << "--- المصفوفة المدخلة ---" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "  [ ";
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j];
            if (j < SIZE - 1) cout << ", ";
        }
        cout << " ]" << endl;
    }

    // ------- الخطوة 3: تحويل المصفوفة لمصفوفة أحادية -------
    int flat[SIZE * SIZE]; // 16 عنصر
    int k = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            flat[k++] = matrix[i][j];

    // ------- الخطوة 4: إيجاد الأرقام المكررة -------
    bool printed[SIZE * SIZE] = {false}; // لتجنب طباعة نفس الرقم مرتين
    bool foundDuplicate = false;

    cout << "\n--- الأرقام المكررة ---" << endl;

    for (int i = 0; i < SIZE * SIZE; i++) {
        if (printed[i]) continue;

        int count = 1;
        for (int j = i + 1; j < SIZE * SIZE; j++) {
            if (flat[i] == flat[j]) {
                count++;
                printed[j] = true;
            }
        }

        if (count > 1) {
            cout << "  الرقم " << flat[i]
                 << " مكرر " << count << " مرات" << endl;
            printed[i] = true;
            foundDuplicate = true;
        }
    }

    if (!foundDuplicate) {
        cout << "  لا توجد أرقام مكررة - جميع العناصر فريدة!" << endl;
    }

    cout << "\n======================================" << endl;
    return 0;
}
