#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<unistd.h>
using namespace std;

class employee{
    
        // Variables for employee details
        char name[30];
        int id;
        char designation[10];
        int age;
        int ctc;
        int experience;
        float sal;
        float grosssal;
        float hra;
        float da;
        float ta;
        float pf;

        // Utility functions
        void waitForEnter(void){
            cout<<"\n\n\n Press the enter key to go back \n\n";
            cin.get();
            cin.get();
        }

        // Functions to perform desired actions
	
	//Function to list total employees with Name, Id and Designation
        void listEmployees(void){ 
            system("cls");
            FILE *file;
            file= fopen("data.txt", "r");
            cout<<"\n\t      List of Employees is as follows\n";
            cout<<"\n----------------------------------------------";
            cout<<"\n NAME        |     ID     |     DESIGNATION\n";
            cout<<"----------------------------------------------";
            while(fscanf(file, "%s %d %s %d %d %d %f %f ", name, &id, designation, &age, &ctc, &experience, &sal, &grosssal)!= EOF)
                cout<<"\n"<<name<<"\t\t"<<id<<"\t\t"<<designation;
            fclose(file);
            waitForEnter();
        }
	//Function to display all details according to Employee's id
        void showDetails(void){ 
            system("cls");
            FILE *file;
            int checkId;
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &designation[0], &age, &ctc, &experience, &sal, &grosssal)!=EOF)
                if(checkId==id){
                    cout<<"\n-----------------------";
                    cout<<"\nName: "<<name;
                    cout<<"\n------------------------";
                    cout<<"\nId: "<<id;
                    cout<<"\n------------------------";
                    cout<<"\nDesignation: "<<designation;
                    cout<<"\n-----------------------";
                    cout<<"\nAge: "<<age;
                    cout<<"\n-----------------------";
                    cout<<"\nCTC: "<<ctc;
                    cout<<"\n---------------------";
                    cout<<"\nExperience: "<<experience;
                    cout<<"\n---------------------";
                    cout<<"\nBasic Salary: "<<sal;
                    cout<<"\n---------------------";
                    cout<<"\nGross Salary: "<<grosssal;
                    cout<<"\n---------------------";
                }
            fclose(file);
            waitForEnter();
        }
	//Function to edit Designation and CTC of an employee
        void editExisting(void){ 
            system("cls");
            int checkId;
            cout<<"\nEnter employee id: ";
            cin>>checkId;
            char newDesignation[10];
            cout<<"\n-----------------------------";
            cout<<"\nEnter new designation: ";
            cin>>newDesignation;
            int newCtc;
            cout<<"------------------------------";
            cout<<"\nEnter new CTC: ";
            cin>>newCtc;
            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &designation[0], &age, &ctc, &experience, &sal, &grosssal)!=EOF){
                if(checkId==id)
                    fprintf(tempfile, "%s %d %s %d %d %d %f %f\n", name, id, newDesignation, age, newCtc, experience, sal, grosssal );
                else
                    fprintf(tempfile, "%s %d %s %d %d %d %f %f \n", name, id, designation, age, ctc, experience, sal, grosssal );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            waitForEnter();
        }
	//Function to add records
        void addNewEmployee(void){ 
        
        	system("cls");
            FILE *file;
            int newid;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &designation[0], &age, &ctc, &experience, &sal, &grosssal)!=EOF)
            {
            	newid=id+1;
			}
            fclose(file);
            
            cout<<"\n----------------------------------------";
            cout<<"\n Enter First Name of the Employee: ";
            cin>>name;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Designation of the Employee: ";
            cin>>designation;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Age of Employee: ";
            cin>>age;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee CTC: ";
            cin>>ctc;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee Experience: ";
            cin>>experience;
            cout<<"\n Enter Employee Basic Salary: ";
            cin>>sal;
            cout<<"\n----------------------------------------";
			
			hra = sal * (.10);
        	da  = sal * (.15);
        	ta  = sal * (.20);
        	pf  = sal * (.25);
        	grosssal = sal + hra + da + ta + pf;
		        	
		        	
            char ch;
            cout<<"\nEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y'){
                FILE  *file;
                file= fopen("data.txt","a");
                fprintf(file, "%s %d %s %d %d %d %f %f \n", name, newid, designation, age, ctc, experience, sal, grosssal );
                fclose(file);
                cout<<"\nNew Employee has been added to database\n";
            }
            else
                addNewEmployee();
            waitForEnter();
        }
	//Function to remove records
        void deleteEmployeeDetails(void){ 
            system("cls");
            int checkId;
            cout<<"\n----------------------------------";
            cout<<"\nEnter Employee Id To Remove: ";
            cin>>checkId;
            char ch;
            cout<<"----------------------------------";
            cout<<"\n\n\n\n\nCONFIRMATION\nEnter 'y' To Confirm Deletion \n";
            cin>>ch;
            if(ch=='y'){
                FILE *file, *tempfile;
                file= fopen("data.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &designation[0], &age, &ctc, &experience, &sal, &grosssal)!=EOF)
                    if(checkId!=id)
                        fprintf(tempfile, "%s %d %s %d %d %d %f %f \n", name, id, designation, age, ctc, experience, sal, grosssal );
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("data.txt");
                int isRenamed= rename("temp.txt", "data.txt");
                cout<<"\nRemoved Successfully\n";
                waitForEnter();
            }
            else
                deleteEmployeeDetails();
        }
	//Function to Calculate salary
        void addOvertime(void){  
        	
        	system("cls");
            FILE *file;
            int checkId,over;
			float newgrosssal;
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            cout<<"\n\nEnter the overtime (number of hours) : ";
            cin>>over;
            
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &designation[0], &age, &ctc, &experience, &sal, &grosssal)!=EOF)
                if(checkId==id){
		        	newgrosssal = grosssal + over*1000;
                }
            fclose(file);
            
            cout<<"\n\nOvertime amount "<<over*1000<<" added to the Gross Salary\n\n";
            
            
            FILE *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &designation[0], &age, &ctc, &experience, &sal, &grosssal)!=EOF){
                if(checkId==id)
                    fprintf(tempfile, "%s %d %s %d %d %d %f %f \n", name, id, designation, age, ctc, experience, sal, newgrosssal );
                else
                    fprintf(tempfile, "%s %d %s %d %d %d %f %f \n", name, id, designation, age, ctc, experience, sal, grosssal );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            waitForEnter();
            
        	
		}
		void generatePay(void){  //to generate pay slip
			system("cls");
            FILE *file;
            int checkId;
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &designation[0], &age, &ctc, &experience, &sal, &grosssal)!=EOF)
                if(checkId==id){
                	cout<<"\n-----------------------------";
		            cout<<"\n\tPAYSLIP\n";
		            cout<<"-----------------------------";
		            cout<<"\nBasic salary\t:\t"<<sal;
		            cout<<"\nhra\t\t:\t"<<sal*(.10);
		            cout<<"\nda\t\t:\t"<<sal*(.15);
		            cout<<"\nta\t\t:\t"<<sal*(.20);
		            cout<<"\npf\t\t:\t"<<sal*(.25);
		            cout<<"\nGross Salary\t:\t"<<grosssal;
                }
            fclose(file);
            waitForEnter();
		}


    public:
        // Function to serve as end point
        void options(void){ //menu
        int login(); //login declaration
                login();//login screen
            while(true){
                system("cls");
                
                // Options to choose an action
                cout<<"\n\t\t\t>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<";
                cout<<"\n";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   1:   To View List of Employees";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   2:   To View Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   3:   To Modify Existing Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   4:   To Add New Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   5:   To Remove an Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   6:   To Add Overtime";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   7:   To Generate PaySlip";
                cout<<"\n\t\t\t------------------------------------------------";
				cout<<"\n\t\t\tENTER   0:   To Exit     ";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";

                // Taking the action input
                int choice;
                cin>>choice;
                // Calling relevant function as per choice
                switch (choice) {
                    case 0:
                    	system("CLS");
                        cout<<"\n\nEMPLOYEE MANAGEMENT SYSTEM \n\n Thank You ('.') \n\n ";
                        Sleep(10);
                        return;
                    case 1:
                        listEmployees();
                        break;
                    case 2:
                        showDetails();
                        break;
                    case 3:
                        editExisting();
                        break;
                    case 4:
                        addNewEmployee();
                        break;
                    case 5:
                        deleteEmployeeDetails();
                        break;
                    case 6:
                        addOvertime();
                        break;
                    case 7:
                        generatePay();
                        break;
                    default:
                        cout<<"\n Sorry..!! I don't understand that..!! \n";
                        break;
                }

            }
        }

};

int main(){
    // Call the options function
    employee e;
    e.options();
    return 0;
}

int login(){ //login procedure
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\t\t\t\t\tEMPLOYEE MANAGEMENT SYSTEM";
   cout <<"\n\n\n\n\n\t\t\t\t\tEnter Your Password :";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass"){
   	cout<<"\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
   	for(int a=1;a<8;a++) // Change 'a<?' to how many * you want
	{
		Sleep(500);
		cout << "...";
	}
      cout << "\n\n\n\t\t\t\t\tAccess Granted..!! \n\n\n";
      
      system("PAUSE");
      system("CLS");
   }else{
      cout << "\nAccess Aborted...!!\n";
      login();
   }
}

