#include "MainWindow.h"
using namespace std;
#include <QGuiApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScreen>
#include <QPushButton>
#include <QString>
#include <QComboBox>
#include <QMessageBox>
#include <QCalendarWidget>
#include <QListWidget>
#include <QStringList>
#include <QLineEdit>
#include <QGridLayout>
#include <QScrollArea>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), f1(new FirstClass()), b1(new BusinessClass()), e1(new EconomyClass()) //instantiate first, business, and economy class here
{
    //assigns values to buttons created in mainWindow.h
    button1 = new QPushButton("Next",this);
    button1->setFixedSize(100,50);
    button1->setFont(QFont("Times", 20));

    yesButton = new QPushButton("Yes", this);
    noButton = new QPushButton("No", this);

    firstClassButton = new QPushButton("First Class", this);
    businessClassButton = new QPushButton("Business Class", this);
    economyClassButton = new QPushButton("Economy Class", this);
    QSize buttonSize(200,80);
    firstClassButton->setFixedSize(buttonSize);
    businessClassButton->setFixedSize(buttonSize);
    economyClassButton->setFixedSize(buttonSize);

    button1->hide();
    yesButton->hide();
    noButton->hide();
    firstClassButton->hide();
    businessClassButton->hide();
    economyClassButton->hide();

    connect(button1, &QPushButton::clicked, this, &MainWindow::onbutton1Clicked);
    connect(yesButton, &QPushButton::clicked, this, &MainWindow::onYesButtonClicked);
    connect(noButton, &QPushButton::clicked, this, &MainWindow::onNoButtonClicked);
    connect(firstClassButton, &QPushButton::clicked, this, &MainWindow::onFirstClassButtonClicked);
    connect(businessClassButton, &QPushButton::clicked, this, &MainWindow::onBusinessClassButtonClicked);
    connect(economyClassButton, &QPushButton::clicked, this, &MainWindow::onEconomyClassButtonClicked);
    FlightBookingTitle();
}

void MainWindow::FlightBookingTitle()
{
    //creates the welcome page
    setWindowTitle("Flight Booking System");
    resize(900, 600);
    QLabel *introText = new QLabel("Welcome to Flight Booking System");
    introText->setFont(QFont("Times", 30));
    introText->setStyleSheet("color:white");
    introText->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addStretch();
    layout->addWidget(introText);
    layout->addStretch();
    layout->addWidget(button1, 0, Qt::AlignRight | Qt::AlignBottom);
    button1->show();

    // Create a central widget and sets the welcome layout
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

};

void MainWindow::onbutton1Clicked()
{
    //hides the next button
    button1->hide();

    QLabel *departure = new QLabel("Select a departure:", this);
    departure->setFont(QFont("Arial", 16));
    departureComboBox = new QComboBox(this);

    QString departureArray[] = {"New York", "Los Angeles", "Chicago", "Miami", "Dallas", "Houston", "Phoenix", "Atlanta", "Las Vegas", "San Francisco", "Seattle"};
    for(int i = 0; i < 11; i++)
    {
        //add departure places from the array to the dropdown
        departureComboBox->addItem(departureArray[i]);
    }

    // Creates a label to show the selected departure
    selectedDepartureLabel = new QLabel(this);

    QLabel *destination = new QLabel("Select a destination:", this);
    destination->setFont(QFont("Arial", 16));

    destinationComboBox = new QComboBox(this);

    QString destinationArray[] = {"New York", "Los Angeles", "Chicago", "Miami", "Dallas", "Houston", "Phoenix", "Atlanta", "Las Vegas", "San Francisco", "Seattle"};
    for(int i = 0; i < 11; i++)
    {
        //add destination places from the array to the dropdown
        destinationComboBox->addItem(destinationArray[i]);
    }

    // Creates a label to show the selected destination
    selectedDestinationLabel = new QLabel(this);
    confirmationLabel = new QLabel(this);


    // Create a "Submit" button
    QPushButton *submitButton1 = new QPushButton("Submit", this);

    // Create a layout to organize the new widgets
    QVBoxLayout *DLayout = new QVBoxLayout;
    DLayout->addWidget(departure);
    DLayout->addWidget(departureComboBox);

    DLayout->addWidget(destination);
    DLayout->addWidget(destinationComboBox);
    DLayout->addSpacing(20);
    DLayout->addWidget(submitButton1);
    DLayout->addWidget(selectedDepartureLabel);
    DLayout->addWidget(selectedDestinationLabel);
    DLayout->addWidget(confirmationLabel);

    DLayout->addWidget(yesButton);
    DLayout->addWidget(noButton);

    // Removes old widgets and creates a new one
    QWidget *mainWidget2 = new QWidget();
    mainWidget2->setLayout(DLayout);
    setCentralWidget(mainWidget2);

    //what happens when submitButton is clicked
    connect(submitButton1, &QPushButton::clicked, [this]
    {
        //assigns values to selectedDeparture and selectedDestination from the comboBox
        selectedDeparture = departureComboBox->currentText();

        selectedDestination = destinationComboBox->currentText();
        if(selectedDeparture==selectedDestination)
        {
            //warning message if selectedDeparture and selectedDestination are the same
            QMessageBox::warning(this, "Invalid Selection", "Departure and Destination cannot be the same");
            return;
        }
        else
        {
            //asks to confirm selection
            selectedDepartureLabel->setText("Your selected departure city: " + selectedDeparture);
            selectedDestinationLabel->setText("Your selected destination city: " + selectedDestination);
            confirmationLabel->setText("Do you confirm your selection? ");
            yesButton->show();
            noButton->show();

        }
    });
}

