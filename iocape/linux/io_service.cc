#include "io_service.h"

using namespace iocape;

IOCAPE_API LinuxIOService::LinuxIOService(peff::Alloc *selfAllocator, peff::Alloc *allocator) : IOService(selfAllocator, allocator) {
}

IOCAPE_API LinuxIOService::~LinuxIOService() {
}

IOCAPE_API void LinuxIOService::dealloc() noexcept {
	peff::destroyAndRelease<LinuxIOService>(selfAllocator.get(), this, alignof(LinuxIOService));
}

IOCAPE_API IOService *iocape::createIOService(peff::Alloc *selfAllocator, peff::Alloc *allocator) {
	std::unique_ptr<LinuxIOService, peff::DeallocableDeleter<LinuxIOService>> p;

	if (!(p = std::unique_ptr<LinuxIOService, peff::DeallocableDeleter<LinuxIOService>>(peff::allocAndConstruct<LinuxIOService>(selfAllocator, alignof(LinuxIOService), selfAllocator, allocator)))) {
		return nullptr;
	}

	return p.release();
}
