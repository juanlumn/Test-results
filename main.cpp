#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <ctime>
#include <sstream>

using namespace std;

//Gets the date and return it with the full name of the file
const char* GetDate(bool option){

    //Set the local time
    time_t tSac = time(NULL);
    tm tms = *localtime(&tSac);

    string date;
    stringstream aux;

    const char *name;

    //The name in function if the list
    if (option)date.append("Distinction.[");
    else date.append("Pass.[");

    //Get the date
    aux<<tms.tm_mday;date.append(aux.str()); aux.str(std::string());
    aux<<tms.tm_mon+1;date.append(aux.str());aux.str(std::string());
    aux<<tms.tm_year+1900;date.append(aux.str());date.append("].txt");

    //From string to const char
    name=date.c_str();

    return(name);
}

int CheckResult(string res){

    //By default the output will be DISTINCTION (out=0)
    int out=0;

    //Get the result without the %
    size_t tam= res.length();
    res.erase(tam-1);

    //The output will be PASS if...
    if (atoi(res.c_str())<=70&&atoi(res.c_str())>=40)out=1;
    //Unwanted output
    if(atoi(res.c_str())<40||atoi(res.c_str())>100)out=-1;

    return(out);
}

void WriteResults(string name,string surname,string res){

    const char *rute;

    //If DISTINCTION
    if (CheckResult(res)==0)rute=GetDate(true);
    //If PASS
    if (CheckResult(res)==1)rute=GetDate(false);

    //If not the unwanted output
    if (CheckResult(res)!=-1){
        //Open the proper file and write the name, surname and score
        ofstream file(rute,ios::app);
        if(file.good())file<<name;file<<" ";file<<surname;file<<" ";file<<res;file<<endl;
        file.close();
    }
    return;
}

void LoadResults (void){

    string name,surname,res;

    //Open the file "results.txt"
    ifstream file("results.txt",ios::in);
    if(file.good()){
        //Read the first line
        file>>name;file>>surname;file>>res;
        while(!file.eof()){
            //Call to WriteResults
            WriteResults(name,surname,res);
            //Read the next line
            file>>name;file>>surname;file>>res;
        }
        //Close the file
        file.close();
    }
    return;
}

int main(void)
{
    LoadResults();
    return (0);
}
