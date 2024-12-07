#include "FileManager/FileManager.cpp"
using namespace std;

int main()
{
    // FileManager::initialize();
    int choice;
    do
    {
        cout << "\nHospital Management System\n";
        cout << "1. Add Doctor\n";
        cout << "2. Delete Doctor\n";
        cout << "3. Update Doctor\n";
        cout << "4. Display All Doctors\n";
        cout << "5. Add Appointment\n";
        cout << "6. Delete Appointment\n";
        cout << "7. Update Appointment\n";
        cout << "8. Display All Appointments\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Add Doctor
            string id, name, address;
            cout << "Enter Doctor ID: ";
            cin >> id;
            cout << "Enter Doctor Name: ";
            cin.ignore(); // To ignore the leftover newline character from the previous input
            getline(cin, name);
            cout << "Enter Doctor Address: ";
            getline(cin, address);

            Doctor newDoctor(id, name, address);
            FileManager::addDoctors(newDoctor);
            break;
        }

        case 2:
        {
            // Delete Doctor
            string id;
            cout << "Enter Doctor ID to delete: ";
            cin >> id;
            FileManager::deleteDoctor(id);
            break;
        }

        case 3:
        {
            // Update Doctor
            string id, newName, newAddress;
            cout << "Enter Doctor ID to update: ";
            cin >> id;
            cout << "Enter new Name (leave empty if no change): ";
            cin.ignore(); // To ignore the leftover newline character
            getline(cin, newName);
            cout << "Enter new Address (leave empty if no change): ";
            getline(cin, newAddress);

            FileManager::updateDoctor(id, newName, newAddress);
            break;
        }

        case 4:
        {
            // Display All Doctors
            FileManager::displayDoctors();
            break;
        }

        case 5:
        {
            // Add Appointment
            string id, doctorID, date;
            cout << "Enter Appointment ID: ";
            cin >> id;
            cout << "Enter Doctor ID for the appointment: ";
            cin >> doctorID;
            cout << "Enter Appointment Date: ";
            cin.ignore();
            getline(cin, date);

            Appointment newAppointment(id, doctorID, date);
            FileManager::addAppointments(newAppointment);
            break;
        }

        case 6:
        {
            // Delete Appointment
            string id;
            cout << "Enter Appointment ID to delete: ";
            cin >> id;
            FileManager::deleteAppointment(id);
            break;
        }

        case 7:
        {
            // Update Appointment
            string id, newDoctorID, newDate;
            cout << "Enter Appointment ID to update: ";
            cin >> id;
            cout << "Enter new Doctor ID (leave empty if no change): ";
            cin.ignore(); // To ignore the leftover newline character
            getline(cin, newDoctorID);
            cout << "Enter new Date (leave empty if no change): ";
            getline(cin, newDate);

            FileManager::updateAppointment(id, newDoctorID, newDate);
            break;
        }

        case 8:
        {
            // Display All Appointments
            FileManager::displayAppointments();
            break;
        }

        case 9:
            // Exit
            cout << "Exiting system. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 9);

    return 0;
}