void MainWindow::onNoButtonClicked()
{
    //brings you back to the blank destination and departure widget and asks you to reinput your destination and departure place
    yesButton->hide();
    noButton->hide();
    QMessageBox::warning(this, "Invalid Selection", "Please re-enter your selection. ");
    if (departureComboBox) {
        departureComboBox->setCurrentIndex(0); // Reset to the first item
    }

    if (destinationComboBox) {
        destinationComboBox->setCurrentIndex(0); // Reset to the first item
    }

    // Clear labels
    if (selectedDepartureLabel) {
        selectedDepartureLabel->clear();
    }

    if (selectedDestinationLabel) {
        selectedDestinationLabel->clear();
    }

    if (confirmationLabel) {
        confirmationLabel->clear();
    }
}
void MainWindow::onYesButtonClicked() {
    //a new layout and three buttons are created asking you to select you cabin of preference
    QHBoxLayout *cabinClassLayout = new QHBoxLayout;
    cabinClassLayout->addWidget(firstClassButton);
    cabinClassLayout->addWidget(businessClassButton);
    cabinClassLayout->addWidget(economyClassButton);
    firstClassButton->show();
    businessClassButton->show();
    economyClassButton->show();

    QLabel *cabinPreference = new QLabel("Please choose your cabin of preference", this);
    cabinPreference->setFont(QFont("Times", 30));
    cabinPreference->setAlignment(Qt::AlignCenter);

    QVBoxLayout *mainCabinClass = new QVBoxLayout;

    mainCabinClass->addStretch(1);
    mainCabinClass->addWidget(cabinPreference);
    mainCabinClass->addSpacing(40);
    mainCabinClass->addLayout(cabinClassLayout);
    mainCabinClass->addStretch(1);

    QWidget *mainWidget3 = new QWidget(this);
    mainWidget3->setLayout(mainCabinClass);
    setCentralWidget(mainWidget3);

}
void MainWindow::onFirstClassButtonClicked()
{
    //this is what happens when first Class button is clicked
    a = 1;
    classAmenities();
}

void MainWindow::onBusinessClassButtonClicked()
{
    //this is what happens when business Class button is clicked
    a = 2;
    classAmenities();
}
void MainWindow::onEconomyClassButtonClicked()
{
    //this is what happens when economy Class button is created
    a = 3;
    classAmenities();
}

