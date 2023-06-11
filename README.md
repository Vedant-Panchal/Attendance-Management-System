# Attendance-Management-System
Attendance Management System: A C-based project to automate marking of student attendance , generate reports, and maintain accurate records. Features include marking attendance, viewing/editing records, student information search, and report export. Streamlines processes and enhances efficiency in educational institutions.

**Introduction**

The Attendance Management System is a C-based software application for managing student attendance records. This readme file provides instructions on how to change the file name for loading student data and exporting attendance reports according to your needs.

To Load Student Data Accoding to your needs you can do the following steps

1) Open the _main()_ function.
2) Locate the section of code where student data is loaded. It should be identified with a function name _loadStudentList()_.
3) Look for the line of code that specifies the file names. It should resemble:  
  _nameFile = fopen("name.txt", "r");
  enrollFile = fopen("enrollno.txt", "r");
  rollNoFile = fopen("roll-no.txt", "r");_
4) Now open all three txt files and make the changes in roll no , enrollment number and student names.Make sure the file contains each data on a new line, with student details organized as per the system's       expectations.

**Exporting Attendance Reports**

1) Open the _main()_ function.
2) Find the section of code responsible for exporting attendance reports. It should be identified with a function name _exportAttendanceToTxtFile()_.
3) Locate the line of code that defines the output file name. It may look like: _char subjectFiles[6][30] = {   //storing the file names in an array[i][j]
    "maths-attendance.txt",
    "ds-attendance.txt",
    "be-attendance.txt",
    "ap-attendance.txt",
    "egd-attendance.txt",
    "hv-attendance.txt"};_
4) Modify the **array** with your **required number of subjects i.e changing the value of "i" with the desired number of subjects for the attendance report export**.You can also change the filenames according to your need    and make the changes in the values of array i.e filenames.
5) Ensure the file name has an appropriate file extension, such as .txt or .csv, depending on your preference.

**Saving Changes**

1) Once you have made the necessary modifications to the file names, save the file.
2) Compile the code using your preferred C compiler.
3) Run the compiled program to verify that the changes are applied correctly.

**Note:** Ensure that the file paths and names are accurate to avoid any runtime errors. It is recommended to keep backup copies of the original files before making any changes.
Conclusion

By following these instructions, you can easily customize the file names for loading student data and exporting attendance reports in the Attendance Management System. Adapt the file names according to your needs, ensuring the files are correctly formatted and easily accessible.

**You can also refer to my presentation to understand the program :** https://docs.google.com/presentation/d/1DTfEJFqVUfU1AEIaDSdeEwLTJwiztM5q/edit?usp=drive_link&ouid=111670482615295196305&rtpof=true&sd=true
