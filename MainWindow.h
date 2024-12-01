// mainwindow.h
#ifndef FLIGHTBOOKINGSYSTEM_MAINWINDOW_H
#define FLIGHTBOOKINGSYSTEM_MAINWINDOW_H
using namespace std;
#include <QMainWindow>
#include <QPushButton>
#include "FirstClass.h"//includes firstclass to use it in mainwindow
#include "BusinessClass.h"
#include "EconomyClass.h"
#include <QLabel>
#include <QCalendarWidget>
#include <QVBoxLayout>
#include <QComboBox>
#include <vector>
class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void FlightBookingTitle();
    void onbutton1Clicked();
    void onNoButtonClicked();
    void onYesButtonClicked();
    void BookingCalendar();
    void updatePrice();
    void classAmenities();
    void onFirstClassButtonClicked();
    void onBusinessClassButtonClicked();
    void onEconomyClassButtonClicked();
    void onContinue2Clicked();
    void onIncreaseSeats();
    void onDecreaseSeats();
    void onContinue3Clicked();
    void personInfo();
    void chooseSeat();
    void chooseSeat2();
    void confirmation();
    void billing();
    void booked();
public:
    QPushButton *yesButton;
    QPushButton *noButton;
    QPushButton *firstClassButton;
    QPushButton *businessClassButton;
    QPushButton *economyClassButton;
    QPushButton *button1;
    QCalendarWidget *calendar;
    QLabel *priceLabel;
    QVBoxLayout *dateLayout;
    QLabel *dateLabel;
    int a = 0;
    int openSeats;


private:
    QComboBox *departureComboBox;
    QComboBox *destinationComboBox;
    QLabel *selectedDepartureLabel;
    QLabel *selectedDestinationLabel;
    QLabel *confirmationLabel;
    QString selectedDeparture;
    QString selectedDestination;

    FirstClass *f1;
    BusinessClass *b1;
    EconomyClass *e1;
    float price;
    //a map that stores and retrieves price for a specific date
    QMap <QDate, float> dateAndPriceMap;
    QLabel *seatCountLabel;
    int seatCount = 1;
    QPushButton *increaseButton;
    QPushButton *decreaseButton;

    vector<QString> firstName;
    vector<QString> lastName;
    vector<QString> birthDay;
    vector<QString> birthMonth;
    vector<QString> birthYear;
    vector<QString> mealType;
    vector<QString> vectorAllergy;

    int personEntered = 0;
    QLabel *infoLabel;
    QLineEdit *firstNameInput;
    QLineEdit *lastNameInput;
    QLineEdit *specificAllergies;
    QComboBox *dayComboBox;
    QComboBox *monthComboBox;
    QComboBox *yearComboBox;
    QComboBox *mealComboBox;
    QString firstNames;
    QString lastNames;
    QString day;
    QString month;
    QString year;
    QString meal;
    QString allergy;

    int closedSeats;
    int rows;
    int columns;
    int b = 0;
    int currentPassengerIndex = 0;
    QPushButton *yesExtra;
    QPushButton *noExtra;
    vector<QString>seats;
    QVector<QString>seatIndexes;
    vector<QString>economySeats;

    float totalMoney;

    QString email1;
};

#endif // MAINWINDOW_H