void MainWindow::classAmenities()
{
    //depending on what cabin class button you clicked, you are shown a list of amenities offered for that particular class
    QStringList amenities;
    QLabel *amenitiesTitle = new QLabel(this);
    if(a ==1)
    {
        //getClassAmenities is a abstract virtual function in BookingClass.h and each derived class overrides this virtual function
        //f1 (firstClass classes object) accesses the getClassAmenities in firstClass.cpp
        amenities = f1->getClassAmenities();
        amenitiesTitle->setText("First Class Amenities:");

    }
    if(a ==2)
    {
        //getClassAmenities is a abstract virtual function in BookingClass.h and each derived class overrides this virtual function
        //b1 (BusinessClass classes object) accesses the getClassAmenities in BusinessClass.cpp
        amenities = b1->getClassAmenities();
        amenitiesTitle->setText("Business Class Amenities:");

    }
    if(a ==3)
    {
        //getClassAmenities is a abstract virtual function in BookingClass.h and each derived class overrides this virtual function
        //e1 (economyClass classes object) accesses the getClassAmenities in economyClass.cpp
        amenities = e1->getClassAmenities();
        amenitiesTitle->setText("Economy Class Amenities:");

    }

    //makes sure everything looks visually appealing
    amenitiesTitle->setFont(QFont("Arial", 20));
    amenitiesTitle->setAlignment(Qt::AlignCenter);

    QListWidget *amenitiesList = new QListWidget;
    amenitiesList->addItems(amenities);
    amenitiesList->setFont(QFont("Arial", 16));
    //creates a continue button and connects it to another function when clicked
    QPushButton *continueButton = new QPushButton("Continue");
    connect(continueButton, &QPushButton::clicked, this, &MainWindow::BookingCalendar);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(amenitiesTitle);
    layout->addWidget(amenitiesList);
    layout->addWidget(continueButton);

    QWidget *amenitiesWidget = new QWidget(this);
    amenitiesWidget->setLayout(layout);
    setCentralWidget(amenitiesWidget);
}

void MainWindow::updatePrice()
{

    QDate selectedDate = calendar->selectedDate();
    //displays price if it is already generated for the date which ensures that there is not a different price everytime you click a certain date twice
    if (dateAndPriceMap.contains(selectedDate)) {
        price = dateAndPriceMap[selectedDate];
        priceLabel->setText(QString("Price: $%1").arg(price, 0, 'f', 2)); // Use the stored price
    }
    else
    {
        //generates a random price depending on which class you are flying
        if(a == 1)
        {
            price = f1->randomPrice();
            price = price * 3.75;
        }
        if(a == 2)
        {
            price = b1->randomPrice();
            price = price * 2.50;
        }
        if(a== 3)
        {
            price = e1->randomPrice();
        }
        // Store the price for the selected date
        dateAndPriceMap[selectedDate] = price;
        priceLabel->setText(QString("Price: $%1").arg(price, 0, 'f', 2)); // Show the new price

    }
}

void MainWindow::BookingCalendar()
{
    //creates a label on top of the calendar
    if (a==1)
    {
        dateLabel = new QLabel("Select your first class flight date:", this);

    }
    if (a==2)
    {
        dateLabel = new QLabel("Select your business class flight date:", this);
    }
    if (a==3)
    {
        dateLabel = new QLabel("Select your economy class flight date:", this);
    }
    dateLabel->setFont(QFont("Arial", 16));
    QWidget *dateWidget = new QWidget(this);
    dateLayout = new QVBoxLayout(dateWidget);

// Add a label
    dateLayout->addWidget(dateLabel);

// Add a calendar widget
    calendar = new QCalendarWidget(this);
    //makes sure that it doesn't let you select date from the past
    calendar->setMinimumDate(QDate::currentDate());
    //set a maximum selection date
    calendar->setMaximumDate(QDate(2025,01,01));
    dateLayout->addWidget(calendar);
    QWidget *mainWidget3 = new QWidget();
    mainWidget3->setLayout(dateLayout);
    setCentralWidget(mainWidget3);
    //assigns selectedDate a value based on what date you clicked on the calendar
    QDate selectedDate = calendar->selectedDate();
    priceLabel = new QLabel(QString("Price: $0.00"),this);
    priceLabel->setFont(QFont("Arial", 16));
    priceLabel->setAlignment(Qt::AlignCenter);
    dateLayout->addWidget(priceLabel);

    QPushButton *continue2 = new QPushButton("continue");
    dateLayout->addWidget(continue2);
    //if selection is changed it takes you to the updatePrice function to either store a new price value or display price that was already assigned to the date
    connect(calendar, &QCalendarWidget::selectionChanged, this, &MainWindow::updatePrice);
    updatePrice();
    connect(continue2, &QPushButton::clicked, this, &MainWindow::onContinue2Clicked);
}

