#include "io_service.h"

using namespace iocape;

IOCAPE_API std::atomic_size_t iocape::g_ioServiceInitCounter = 0;

IOCAPE_API Win32IOService::Win32IOService(peff::Alloc *selfAllocator, peff::Alloc *allocator) : IOService(selfAllocator, allocator) {
}

IOCAPE_API Win32IOService::~Win32IOService() {
	if (!--g_ioServiceInitCounter)
		WSACleanup();
}

IOCAPE_API void Win32IOService::dealloc() noexcept {
	peff::destroyAndRelease<Win32IOService>(selfAllocator.get(), this, alignof(Win32IOService));
}

IOCAPE_API IOService *iocape::createIOService(peff::Alloc *selfAllocator, peff::Alloc *allocator) {
	std::unique_ptr<Win32IOService, peff::DeallocableDeleter<Win32IOService>> p;

	if (!g_ioServiceInitCounter) {
		WSADATA wsaData;

		if (WSAStartup(MAKEWORD(2, 2), &wsaData)) {
			return nullptr;
		}
	}
	++g_ioServiceInitCounter;

	if (!(p = std::unique_ptr<Win32IOService, peff::DeallocableDeleter<Win32IOService>>(peff::allocAndConstruct<Win32IOService>(selfAllocator, alignof(Win32IOService), selfAllocator, allocator)))) {
		return nullptr;
	}

	return p.release();
}
