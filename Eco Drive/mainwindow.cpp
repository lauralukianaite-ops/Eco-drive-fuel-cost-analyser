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
#include "apimanager.h"
#include "distanceapi.h"
#include "fuelpriceapi.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QButtonGroup *fuelGroup = new QButtonGroup(this);

    ui->carModelLabel->setText("");
    ui->descriptionLabel->setText("");

    ui->petrolButton->setCheckable(true);
    ui->dieselButton->setCheckable(true);
    ui->dieselButton->setChecked(true);

    fuelGroup->addButton(ui->petrolButton);
    fuelGroup->addButton(ui->dieselButton);

    ui->availableRoutesCard->setVisible(false);

    if(ui->apperingOnCalculateTripFrame){
        ui->apperingOnCalculateTripFrame->hide();
    }

    QList<QPushButton*> buttons = {
        ui->routeAnalysisButton, ui->dashboardButton, ui->settingsButton,
        ui->saveProfileButton, ui->calculateButton,
        ui->petrolButton, ui->dieselButton, ui->saveRouteButton, ui->deleteButton
    };
    for (auto btn : buttons)
        btn->setCursor(Qt::PointingHandCursor);

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

    ui->currentPriceAPILabel->setText("1.88");
    QString fuelPrice = ui->currentPriceAPILabel->text();
    ui->priceLine->setText(fuelPrice + " €/L");
    ui->fuelPriceProfileLine->setText(fuelPrice + " €/L");
    ui->priceLine->setReadOnly(true);
    ui->fuelPriceProfileLine->setReadOnly(true);
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

    if(model.isEmpty()) {
        model = "My Car";
    }

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

    ui->consumptionLine->setText(QString::number(consumption.toDouble(), 'f', 1) + " L/100km");
    ui->consumptionLine->setReadOnly(true);
}

void MainWindow::on_calculateButton_clicked()
{
    QString start = ui->startLine->text().trimmed();
    QString dest = ui->destinationLine->text().trimmed();

    QString consText = ui->avgCansumptionEnterLine->text().trimmed();

    QString validationMsg = InputValidator::validateRouteInputs(start, dest);
    if (!validationMsg.isEmpty()) {
        QMessageBox::warning(this, "Validation error", validationMsg);
        return;
    }

    if (consText.isEmpty() || !InputValidator::isPositiveNumber(consText)) {
        QMessageBox::warning(this, "Validation error", "Please enter correct fuel consumption.");
        return;
    }

    userProfile.setConsumption(consText.toDouble());
    userProfile.setFuelType(ui->petrolButton->isChecked() ? "Petrol" : "Diesel");

    Route route(start, dest);
    Trip *currentTrip = new Trip(route, userProfile, this);

    ui->calculateButton->setEnabled(false);

    connect(currentTrip, &Trip::calculationFinished, this, [this, currentTrip]() {
        QVector<RouteOption> routes = currentTrip->getRoutes();

        RouteOption cheapest    = routes.value(0);
        RouteOption alternative = routes.value(1, cheapest);

        ui->distanceResult->setText(
            QString::number(cheapest.distanceKm, 'f', 1) + " km");
        ui->distanceResult_2->setText(
            QString::number((cheapest.distanceKm / 100.0) * userProfile.getConsumption(), 'f', 2) + " L");
        ui->distanceResult_3->setText(
            QString::number(cheapest.fuelCost, 'f', 2) + " €");

        auto fmtTime = [](int mins) -> QString {
            if (mins < 60) return QString("~%1 min").arg(mins);
            return QString("~%1h %2min").arg(mins / 60).arg(mins % 60);
        };

        ui->cheapestKmLabel->setText(
            QString("~%1 km").arg(cheapest.distanceKm, 0, 'f', 0));
        ui->cheapestTimeLabel->setText(fmtTime(cheapest.durationMinutes));
        ui->label_14->setText(
            QString::number(cheapest.fuelCost, 'f', 2) + " €");

        ui->label_11->setText(
            QString("~%1 km").arg(alternative.distanceKm, 0, 'f', 0));
        ui->label_12->setText(fmtTime(alternative.durationMinutes));
        ui->label_13->setText(
            QString::number(alternative.fuelCost, 'f', 2) + " €");

        ui->apperingOnCalculateTripFrame->show();
        ui->availableRoutesCard->setVisible(true);

        ui->calculateButton->setEnabled(true);
        ui->calculateButton->setText("Calculate Trip");
        currentTrip->deleteLater();
    });

    connect(currentTrip, &Trip::calculationError, this, [this, currentTrip](const QString &error) {
        QMessageBox::critical(this, "Error", "Failed to retrieve API data: " + error);
        ui->calculateButton->setEnabled(true);
        ui->calculateButton->setText("Calculate Trip");
        currentTrip->deleteLater();
    });

    currentTrip->startCalculation();
}
void MainWindow::on_saveRouteButton_clicked() {
    QString distanceText = ui->distanceResult  ? ui->distanceResult->text()   : "";
    QString fuelText     = ui->distanceResult_2 ? ui->distanceResult_2->text() : "";
    QString priceText    = ui->distanceResult_3 ? ui->distanceResult_3->text() : "";

    if (distanceText.isEmpty() || distanceText == "--- km") {
        QMessageBox::warning(this, "No Results", "Please calculate a trip before saving.");
        return;
    }

    QString start = ui->startLine->text().trimmed();
    QString dest  = ui->destinationLine->text().trimmed();

    SavedRoute entry;
    entry.date     = QDate::currentDate().toString("yyyy-MM-dd");
    entry.route    = start + " → " + dest;
    entry.distance = distanceText;
    entry.fuel     = fuelText;
    entry.price    = priceText;

    if (!SavedRoutes::saveRoute(entry)) {
        QMessageBox::warning(this, "Error", "Could not save the route.");
        return;
    }

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    auto addItem = [&](int col, const QString &text) {
        auto *item = new QTableWidgetItem(text);
        item->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row, col, item);
    };

    addItem(0, entry.date);
    addItem(1, entry.route);
    addItem(2, entry.distance);
    addItem(3, entry.fuel);
    addItem(4, entry.price);

    QMessageBox::information(this, "Saved", "Route saved successfully.");
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

    if (clickedRow == m_lastSelectedRow) {
        ui->tableWidget->clearSelection();
        ui->tableWidget->setCurrentCell(-1, -1);
        m_lastSelectedRow = -1;
    }
    else {
        m_lastSelectedRow = clickedRow;
    }
}

void MainWindow::on_petrolButton_clicked(){
    ui->currentFuelPriceAPILabel->setText("Current petrol price (API)");
    ui->currentPriceAPILabel->setText("1.74");
    QString fuelPrice = ui->currentPriceAPILabel->text();
    ui->priceLine->setText(fuelPrice + " €/L");
    ui->fuelPriceProfileLine->setText(fuelPrice + " €/L");
    ui->priceLine->setReadOnly(true);
    ui->fuelPriceProfileLine->setReadOnly(true);
}

void MainWindow::on_dieselButton_clicked(){
    ui->currentFuelPriceAPILabel->setText("Current diesel price (API)");
    ui->currentPriceAPILabel->setText("1.88");
    QString fuelPrice = ui->currentPriceAPILabel->text();
    ui->priceLine->setText(fuelPrice + " €/L");
    ui->fuelPriceProfileLine->setText(fuelPrice + " €/L");
    ui->priceLine->setReadOnly(true);
    ui->fuelPriceProfileLine->setReadOnly(true);
}
