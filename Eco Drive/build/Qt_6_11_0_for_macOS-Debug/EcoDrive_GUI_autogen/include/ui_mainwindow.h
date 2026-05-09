/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *sidebarFrame;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QPushButton *routeAnalysisButton;
    QPushButton *dashboardButton;
    QPushButton *settingsButton;
    QSpacerItem *verticalSpacer;
    QFrame *userProfileWidget;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *iconLabel;
    QVBoxLayout *verticalLayout_7;
    QLabel *carModelLabel;
    QLabel *descriptionLabel;
    QFrame *mainWindowFrame;
    QStackedWidget *stackedWidget;
    QWidget *settingsPage;
    QFrame *vehicleProfileCard;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QLineEdit *carModelLine;
    QLineEdit *avgCansumptionEnterLine;
    QLineEdit *priceLine_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *petrolButton;
    QPushButton *dieselButton;
    QPushButton *saveProfileButton;
    QLabel *travelCostCalculatorLabel_2;
    QLabel *travelCostCalculatorLabel_3;
    QFrame *fuelPriceCard;
    QVBoxLayout *verticalLayout_6;
    QLabel *fuelPriceTitleLabel;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QLabel *currentPriceAPILabel;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QLabel *lastUpdatedLabel;
    QHBoxLayout *horizontalLayout_10;
    QLabel *sourceLabel;
    QLabel *source2Label;
    QLabel *label_3;
    QWidget *RouteAnalysisPage;
    QFrame *parametersCard;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_6;
    QLineEdit *startLine;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_7;
    QLineEdit *destinationLine;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *priceLine;
    QLineEdit *consumptionLine;
    QPushButton *calculateButton;
    QLabel *travelCostCalculatorLabel;
    QFrame *apperingOnCalculateTripFrame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QFrame *fuelRequiredFrame;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_9;
    QLabel *distanceLabel_2;
    QLabel *distanceResult_2;
    QFrame *distanceFrame;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_8;
    QLabel *distanceLabel;
    QLabel *distanceResult;
    QFrame *priceFrame;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_10;
    QLabel *distanceLabel_3;
    QLabel *distanceResult_3;
    QFrame *availableRoutesCard;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QPushButton *saveRouteButton;
    QFrame *frame;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_9;
    QLabel *cheapestKmLabel;
    QLabel *cheapestTimeLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_13;
    QWidget *travelHistoryPage;
    QLabel *travelCostCalculatorLabel_4;
    QTableWidget *tableWidget;
    QLabel *travelCostCalculatorLabel_5;
    QPushButton *deleteButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 700);
        MainWindow->setStyleSheet(QString::fromUtf8("QFrame#sidebarFrame {\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: transparent; \n"
"    font-weight: bold;\n"
"    color: #687c94;  \n"
"    border: none;\n"
"    text-align: left;\n"
"    padding-left: 10px;\n"
"}\n"
"\n"
"Line {\n"
"	color: #687c94; \n"
"	background-color: #687c94;\n"
"	border: none;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"    background-color: #0d1117; \n"
"}"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sidebarFrame = new QFrame(centralwidget);
        sidebarFrame->setObjectName("sidebarFrame");
        sidebarFrame->setMinimumSize(QSize(220, 0));
        sidebarFrame->setMaximumSize(QSize(220, 16777215));
        sidebarFrame->setStyleSheet(QString::fromUtf8("QFrame#sidebarFrame {\n"
"    background-color: #181d24; \n"
"    border-right: 2px solid #30363d;\n"
"}\n"
"QLabel#titleLabel{\n"
"	color: #00c896;\n"
"	letter-spacing: 3px;\n"
"}\n"
""));
        sidebarFrame->setFrameShape(QFrame::Shape::StyledPanel);
        sidebarFrame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(sidebarFrame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 41, 20, 20);
        titleLabel = new QLabel(sidebarFrame);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setMinimumSize(QSize(0, 100));
        titleLabel->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        verticalLayout->addWidget(titleLabel);

        routeAnalysisButton = new QPushButton(sidebarFrame);
        routeAnalysisButton->setObjectName("routeAnalysisButton");
        routeAnalysisButton->setMinimumSize(QSize(0, 60));

        verticalLayout->addWidget(routeAnalysisButton);

        dashboardButton = new QPushButton(sidebarFrame);
        dashboardButton->setObjectName("dashboardButton");
        dashboardButton->setMinimumSize(QSize(0, 60));

        verticalLayout->addWidget(dashboardButton);

        settingsButton = new QPushButton(sidebarFrame);
        settingsButton->setObjectName("settingsButton");
        settingsButton->setMinimumSize(QSize(0, 60));

        verticalLayout->addWidget(settingsButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        userProfileWidget = new QFrame(sidebarFrame);
        userProfileWidget->setObjectName("userProfileWidget");
        userProfileWidget->setMinimumSize(QSize(0, 50));
        userProfileWidget->setStyleSheet(QString::fromUtf8("QFrame#userProfileWidget {\n"
"    border: 0px solid #161b22;\n"
"}"));
        userProfileWidget->setFrameShape(QFrame::Shape::StyledPanel);
        userProfileWidget->setFrameShadow(QFrame::Shadow::Raised);
        userProfileWidget->setLineWidth(0);
        horizontalLayoutWidget_6 = new QWidget(userProfileWidget);
        horizontalLayoutWidget_6->setObjectName("horizontalLayoutWidget_6");
        horizontalLayoutWidget_6->setGeometry(QRect(0, 0, 181, 51));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        iconLabel = new QLabel(horizontalLayoutWidget_6);
        iconLabel->setObjectName("iconLabel");
        iconLabel->setMaximumSize(QSize(40, 40));
        QFont font1;
        font1.setBold(true);
        iconLabel->setFont(font1);
        iconLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border-radius: 20px; \n"
"	background-color: #d1f7ec; \n"
"	color: #0d1117;\n"
"}"));

        horizontalLayout_7->addWidget(iconLabel);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName("verticalLayout_7");
        carModelLabel = new QLabel(horizontalLayoutWidget_6);
        carModelLabel->setObjectName("carModelLabel");
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        carModelLabel->setFont(font2);

        verticalLayout_7->addWidget(carModelLabel);

        descriptionLabel = new QLabel(horizontalLayoutWidget_6);
        descriptionLabel->setObjectName("descriptionLabel");
        QFont font3;
        font3.setPointSize(11);
        descriptionLabel->setFont(font3);

        verticalLayout_7->addWidget(descriptionLabel);


        horizontalLayout_7->addLayout(verticalLayout_7);


        verticalLayout->addWidget(userProfileWidget);


        horizontalLayout->addWidget(sidebarFrame);

        mainWindowFrame = new QFrame(centralwidget);
        mainWindowFrame->setObjectName("mainWindowFrame");
        mainWindowFrame->setStyleSheet(QString::fromUtf8(""));
        mainWindowFrame->setFrameShape(QFrame::Shape::StyledPanel);
        mainWindowFrame->setFrameShadow(QFrame::Shadow::Raised);
        stackedWidget = new QStackedWidget(mainWindowFrame);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 781, 701));
        stackedWidget->setLineWidth(0);
        settingsPage = new QWidget();
        settingsPage->setObjectName("settingsPage");
        vehicleProfileCard = new QFrame(settingsPage);
        vehicleProfileCard->setObjectName("vehicleProfileCard");
        vehicleProfileCard->setGeometry(QRect(60, 170, 300, 391));
        vehicleProfileCard->setMinimumSize(QSize(300, 0));
        vehicleProfileCard->setMaximumSize(QSize(300, 16777215));
        vehicleProfileCard->setStyleSheet(QString::fromUtf8("QFrame#vehicleProfileCard {\n"
"    background-color: #161b22;\n"
"    border: 1px solid #30363d;\n"
"    border-radius: 12px;\n"
"}\n"
"QLabel {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 16px;\n"
"}\n"
"QLineEdit {\n"
"    background-color: #0d1117;\n"
"    border: 1px solid #30363d;\n"
"    border-radius: 6px;\n"
"    color: white;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton#saveProfileButton{\n"
"    background-color: #00c896;\n"
"    color: black;\n"
"    border-radius: 8px;\n"
"    font-weight: bold;\n"
"    height: 40px;\n"
"}\n"
"\n"
"QPushButton#saveProfileButton:hover  {\n"
"    background-color: #00c896;\n"
"    color: black;\n"
"    border-radius: 8px;\n"
"    font-weight: bold;\n"
"    height: 40px;\n"
"	background-color: rgba(0, 200, 150, 127);\n"
"}\n"
"\n"
"QPushButton#petrolButton, QPushButton#dieselButton{\n"
"    background-color: #161b22;\n"
"    border: 1px solid #30363d;\n"
"    color: gray;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"/* Mygt"
                        "ukas, kur\304\257 vartotojas pasirinko */\n"
"QPushButton#petrolButton:checked {\n"
"    background-color: #161b22;\n"
"    border: 2px solid #00c896;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton#dieselButton:checked {\n"
"    background-color: #161b22;\n"
"    border: 2px solid #00c896;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}"));
        vehicleProfileCard->setFrameShape(QFrame::Shape::StyledPanel);
        vehicleProfileCard->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_5 = new QVBoxLayout(vehicleProfileCard);
        verticalLayout_5->setSpacing(19);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(-1, 21, -1, 21);
        label_2 = new QLabel(vehicleProfileCard);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 40));

        verticalLayout_5->addWidget(label_2);

        carModelLine = new QLineEdit(vehicleProfileCard);
        carModelLine->setObjectName("carModelLine");
        carModelLine->setMaximumSize(QSize(16777215, 47));

        verticalLayout_5->addWidget(carModelLine);

        avgCansumptionEnterLine = new QLineEdit(vehicleProfileCard);
        avgCansumptionEnterLine->setObjectName("avgCansumptionEnterLine");
        avgCansumptionEnterLine->setMaximumSize(QSize(16777215, 47));

        verticalLayout_5->addWidget(avgCansumptionEnterLine);

        priceLine_2 = new QLineEdit(vehicleProfileCard);
        priceLine_2->setObjectName("priceLine_2");
        priceLine_2->setMaximumSize(QSize(16777215, 47));

        verticalLayout_5->addWidget(priceLine_2);

        horizontalLayout_6 = new QHBoxLayout();