void MainWindow::onContinue2Clicked()
{
    //object that points to an overriden function in its respective cpp file to generate a random number for how many seats are available
    if(a == 1)
    {
         openSeats = f1->seatsAvailable();

    }
    if(a == 2)
    {
        openSeats = b1->seatsAvailable();
    }
    if(a == 3)
    {
        openSeats = e1->seatsAvailable();
    }

    //creates a + and - button with a number in the middle to enter how many people are flying
    QLabel *seatInformation = new QLabel("Please enter the number of people flying. ", this);
    seatInformation->setFont(QFont("Arial", 20));
    seatInformation->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout1 = new QVBoxLayout;
    layout1->addWidget(seatInformation);

    seatCountLabel = new QLabel(QString::number(seatCount), this);
    seatCountLabel->setFont(QFont("Arial", 25, QFont::Bold));
    seatCountLabel->setAlignment(Qt::AlignCenter);
// Create the "+" and "-" buttons
    increaseButton = new QPushButton("+", this);
    decreaseButton = new QPushButton("-", this);
    QPushButton *continue3 = new QPushButton("continue", this);

    // Set button sizes and fonts
    increaseButton->setFixedSize(60, 60);
    decreaseButton->setFixedSize(60, 60);
    increaseButton->setFont(QFont("Arial", 24));
    decreaseButton->setFont(QFont("Arial", 24));

    increaseButton->setStyleSheet("background-color: #4CAF50; color: white; border-radius: 30px;");
    decreaseButton->setStyleSheet("background-color: #F44336; color: white; border-radius: 30px;");

    // Connect buttons to their respective slots
    connect(increaseButton, &QPushButton::clicked, this, &MainWindow::onIncreaseSeats);
    connect(decreaseButton, &QPushButton::clicked, this, &MainWindow::onDecreaseSeats);
    connect(continue3, &QPushButton::clicked, this, &MainWindow::onContinue3Clicked);

    // Layout to organize buttons and seat count label
    QHBoxLayout *layout2 = new QHBoxLayout;
    layout2->addWidget(decreaseButton);
    layout2->addWidget(seatCountLabel);
    layout2->addWidget(increaseButton);

    layout1->addLayout(layout2);
    layout1->addWidget(continue3);
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout1);
    setCentralWidget(centralWidget);
}

void MainWindow::onIncreaseSeats()
{
    if(seatCount < openSeats)
       {
           seatCount++;  // Increase seat count by 1
           seatCountLabel->setText(QString::number(seatCount));  // Update the display
       }
    //gives you a warning if you enter more seats than available seats on the plane
    if(seatCount >= openSeats)
       {
           QMessageBox::warning(this, "Error", "There are no more seats available. ");
       }
}

void MainWindow::onDecreaseSeats()
{
    if (seatCount > 0) {  // Prevent going below 0
        seatCount--;  // Decrease seat count by 1
        seatCountLabel->setText(QString::number(seatCount));  // Update the display
    }
}

void MainWindow::onContinue3Clicked()
{
    //takes you to this function when the button is clicked and this function takes you to personInfo() function
    personInfo();
}

