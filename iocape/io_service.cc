#include "io_service.h"

using namespace iocape;

IOCAPE_API IOService::IOService(peff::Alloc *selfAllocator, peff::Alloc *allocator) : selfAllocator(selfAllocator), allocator(allocator) {
}

IOCAPE_API IOService::~IOService() {
}