#ifndef Q_OS_MAC
        horizontalLayout_6->setSpacing(-1);
#endif
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(-1, 0, -1, -1);
        petrolButton = new QPushButton(vehicleProfileCard);
        petrolButton->setObjectName("petrolButton");
        petrolButton->setMinimumSize(QSize(100, 0));
        petrolButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: center;\n"
"}"));

        horizontalLayout_6->addWidget(petrolButton, 0, Qt::AlignmentFlag::AlignLeft);

        dieselButton = new QPushButton(vehicleProfileCard);
        dieselButton->setObjectName("dieselButton");
        dieselButton->setMinimumSize(QSize(100, 0));
        dieselButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: center;\n"
"}"));

        horizontalLayout_6->addWidget(dieselButton, 0, Qt::AlignmentFlag::AlignRight);


        verticalLayout_5->addLayout(horizontalLayout_6);

        saveProfileButton = new QPushButton(vehicleProfileCard);
        saveProfileButton->setObjectName("saveProfileButton");
        saveProfileButton->setMinimumSize(QSize(0, 20));
        saveProfileButton->setMaximumSize(QSize(16777215, 40));
        saveProfileButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: center;\n"
"    padding: 5px; \n"
"}"));

        verticalLayout_5->addWidget(saveProfileButton);

        travelCostCalculatorLabel_2 = new QLabel(settingsPage);
        travelCostCalculatorLabel_2->setObjectName("travelCostCalculatorLabel_2");
        travelCostCalculatorLabel_2->setGeometry(QRect(60, 40, 431, 61));
        QFont font4;
        font4.setPointSize(36);
        font4.setBold(true);
        travelCostCalculatorLabel_2->setFont(font4);
        travelCostCalculatorLabel_3 = new QLabel(settingsPage);
        travelCostCalculatorLabel_3->setObjectName("travelCostCalculatorLabel_3");
        travelCostCalculatorLabel_3->setGeometry(QRect(60, 70, 431, 61));
        QFont font5;
        font5.setPointSize(16);
        font5.setBold(false);
        travelCostCalculatorLabel_3->setFont(font5);
        travelCostCalculatorLabel_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #687c94; \n"