void MainWindow::personInfo()
{

    infoLabel = new QLabel("Enter information as provided in the government ID", this);
    infoLabel->setFont(QFont("Arial", 16));
    infoLabel->setAlignment(Qt::AlignCenter);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(infoLabel);
    //asks you to enter details for each person such as name, birthdate, etc
    QHBoxLayout *person = new QHBoxLayout;
    QLabel *personLabel = new QLabel(QString("Enter details for Passenger %1 of %2 ").arg(personEntered + 1).arg(seatCount), this);
    personLabel->setAlignment(Qt::AlignLeft);
    layout->addWidget(personLabel);

    QHBoxLayout *fname = new QHBoxLayout;
    QLabel *firstNameLabel = new QLabel("First Name: ");
    firstNameInput = new QLineEdit(this);
    fname->addWidget(firstNameLabel);
    fname->addWidget(firstNameInput);
    layout->addLayout(fname);

    QHBoxLayout *lname = new QHBoxLayout;
    QLabel *lastNameLabel = new QLabel("Last Name: ");
    lastNameInput = new QLineEdit(this);
    lname->addWidget(lastNameLabel);
    lname->addWidget(lastNameInput);
    layout->addLayout(lname);

    QHBoxLayout *dob = new QHBoxLayout;
    QLabel *dobLabel = new QLabel("Date of Birth: ");
    dayComboBox = new QComboBox(this);
    monthComboBox = new QComboBox(this);
    yearComboBox = new QComboBox(this);
    for(int x = 0; x <= 31; x++)
    {
        dayComboBox->addItem(QString::number(x));
    }
    for(int y = 0; y <= 12; y++)
    {
        monthComboBox->addItem(QString::number(y));
    }
    for(int z = 1910; z <= 2024; z++)
    {
        yearComboBox->addItem(QString::number(z));
    }

    dob->addWidget(dobLabel);
    dob->addWidget(monthComboBox);
    dob->addWidget(dayComboBox);
    dob->addWidget(yearComboBox);
    layout->addLayout(dob);


    QHBoxLayout *mealPreference = new QHBoxLayout;
    QLabel *mealLabel = new QLabel("Meal Restrictions: ");
    mealComboBox = new QComboBox(this);
    mealComboBox->addItems({ "Select" , "No Dietary Restrictions","Vegetarian", "Vegan", "Gluten Free"});
    mealPreference->addWidget(mealLabel);
    mealPreference->addWidget(mealComboBox);
    layout->addLayout(mealPreference);
    QHBoxLayout *allergyLayout = new QHBoxLayout;

    QLabel *allergies = new QLabel("Please list any specific allergies: ");
    specificAllergies = new QLineEdit(this);
    allergyLayout->addWidget(allergies);
    allergyLayout->addWidget(specificAllergies);
    layout->addLayout(allergyLayout);


    QPushButton *next = new QPushButton(personEntered + 1 < seatCount ?  "Next" : "Finish", this);
    layout->addWidget(next);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(next, &QPushButton::clicked, [this, next] ()
    {
        firstNames = firstNameInput->text();
        lastNames = lastNameInput->text();
        day = dayComboBox->currentText();
        month = monthComboBox->currentText();
        year = yearComboBox->currentText();
        meal = mealComboBox->currentText();
        allergy = specificAllergies->text();
        //ensures that all items are filled out
        if(firstNameInput->text().isEmpty() || lastNameInput->text().isEmpty() || day == "0" || month == "0" || year == "1910" || meal == "Select" || specificAllergies->text().isEmpty())
        {
            QMessageBox::warning(this, "Validation Error", "All fields must be filled.");
            return;
        }
        else
        {
            //pushes the items into a vector so they can be accessed later during the confirmation
            firstName.push_back(firstNames);
            lastName.push_back(lastNames);
            birthDay.push_back(day);
            birthMonth.push_back(month);
            birthYear.push_back(year);
            mealType.push_back(meal);
            vectorAllergy.push_back(allergy);

            personEntered++;
            if(personEntered < seatCount)
            {
                personInfo();
            }
            else
            {
                chooseSeat();
            }
        }
    });

}

void MainWindow::chooseSeat()
{
    //assigns number of row and columns to each class depending on which one you clicked
    if(a == 1)
    {
        rows = 7;  // Number of rows (example)
        columns = 2;  // Number of seats per row (A, B, C, D)
        closedSeats = 14 - openSeats;
    }
    if(a == 2)
    {
        rows = 8;
        columns = 4;
        closedSeats = 32 - openSeats;
    }
    if(a == 3)
    {
        rows = 30;
        columns = 6;
        closedSeats = 180 - openSeats;
    }

    //entered all the seat numbers into a vector
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            QString seatName = QString("%1%2").arg(r + 1).arg(QChar('A' + c));
            seatIndexes.push_back(seatName);
        }
    }

    //takes you to another function if you choose firstClass or businessClass
    if(a == 1 || a == 2)
    {
        chooseSeat2();
    }

    //if you choose economyClass it gives you the option to randomly be assigned a seat or to pay an extra 10 dollars for each person to choose a seat
    if (a == 3)
    {
        QLabel *seatExtra = new QLabel("Do you want to pay extra $10 for each person to choose seat? ", this);
        yesExtra = new QPushButton("Yes", this);
        noExtra = new QPushButton("No", this);
        QVBoxLayout *economySeatChoice = new QVBoxLayout;
        QHBoxLayout *buttonLayout = new QHBoxLayout;
        buttonLayout->addWidget(yesExtra);
        buttonLayout->addWidget(noExtra);
        economySeatChoice->addWidget(seatExtra);
        economySeatChoice->addLayout(buttonLayout);

        QWidget *centralWidget = new QWidget(this);
        centralWidget->setLayout(economySeatChoice);
        setCentralWidget(centralWidget);
        //if you choose yes to paying extra it takes you to another function to choose seats
        connect(yesExtra, &QPushButton::clicked, [this]
        {
            chooseSeat2();
        });

        connect(noExtra, &QPushButton::clicked, [this]
        {
            //if you choose no then it randomly assigns you a seat value using indexes and then takes you to the confirmation page
            QVector<int> v1;
            while(economySeats.size() < seatCount)
            {
                int randomSeatIndex = QRandomGenerator::global()->bounded(seatIndexes.size());
                if (!v1.contains(randomSeatIndex)) {
                    v1.push_back(randomSeatIndex);
                    QString randomSeat = seatIndexes[randomSeatIndex];
                    economySeats.push_back(randomSeat);
                }
            }
            b = 1;
            confirmation();
        });
    }
}


