#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Student{
    string name, surname;
    int Birth_day, Birth_month, Birth_year;
};
int main(){
    int N = 0;
    cin>>N;
    vector<Student> students(N);
    for(auto& i: students)
        cin>>i.name>>i.surname>>i.Birth_day>>i.Birth_month>>i.Birth_year;

    cin>>N;
    {
        string command;
        int number;
        while(--N+1){
            cin>>command>>number;
            --number;
            if(number > students.size() || number < 0)
                cout<<"bad request"<<endl;
            else{
                if(command == "name")
                    cout<<students[number].name<<" "<<students[number].surname<<endl;
                else if(command == "date")
                    cout<<students[number].Birth_day<<"."<<students[number].Birth_month<<"."<<students[number].Birth_year<<endl;
                else
                    cout<<"bad request"<<endl;
            }
        }
    }


    return 0;
}

//514786216.950133076.166474413
//bad request
//616788147.705587264.244800286
//nyhFXEKa UrWtnwtYZXG
//40757237.518708565.414337061
//bad request

//514786216.950133076.166474413
//bad request
//616788147.705587264.244800286
//nyhFXEKa UrWtnwtYZXG
//40757237.518708565.414337061
//bad request