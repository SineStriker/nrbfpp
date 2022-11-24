#include "ArrayInfo.h"

QNRBF_BEGIN_NAMESPACE

ArrayInfo::ArrayInfo() {
    objectId = 0;
    length = 0;
}

bool ArrayInfo::read(QDataStream &in) {
    in >> objectId;
    in >> length;
    if (in.status() != QDataStream::Ok) {
        return false;
    }
    return true;
}

QNRBF_END_NAMESPACE