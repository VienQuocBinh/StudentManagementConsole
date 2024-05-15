#include <iostream>
#include <Student.h>
#include <vector>

using namespace std;

void displayStudent(Student& s);
void displayAllStudent(vector<Student>& students);
void addNewStudent(vector<Student> &students);
void searchStudent(vector<Student>& students);
void deleteStudent(vector<Student>& students);
void updateStudent(vector<Student>& students);

int main()
{
    Student s = Student(1,20,"Binh");
    Student s2 = Student(2,22,"Ali");
    vector<Student> students = {s, s2};

    char choice;

    do{
        system("cls");

        cout<<"\n\t\t--------------------------------";

		cout<<"\n\t\t*** Student Management System ***";

		cout<<"\n\t\t--------------------------------";

		cout<<"\n\t\t 1. Add New Student"<<endl;

		cout<<"\t\t 2. Display All Student "<<endl;

		cout<<"\t\t 3. Search Student"<<endl;

		cout<<"\t\t 4. Update Student"<<endl;

		cout<<"\t\t 5. Delete Student "<<endl;

		cout<<"\t\t 6. Exit"<<endl;

		cout<<"\t\t Enter Your Choice : ";

		int opt;
		cin >> opt;

		switch(opt){
            case 1:
                addNewStudent(students);
                break;
            case 2:
                displayAllStudent(students);
                break;
            case 3:
                searchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                exit(1);
            default:
                cout << "\t\tInvalid Number" << endl;
		}

		cout << "\t\tDo you want to continue? [Y/N]";
		cin >> choice;
    } while(choice == 'y' || choice == 'Y');

//    Student* s3 = new Student(1,2,"asf");
//    delete s3;

    return 0;
}

void displayStudent(Student& s){

			cout << "Roll No: " << s.getRollNo() << endl;

			cout << "Name: " << s.getName() << endl;

			cout << "Age: " << s.getAge() << endl;

}

//create function to show all list of  student
void displayAllStudent(vector<Student>& students){

	if(students.empty()){
		cout<<"\t\t No Student Found "<<endl;
		return;
	}

	for(int i = 0; i < students.size(); i++){
		displayStudent(students[i]);
		cout << endl;
	}
}


//create function to search student in list
void searchStudent(vector<Student>& students){
	int rollno;

	cout<<"\t\tEnter Rollno: ";
	cin>>rollno;

	for(int i = 0; i<students.size();i++){
		if(students[i].getRollNo() == rollno){
			cout<<"\t\t--------Student Found ------------"<<endl;
			displayStudent(students[i]);
			return;
		}
	}
	cout<<"\t\t--------Student Roll no "<< rollno <<" Not Found ------------"<<endl;
}

//create function to add new student
void addNewStudent(vector<Student>& students){
	int rollno,age;
	string name;

	cout << "Enter Rollno: ";
	cin >> rollno;

	//check if student already exit
	for(int i = 0; i < students.size();i++){
		if(students[i].getRollNo() == rollno){
			cout << "\t\tStudent Already Exit" << endl;
			return;
		}

	}

	cout<<"Enter Name: ";
	cin>>name;

	cout<<"Enter Age: ";
	cin>>age;

	Student newStudent(rollno,age,name);
	students.push_back(newStudent);
}

//create function to delete student in list
void deleteStudent(vector<Student>& students){
	string name;
	cout<<"\t\tEnter Name to Delete :";
	cin.ignore();

	getline(cin,name);

	for(int i = 0; i<students.size();i++){
		if(students[i].getName() == name){
            cout << "\t\tDo you want to this student? [Y/N]";
            char choice;
            cin >> choice;
            if(choice == 'Y' || choice == 'y'){

                students.erase(students.begin() + i);
                cout<<"\t\tStudent Remove Successfully"<<endl;
            }
			return;
		}
	}
    cout<<"\t\t--------Student name "<< name <<" Not Found ------------"<<endl;
}

//Create function to update Student record
void updateStudent(vector<Student>& students){
	string sname;
	bool found = false;

	int choice;

	cout<<"\t\tEnter Name to Update Record: ";

	cin >> sname;
	for(int i = 0; i<students.size();i++){
		if(students[i].getName()==sname){
			found = true;

			cout<<"\t\t---Student Found -----"<<endl;

			cout<<"\t\t 1. Update Rollno "<<endl;

			cout<<"\t\t 2. Update Name "<<endl;

			cout<<"\t\t 3. Update Age "<<endl;

			cout<<"\t\tEnter Your Choice :";

			cin>>choice;

			switch(choice){
				case 1:{
					int rno;

					cout<<"\t\tEnter New Rollno :";
					cin>>rno;

					students[i].setRollNo(rno);
					break;
				}
				case 2:{
					string name;

					cout<<"\t\tEnter New Name :";
					cin.ignore();
					getline(cin,name);
					students[i].setName(name);

					break;
				}

				case 3:{
					int age;
					cout<<"\t\tEnter New Age :";
					cin>>age;

					students[i].setAge(age);
					break;
				}

				default:
				cout<<"\t\tInvalid Number"<<endl;
			}
		}

		if(!found){
			cout<<"\t\tRecord Not Found"<<endl;
			return;
		}
	}
}


