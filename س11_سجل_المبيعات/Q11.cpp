/*
 * =============================================================
 *  اسم الطالب : عمار الحميري
 *  رقم السؤال : 11
 *  وصف البرنامج: Struct لتخزين معلومات المبيعات
 *               (اسم المندوب، الشهر، مبيعات كل منتج)
 *               ثم عرض المندوبين الذين تجاوزت مبيعاتهم حداً معيناً
 * =============================================================
 */

#include <iostream>
#include <string>
using namespace std;

// ====== تعريف الـ Struct ======
struct SalesRecord {
    string repName;    // اسم مندوب المبيعات
    string month;      // الشهر
    double product1;   // مبيعات المنتج الأول
    double product2;   // مبيعات المنتج الثاني
    double product3;   // مبيعات المنتج الثالث
    double totalSales; // مجموع المبيعات (يُحسب تلقائياً)
};

// ====== إعلان الدوال ======
SalesRecord inputRecord(int repNumber);
void        displayRecord(SalesRecord rec);
void        displayTopSales(SalesRecord records[], int count, double target);

// ====== الدالة الرئيسية ======
int main() {

    cout << "============================================" << endl;
    cout << "   نظام إدارة مبيعات فريق المندوبين" << endl;
    cout << "============================================" << endl;

    int n;
    cout << "أدخل عدد مندوبي المبيعات: ";
    cin >> n;
    cin.ignore(); // لتجاهل سطر الإدخال

    SalesRecord records[50];

    // ------- إدخال البيانات -------
    cout << "\n--- إدخال بيانات المندوبين ---\n" << endl;
    for (int i = 0; i < n; i++) {
        cout << "=== المندوب رقم " << i + 1 << " ===" << endl;
        records[i] = inputRecord(i + 1);
        cout << endl;
    }

    // ------- عرض جميع السجلات -------
    cout << "\n============================================" << endl;
    cout << "   بيانات جميع المندوبين" << endl;
    cout << "============================================" << endl;
    for (int i = 0; i < n; i++) {
        displayRecord(records[i]);
    }

    // ------- عرض المتميزين -------
    double target;
    cout << "\nأدخل الحد الأدنى للمبيعات المتميزة: ";
    cin >> target;

    displayTopSales(records, n, target);

    return 0;
}

// ====== دالة إدخال سجل واحد ======
SalesRecord inputRecord(int repNumber) {
    SalesRecord rec;
    cout << "  اسم المندوب: ";
    getline(cin, rec.repName);
    cout << "  الشهر: ";
    getline(cin, rec.month);
    cout << "  مبيعات المنتج الأول : ";
    cin >> rec.product1;
    cout << "  مبيعات المنتج الثاني: ";
    cin >> rec.product2;
    cout << "  مبيعات المنتج الثالث: ";
    cin >> rec.product3;
    cin.ignore();

    rec.totalSales = rec.product1 + rec.product2 + rec.product3;
    return rec;
}

// ====== دالة عرض سجل واحد ======
void displayRecord(SalesRecord rec) {
    cout << "--------------------------------------------" << endl;
    cout << "  المندوب  : " << rec.repName           << endl;
    cout << "  الشهر    : " << rec.month             << endl;
    cout << "  منتج 1   : " << rec.product1 << " ريال" << endl;
    cout << "  منتج 2   : " << rec.product2 << " ريال" << endl;
    cout << "  منتج 3   : " << rec.product3 << " ريال" << endl;
    cout << "  الإجمالي : " << rec.totalSales << " ريال" << endl;
}

// ====== دالة عرض المتميزين ======
void displayTopSales(SalesRecord records[], int count, double target) {
    cout << "\n============================================" << endl;
    cout << "  المندوبون الذين تجاوزت مبيعاتهم "
         << target << " ريال:" << endl;
    cout << "============================================" << endl;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (records[i].totalSales > target) {
            cout << "  ⭐ " << records[i].repName
                 << " - الإجمالي: " << records[i].totalSales
                 << " ريال" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "  لا يوجد مندوبون تجاوزوا الحد المحدد." << endl;
    }
    cout << "============================================" << endl;
}
