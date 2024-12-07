#include "FileManager.h"
int main()
{
    FileManager::initialize();
    Doctor doctor("1", "Youssef", "Riyadh");
    Doctor doctor2("2", "Youssef", "Riyadh");
    Doctor doctor3("3", "ahmed", "Riyadh");
    Doctor doctor4("4", "ahmed", "Riyadh");
    Doctor doctor5("5", "khalid", "Riyadh");

    Appointment appointment("1", "1", "2023-01-01");
    Appointment appointment2("2", "1", "2023-01-01");
    Appointment appointment3("3", "2", "2023-01-01");
    Appointment appointment4("4", "2", "2023-01-01");
    Appointment appointment5("5", "3", "2023-01-01");
    Appointment appointment6("6", "3", "2023-01-01");
    Appointment appointment7("7", "4", "2023-01-01");
    Appointment appointment8("8", "4", "2023-01-01");
    Appointment appointment9("9", "5", "2023-01-01");
    Appointment appointment10("10", "5", "2023-01-01");

    //    FileManager::addDoctors(doctor);
    //    FileManager::addDoctors(doctor2);
    //    FileManager::addDoctors(doctor3);
    //    FileManager::addDoctors(doctor4);
    //    FileManager::addDoctors(doctor5);
    //
    //    FileManager::addAppointments(appointment);
    //    FileManager::addAppointments(appointment2);
    //    FileManager::addAppointments(appointment3);
    //    FileManager::addAppointments(appointment4);
    //    FileManager::addAppointments(appointment5);
    //    FileManager::addAppointments(appointment6);
    //    FileManager::addAppointments(appointment7);
    //    FileManager::addAppointments(appointment8);
    //    FileManager::addAppointments(appointment9);
    //    FileManager::addAppointments(appointment10);
    //    FileManager::updateDoctor("4" , "khalid" , "Riyadh");
    //    FileManager::deleteAppointment("1");
    //    FileManager::deleteDoctor("1");
    //    FileManager::addDoctors(doctor);
    //    FileManager::deleteDoctor("2");
    FileManager::displayDoctors();
    cout << "\n\n";
    FileManager::displayAppointments();
}
