//The Jadwal`s
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip> // Untuk format output
#include <ctime>   // Untuk mendapatkan jumlah hari dalam bulan tertentu
using namespace std;

// Struktur untuk merepresentasikan sebuah acara
struct Event {
    string name;
    string date;
    string time;
    Event* next;

    // Konstruktor
    Event(string n, string d, string t) : name(n), date(d), time(t), next(nullptr) {}
};

class ScheduleManager {
private:
    Event* head; // Pointer ke elemen pertama dalam linked list

public:
    // Konstruktor
    ScheduleManager() : head(nullptr) {}

    // Method untuk menambahkan acara baru ke dalam jadwal
    void addEvent(string name, string date, string time) {
        Event* newEvent = new Event(name, date, time);
        if (head == nullptr) {
            head = newEvent;
        } else {
            Event* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newEvent;
        }
        cout << "Acara \"" << name << "\" berhasil ditambahkan ke dalam jadwal." << endl;
    }

    // Method untuk menampilkan semua acara dalam jadwal
    void displaySchedule() {
        if (head == nullptr) {
            cout << "Jadwal kosong." << endl;
        } else {
            Event* temp = head;
            cout << "Jadwal Anda:" << endl;
            while (temp != nullptr) {
                cout << "Nama Acara: " << temp->name << endl;
                cout << "Tanggal: " << temp->date << endl;
                cout << "Waktu: " << temp->time << endl << endl;
                temp = temp->next;
            }
        }
    }

    // Method untuk menampilkan acara dalam bentuk kalender dan kalender kosong untuk bulan dan tahun tertentu
    void displayCalendar(int month, int year) {
        // Map untuk menyimpan acara berdasarkan tanggal
        map<string, vector<Event*>> calendar;
        Event* temp = head;
        while (temp != nullptr) {
            calendar[temp->date].push_back(temp);
            temp = temp->next;
        }

        static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        // Cek apakah tahun kabisat
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        int days = daysInMonth[month - 1];
        if (isLeapYear && month == 2) {
            days = 29;
        }

        // Menentukan hari pertama dalam bulan tersebut
        tm time_in = { 0, 0, 0, 1, month - 1, year - 1900 };
        time_t firstDay = mktime(&time_in);
        tm* time_out = localtime(&firstDay);
        int startDay = time_out->tm_wday; // 0 = Minggu, 1 = Senin, ..., 6 = Sabtu

        cout << "==========================\n";
        cout << "Kalender Bulan " << month << " Tahun " << year << ":" << endl;
        cout << "Su Mo Tu We Th Fr Sa" << endl;

        // Cetak hari kosong sebelum tanggal 1
        for (int i = 0; i < startDay; ++i) {
            cout << "   ";
        }

        // Cetak tanggal-tanggal dalam bulan dan acara yang ada
        for (int day = 1; day <= days; ++day) {
            cout << setw(2) << day << " ";
            if ((day + startDay) % 7 == 0) {
                cout << endl;
            }
        }
        cout << endl << "==========================\n";

        // Menampilkan acara pada bulan dan tahun yang ditentukan
        cout << "Kalender Jadwal Anda:" << endl;
        for (const auto& entry : calendar) {
            string date = entry.first;
            int eventYear, eventMonth, eventDay;
            sscanf(date.c_str(), "%d-%d-%d", &eventYear, &eventMonth, &eventDay);
            if (eventYear == year && eventMonth == month) {
                cout << date << ":" << endl; // Tanggal
                for (const auto& event : entry.second) {
                    cout << "  " << setw(5) << event->time << " - " << event->name << endl;
                }
            }
        }
        cout << endl;
    }

    // Method untuk menghapus acara berdasarkan nama
    void deleteEvent(string name) {
        if (head == nullptr) {
            cout << "Jadwal kosong. Tidak ada acara yang bisa dihapus." << endl;
            return;
        }

        if (head->name == name) {
            Event* temp = head;
            head = head->next;
            delete temp;
            cout << "Acara \"" << name << "\" berhasil dihapus dari jadwal." << endl;
            return;
        }

        Event* current = head;
        while (current->next != nullptr && current->next->name != name) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "Acara dengan nama \"" << name << "\" tidak ditemukan." << endl;
        } else {
            Event* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Acara \"" << name << "\" berhasil dihapus dari jadwal." << endl;
        }
    }

    // Method untuk menghapus semua acara dalam jadwal
    void deleteAllEvents() {
        while (head != nullptr) {
            Event* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Semua acara berhasil dihapus dari jadwal." << endl;
    }

    // Destructor untuk membersihkan memori
    ~ScheduleManager() {
        deleteAllEvents();
    }
};

bool isValidDate(int year, int month, int day) {
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month < 1 || month > 12) {
        return false;
    }
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int days = daysInMonth[month - 1];
    if (isLeapYear && month == 2) {
        days = 29;
    }
    return day >= 1 && day <= days;
}

bool isValidTime(const string& time) {
    int hour, minute;
    if (sscanf(time.c_str(), "%d:%d", &hour, &minute) != 2) {
        return false;
    }
    return hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59;
}

int main() {
    ScheduleManager schedule;
    string name, date, time;
    char choice;
    int month, year, day;

    do {
        cout << "Menu:" << endl;
        cout << "1. Tambah Acara" << endl;
        cout << "2. Tampilkan Jadwal" << endl;
        cout << "3. Tampilkan Kalender" << endl;
        cout << "4. Hapus Acara" << endl;
        cout << "5. Hapus Semua Acara" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih opsi (1-6): ";
        cin >> choice;
        cin.ignore(); // Mengabaikan karakter newline yang tersisa di buffer

        switch (choice) {
            case '1':
                cout << "Masukkan nama acara: ";
                getline(cin, name);
                do {
                    cout << "Masukkan tanggal acara (YYYY-MM-DD): ";
                    getline(cin, date);
                    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
                    if (!isValidDate(year, month, day)) {
                        cout << "Tanggal tidak valid. Silakan coba lagi." << endl;
                    }
                } while (!isValidDate(year, month, day));
                do {
                    cout << "Masukkan waktu acara (HH:MM): ";
                    getline(cin, time);
                    if (!isValidTime(time)) {
                        cout << "Waktu tidak valid. Silakan coba lagi." << endl;
                    }
                } while (!isValidTime(time));
                schedule.addEvent(name, date, time);
                break;
            case '2':
                schedule.displaySchedule();
                break;
            case '3':
                do {
                    cout << "Masukkan bulan (1-12): ";
                    cin >> month;
                    cout << "Masukkan tahun: ";
                    cin >> year;
                    if (month < 1 || month > 12) {
                        cout << "Bulan tidak valid. Silakan coba lagi." << endl;
                    }
                } while (month < 1 || month > 12);
                schedule.displayCalendar(month, year);
                break;
            case '4':
                cout << "Masukkan nama acara yang akan dihapus: ";
                getline(cin, name);
                schedule.deleteEvent(name);
                break;
            case '5':
                schedule.deleteAllEvents();
                break;
            case '6':
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Opsi tidak valid. Silakan pilih antara 1-6." << endl;
        }
    } while (choice != '6');

    return 0;
}