#include "InputValidator.h"

bool InputValidator::isNotEmpty(const QString &value)
{
    return !value.trimmed().isEmpty();
}

bool InputValidator::isPositiveNumber(const QString &value)
{
    bool ok;
    double number = value.trimmed().toDouble(&ok);
    return ok && number > 0;
}

QString InputValidator::validateProfileInputs(const QString &consumption)
{
    if (!isPositiveNumber(consumption))
        return "Please enter a valid fuel consumption";

    return "";
}

QString InputValidator::validateRouteInputs(const QString &startLocation,
                                            const QString &destLocation,
                                            const QString &consumption)
{
    if (!isNotEmpty(startLocation))
        return "Please enter your starting location";

    if (!isNotEmpty(destLocation))
        return "Please enter your destination";

    if (!isPositiveNumber(consumption))
        return "Please enter a valid fuel consumption";

    return "";
}