"}"));
        fuelPriceCard = new QFrame(settingsPage);
        fuelPriceCard->setObjectName("fuelPriceCard");
        fuelPriceCard->setGeometry(QRect(410, 170, 300, 281));
        fuelPriceCard->setMinimumSize(QSize(300, 0));
        fuelPriceCard->setMaximumSize(QSize(300, 16777215));
        fuelPriceCard->setStyleSheet(QString::fromUtf8("QFrame#fuelPriceCard {\n"
"    background-color: #161b22;\n"
"    border: 1px solid #30363d;\n"
"    border-radius: 12px;\n"
"}\n"
"QLabel#fuelPriceTitleLabel {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 16px;\n"
"}\n"
"QPushButton#saveProfileButton {\n"
"    background-color: #00c896;\n"
"    color: black;\n"
"    border-radius: 8px;\n"
"    font-weight: bold;\n"
"    height: 40px;\n"
"}\n"
"\n"
""));
        fuelPriceCard->setFrameShape(QFrame::Shape::StyledPanel);
        fuelPriceCard->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_6 = new QVBoxLayout(fuelPriceCard);
        verticalLayout_6->setSpacing(7);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(-1, 21, -1, 21);
        fuelPriceTitleLabel = new QLabel(fuelPriceCard);
        fuelPriceTitleLabel->setObjectName("fuelPriceTitleLabel");
        fuelPriceTitleLabel->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_6->addWidget(fuelPriceTitleLabel);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_4 = new QLabel(fuelPriceCard);
        label_4->setObjectName("label_4");

        horizontalLayout_8->addWidget(label_4);

        currentPriceAPILabel = new QLabel(fuelPriceCard);
        currentPriceAPILabel->setObjectName("currentPriceAPILabel");
        currentPriceAPILabel->setFont(font1);
        currentPriceAPILabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #00c896;\n"
