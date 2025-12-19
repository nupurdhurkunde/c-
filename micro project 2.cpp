#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include<iomanip>
using namespace std;
 void home();
 void update();
 void insert();
 void remove();
 void login();
 struct employee{
 	string fname, lname, password, email, department;
	long long contact, doj;
 };
 
 void color( int color)
 {
 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
 }

void saveemployee(employee emp){
    ofstream fout("employee.txt",ios::app);
    fout<<emp.fname<<" "<<emp.lname<<" "<<emp.password<<" "<<emp.email<<" "<<emp.department<<" "<<emp.contact<<" "<<emp.doj<<endl;
    fout.close();}
    
bool searchemployee(string fname, string lname, string pass, employee &emp){
	ifstream fin("employee.txt");
while (fin>>emp.fname>>emp.lname>>emp.password>>emp.email>>emp.department>>emp.contact>>emp.doj){
	if(emp.fname==fname && emp.lname==lname && emp.password==pass){
	    fin.close();
		return true;
	}
}
fin.close();
return false;
}    

void deleteemployee(string fname, string lname, string pass){
	ifstream fin("employee.txt");
	ofstream fout("temp.txt");
	employee emp;
	bool found=false;
	
while (fin>>emp.fname>>emp.lname>>emp.password>>emp.email>>emp.department>>emp.contact>>emp.doj){
	if (emp.fname==fname && emp.lname==lname && emp.password==pass){
		found=true;
		continue;
	}
	fout<<emp.fname<<" "<<emp.lname<<" "<<emp.password<<" "<<emp.email<<" "<<emp.department<<" "<<emp.contact<<" "<<emp.doj<<endl;
}	
fin.close();
fout.close();
remove("employee.txt");
rename("temp.txt","employee.txt");
if (found)
cout<<"employee deleted successfully"<<endl;
else 
cout<<"record not found"<<endl;
}

void firstpage(){
	char a[]="EMPLOYEE PERSONAL INFORMATION MANAGEMENT SYSTEM";
	color(12);
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"                                                    ";
	Sleep(1000);
	for(int i=0; i<47; i++){
		cout<<a[i];
		Sleep(200);
	}
	Sleep(2000);
}

void name(){
	system("CLS");
	ifstream fin ("employee.txt");
	employee emp;
	color(14);
	cout<<"============ LIST OF EMPLOYEES ============"<<endl<<endl;
	color(11);
	cout<<left<<setw(15)<<"First name"
	    <<setw(15)<<"Last name"
		<<setw(25)<<"Email"
		<<setw(25)<<"Department"
		<<setw(15)<<"Contact"
		<<setw(15)<<"Date of joining"<<endl;
	color(7);
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
	while(fin >> emp.fname>> emp.lname>> emp.password>> emp.email>> emp.department>> emp.contact >> emp.doj){
		cout<<left<<setw(15)<<emp.fname
		    <<setw(15)<<emp.lname
			<<setw(25)<<emp.email 
			<<setw(25)<<emp.department
			<<setw(15)<<emp.contact
			<<setw(15)<<emp.doj<<endl;
	} fin.close();
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
	system("pause");
	home();
	
}

