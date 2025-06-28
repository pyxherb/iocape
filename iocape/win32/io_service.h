#ifndef _IOCAPE_WIN32_IO_SERVICE_H_
#define _IOCAPE_WIN32_IO_SERVICE_H_

#include "../io_service.h"

#include <atomic>
#include <WinSock2.h>

namespace iocape {
	class Win32IOService : public IOService {
	public:
		IOCAPE_API Win32IOService(peff::Alloc *selfAllocator, peff::Alloc *allocator);
		IOCAPE_API virtual ~Win32IOService();

		IOCAPE_API virtual void dealloc() noexcept override;
	};

	IOCAPE_API extern std::atomic_size_t g_ioServiceInitCounter;
}

#endif
