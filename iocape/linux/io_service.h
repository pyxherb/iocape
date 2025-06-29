#ifndef _IOCAPE_WIN32_IO_SERVICE_H_
#define _IOCAPE_WIN32_IO_SERVICE_H_

#include "../io_service.h"

#include <unistd.h>
#include <sys/epoll.h>

#include <peff/containers/dynarray.h>

#include <pthread.h>

#include <variant>

namespace iocape {
	class LinuxIOService : public IOService {
	public:
		enum class Mode : uint8_t {
			Select = 0,
			Epoll,
			IOURing,
		};

		Mode mode;

		struct SelectModeData final {
			peff::DynArray<pthread_t> workerThreads;

			fd_set fdSet;

			IOCAPE_FORCEINLINE SelectModeData(peff::Alloc *allocator): workerThreads(allocator) {}
			IOCAPE_FORCEINLINE ~SelectModeData() {}
		};

		std::variant<std::monostate, SelectModeData> modeSpecificData;

		IOCAPE_API LinuxIOService(peff::Alloc *selfAllocator, peff::Alloc *allocator);
		IOCAPE_API virtual ~LinuxIOService();

		IOCAPE_API virtual void dealloc() noexcept override;
	};
}

#endif