void login(){
    system("CLS");
    string fname, lname, pass;
    int a,e,k,j,f,s,t,l,v,y;
    employee emp;
    color(14);
	cout<<"============ LOGIN PORTAL ============"<<endl<<endl;
	color(7);
	cout<<" Enter username : ";
	cin>>fname>>lname;
	cout<<endl<<" Enter password : ";
	cin>>pass;
	if(searchemployee(fname, lname, pass, emp))
	{system("CLS");
	color(14);	
	cout<<"============ EMPLOYEE DASHBOARD ============"<<endl<<endl;
	color(11);
    cout<<"Welcome, ";
    color(7);
	cout<<emp.fname<<" "<<emp.lname<<endl<<endl;
	cout<<"-----------------------------------"<<endl;
	color(11);
    cout<<"Email           : ";
    color(7);
	cout<<emp.email<<endl;
    cout<<"-----------------------------------"<<endl;
    color(11);
    cout<<"Department      : ";
	color(7);
	cout<<emp.department<<endl;
    cout<<"-----------------------------------"<<endl;
    color(11);
    cout<<"Contact         : ";
	color(7);
	cout<<emp.contact<<endl;
    cout<<"-----------------------------------"<<endl;
    color(11);
    cout<<"Date of joining : ";
    color(7);
	cout<<emp.doj<<endl;
    cout<<"-----------------------------------"<<endl<<endl;
    color(12);
    cout<<"* Press 1 to see months left in next increment "<<endl;
    cout<<"* Press 2 to mark attendance"<<endl;
    cout<<"* Press 3 to view attendance"<<endl;
    cout<<"* Press 4 to go back to home"<<endl;
    color(7);
	cin>>a;
    if (a==1){
    	system("CLS");
        color(11);	
	    cout<<"============ EMPLOYEE DASHBOARD ============"<<endl<<endl;
        color(7);
		cout<<"Your date of joining (dd mm yyyy): ";
		cin>>e>>k>>j;
		cout<<"Enter today's date : ";
		cin>>f>>s>>t;
		cout<<endl<<"so your joining date is : "<<e<<"/"<<k<<"/"<<j<<endl;
		cout<<"and today is : "<<f<<"/"<<s<<"/"<<t<<endl<<endl;
		y=t-j;
	    if ( k>s && e>f){
	        y=y-1;
	        l=(30-e)+f;
	        v=s-1;}
        else if(k>s && e<=f){
	        l=f-e;
		    v=s;
	        y=y-1;}
   		else if(s>k && e>f){
	        l=(30-e)+f;
	        v=(s-k)-1;}
	   	else if(e<=f && s>k){
	        l=f-e;
	        v=s-k;}
		cout<<"So you're working with us : "<<l<<" days "<<v<<" months "<<y<<" year "<<endl<<endl;
	    if(v>6)
		v=12-v;
	  	else if(v<=6)
	    v=6-v;
		cout<<"So you're having your next increment in : ";
		color(12);
		cout<<v<<" months"<<endl<<endl;}
	else if(a==2){
		system("CLS");
		employee emp;
		ifstream fin("employee.txt");
		long long date;
		char status;
		bool found=false;
		while(fin>>emp.fname>>emp.lname>>emp.password>>emp.email>>emp.department>>emp.contact>>emp.doj){
		if(emp.fname==fname && emp.lname==lname){
			found=true;
			break;}}
		fin.close();
		if(found){
			color(11);
			cout<<"====================== ATTENDANCE RECORD ======================"<<endl<<endl;
			color(7);
			cout<<"Enter date (ddmmyyyy) :";
			cin>>date;
			cout<<endl<<"Enter attendance (P/A) :";
			cin>>status;
			ofstream fout("attendance.txt",ios::app);
			fout<<fname<<" "<<lname<<" "<<date<<" "<<status<<endl;
			fout.close();
			cout<<endl<<"Attendance marked successfully"<<endl;}	
		else{
			cout<<"Employee not found"<<endl;}
		system("pause");
		home();}
	else(a==3);{
		system("CLS");
	    ifstream fin("attendance.txt");
		long long date;
		char status;
		color(11);
	    cout<<"====================== ATTENDANCE RECORD ======================"<<endl<<endl;
	    color(7);
	    cout<<left<<setw(15)<<"First Name"
                  <<setw(15)<<"Last Name"	    
	              <<setw(15)<<"Date"
	              <<setw(10)<<"Status"<<endl;
	    cout<<"---------------------------------------------------------------"<<endl;
		while(fin >> fname >> lname >> date >> status){
			cout<<left<<setw(15)<<fname
                  <<setw(15)<<lname	    
	              <<setw(15)<<date
	              <<setw(10)<<status<<endl;
		}        
		fin.close();
		cout<<"---------------------------------------------------------------"<<endl;
		system("pause");
		home();
	}
	home();	
	}
	else{
		system("CLS");
		cout<<endl<<"Invalid login"<<endl;
		system("pause");
		home();
	}
}
void insert(){
    employee emp;
    system("CLS");
    color(14);
    cout<<"============ NEW EMPLOYEE ENTRY ============"<<endl<<endl;
    color(7);
    cout<<"Enter user name : ";
    cin>>emp.fname>>emp.lname;
    cout<<endl<<"Enter your password :";
    cin>>emp.password;
    cout<<endl<<"Enter your email :";
    cin>>emp.email;
    cout<<endl<<"Enter your department :";
    cin>>emp.department;
    cout<<endl<<"Enter your contact number :";
    cin>>emp.contact;
    cout<<endl<<"Enter your date of joining (dd mm yyyy) : ";
    cin>>emp.doj;
    saveemployee(emp);
    cout<<endl<<"Employee added successfully"<<endl;
    system("pause");
    home();
 }	
 void remove() 
 { 
    string fname, lname, pass;
    int i;
    system("CLS");
    color(14);
    cout<<"============ DELETE EMPLOYEE DATA ============"<<endl<<endl;
    color(7);
    cout<<"(Enter the details of that employee whose details has to be deleted) "<<endl<<endl;
    cout<<"Username : ";
    cin>>fname>>lname;
    cout<<endl<<"Password : ";
    cin>>pass;
    deleteemployee(fname, lname, pass);
    system("pause");
    home();
 }
 
 void update()
 {
 	cout<<endl<<"Update can be done by deleting and re-inserting record"<<endl;
 	system("pause");
 	home();
 }
 
void home()
{
	system("CLS");
	int z;
	color(12);
cout<<"  ******************************"<<endl;
cout<<"    Employee management system"<<endl;
cout<<"  ******************************"<<endl<<endl;
color(7);
cout<<"    * Press 1 to login "<<endl;
cout<<"    * Press 2 to update data"<<endl;
cout<<"    * Press 3 to insert data"<<endl;
cout<<"    * Press 4 to delete data"<<endl;
cout<<"    * Press 5 to see list of employees"<<endl;
cout<<"      Enter your choice : ";
cin>>z;
if (z==1)
login();
else if(z==2)
update();
else if(z==3)
insert();
else if(z==4)
remove();
else if(z==5)
name();
else{
	system("CLS");
    cout<<endl<<"Wrong input"<<endl;
    system("pause");
    home();}
return ; 
}
int main()
{
   ofstream fout;
   fout.open("employee.txt");
   fout.close();
   firstpage();
   home();
   return 0;
}   
