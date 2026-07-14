#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Patient
{
    int id;
    string name;
    int age;
    string gender;   
    string diagnosis; 
};

int binarySearch(Patient patients[], int size, int searchID){
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (patients[i].id > patients[j].id)
            {
                Patient temp = patients[i];
                patients[i] = patients[j];
                patients[j] = temp;
            }
        }
    }

    int left = 0;
    int right = size - 1;
    while (left <= right){
        int mid = (left + right) / 2;
        
        if (patients[mid].id == searchID)
            return mid;
        if (patients[mid].id < searchID)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main(){
    int SIZE = 100;
    Patient* patients = new Patient[SIZE];
    int count = 0;

    int choice = 0;
    while(choice != 6){
        cout << "\n Hospital Patient System\n";
        cout << "\n1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Search Patient \n";
        cout << "4. Update Patient \n";
        cout << "5. Save Patients \n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1){
            cout << "Enter Patient ID: ";
            cin >> patients[count].id;
            cin.ignore();
            cout << "Enter Patient Name: "<<endl;
            getline(cin,patients[count].name);
            cout << "Enter Patient Age: ";
            cin >> patients[count].age;
            cout << "Enter Patient Gender: ";
            cin >> patients[count].gender;
            cout << "Enter Patient Diagnosis: ";
            cin >> patients[count].diagnosis;
            count++;
        }else if(choice == 2){
            cout << "\nPatient Records\n";
            for(int i = 0; i < count; i++){
                cout << "ID: " << patients[i].id << endl;
                cout << "Name: " << patients[i].name << endl;
                cout << "Age: " << patients[i].age << endl;
                cout << "Gender: " << patients[i].gender << endl;
                cout << "Diagnosis: " << patients[i].diagnosis << endl;
            }
        }else if(choice == 3){
            int searchID;
            cout << "Enter Patient ID to search: ";
            cin >> searchID;            
            int result = binarySearch(patients, count, searchID);
            if (result != -1){
                cout << "\nPatient Found\n";
                cout << "ID: " << patients[result].id << endl;
                cout << "Name: " << patients[result].name << endl;
                cout << "Age: " << patients[result].age << endl;
                cout << "Diagnosis: " << patients[result].diagnosis << endl;
            }else{
                cout << "\nPatient not found.\n";
            }
        }else if(choice == 4){
            cout << "Enter Patient ID to update: ";
            int idUpdate;
            cin >> idUpdate;
            int result = binarySearch(patients, count, idUpdate);   
            cin.ignore(); 
            cout << "Enter new diagnosis: ";
            getline(cin, patients[result].diagnosis);

        }else if(choice == 5){
            ofstream outFile("patients.txt");
            if (!outFile){
                cout << "Error opening file for writing\n";
            }
            for(int i = 0; i < count; i++){
                outFile << patients[i].id << "," << patients[i].name 
                << "," << patients[i].age << "," << patients[i].gender << "," << patients[i].diagnosis << endl;
            }
            outFile.close();
            cout << "Records saved \n";


        }else if (choice == 6){
            cout << "Good Bye!";
        }
    }
    return 0;
}
