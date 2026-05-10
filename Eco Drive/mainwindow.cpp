#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "InputValidator.h"
#include <QButtonGroup>
#include <QMessageBox>
#include <QString>
#include <QDate>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QKeyEvent>
#include "vehicleprofile.h"
#include "route.h"
#include "trip.h"
#include "savedroutes.h"

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

    // Pointer cursor for buttons
    QList<QPushButton*> buttons = {
        ui->routeAnalysisButton, ui->dashboardButton, ui->settingsButton,
        ui->saveProfileButton, ui->calculateButton,
        ui->petrolButton, ui->dieselButton, ui->saveRouteButton, ui->deleteButton
    };
    for (auto btn : buttons)
        btn->setCursor(Qt::PointingHandCursor);

    // Table styling
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    const auto routes = SavedRoutes::loadAllRoutes();
    for (const auto &route : routes) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        auto addItem = [&](int col, const QString &text) {
            auto *item = new QTableWidgetItem(text);
            item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(row, col, item);
        };

        addItem(0, route.date);
        addItem(1, route.route);
        addItem(2, route.distance);
        addItem(3, route.fuel);
        addItem(4, route.price);
    }

    // Hardcoded fuel price until API is connected
    const QString fuelPrice = "1.88";
    ui->priceLine->setText(fuelPrice + " €/L");
    ui->priceLine_2->setText(fuelPrice + " €/L");
    ui->priceLine->setReadOnly(true);
    ui->priceLine_2->setReadOnly(true);
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

    QString error = InputValidator::validateProfileInputs(consumption);
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
        ui->consumptionLine->text()
        );

    if (!error.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", error);
        return;
    }

    Route currentRoute(ui->startLine->text(), ui->destinationLine->text());

    double consumption = ui->consumptionLine->text().toDouble();
    double fuelPrice = 1.88;

    VehicleProfile tripProfile;
    tripProfile.setConsumption(consumption);
    tripProfile.setFuelType(ui->dieselButton->isChecked() ? "Diesel" : "Petrol");

    Trip currentTrip(currentRoute, tripProfile, fuelPrice);

    ui->distanceResult->setText(QString::number(currentRoute.getDistance(), 'f', 0) + " km");
    ui->distanceResult_2->setText(QString::number(currentTrip.calculateFuelRequired(), 'f', 1) + " L");
    ui->distanceResult_3->setText(QString::number(currentTrip.calculateTotalPrice(), 'f', 2) + " €");

    ui->apperingOnCalculateTripFrame->show();
}

void MainWindow::on_saveRouteButton_clicked(){
    if (ui->distanceResult->text() == "--- km") {
        QMessageBox::warning(this, "No Route", "Please calculate a trip first");
        return;
    }

    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    QString route = ui->startLine->text() + " → " + ui->destinationLine->text();
    QString distance = ui->distanceResult->text();
    QString fuel = ui->distanceResult_2->text();
    QString price = ui->distanceResult_3->text();

    for (int r = 0; r < ui->tableWidget->rowCount(); r++) {
        QString existingDate = ui->tableWidget->item(r, 0)->text();
        QString existingRoute = ui->tableWidget->item(r, 1)->text();
        QString existingDistance = ui->tableWidget->item(r, 2)->text();

        if (existingDate == date && existingRoute == route && existingDistance == distance) {
            QMessageBox::information(this, "Already Saved", "This route is already in your history");
            return;
        }
    }

    SavedRoute newRoute;
    newRoute.date = date;
    newRoute.route = route;
    newRoute.distance = distance;
    newRoute.fuel = fuel;
    newRoute.price = price;

    if (!SavedRoutes::saveRoute(newRoute)) {
        QMessageBox::warning(this, "Error", "Could not save route");
        return;
    }

    int row = 0;
    ui->tableWidget->insertRow(row);

    auto addItem = [&](int col, const QString &text) {
        auto *item = new QTableWidgetItem(text);
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, col, item);
    };

    addItem(0, date);
    addItem(1, route);
    addItem(2, distance);
    addItem(3, fuel);
    addItem(4, price);

    QMessageBox::information(this, "Saved", "Route saved successfully!");
}

void MainWindow::on_deleteButton_clicked(){
    int row = ui->tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a route to delete");
        return;
    }

    SavedRoute routeToDelete;
    routeToDelete.date = ui->tableWidget->item(row, 0)->text();
    routeToDelete.route = ui->tableWidget->item(row, 1)->text();
    routeToDelete.distance = ui->tableWidget->item(row, 2)->text();

    if (SavedRoutes::deleteRoute(routeToDelete)) {
        ui->tableWidget->clearSelection();
        ui->tableWidget->setCurrentCell(-1, -1);
        ui->tableWidget->removeRow(row);

        QMessageBox::information(this, "Deleted", "Route removed successfully");
    } else {
        QMessageBox::warning(this, "Error", "Could not delete route");
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    // If ESC is pressed, clear table selection
    if (event->key() == Qt::Key_Escape) {
        ui->tableWidget->clearSelection();
        ui->tableWidget->setCurrentCell(-1, -1);
        event->accept();
        return;
    }
    QMainWindow::keyPressEvent(event);
}

void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem *item) {
    if (!item) return;

    int clickedRow = item->row();

    // When clicked on selected row, clear selection
    if (clickedRow == m_lastSelectedRow) {
        ui->tableWidget->clearSelection();
        ui->tableWidget->setCurrentCell(-1, -1);
        m_lastSelectedRow = -1;
    }
    else {
        m_lastSelectedRow = clickedRow;
    }
}