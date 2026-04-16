/*
 * =============================================================
 *  اسم الطالب : عمار الحميري
 *  رقم السؤال : 13
 *  وصف البرنامج: استخدام السجلات المتداخلة (Nested Structs) 
 *               ومحددات الوصول (Public/Private) لبيانات الكلية والطلاب.
 * =============================================================
 */

#include <iostream>
#include <string>
using namespace std;

// ====== تعريف Struct الكلية ======
struct College {
private:
    string name;       // اسم الكلية
    string major;      // تخصصها
    int departments;   // عدد الأقسام
    string university; // الجامعة التي تتبعها
    string phone;      // رقم الهاتف
    string location;   // موقع الكلية
    string email;      // البريد الإلكتروني

public:
    // دالة لإدخال بيانات الكلية
    void inputCollegeData() {
        cout << "    اسم الكلية           : ";
        getline(cin, name);
        cout << "    التخصص العام للكلية  : ";
        getline(cin, major);
        cout << "    الجامعة التي تتبعها  : ";
        getline(cin, university);
        cout << "    موقع الكلية          : ";
        getline(cin, location);
        cout << "    رقم الهاتف           : ";
        getline(cin, phone);
        cout << "    البريد الإلكتروني    : ";
        getline(cin, email);
        
        do {
            cout << "    عدد الأقسام بالكلية  : ";
            cin >> departments;
            if (departments <= 0) cout << "    ⚠️ عذراً، عدد الأقسام يجب أن يكون أكبر من 0.\n";
        } while (departments <= 0);
    }

    // دالة لعرض بيانات الكلية
    void printCollegeData() const {
        cout << "\n    [ بيانات الكلية ]" << endl;
        cout << "    الكلية    : " << name << " (" << major << ")" << endl;
        cout << "    الجامعة   : " << university << " - " << location << endl;
        cout << "    عدد الأقسام: " << departments << endl;
        cout << "    الاتصال   : " << phone << " | " << email << endl;
    }
};

// ====== تعريف Struct الطالب ======
struct Student {
private:
    string name;       // اسم الطالب
    string studentId;  // الرقم الأكاديمي (يجب ألا يقل عن 6 أرقام)
    College college;   // الكلية (Nesting Structure)
    string major;      // التخصص
    int level;         // المستوى
    int age;           // العمر (لا يقل عن 18)
    string phone;      // رقم الهاتف
    string address;    // العنوان

public:
    // دالة الإدخال
    void inputStudentData() {
        cin.ignore();
        cout << "  اسم الطالب          : ";
        getline(cin, name);

        // التحقق من الرقم الأكاديمي
        do {
            cout << "  الرقم الأكاديمي (6 أرقام على الأقل): ";
            getline(cin, studentId);
            if (studentId.length() < 6) {
                cout << "  ⚠️ خطأ: الرقم الأكاديمي قصير جداً!\n";
            }
        } while (studentId.length() < 6);

        // التحقق من العمر
        do {
            cout << "  عمر الطالب (18 فأكثر) : ";
            cin >> age;
            if (age < 18) {
                cout << "  ⚠️ خطأ: يجب أن يكون العمر 18 عاماً أو أكثر.\n";
            }
        } while (age < 18);

        cin.ignore();
        
        cout << "  التخصص الدقيق       : ";
        getline(cin, major);

        do {
            cout << "  المستوى الدراسي       : ";
            cin >> level;
        } while(level <= 0);
        
        cin.ignore();

        cout << "  رقم الجوال          : ";
        getline(cin, phone);
        cout << "  عنوان السكن         : ";
        getline(cin, address);

        cout << "\n  -- إدخال بيانات الكلية الملتحق بها الطالب --\n";
        college.inputCollegeData(); // استدعاء دالة الكلية من الداخل (Nesting)
    }

    // دالة الطباعة
    void printStudentData() const {
        cout << "------------------------------------------------" << endl;
        cout << "  [ معلومات الطالب الإساسية ]" << endl;
        cout << "  الاسم      : " << name << "\tالعمر : " << age << " سنة" << endl;
        cout << "  الرقم الأكاديمي: " << studentId << endl;
        cout << "  التخصص     : " << major << "\tالمستوى: " << level << endl;
        cout << "  بيانات التواصل: " << phone << " - " << address << endl;
        
        // طباعة بيانات الكلية المتداخلة
        college.printCollegeData();
        cout << "------------------------------------------------" << endl;
    }
};

// ====== الدالة الرئيسية ======
int main() {
    cout << "============================================" << endl;
    cout << "   نظام تسجيل بيانات الطلاب الأكاديمية" << endl;
    cout << "============================================" << endl;

    int n;
    do {
        cout << "أدخل عدد الطلاب المراد تسجيلهم (كحد أقصى 1000): ";
        cin >> n;
        if (n <= 0 || n > 1000) {
            cout << "⚠️ عدد غير صالح! الرجاء إدخال رقم بين 1 و 1000.\n";
        }
    } while (n <= 0 || n > 1000);

    // إنشاء مصفوفة من الطلاب
    Student students[1000];

    // إدخال البيانات
    for (int i = 0; i < n; i++) {
        cout << "\n=== إدخال بيانات الطالب رقم [" << (i + 1) << "] ===" << endl;
        students[i].inputStudentData();
    }

    // عرض البيانات المدخلة
    cout << "\n\n============================================" << endl;
    cout << "          السجلات الأكاديمية المدخلة" << endl;
    cout << "============================================" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << "\nسجل رقم [" << (i + 1) << "]" << endl;
        students[i].printStudentData();
    }

    return 0;
}
