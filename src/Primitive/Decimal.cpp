#include "Decimal.h"

#include "LengthPrefixedString.h"

QNRBF_BEGIN_NAMESPACE

Decimal::Decimal() {
}

Decimal::Decimal(const QString &data) : _data(data) {
}

Decimal::Decimal(QString &&data) noexcept : _data(data) {
}

Decimal::Decimal(const Decimal &other) {
    _data = other._data;
}

Decimal::Decimal(Decimal &&other) noexcept {
    _data = std::move(other._data);
}

Decimal &Decimal::operator=(const Decimal &other) {
    _data = other._data;
    return *this;
}

Decimal &Decimal::operator=(Decimal &&other) noexcept {
    _data = std::move(other._data);
    return *this;
}

bool Decimal::read(QDataStream &in) {
    return Parser::readString(_data, in);
}

QNRBF_END_NAMESPACE
