🎓 CGPA Calculator — C++ Project

CodeAlpha Internship | By: Mohammad Firoj

📌 Project Overview

The CGPA Calculator is a simple yet powerful C++ console application that calculates a student's CGPA based on their course grades and credit hours.
It provides clean input validation, formatted output, and the option to save a detailed course report.

🚀 Features

✅ Enter number of courses
✅ Input course name, grade, credit hours
✅ Grade validation (A/B/C/D/F)
✅ Dynamic vector-based storage
✅ Calculates:

Total credits

Total grade points

CGPA
✅ Performance level (Excellent/Good/Needs Improvement)
✅ Cleanly formatted summary table
✅ Save report to .txt file

🧠 Concepts Used

Input validation

File handling (ofstream)

Functions

Vectors

Formatting using iomanip

Looping & conditionals

🏗️ How It Works

1️⃣ Student enters total number of courses
2️⃣ For each course:

Name

Grade

Credit hours
3️⃣ Program converts grade → grade points
4️⃣ CGPA is calculated using formula:

CGPA = Total Grade Points / Total Credits


5️⃣ Summary is displayed
6️⃣ User can choose to save report

📄 Sample Output
Course Name    Grade    Credit    Grade Points
Maths          A        4         40
Physics        B        3         24
Chemistry      C        3         18
-------------------------------------------
Total Credits: 10
Total Grade Points: 82
Final CGPA: 8.20
Performance: Very Good 👍

💾 File Output

The program can generate a cgpa_report.txt file:

CGPA REPORT SUMMARY
-------------------
Course Name | Grade | Credit Hours | Grade Points
...
Final CGPA: 8.20
Performance: Very Good

🧰 Run Instructions
Compile the program
g++ main.cpp -o cgpa

Run the program
./cgpa

📁 File Structure
📂 CGPA_Calculator
 ┣ main.cpp
 ┗ cgpa_report.txt  (auto-generated)

🧑‍💻 Author

Mohammad Firoj
✅ CodeAlpha C++ Internship Project