"}"));

        horizontalLayout_8->addWidget(currentPriceAPILabel, 0, Qt::AlignmentFlag::AlignRight);


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_5 = new QLabel(fuelPriceCard);
        label_5->setObjectName("label_5");

        horizontalLayout_9->addWidget(label_5);

        lastUpdatedLabel = new QLabel(fuelPriceCard);
        lastUpdatedLabel->setObjectName("lastUpdatedLabel");
        lastUpdatedLabel->setFont(font1);

        horizontalLayout_9->addWidget(lastUpdatedLabel, 0, Qt::AlignmentFlag::AlignRight);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        sourceLabel = new QLabel(fuelPriceCard);
        sourceLabel->setObjectName("sourceLabel");

        horizontalLayout_10->addWidget(sourceLabel);

        source2Label = new QLabel(fuelPriceCard);
        source2Label->setObjectName("source2Label");
        source2Label->setFont(font1);

        horizontalLayout_10->addWidget(source2Label, 0, Qt::AlignmentFlag::AlignRight);


        verticalLayout_6->addLayout(horizontalLayout_10);

        label_3 = new QLabel(fuelPriceCard);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 40));
        label_3->setMaximumSize(QSize(16777215, 16777215));
        label_3->setFont(font3);
        label_3->setAcceptDrops(false);
        label_3->setWordWrap(true);

        verticalLayout_6->addWidget(label_3);

        stackedWidget->addWidget(settingsPage);
        RouteAnalysisPage = new QWidget();
        RouteAnalysisPage->setObjectName("RouteAnalysisPage");
        parametersCard = new QFrame(RouteAnalysisPage);
        parametersCard->setObjectName("parametersCard");
        parametersCard->setGeometry(QRect(60, 120, 650, 241));
        parametersCard->setMinimumSize(QSize(600, 0));
        parametersCard->setMaximumSize(QSize(650, 16777215));
        parametersCard->setStyleSheet(QString::fromUtf8("QFrame#parametersCard {\n"
"    background-color: #161b22;\n"
"    border: 1px solid #30363d;\n"
"    border-radius: 12px;\n"
"}\n"
"QLabel {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 16px;\n"
"}\n"
"QLineEdit {\n"
"    background-color: #0d1117;\n"
"    border: 1px solid #30363d;\n"
"    border-radius: 6px;\n"
"    color: white;\n"
"    padding: 8px;\n"
"}\n"
"\n"
"QPushButton#calculateButton {\n"
"    background-color: #00c896;\n"
"    color: black;\n"
"    border-radius: 8px;\n"
"    font-weight: bold;\n"
"    height: 40px;\n"
"}\n"
"\n"
"QPushButton#calculateButton:hover {\n"
"    background-color: #00c896;\n"
"    color: black;\n"
"    border-radius: 8px;\n"
"    font-weight: bold;\n"
"    height: 40px;\n"
"    background-color: rgba(0, 200, 150, 127);\n"
"}"));
        parametersCard->setFrameShape(QFrame::Shape::StyledPanel);
        parametersCard->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(parametersCard);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(parametersCard);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 40));

        verticalLayout_2->addWidget(label);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_6 = new QLabel(parametersCard);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #e67a07;\n"
"    border-radius: 6px; \n"
"    min-width: 12px;\n"
"    min-height: 12px;\n"
"    max-width: 12px;\n"
"    max-height: 12px;\n"
"}"));

        horizontalLayout_12->addWidget(label_6);

        startLine = new QLineEdit(parametersCard);
        startLine->setObjectName("startLine");
        startLine->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_12->addWidget(startLine);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_7 = new QLabel(parametersCard);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #00c896;\n"
