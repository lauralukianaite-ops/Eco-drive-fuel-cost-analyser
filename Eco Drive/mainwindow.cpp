#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "InputValidator.h"
#include <QButtonGroup>
#include <QMessageBox>
#include <QString>
#include "vehicleprofile.h"
#include "route.h"
#include "trip.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QButtonGroup *fuelGroup = new  QButtonGroup(this);

    ui->petrolButton->setCheckable(true);
    ui->dieselButton->setCheckable(true);

    fuelGroup->addButton(ui->petrolButton);
    fuelGroup->addButton(ui->dieselButton);

    if(ui->apperingOnCalculateTripFrame){
        ui->apperingOnCalculateTripFrame->hide();
    }

    connect(ui->routeAnalysisButton, &QPushButton::clicked, this, &MainWindow::on_routeAnalysisButton_clicked);
    connect(ui->dashboardButton, &QPushButton::clicked, this, &MainWindow::on_dashboardButton_clicked);
    connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::on_settingsButton_clicked);
    connect(ui->saveProfileButton, &QPushButton::clicked, this, &MainWindow::on_saveProfileButton_clicked);

    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::on_calculateButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_routeAnalysisButton_clicked(){
    ui->stackedWidget->setCurrentWidget(ui->RouteAnalysisPage);
}
void MainWindow::on_dashboardButton_clicked(){
    ui->stackedWidget->setCurrentWidget(ui->travelHistoryPage);
}
void MainWindow::on_settingsButton_clicked(){
    ui->stackedWidget->setCurrentWidget(ui->settingsPage);
}
void MainWindow::on_saveProfileButton_clicked(){

    QString model = ui->carModelLine->text();
    QString consumption = ui->avgCansumptionEnterLine->text();
    QString fuelType = ui->dieselButton->isChecked() ? "Diesel" : "Petrol";

    if (!ui->petrolButton->isChecked() && !ui->dieselButton->isChecked()) {
        QMessageBox::warning(this, "Invalid Input", "Please select a fuel type");
        return;
    }

    QString error = InputValidator::validateProfileInputs(consumption, ui->priceLine_2->text());
    if (!error.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", error);
        return;
    }

    userProfile.setModel(model);
    userProfile.setConsumption(consumption.toDouble());
    userProfile.setFuelType(fuelType);

    if(!model.isEmpty()){
        ui->carModelLabel->setText(model);
    }

    ui->descriptionLabel->setText(userProfile.getShortSummary());

    ui->consumptionLine->setText(QString::number(consumption.toDouble(), 'f', 1));
}
void MainWindow::on_calculateButton_clicked(){


    QString error = InputValidator::validateRouteInputs(
        ui->startLine->text(),
        ui->destinationLine->text(),
        ui->priceLine->text(),
        ui->consumptionLine->text()
        );

    if (!error.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", error);
        return;
    }

    QString start = ui->startLine->text();
    QString destination = ui->destinationLine->text();

    Route currentRoute(start, destination);

    double fuelPrice = 1.88;
    double distance = currentRoute.getDistance();

    VehicleProfile tripProfile = userProfile;

    Trip currentTrip(currentRoute, tripProfile, fuelPrice);

    ui->distanceResult->setText(QString::number(distance, 'f', 0) + " km");
    ui->distanceResult_2->setText(QString::number(currentTrip.calculateFuelRequired(), 'f', 1) + " L");
    ui->distanceResult_3->setText(QString::number(currentTrip.calculateTotalPrice(), 'f', 2) + " €");

    ui->apperingOnCalculateTripFrame->show();
}
