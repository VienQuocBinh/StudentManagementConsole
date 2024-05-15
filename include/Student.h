#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student
{
    private:
        int rollno, age;
        string name;

    public:
        Student();
        virtual ~Student();
        Student(int rollno, int age, string name){
            this->rollno = rollno;
            this->name = name;
            this->age = age;
        };

        void setRollNo(int rollno){
            this->rollno = rollno;
        }

        int getRollNo(){
            return rollno;
        }

        void setName(string name){
			this->name = name;
		}

		string getName(){
			return name;
		}

		void setAge(int age){
			this->age = age;
		}

		int getAge(){
			return age;
		}

};

#endif // STUDENT_H
