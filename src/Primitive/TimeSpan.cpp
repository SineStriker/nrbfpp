#include "TimeSpan.h"

QNRBF_BEGIN_NAMESPACE

TimeSpan::TimeSpan() : TimeSpan(0) {
}

TimeSpan::TimeSpan(quint64 data) : _data(data) {
}

TimeSpan::TimeSpan(const TimeSpan &other) {
    _data = other._data;
}

TimeSpan::TimeSpan(TimeSpan &&other) noexcept {
    _data = std::move(other._data);
}

TimeSpan &TimeSpan::operator=(const TimeSpan &other) {
    _data = other._data;
    return *this;
}

TimeSpan &TimeSpan::operator=(TimeSpan &&other) noexcept {
    _data = std::move(other._data);
    return *this;
}

bool TimeSpan::read(QDataStream &in) {
    in >> _data;
    if (in.status() != QDataStream::Ok)
        return false;
    return true;
}

QNRBF_END_NAMESPACE