void MainWindow::chooseSeat2()
{
    //gridLayout for the seats
    QGridLayout *gridLayout = new QGridLayout;
    //creates a scrollable page to ensure that customer can view all the seats offered since it doesn't fit in one page
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    QWidget *gridContainer = new QWidget(scrollArea);
    gridContainer->setLayout(gridLayout);
    scrollArea->setWidget(gridContainer);

    //randomly generates seat indexes for closed seats and pushes it back into a vector
    QRandomGenerator random2;
    QVector<int> closedSeatsIndexes;
    while (closedSeatsIndexes.size() < closedSeats)
    {
        int randomIndex = random2.bounded(seatIndexes.size());
        // Ensure that we do not pick the same seat multiple times
        if (!closedSeatsIndexes.contains(randomIndex))
        {
            closedSeatsIndexes.push_back(randomIndex);
        }
    }

    // Create seat selection label
    QLabel *seatSelectionLabel = new QLabel("Select seat for " + firstName[currentPassengerIndex] + " " + lastName[currentPassengerIndex] + ":", this);
    seatSelectionLabel->setFont(QFont("Arial", 20));
    seatSelectionLabel->setAlignment(Qt::AlignCenter);

    QPushButton *nextPersonButton;
    if(seatCount > 1)
    {
        nextPersonButton = new QPushButton("Next Person", this);
    }
    if(seatCount == 1)
    {
       nextPersonButton = new QPushButton("Finish", this);
    }
    nextPersonButton->setFont(QFont("Arial", 16));
    nextPersonButton->setEnabled(false);


    // Create seat buttons
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            // creates seat label like "1A", "1B", ..., "10D"
            QString seatLabel = QString("%1%2").arg(r + 1).arg(QChar('A' + c));

            // Create seat button
            QPushButton *seatButton = new QPushButton(seatLabel, this);
            seatButton->setFont(QFont("Arial", 12));
            seatButton->setStyleSheet("background-color: green;");
            seatButton->setFixedSize(50, 50);  // Set smaller button size

            //if the seatIndex is in the closedSeatsIndexes vector then it causes the button to turn red and unenables the button
            int seatIndex = r * columns + c;
            if(closedSeatsIndexes.contains(seatIndex))
            {
                seatButton->setStyleSheet("background-color: red;");
                seatButton->setEnabled(false);
            }

            // Add button to grid layout
            gridLayout->addWidget(seatButton, r, c);

            // Connect button click signal to seat selection logic
            connect(seatButton, &QPushButton::clicked, [this, seatLabel, seatButton, nextPersonButton] {
                if(seats.size() <= currentPassengerIndex)
                {
                    //when a green seat is clicked it turns red, and you can't click on it again
                    seats.push_back(seatLabel);  // Add seat to selection vector
                    seatButton->setStyleSheet("background-color: red;");  // Change color to red to indicate selection
                    seatButton->setEnabled(false);
                    nextPersonButton->setEnabled(true);
                }

            });

        }
    }

    connect(nextPersonButton, &QPushButton::clicked, [this, seatSelectionLabel, nextPersonButton]{
        currentPassengerIndex++;
        if(currentPassengerIndex == seatCount - 1)
        {
            nextPersonButton->setText("Finish");
        }
        if(currentPassengerIndex == seatCount)
        {
            //takes you to confirmation function
            confirmation();
            return;
        }

        if(currentPassengerIndex < seatCount)
        {
            seatSelectionLabel->setText("Select seat for " + firstName[currentPassengerIndex] + " " + lastName[currentPassengerIndex] + ":");
            nextPersonButton->setEnabled(false);
        }


    });

    //layout for seat selection
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(seatSelectionLabel);
    layout->addWidget(scrollArea);
    layout->addWidget(nextPersonButton);

    // Set the central widget for seat selection
    QWidget *seatWidget = new QWidget(this);
    seatWidget->setLayout(layout);
    setCentralWidget(seatWidget);

}