"    border-radius: 6px; \n"
"    min-width: 12px;\n"
"    min-height: 12px;\n"
"    max-width: 12px;\n"
"    max-height: 12px;\n"
"}"));

        horizontalLayout_13->addWidget(label_7);

        destinationLine = new QLineEdit(parametersCard);
        destinationLine->setObjectName("destinationLine");
        destinationLine->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_13->addWidget(destinationLine);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_11 = new QHBoxLayout();
#ifndef Q_OS_MAC
        horizontalLayout_11->setSpacing(-1);
#endif
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        priceLine = new QLineEdit(parametersCard);
        priceLine->setObjectName("priceLine");
        priceLine->setMinimumSize(QSize(40, 0));
        priceLine->setMaximumSize(QSize(200, 40));

        horizontalLayout_11->addWidget(priceLine);

        consumptionLine = new QLineEdit(parametersCard);
        consumptionLine->setObjectName("consumptionLine");
        consumptionLine->setMaximumSize(QSize(200, 40));

        horizontalLayout_11->addWidget(consumptionLine);

        calculateButton = new QPushButton(parametersCard);
        calculateButton->setObjectName("calculateButton");
        calculateButton->setMinimumSize(QSize(0, 20));
        calculateButton->setMaximumSize(QSize(16777215, 40));
        calculateButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: center;\n"
"    padding: 5px; \n"
"}"));

        horizontalLayout_11->addWidget(calculateButton);


        verticalLayout_2->addLayout(horizontalLayout_11);

        travelCostCalculatorLabel = new QLabel(RouteAnalysisPage);
        travelCostCalculatorLabel->setObjectName("travelCostCalculatorLabel");
        travelCostCalculatorLabel->setGeometry(QRect(60, 40, 431, 61));
        travelCostCalculatorLabel->setFont(font4);
        apperingOnCalculateTripFrame = new QFrame(RouteAnalysisPage);
        apperingOnCalculateTripFrame->setObjectName("apperingOnCalculateTripFrame");
        apperingOnCalculateTripFrame->setGeometry(QRect(60, 340, 651, 141));
        apperingOnCalculateTripFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    border:  transparent;\n"
