#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <QString>

class InputValidator
{
public:
    static bool isNotEmpty(const QString &value);
    static bool isPositiveNumber(const QString &value);

    static QString validateRouteInputs(const QString &startLocation,
                                       const QString &destLocation);

    static QString validateProfileInputs(const QString &consumption);
};

#endif // INPUTVALIDATOR_H