void MainWindow::confirmation()
{
    QLabel *flightType;
    QLabel *departureType;
    QLabel *destinationType;
    QVBoxLayout *confirmationLayout = new QVBoxLayout;

    QLabel *totalLabel = new QLabel("Booking Confirmation", this);
    totalLabel->setFont(QFont("Arial", 24));
    totalLabel->setAlignment(Qt::AlignCenter);
    confirmationLayout->addWidget(totalLabel);
    if(a == 1)
    {
        flightType = new QLabel("First Class Flight", this);
    }
    if(a == 2)
    {
        flightType = new QLabel("Business Class Flight", this);
    }
    if(a == 3)
    {
        flightType = new QLabel("Economy Class Flight", this);
    }

    departureType = new QLabel("Departure: " + selectedDeparture);
    destinationType = new QLabel("Destination: " + selectedDestination);

    flightType->setFont(QFont("Arial", 20));
    departureType->setFont(QFont("Arial", 20));
    destinationType->setFont(QFont("Arial", 20));
    flightType->setAlignment(Qt::AlignCenter);
    departureType->setAlignment(Qt::AlignCenter);
    destinationType->setAlignment(Qt::AlignCenter);

    confirmationLayout->addWidget(flightType);
    confirmationLayout->addWidget(departureType);
    confirmationLayout->addWidget(destinationType);

    //creates booking confirmation with name, date of birth, meal type, etc for each person
    for(int i = 0; i < seatCount; i++)
    {
        QLabel *passengerName = new QLabel(firstName[i] + " " + lastName[i]);
        QLabel *passengerSeat;

        if(b == 1)
        {
            passengerSeat = new QLabel("Seat " + economySeats[i], this);
        }
        else
        {
            passengerSeat = new QLabel("Chosen seat " + seats[i], this);
        }
        QLabel *passengerDOB = new QLabel("Birthday: " + birthMonth[i] + " " + birthDay[i] + ", " + birthYear[i], this);
        QLabel *passengerMeal = new QLabel("Meal Type: " + mealType[i], this);
        QLabel *passengerAllergy = new QLabel("Allergies: " + vectorAllergy[i], this);
        QLabel *extraSpace = new QLabel("     ", this);

        confirmationLayout->addWidget(passengerName);
        confirmationLayout->addWidget(passengerSeat);
        confirmationLayout->addWidget(passengerDOB);
        confirmationLayout->addWidget(passengerMeal);
        confirmationLayout->addWidget(passengerAllergy);
        confirmationLayout->addWidget(extraSpace);
    }

    //displayes the total price and the breakdown for the price
    QLabel *flightTicketPrice;
    float totalPrice = price * seatCount;
    if(seatCount == 1)
    {
        flightTicketPrice = new QLabel("Flight Ticket: $" + QString::number(price) + " x " + QString::number(seatCount) + " person ----------$" + QString::number(totalPrice));
    }
    else
    {
        flightTicketPrice = new QLabel("Flight Ticket: $" + QString::number(price) + " x " + QString::number(seatCount) + " people ----------$" + QString::number(totalPrice));
    }

    confirmationLayout->addWidget(flightTicketPrice);
    //displays the extra money economy class people have to pay if they wanted to select a seat
    QLabel *extra;
    float totalExtra = 0;
    if(b == 0)
    {
        if(a == 3)
        {
            totalExtra = 10 * seatCount;
            if(seatCount == 1)
            {
                extra = new QLabel("Extra for choosing seat: $10 x " + QString::number(seatCount) + " person ----------$" + QString::number(totalExtra));
            }
            else
            {
                extra = new QLabel("Extra for choosing seat: $10 x " + QString::number(seatCount) + " people ----------$" + QString::number(totalExtra));
            }
            confirmationLayout->addWidget(extra);
            extra->setFont(QFont("Arial", 20));
        }
    }
    QLabel *random = new QLabel("----------------------------------------------------------------------------------------", this);
    flightTicketPrice->setFont(QFont("Arial", 20));
    random->setFont(QFont("Arial", 20));

    totalMoney = totalPrice + totalExtra;
    QLabel *total = new QLabel("Total Price    $" + QString::number(totalMoney));
    total->setFont(QFont("Arial", 20));


    confirmationLayout->addWidget(random);
    confirmationLayout->addWidget(total);

    QPushButton *Pay = new QPushButton("Pay", this);
    Pay->setFixedSize(70,70);
    confirmationLayout->addWidget(Pay);


    QWidget *confirmationWidget = new QWidget(this);
    confirmationWidget->setLayout(confirmationLayout);
    //makes the page scrollable
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(confirmationWidget);
    scrollArea->setWidgetResizable(true);

    setCentralWidget(scrollArea);
    //connectes it to billing function is the pay button is clicked
    connect(Pay, &QPushButton::clicked, this, &MainWindow::billing);
}
void MainWindow::billing()
{
    //creates a billing page where it asks you to enter credit card number, cvv, etc
    QLabel *billingPage = new QLabel("Billing Page");
    billingPage->setAlignment(Qt::AlignCenter);
    billingPage->setFont(QFont("Arial", 24));

    QLabel *totalDue = new QLabel("Total Due: $" + QString::number(totalMoney));


    QVBoxLayout *mainLayout = new QVBoxLayout;

    QLineEdit *emailInput = new QLineEdit(this);
    emailInput->setPlaceholderText("Enter a valid email");

    // Credit Card Number Field
    QLineEdit *cardNumberInput = new QLineEdit(this);
    cardNumberInput->setPlaceholderText("Enter your 16-digit card number");
    cardNumberInput->setMaxLength(16); // Limit to 16 digits

    // Expiration Date Field
    QLineEdit *expirDateInput = new QLineEdit(this);
    expirDateInput->setPlaceholderText("MM/YY");
    expirDateInput->setMaxLength(5); // Format: MM/YY

    // CVV Field
    QLineEdit *cvvInput = new QLineEdit(this);
    cvvInput->setPlaceholderText("CVV");
    cvvInput->setMaxLength(3); // CVV is usually 3 digits

    QHBoxLayout *emailLayout = new QHBoxLayout;
    QLabel *email = new QLabel("Email:", this);
    emailLayout->addWidget(email);
    emailLayout->addWidget(emailInput);

    QHBoxLayout *c = new QHBoxLayout;
    QLabel *c1 = new QLabel ("Card Number:", this);
    c->addWidget(c1);
    c->addWidget(cardNumberInput);

    QHBoxLayout *e = new QHBoxLayout;
    QLabel *e2 = new QLabel ("Expiration Date:", this);
    e->addWidget(e2);
    e->addWidget(expirDateInput);

    QHBoxLayout *cvv = new QHBoxLayout;
    QLabel *cvv1 = new QLabel ("CVV:", this);
    cvv->addWidget(cvv1);
    cvv->addWidget(cvvInput);

    mainLayout->addLayout(emailLayout);
    mainLayout->addLayout(c);
    mainLayout->addLayout(e);
    mainLayout->addLayout(cvv);
    // Submit Button
    QPushButton *submitButton = new QPushButton("Submit Payment", this);
    mainLayout->addWidget(submitButton);

    QWidget *paymentWidget = new QWidget(this);
    paymentWidget->setLayout(mainLayout);
    setCentralWidget(paymentWidget);


    connect(submitButton, &QPushButton::clicked, this, [=]() {
        QString cardNumber = cardNumberInput->text();
        QString expirDate = expirDateInput->text();
        QString cvv = cvvInput->text();
        email1 = emailInput->text();
        //ensures that the cardNumber, expirDate, and cvv has the right length
       if(cardNumber.length() != 16)
       {
           QMessageBox::warning(this, "Error", "Card number must be 16 digits");
           return;
       }
       if(expirDate.length() != 5)
       {
           QMessageBox::warning(this, "Error", "Expiry date must be in MM/YY format.");
           return;
       }
       if(cvv.length() != 3)
       {
           QMessageBox::warning(this, "Error", "CVV must be 3 digits.");
           return;
       }
       booked();
    });
}

void MainWindow::booked()
{
    //congratulation page displayed once everything is booked
    QLabel *congrats = new QLabel("Congratulations!!! You have booked " + QString::number(seatCount) + " ticket(s) from " + selectedDeparture + " to " + selectedDestination + ". ", this);
    QLabel *congrats1 = new QLabel("A receipt will be sent to you email " + email1 + " shortly.", this);
    congrats->setFont(QFont("Arial", 20));
    congrats->setAlignment(Qt::AlignCenter);
    congrats1->setFont(QFont("Arial", 20));
    congrats1->setAlignment(Qt::AlignCenter);
    QVBoxLayout *finalLayout = new QVBoxLayout;
    finalLayout->addWidget(congrats);
    finalLayout->addWidget(congrats1);
    QWidget *finalWidget = new QWidget(this);
    finalWidget->setLayout(finalLayout);
    setCentralWidget(finalWidget);
}

MainWindow::~MainWindow()
{

}