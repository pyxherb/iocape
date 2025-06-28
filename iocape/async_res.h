#ifndef _IOCAPE_ASYNC_RES_H_
#define _IOCAPE_ASYNC_RES_H_

#include "basedefs.h"
#include <peff/base/rcobj.h>

namespace iocape {
	class AsyncBuffer : public peff::RcObject {
	public:
		char *const ptr;
		const size_t size;

		IOCAPE_API AsyncBuffer(char *ptr, size_t size);
		IOCAPE_API virtual ~AsyncBuffer();
	};
}

#endif
