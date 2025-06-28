#include "async_res.h"

using namespace iocape;

IOCAPE_API AsyncBuffer::AsyncBuffer(char *ptr, size_t size) : ptr(ptr), size(size) {
}

IOCAPE_API AsyncBuffer::~AsyncBuffer() {
}

