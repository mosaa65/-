/*
 * =============================================================
 *  اسم الطالب : عمار الحميري
 *  رقم السؤال : 14
 *  وصف البرنامج: نظام إدارة مطعم متكامل يحتوي على القائمة، 
 *               الطلبات، والأسعار. يستخدم Structs و Arrays و Functions.
 * =============================================================
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ====== تعريف السجلات (Structs) ======

// 1. سجل للصنف في قائمة الطعام
struct MenuItem {
    int id;           // رقم الصنف
    string name;      // اسم الصنف
    double price;     // السعر
    bool available;   // متوفر أم لا؟
};

// 2. سجل لطلب الزبون
struct OrderItem {
    int menuItemId;   // رقم الصنف المطلوب
    string name;      // اسم الصنف
    int quantity;     // الكمية المطلوبة
    double itemTotal; // إجمالي سعر هذا الصنف (السعر * الكمية)
};

// 3. سجل الفاتورة كاملة
struct Bill {
    string customerName;        // اسم الزبون
    OrderItem items[20];        // مصفوفة الطلبات (حد أقصى 20 صنف)
    int numberOfItemsCount;     // عدد الأصناف المطلوبة
    double totalAmount;         // إجمالي الفاتورة
};

// ====== إعلان الدوال Functions ======
void setupMenu(MenuItem menu[]);
void displayMenu(const MenuItem menu[], int size);
int  findMenuItem(const MenuItem menu[], int size, int id);
void takeOrder(const MenuItem menu[], int menuSize, Bill &currentBill);
void printBill(const Bill &currentBill);

// ====== الدالة الرئيسية ======
int main() {
    // إعداد قائمة الطعام
    const int MENU_SIZE = 6;
    MenuItem menu[MENU_SIZE];
    setupMenu(menu);

    Bill currentBill;
    currentBill.numberOfItemsCount = 0;
    currentBill.totalAmount = 0.0;

    int choice;
    do {
        cout << "\n============================================\n";
        cout << "           نظام إدارة مطعم عمار\n";
        cout << "============================================\n";
        cout << "  1. عرض قائمة الطعام\n";
        cout << "  2. تسجيل طلب جديد\n";
        cout << "  3. طباعة الفاتورة\n";
        cout << "  4. الخروج\n";
        cout << "--------------------------------------------\n";
        cout << "اختر عملية: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayMenu(menu, MENU_SIZE);
                break;
            case 2:
                // تنظيف الفاتورة القديمة
                currentBill.numberOfItemsCount = 0;
                currentBill.totalAmount = 0.0;
                cout << "\nأدخل اسم الزبون: ";
                cin.ignore();
                getline(cin, currentBill.customerName);
                takeOrder(menu, MENU_SIZE, currentBill);
                break;
            case 3:
                printBill(currentBill);
                break;
            case 4:
                cout << "\nشكراً لاستخدامك النظام. وداعاً!\n";
                break;
            default:
                cout << "\n⚠️ خيار غير صحيح، الرجاء المحاولة مرة أخرى.\n";
        }
    } while (choice != 4);

    return 0;
}

// ====== تعريف الدوال ======

// دالة لتهيئة قائمة الطعام بالبيانات
void setupMenu(MenuItem menu[]) {
    menu[0] = {101, "برجر لحم مشوي", 25.50, true};
    menu[1] = {102, "شاورما دجاج صاروخ", 15.00, true};
    menu[2] = {103, "بيتزا مارجريتا", 30.00, true};
    menu[3] = {104, "وجبة دجاج بروستد", 35.00, false}; // نفذت الكمية
    menu[4] = {201, "بطاطس مقلية", 8.00, true};
    menu[5] = {301, "عصير برتقال طازج", 10.00, true};
}

// دالة عرض قائمة الطعام
void displayMenu(const MenuItem menu[], int size) {
    cout << "\n============================================\n";
    cout << "              قائمة الطعام\n";
    cout << "============================================\n";
    cout << setw(5) << "الرقم" << " | " 
         << setw(20) << left << "الصنف" << " | "
         << setw(10) << "السعر" << " | "
         << "الحالة" << endl;
    cout << "--------------------------------------------\n";
    
    for (int i = 0; i < size; i++) {
        cout << setw(5) << right << menu[i].id << " | " 
             << setw(20) << left << menu[i].name << " | "
             << setw(10) << menu[i].price << " | ";
        if (menu[i].available)
            cout << "متوفر" << endl;
        else
            cout << "غير متوفر" << endl;
    }
    cout << "============================================\n";
}

// دالة للبحث عن الصنف برقم الـ ID، تعيد موقعه في المصفوفة أو -1 إذا لم يوجد
int findMenuItem(const MenuItem menu[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (menu[i].id == id) {
            return i;
        }
    }
    return -1;
}

// دالة لأخذ الطلبات
void takeOrder(const MenuItem menu[], int menuSize, Bill &currentBill) {
    int itemId, qty;
    char addMore;

    cout << "\n--- تسجيل الطلبات ---\n";
    do {
        cout << "أدخل رقم الصنف (ID): ";
        cin >> itemId;

        int index = findMenuItem(menu, menuSize, itemId);

        if (index == -1) {
            cout << "⚠️ عذراً، الصنف غير موجود في القائمة!\n";
        } else if (!menu[menuSize].available) {
             cout << "⚠️ عذراً، هذا الصنف (" << menu[index].name << ") غير متوفر حالياً!\n";
        } else {
            cout << "لقد اخترت: " << menu[index].name << " (السعر: " << menu[index].price << ")\n";
            do {
                cout << "أدخل الكمية: ";
                cin >> qty;
                if(qty <= 0) cout << "الكمية يجب أن تكون 1 أو أكثر.\n";
            } while (qty <= 0);

            // إضافة الطلب للفاتورة
            int &count = currentBill.numberOfItemsCount; // اختصار مؤشر للعدد
            currentBill.items[count].menuItemId = menu[index].id;
            currentBill.items[count].name = menu[index].name;
            currentBill.items[count].quantity = qty;
            currentBill.items[count].itemTotal = menu[index].price * qty;
            
            // تحديث الإجمالي الكلي للفاتورة
            currentBill.totalAmount += currentBill.items[count].itemTotal;
            count++;

            cout << "✅ تمت الإضافة للفاتورة بنجاح.\n";
        }

        cout << "هل تريد إضافة طلب آخر؟ (y/n): ";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');
}

// دالة لطباعة الفاتورة النهائية
void printBill(const Bill &currentBill) {
    if (currentBill.numberOfItemsCount == 0) {
        cout << "\n⚠️ الفاتورة فارغة، لا توجد طلبات لعرضها.\n";
        return;
    }

    cout << "\n\n";
    cout << "********************************************\n";
    cout << "               فاتورة المبيعات\n";
    cout << "********************************************\n";
    cout << "اسم الزبون: " << currentBill.customerName << endl;
    cout << "عدد الأصناف: " << currentBill.numberOfItemsCount << endl;
    cout << "--------------------------------------------\n";
    cout << setw(20) << left << "الصنف" << " | " 
         << setw(5)  << right << "الكمية" << " | "
         << setw(10) << right << "الإجمالي" << endl;
    cout << "--------------------------------------------\n";

    for (int i = 0; i < currentBill.numberOfItemsCount; i++) {
        cout << setw(20) << left << currentBill.items[i].name << " | " 
             << setw(5)  << right << currentBill.items[i].quantity << " | "
             << setw(10) << right << currentBill.items[i].itemTotal << " ريال\n";
    }

    cout << "--------------------------------------------\n";
    // إضافة ضريبة القيمة المضافة 15%
    double tax = currentBill.totalAmount * 0.15;
    double finalAmount = currentBill.totalAmount + tax;

    cout << setw(25) << right << "المجموع الفرعي: " << setw(10) << right << currentBill.totalAmount << " ريال\n";
    cout << setw(25) << right << "ضريبة (15%): " << setw(10) << right << tax << " ريال\n";
    cout << "********************************************\n";
    cout << setw(25) << right << "الإجمالي المستحق: " << setw(10) << right << finalAmount << " ريال\n";
    cout << "********************************************\n";
    cout << "        نتمنى لكم وجبة هنيئة!\n";
    cout << "********************************************\n";
}
