Test-results
============

C++ program wich reads the contents of a results.txt file and:

  - Creates a new file with the file name Pass.[CurrentDate].txt and adds the student names and scores of the users that
    passed and leaves out the students that scored distinction.

  - Creates a new file with the file name Distinction.[CurrentDate].txt and adds the student names and scores of the 
    users that earned a distinction.

In both instances [CurrentDate] will be the current date at the time the script ran in the format ddmmyyyy.

In order to test it please use the attached file 'results.txt' or a new one following the format:
'Name' 'Surname' 'result%', ie: John Smith 56%
