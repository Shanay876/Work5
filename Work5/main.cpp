//
//  main.cpp
//  Homework7
//
//  Created by Shanay Saddler on 11/17/14.
//  Copyright (c) 2014 ___SHANAY SADDLER___. All rights reserved.
//
#include <fstream>//header files
#include <iostream>//This is for input and output of the file
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream>
using namespace std;
ifstream myfile;
void Evaluate_Cholesterol(int,int,string&,string&);//declaring functions with parameters
void Evaluate_Blood_Pressure(int, int, string&,string&);
string HDL_Evaluation(int);
string LDL_Evaluation(int);
string SYSTO_Evaluation(int);
string DIASTO_Evaluation(int);
string type_patient(char);
string ratio_eval(float);
int main ()
{
    cout << "****************************************************************************"<< endl;//Heading for the program
    cout << "Shanay Saddler" << endl;
    cout << "ID 02713672" << endl;
    cout << "SYCS-135 Computer Science I" << endl;
    cout << "Assignment 7" << endl;
    cout << "November 18, 2014" << endl;
    cout << "****************************************************************************"<< endl;
    int number,numbervisits, HDL, LDL, SYSTO, DIASTO, next=1,count=0;//declare variables
    string PName, HDL_eval, LDL_eval, SYSTO_eval, DIASTO_eval, TYPE;
    char typeofpatient;
    cout<<"Enter the number of patient records:";//prompt the user to enter the number of patient's records they want to see
    cin >> number;
    myfile.open("infile.txt");//open the file
    
    myfile>>PName;//reading patient's info to see if it was already read.(priming reading)
    myfile>>typeofpatient;//reading type of patient
    TYPE = type_patient(typeofpatient);//return the string of what each type means
    myfile>>numbervisits;
    
    while(!myfile.eof())//while it is not the end of the file
        //for(int count = 0; count < number; count++)
    {
        if(count == number)//if count is equal to number then stop reading
            break;
        cout<<"\n"<<TYPE<<" Patient's Name- "<<PName<<"\n\n";//print statement
        for(int count2 = 0; count2 < numbervisits; count2++)//inner for loop for the doc's documentation based on each visit
        {
            cout<<"DATA SET "<<next<<"\n";
            next++;
            myfile>>HDL;//reading from the file
            myfile>>LDL;
            myfile>>SYSTO;
            myfile>>DIASTO;
            HDL_eval= HDL_Evaluation(HDL);// storing the returned value in string variable
            LDL_eval = LDL_Evaluation(LDL);// storing the returned value in string variable
            SYSTO_eval=SYSTO_Evaluation(SYSTO);// storing the returned value in string variable
            DIASTO_eval=DIASTO_Evaluation(DIASTO);// storing the returned value in string variable
            Evaluate_Cholesterol(HDL, LDL, HDL_eval, LDL_eval);//calling on the function to print records
            Evaluate_Blood_Pressure(SYSTO, DIASTO, SYSTO_eval, DIASTO_eval);//calling on the function to print records
        }
        next=1;//reset the counter for each patient
        myfile>>PName;
        myfile>>typeofpatient;
        TYPE = type_patient(typeofpatient);
        myfile>>numbervisits;
        count++;
    }
    myfile.close();//close file
    return 0;
}
string type_patient(char typeofpatient)//function to return what each type in the file meant
{
    string currentpatient,newpatient, refpatient, retpatient;
    if (typeofpatient == 'C')
        return (currentpatient = "Current");
    else if (typeofpatient == 'N')
        return (newpatient = "New");
    else if (typeofpatient == 'F')
        return (refpatient = "Referral");
    else
        return (retpatient = "Returning");
}
string HDL_Evaluation(int HDL)//function to return the what the level of each patient HDL meant
{
    string Excellent, TooLow,IsOkay;
    if (HDL<40)
        return (TooLow = "Too Low");
    else if ((HDL>=40)&&(HDL<60))
        return (IsOkay = "Is Okay");
    else
        return (Excellent = "Excellent");
}
string LDL_Evaluation(int LDL)//function to return the what the level of each patient LDL meant
{
    string OPTIMAL, NEAROPTIMAL, BORDERLINE, HIGH, VERYHIGH;
    if (LDL<100)
        return (OPTIMAL = "Optimal");
    else if ((LDL>=100)&&(LDL<130))
        return (NEAROPTIMAL = "Near Optimal");
    else if ((LDL>=130)&&(LDL<160))
        return (BORDERLINE = "Borderline High");
    else if ((LDL>=160)&&(LDL<190))
        return (HIGH = "High");
    else
        return (VERYHIGH ="very high");
}
string SYSTO_Evaluation(int SYSTO)//function to return the what the level of each patient systolic meant
{
    string OPTIMAL, NORMAL, NORMALHIGH, STAGE1, STAGE2, STAGE3;
    if (SYSTO < 120)
        return (OPTIMAL = "Optimal");
    else if (SYSTO < 130)
        return (NORMAL = "Normal");
    else if (SYSTO <140)
        return (NORMALHIGH = "Normal High");
    else if (SYSTO < 160)
        return (STAGE1 = "Stage 1 Hypertension");
    else if (SYSTO < 180)
        return (STAGE2 = "Stage 2 Hypertension");
    else
        return (STAGE3 = "Stage 3 Hypertension");
}
string DIASTO_Evaluation(int DIASTO)//function to return the what the level of each patient diastolic meant
{
    string OPTIMAL, NORMAL, NORMALHIGH, STAGE1, STAGE2, STAGE3;
    if (DIASTO < 80)
        return (OPTIMAL = "Optimal");
    else if (DIASTO < 85)
        return (NORMAL = "Normal");
    else if (DIASTO < 90)
        return (NORMALHIGH = "Normal High");
    else if (DIASTO < 100)
        return (STAGE1 = "Stage 1 Hypertension");
    else if (DIASTO < 110)
        return (STAGE2 = "Stage 2 Hypertension");
    else
        return (STAGE3 = "Stage 3 Hypertension");
}
void Evaluate_Cholesterol(int HDL,int LDL,string& HDL_eval,string& LDL_eval)//function to print records
{
    string ratio;
    float patientratio;
    patientratio = (float)HDL/ (float)LDL;//returned float value
    ratio = ratio_eval(patientratio);
    cout<<"Cholesterol Profile\n";
    cout<<" HDL:"<<HDL<<" LDL:"<<LDL<<"\n";
    cout<<" Ratio:"<<fixed<<setprecision(4)<<showpoint<<patientratio<<"\n";
    cout<<" HDL is "<<HDL_eval<<"\n";
    cout<<" LDL is "<<LDL_eval<<"\n";
    cout<<" Ratio of HDL to LDL is "<<ratio<<"\n";//print the ratio to two decimal place
}
string ratio_eval(float patientratio)
{
    string GOOD, NOTGOOD;
    if (patientratio > 0.3)
        return (GOOD = "Good");
    else
        return (NOTGOOD = "Not Good");
}
void Evaluate_Blood_Pressure(int SYSTO,int DIASTO,string& SYSTO_eval,string& DIASTO_eval)
{
    cout<<"Blood Pressure Profile\n";
    cout<<" Systolic "<<SYSTO<<" Diastolic:"<<DIASTO<<"\n";
    cout<<" Systolic reading is "<<SYSTO_eval<<"\n";
    cout<<" Diastolic reading is "<<DIASTO_eval<<"\n\n";
}
/*
 ****************************************************************************
 Shanay Saddler
 ID 02713672
 SYCS-135 Computer Science I
 Assignment 7
 November 18, 2014
 ****************************************************************************
 Enter the number of patient records:5
 
 Current Patient's Name- Jones
 
 DATA SET 1
 Cholesterol Profile
 HDL:60 LDL:124
 Ratio:0.4839
 HDL is Excellent
 LDL is Near Optimal
 Ratio of HDL to LDL is Good
 Blood Pressure Profile
 Systolic 130 Diastolic:84
 Systolic reading is Normal High
 Diastolic reading is Normal
 
 DATA SET 2
 Cholesterol Profile
 HDL:65 LDL:121
 Ratio:0.5372
 HDL is Excellent
 LDL is Near Optimal
 Ratio of HDL to LDL is Good
 Blood Pressure Profile
 Systolic 133 Diastolic:80
 Systolic reading is Normal High
 Diastolic reading is Normal
 
 DATA SET 3
 Cholesterol Profile
 HDL:70 LDL:120
 Ratio:0.5833
 HDL is Excellent
 LDL is Near Optimal
 Ratio of HDL to LDL is Good
 Blood Pressure Profile
 Systolic 130 Diastolic:81
 Systolic reading is Normal High
 Diastolic reading is Normal
 
 
 New Patient's Name- Smith
 
 DATA SET 1
 Cholesterol Profile
 HDL:30 LDL:195
 Ratio:0.1538
 HDL is Too Low
 LDL is very high
 Ratio of HDL to LDL is Not Good
 Blood Pressure Profile
 Systolic 120 Diastolic:85
 Systolic reading is Normal
 Diastolic reading is Normal High
 
 
 Referral Patient's Name- Williams
 
 DATA SET 1
 Cholesterol Profile
 HDL:45 LDL:185
 Ratio:0.2432
 HDL is Is Okay
 LDL is High
 Ratio of HDL to LDL is Not Good
 Blood Pressure Profile
 Systolic 190 Diastolic:112
 Systolic reading is Stage 3 Hypertension
 Diastolic reading is Stage 3 Hypertension
 
 DATA SET 2
 Cholesterol Profile
 HDL:50 LDL:181
 Ratio:0.2762
 HDL is Is Okay
 LDL is High
 Ratio of HDL to LDL is Not Good
 Blood Pressure Profile
 Systolic 193 Diastolic:115
 Systolic reading is Stage 3 Hypertension
 Diastolic reading is Stage 3 Hypertension
 
 
 Returning Patient's Name- Foster
 
 DATA SET 1
 Cholesterol Profile
 HDL:55 LDL:165
 Ratio:0.3333
 HDL is Is Okay
 LDL is High
 Ratio of HDL to LDL is Good
 Blood Pressure Profile
 Systolic 163 Diastolic:115
 Systolic reading is Stage 2 Hypertension
 Diastolic reading is Stage 3 Hypertension
 
 DATA SET 2
 Cholesterol Profile
 HDL:65 LDL:145
 Ratio:0.4483
 HDL is Excellent
 LDL is Borderline High
 Ratio of HDL to LDL is Good
 Blood Pressure Profile
 Systolic 167 Diastolic:95
 Systolic reading is Stage 2 Hypertension
 Diastolic reading is Stage 1 Hypertension
 
 DATA SET 3
 Cholesterol Profile
 HDL:57 LDL:165
 Ratio:0.3455
 HDL is Is Okay
 LDL is High
 Ratio of HDL to LDL is Good
 Blood Pressure Profile
 Systolic 163 Diastolic:105
 Systolic reading is Stage 2 Hypertension
 Diastolic reading is Stage 2 Hypertension
 
 DATA SET 4
 Cholesterol Profile
 HDL:59 LDL:163
 Ratio:0.3620
 HDL is Is Okay
 LDL is High
 Ratio of HDL to LDL is Good
 Blood Pressure Profile
 Systolic 165 Diastolic:108
 Systolic reading is Stage 2 Hypertension
 Diastolic reading is Stage 2 Hypertension
 
 Program ended with exit code: 0
 */