"}"));
        apperingOnCalculateTripFrame->setFrameShape(QFrame::Shape::StyledPanel);
        apperingOnCalculateTripFrame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayoutWidget = new QWidget(apperingOnCalculateTripFrame);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(-10, 40, 671, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        fuelRequiredFrame = new QFrame(horizontalLayoutWidget);
        fuelRequiredFrame->setObjectName("fuelRequiredFrame");
        fuelRequiredFrame->setMaximumSize(QSize(198, 16777215));
        fuelRequiredFrame->setStyleSheet(QString::fromUtf8("QFrame#fuelRequiredFrame {\n"
"    background-color: #161b22;\n"
"    border: 1px solid #30363d;\n"
"    border-radius: 12px;\n"
"}"));
        fuelRequiredFrame->setFrameShape(QFrame::Shape::StyledPanel);
        fuelRequiredFrame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayoutWidget_3 = new QWidget(fuelRequiredFrame);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(10, 10, 121, 61));
        verticalLayout_9 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        distanceLabel_2 = new QLabel(verticalLayoutWidget_3);
        distanceLabel_2->setObjectName("distanceLabel_2");
        distanceLabel_2->setMaximumSize(QSize(16777215, 35));

        verticalLayout_9->addWidget(distanceLabel_2);

        distanceResult_2 = new QLabel(verticalLayoutWidget_3);
        distanceResult_2->setObjectName("distanceResult_2");
        distanceResult_2->setMaximumSize(QSize(16777215, 35));
        QFont font6;
        font6.setPointSize(25);
        distanceResult_2->setFont(font6);
        distanceResult_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_9->addWidget(distanceResult_2, 0, Qt::AlignmentFlag::AlignLeft);


        horizontalLayout_2->addWidget(fuelRequiredFrame);

        distanceFrame = new QFrame(horizontalLayoutWidget);
        distanceFrame->setObjectName("distanceFrame");
        distanceFrame->setMaximumSize(QSize(198, 16777215));
        distanceFrame->setStyleSheet(QString::fromUtf8("QFrame#distanceFrame {\n"
"    background-color: #161b22;\n"
"    border: 1px solid #30363d;\n"
"    border-radius: 12px;\n"
"}"));
        distanceFrame->setFrameShape(QFrame::Shape::StyledPanel);
        distanceFrame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayoutWidget_2 = new QWidget(distanceFrame);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 121, 61));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        distanceLabel = new QLabel(verticalLayoutWidget_2);
        distanceLabel->setObjectName("distanceLabel");
        distanceLabel->setMaximumSize(QSize(16777215, 35));

        verticalLayout_8->addWidget(distanceLabel);

        distanceResult = new QLabel(verticalLayoutWidget_2);
        distanceResult->setObjectName("distanceResult");
        distanceResult->setMaximumSize(QSize(16777215, 35));
        distanceResult->setFont(font6);
        distanceResult->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_8->addWidget(distanceResult, 0, Qt::AlignmentFlag::AlignLeft);


        horizontalLayout_2->addWidget(distanceFrame);

        priceFrame = new QFrame(horizontalLayoutWidget);
        priceFrame->setObjectName("priceFrame");
        priceFrame->setMaximumSize(QSize(198, 16777215));
        priceFrame->setStyleSheet(QString::fromUtf8("QFrame#priceFrame {\n"
"    background-color: #161b22;\n"
"    border: 1px solid #30363d;\n"
"    border-radius: 12px;\n"
"}"));
        priceFrame->setFrameShape(QFrame::Shape::StyledPanel);
        priceFrame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayoutWidget_4 = new QWidget(priceFrame);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(10, 10, 121, 61));
        verticalLayout_10 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        distanceLabel_3 = new QLabel(verticalLayoutWidget_4);
        distanceLabel_3->setObjectName("distanceLabel_3");
        distanceLabel_3->setMaximumSize(QSize(16777215, 35));

        verticalLayout_10->addWidget(distanceLabel_3);

        distanceResult_3 = new QLabel(verticalLayoutWidget_4);
        distanceResult_3->setObjectName("distanceResult_3");
        distanceResult_3->setMaximumSize(QSize(16777215, 35));
        distanceResult_3->setFont(font6);
        distanceResult_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_10->addWidget(distanceResult_3, 0, Qt::AlignmentFlag::AlignLeft);


        horizontalLayout_2->addWidget(priceFrame);

        availableRoutesCard = new QFrame(RouteAnalysisPage);
        availableRoutesCard->setObjectName("availableRoutesCard");
        availableRoutesCard->setGeometry(QRect(60, 480, 650, 200));
        availableRoutesCard->setMinimumSize(QSize(600, 0));
        availableRoutesCard->setMaximumSize(QSize(650, 200));
        availableRoutesCard->setStyleSheet(QString::fromUtf8("QFrame#availableRoutesCard {\n"
"    background-color: #161b22;\n"
"    border: 1px solid #30363d;\n"
"    border-radius: 12px;\n"
"}\n"
"QLabel {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 16px;\n"
"}\n"
"QLineEdit {\n"
"    background-color: #0d1117;\n"
"    border: 1px solid #30363d;\n"
"    border-radius: 6px;\n"
"    color: white;\n"
"    padding: 8px;\n"
"}\n"
"\n"
"QPushButton#saveRouteButton {\n"
"    background-color: #00c896;\n"
"    color: black;\n"
"    border-radius: 8px;\n"
"    font-weight: bold;\n"
"    height: 40px;\n"
"}\n"
"\n"
"QPushButton#saveRouteButton:hover {\n"
"    background-color: #00c896;\n"
"    color: black;\n"
"    border-radius: 8px;\n"
"    font-weight: bold;\n"
"    height: 40px;\n"
"    background-color: rgba(0, 200, 150, 127);\n"
"}"));
        availableRoutesCard->setFrameShape(QFrame::Shape::StyledPanel);
        availableRoutesCard->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(availableRoutesCard);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_8 = new QLabel(availableRoutesCard);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(16777215, 40));
        label_8->setFont(font1);

        horizontalLayout_3->addWidget(label_8);

        saveRouteButton = new QPushButton(availableRoutesCard);
        saveRouteButton->setObjectName("saveRouteButton");
        saveRouteButton->setMaximumSize(QSize(200, 40));
        saveRouteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: center;\n"
