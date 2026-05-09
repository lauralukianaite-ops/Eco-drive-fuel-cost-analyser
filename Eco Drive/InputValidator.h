#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <QString>

class InputValidator
{
public:
    static bool isNotEmpty(const QString &value);
    static bool isPositiveNumber(const QString &value);

    static QString validateRouteInputs(const QString &startLocation,
                                       const QString &destLocation,
                                       const QString &fuelPrice,
                                       const QString &consumption);

    static QString validateProfileInputs(const QString &consumption,
                                         const QString &fuelPrice);
};

#endif // INPUTVALIDATOR_H
