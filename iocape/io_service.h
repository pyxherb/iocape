#ifndef _IOCAPE_IO_SERVICE_H_
#define _IOCAPE_IO_SERVICE_H_

#include "socket.h"
#include <peff/base/alloc.h>
#include <peff/base/deallocable.h>

namespace iocape {
	class IOService {
	public:
		peff::RcObjectPtr<peff::Alloc> selfAllocator;
		peff::RcObjectPtr<peff::Alloc> allocator;

		IOCAPE_API IOService(peff::Alloc *selfAllocator, peff::Alloc *allocator);
		IOCAPE_API virtual ~IOService();

		virtual void dealloc() noexcept = 0;
	};

	using IOServiceUniquePtr = std::unique_ptr<IOService, peff::DeallocableDeleter<IOService>>;

	IOCAPE_API IOService *createIOService(peff::Alloc *selfAllocator, peff::Alloc *allocator);
}

#endif