"    padding: 5px; \n"
"}"));

        horizontalLayout_3->addWidget(saveRouteButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        frame = new QFrame(availableRoutesCard);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"    border: 0px solid #161b22;\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 621, 50));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget);
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName("label_9");
        label_9->setMaximumSize(QSize(100, 25));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #00c896;\n"
"    color: #0d1117;\n"
"    border-radius: 10px;\n"
"    font-size: 10px;\n"
"    padding: 2px 6px;\n"
"    font-weight: bold;\n"
"    align: center;\n"
"    qproperty-alignment: 'AlignHCenter | AlignVCenter';\n"
"}\n"
"\n"
""));

        horizontalLayout_14->addWidget(label_9);

        cheapestKmLabel = new QLabel(layoutWidget);
        cheapestKmLabel->setObjectName("cheapestKmLabel");
        cheapestKmLabel->setMaximumSize(QSize(200, 16777215));
        cheapestKmLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: gray;\n"
"}"));

        horizontalLayout_14->addWidget(cheapestKmLabel);

        cheapestTimeLabel = new QLabel(layoutWidget);
        cheapestTimeLabel->setObjectName("cheapestTimeLabel");
        cheapestTimeLabel->setMaximumSize(QSize(300, 16777215));
        cheapestTimeLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: gray;\n"
"}"));

        horizontalLayout_14->addWidget(cheapestTimeLabel);

        horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName("label_14");
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: gray;\n"
"}"));

        horizontalLayout_14->addWidget(label_14);


        verticalLayout_3->addWidget(frame);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        label_10 = new QLabel(availableRoutesCard);
        label_10->setObjectName("label_10");
        label_10->setMaximumSize(QSize(100, 25));
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: gray;\n"
"    color: #0d1117;\n"
"    border-radius: 10px;\n"
"    font-size: 10px;\n"
"    padding: 2px 6px;\n"
"    font-weight: bold;\n"
"    align: center;\n"
"    qproperty-alignment: 'AlignHCenter | AlignVCenter';\n"
"}"));

        horizontalLayout_15->addWidget(label_10);

        label_11 = new QLabel(availableRoutesCard);
        label_11->setObjectName("label_11");
        label_11->setMaximumSize(QSize(300, 16777215));
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: gray;\n"
"}"));

        horizontalLayout_15->addWidget(label_11);

        label_12 = new QLabel(availableRoutesCard);
        label_12->setObjectName("label_12");
        label_12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: gray;\n"
"}"));

        horizontalLayout_15->addWidget(label_12);

        horizontalSpacer_2 = new QSpacerItem(200, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_2);

        label_13 = new QLabel(availableRoutesCard);
        label_13->setObjectName("label_13");
        label_13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: gray;\n"
"}"));

        horizontalLayout_15->addWidget(label_13);


        verticalLayout_3->addLayout(horizontalLayout_15);

        stackedWidget->addWidget(RouteAnalysisPage);
        travelHistoryPage = new QWidget();
        travelHistoryPage->setObjectName("travelHistoryPage");
        travelCostCalculatorLabel_4 = new QLabel(travelHistoryPage);
        travelCostCalculatorLabel_4->setObjectName("travelCostCalculatorLabel_4");
        travelCostCalculatorLabel_4->setGeometry(QRect(60, 40, 431, 61));
        travelCostCalculatorLabel_4->setFont(font4);
        tableWidget = new QTableWidget(travelHistoryPage);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(60, 170, 641, 311));
        tableWidget->setStyleSheet(QString::fromUtf8("\n"
"QTableWidget {\n"
"    background-color: #161b22;\n"
"    border: 1px solid #30363d;\n"
"    border-radius: 12px; \n"
"    gridline-color: transparent;\n"
"}\n"
"\n"
"QHeaderView {\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QHeaderView::section:horizontal:first {\n"
"    border-top-left-radius: 11px;\n"
"}\n"
"\n"
"QHeaderView::section:horizontal:last {\n"
"    border-top-right-radius: 11px;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #21262d;\n"
"    color: #848d97;\n"
"    padding: 10px;\n"
"    border: none;\n"
"    border-bottom: 1px solid #30363d;\n"
"}"));
        tableWidget->horizontalHeader()->setDefaultSectionSize(126);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        travelCostCalculatorLabel_5 = new QLabel(travelHistoryPage);
        travelCostCalculatorLabel_5->setObjectName("travelCostCalculatorLabel_5");
        travelCostCalculatorLabel_5->setGeometry(QRect(60, 70, 431, 61));
        travelCostCalculatorLabel_5->setFont(font5);
        travelCostCalculatorLabel_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #687c94; \n"
"}"));
        deleteButton = new QPushButton(travelHistoryPage);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(490, 500, 211, 40));
        deleteButton->setMinimumSize(QSize(0, 20));
        deleteButton->setMaximumSize(QSize(16777215, 40));
        deleteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: center;\n"
