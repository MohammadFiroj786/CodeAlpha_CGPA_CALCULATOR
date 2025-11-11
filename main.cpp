#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
using namespace std;

// Function to convert grade letter to grade point
double gradeToPoint(string grade) {
    if (grade == "A" || grade == "a") return 10.0;
    else if (grade == "B" || grade == "b") return 8.0;
    else if (grade == "C" || grade == "c") return 6.0;
    else if (grade == "D" || grade == "d") return 5.0;
    else if (grade == "F" || grade == "f") return 0.0;
    else return -1; // Invalid grade
}

int main() {
    system("chcp 65001 >nul"); // enable UTF-8 support
    cout << "=========================================\n";
    cout << "        🎓 CodeAlpha Internship\n";
    cout << "             CGPA CALCULATOR\n";
    cout << "            By: Mohammad Firoj\n";
    cout << "=========================================\n\n";

    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of courses! Exiting...\n";
        return 0;
    }

    vector<string> courseNames(n);
    vector<string> grades(n);
    vector<double> credits(n);
    vector<double> gradePoints(n);

    double totalCredits = 0.0, totalGradePoints = 0.0;

    cout << "\n---------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "Course #" << (i + 1) << " name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, courseNames[i]);

        double gp;
        do {
            cout << "Enter grade (A/B/C/D/F): ";
            cin >> grades[i];
            gp = gradeToPoint(grades[i]);
            if (gp == -1) {
                cout << "Invalid grade! Please enter A, B, C, D, or F.\n";
            }
        } while (gp == -1);
        gradePoints[i] = gp;

        cout << "Enter credit hours: ";
        cin >> credits[i];

        totalCredits += credits[i];
        totalGradePoints += credits[i] * gp;

        cout << "---------------------------------------------\n";
    }

    double cgpa = totalGradePoints / totalCredits;
    string performance;

    if (cgpa >= 9.0) performance = "Excellent 🌟";
    else if (cgpa >= 8.0) performance = "Very Good 👍";
    else if (cgpa >= 6.0) performance = "Good 🙂";
    else performance = "Needs Improvement 😔";

    // Display summary
    cout << "\n=================== COURSE SUMMARY ===================\n";
    cout << left << setw(5) << "No."
         << setw(20) << "Course Name"
         << setw(10) << "Grade"
         << setw(15) << "Credit Hours"
         << setw(15) << "Grade Points" << "\n";
    cout << "------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << left << setw(5) << (i + 1)
             << setw(20) << courseNames[i]
             << setw(10) << grades[i]
             << setw(15) << credits[i]
             << setw(15) << fixed << setprecision(2) << (credits[i] * gradePoints[i]) << "\n";
    }

    cout << "------------------------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Total Credits: " << totalCredits << "\n";
    cout << "Total Grade Points: " << totalGradePoints << "\n";
    cout << "------------------------------------------------------\n";
    cout << "Final CGPA: " << cgpa << "\n";
    cout << "Performance: " << performance << "\n";
    cout << "------------------------------------------------------\n";
    cout << "Thank you for using the CGPA Calculator.\n";
    cout << "=========================================\n";

    // ✅ Ask user before saving
    char saveChoice;
    cout << "\nDo you want to save this report to a file? (y/n): ";
    cin >> saveChoice;

    if (tolower(saveChoice) == 'y') {
        ofstream report("cgpa_report.txt");
        if (report.is_open()) {
            report << "=========================================\n";
            report << "           🎓 CGPA REPORT SUMMARY\n";
            report << "=========================================\n\n";

            report << left << setw(5) << "No."
                   << setw(20) << "Course Name"
                   << setw(10) << "Grade"
                   << setw(15) << "Credit Hours"
                   << setw(15) << "Grade Points" << "\n";
            report << "------------------------------------------------------\n";

            for (int i = 0; i < n; i++) {
                report << left << setw(5) << (i + 1)
                       << setw(20) << courseNames[i]
                       << setw(10) << grades[i]
                       << setw(15) << credits[i]
                       << setw(15) << fixed << setprecision(2) << (credits[i] * gradePoints[i]) << "\n";
            }

            report << "------------------------------------------------------\n";
            report << "Total Credits: " << totalCredits << "\n";
            report << "Total Grade Points: " << totalGradePoints << "\n";
            report << "Final CGPA: " << cgpa << "\n";
            report << "Performance: " << performance << "\n";
            report << "------------------------------------------------------\n";
            report << "Report saved successfully ✅\n";
            report.close();
            cout << "\n📁 Report saved successfully as 'cgpa_report.txt'!\n";
        } else {
            cout << "\n⚠️ Error: Could not save report.\n";
        }
    } else {
        cout << "\nReport not saved. ✅\n";
    }

    return 0;
}