"    padding: 5px; \n"
"}\n"
"\n"
"QPushButton#deleteButton  {\n"
"    background-color: #4f2123;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    font-weight: bold;\n"
"    height: 40px;\n"
"}\n"
"\n"
"QPushButton#deleteButton:hover  {\n"
"    background-color: #4f2123;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    font-weight: bold;\n"
"    height: 40px;\n"
"    background-color: rgba(79, 33, 35, 127);\n"
"}"));
        stackedWidget->addWidget(travelHistoryPage);

        horizontalLayout->addWidget(mainWindowFrame);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "EcoDrive", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", " ECO DRIVE         ", nullptr));
        routeAnalysisButton->setText(QCoreApplication::translate("MainWindow", "Route Analysis", nullptr));
        dashboardButton->setText(QCoreApplication::translate("MainWindow", "Saved Routes", nullptr));
        settingsButton->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        iconLabel->setText(QString());
        carModelLabel->setText(QCoreApplication::translate("MainWindow", "Model", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("MainWindow", "7.1 L/100km \342\200\242 Diesel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Vehicle Profile", nullptr));
        carModelLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "Car model (optional)", nullptr));
        avgCansumptionEnterLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "Avg. Consumption (L/100km)", nullptr));
        priceLine_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Fuel Price (\342\202\254/L)", nullptr));
        petrolButton->setText(QCoreApplication::translate("MainWindow", "Petrol", nullptr));
        dieselButton->setText(QCoreApplication::translate("MainWindow", "Diesel", nullptr));
        saveProfileButton->setText(QCoreApplication::translate("MainWindow", "Save Profile", nullptr));
        travelCostCalculatorLabel_2->setText(QCoreApplication::translate("MainWindow", "Vehicle Profile & Settings", nullptr));
        travelCostCalculatorLabel_3->setText(QCoreApplication::translate("MainWindow", "Your car details are used for all calculations", nullptr));
        fuelPriceTitleLabel->setText(QCoreApplication::translate("MainWindow", "Fuel Price Source", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Current price (API)", nullptr));
        currentPriceAPILabel->setText(QCoreApplication::translate("MainWindow", "1.88 \342\202\254/L", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Last updated", nullptr));
        lastUpdatedLabel->setText(QCoreApplication::translate("MainWindow", "Today, 14:32", nullptr));
        sourceLabel->setText(QCoreApplication::translate("MainWindow", "Source", nullptr));
        source2Label->setText(QCoreApplication::translate("MainWindow", "Fuel Price API", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Price is fetched automatically. You don't need to enter it manually.", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Parameters", nullptr));
        label_6->setText(QString());
        startLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "Starting City (e.g. Vilnius)", nullptr));
        label_7->setText(QString());
        destinationLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "Destination (e.g. Kaunas)", nullptr));
        priceLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "Fuel Price (\342\202\254/L)", nullptr));
        consumptionLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "Avg. Consumption (L/100km)", nullptr));
        calculateButton->setText(QCoreApplication::translate("MainWindow", "Calculate Trip", nullptr));
        travelCostCalculatorLabel->setText(QCoreApplication::translate("MainWindow", "Route Analysis", nullptr));
        distanceLabel_2->setText(QCoreApplication::translate("MainWindow", "Fuel Required", nullptr));
        distanceResult_2->setText(QCoreApplication::translate("MainWindow", "--- L", nullptr));
        distanceLabel->setText(QCoreApplication::translate("MainWindow", "Distance", nullptr));
        distanceResult->setText(QCoreApplication::translate("MainWindow", "--- km", nullptr));
        distanceLabel_3->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        distanceResult_3->setText(QCoreApplication::translate("MainWindow", "--- \342\202\254", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Available Routes", nullptr));
        saveRouteButton->setText(QCoreApplication::translate("MainWindow", "Save Route", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Cheapest", nullptr));
        cheapestKmLabel->setText(QCoreApplication::translate("MainWindow", "~180 km", nullptr));
        cheapestTimeLabel->setText(QCoreApplication::translate("MainWindow", "~1h 30min", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "12.8 \342\202\254", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Alternative", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "~200 km", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "~1h 50min", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "14.2 \342\202\254", nullptr));
        travelCostCalculatorLabel_4->setText(QCoreApplication::translate("MainWindow", "Travel History", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Route", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "KM", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Fuel", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        travelCostCalculatorLabel_5->setText(QCoreApplication::translate("MainWindow", "Your previous trips", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
